#include <UNIT/SUnit_ESE.h>

#include <D2BitManip.h>

#include <D2Dungeon.h>
#include <Drlg/D2DrlgDrlg.h>
#include <Drlg/D2DrlgPreset.h>
#include <Units/UnitRoom.h>
#include <D2StatList.h>
#include <D2Collision.h>
#include <D2States.h>
#include <D2Monsters.h>
#include <D2Items.h>
#include <DataTbls/MonsterIds.h>
#include <DataTbls/LevelsIds.h>
#include <Path/PathMisc.h>


#include "AI/AiGeneral.h"
#include "GAME/Arena.h"
#include "GAME/Clients.h"
#include "GAME/Event.h"
#include "GAME/Game.h"
#include "GAME/SCmd.h"
#include "GAME/Targets.h"
#include "INVENTORY/InvMode.h"
#include "ITEMS/ItemMode.h"
#include "ITEMS/Items.h"
#include "MISSILES/Missiles.h"
#include "MONSTER/Monster.h"
#include "MONSTER/MonsterAI.h"
#include "MONSTER/MonsterMode_ESE.h"
#include "MONSTER/MonsterRegion.h"
#include "OBJECTS/Objects.h"
#include "OBJECTS/ObjMode.h"
#include "PLAYER/Player.h"
#include "PLAYER/PlayerList.h"
#include "PLAYER/PlayerPets.h"
#include "PLAYER/PlrModes.h"
#include "QUESTS/Quests.h"
#include "SKILLS/SkillAss_ESE.h"
#include "UNIT/Party.h"
#include "UNIT/SUnitDmg_ESE.h"
#include "UNIT/SUnitEvent_ESE.h"
#include "UNIT/SUnitMsg.h"
#include "UNIT/SUnitProxy.h"

//D2Game.0x6FCBDE90
void __fastcall ESE_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable)
{
    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, bSetUninterruptable);

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    if (!bSetUninterruptable && STATES_CheckState(pUnit, STATE_DEATH_DELAY))
    {
        STATES_ToggleState(pUnit, STATE_DEATH_DELAY, 0);

        D2UnitStrc* pAttacker = SUNIT_GetLastAttacker(pGame, pUnit);
        if (pAttacker)
        {
            D2DamageStrc damage = {};
            damage.wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
            ESE_SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
        }
        else
        {
            ESE_SUNITDMG_KillMonster(pGame, pUnit, nullptr, 1);
        }
    }

    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, UNITEVENTCALLBACK_AITHINK, 0);
    }
}
