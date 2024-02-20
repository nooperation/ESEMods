#pragma once

#include <Units/Units.h>
#include "D2PacketDef.h"

#pragma warning(push)
#pragma warning(disable: 4820)
#include <storm/hash/TSHashObject.hpp>
#include <storm/hash/Hashkey.hpp>
#include <storm/hash/TSExportTableSyncReuse.hpp>
#include <storm/thread/CCritSect.hpp>
#pragma warning(pop)

struct D2ClientInfoStrc;
struct D2UnitInfoStrc;
struct D2UnitDescriptionListStrc;
struct D2PartyControlStrc;
struct D2ArenaStrc;
struct D2InactiveUnitListStrc;
struct D2MonsterRegionStrc;
struct D2NpcControlStrc;
struct D2QuestInfoStrc;
struct D2EventTimerQueueStrc;

enum D2PacketTypeAdmin
{
	PACKET_ADMIN_GETINFO = 0x01,
	PACKET_ADMIN_CONNECT = 0xFA,
	PACKET_ADMIN_DISCONNECT = 0xFB,
	PACKET_ADMIN_GETIP = 0xFC,
	PACKET_ADMIN_GETGAMEINFO = 0xFD
};

enum D2GameFlags
{
	GAMEFLAG_ARENA_MODE					= 0x00000002,
	GAMEFLAG_ARENA_UPDATECLIENTS		= 0x00000004,
	GAMEFLAG_ARENA_TEMPLATE				= 0x00000020,
	GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID = 0x00000100,
	GAMEFLAG_ARENA_UPDATE				= 0x00000400,
	GAMEFLAG_ARENA_HARDCORE				= 0x00000800,
	GAMEFLAG_ARENA_ACTIVE				= 0x00010000,
	GAMEFLAG_ARENA_EXPANSION			= 0x00100000,
	GAMEFLAG_ARENA_LADDER				= 0x00200000,

	GAMEFLAG_DIFFICULTY_BIT				= 12,
	GAMEFLAG_DIFFICULTY_MASK			= (0x7) << GAMEFLAG_DIFFICULTY_BIT,
};

using D2GameGUID = uint32_t;
constexpr D2GameGUID D2GameInvalidGUID = (D2GameGUID)-1;
DECLARE_STRICT_HANDLE(HGAMEDATA);
DECLARE_STRICT_HANDLE(GAMEDATALOCKEDHANDLE);

// TODO: get rid of this and use handles properly where needed
inline D2GameGUID GetHashValueFromGameHandle(HGAMEDATA hGame) { return (uint32_t)(uintptr_t)hGame; }
inline HGAMEDATA GetGameHandleFromHashValue(D2GameGUID nGameGUID) { return (HGAMEDATA)(uintptr_t)nGameGUID; }
static const HGAMEDATA D2GameReservedSlotHandle = GetGameHandleFromHashValue(D2GameInvalidGUID);


using FnCloseGame = void(__fastcall*)(WORD nGameId, uint32_t nProductCode, uint32_t nSpawnedPlayers, int32_t nFrame);
using FnLeaveGame = void(__fastcall*)(D2ClientInfoStrc** ppClientInfo, WORD nGameId, int32_t nClassId, int32_t nLevel, uint32_t nExperience, int32_t a6, uint32_t nFlags, const char* szCharName, const char* a9, int32_t bUnlockChar, int32_t nZero11, int32_t nZero12, const char* szAccountName, int32_t a14, uint64_t* pLadderGUID); //TODO: Unknown args
using FnGetDatabaseCharacter = void(__fastcall*)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, DWORD dwClientId, const char* szAccountName);
using FnSaveDatabaseCharacter = void(__fastcall*)(int32_t* pRealmId, const char* szCharName, const char* szAccountName, BYTE* pSaveData, uint32_t nSaveDataSize, int32_t nUnused);
using FnServerLogMessage = void(*)(int32_t nLogLevel, const char* szFormat, ...);
using FnEnterGame = void(__fastcall*)(WORD nGameId, const char* szCharName, int32_t nClassId, int32_t nLevel, uint32_t nFlags);
using FnFindPlayerToken = int32_t(__fastcall*)(const char* szCharName, int32_t nTokenId, WORD nGameId, char* pszOutAccountName, int32_t* pOutValueResolvedUsingToken, int32_t* a6, int32_t* a7); //TODO: Last 3 args
/*UNUSED*/	using FnSaveDatabaseGuild = int(__fastcall*)(const char*, char*, size_t);
using FnUnlockDatabaseCharacter = void(__fastcall*)(uint32_t* pGameData, const char* szCharName, const char* szAccountName);
/*UNUSED*/	using FnUnk0x24 = int(__fastcall*)(int, int);
using FnUpdateCharacterLadder = void(__fastcall*)(const char* szCharName, int32_t nClassId, int32_t nLevel, uint32_t nExperience, int32_t nZero, uint32_t nFlags, uint64_t* pLadderGUID);
using FnUpdateGameInformation = void(__fastcall*)(WORD nGameId, const char* szCharName, int32_t nClassId, int32_t nLevel);
using FnHandlePacket = void(__fastcall*)(void* pPacket, int32_t nPacketSize);
using FnSetGameData = uint32_t(__fastcall*)();
using FnRelockDatabaseCharacter = void(__fastcall*)(int32_t* pRealmId, const char* szCharName, const char* szAccountName);
/*UNUSED*/	using FnLoadComplete = int32_t(__stdcall*)(int32_t);

