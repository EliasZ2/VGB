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

void MemMap::writeByte(uint16_t address, uint8_t value) {

    // Cartridge ROM bank 00: 0000-3FFF
    if (address <= 0x3FFF) {
        cartridge[address] = value;
    }

    // Switchable cartridge ROM bank: 4000-7FFF
    else if (address <= 0x7FFF) {
        cartridge_s[address - 0x4000] = value;
    }

    // Video RAM: 8000-9FFF
    else if (address <= 0x9FFF) {
        vram[address - 0x8000] = value;
    }

    // External RAM: A000-BFFF
    else if (address <= 0xBFFF) {
        eram[address - 0xA000] = value;
    }

    // Work RAM bank 0: C000-CFFF
    else if (address <= 0xCFFF) {
        wram0[address - 0xC000] = value;
    }

    // Work RAM bank 1: D000-DFFF
    else if (address <= 0xDFFF) {
        wram1[address - 0xD000] = value;
    }

    // Echo RAM: E000-FDFF (mirror of C000-DDFF)
    else if (address <= 0xFDFF) {
        uint16_t mirroredAddress = address - 0x2000;

        if (mirroredAddress <= 0xCFFF) {
            wram0[mirroredAddress - 0xC000] = value;
        }
        else {
            wram1[mirroredAddress - 0xD000] = value;
        }
    }

    // Object Attribute Memory: FE00-FE9F
    else if (address <= 0xFE9F) {
        oam[address - 0xFE00] = value;
    }

    // Unusable memory: FEA0-FEFF
    /*else if (address <= 0xFEFF) {
        return 0xFF;
    }*/

    // I/O registers: FF00-FF7F
    else if (address <= 0xFF7F) {
        io_registers[address - 0xFF00] = value;
    }

    // High RAM: FF80-FFFE
    else if (address <= 0xFFFE) {
        hram[address - 0xFF80] = value;
    }

    // Interrupt Enable: FFFF
    else {
        interrupt_enable = value;
    }
}