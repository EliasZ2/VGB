#include <cstdint>
#include "Definitions.h"

Definitions::Registers::Registers() : regMap8b{
    &reg_b,
    &reg_c,
    &reg_d,
    &reg_e,
    &reg_h,
    &reg_l
}{}
