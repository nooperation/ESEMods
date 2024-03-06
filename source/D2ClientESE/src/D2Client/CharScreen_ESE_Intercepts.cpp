#include "D2Client/CharScreen_ESE_Intercepts.h"
#include "LibESE.h"

extern CHARSCREEN_DrawSkillDamageLeft_t CHARSCREEN_DrawSkillDamageLeft_Original = nullptr;
extern CHARSCREEN_DrawSkillDamageRight_t CHARSCREEN_DrawSkillDamageRight_Original = nullptr;


void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawSkillDamageLeft(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREEN_DrawSkillDamageLeft(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawSkillDamageRight(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    CHARSCREEN_DrawSkillDamageRight_Original(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);;
}
