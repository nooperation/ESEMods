#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Ancients
struct D2Act5Quest5Strc					//sizeof 0x64
{
	uint8_t bAncientsDefeated;			//0x00
	uint8_t bQualKehkActivated;			//0x01
	uint8_t unused0x02[2];				//0x02
	uint8_t bTimerActive;				//0x04
	uint8_t unused0x05[7];				//0x05
	int nActivePortalCount;				//0x0C
	uint8_t unk0x10;					//0x10 TODO
	uint8_t bActivatable;				//0x11
	uint8_t pad0x12[2];					//0x12
	int nAncientStatueGUID[3];			//0x14
	int nAncientMonsterGUID[3];			//0x20
	uint8_t bAncientMonsterSpawned[3];	//0x2C
	uint8_t pad0x2F;					//0x2F
	int nAncientStatueObjectMode[3];	//0x30
	uint8_t bAncienStatueRespawned[3];	//0x3C
	uint8_t pad0x3F;					//0x3F
	int nAncientsSpawned;				//0x40
	int nAncientsAlive;					//0x44
	uint8_t bAncientsActivated;			//0x48
	uint8_t unused0x49;					//0x49
	uint8_t bQuestCompletedBefore;		//0x4A
	uint8_t pad0x4B;					//0x4B
	int nAltarObjectMode;				//0x4C
	int nAltarGUID;						//0x50
	int nLivingPlayersOnSummit;			//0x54
	uint8_t bSummitDoorInitialized;		//0x58
	uint8_t pad0x59[3];					//0x59
	int nSummitDoorGUID;				//0x5C
	int nSummitDoorObjectMode;			//0x60
};

#pragma pack()
