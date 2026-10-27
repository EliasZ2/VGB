#include <cstdint> 

// Memory map

// Cartridge ROM bank 00: 0000-3FFF
uint8_t cartridge[0x4000];

// Cartridge switchable ROM bank: 4000-7FFF
uint8_t cartridge_s[0x4000];

// Video RAM (VRAM): 8000-9FFF
uint8_t vram[0x2000];

// External RAM: A000-BFFF
uint8_t eram[0x2000];

// Work RAM bank 0: C000-CFFF
uint8_t wram0[0x1000];

// Work RAM bank 1: D000-DFFF
uint8_t wram1[0x1000];

// Echo RAM: E000-FDFF (mirror of C000-DDFF)
uint8_t echo_ram[0x1E00];

// Object Attribute Memory (OAM): FE00-FE9F
uint8_t oam[0xA0];

// Unusable memory region: FEA0-FEFF
uint8_t unusable[0x60];

// I/O registers: FF00-FF7F
uint8_t io_registers[0x80];

// High RAM (HRAM): FF80-FFFE
uint8_t hram[0x7F];

// Interrupt Enable register: FFFF
uint8_t interrupt_enable;
