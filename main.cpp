#include <iostream>
#include "CPU/CPU.h"

using namespace std;
using namespace Definitions;

int main() {
    
    // reset everything
    // run boot rom 
    // read first instruction
    CPU cpu{};
    // read value
    cpu.registers.reg_pc = 0x0100;
    cpu.memory.cartridge[0x0100] = 0x0E;
    cpu.memory.cartridge[0x0101] = 0x42;
    cpu.readOpcode();
    return 0;
}