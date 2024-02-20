#pragma once

#include "D2WinControlHeader.h"


struct D2WinTextBoxStrc;

#pragma pack(push, 1)
struct D2WinScrollBarStrc
{
	D2WinControlStrc controlHeader;					//0x00
	int32_t bIsUpperArrowPressed;					//0x40
	int32_t bIsLowerArrowPressed;					//0x44
	int32_t nMaxSteps;								//0x48
	int32_t nCurrentStep;							//0x4C
	int32_t field_50;								//0x50
	D2WinTextBoxStrc* pTextBox;						//0x54
	int32_t bIsStepIndicatorDragged;				//0x58
	void(__stdcall* field_5C)(SMSGHANDLER_PARAMS*);		//0x5C
};
#pragma pack(pop)
