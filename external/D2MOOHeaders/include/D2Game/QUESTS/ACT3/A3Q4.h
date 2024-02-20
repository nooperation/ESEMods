#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//GoldenBird
struct D2Act3Quest4Strc						//sizeof 0x1C
{
	uint8_t bGoldenBirdBroughtToAlkor;		//0x00
	uint8_t unk0x01;						//0x01 TODO
	uint8_t unk0x02;						//0x02 TODO
	uint8_t pad0x03;						//0x03
	int nBossGUID;							//0x04
	uint8_t bTalkedToAlkor;					//0x08
	uint8_t bTalkedToCainOnce;				//0x09
	uint8_t bTalkedToCainTwice;				//0x0A
	uint8_t bTalkedToMeshif;				//0x0B
	uint8_t unk0x0C;						//0x0C TODO
	uint8_t pad0x0D[3];						//0x0D
	int nGoldenBirdsInGame;					//0x10
	uint8_t bJadeFigurineDropped;			//0x14
	uint8_t bPlayerDroppedWithItem;			//0x15
	uint8_t pad0x16[2];						//0x16
	int nCurrentQuestFlag;					//0x18
};

#pragma pack()
