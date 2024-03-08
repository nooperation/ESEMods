#include "D2Client/CHARSCREENDMG_ESE_Intercepts.h"
#include "LibESE.h"

extern CHARSCREENDMG_DrawDescDam1_t CHARSCREENDMG_DrawDescDam1_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam2_t CHARSCREENDMG_DrawDescDam2_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam3_t CHARSCREENDMG_DrawDescDam3_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam4_t CHARSCREENDMG_DrawDescDam4_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam5_t CHARSCREENDMG_DrawDescDam5_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam6_t CHARSCREENDMG_DrawDescDam6_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam7_t CHARSCREENDMG_DrawDescDam7_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam8_t CHARSCREENDMG_DrawDescDam8_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam9_t CHARSCREENDMG_DrawDescDam9_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam10_t CHARSCREENDMG_DrawDescDam10_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam11_t CHARSCREENDMG_DrawDescDam11_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam12_t CHARSCREENDMG_DrawDescDam12_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam13_t CHARSCREENDMG_DrawDescDam13_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam14_t CHARSCREENDMG_DrawDescDam14_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam15_t CHARSCREENDMG_DrawDescDam15_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam16_t CHARSCREENDMG_DrawDescDam16_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam17_t CHARSCREENDMG_DrawDescDam17_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam18_t CHARSCREENDMG_DrawDescDam18_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam19_t CHARSCREENDMG_DrawDescDam19_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam20_t CHARSCREENDMG_DrawDescDam20_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam21_t CHARSCREENDMG_DrawDescDam21_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam22_t CHARSCREENDMG_DrawDescDam22_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam23_t CHARSCREENDMG_DrawDescDam23_Original = nullptr;
extern CHARSCREENDMG_DrawDescDam24_t CHARSCREENDMG_DrawDescDam24_Original = nullptr;

//D2Client.0x6FB0C270 (6C270)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam1(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam1(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CD40 (6CD40)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam2(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam2(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0D330 (6D330)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam3(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam3(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0D920 (6D920)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam4(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam4(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0DEC0 (6DEC0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam5(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam5(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0ACE0 (6ACE0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam6(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam6(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0BEC0 (6BEC0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam7(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam7(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E800 (6E800)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam8(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam8(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0EAB0 (6EAB0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam9(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam9(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0ED40 (6ED40)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam10(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam10(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0F080 (6F080)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam11(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam11(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0F700 (6F700)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam12(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam12(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E7B0 (6E7B0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam13(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam13(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0FA50 (6FA50)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam14(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam14(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0FC60 (6FC60)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam15(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam15(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB10010 (70010)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam16(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam16(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB10540 (70540)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam17(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam17(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB108F0 (708F0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam18(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam18(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CA60 (6CA60)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam19(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam19(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0C930 (6C930)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam20(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam20(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0CE90 (6CE90)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam21(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam21(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0DAB0 (6DAB0)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam22(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam22(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E440 (6E440)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam23(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam23(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}

//D2Client.0x6FB0E180 (6E180)
void __fastcall ESE_INTERCEPT_CHARSCREENDMG_DrawDescDam24(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillLevel, int offsetA, int offsetB, int offsetC)
{
    ESE_CHARSCREENDMG_DrawDescDam24(pUnit, pSkill, pSkillsTxtRecord, nSkillLevel, offsetA, offsetB, offsetC);
}
