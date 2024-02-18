#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <SKILLS/SkillItem_ESE.h>

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

extern decltype(&SKILLITEM_pSpell01_Initializer) SKILLITEM_pSpell01_Initializer_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell01_Initializer), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer)>, "ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell01_IdentifyItem) SKILLITEM_pSpell01_IdentifyItem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell01_IdentifyItem), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem)>, "ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell02_CastPortal) SKILLITEM_pSpell02_CastPortal_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell02_CastPortal), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal)>, "ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell03_Potion) SKILLITEM_pSpell03_Potion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell03_Potion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell03_Potion), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell03_Potion)>, "ESE_INTERCEPT_SKILLITEM_pSpell03_Potion has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell04_Unused) SKILLITEM_pSpell04_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell04_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell04_Unused), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell04_Unused)>, "ESE_INTERCEPT_SKILLITEM_pSpell04_Unused has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell05_RejuvPotion) SKILLITEM_pSpell05_RejuvPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell05_RejuvPotion), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion)>, "ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell09_StaminaPotion) SKILLITEM_pSpell09_StaminaPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell09_StaminaPotion), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion)>, "ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell09_AntidoteThawingPotion) SKILLITEM_pSpell09_AntidoteThawingPotion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell09_AntidoteThawingPotion), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion)>, "ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell08_ExperienceElixir) SKILLITEM_pSpell08_ExperienceElixir_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell08_ExperienceElixir), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir)>, "ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell07_OpenCube) SKILLITEM_pSpell07_OpenCube_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell07_OpenCube), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube)>, "ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell10_CastFireBallOnTarget) SKILLITEM_pSpell10_CastFireBallOnTarget_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell10_CastFireBallOnTarget), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget)>, "ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell11_CastFireBallToCoordinates) SKILLITEM_pSpell11_CastFireBallToCoordinates_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell11_CastFireBallToCoordinates), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates)>, "ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates has a different type than previously known.");

extern decltype(&SKILLITEM_pSpell_Handler) SKILLITEM_pSpell_Handler_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY);
static_assert(std::is_same_v<decltype(&SKILLITEM_pSpell_Handler), decltype(&ESE_INTERCEPT_SKILLITEM_pSpell_Handler)>, "ESE_INTERCEPT_SKILLITEM_pSpell_Handler has a different type than previously known.");

extern decltype(&SKILLS_SrvDo113_Scroll_Book) SKILLS_SrvDo113_Scroll_Book_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLS_SrvDo113_Scroll_Book), decltype(&ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book)>, "ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book has a different type than previously known.");

extern decltype(&SKILLITEM_ActivateAura) SKILLITEM_ActivateAura_Original;
void __fastcall ESE_INTERCEPT_SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_ActivateAura), decltype(&ESE_INTERCEPT_SKILLITEM_ActivateAura)>, "ESE_INTERCEPT_SKILLITEM_ActivateAura has a different type than previously known.");

extern decltype(&SKILLITEM_DeactivateAura) SKILLITEM_DeactivateAura_Original;
void __fastcall ESE_INTERCEPT_SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a4, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SKILLITEM_DeactivateAura), decltype(&ESE_INTERCEPT_SKILLITEM_DeactivateAura)>, "ESE_INTERCEPT_SKILLITEM_DeactivateAura has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc06_AttackerTakesDamage) SKILLITEM_EventFunc06_AttackerTakesDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc06_AttackerTakesDamage), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage)>, "ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc10_AttackerTakesLightDamage) SKILLITEM_EventFunc10_AttackerTakesLightDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc10_AttackerTakesLightDamage), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage)>, "ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc11_ApplyFireDamage) SKILLITEM_EventFunc11_ApplyFireDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc11_ApplyFireDamage), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage)>, "ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc12_ApplyColdDamage) SKILLITEM_EventFunc12_ApplyColdDamage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc12_ApplyColdDamage), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage)>, "ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc07_Knockback) SKILLITEM_EventFunc07_Knockback_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc07_Knockback), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback)>, "ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc08_Howl) SKILLITEM_EventFunc08_Howl_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc08_Howl), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl)>, "ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc09_Stupidity) SKILLITEM_EventFunc09_Stupidity_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc09_Stupidity), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity)>, "ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc13_DamageToMana) SKILLITEM_EventFunc13_DamageToMana_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc13_DamageToMana), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana)>, "ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc14_Freeze) SKILLITEM_EventFunc14_Freeze_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc14_Freeze), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze)>, "ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze has a different type than previously known.");

