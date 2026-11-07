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
            uint8_t reg_a = 0;
            uint8_t reg_f = 0;
            // Stack pointer 
            uint16_t reg_sp = 0;
            // Program counter
            uint16_t reg_pc = 0;

            uint8_t* regMap8b[7];

            // 16 bit operations
            void loadRegister_16b(uint8_t high, uint8_t low, uint16_t value);
            
            Registers();
    };

}
