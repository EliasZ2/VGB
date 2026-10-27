#include <cstdint>

namespace Definitions{
    class Registers {
        public:
            // General purpose registers
            uint8_t reg_b = 0;
            uint8_t reg_c = 0;
            uint8_t reg_d = 0;
            uint8_t reg_e = 0;
            uint8_t reg_h = 0;
            uint8_t reg_l = 0;

            // Accumulator & Flags - bottom 8 bits untouchable
            uint16_t reg_af = 0;
            // Stack pointer 
            uint16_t reg_sp = 0;
            // Program counter
            uint16_t reg_pc = 0;
    };
}
