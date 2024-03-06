#pragma once

#include <D2Client/CharScreen_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void (__fastcall* CHARSCREEN_DrawSkillDamageLeft_t)(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
typedef void (__fastcall* CHARSCREEN_DrawSkillDamageRight_t)(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

extern CHARSCREEN_DrawSkillDamageLeft_t CHARSCREEN_DrawSkillDamageLeft_Original;
extern CHARSCREEN_DrawSkillDamageRight_t CHARSCREEN_DrawSkillDamageRight_Original;

//D2Client.0x6FB0E800 (6E800)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawSkillDamageLeft(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0DEC0 (6DEC0)
void __fastcall ESE_INTERCEPT_CHARSCREEN_DrawSkillDamageRight(D2UnitStrc* pUnit, D2SkillStrc *pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0B140 (6B140)
// struct Unicode *__fastcall PrintRangeString(struct Unicode *pText, int minDamage, int maxDamage, int isAdditonRange, int allowThousandsSuffix)

//D2Client.0x6FACFCD0 (2FCD0)
// void __fastcall DrawTextCentered(int nX, int nY, int maxWidthMaybe, const Unicode *text, int nColor)

