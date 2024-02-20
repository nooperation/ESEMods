#pragma once

#include <D2BitManip.h>

#include <Units/Units.h>
#include <D2Text.h>

#include <GAME/Game.h>
#include <GAME/Clients.h>
#include <OBJECTS/Objects.h>
#include <OBJECTS/ObjMode.h>

#pragma pack(1)

enum D2QuestStateFlagIds
{
	QUESTSTATEFLAG_A1Q0 = 0,
	QUESTSTATEFLAG_A1Q1 = 1,
	QUESTSTATEFLAG_A1Q2 = 2,
	QUESTSTATEFLAG_A1Q3 = 3,
	QUESTSTATEFLAG_A1Q4 = 4,
	QUESTSTATEFLAG_A1Q5 = 5,
	QUESTSTATEFLAG_A1Q6 = 6,

	QUESTSTATEFLAG_A1COMPLETED = 7,

	QUESTSTATEFLAG_A2Q0 = 8,
	QUESTSTATEFLAG_A2Q1 = 9,
	QUESTSTATEFLAG_A2Q2 = 10,
	QUESTSTATEFLAG_A2Q3 = 11,
	QUESTSTATEFLAG_A2Q4 = 12,
	QUESTSTATEFLAG_A2Q5 = 13,
	QUESTSTATEFLAG_A2Q6 = 14,

	QUESTSTATEFLAG_A2COMPLETED = 15,

	QUESTSTATEFLAG_A3Q0 = 16,
	QUESTSTATEFLAG_A3Q1 = 17,
	QUESTSTATEFLAG_A3Q2 = 18,
	QUESTSTATEFLAG_A3Q3 = 19,
	QUESTSTATEFLAG_A3Q4 = 20,
	QUESTSTATEFLAG_A3Q5 = 21,
	QUESTSTATEFLAG_A3Q6 = 22,

	QUESTSTATEFLAG_A3COMPLETED = 23,

	QUESTSTATEFLAG_A4Q0 = 24,
	QUESTSTATEFLAG_A4Q1 = 25,
	QUESTSTATEFLAG_A4Q2 = 26,
	QUESTSTATEFLAG_A4Q3 = 27,

	QUESTSTATEFLAG_A4COMPLETED = 28,

	QUESTSTATEFLAG_A1Q7 = 29,

	QUESTSTATEFLAG_A2Q7 = 30,
	QUESTSTATEFLAG_A2Q8 = 31,

	QUESTSTATEFLAG_A3Q7 = 32,

	QUESTSTATEFLAG_A4Q4 = 33,

	//Unused: 34

	QUESTSTATEFLAG_A5Q1 = 35,
	QUESTSTATEFLAG_A5Q2 = 36,
	QUESTSTATEFLAG_A5Q3 = 37,
	QUESTSTATEFLAG_A5Q4 = 38,
	QUESTSTATEFLAG_A5Q5 = 39,
	QUESTSTATEFLAG_A5Q6 = 40,

	MAX_QUEST_STATUS = 41,
	QUESTSTATEFLAG_A1INTRO = MAX_QUEST_STATUS,
	QUESTSTATEFLAG_A2INTRO = MAX_QUEST_STATUS,
	QUESTSTATEFLAG_A3INTRO = MAX_QUEST_STATUS,
	QUESTSTATEFLAG_A5INTRO = MAX_QUEST_STATUS,
};

enum D2Quests
{
	QUEST_A1Q0_WARRIVGOSSIP = 0,
	QUEST_A1Q1_DENOFEVIL = 1,
	QUEST_A1Q2_BLOODRAVEN = 2,
	QUEST_A1Q3_MALUS = 3,
	QUEST_A1Q4_CAIN = 4,
	QUEST_A1Q5_COUNTESS = 5,
	QUEST_A1Q6_ANDARIEL = 6,

	QUEST_A2Q0_JERHYNGOSSIP = 7,
	QUEST_A2Q1_RADAMENT = 8,
	QUEST_A2Q2_HORADRICSTAFF = 9,
	QUEST_A2Q3_TAINTEDSUN = 10,
	QUEST_A2Q4_HORAZONTOME = 11,
	QUEST_A2Q5_SUMMONER = 12,
	QUEST_A2Q6_DURIEL = 13,

	QUEST_A3Q0_HRATLIGOSSIP = 14,
	QUEST_A3Q1_LAMESENTOME = 15,
	QUEST_A3Q2_KHALIMFLAIL = 16,
	QUEST_A3Q3_GIDBINN = 17,
	QUEST_A3Q4_GOLDENBIRD = 18,
	QUEST_A3Q5_TRAVINCAL = 19,
	QUEST_A3Q6_MEPHISTO = 20,

	QUEST_A4Q0_TYRAELGOSSIP = 21,
	QUEST_A4Q1_IZUAL = 22,
	QUEST_A4Q2_DIABLO = 23,
	QUEST_A4Q3_HELLFORGE = 24,

	QUEST_A1Q1EX_NAVI = 25,

	QUEST_A2Q7_UNUSED_GUARDGOSSIP = 26,
	QUEST_A2Q8_UNUSED_GUARDGOSSIP = 27,

	QUEST_A3Q7_DARKWANDERER = 28,

	QUEST_A4Q4_MALACHAI = 29,

	//TODO: 30 unused?

