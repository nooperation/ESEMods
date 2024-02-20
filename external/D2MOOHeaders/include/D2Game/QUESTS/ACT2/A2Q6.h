#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Duriel
struct D2Act2Quest6Strc							//sizeof 0x68
{
	uint8_t unk0x00;							//0x00 TODO
	uint8_t bDurielKilled;						//0x01
	uint8_t unk0x02;							//0x02 TOOO
	uint8_t bTimerActive;						//0x03
	uint8_t bHoradricOrificeInitialized;		//0x04
	uint8_t bTyraelsDoorInitialized;			//0x05
	uint8_t bUnusedObjectInitialized;			//0x06
	uint8_t unused0x07;							//0x07
	uint8_t bInitJerhynActivated;				//0x08
	uint8_t bTyraelActivated;					//0x09
	uint8_t bEndJerhynActivated;				//0x0A
	uint8_t bDurielLairTombOpen;				//0x0B
	uint8_t bDurielLairPortalNeedsToOpen;		//0x0C
	uint8_t bObjectsNeedUpdate;					//0x0D
	uint8_t bStaffItemsRemoved;					//0x0E
	uint8_t bPortalToLutGholeinOpened;			//0x0F
	uint8_t bHoradricStaffIsMissing;			//0x10
	uint8_t pad0x11[3];							//0x11
	int nQuestStatus;							//0x14
	int nTyraelsDoorObjectMode;					//0x18
	int unk0x1C;								//0x1C
	int nHoradricOrificeGUID;					//0x20
	uint8_t unused0x24[4];						//0x24
	int nUnusedObjectGUID;						//0x28
	int nTyraelsDoorGUID;						//0x2C
	uint8_t unused0x30[4];						//0x30
	int nStaffTombLevelId;						//0x34
	uint8_t bObjectIdsInitialized;				//0x38
	uint8_t pad0x39;							//0x39
	uint16_t nArcaneThings;						//0x3A
	uint8_t bPortalIsOpening;					//0x3C
	uint8_t bRewardedOrCompletedBefore;			//0x3D
	uint8_t pad0x3E[2];							//0x3E
	D2UnitStrc* pTyrael;						//0x40
	uint8_t bCloseToTyrael;						//0x44
	uint8_t pad0x45[3];							//0x45
	int nArcaneThingObjectIds[6];				//0x48
	D2ActiveRoomStrc* pDurielRoom;					//0x60
	int unused0x64;								//0x64
};

#pragma pack()
