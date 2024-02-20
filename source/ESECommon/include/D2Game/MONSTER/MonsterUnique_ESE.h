#pragma once

#include <../D2MooHeaders.h>
#include <MONSTER/MonsterUnique.h>
#include <Units/Units.h>
#include <DataTbls/MissilesTbls.h>
#include <DataTbls/MonsterTbls.h>
#include <Drlg/D2DrlgDrlg.h>

//D2Game.0x6FC6AF70
int32_t __fastcall ESE_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3);
//D2Game.0x6FC6B030
void __fastcall ESE_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B210
void __fastcall ESE_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B4B0
void __fastcall ESE_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B610
void __fastcall ESE_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BA70
void __fastcall ESE_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BC10
void __fastcall ESE_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BDD0
void __fastcall ESE_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BF90
void __fastcall ESE_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C160
void __fastcall ESE_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C340
void __fastcall ESE_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C740
void __fastcall ESE_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C9E0
void __fastcall ESE_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CF10
void __fastcall ESE_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CF90
void __fastcall ESE_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D1C0
void __fastcall ESE_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E240
void __fastcall ESE_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E410
void __fastcall ESE_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);