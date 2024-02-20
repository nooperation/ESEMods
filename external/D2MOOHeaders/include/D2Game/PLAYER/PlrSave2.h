#pragma once

#include <Units/Units.h>

#pragma pack(1)

enum D2PlayerSave2Error
{
	PLRSAVE2ERROR_SUCCESS = 0,
	PLRSAVE2ERROR_UNKNOWN = 1,
	PLRSAVE2ERROR_NEWBIE_SAVE = 2,
	PLRSAVE2ERROR_BAD_CLIENT = 3,
	PLRSAVE2ERROR_CLIENT_ERROR = 4,
	PLRSAVE2ERROR_INVALID_SIZE = 5,
	PLRSAVE2ERROR_INVALID_CHECKSUM = 6,
	PLRSAVE2ERROR_NOT_COMPATIBLE = 7,
	PLRSAVE2ERROR_NOTEXPANSIONGAME = 8,
	PLRSAVE2ERROR_EXPANSIONGAME = 9,
	PLRSAVE2ERROR_DEADHARDCORE = 10,
	PLRSAVE2ERROR_HARDCOREJOINSOFTCORE = 11,
	PLRSAVE2ERROR_SOFTCOREJOINHARDCORE = 12,
	PLRSAVE2ERROR_NIGHTMARE_NOT_UNLOCKED = 13,
	PLRSAVE2ERROR_HELL_NOT_UNLOCKED = 14,
	PLRSAVE2ERROR_BAD_QUESTRECORD = 15,
	PLRSAVE2ERROR_BAD_WAYPOINT = 16,
	PLRSAVE2ERROR_BAD_PLAYERINTRO = 17,
	PLRSAVE2ERROR_BAD_STATS = 18,
	PLRSAVE2ERROR_BAD_SKILLS = 19,
	PLRSAVE2ERROR_BAD_ITEMS = 20,
	PLRSAVE2ERROR_BAD_CORPSES = 21,
	PLRSAVE2ERROR_BAD_PET = 22,
	PLRSAVE2ERROR_BAD_IRONGOLEM = 23,
	PLRSAVE2ERROR_UNK_24 = 24,
	PLRSAVE2ERROR_NOTLADDERGAME = 25,
	PLRSAVE2ERROR_LADDERGAME = 26,
	PLRSAVE2ERROR_COUNT

};

struct D2MercSaveDataStrc
{
	uint32_t nFlags;							//0x00		//0xAF of D2SaveHeaderStrc
	uint32_t nSeed;								//0x04		//0xB3
	uint16_t wName;								//0x08		//0xB7
	uint16_t nHirelingId;						//0x0A		//0xB9
	uint32_t nExperience;						//0x0C		//0xBB
	uint32_t unk0x10[4];						//0x10
};

struct D2SaveSkillKeyStrc
{
	uint16_t nSkill;							//0x00
	union
	{
		struct
		{
			uint8_t nKey;						//0x02
			uint8_t nKeyEx;						//0x03
		};

		uint16_t nItemSlot;						//0x02
	};
};

struct D2SaveHeaderStrc
{
	uint32_t dwHeaderMagic;					//0x00
	uint32_t dwVersion;						//0x04
	uint32_t dwSize;						//0x08
	uint32_t dwChecksum;					//0x0C
	uint32_t dwWeaponSwitch;				//0x10
	char szName[16];						//0x14
	uint32_t dwSaveFlags;					//0x24
	uint8_t nClass;							//0x28
	uint8_t nStats;							//0x29
	uint8_t nSkills;						//0x2A
	uint8_t nLevel;							//0x2B
	uint32_t dwCreateTime;					//0x2C
	uint32_t dwLasTime;						//0x30
	uint32_t dwPlayTime;					//0x34
	D2SaveSkillKeyStrc SkillKeys[16];		//0x38
	int16_t nLeftSkillId;					//0x78
	int16_t nLeftSkillItemIndex;			//0x7A
	int16_t nRightSkillId;					//0x7C
	int16_t nRightSkillItemIndex;			//0x7E
	int16_t nSwitchLeftSkillId;				//0x80
	int16_t nSwitchLeftSkillItemIndex;		//0x82
	int16_t nSwitchRightSkillId;			//0x84
	int16_t nSwitchRightSkillItemIndex;		//0x86
	uint8_t nComponent[16];					//0x88
	uint8_t nCompColor[16];					//0x98
	uint8_t nTown[3];						//0xA8
	uint32_t dwMapSeed;						//0xAB
	D2MercSaveDataStrc MercSaveData;		//0xAF
	uint8_t nGuildEmblemBgColor;			//0xCF
	uint32_t dwLastLevel;					//0xD0
	uint32_t dwLastTown;					//0xD4
	uint8_t nLastDifficulty;				//0xD8

	char unk0xD9[118];
};

#pragma pack()
