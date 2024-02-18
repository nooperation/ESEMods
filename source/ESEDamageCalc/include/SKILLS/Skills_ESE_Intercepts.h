#pragma once

#include <type_traits>
#include <cstdlib>
#include <D2StatList.h>
#include <Units/Units.h>
#include <Units/UnitFinds.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <SKILLS/Skills_ESE.h>

//D2Game.0x6FD0F8B0
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue);
//D2Game.0x6FD0FA00
int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter);
//D2Game.0x6FD0FDD0
void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit);
//D2Game.0x6FD0FE50
void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs);
//D2Game.0x6FD0FE80
void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine);
//D2Game.0x6FD10140
void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused);
//D2Game.0x6FD10200
int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter);
//D2Game.0x6FD10250
void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD10360
int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs);
//D2Game.0x6FD10630
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*));
//D2Game.0x6FD106F0
int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD10790
int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter);
//D2Game.0x6FD107E0
int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD107F0
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8);
//D2Game.0x6FD10880
int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern decltype(&sub_6FD0F8B0) sub_6FD0F8B0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue);
static_assert(std::is_same_v<decltype(&sub_6FD0F8B0), decltype(&ESE_INTERCEPT_sub_6FD0F8B0)>, "ESE_INTERCEPT_sub_6FD0F8B0 has a different type than previously known.");

extern decltype(&sub_6FD0FA00) sub_6FD0FA00_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter);
static_assert(std::is_same_v<decltype(&sub_6FD0FA00), decltype(&ESE_INTERCEPT_sub_6FD0FA00)>, "ESE_INTERCEPT_sub_6FD0FA00 has a different type than previously known.");

extern decltype(&sub_6FD0FDD0) sub_6FD0FDD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FD0FDD0), decltype(&ESE_INTERCEPT_sub_6FD0FDD0)>, "ESE_INTERCEPT_sub_6FD0FDD0 has a different type than previously known.");

extern decltype(&sub_6FD0FE50) sub_6FD0FE50_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs);
static_assert(std::is_same_v<decltype(&sub_6FD0FE50), decltype(&ESE_INTERCEPT_sub_6FD0FE50)>, "ESE_INTERCEPT_sub_6FD0FE50 has a different type than previously known.");

extern decltype(&sub_6FD0FE80) sub_6FD0FE80_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine);
static_assert(std::is_same_v<decltype(&sub_6FD0FE80), decltype(&ESE_INTERCEPT_sub_6FD0FE80)>, "ESE_INTERCEPT_sub_6FD0FE80 has a different type than previously known.");

extern decltype(&sub_6FD10140) sub_6FD10140_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused);
static_assert(std::is_same_v<decltype(&sub_6FD10140), decltype(&ESE_INTERCEPT_sub_6FD10140)>, "ESE_INTERCEPT_sub_6FD10140 has a different type than previously known.");

extern decltype(&sub_6FD10200) sub_6FD10200_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter);
static_assert(std::is_same_v<decltype(&sub_6FD10200), decltype(&ESE_INTERCEPT_sub_6FD10200)>, "ESE_INTERCEPT_sub_6FD10200 has a different type than previously known.");

extern decltype(&sub_6FD10250) sub_6FD10250_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&sub_6FD10250), decltype(&ESE_INTERCEPT_sub_6FD10250)>, "ESE_INTERCEPT_sub_6FD10250 has a different type than previously known.");

extern decltype(&sub_6FD10360) sub_6FD10360_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs);
static_assert(std::is_same_v<decltype(&sub_6FD10360), decltype(&ESE_INTERCEPT_sub_6FD10360)>, "ESE_INTERCEPT_sub_6FD10360 has a different type than previously known.");

extern decltype(&SKILLS_FindAuraTarget) SKILLS_FindAuraTarget_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*));
static_assert(std::is_same_v<decltype(&SKILLS_FindAuraTarget), decltype(&ESE_INTERCEPT_SKILLS_FindAuraTarget)>, "ESE_INTERCEPT_SKILLS_FindAuraTarget has a different type than previously known.");

extern decltype(&sub_6FD106F0) sub_6FD106F0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FD106F0), decltype(&ESE_INTERCEPT_sub_6FD106F0)>, "ESE_INTERCEPT_sub_6FD106F0 has a different type than previously known.");

extern decltype(&sub_6FD10790) sub_6FD10790_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter);
static_assert(std::is_same_v<decltype(&sub_6FD10790), decltype(&ESE_INTERCEPT_sub_6FD10790)>, "ESE_INTERCEPT_sub_6FD10790 has a different type than previously known.");

extern decltype(&sub_6FD107E0) sub_6FD107E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FD107E0), decltype(&ESE_INTERCEPT_sub_6FD107E0)>, "ESE_INTERCEPT_sub_6FD107E0 has a different type than previously known.");

extern decltype(&sub_6FD107F0) sub_6FD107F0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8);
static_assert(std::is_same_v<decltype(&sub_6FD107F0), decltype(&ESE_INTERCEPT_sub_6FD107F0)>, "ESE_INTERCEPT_sub_6FD107F0 has a different type than previously known.");

extern decltype(&sub_6FD10880) sub_6FD10880_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FD10880), decltype(&ESE_INTERCEPT_sub_6FD10880)>, "ESE_INTERCEPT_sub_6FD10880 has a different type than previously known.");

