#pragma once

#include "D2PacketDef.h"
#include <Units/Units.h>
#include "Game.h"
#include "D2Packet.h"

struct D2SaveHeaderStrc;

#pragma pack(1)
enum D2SystemError
{
	SYSERROR_SUCCESS = 0,
	SYSERROR_BAD_INPUT = 1,
	SYSERROR_UNK_1 = 1,
	SYSERROR_UNK_2 = 2,
	SYSERROR_BAD_WAYPOINT = 3,
	SYSERROR_BAD_STATS = 4,
	SYSERROR_BAD_SKILLS = 5,
	SYSERROR_UNK_6 = 6,
	SYSERROR_UNK_7 = 7,
	SYSERROR_CORPSES = 8,
	SYSERROR_UNK_9 = 9,
	SYSERROR_UNK_10 = 10,
	SYSERROR_UNK_11 = 11,
	SYSERROR_UNK_12 = 12,
	SYSERROR_INVENTORY = 13,
	SYSERROR_UNK_14 = 14,
	SYSERROR_NIGHTMARE_NOT_UNLOCKED = 17,
	SYSERROR_HELL_NOT_UNLOCKED = 18,
	SYSERROR_SOFTCOREJOINHARDCORE = 19,
	SYSERROR_HARDCOREJOINSOFTCORE = 20,
	SYSERROR_DEADHARDCORE = 21,
	SYSERROR_EXPANSIONGAME = 23,
	SYSERROR_NOTEXPANSIONGAME = 24,
	SYSERROR_LADDERGAME = 25,
	SYSERROR_NOTLADDERGAME = 26,
};

enum D2ClientState : uint32_t
{
	CLIENTSTATE_JUST_CREATED = 0,
	CLIENTSTATE_GAME_INIT_SENT = 1,
	CLIENTSTATE_ACT_INIT_SENT = 2,
	CLIENTSTATE_PLAYER_SPAWNED = 3,
	CLIENTSTATE_INGAME = 4,
	CLIENTSTATE_CHANGING_ACT = 5,
};

// Character information flags
enum D2ClientSaveFlags
{
	CLIENTSAVEFLAG_INIT = 0x1, // Newbie save
	CLIENTSAVEFLAG_0x2 = 0x2,
	CLIENTSAVEFLAG_HARDCORE = 0x4,
	CLIENTSAVEFLAG_DEAD = 0x8,
	CLIENTSAVEFLAG_0x10 = 0x10,
	CLIENTSAVEFLAG_EXPANSION = 0x20,
	CLIENTSAVEFLAG_LADDER = 0x40,
	CLIENTSAVEFLAG_0x80 = 0x80,
	CLIENTSAVEFLAG_WEAPON_SWITCH = 0x2000,

	// Encodes completed acts 
	// => 0 No act completed
	// => Acts 1-5 Normal (values 1-5), then 1-5 NM (values 6-10), then 1-5 Hell (values 11-15) for Expansion
	// => Acts 1-4 Normal (values 1-4), then 1-4 NM (values 5-8), then 1-4 Hell  (values 9-12) for Classic
	CLIENTSAVEFLAG_CHARACTER_PROGRESSION_BIT = 8,
	CLIENTSAVEFLAG_CHARACTER_PROGRESSION_MASK = (0x1F) << CLIENTSAVEFLAG_CHARACTER_PROGRESSION_BIT,

};

// Internal management flags
enum D2ClientFlagsEx
{
	CLIENTFLAGEX_PLAYER_UNIT_ALIVE	= 0x01,
	CLIENTFLAGEX_ARENA_RELATED		= 0x04,
	CLIENTFLAGEX_HAS_SAVE_CHECKSUM	= 0x08,
	CLIENTFLAGEX_SAVE_LOADED		= 0x10,
};

enum D2ClientsConstants
{
	CLIENTS_MAX_UPDATES = 55,
};

struct D2CharacterPreviewInfoStrc // This is used as string, values are encoded so that they are != 0
{
	uint16_t unk0x00;					//0x00 lower byte is cleared if invalid data was found => empty string
	uint8_t pComponents[11];			//0x02
	uint8_t nClass;						//0x0D
	uint8_t pComponentColors[11];		//0x0C
	uint8_t nLevel;						//0x19
	uint16_t nClientFlags;				//0x1A
	uint16_t nGuildFlags;				//0x1C
	uint8_t nGuildEmblemBgColor;		//0x1E
	uint8_t nGuildEmblemFgColor;		//0x1F
	uint8_t nGuildEmblemType;			//0x20 maps to D2DATA.MPQ/data/global/ui/Emblems/icon(nGuildEmblemType-1)a.dc6
	uint32_t szGuildTag;				//0x21
	uint8_t pad0x25;					//0x25
};

struct D2ClientInfoStrc
{
	D2ClientInfoStrc* pSelf;				//0x00
	int32_t dwClientId;							//0x04
	uint32_t nFlags;					//0x08
	const char* szKickMessage;				//0x0C
	int32_t unk0x10;							//0x10
	uint32_t dwLastPacketResetTick;		//0x14
	uint32_t nPacketsPerSecond;			//0x18
	uint32_t dwNewGameTick;				//0x1C
	uint32_t dwRemoveTick;				//0x20
	int32_t unk0x24;							//0x24
	int32_t unk0x28;							//0x28
	uint32_t dwHackDetectionPacketTick;	//0x2C
	uint32_t nACDataCount;				//0x30
	int32_t unk0x34;							//0x34
	int32_t unk0x38;							//0x38
	uint32_t unk0x3C;					//0x3C
};

