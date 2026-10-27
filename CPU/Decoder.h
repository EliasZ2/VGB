#include <cstdint>

// Load register
void LDr(uint16_t value){
    std::cout << "loaded register" << std::endl;
}

class Decoder {
    public:
        typedef void(*ptof)(uint16_t value);
        ptof opcodes[0x0100];
        Decoder();
};

Decoder::Decoder(){
    opcodes[0x0100] = LDr;
}