#include <iostream>
#include "Definitions.h"
#include "Decoder.h"

using namespace std;
using namespace Definitions;

int main() {
    
    // reset everything
    // run boot rom 
    // read first instruction
    Registers reg{};
    reg.reg_pc = 0x0100;
    Decoder dec{};

    dec.opcodes[0x0100];


    return 0;
}