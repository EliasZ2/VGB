#include <cstdint>
#include "Definitions.h"

Definitions::Registers::Registers() : regMap8b{
    &reg_b,
    &reg_c,
    &reg_d,
    &reg_e,
    &reg_h,
    &reg_l,
    &reg_a
}{}

void Definitions::Registers::loadRegister_16b(uint8_t high, uint8_t low, uint16_t value){
    *Registers::regMap8b[high] = (value>>8) & 0xFF;
    *Registers::regMap8b[low] = (value & 0xFF);
}
