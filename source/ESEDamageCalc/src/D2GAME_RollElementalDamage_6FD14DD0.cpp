#include "ESEDamageCalc.h"

#include <algorithm>

#include <SKILLS/SkillAss.h>
#include <SKILLS/Skills.h>
#include <ITEMS/Items.h>
#include <D2Skills.h>


//D2Game.0x6FD14DD0
int32_t __fastcall D2GAME_RollElementalDamage_6FD14DD0_ESEDamageCalc(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int64_t nMinDamage = SKILLS_GetMinElemDamage_ESEDamageCalc(pUnit, nSkillId, nSkillLevel, 1);
        const int64_t nMaxDamage = SKILLS_GetMaxElemDamage_ESEDamageCalc(pUnit, nSkillId, nSkillLevel, 1);

        auto maxMinDamageRange = std::clamp(nMaxDamage - nMinDamage, (int64_t)INT32_MIN, (int64_t)INT32_MAX);

        const int64_t nDamage = (int64_t)ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, (int32_t)maxMinDamageRange) + nMinDamage;

        sub_6FD11E40(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1), 0, 0);
        return (int32_t)nDamage;
    }

    return 0;
}