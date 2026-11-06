#include <cstdint>
#include <iostream>
#include "CPU.h"

CPU::CPU(){
    opcodes[0x06] = &CPU::LDr;
}

void CPU::readOpcode(){
    uint8_t opcode = memory.readByte(registers.reg_pc);
    (this->*opcodes[opcode])();
}

void CPU::LDr(){
    uint8_t reg = (registers.reg_pc>>3)&(0x07);
    uint8_t val = memory.readByte(++registers.reg_pc);
    *registers.regMap8b[(registers.reg_pc>>3)&(0x07)] = val;
    registers.reg_pc++;
}