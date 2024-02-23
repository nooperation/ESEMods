#pragma once

#include "D2Common/D2Skills_ESE.h"

#include <../D2MooHeaders.h>
#include <CommonDefinitions.h>
#include <D2Inventory.h>

// Inlined / helper
D2SkillDescTxt* __fastcall ESE_DATATBLS_GetSkillDescTxtRecord(int nSkillDesc);
D2SkillsTxt* __fastcall ESE_DATATBLS_GetSkillsTxtRecord(int nSkillId);

//D2Common.0x6FDAEB60 (#11271)
int __stdcall ESE_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel);
//D2Common.0x6FDB2280 (#11001)
int __stdcall ESE_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel);
//D2Common.0x6FDB22E0
int __fastcall ESE_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);
//D2Common.0x6FDB2390 (#11002)
int __stdcall ESE_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB25D0 (#11003)
int __stdcall ESE_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB2810 (#11004)
int __stdcall ESE_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB29D0
int __fastcall ESE_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);
//D2Common.0x6FDB2B00 (#11005)
int __stdcall ESE_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4);
//D2Common.0x6FDB2CA0 (#11006)
int __stdcall ESE_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused);
//D2Common.0x6FDB3A90 (#11028)
int __stdcall ESE_D2Common_11028(int a1);
//D2Common.0x6FDB3AB0 (#11033)
int __stdcall ESE_D2Common_11033(int nLevel, int nParam, int nMax);
//D2Common.0x6FDB41D0 (#11047)
int __stdcall ESE_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);
//D2Common.0x6FDB4260 (#11283)
void __stdcall ESE_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent);
