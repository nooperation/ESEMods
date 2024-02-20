#pragma once

#include <Windows.h>
#include <cstdint>

#include "DrawMode.h"
#include "Font.h"
#include <D2Unicode.h>

struct D2CellFileStrc;


#pragma pack(push, 1)
struct D2CharStrc
{
	WORD wChar;										//0x00
	BYTE unk0x02;									//0x02
	BYTE nWidth;									//0x03
	BYTE nHeight;									//0x04
	BYTE unk0x05;									//0x05
	WORD unk0x06;									//0x06
	WORD nImageIndex;								//0x08
	DWORD unk0x0A;									//0x0A
};

struct D2FontStrc
{
	DWORD dwHeader;									//0x00 - 'Woo!'
	WORD unk0x04;									//0x04
	WORD unk0x06;									//0x06
	WORD unk0x08;									//0x08
	BYTE nHeight;									//0x0A
	BYTE nWidth;									//0x0B
	D2CharStrc pChars[256];							//0x0C
};

struct D2FontCacheStrc
{
	D2CellFileStrc* pCellFile;						//0x00
	D2FontStrc* pFontInfo[2];						//0x04
	D2CharStrc* pCharInfo;							//0x0C
	DWORD dwShiftedTickCount;						//0x10
};

struct D2SplittedTextStrc
{
	Unicode* wszLine;								//0x00
	D2SplittedTextStrc* pNextLine;					//0x04
};
#pragma pack(