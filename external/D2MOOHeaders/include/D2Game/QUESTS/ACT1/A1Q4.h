#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//RescueCain
struct D2Act1Quest4Strc								//sizeof 0x1BC
{
	uint16_t nStoneOrder[5];						//0x00
	uint16_t unused0x0A;							//0x0A
	uint16_t nCurrentMonolithNo;					//0x0C
	uint8_t pad0x0E[2];								//0x0E
	int nMonolithGUIDs[5];							//0x10
	int unused0x24;									//0x24
	int nInvisibleObjectGUID;						//0x28
	short nCairnStoneInteractions;					//0x2C
	uint8_t pad0x2E[2];								//0x2E
	int nInifussTreeGUID;							//0x30
	int nCainGibbetGUID;							//0x34
	int nDecipheredScrollGUID;						//0x38
	int nPlayerGUID;								//0x3C
	int nCairnStoneAlphaGUID;						//0x40
	uint8_t bOpenPortalTimerActive;					//0x44
	uint8_t bPortalToTristramOpened;				//0x45
	uint8_t bTimerActive;							//0x46
	uint8_t bInifussTreeInitialized;				//0x47
	uint8_t bCageModeChanged;						//0x48
	uint8_t bInvisbleObjectInitialized;				//0x49
	uint8_t bMonolithStonesOrdered;					//0x4A
	uint8_t unk0x4B;								//0x4B TODO
	uint8_t unk0x4C;								//0x4C TODO
	uint8_t bActivateCairnStones;					//0x4D
	uint8_t bDecipheredScrollAcquired;				//0x4E
	uint8_t bOperatedWithLastCairnStone;			//0x4F
	uint8_t unk0x50;								//0x50 TODO: Cain rescued?
	uint8_t bCainInTownSpawned;						//0x51
	uint8_t unk0x52;								//0x52 TODO: Cain not spawned?
	uint8_t bAkaraIntroActivated;					//0x53
	int nCainGibbetObjectMode;						//0x54
	int unk0x58;									//0x58 TODO
	uint8_t bCairnStonesActive[5];					//0x5C
	uint8_t bCainRemovedFromTristram;				//0x61
	uint8_t bCainNotCreated;						//0x62
	uint8_t bQuestCompleteBefore;					//0x63
	uint8_t bAkaraActivatedForScroll;				//0x64
	uint8_t unused0x65;								//0x65
	uint8_t bPortalFromTristramToTownSpawned;		//0x66
	uint8_t bCainPortalCoordsInitialized;			//0x67
	int nCainMonsterInTownGUID;						//0x68
	int nCainObjectGUID;							//0x6C
	uint8_t bCainObjectInitialized;					//0x70
	uint8_t pad0x71[3];								//0x71
	D2UnitStrc* pPlayerInTristram;					//0x74
	uint8_t bScrollAcquired;						//0x78
	uint8_t pad0x79[3];								//0x79
	int nScrollsInGame;								//0x7C
	int nObjectUpdateInvocations;					//0x80
	D2CoordStrc pCainStartPositionCoords;			//0x84
	int nGoldPilesToDropFromWirtsBody;				//0x8C
	uint8_t bWirtsBodyInitialized;					//0x90
	uint8_t bChangePortalOutsideTownToSpecialMode;	//0x91
	uint8_t bChangePortalInTownToSpecialMode;		//0x92
	uint8_t bCainInTristramDeactivated;				//0x93
	uint8_t unused0x94;								//0x94
	uint8_t bCainPortalOutsideTownSpawned;			//0x95
	uint8_t bCainPortalInTownSpawned;				//0x96
	uint8_t unused0x97;								//0x97
	int nCainPortalOutsideTownGUID;					//0x98
	D2CoordStrc pCainPortalOutsideTownCoords;		//0x9C
	int nCainPortalInTownGUID;						//0xA4
	D2CoordStrc pCainPortalInTownCoords;			//0xA8
	uint8_t unused0xB0[4];							//0xB0
	D2QuestGUIDStrc pQuestGUID;						//0xB4
	D2QuestGUIDStrc tPlayerGUIDs;							//0x138
};

#pragma pack()
