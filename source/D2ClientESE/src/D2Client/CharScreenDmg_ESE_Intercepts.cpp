#include "D2Client/CHARSCREENDMG_ESE_Intercepts.h"
#include "LibESE.h"

extern D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270_t D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40_t D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330_t D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920_t D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0_t D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0_t D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0_t D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800_t D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0_t D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40_t D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080_t D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700_t D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0_t D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50_t D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60_t D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010_t D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540_t D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0_t D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60_t D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930_t D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90_t D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0_t D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440_t D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440_Original = nullptr;
extern D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180_t D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180_Original = nullptr;

//D2Client.0x6FB0C270 (6C270)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam1_6FB0C270(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CD40 (6CD40)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam2_6FB0CD40(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0D330 (6D330)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam3_6FB0D330(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0D920 (6D920)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam4_6FB0D920(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0DEC0 (6DEC0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam5_6FB0DEC0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0ACE0 (6ACE0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam6_6FB0ACE0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0BEC0 (6BEC0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam7_6FB0BEC0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E800 (6E800)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam8_6FB0E800(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0EAB0 (6EAB0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam9_6FB0EAB0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0ED40 (6ED40)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam10_6FB0ED40(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0F080 (6F080)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam11_6FB0F080(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0F700 (6F700)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam12_6FB0F700(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E7B0 (6E7B0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam13_6FB0E7B0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0FA50 (6FA50)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam14_6FB0FA50(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0FC60 (6FC60)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam15_6FB0FC60(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB10010 (70010)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam16_6FB10010(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB10540 (70540)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam17_6FB10540(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB108F0 (708F0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam18_6FB108F0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CA60 (6CA60)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam19_6FB0CA60(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0C930 (6C930)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam20_6FB0C930(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CE90 (6CE90)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam21_6FB0CE90(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0DAB0 (6DAB0)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam22_6FB0DAB0(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E440 (6E440)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam23_6FB0E440(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E180 (6E180)
void __fastcall ESE_INTERCEPT_D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_D2Client_UI_CHARSCREENDMG_DrawDescDam24_6FB0E180(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}
