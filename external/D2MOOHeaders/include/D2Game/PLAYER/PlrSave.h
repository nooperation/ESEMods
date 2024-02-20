#pragma once

#include <Units/Units.h>
#include "PlrSave2.h"

#pragma pack(push, 1)
struct D2SavedItemStrc
{
    uint8_t nBodyLoc;
    uint8_t unk0x01;
    int32_t nItemLevel;
    int32_t nItemId;
    uint8_t nSpawnType;
    uint8_t nItemQuality;
    int32_t nQuantity;
    int32_t nMinDurability;
    int32_t nMaxDurability;
    int32_t nX;
    int32_t nY;
    int32_t nItemIndex;
    int32_t nItemFlags;
    int32_t nSeed;
    int32_t nItemSeed;
    uint8_t nInvPage;
    uint8_t nEarLevel;
    char szName[16];
    uint16_t nItemFormat;
    uint32_t nItemCode;
};
#pragma pack(pop)
