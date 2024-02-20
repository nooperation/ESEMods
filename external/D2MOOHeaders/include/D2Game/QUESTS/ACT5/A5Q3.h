#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)


struct D2PrisonOfIceRewardStrc						//sizeof 0x08
{
	const uint32_t* dwItemCodes;					//0x00
	int nItemCount;									//0x04
};

//PrisonOfIce/Anya
struct D2Act5Quest3Strc								//sizeof 0x114
{
	D2QuestGUIDStrc tPlayerGUIDs;							//0x00
	int unk0x84;									//0x84 TODO
	int unk0x88;									//0x88 TODO
	int nTimerInvocations;							//0x8C
	uint8_t bDrehyaIcedMonsterSpawned;				//0x90
	uint8_t bDrehyaMonsterInTownSpawned;			//0x91
	uint8_t bNilathakOutsideTownSpawned;			//0x92
	uint8_t bNihlathakMonsterInTownSpawned;			//0x93
	int nDrehyaMonsterInTownGUID;					//0x94
	int nDrehyaIcedMonsterGUID;						//0x98
	int NihlathakMonsterInTownGUID;					//0x9C
	int nNihlathakOutsideTownGUID;					//0xA0
	uint8_t bFrozenAnyaObjectSpawned;				//0xA4
	uint8_t pad0xA5[3];								//0xA5
	int nFrozenDrehyaObjectGUID;					//0xA8
	uint8_t bMalahIntroActivated;					//0xAC
	uint8_t bChangeToSpecialObjectModeOutsideTown;	//0xAD
	uint8_t bChangeToSpecialObjectModeInTown;		//0xAE
	uint8_t pad0xAF;								//0xAF
	uint8_t unused0xB0;								//0xB0
	uint8_t bDrehyaPortalOutsideTownSpawned;		//0xB1
	uint8_t bDrehyaPortalInTownSpawned;				//0xB2
	uint8_t unused0xB3;								//0xB3
	int nDrehyaPortalInTownGUID;					//0xB4
	uint8_t unused0xB8[8];							//0xB8
	int nDrehyaPortalOutsideTownGUID;				//0xC0
	D2CoordStrc pDrehyaPortalCoords;				//0xC4
	uint8_t unused0xCC[12];							//0xCC
	int nDefrostPotionsInGame;						//0xD8
	int nObjectUpdateInvocations;					//0xDC
	uint8_t bDrehyaPortalCoordsInitialized;			//0xE0
	uint8_t bDrehyaInTownInitialized;				//0xE1
	uint8_t bDefrostPotionAcquired;					//0xE2
	uint8_t bDrehyaIcedRemoved;						//0xE3
	int nDrehyaObjectInTownGUID;					//0xE4
	D2CoordStrc pDrehyaObjectInTownCoords;			//0xE8
	D2CoordStrc pDrehyaObjectOutsideTownCoords;		//0xF0
	int nDrehyaObjectOutsideTownGUID;				//0xF8
	int nFrozenAnyaObjectGUID;						//0xFC
	uint8_t bTimerActive;							//0x100
	uint8_t bMalahActivated;						//0x101
	uint8_t bRewarded;								//0x102
	uint8_t pad0x103;								//0x103
	D2MapAIStrc* pDrehyaMapAI;						//0x104
	D2MapAIStrc* pNilathakMapAI;					//0x108
	uint8_t bDrehyaMapAIChanged;					//0x10C
	uint8_t bNilathakMapAIChanged;					//0x10D
	uint8_t pad0x10E[2];							//0x10E
	int nNihlathakObjectInTownGUID;					//0x110
};

#pragma pack()
