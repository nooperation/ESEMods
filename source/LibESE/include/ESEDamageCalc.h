#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>

#pragma pack(push, 1)
struct D2DamageReportPacket
{
    uint8_t packetId;
    uint8_t isPlayerBeingAttacked;
    uint32_t unitId;
    int64_t damage;
};

struct D2DamagePacket
{
    uint8_t packetId;
    uint8_t unknownA;
    uint8_t unknownB;
    uint8_t unknownC;
    uint32_t unitId;
    uint32_t damage;
    uint8_t unknownD;
};

#pragma pack(pop)
