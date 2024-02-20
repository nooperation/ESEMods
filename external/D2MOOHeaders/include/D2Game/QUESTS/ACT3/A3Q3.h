#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//Gidbinn
struct D2Act3Quest3Strc						//sizeof 0x30
{
	uint8_t bGidbinnDropped;				//0x00
	uint8_t bHratliActivated;				//0x01
	uint8_t bBossHasSpawned;				//0x02
	uint8_t bGidbinnObjectActivated;		//0x03
	uint8_t bBossIsSpawning;				//0x04
	uint8_t bSpawnTimerStarted;				//0x05
	uint8_t bAltarCanBeActivated;			//0x06
	uint8_t bGidbinnBroughtToOrmus;			//0x07
	int nGidbinnX;							//0x08
	int nGidbinnY;							//0x0C
	int nAltarX;							//0x10
	int nAltarY;							//0x14
	uint8_t bGidbinnObjectInitialized;		//0x18
	uint8_t pad0x19[3];						//0x19
	int nGidbinnsInGame;					//0x1C
	uint8_t bPlayerWithGidbinnDropped;		//0x20
	uint8_t pad0x21[3];						//0x21
	int nFetishBossGUID;					//0x24
	int nAltarGUID;							//0x28
	int nAltarObjectMode;					//0x2C
};

#pragma pack()