struct D2ClientPlayerDataStrc
{
	uint32_t dwInactivityTime;					//0x00
	uint16_t nHitPoints;						//0x04
	uint16_t nManaPoints;						//0x06
	uint16_t nStaminaPoints;					//0x08
	uint8_t nPotionLifePercent;					//0x0A
	uint8_t nPotionManaPercent;					//0x0B
	uint16_t nPosX;								//0x0C
	uint16_t nPosY;								//0x0E
	uint16_t nTargetOffsetX;					//0x10
	uint16_t nTargetOffsetY;					//0x12
	uint32_t dwBeltGold;						//0x14
	uint32_t dwExperience;						//0x18
};

struct D2ClientUnitUpdateSortStrc
{
	D2UnitStrc* pUnit;							//0x00
	int32_t nDistance;							//0x04
	int32_t nNextIndex;							//0x08
};

struct D2ClientKeySkillStrc
{
	int16_t nSkill;								//0x00
	int16_t nHand;								//0x02
	uint32_t nItemGUID;							//0x04
};

struct D2GuildInformationStrc
{
	int16_t nGuildFlags;						//0x00
	uint32_t szGuildTag;						//0x02
	char szGuildName[28];						//0x06
	uint8_t nBackgroundColor;					//0x22
	uint8_t nForegroundColor;					//0x23
	uint8_t nEmblemType;						//0x24
};

struct D2ClientStrc
{
	uint32_t dwClientId;						//0x000
	D2ClientState dwClientState;				//0x004
	uint8_t nClassId;							//0x008
	uint8_t unk0x09;							//0x009
	uint16_t nSaveFlags;						//0x00A D2ClientSaveFlags
	uint8_t nCharTemplate;						//0x00C
	char szName[16];							//0x00D
	char szAccount[16];							//0x01D
	uint8_t unk0x2D[51];						//0x02D
	int32_t nCharSaveTransactionToken;			//0x060
	int32_t unk0x64;							//0x064
	D2ClientInfoStrc* pClientInfo;				//0x068
	D2CharacterPreviewInfoStrc tCharacterInfo;	//0x06C
	uint8_t unk0x92[218];						//0x092
	uint32_t dwUnitType;						//0x16C
	D2UnitGUID dwUnitGUID;						//0x170
	D2UnitStrc* pPlayer;						//0x174
	uint32_t bUnlockCharacter;					//0x178
	D2SaveHeaderStrc* pSaveHeader;				//0x17C
	int32_t nSaveHeaderSize;					//0x180
	uint32_t unk0x184;							//0x184
	uint32_t nSaveHeaderDataSentBytes;			//0x188
	DWORD nSaveChecksum;						//0x18C
	uint64_t nLadderGUID;						//0x190
	DWORD unk0x198[4];							//0x198
	D2GameStrc* pGame;							//0x1A8
	uint8_t nAct;								//0x1AC
	uint8_t pad0x1AD[3];						//0x1AD
	uint32_t unk0x1B0;							//0x1B0
	D2ActiveRoomStrc* pRoom;					//0x1B4
	struct PacketList {
		D2PacketDataStrc* pHead;				//0x1B8
		D2PacketDataStrc* pTail;				//0x1BC
		D2PacketDataStrc* pPacketDataPool;		//0x1C0
	} tPacketDataList;
	uint32_t nSaveHeaderSendFailures;			//0x1C4
	uint32_t unk0x1C8;							//0x1C8
	D2ClientUnitUpdateStrc unitUpdate[CLIENTS_MAX_UPDATES]; //0x1CC
	uint8_t pad0x3BB;							//0x3BB
	uint32_t nUnitUpdateIndex;					//0x3BC
	int32_t aLastWarpAttemptsFrame[5];			//0x3C0
	uint32_t dwFlags;							//0x3D4 D2ClientFlagsEx
	uint32_t dwLastPacketTick;					//0x3D8
	D2ClientKeySkillStrc HotkeySkills[16];		//0x3DC
	uint8_t bSwitchWeapon;						//0x45C
	uint8_t padding0x45D;						//0x45D
	D2GuildInformationStrc tGuildInfo;			//0x45E
	uint8_t padding0x483;						//0x483
	int32_t nIronGolemItemGUID;					//0x484
	uint32_t nCreateTime;						//0x488
	D2ClientPlayerDataStrc clientPlayerData;	//0x48C
	D2ClientStrc* pNext;						//0x4A8
	D2ClientStrc* pListNext;					//0x4AC
	D2ClientStrc* pNextByName;					//0x4B0
	uint32_t aPingHistory[17];					//0x4B4
	uint64_t nPingMovingAverage;				//0x4F8
	uint32_t dwPingsCount;						//0x500
#ifdef D2_VERSION_113C
	uint32_t unk0x504;							//0x504
#endif
	int32_t nExpLoss;							//0x504
	uint32_t dwLocale;							//0x508
	uint32_t dwLangId;							//0x50C
#ifdef D2_VERSION_113C
	uint32_t pad0x514;							//0x514
#endif
};

#pragma pack()
