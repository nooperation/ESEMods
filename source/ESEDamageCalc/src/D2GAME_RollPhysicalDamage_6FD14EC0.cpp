#include "ESEDamageCalc.h"

#include <algorithm>

#include <SKILLS/SkillAss.h>
#include <SKILLS/Skills.h>
#include <ITEMS/Items.h>
#include <D2Skills.h>


//D2Game.0x6FD14EC0
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0_ESEDamageCalc(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int64_t nMinDamage = SKILLS_GetMinPhysDamage_ESEDamageCalc(pUnit, nSkillId, nSkillLevel, 0);
        const int64_t nMaxDamage = SKILLS_GetMaxPhysDamage_ESEDamageCalc(pUnit, nSkillId, nSkillLevel, 0);

        auto maxMinDamageRange = std::clamp(nMaxDamage - nMinDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

        const int64_t nDamage = (int64_t)ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, maxMinDamageRange) + nMinDamage;

        pDamage->dwPhysDamage = std::clamp(pDamage->dwPhysDamage + nDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);
    }
}
