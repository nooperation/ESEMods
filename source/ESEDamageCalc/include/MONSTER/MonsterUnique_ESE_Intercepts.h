#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <DataTbls/MissilesTbls.h>
#include <DataTbls/MonsterTbls.h>
#include <Drlg/D2DrlgDrlg.h>

#include <MONSTER/MonsterUnique_ESE.h>

//D2Game.0x6FC6AF70
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3);
//D2Game.0x6FC6B030
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B210
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B4B0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B610
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BA70
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BC10
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BDD0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BF90
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C160
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C340
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C740
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C9E0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CF10
void __fastcall ESE_INTERCEPT_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CF90
void __fastcall ESE_INTERCEPT_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D1C0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E240
void __fastcall ESE_INTERCEPT_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E410
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3);

extern decltype(&MONSTERUNIQUE_UMod16_Champion) MONSTERUNIQUE_UMod16_Champion_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod36_Ghostly) MONSTERUNIQUE_UMod36_Ghostly_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod39_Berserk) MONSTERUNIQUE_UMod39_Berserk_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod8_Resistant) MONSTERUNIQUE_UMod8_Resistant_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod5_Strong) MONSTERUNIQUE_UMod5_Strong_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod9_FireEnchanted) MONSTERUNIQUE_UMod9_FireEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod17_LightningEnchanted) MONSTERUNIQUE_UMod17_LightningEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod18_ColdEnchanted) MONSTERUNIQUE_UMod18_ColdEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod23_PoisonEnchanted) MONSTERUNIQUE_UMod23_PoisonEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_UMod25_ManaSteal) MONSTERUNIQUE_UMod25_ManaSteal_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_CastCorpseExplode) MONSTERUNIQUE_CastCorpseExplode_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_CastCorpseExplode2) MONSTERUNIQUE_CastCorpseExplode2_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&sub_6FC6CF10) sub_6FC6CF10_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&sub_6FC6CF90) sub_6FC6CF90_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_ApplyElementalDamage) MONSTERUNIQUE_ApplyElementalDamage_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&sub_6FC6E240) sub_6FC6E240_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);

extern decltype(&MONSTERUNIQUE_CastSuicideExplodeMissile) MONSTERUNIQUE_CastSuicideExplodeMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
