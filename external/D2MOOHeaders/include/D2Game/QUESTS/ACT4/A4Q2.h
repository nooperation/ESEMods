#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Diablo
struct D2Act4Quest2Strc						//sizeof 0x4C
{
	uint8_t bTalkedToTyrael;				//0x00
	uint8_t bTimerCreated;					//0x01
	uint8_t bNeedToSpawnDiablo;				//0x02
	uint8_t unk0x03;						//0x03 TODO
	uint8_t bNeedToEndGame;					//0x04
	uint8_t bNeedToWarpPlayers;				//0x05
	uint8_t bDiabloStartPointInitialized;	//0x06
	uint8_t pad0x07;						//0x07
	int nDiabloStartPointObjectGUID;		//0x08
	uint8_t bSealActivated[5];				//0x0C
	uint8_t bDiabloSpawned;					//0x11
	uint8_t unused0x12;						//0x12
	uint8_t bSanctumCleared;				//0x13
	uint8_t bDiabloKilled;					//0x14
	uint8_t bClientsSaved;					//0x15
	uint8_t pad0x16[2];						//0x16
	uint32_t dwTickCount;					//0x18 TODO: What TickCount?
	int nPlayerCount;						//0x1C
	D2UnitStrc* unk0x20;					//0x20 TODO
	D2CoordStrc pSealCoords[3];				//0x24
	D2ActiveRoomStrc* pRoom;						//0x3C
	int nLastLastPortalObjectMode;			//0x40
	uint8_t unk0x44;						//0x44 TODO
	uint8_t bPortalToAct5Spawned;			//0x45
	uint8_t pad0x46[2];						//0x46
	int nBossesKilled;						//0x48
};

#pragma pack()
