#include <cstdint>
#include <iostream>
#include "CPU.h"

CPU::CPU(){
    for (int i = 0x06; i <= 0x3E; i += 0x08) {
        opcodes[i] = &CPU::LDrn8b;
    }

}

void CPU::readOpcode(){
    uint8_t opcode = memory.readByte(registers.reg_pc);
    (this->*opcodes[opcode])();
}

// Load 8 bit register with 8 bit val n
void CPU::LDrn8b(){
    uint8_t reg = (memory.readByte(registers.reg_pc)>>3)&(0x07);
    uint8_t val = memory.readByte(++registers.reg_pc);
    if (reg == 0b0110){
        uint16_t hladdr = (registers.reg_h << 8) | registers.reg_l;
        memory.writeByte(hladdr, val);
    } 
    else if (reg == 0b0111) {
        registers.reg_a = val;
    }
    else {
        *registers.regMap8b[reg] = val;
    }
    registers.reg_pc++;
}

// Load 16 bit combined register rr with 16 bit val nn
void CPU::LDrrnn(){
    uint8_t highReg = (registers.reg_pc >> 5)&(0x01);
    uint8_t lowReg = (registers.reg_pc >> 4)&(0x01);
    uint16_t val = memory.readByte(++registers.reg_pc);
    registers.loadRegister_16b(highReg, lowReg, val);
    registers.reg_pc++;
    registers.reg_pc++;
}