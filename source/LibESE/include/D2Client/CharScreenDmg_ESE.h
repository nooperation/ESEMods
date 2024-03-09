#pragma once

#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void(__fastcall* DamageCallback7D0_t)(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* pItem);

void __fastcall ESE_sub_6FB0F5E0(D2UnitStrc* pUnit, int64_t nMinDamage, int64_t nMaxDamage, int nColor, int offsetA, int offsetB, int offsetC);
void __fastcall ESE_PrintRangeString_6FB0B140(wchar_t* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange, int allowThousandsSuffix);
void __fastcall ESE_sub_6FB0AC10(Unicode* pTextA, Unicode* pTextB, int offsetA, int offsetB, int offsetC, int nColorA, int nColorB);
void __fastcall ESE_sub_6FB0B0F0(struct Unicode* pText, int64_t damage, int isAdditonRange);
void __fastcall ESE_sub_6FB0B250(struct Unicode* pText, int64_t minDamage, int64_t maxDamage, int isAdditonRange);
void __fastcall ESE_sub_6FB0B6F0(D2UnitStrc* pUnit, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int32_t* pColor, D2UnitStrc* pItem, D2SkillStrc* pSkill);
void __fastcall ESE_sub_6FB0D4F0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalWeaponMasteryBonus, int64_t a6, D2SkillStrc* pSkill, int64_t a8, D2UnitStrc* pItem);
void __fastcall ESE_sub_6FB0B2C0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* item, int32_t unknown7);
void __fastcall ESE_sub_6FB0BB10(D2UnitStrc* pUnit, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int32_t* pColor);
void __fastcall ESE_sub_6FB0C3A0(D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, int32_t* pColor, int64_t additionalDamagePct, int64_t additionalDamage, D2SkillStrc* pSkill, int64_t nSrcDamOverride, D2UnitStrc* pItem);
int __fastcall ESE_sub_6FB0A7D0(D2UnitStrc* pUnit, int64_t* pMinDamageA, int64_t* pMaxDamageA, int32_t* pColorA, int64_t* pMinDamageB, int64_t* pMaxDamageB, int32_t* pColorB, D2SkillStrc* pSkill, DamageCallback7D0_t callback, int64_t ddamCalc1, int64_t ddamCalc2);
void __fastcall ESE_sub_6FB0C840(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillLevel, int64_t* pMinElemDamage, int64_t* pMaxElemDamage, int* pColor);
void __fastcall ESE_sub_6FB0C400(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, DamageCallback7D0_t callback, int64_t ddamCalc1, int64_t ddamCalc2, int32_t offsetA, int32_t offsetB, int32_t offsetC, int32_t flag);
void __fastcall ESE_sub_6FB0BD60(const D2UnitStrc* pUnit, int64_t* pMinDamage, int64_t* pMaxDamage, uint8_t elemType);

//D2Client.0x6FB0C270 (6C270)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam1(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CD40 (6CD40)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam2(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0D330 (6D330)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam3(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0D920 (6D920)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam4(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0DEC0 (6DEC0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam5(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0ACE0 (6ACE0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam6(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0BEC0 (6BEC0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam7(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E800 (6E800)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam8(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0EAB0 (6EAB0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam9(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0ED40 (6ED40)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam10(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0F080 (6F080)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam11(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0F700 (6F700)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam12(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E7B0 (6E7B0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam13(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0FA50 (6FA50)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam14(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0FC60 (6FC60)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam15(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB10010 (70010)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam16(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB10540 (70540)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam17(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB108F0 (708F0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam18(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CA60 (6CA60)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam19(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0C930 (6C930)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam20(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0CE90 (6CE90)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam21(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0DAB0 (6DAB0)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam22(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E440 (6E440)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam23(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);

//D2Client.0x6FB0E180 (6E180)
void __fastcall ESE_CHARSCREENDMG_DrawDescDam24(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC);
