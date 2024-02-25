#include "D2Game/SKILLS/SkillItem_ESE_Intercepts.h"

SKILLITEM_pSpell01_Initializer_t SKILLITEM_pSpell01_Initializer_Original = nullptr;
SKILLITEM_pSpell01_IdentifyItem_t SKILLITEM_pSpell01_IdentifyItem_Original = nullptr;
SKILLITEM_pSpell02_CastPortal_t SKILLITEM_pSpell02_CastPortal_Original = nullptr;
SKILLITEM_pSpell03_Potion_t SKILLITEM_pSpell03_Potion_Original = nullptr;
SKILLITEM_pSpell04_Unused_t SKILLITEM_pSpell04_Unused_Original = nullptr;
SKILLITEM_pSpell05_RejuvPotion_t SKILLITEM_pSpell05_RejuvPotion_Original = nullptr;
SKILLITEM_pSpell09_StaminaPotion_t SKILLITEM_pSpell09_StaminaPotion_Original = nullptr;
SKILLITEM_pSpell09_AntidoteThawingPotion_t SKILLITEM_pSpell09_AntidoteThawingPotion_Original = nullptr;
SKILLITEM_pSpell08_ExperienceElixir_t SKILLITEM_pSpell08_ExperienceElixir_Original = nullptr;
SKILLITEM_pSpell07_OpenCube_t SKILLITEM_pSpell07_OpenCube_Original = nullptr;
SKILLITEM_pSpell10_CastFireBallOnTarget_t SKILLITEM_pSpell10_CastFireBallOnTarget_Original = nullptr;
SKILLITEM_pSpell11_CastFireBallToCoordinates_t SKILLITEM_pSpell11_CastFireBallToCoordinates_Original = nullptr;
SKILLITEM_pSpell_Handler_t SKILLITEM_pSpell_Handler_Original = nullptr;
SKILLS_SrvDo113_Scroll_Book_t SKILLS_SrvDo113_Scroll_Book_Original = nullptr;
SKILLITEM_ActivateAura_t SKILLITEM_ActivateAura_Original = nullptr;
SKILLITEM_DeactivateAura_t SKILLITEM_DeactivateAura_Original = nullptr;
SKILLITEM_EventFunc06_AttackerTakesDamage_t SKILLITEM_EventFunc06_AttackerTakesDamage_Original = nullptr;
SKILLITEM_EventFunc10_AttackerTakesLightDamage_t SKILLITEM_EventFunc10_AttackerTakesLightDamage_Original = nullptr;
SKILLITEM_EventFunc11_ApplyFireDamage_t SKILLITEM_EventFunc11_ApplyFireDamage_Original = nullptr;
SKILLITEM_EventFunc12_ApplyColdDamage_t SKILLITEM_EventFunc12_ApplyColdDamage_Original = nullptr;
SKILLITEM_EventFunc07_Knockback_t SKILLITEM_EventFunc07_Knockback_Original = nullptr;
SKILLITEM_EventFunc08_Howl_t SKILLITEM_EventFunc08_Howl_Original = nullptr;
SKILLITEM_EventFunc09_Stupidity_t SKILLITEM_EventFunc09_Stupidity_Original = nullptr;
SKILLITEM_EventFunc13_DamageToMana_t SKILLITEM_EventFunc13_DamageToMana_Original = nullptr;
SKILLITEM_EventFunc14_Freeze_t SKILLITEM_EventFunc14_Freeze_Original = nullptr;
SKILLITEM_CalculateOpenWoundsHpRegen_t SKILLITEM_CalculateOpenWoundsHpRegen_Original = nullptr;
SKILLITEM_EventFunc15_OpenWounds_t SKILLITEM_EventFunc15_OpenWounds_Original = nullptr;
SKILLITEM_EventFunc16_CrushingBlow_t SKILLITEM_EventFunc16_CrushingBlow_Original = nullptr;
SKILLITEM_EventFunc17_ManaAfterKill_t SKILLITEM_EventFunc17_ManaAfterKill_Original = nullptr;
SKILLITEM_EventFunc28_HealAfterKill_t SKILLITEM_EventFunc28_HealAfterKill_Original = nullptr;
SKILLITEM_EventFunc18_HealAfterDemonKill_t SKILLITEM_EventFunc18_HealAfterDemonKill_Original = nullptr;
SKILLITEM_EventFunc19_Slow_t SKILLITEM_EventFunc19_Slow_Original = nullptr;
SKILLITEM_EventFunc20_SkillOnAttackHitKill_t SKILLITEM_EventFunc20_SkillOnAttackHitKill_Original = nullptr;
SKILLITEM_EventFunc21_SkillOnGetHit_t SKILLITEM_EventFunc21_SkillOnGetHit_Original = nullptr;
SKILLITEM_EventFunc30_SkillOnDeathLevelup_t SKILLITEM_EventFunc30_SkillOnDeathLevelup_Original = nullptr;
SKILLITEM_EventFunc29_RestInPeace_t SKILLITEM_EventFunc29_RestInPeace_Original = nullptr;
SKILLITEM_TimerCallback_ReanimateMonster_t SKILLITEM_TimerCallback_ReanimateMonster_Original = nullptr;
SKILLITEM_EventFunc31_Reanimate_t SKILLITEM_EventFunc31_Reanimate_Original = nullptr;
SKILLITEM_FindTargetPosition_t SKILLITEM_FindTargetPosition_Original = nullptr;
SKILLITEM_HandleItemEffectSkill_t SKILLITEM_HandleItemEffectSkill_Original = nullptr;
SKILLITEM_CastSkillOnTarget_t SKILLITEM_CastSkillOnTarget_Original = nullptr;
SKILLITEM_CastSkillOnPosition_t SKILLITEM_CastSkillOnPosition_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell01_Initializer(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell01_IdentifyItem(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell02_CastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell02_CastPortal(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell03_Potion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell03_Potion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell04_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell04_Unused(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell05_RejuvPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell09_StaminaPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell09_AntidoteThawingPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell09_AntidoteThawingPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell08_ExperienceElixir(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell08_ExperienceElixir(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell07_OpenCube(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell10_CastFireBallOnTarget(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY, int32_t nSkillId)
{
    return ESE_SKILLITEM_pSpell11_CastFireBallToCoordinates(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int32_t nX, int32_t nY)
{
    return ESE_SKILLITEM_pSpell_Handler(pGame, pUnit, pItem, pTarget, nX, nY);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo113_Scroll_Book(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_SKILLITEM_ActivateAura(pGame, pUnit, a5, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a4, int32_t nSkillId)
{
    ESE_SKILLITEM_DeactivateAura(pGame, pUnit, a4, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc06_AttackerTakesDamage(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc10_AttackerTakesLightDamage(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc11_ApplyFireDamage(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc12_ApplyColdDamage(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc07_Knockback(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc07_Knockback(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc08_Howl(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc09_Stupidity(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc13_DamageToMana(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc13_DamageToMana(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc14_Freeze(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc14_Freeze(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CalculateOpenWoundsHpRegen(int32_t nLevel, const int32_t* pValues)
{
    return ESE_SKILLITEM_CalculateOpenWoundsHpRegen(nLevel, pValues);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc15_OpenWounds(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc16_CrushingBlow(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc17_ManaAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc17_ManaAfterKill(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc28_HealAfterKill(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc18_HealAfterDemonKill(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc19_Slow(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc20_SkillOnAttackHitKill(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc21_SkillOnGetHit(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc30_SkillOnDeathLevelup(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc29_RestInPeace(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pSource, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int32_t nMonId, int32_t nOwnerId)
{
    return ESE_SKILLITEM_TimerCallback_ReanimateMonster(pGame, nEvent, pSource, pTarget, pDamage, nMonId, nOwnerId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_EventFunc31_Reanimate(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_EventFunc31_Reanimate(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLITEM_FindTargetPosition(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t nX, int32_t nY, int32_t* pUnitType, int32_t* pUnitGUID, int32_t* pX, int32_t* pY, int32_t a7)
{
    return ESE_SKILLITEM_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, pTargetUnit, nX, nY, pUnitType, pUnitGUID, pX, pY, a7);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, D2UnitStrc* pTargetUnit, int32_t a5)
{
    return ESE_SKILLITEM_CastSkillOnTarget(pUnit, nSkillId, nSkillLevel, pTargetUnit, a5);
}

int32_t __fastcall ESE_INTERCEPT_SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t a0)
{
    return ESE_SKILLITEM_CastSkillOnPosition(pUnit, nSkillId, nSkillLevel, nX, nY, a0);
}


