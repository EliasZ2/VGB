#include <cstdint>
#include "Definitions.h"
#include "Memory.h"

class CPU {
    public:

        // Pointer of functions responsible for decoding
        typedef void(CPU::*ptof)();
        ptof opcodes[0x0100];

        // Registers
        Definitions::Registers registers;

        // Memory Map
        MemMap memory;

        // Read Opcode
        void readOpcode();

        // Instruction handlers
        void LDr();

        CPU();

};