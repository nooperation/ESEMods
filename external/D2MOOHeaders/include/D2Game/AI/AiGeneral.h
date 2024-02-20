#pragma once

#include <Units/Units.h>
#include <UNIT/SUnitInactive.h>

#include "GAME/Game.h"

#pragma pack(1)

struct D2AiCmdStrc
{
	D2AiCmdStrc* pNextCmd;					//0x00
	D2AiCmdStrc* pPrevCmd;					//0x04
	int32_t nCmdParam[5];					//0x08
};

struct D2AiTickParamStrc
{
	D2AiControlStrc* pAiControl;			//0x00
	uint32_t unk0x04;						//0x04
	D2UnitStrc* pTarget;					//0x08
	uint32_t unk0x0C[2];					//0x0C
	int32_t nTargetDistance;				//0x14
	BOOL bCombat;							//0x18
	D2MonStatsTxt* pMonstatsTxt;			//0x1C
	D2MonStats2Txt* pMonstats2Txt;			//0x20
};

typedef void(__fastcall* AIPARAMFN)(D2GameStrc*, D2UnitStrc*, D2AiTickParamStrc*);

struct D2AiControlStrc
{
	uint32_t dwSpecialState;				//0x00
	AIPARAMFN pAiParamFn;					//0x04
	uint16_t nAiFlags;						//0x08
	uint8_t unk0x0A[2];						//0x0A
	D2UnitGUID dwOwnerGUID;					//0x0C
	uint32_t dwOwnerType;					//0x10
	int32_t dwAiParam[3];					//0x14
	D2AiCmdStrc* pCurrentCmd;				//0x20
	D2AiCmdStrc* pLastCmd;					//0x24
	D2GameStrc* pGame;						//0x28
	D2UnitGUID dwOwnerGUIDEx;				//0x2C
	uint32_t dwOwnerTypeEx;					//0x30
	D2MinionListStrc* pMinionList;			//0x34
	D2MapAIStrc* pMapAi;					//0x38
	//int32_t nTrapType;					//0x38
	int32_t nMinionSpawnClassId;			//0x3C
};

struct D2AiParamStrc
{
	//uint32_t unk0x00;						//0x00
	//void* pAiParamFn;						//0x04
	//uint16_t nAiFlags;					//0x08
	//uint8_t unk0x0A[16];					//0x0A
	//uint32_t dwMoveMethod;				//0x18
	//int32_t nSpeedBonus;					//0x1C
	//int32_t nSteps;						//0x20

	uint8_t unk0x00;
	uint8_t unk0x01;
	uint8_t unk0x02;
	uint8_t unk0x03;
	D2UnitStrc* pTarget;
	int32_t unk0x08;
	int32_t unk0x0C;
	int32_t unk0x10;
	int32_t unk0x14;
	int32_t unk0x18;
	int32_t nVelocity;
	uint8_t unk0x20;
	uint8_t unk0x21;
	uint8_t unk0x22;
	uint8_t unk0x23;
};

struct D2AiTableStrc
{
	int32_t unk0x00;						//0x00
	AIPARAMFN unk0x04;						//0x04
	AIPARAMFN pAiParamFn;					//0x08
	AIPARAMFN unk0x0C;						//0x0C
};


#pragma pack()