	QUEST_A5Q1_SHENK = 31,
	QUEST_A5Q2_RESCUESOLDIERS = 32,
	QUEST_A5Q3_PRISONOFICE = 33,
	QUEST_A5Q4_NIHLATHAK = 34,
	QUEST_A5Q5_ANCIENTS = 35,
	QUEST_A5Q6_BAAL = 36
};

// Original work from @Necrolis https://d2mods.info/forum/viewtopic.php?p=412899#p412899

struct D2QuestArgStrc
{
	D2GameStrc* pGame;							//0x00
	int32_t nEvent;								//0x04
	D2UnitStrc* pTarget;						//0x08
	D2UnitStrc* pPlayer;						//0x0C
	uint32_t unk0x10;							//0x10
	union
	{
		struct
		{
			D2TextHeaderStrc* pTextControl;		//0x14
			uint32_t dw18;						//0x18
		};
		struct
		{
			int16_t nNPCNo;						//0x14
			uint16_t unk0x16;					//0x16
			int16_t nMessageIndex;				//0x18
			uint16_t unk0x1A;					//0x1A
		};
		struct
		{
			int32_t nOldLevel;					//0x14
			int32_t nNewLevel;					//0x18
		};
	};
};

struct D2QuestChainStrc
{
	struct D2QuestDataStrc* pQuestData;				//0x00
	D2QuestChainStrc* pNext;					//0x04
};

typedef void(__fastcall* QUESTINIT)(D2QuestDataStrc*);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSTATUS)(D2QuestDataStrc*, D2UnitStrc*, D2BitBufferStrc*, D2BitBufferStrc*, uint8_t*);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);
typedef bool(__fastcall* QUESTACTIVE)(D2QuestDataStrc*, int32_t, D2UnitStrc*, D2BitBufferStrc*, D2UnitStrc*);
typedef int32_t(__fastcall* QUESTSEQ)(D2QuestDataStrc*, D2UnitStrc*, D2BitBufferStrc*, D2BitBufferStrc*, uint8_t*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc*);

struct D2QuestGUIDStrc						//sizeof 0x84
{
	uint32_t nPlayerGUIDs[32];				//0x00 - players that have entered the quest zone
	uint16_t nPlayerCount;					//0x80
	uint8_t pad0x82[2];						//0x82
};

struct D2NPCMessageStrc
{
	int32_t nNPCNo;							//0x00
	int16_t nStringIndex;					//0x04
	int16_t nPad;							//0x06
	BOOL nMenu;								//0x08
};

struct D2NPCMessageTableStrc
{
	D2NPCMessageStrc pMessages[16];			//0x00
	int32_t nMessages;						//0xC0
};

struct D2QuestDataStrc						//sizeof 0xF4
{
	int32_t nQuestNo;						//0x00 - internal
	D2GameStrc* pGame;						//0x04
	uint8_t nActNo;							//0x08
	bool bNotIntro;							//0x09 - set to false for intro quests, it could also be for already completed...
	bool bActive;							//0x0A - confirmed
	uint8_t fLastState;						//0x0B - previous quest state
	uint8_t fState;							//0x0C - main quest state
	char nInitNo;							//0x0D
	uint16_t dw0E;							//0x0E 
	int32_t nSeqId;							//0x10 - nInitNo
	uint32_t dwFlags;						//0x14
	void* pQuestDataEx;						//0x18 - union of 0x29 structs
	D2QuestGUIDStrc tPlayerGUIDs;			//0x1C
	QUESTCALLBACK pfCallback[15];			//0xA0
	D2NPCMessageTableStrc* pNPCMessages;	//0xDC
	int32_t nQuestFilter;					//0xE0 - index in quest flag bit array, called eFilter in original code
	QUESTSTATUS pfStatusFilter;				//0xE4
	QUESTACTIVE pfActiveFilter;				//0xE8
	QUESTSEQFILTER pfSeqFilter;				//0xEC
	D2QuestDataStrc* pPrev;					//0xF0
};

struct D2QuestInitTableStrc
{
	QUESTINIT pfInit;						//0x00
	uint8_t nAct;							//0x04
	uint8_t pad0x05[3];						//0x05
	uint32_t nVersion;						//0x08
	bool bNoSetState;						//0x0C - used by the sequences for quest init flags
	uint8_t pad0x0D[3];						//0x0D
	int32_t nChainNo;						//0x10 - quest data internal chain id
	uint32_t nQuestNo;						//0x14 - pQuestData flag no
};

struct D2QuestIntroTableStrc
{
	QUESTINIT pfInit;						//0x00
	uint8_t nAct;							//0x04
	uint8_t pad0x05[3];						//0x05
};

struct D2QuestTimerStrc
{
	QUESTUPDATE pfUpdate;					//0x00
	D2QuestDataStrc* pQuest;				//0x04
	uint32_t dwTicks;						//0x08
	uint32_t dwTimeout;						//0x0C
	D2QuestTimerStrc* pNext;				//0x10
};

struct D2QuestInfoStrc
{
	D2QuestDataStrc* pLastQuest;			//0x00
	BOOL bExecuting;						//0x04
	BOOL bPickedSet;						//0x08
	D2BitBufferStrc* pQuestFlags;			//0x0C
	D2QuestTimerStrc* pTimer;				//0x10
	uint32_t dwTick;						//0x14
	D2SeedStrc pSeed;						//0x18
	uint8_t unk0x20;						//0x20
	uint8_t unk0x21[3];						//0x21
};

#pragma pack()
