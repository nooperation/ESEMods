#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/SKILLS/SkillItem_ESE.h"

#include <Units/Units.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FD02BA0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD02BF0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD02C80
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD02E10
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell03_Potion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD032D0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell04_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03610
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD039A0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03BB0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03C80
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03CD0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03D80
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03DF0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
//D2Game.0x6FD03E40
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY);
//D2Game.0x6FD040B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04270
void __fastcall ESE_INTERCEPT_SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04340
void __fastcall ESE_INTERCEPT_SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a4, int32_t nSkillId);
//D2Game.0x6FD043F0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD044B0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04570
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04630
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04720
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04820
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD048B0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD049D0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04B10
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04C40
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen(int32_t nLevel, const int32_t* pValues);
//D2Game.0x6FD04CF0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD04E50
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD050D0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05160
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD051E0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05270
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD053D0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05520
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05640
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05750
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05780
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pSource, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int32_t nMonId, int32_t nOwnerId);
//D2Game.0x6FD05B60
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05C20
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD05D70
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t nX, int32_t nY, int32_t* pUnitType, int32_t* pUnitGUID, int32_t* pX, int32_t* pY, int32_t a7);
//D2Game.0x6FD06020
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t a5);
//D2Game.0x6FD060F0
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t a0);

extern SKILLITEM_pSpell01_Initializer_t SKILLITEM_pSpell01_Initializer_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell01_IdentifyItem_t SKILLITEM_pSpell01_IdentifyItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell02_CastPortal_t SKILLITEM_pSpell02_CastPortal_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell03_Potion_t SKILLITEM_pSpell03_Potion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell03_Potion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell04_Unused_t SKILLITEM_pSpell04_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell04_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell05_RejuvPotion_t SKILLITEM_pSpell05_RejuvPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell09_StaminaPotion_t SKILLITEM_pSpell09_StaminaPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell09_AntidoteThawingPotion_t SKILLITEM_pSpell09_AntidoteThawingPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell08_ExperienceElixir_t SKILLITEM_pSpell08_ExperienceElixir_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell07_OpenCube_t SKILLITEM_pSpell07_OpenCube_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell10_CastFireBallOnTarget_t SKILLITEM_pSpell10_CastFireBallOnTarget_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell11_CastFireBallToCoordinates_t SKILLITEM_pSpell11_CastFireBallToCoordinates_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);

extern SKILLITEM_pSpell_Handler_t SKILLITEM_pSpell_Handler_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY);

extern SKILLS_SrvDo113_Scroll_Book_t SKILLS_SrvDo113_Scroll_Book_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_ActivateAura_t SKILLITEM_ActivateAura_Original;
void __fastcall ESE_INTERCEPT_SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_DeactivateAura_t SKILLITEM_DeactivateAura_Original;
void __fastcall ESE_INTERCEPT_SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a4, int32_t nSkillId);

extern SKILLITEM_EventFunc06_AttackerTakesDamage_t SKILLITEM_EventFunc06_AttackerTakesDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc10_AttackerTakesLightDamage_t SKILLITEM_EventFunc10_AttackerTakesLightDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc11_ApplyFireDamage_t SKILLITEM_EventFunc11_ApplyFireDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc12_ApplyColdDamage_t SKILLITEM_EventFunc12_ApplyColdDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc07_Knockback_t SKILLITEM_EventFunc07_Knockback_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc08_Howl_t SKILLITEM_EventFunc08_Howl_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc09_Stupidity_t SKILLITEM_EventFunc09_Stupidity_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc13_DamageToMana_t SKILLITEM_EventFunc13_DamageToMana_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc14_Freeze_t SKILLITEM_EventFunc14_Freeze_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_CalculateOpenWoundsHpRegen_t SKILLITEM_CalculateOpenWoundsHpRegen_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen(int32_t nLevel, const int32_t* pValues);

extern SKILLITEM_EventFunc15_OpenWounds_t SKILLITEM_EventFunc15_OpenWounds_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc16_CrushingBlow_t SKILLITEM_EventFunc16_CrushingBlow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc17_ManaAfterKill_t SKILLITEM_EventFunc17_ManaAfterKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc28_HealAfterKill_t SKILLITEM_EventFunc28_HealAfterKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc18_HealAfterDemonKill_t SKILLITEM_EventFunc18_HealAfterDemonKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc19_Slow_t SKILLITEM_EventFunc19_Slow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc20_SkillOnAttackHitKill_t SKILLITEM_EventFunc20_SkillOnAttackHitKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc21_SkillOnGetHit_t SKILLITEM_EventFunc21_SkillOnGetHit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc30_SkillOnDeathLevelup_t SKILLITEM_EventFunc30_SkillOnDeathLevelup_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_EventFunc29_RestInPeace_t SKILLITEM_EventFunc29_RestInPeace_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_TimerCallback_ReanimateMonster_t SKILLITEM_TimerCallback_ReanimateMonster_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pSource, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int32_t nMonId, int32_t nOwnerId);

extern SKILLITEM_EventFunc31_Reanimate_t SKILLITEM_EventFunc31_Reanimate_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_FindTargetPosition_t SKILLITEM_FindTargetPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLITEM_HandleItemEffectSkill_t SKILLITEM_HandleItemEffectSkill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t nX, int32_t nY, int32_t* pUnitType, int32_t* pUnitGUID, int32_t* pX, int32_t* pY, int32_t a7);

extern SKILLITEM_CastSkillOnTarget_t SKILLITEM_CastSkillOnTarget_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t a5);

extern SKILLITEM_CastSkillOnPosition_t SKILLITEM_CastSkillOnPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t a0);