extern char gszEmptyString_6FD447EC[8];

#pragma pack(push, 1)
struct D2ServerCallbackFunctions							// sizeof 0x40
{
	FnCloseGame pfCloseGame;								//0x00
	FnLeaveGame pfLeaveGame;								//0x04
	FnGetDatabaseCharacter pfGetDatabaseCharacter;			//0x08
	FnSaveDatabaseCharacter pfSaveDatabaseCharacter;		//0x0C
	FnServerLogMessage pfServerLogMessage;					//0x10
	FnEnterGame pfEnterGame;								//0x14
	FnFindPlayerToken pfFindPlayerToken;					//0x18
	FnSaveDatabaseGuild pfSaveDatabaseGuild;				//0x1C
	FnUnlockDatabaseCharacter pfUnlockDatabaseCharacter;	//0x20
	FnUnk0x24 unk0x24;										//0x24
	FnUpdateCharacterLadder pfUpdateCharacterLadder;		//0x28
	FnUpdateGameInformation pfUpdateGameInformation;		//0x2C
	FnHandlePacket pfHandlePacket;							//0x30
	FnSetGameData pfSetGameData;							//0x34
	FnRelockDatabaseCharacter pfRelockDatabaseCharacter;	//0x38
	FnLoadComplete pfLoadComplete;							//0x3C
};


struct D2GameInfoStrc
{
	int32_t nGameId;								// 0x00
	uint32_t nInitSeed;								// 0x04
	int32_t nClients;								// 0x08
	int32_t nPlayers;								// 0x0C
	int32_t nMonsters;								// 0x10
	int32_t nObjects;								// 0x14
	int32_t nItems;									// 0x18
	int32_t nMissiles;								// 0x1C
	int32_t nUniqueItems;							// 0x20
	int32_t nNPCs;									// 0x24
	uint32_t dwLastUsedUnitGUID[UNIT_TYPES_COUNT];	// 0x3C Tile = Warp
	int32_t nPathTowardPct;							// 0x40
	int32_t nPathClockPct;							// 0x44
	int32_t nPathCounterPct;						// 0x48
	int32_t nPathFoWallPct;							// 0x4C
	int32_t nPathAStarPct;							// 0x50
	int32_t nPathTotalCalls;						// 0x54
	int32_t nFrames;								// 0x58 Frames / 100
	int32_t nTime;									// 0x5C Time (minutes) since game creation (bugged, actually returns machine uptime)
	int32_t nFrameRate;								// 0x60
	char szGameName[16];							// 0x64
	char szGamePassword[16];						// 0x74
	char szGameDescription[32];						// 0x84 Before 1.10f (unsure what version), struct used to have desc of 24 chars, and end here.
	uint8_t nArenaTemplate;							// 0xA4
	uint8_t unk0xA5;								// 0xA5
	uint8_t unk0xA6;								// 0xA6
	uint8_t padding0xA7;							// 0xA7
	uint32_t nArenaFlags;							// 0xA8
	void* pMemoryPool;								// 0xAC
};

struct D2TargetNodeStrc
{
	D2UnitStrc* pUnit;							//0x00
	int32_t unk0x04;							//0x04
	D2TargetNodeStrc* pNext;					//0x08
	D2TargetNodeStrc* unk0x0C;					//0x0C
};