extern decltype(&SKILLITEM_CalculateOpenWoundsHpRegen) SKILLITEM_CalculateOpenWoundsHpRegen_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen(int32_t nLevel, const int32_t* pValues);
static_assert(std::is_same_v<decltype(&SKILLITEM_CalculateOpenWoundsHpRegen), decltype(&ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen)>, "ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc15_OpenWounds) SKILLITEM_EventFunc15_OpenWounds_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc15_OpenWounds), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds)>, "ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc16_CrushingBlow) SKILLITEM_EventFunc16_CrushingBlow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc16_CrushingBlow), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow)>, "ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc17_ManaAfterKill) SKILLITEM_EventFunc17_ManaAfterKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc17_ManaAfterKill), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill)>, "ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc28_HealAfterKill) SKILLITEM_EventFunc28_HealAfterKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc28_HealAfterKill), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill)>, "ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc18_HealAfterDemonKill) SKILLITEM_EventFunc18_HealAfterDemonKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc18_HealAfterDemonKill), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill)>, "ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc19_Slow) SKILLITEM_EventFunc19_Slow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc19_Slow), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow)>, "ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc20_SkillOnAttackHitKill) SKILLITEM_EventFunc20_SkillOnAttackHitKill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc20_SkillOnAttackHitKill), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill)>, "ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc21_SkillOnGetHit) SKILLITEM_EventFunc21_SkillOnGetHit_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc21_SkillOnGetHit), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit)>, "ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc30_SkillOnDeathLevelup) SKILLITEM_EventFunc30_SkillOnDeathLevelup_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc30_SkillOnDeathLevelup), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup)>, "ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc29_RestInPeace) SKILLITEM_EventFunc29_RestInPeace_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc29_RestInPeace), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace)>, "ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace has a different type than previously known.");

extern decltype(&SKILLITEM_TimerCallback_ReanimateMonster) SKILLITEM_TimerCallback_ReanimateMonster_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pSource, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int32_t nMonId, int32_t nOwnerId);
static_assert(std::is_same_v<decltype(&SKILLITEM_TimerCallback_ReanimateMonster), decltype(&ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster)>, "ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster has a different type than previously known.");

extern decltype(&SKILLITEM_EventFunc31_Reanimate) SKILLITEM_EventFunc31_Reanimate_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_EventFunc31_Reanimate), decltype(&ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate)>, "ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate has a different type than previously known.");

extern decltype(&SKILLITEM_FindTargetPosition) SKILLITEM_FindTargetPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&SKILLITEM_FindTargetPosition), decltype(&ESE_INTERCEPT_SKILLITEM_FindTargetPosition)>, "ESE_INTERCEPT_SKILLITEM_FindTargetPosition has a different type than previously known.");

extern decltype(&SKILLITEM_HandleItemEffectSkill) SKILLITEM_HandleItemEffectSkill_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t nX, int32_t nY, int32_t* pUnitType, int32_t* pUnitGUID, int32_t* pX, int32_t* pY, int32_t a7);
static_assert(std::is_same_v<decltype(&SKILLITEM_HandleItemEffectSkill), decltype(&ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill)>, "ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill has a different type than previously known.");

extern decltype(&SKILLITEM_CastSkillOnTarget) SKILLITEM_CastSkillOnTarget_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t a5);
static_assert(std::is_same_v<decltype(&SKILLITEM_CastSkillOnTarget), decltype(&ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget)>, "ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget has a different type than previously known.");

extern decltype(&SKILLITEM_CastSkillOnPosition) SKILLITEM_CastSkillOnPosition_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t a0);
static_assert(std::is_same_v<decltype(&SKILLITEM_CastSkillOnPosition), decltype(&ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition)>, "ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition has a different type than previously known.");

