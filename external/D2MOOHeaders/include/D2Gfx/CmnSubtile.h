#pragma once

#include <cstdint>

#include <Windows.h>


struct D2TileLibraryEntryStrc;
struct D2GfxLightExStrc;
struct D2PaletteTableStrc;


#pragma pack(push, 1)
struct D2PaletteStrc
{
    uint8_t unk0x00[256];
};

struct D2TileLibraryBlockStrc
{
    uint16_t nPosX;
    uint16_t nPosY;
    uint16_t unk0x04;
    uint8_t nGridX;
    uint8_t nGridY;
    uint16_t nFormat;
    uint32_t nLength;
    uint16_t unk0x0E;
    uint8_t* dwOffset_pData;
};
#pragma pack(pop)

