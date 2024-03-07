#pragma once

#include <Windows.h>
#include <cstdint>

#include <Drlg/D2DrlgDrlg.h>
#include <D2StatList.h>
#include <Units/UnitFinds.h>

struct Unicode;
struct D2SkillStrc;

void InitD2ClientExports();

typedef void(__fastcall * D2Client_DrawTextCentered_6FACFCD0_t)(int nX, int nY, int maxWidthMaybe, const Unicode* text, int nColor);
typedef void(__fastcall * D2Client_sub_6FB0B2C0_t)(D2UnitStrc* pUnit, int32_t *pUnknown1, int32_t* pUnknown2, int32_t* pColor, int32_t unknown3, int32_t unknown4, D2SkillStrc* pSkill, int32_t unknown5, int32_t unknown6, int32_t unknown7);
typedef void(__fastcall * D2Client_sub_6FB0B6F0_t)(D2UnitStrc* pUnit, int32_t *pUnknown1, int32_t *pUnknown2, int32_t* pColor, int32_t unknown3, D2SkillStrc* pSkill);

extern D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0;
extern D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0;
extern D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0;

extern int32_t * D2Client_pDWORD_6FBBA748; // 11A748
extern int32_t * D2Client_pDWORD_6FBBA74C; // 11A74C
extern int32_t * D2Client_pDWORD_6FB740F0; // D40F0
extern int32_t * D2Client_pDWORD_6FB8CCF8; // ECCF8