struct D2GameStrc : TSHashObject<D2GameStrc, HASHKEY_NONE> // called SGAMEDATA in original game
{
	LPCRITICAL_SECTION lpCriticalSection;			//0x18
	void* pMemoryPool;								//0x1C
	uint32_t nGameData;								//0x20
	uint32_t unk0x24;								//0x24
	uint16_t nGameId;								//0x28
	char szGameName[16];							//0x2A
	char szGamePassword[16];						//0x3A
	char szGameDesc[32];							//0x4A
	uint8_t nGameType;								//0x6A
	uint8_t nArenaTemplate;							//0x6B
	uint8_t unk0x6C;								//0x6C
	uint8_t nDifficulty;							//0x6D
	uint8_t unk0x6E;								//0x6E
	uint8_t unk0x6F;								//0x6F
	BOOL bExpansion;								//0x70
	uint32_t dwGameType;							//0x74 1=Ladder
	uint16_t wItemFormat;							//0x78
	uint16_t unk0x7A;								//0x7A
	uint32_t dwInitSeed;							//0x7C
	uint32_t dwObjSeed;								//0x80
	uint32_t InitSeed;								//0x84
	D2ClientStrc* pClientList;						//0x88
	uint32_t nClients;								//0x8C
	uint32_t dwLastUsedUnitGUID[UNIT_TYPES_COUNT];	//0x90
	int32_t dwGameFrame;							//0xA8
	uint32_t nFrameRate;							//0xAC
	uint32_t nFramesSinceLastFrameRateUpdate;		//0xB0
	uint32_t nPreviousUpdateTickCount;				//0xB4
	D2EventTimerQueueStrc* pTimerQueue;				//0xB8
	D2DrlgActStrc* pAct[5];							//0xBC
	D2SeedStrc pGameSeed;							//0xD0
	D2InactiveUnitListStrc* pInactiveUnitList[5];	//0xD8
	uint32_t dwMonSeed;								//0xEC
	D2MonsterRegionStrc* pMonReg[1024];				//0xF0
	D2ObjectControlStrc* pObjectControl;			//0x10F0
	D2QuestInfoStrc* pQuestControl;					//0x10F4
	D2TargetNodeStrc* pTargetNodes[10];				//0x10F8
	D2UnitStrc* pUnitList[5][128];					//0x1120 Note: This is not indexed by UnitType! See GAME_RemapUnitTypeToListIndex
	D2UnitStrc* pTileList;							//0x1B20
	uint32_t dwUniqueFlags[128];					//0x1B24
	D2NpcControlStrc* pNpcControl;					//0x1D24
	D2ArenaStrc* pArenaCtrl;						//0x1D28
	D2PartyControlStrc* pPartyControl;				//0x1D2C
	uint8_t nBossFlagList[64];						//0x1D30
	uint32_t dwPathTypesCount[17];					//0x1D70 Note: 17 entries only, means PATHTYPE_UNKNOWN_17 is unused ? Stats only
	uint32_t nTotalPathTypesCount;					//0x1DB4
	uint32_t nLastUpdateSystemTimeMs;				//0x1DB8
	uint32_t nCreationTimeMs_Or_CPUTargetRatioFP10;	//0x1DBC Used to be the creation time, but now represents ratio of the budget used for last frame, in FP10 represenation (x/1024)
	uint32_t nTickCountSinceNoClients;				//0x1DC0
	uint32_t nSyncTimer;							//0x1DC4

	uint32_t unk0x1DC8;								//0x1DC8
	uint32_t unk0x1DCC;								//0x1DCC
	uint32_t unk0x1DD0;								//0x1DD0
	uint32_t unk0x1DD4;								//0x1DD4
	uint32_t unk0x1DD8;								//0x1DD8
	uint32_t unk0x1DDC;								//0x1DDC
};

struct D2GameDataTableStrc
{
	TSExportTableSyncReuse<D2GameStrc, HGAMEDATA, GAMEDATALOCKEDHANDLE, CCritSect> tHashTable;
}; // Size = 0x68

struct D2GameStatisticsStrc
{
	DWORD nGamesCount;
	DWORD nActiveMonsters;
	DWORD nInactiveMonsters;
	DWORD nPlayersCount;
};

#pragma pack(pop)
