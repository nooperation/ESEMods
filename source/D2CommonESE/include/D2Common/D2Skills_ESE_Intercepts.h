#pragma once

#include <D2Common/D2Skills_ESE.h>

#include <cstdlib>
#include <CommonDefinitions.h>
#include <D2Inventory.h>

//D2Common.0x6FDAEB60
int __stdcall ESE_INTERCEPT_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel);
//D2Common.0x6FDB2280
int __stdcall ESE_INTERCEPT_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel);
//D2Common.0x6FDB22E0
int __fastcall ESE_INTERCEPT_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);
//D2Common.0x6FDB2390
int __stdcall ESE_INTERCEPT_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB25D0
int __stdcall ESE_INTERCEPT_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB2810
int __stdcall ESE_INTERCEPT_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB29D0
int __fastcall ESE_INTERCEPT_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);
//D2Common.0x6FDB2B00
int __stdcall ESE_INTERCEPT_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB2CA0
int __stdcall ESE_INTERCEPT_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused);
//D2Common.0x6FDB3A90
int __stdcall ESE_INTERCEPT_D2Common_11028(int a1);
//D2Common.0x6FDB3AB0
int __stdcall ESE_INTERCEPT_D2Common_11033(int nLevel, int nParam, int nMax);
//D2Common.0x6FDB41D0
int __stdcall ESE_INTERCEPT_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);
//D2Common.0x6FDB4260
void __stdcall ESE_INTERCEPT_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent);

extern SKILLS_GetSpecialParamValue_t SKILLS_GetSpecialParamValue_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel);

extern SKILLS_GetManaCosts_t SKILLS_GetManaCosts_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel);

extern SKILLS_CalculateDamageBonusByLevel_t SKILLS_CalculateDamageBonusByLevel_Original;
int __fastcall ESE_INTERCEPT_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);

extern SKILLS_GetMinPhysDamage_t SKILLS_GetMinPhysDamage_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);

extern SKILLS_GetMaxPhysDamage_t SKILLS_GetMaxPhysDamage_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);

extern SKILLS_GetMinElemDamage_t SKILLS_GetMinElemDamage_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);

extern SKILLS_CalculateMasteryBonus_t SKILLS_CalculateMasteryBonus_Original;
int __fastcall ESE_INTERCEPT_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);

extern SKILLS_GetMaxElemDamage_t SKILLS_GetMaxElemDamage_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);

extern SKILLS_GetElementalLength_t SKILLS_GetElementalLength_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused);

extern D2Common_11028_t D2Common_11028_Original;
int __stdcall ESE_INTERCEPT_D2Common_11028(int a1);

extern D2Common_11033_t D2Common_11033_Original;
int __stdcall ESE_INTERCEPT_D2Common_11033(int nLevel, int nParam, int nMax);

extern SKILLS_GetConcentrationDamageBonus_t SKILLS_GetConcentrationDamageBonus_Original;
int __stdcall ESE_INTERCEPT_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);

extern SKILLS_CalculateKickDamage_t SKILLS_CalculateKickDamage_Original;
void __stdcall ESE_INTERCEPT_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent);

