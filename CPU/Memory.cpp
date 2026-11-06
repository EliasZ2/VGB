#include <cstdint>
#include <Memory.h>

uint8_t MemMap::readByte(uint16_t address) {

    // Cartridge ROM bank 00: 0000-3FFF
    if (address <= 0x3FFF) {
        return cartridge[address];
    }

    // Switchable cartridge ROM bank: 4000-7FFF
    else if (address <= 0x7FFF) {
        return cartridge_s[address - 0x4000];
    }

    // Video RAM: 8000-9FFF
    else if (address <= 0x9FFF) {
        return vram[address - 0x8000];
    }

    // External RAM: A000-BFFF
    else if (address <= 0xBFFF) {
        return eram[address - 0xA000];
    }

    // Work RAM bank 0: C000-CFFF
    else if (address <= 0xCFFF) {
        return wram0[address - 0xC000];
    }

    // Work RAM bank 1: D000-DFFF
    else if (address <= 0xDFFF) {
        return wram1[address - 0xD000];
    }

    // Echo RAM: E000-FDFF (mirror of C000-DDFF)
    else if (address <= 0xFDFF) {
        return readByte(address - 0x2000);
    }

    // Object Attribute Memory: FE00-FE9F
    else if (address <= 0xFE9F) {
        return oam[address - 0xFE00];
    }

    // Unusable memory: FEA0-FEFF
    else if (address <= 0xFEFF) {
        return 0xFF;
    }

    // I/O registers: FF00-FF7F
    else if (address <= 0xFF7F) {
        return io_registers[address - 0xFF00];
    }

    // High RAM: FF80-FFFE
    else if (address <= 0xFFFE) {
        return hram[address - 0xFF80];
    }

    // Interrupt Enable: FFFF
    else {
        return interrupt_enable;
    }
}