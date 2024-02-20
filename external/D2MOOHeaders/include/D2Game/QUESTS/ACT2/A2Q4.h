#pragma once

#include <QUESTS/Quests.h>

#pragma pack(1)

//HorazonTome
struct D2Act2Quest4Strc							//sizeof 0x48
{
	uint8_t unused0x00[4];						//0x00
	uint8_t bDrognanActivated;					//0x04
	uint8_t pad0x05[3];							//0x05
	D2ActiveRoomStrc* pRoom;							//0x08
	uint8_t bJerhynStartInitialized;			//0x0C
	uint8_t bJerhynPalaceInitialized;			//0x0D
	uint8_t bPalaceOpen;						//0x0E
	uint8_t unk0x0F;							//0x0F TODO
	uint8_t unk0x10;							//0x10 TODO
	uint8_t bHaremBlockerInitialized;			//0x11
	uint8_t unk0x12;							//0x12 TODO
	uint8_t unk0x13;							//0x13 TODO
	uint8_t unk0x14;							//0x14 TODO
	uint8_t bJerhynCoordinatesStored;			//0x15
	uint8_t bPortalToCanyonOpen;				//0x16
	uint8_t unused0x17;							//0x17
	uint8_t unk0x18;							//0x18 TODO
	uint8_t unk0x19;							//0x19 TODO
	uint8_t bPlayerCloseToHaremBlocker;			//0x1A
	uint8_t pad0x1B;							//0x1B
	int nPlayerCloseToHaremBlockerGUID;			//0x1C
	D2CoordStrc pHaremBlockerCoords;			//0x20
	D2CoordStrc pJerhynCoords;					//0x28
	D2CoordStrc pGuardCoords;					//0x30
	int nHaremBlockerGUID;						//0x38
	int nJerhynGUID;							//0x3C
	uint16_t nHaremBlockerObjectMode;			//0x40
	uint16_t nPortalModeInSanctuary;			//0x42
	uint16_t nPortalModeInCellar;				//0x44
	uint8_t bIsHaremBlockerNeutral;				//0x46
	uint8_t pad0x47;							//0x47
};

#pragma pack()
