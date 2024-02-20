#pragma once

#include "D2WinControlHeader.h"

#include <D2Unicode.h>
#include "Font.h"


enum ButtonFlags
{
	BUTTONFLAG_IS_TOGGLE = 2,
	BUTTONFLAG_SKIP_SOUND = 4,
};


#pragma pack(push, 1)
struct D2WinButtonStrc
{
	D2WinControlStrc controlHeader;							//0x00
	uint32_t dwButtonFlags;									//0x40
	int32_t bIsPressed;										//0x44
	int32_t bIsCallbackPending;								//0x48
	int32_t nActivationCounter;								//0x4C
	int32_t nActivationVirtualKey;							//0x50
	int32_t nIsPressedFrameOffset;							//0x54
	int32_t field_58;										//0x58
	int32_t nBaseFrame;										//0x5C
	Font eFont;												//0x60
	Unicode wszText[256];									//0x64
	int32_t nTextColor;										//0x264
	int32_t(__stdcall* pfUpdateHoverState)(SMSGHANDLER_PARAMS*);	//0x268
	int32_t isButtonHovered;								//0x26C
	uint16_t nStringId;										//0x270
	int16_t pad0x272;										//0x272
};
#pragma pack(pop)

