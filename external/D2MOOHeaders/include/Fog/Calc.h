#pragma once

#include <D2BasicTypes.h>


#include <Fog.h>

#pragma pack(1)

enum FOGCalcExpressionParserTokenType : uint8_t
{
	TOKEN_PAREN_OPEN = 0,
	TOKEN_PAREN_CLOSE = 1,
	TOKEN_COMMA = 2,
	TOKEN_PLUS = 3,
	TOKEN_MINUS = 4,
	TOKEN_ASTERISK = 5,
	TOKEN_SLASH = 6,
	TOKEN_QUESTION_MARK = 7,
	TOKEN_COLON = 8,
	TOKEN_CIRCUM = 9,
	TOKEN_LESS_OR_EQ = 10,
	TOKEN_LESS = 11,
	TOKEN_GREATER_OR_EQ = 12,
	TOKEN_GREATER = 13,
	TOKEN_LOGIC_EQUALS = 14,
	TOKEN_LOGIC_DIFFERENT = 15,
	TOKEN_CUSTOM_RAW_CONSTANT = 16,
	TOKEN_CUSTOM_FUNCTION_PARAMETER_CONSTANT = 17,
	TOKEN_CUSTOM_FUNCTION_TABLE = 18,
};

enum FOGASTType : uint8_t
{
	AST_None = 0,
	AST_CallbackTable = 1,
	AST_Parenthesis_Open = 2,
	AST_Callback_Param_Separator = 3,
	AST_Callback_Param_UInt8 = 4,
	AST_Callback_Param_UInt16 = 5,
	AST_Callback_Param_UInt32 = 6,
	AST_Raw_Int8 = 7,
	AST_Raw_Int16 = 8,
	AST_Raw_Int32 = 9,
	AST_LessThan = 10,
	AST_GreaterThan = 11,
	AST_LessOrEqualThan = 12,
	AST_GreaterOrEqualThan = 13,
	AST_Equal = 14,
	AST_NotEqual = 15,
	AST_Addition = 16,
	AST_Substraction = 17,
	AST_Multipliction = 18,
	AST_Division = 19,
	AST_Power = 20,
	AST_Negate = 21,
	AST_Ternary = 22,
	AST_Ternary_Colon = 23,
	AST_COUNT = 24,
};

union FOGASTNodeStrc
{
	FOGASTType nType;
	uint8_t nRawValue;
};

typedef int(__fastcall* CalcFogCallBack_t)(int, int, int, void*);
typedef int(__fastcall* CalcFogCallBack2_t)(int, void*);

struct D2CalcCallbackInfoStrc
{
	CalcFogCallBack_t fpCallBack;            //0x00
	int nParameters;                         //0x04
};

typedef int(__fastcall* CalcGetKeyWordToNumber_t)(char* szKey);
typedef int(__fastcall* CalcGetFunctionParameterCount_t)(int nFunctionIndex);
typedef int(__fastcall* CalcGetLinkerIndex_t)(char* szText, BOOL* pOutHasResolvedToConstant, int nAST, int nKeywordNumber);
typedef int(__fastcall* CalcProcessCache_t)(int nIndex);

struct FOGExpressionParserContextStrc
{
	FOGASTType tPendingOperationsASTs[64]; // 0x000
	int32_t tLinkerIndex[64];              // 0x040
	int32_t nPendingOps;                   // 0x140
	int32_t nPendingParameters;            // 0x144
};

struct Fog64IntStack
{
  static const int32_t nCapacity = 64;
  
  int32_t tData[nCapacity];
  int32_t nSize;
};

#pragma pack()
