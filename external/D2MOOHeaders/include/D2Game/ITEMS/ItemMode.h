#pragma once

#include <Units/Units.h>

#include <DataTbls/ItemsTbls.h>
#include "Items.h"

#pragma pack(push, 1)
struct D2UnkItemModeStrc
{
	int32_t nHitpoints;
	int32_t nMana;
	int32_t nStamina;
	int32_t nRightSkillId;
	int32_t nLeftSkillId;
	int32_t nRightSkillOwnerGUID;
	int32_t nLeftSkillOwnerGUID;
};

struct D2UnkItemModeStrc2
{
	int32_t nBodyLoc;
	D2UnitStrc* pItem;
	int32_t nSwitchBodyLoc;
	int32_t nSocketArg;
};

struct D2ItemModeArgStrc
{
    int32_t bIsBow;
    int32_t bIsCrossBow;
    int32_t bIsBowQuiver;
    int32_t bIsCrossBowQuiver;
    int32_t bIsShield;
    int32_t bIsWeapon;
    int32_t bIsTwoHanded;
    int32_t bCanUse2Weapons;
    int32_t bIsThrowable;
    int32_t bIsRing;
};
#pragma pack(pop)
