
#pragma once

#include <Windows.h>
#include <cstdint>
#include <StormHandles.h>
#include <Calc.h>

struct AsyncData;
struct QServer;
struct D2BinFileStrc;
struct D2BinFieldStrc;
struct AsyncDataLoadFileCallback;

void InitD2FogExports();

typedef int (*D2ExceptionCallback)();

typedef  int(__stdcall* DATATBLS_CalcEvaluateExpression_t)(const FOGASTNodeStrc* pExpressionBuffer, int32_t nExpressionBufferSize, CalcFogCallBack2_t fpParamCallBack, D2CalcCallbackInfoStrc* pTableData, int nTableSize, void* pUserData);
typedef  int(__stdcall* DATATBLS_CompileExpression_t)(const char* szFormulaString, FOGASTNodeStrc* pOutASTBuffer, int nOutASTBufferSize, CalcGetKeyWordToNumber_t pfnFunctionNameToId, CalcGetFunctionParameterCount_t pfnGetFunctionParameterCount, CalcGetLinkerIndex_t pfnLinkParse);

extern DATATBLS_CalcEvaluateExpression_t DATATBLS_CalcEvaluateExpression;
extern DATATBLS_CompileExpression_t DATATBLS_CompileExpression;

typedef const char* (__cdecl *FOG_csprintf_t)(char* szDest, const char* szFormat, ...);
typedef void (__fastcall *FOG_InitErrorMgr_t)(const char* szProgramName, D2ExceptionCallback pExceptionCallback, const char* szVersion, BOOL bLogToFile);
typedef int (__fastcall *FOG_SetLogPrefix_t)(const char* szLogPrefix);
typedef void* (__cdecl *FOG_GetSystemInfo_t)();
typedef void (__cdecl *FOG_DisplayAssert_t)(const char* szMsg, const char* szFile, int nLine);
typedef void (__cdecl *FOG_DisplayHalt_t)(const char* szMsg, const char* szFile, int nLine);
typedef void (__cdecl *FOG_DisplayWarning_t)(const char* szMsg, const char* szFile, int nLine);
typedef void (__cdecl *FOG_DisplayError_t)(int nCategory, const char* szMsg, const char* szFile, int nLine);
typedef void (__cdecl *FOG_Trace_t)(const char* szFormat, ...);
typedef void (__cdecl *FOG_TraceF_t)(const char* pFileSubName, const char* szFormat, ...);
typedef void (__cdecl *FOG_TraceAppend_t)(const char* szFormat, ...);
typedef BOOL (__cdecl *FOG_IsHandlingError_t)();
typedef void* (__fastcall *FOG_Alloc_t)(int nSize, const char* szFile, int nLine, int n0);
typedef void (__fastcall *FOG_Free_t)(void* pFree, const char* szFile, int nLine, int n0);
typedef void (__fastcall *FOG_Realloc_t)(void* pMemory, int nSize, const char* szFile, int nLine, int n0);
typedef void* (__fastcall *FOG_AllocPool_t)(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);
typedef void (__fastcall *FOG_FreePool_t)(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);
typedef void* (__fastcall *FOG_ReallocPool_t)(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);
typedef void (__fastcall *FOG_10050_EnterCriticalSection_t)(_Acquires_lock_(*_Curr_) CRITICAL_SECTION* pCriticalSection, int nLine);
typedef int32_t (__fastcall *FOG_10055_GetSyncTime_t)();
typedef void (__fastcall *FOG_10082_Noop_t)();
typedef float (__stdcall *FOG_10083_Cos_LUT_t)(int16_t index);
typedef float (__stdcall *FOG_10084_Sin_LUT_t)(int16_t index);
typedef unsigned (__stdcall *FOG_Decode14BitsFromString_t)(uint16_t* p2Characters);
typedef void (__stdcall *FOG_Encode14BitsToString_t)(uint16_t* p2Characters, uint32_t value);
typedef unsigned (__stdcall *FOG_Decode32BitsFromString_t)(uint32_t* p4Characters);
typedef void (__stdcall *FOG_Encode32BitsToString_t)(uint32_t* p4Characters, uint32_t value);
typedef void (__fastcall *FOG_AsyncDataInitialize_t)(BOOL bEnableAsyncOperations);
typedef void (__fastcall *FOG_AsyncDataDestroy_t)();
typedef AsyncData* (__fastcall *FOG_AsyncDataLoadFileEx_t)(void* pMemPool, const char* pFileName, BOOL bAllowAsync, LONG nFileOffset, int nFileSize, void* pBuffer, AsyncDataLoadFileCallback* asyncOpDesc, int a8, const char* sourceFile, int sourceLine);
typedef BOOL (__fastcall *FOG_AsyncDataTestLoaded_t)(AsyncData* pAsyncData);
typedef void (__fastcall *FOG_AsyncDataWaitAndGetBuffer_t)(AsyncData* pAsyncData);
typedef void* (__fastcall *FOG_AsyncDataGetBuffer_t)(AsyncData* pAsyncData);
typedef DWORD (__fastcall *FOG_AsyncDataGetBufferSize_t)(AsyncData* pAsyncData);
typedef void (__fastcall *FOG_AsyncDataSetResults_t)(AsyncData* pAsyncData, void* pBuffer, int nBufferSize);
typedef void (__fastcall *FOG_AsyncDataFree_t)(AsyncData* pAsyncData);
typedef void (__fastcall *FOG_AsyncDataSetPriority_t)(AsyncData* pAsyncData, int nPriority);
typedef void (__fastcall *FOG_AsyncDataHandlePriorityChanges_t)(BOOL bPostpone);
typedef BOOL (__fastcall *FOG_MPQSetConfig_t)(int dwDirectAccessFlags, int bEnableSeekOptimization);
typedef BOOL (__fastcall *FOG_MPQFileOpen_t)(const char* szFile, HSFILE* pFileHandle);
typedef void (__fastcall *FOG_MPQFileClose_t)(HSFILE pFile);
typedef BOOL (__fastcall *FOG_MPQFileRead_t)(HSFILE pFile, void* pBuffer, size_t nSize, int* nBytesRead, uint32_t, uint32_t, uint32_t);
typedef size_t (__fastcall *FOG_MPQFileGetSize_t)(HSFILE pFileHandle, uint32_t* lpFileSizeHigh);
typedef BOOL (__fastcall *FOG_CreatePathHierarchy_t)(char* szPath);
typedef size_t (__fastcall *FOG_GetSavePath_t)(char* pPathBuffer, size_t nBufferSize);
typedef BOOL (__fastcall *FOG_GetInstallPath_t)(char* pPathBuffer, size_t nBufferSize);
typedef BOOL (__fastcall *FOG_UseDirect_t)();
typedef uint16_t (__stdcall *FOG_ComputeStringCRC16_t)(const char* szString);
typedef void (__cdecl *FOG_CreateNewPoolSystem_t)(void** pMemPoolSystem, const char* szName, uint32_t nPools, uint32_t nUnused);
typedef void (__cdecl *FOG_DestroyMemoryPoolSystem_t)(void* pMemoryPoolSystem);
typedef DWORD (__cdecl *FOG_GetMemoryUsage_t)(void*);
typedef QServer* (__stdcall *FOG_InitializeServer_t)(int, int, int, int, void*, void*, void*, void*);
typedef int (__stdcall *FOG_SetMaxClientsPerGame_t)(QServer*, int);
typedef int (__stdcall *FOG_10152_t)(void*, const uint8_t*, int);
typedef int (__stdcall *FOG_WaitForSingleObject_t)(void*, int);
typedef int (__stdcall *FOG_10156_t)(void*, int, uint8_t*, int);
typedef int (__stdcall *FOG_10157_t)(void*, int, const uint8_t*, int);
typedef int (__stdcall *FOG_10158_t)(void*, int);
typedef int (__stdcall *FOG_10159_t)(void*, int, char*, int);
typedef int (__stdcall *FOG_10161_t)(void*, int);
typedef int (__stdcall *FOG_10162_t)(void*, int, const char*, int);
typedef int (__stdcall *FOG_10163_t)(void*, int, const char*, int);
typedef int (__stdcall *FOG_10164_t)(void*, int, int, int);
typedef int (__stdcall *FOG_10165_t)(void*, int, const char*, int);
typedef int (__stdcall *FOG_10166_t)(void*, int, int, int);
typedef int (__stdcall *FOG_10170_t)(void*, int);
typedef int (__stdcall *FOG_10171_t)(void*, void*);
typedef int (__stdcall *FOG_10172_t)(void*, int, int);
typedef int (__stdcall *FOG_10173_t)(void*, int);
typedef int (__stdcall *FOG_10175_t)(void*, const uint8_t*, int, int);
typedef int (__stdcall *FOG_10177_t)(void*, int);
typedef int (__stdcall *FOG_SetHackListEnabled_t)(QServer* pServer, BOOL bHacklistEnabled);
typedef int (__stdcall *FOG_10180_t)(void*);
typedef int (__stdcall *FOG_10181_t)(void*, const uint8_t*, int, int);
typedef int (__stdcall *FOG_10182_Return_t)(void*);
typedef int (__stdcall *FOG_10183_Return_t)(void*, int);
typedef int (__stdcall *FOG_10186_t)(void*, int, int);
typedef int (__fastcall *FOG_10187_t)(void*, int, int);
typedef void (__stdcall *FOG_10207_t)(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize);
typedef D2BinFileStrc* (__stdcall *FOG_CreateBinFile_t)(void* pDataBuffer, int nBufferSize);
typedef void (__stdcall *FOG_FreeBinFile_t)(D2BinFileStrc* pBinFile);
typedef int (__stdcall *FOG_GetRecordCountFromBinFile_t)(D2BinFileStrc* pBinFile);
typedef void* (__stdcall *FOG_AllocLinker_t)(const char* szFile, int nLine);
typedef void (__stdcall *FOG_FreeLinker_t)(void* pLinker);
typedef int (__stdcall *FOG_GetLinkIndex_t)(void* pLink, uint32_t dwCode, BOOL bLogError);
typedef int (__stdcall *FOG_GetStringFromLinkIndex_t)(void* pLinker, int nIndex, char* szString);
typedef int (__stdcall *FOG_10215_t)(void* pBin, int a2);
typedef int (__stdcall *FOG_10216_AddRecordToLinkingTable_t)(void* pBin, const char* a2);
typedef int (__stdcall *FOG_GetRowFromTxt_t)(void* pBin, char* szText, int nColumn);
typedef int (__fastcall *FOG_10219_t)(uint8_t*);
typedef int (__fastcall *FOG_10222_t)(const uint8_t*, int);
typedef int (__fastcall *FOG_10223_t)(uint8_t*, int, const uint8_t*, int);
typedef int (__fastcall *FOG_10224_t)(char*, int, uint8_t*, int);
typedef int (__fastcall *FOG_IsExpansion_t)();
typedef uint32_t (__stdcall *FOG_ComputeChecksum_t)(void* pData, size_t dwSize);
typedef uint32_t (__stdcall *FOG_PopCount_t)(void* pData, size_t dwSize);
typedef void (__fastcall *FOG_10233_t)(const char*, int);
typedef uint32_t (__stdcall *FOG_LeadingZeroesCount_t)(uint32_t nValue);
typedef char* (__stdcall *FOG_10255_t)(void* pLinker, int nId, int a3);

