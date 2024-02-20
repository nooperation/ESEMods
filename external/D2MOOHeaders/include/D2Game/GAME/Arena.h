#pragma once

#include <Units/Units.h>

#pragma pack(1)


enum D2ArenaScoreTypes
{
    ARENASCORE_SUICIDE,
    ARENASCORE_PLAYERKILL,
    ARENASCORE_PLAYERKILLPERCENT,
    ARENASCORE_MONSTERKILL,
    ARENASCORE_PLAYERDEATH,
    ARENASCORE_PLAYERDEATHPERCENT,
    ARENASCORE_MONSTERDEATH,
    NUM_ARENA_SCORES,
};

struct D2ArenaStrc
{
    int32_t nAlternateStartTown;				//0x00
    int32_t nType;								//0x04
    uint32_t fFlags;							//0x08 D2GameFlags
    int32_t nTemplate;							//0x0C - uint8_t with 3 pad
};

struct D2ArenaUnitStrc
{
    int32_t nScore;								//0x00
    BOOL bUpdateScore;						    //0x04 
};

#pragma pack()
