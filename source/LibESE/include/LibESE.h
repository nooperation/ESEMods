#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>
#include <algorithm>

inline constexpr int32_t Clamp64To32(const int64_t value)
{
    return static_cast<int32_t>(std::clamp<int64_t>(INT_MIN, INT_MAX, value));
}

#pragma pack(push, 1)
struct D2DamageReportPacket
{
    uint8_t packetId;
    uint8_t isPlayerBeingAttacked;
    uint32_t unitId;
    int64_t damage;
};
#pragma pack(pop)
