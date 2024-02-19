#include <MONSTER/MonsterUnique_ESE_Intercepts.h>

decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod16_Champion) MONSTERUNIQUE_UMod16_Champion_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod36_Ghostly) MONSTERUNIQUE_UMod36_Ghostly_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod39_Berserk) MONSTERUNIQUE_UMod39_Berserk_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod8_Resistant) MONSTERUNIQUE_UMod8_Resistant_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod5_Strong) MONSTERUNIQUE_UMod5_Strong_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod9_FireEnchanted) MONSTERUNIQUE_UMod9_FireEnchanted_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod17_LightningEnchanted) MONSTERUNIQUE_UMod17_LightningEnchanted_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod18_ColdEnchanted) MONSTERUNIQUE_UMod18_ColdEnchanted_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod23_PoisonEnchanted) MONSTERUNIQUE_UMod23_PoisonEnchanted_Original = nullptr;
decltype(&MONSTERUNIQUE_UMod25_ManaSteal) MONSTERUNIQUE_UMod25_ManaSteal_Original = nullptr;
decltype(&MONSTERUNIQUE_CastCorpseExplode) MONSTERUNIQUE_CastCorpseExplode_Original = nullptr;
decltype(&MONSTERUNIQUE_CastCorpseExplode2) MONSTERUNIQUE_CastCorpseExplode2_Original = nullptr;
decltype(&sub_6FC6CF10) sub_6FC6CF10_Original = nullptr;
decltype(&sub_6FC6CF90) sub_6FC6CF90_Original = nullptr;
decltype(&MONSTERUNIQUE_ApplyElementalDamage) MONSTERUNIQUE_ApplyElementalDamage_Original = nullptr;
decltype(&sub_6FC6E240) sub_6FC6E240_Original = nullptr;
decltype(&MONSTERUNIQUE_CastSuicideExplodeMissile) MONSTERUNIQUE_CastSuicideExplodeMissile_Original = nullptr;

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
