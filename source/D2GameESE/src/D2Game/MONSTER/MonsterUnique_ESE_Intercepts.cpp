#include "D2Game/MONSTER/MonsterUnique_ESE_Intercepts.h"

MONSTERUNIQUE_CalculatePercentage_t MONSTERUNIQUE_CalculatePercentage_Original = nullptr;
MONSTERUNIQUE_UMod16_Champion_t MONSTERUNIQUE_UMod16_Champion_Original = nullptr;
MONSTERUNIQUE_UMod36_Ghostly_t MONSTERUNIQUE_UMod36_Ghostly_Original = nullptr;
MONSTERUNIQUE_UMod39_Berserk_t MONSTERUNIQUE_UMod39_Berserk_Original = nullptr;
MONSTERUNIQUE_UMod8_Resistant_t MONSTERUNIQUE_UMod8_Resistant_Original = nullptr;
MONSTERUNIQUE_UMod5_Strong_t MONSTERUNIQUE_UMod5_Strong_Original = nullptr;
MONSTERUNIQUE_UMod9_FireEnchanted_t MONSTERUNIQUE_UMod9_FireEnchanted_Original = nullptr;
MONSTERUNIQUE_UMod17_LightningEnchanted_t MONSTERUNIQUE_UMod17_LightningEnchanted_Original = nullptr;
MONSTERUNIQUE_UMod18_ColdEnchanted_t MONSTERUNIQUE_UMod18_ColdEnchanted_Original = nullptr;
MONSTERUNIQUE_UMod23_PoisonEnchanted_t MONSTERUNIQUE_UMod23_PoisonEnchanted_Original = nullptr;
MONSTERUNIQUE_UMod25_ManaSteal_t MONSTERUNIQUE_UMod25_ManaSteal_Original = nullptr;
MONSTERUNIQUE_CastCorpseExplode_t MONSTERUNIQUE_CastCorpseExplode_Original = nullptr;
MONSTERUNIQUE_CastCorpseExplode2_t MONSTERUNIQUE_CastCorpseExplode2_Original = nullptr;
sub_6FC6CF10_t sub_6FC6CF10_Original = nullptr;
sub_6FC6CF90_t sub_6FC6CF90_Original = nullptr;
MONSTERUNIQUE_ApplyElementalDamage_t MONSTERUNIQUE_ApplyElementalDamage_Original = nullptr;
sub_6FC6E240_t sub_6FC6E240_Original = nullptr;
MONSTERUNIQUE_CastSuicideExplodeMissile_t MONSTERUNIQUE_CastSuicideExplodeMissile_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3)
{
    return ESE_MONSTERUNIQUE_CalculatePercentage(a1, a2, a3);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod16_Champion(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod36_Ghostly(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod39_Berserk(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod5_Strong(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod9_FireEnchanted(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod17_LightningEnchanted(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod18_ColdEnchanted(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod23_PoisonEnchanted(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_UMod25_ManaSteal(pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_CastCorpseExplode(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_CastCorpseExplode2(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_sub_6FC6CF10(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_sub_6FC6CF90(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_ApplyElementalDamage(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_sub_6FC6E240(pGame, pUnit, nUMod, bUnique);
}

void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique)
{
    ESE_MONSTERUNIQUE_CastSuicideExplodeMissile(pGame, pUnit, nUMod, bUnique);
}