extern FOG_csprintf_t FOG_csprintf;
extern FOG_InitErrorMgr_t FOG_InitErrorMgr;
extern FOG_SetLogPrefix_t FOG_SetLogPrefix;
extern FOG_GetSystemInfo_t FOG_GetSystemInfo;
extern FOG_DisplayAssert_t FOG_DisplayAssert;
extern FOG_DisplayHalt_t FOG_DisplayHalt;
extern FOG_DisplayWarning_t FOG_DisplayWarning;
extern FOG_DisplayError_t FOG_DisplayError;
extern FOG_Trace_t FOG_Trace;
extern FOG_TraceF_t FOG_TraceF;
extern FOG_TraceAppend_t FOG_TraceAppend;
extern FOG_IsHandlingError_t FOG_IsHandlingError;
extern FOG_Alloc_t FOG_Alloc;
extern FOG_Free_t FOG_Free;
extern FOG_Realloc_t FOG_Realloc;
extern FOG_AllocPool_t FOG_AllocPool;
extern FOG_FreePool_t FOG_FreePool;
extern FOG_ReallocPool_t FOG_ReallocPool;
extern FOG_10050_EnterCriticalSection_t FOG_10050_EnterCriticalSection;
extern FOG_10055_GetSyncTime_t FOG_10055_GetSyncTime;
extern FOG_10082_Noop_t FOG_10082_Noop;
extern FOG_10083_Cos_LUT_t FOG_10083_Cos_LUT;
extern FOG_10084_Sin_LUT_t FOG_10084_Sin_LUT;
extern FOG_Decode14BitsFromString_t FOG_Decode14BitsFromString;
extern FOG_Encode14BitsToString_t FOG_Encode14BitsToString;
extern FOG_Decode32BitsFromString_t FOG_Decode32BitsFromString;
extern FOG_Encode32BitsToString_t FOG_Encode32BitsToString;
extern FOG_AsyncDataInitialize_t FOG_AsyncDataInitialize;
extern FOG_AsyncDataDestroy_t FOG_AsyncDataDestroy;
extern FOG_AsyncDataLoadFileEx_t FOG_AsyncDataLoadFileEx;
extern FOG_AsyncDataTestLoaded_t FOG_AsyncDataTestLoaded;
extern FOG_AsyncDataWaitAndGetBuffer_t FOG_AsyncDataWaitAndGetBuffer;
extern FOG_AsyncDataGetBuffer_t FOG_AsyncDataGetBuffer;
extern FOG_AsyncDataGetBufferSize_t FOG_AsyncDataGetBufferSize;
extern FOG_AsyncDataSetResults_t FOG_AsyncDataSetResults;
extern FOG_AsyncDataFree_t FOG_AsyncDataFree;
extern FOG_AsyncDataSetPriority_t FOG_AsyncDataSetPriority;
extern FOG_AsyncDataHandlePriorityChanges_t FOG_AsyncDataHandlePriorityChanges;
extern FOG_MPQSetConfig_t FOG_MPQSetConfig;
extern FOG_MPQFileOpen_t FOG_MPQFileOpen;
extern FOG_MPQFileClose_t FOG_MPQFileClose;
extern FOG_MPQFileRead_t FOG_MPQFileRead;
extern FOG_MPQFileGetSize_t FOG_MPQFileGetSize;
extern FOG_CreatePathHierarchy_t FOG_CreatePathHierarchy;
extern FOG_GetSavePath_t FOG_GetSavePath;
extern FOG_GetInstallPath_t FOG_GetInstallPath;
extern FOG_UseDirect_t FOG_UseDirect;
extern FOG_ComputeStringCRC16_t FOG_ComputeStringCRC16;
extern FOG_CreateNewPoolSystem_t FOG_CreateNewPoolSystem;
extern FOG_DestroyMemoryPoolSystem_t FOG_DestroyMemoryPoolSystem;
extern FOG_GetMemoryUsage_t FOG_GetMemoryUsage;
extern FOG_InitializeServer_t FOG_InitializeServer;
extern FOG_SetMaxClientsPerGame_t FOG_SetMaxClientsPerGame;
extern FOG_10152_t FOG_10152;
extern FOG_WaitForSingleObject_t FOG_WaitForSingleObject;
extern FOG_10156_t FOG_10156;
extern FOG_10157_t FOG_10157;
extern FOG_10158_t FOG_10158;
extern FOG_10159_t FOG_10159;
extern FOG_10161_t FOG_10161;
extern FOG_10162_t FOG_10162;
extern FOG_10163_t FOG_10163;
extern FOG_10164_t FOG_10164;
extern FOG_10165_t FOG_10165;
extern FOG_10166_t FOG_10166;
extern FOG_10170_t FOG_10170;
extern FOG_10171_t FOG_10171;
extern FOG_10172_t FOG_10172;
extern FOG_10173_t FOG_10173;
extern FOG_10175_t FOG_10175;
extern FOG_10177_t FOG_10177;
extern FOG_SetHackListEnabled_t FOG_SetHackListEnabled;
extern FOG_10180_t FOG_10180;
extern FOG_10181_t FOG_10181;
extern FOG_10182_Return_t FOG_10182_Return;
extern FOG_10183_Return_t FOG_10183_Return;
extern FOG_10186_t FOG_10186;
extern FOG_10187_t FOG_10187;
extern FOG_10207_t FOG_10207;
extern FOG_CreateBinFile_t FOG_CreateBinFile;
extern FOG_FreeBinFile_t FOG_FreeBinFile;
extern FOG_GetRecordCountFromBinFile_t FOG_GetRecordCountFromBinFile;
extern FOG_AllocLinker_t FOG_AllocLinker;
extern FOG_FreeLinker_t FOG_FreeLinker;
extern FOG_GetLinkIndex_t FOG_GetLinkIndex;
extern FOG_GetStringFromLinkIndex_t FOG_GetStringFromLinkIndex;
extern FOG_10215_t FOG_10215;
extern FOG_10216_AddRecordToLinkingTable_t FOG_10216_AddRecordToLinkingTable;
extern FOG_GetRowFromTxt_t FOG_GetRowFromTxt;
extern FOG_10219_t FOG_10219;
extern FOG_10222_t FOG_10222;
extern FOG_10223_t FOG_10223;
extern FOG_10224_t FOG_10224;
extern FOG_IsExpansion_t FOG_IsExpansion;
extern FOG_ComputeChecksum_t FOG_ComputeChecksum;
extern FOG_PopCount_t FOG_PopCount;
extern FOG_10233_t FOG_10233;
extern FOG_LeadingZeroesCount_t FOG_LeadingZeroesCount;
extern FOG_10255_t FOG_10255;
