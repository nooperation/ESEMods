#pragma once

#include <Units/Units.h>


#pragma pack(push, 1)
struct D2BaalThroneAiCallbackArgStrc
{
	D2UnitStrc* pTarget;
	int32_t nDistance;
	int32_t unk0x08;
	int32_t nMaxDistance;
};

struct D2UnkAiCallbackArgStrc
{
	D2UnitStrc* pTarget;
	int32_t nDistance;
	int32_t unk0x08;
	int32_t nMaxDistance;
	int32_t unk0x10;
	D2UnitStrc* pAlternativeTarget;
	int32_t nAlternativeDistance;
};

struct D2UnkAiCallbackArgStrc2
{
	D2UnitStrc* pTarget;
	int32_t nDistance;
	D2UnitStrc* pAlternativeTarget;
	int32_t nAlternativeDistance;
};

struct D2AiCallback7ArgStrc
{
	D2UnitStrc* pTarget;
	int32_t nDistance;
	D2UnitStrc* unk0x08;
};

struct D2AiCallback11ArgStrc
{
	D2UnitStrc* pTarget;
	int32_t nDistance;
	D2UnitStrc* unk0x08;
};

struct D2DoorObjectAiCallbackArgStrc
{
	D2UnitStrc* pDoor;
	int32_t nDistance;
};

struct D2FallenShamanAiCallbackArgStrc
{
	D2UnitStrc* pTarget;
	int32_t nCounter;
	int32_t nDistance;
	int32_t nMaxDistance;
};

struct D2VileMotherAiCallbackArgStrc
{
	int32_t nLastInClass;
	int32_t nMaxDistance;
	int32_t nCounter;
};

struct UnkAiStrc5
{
	int32_t nMaxDistance;
};
#pragma pack(pop)

