#include "../D2FogExports.h"

FOG_csprintf_t FOG_csprintf = nullptr;
FOG_InitErrorMgr_t FOG_InitErrorMgr = nullptr;
FOG_SetLogPrefix_t FOG_SetLogPrefix = nullptr;
FOG_GetSystemInfo_t FOG_GetSystemInfo = nullptr;
FOG_DisplayAssert_t FOG_DisplayAssert = nullptr;
FOG_DisplayHalt_t FOG_DisplayHalt = nullptr;
FOG_DisplayWarning_t FOG_DisplayWarning = nullptr;
FOG_DisplayError_t FOG_DisplayError = nullptr;
FOG_Trace_t FOG_Trace = nullptr;
FOG_TraceF_t FOG_TraceF = nullptr;
FOG_TraceAppend_t FOG_TraceAppend = nullptr;
FOG_IsHandlingError_t FOG_IsHandlingError = nullptr;
FOG_Alloc_t FOG_Alloc = nullptr;
FOG_Free_t FOG_Free = nullptr;
FOG_Realloc_t FOG_Realloc = nullptr;
FOG_AllocPool_t FOG_AllocPool = nullptr;
FOG_FreePool_t FOG_FreePool = nullptr;
FOG_ReallocPool_t FOG_ReallocPool = nullptr;
FOG_10050_EnterCriticalSection_t FOG_10050_EnterCriticalSection = nullptr;
FOG_10055_GetSyncTime_t FOG_10055_GetSyncTime = nullptr;
FOG_10082_Noop_t FOG_10082_Noop = nullptr;
FOG_10083_Cos_LUT_t FOG_10083_Cos_LUT = nullptr;
FOG_10084_Sin_LUT_t FOG_10084_Sin_LUT = nullptr;
FOG_Decode14BitsFromString_t FOG_Decode14BitsFromString = nullptr;
FOG_Encode14BitsToString_t FOG_Encode14BitsToString = nullptr;
FOG_Decode32BitsFromString_t FOG_Decode32BitsFromString = nullptr;
FOG_Encode32BitsToString_t FOG_Encode32BitsToString = nullptr;
FOG_AsyncDataInitialize_t FOG_AsyncDataInitialize = nullptr;
FOG_AsyncDataDestroy_t FOG_AsyncDataDestroy = nullptr;
FOG_AsyncDataLoadFileEx_t FOG_AsyncDataLoadFileEx = nullptr;
FOG_AsyncDataTestLoaded_t FOG_AsyncDataTestLoaded = nullptr;
FOG_AsyncDataWaitAndGetBuffer_t FOG_AsyncDataWaitAndGetBuffer = nullptr;
FOG_AsyncDataGetBuffer_t FOG_AsyncDataGetBuffer = nullptr;
FOG_AsyncDataGetBufferSize_t FOG_AsyncDataGetBufferSize = nullptr;
FOG_AsyncDataSetResults_t FOG_AsyncDataSetResults = nullptr;
FOG_AsyncDataFree_t FOG_AsyncDataFree = nullptr;
FOG_AsyncDataSetPriority_t FOG_AsyncDataSetPriority = nullptr;
FOG_AsyncDataHandlePriorityChanges_t FOG_AsyncDataHandlePriorityChanges = nullptr;
FOG_MPQSetConfig_t FOG_MPQSetConfig = nullptr;
FOG_MPQFileOpen_t FOG_MPQFileOpen = nullptr;
FOG_MPQFileClose_t FOG_MPQFileClose = nullptr;
FOG_MPQFileRead_t FOG_MPQFileRead = nullptr;
FOG_MPQFileGetSize_t FOG_MPQFileGetSize = nullptr;
FOG_CreatePathHierarchy_t FOG_CreatePathHierarchy = nullptr;
FOG_GetSavePath_t FOG_GetSavePath = nullptr;
FOG_GetInstallPath_t FOG_GetInstallPath = nullptr;
FOG_UseDirect_t FOG_UseDirect = nullptr;
FOG_ComputeStringCRC16_t FOG_ComputeStringCRC16 = nullptr;
FOG_CreateNewPoolSystem_t FOG_CreateNewPoolSystem = nullptr;
FOG_DestroyMemoryPoolSystem_t FOG_DestroyMemoryPoolSystem = nullptr;
FOG_GetMemoryUsage_t FOG_GetMemoryUsage = nullptr;
FOG_InitializeServer_t FOG_InitializeServer = nullptr;
FOG_SetMaxClientsPerGame_t FOG_SetMaxClientsPerGame = nullptr;
FOG_10152_t FOG_10152 = nullptr;
FOG_WaitForSingleObject_t FOG_WaitForSingleObject = nullptr;
FOG_10156_t FOG_10156 = nullptr;
FOG_10157_t FOG_10157 = nullptr;
FOG_10158_t FOG_10158 = nullptr;
FOG_10159_t FOG_10159 = nullptr;
FOG_10161_t FOG_10161 = nullptr;
FOG_10162_t FOG_10162 = nullptr;
FOG_10163_t FOG_10163 = nullptr;
FOG_10164_t FOG_10164 = nullptr;
FOG_10165_t FOG_10165 = nullptr;
FOG_10166_t FOG_10166 = nullptr;
FOG_10170_t FOG_10170 = nullptr;
FOG_10171_t FOG_10171 = nullptr;
FOG_10172_t FOG_10172 = nullptr;
FOG_10173_t FOG_10173 = nullptr;
FOG_10175_t FOG_10175 = nullptr;
FOG_10177_t FOG_10177 = nullptr;
FOG_SetHackListEnabled_t FOG_SetHackListEnabled = nullptr;
FOG_10180_t FOG_10180 = nullptr;
FOG_10181_t FOG_10181 = nullptr;
FOG_10182_Return_t FOG_10182_Return = nullptr;
FOG_10183_Return_t FOG_10183_Return = nullptr;
FOG_10186_t FOG_10186 = nullptr;
FOG_10187_t FOG_10187 = nullptr;
FOG_10207_t FOG_10207 = nullptr;
FOG_CreateBinFile_t FOG_CreateBinFile = nullptr;
FOG_FreeBinFile_t FOG_FreeBinFile = nullptr;
FOG_GetRecordCountFromBinFile_t FOG_GetRecordCountFromBinFile = nullptr;
FOG_AllocLinker_t FOG_AllocLinker = nullptr;
FOG_FreeLinker_t FOG_FreeLinker = nullptr;
FOG_GetLinkIndex_t FOG_GetLinkIndex = nullptr;
FOG_GetStringFromLinkIndex_t FOG_GetStringFromLinkIndex = nullptr;
FOG_10215_t FOG_10215 = nullptr;
FOG_10216_AddRecordToLinkingTable_t FOG_10216_AddRecordToLinkingTable = nullptr;
FOG_GetRowFromTxt_t FOG_GetRowFromTxt = nullptr;
FOG_10219_t FOG_10219 = nullptr;
FOG_10222_t FOG_10222 = nullptr;
FOG_10223_t FOG_10223 = nullptr;
FOG_10224_t FOG_10224 = nullptr;
FOG_IsExpansion_t FOG_IsExpansion = nullptr;
FOG_ComputeChecksum_t FOG_ComputeChecksum = nullptr;
FOG_PopCount_t FOG_PopCount = nullptr;
FOG_10233_t FOG_10233 = nullptr;
FOG_LeadingZeroesCount_t FOG_LeadingZeroesCount = nullptr;
FOG_10255_t FOG_10255 = nullptr;


void InitD2FogExports()
{
    auto fogModule = GetModuleHandle("Fog");

    FOG_csprintf = (FOG_csprintf_t)GetProcAddress(fogModule, (LPCSTR)10018);
    FOG_InitErrorMgr = (FOG_InitErrorMgr_t)GetProcAddress(fogModule, (LPCSTR)10019);
    FOG_SetLogPrefix = (FOG_SetLogPrefix_t)GetProcAddress(fogModule, (LPCSTR)10021);
    FOG_GetSystemInfo = (FOG_GetSystemInfo_t)GetProcAddress(fogModule, (LPCSTR)10022);
    FOG_DisplayAssert = (FOG_DisplayAssert_t)GetProcAddress(fogModule, (LPCSTR)10023);
    FOG_DisplayHalt = (FOG_DisplayHalt_t)GetProcAddress(fogModule, (LPCSTR)10024);
    FOG_DisplayWarning = (FOG_DisplayWarning_t)GetProcAddress(fogModule, (LPCSTR)10025);
    FOG_DisplayError = (FOG_DisplayError_t)GetProcAddress(fogModule, (LPCSTR)10026);
    FOG_Trace = (FOG_Trace_t)GetProcAddress(fogModule, (LPCSTR)10029);
    FOG_TraceF = (FOG_TraceF_t)GetProcAddress(fogModule, (LPCSTR)10030);
    FOG_TraceAppend = (FOG_TraceAppend_t)GetProcAddress(fogModule, (LPCSTR)10031);
    FOG_IsHandlingError = (FOG_IsHandlingError_t)GetProcAddress(fogModule, (LPCSTR)10039);
    FOG_Alloc = (FOG_Alloc_t)GetProcAddress(fogModule, (LPCSTR)10042);
    FOG_Free = (FOG_Free_t)GetProcAddress(fogModule, (LPCSTR)10043);
    FOG_Realloc = (FOG_Realloc_t)GetProcAddress(fogModule, (LPCSTR)10044);
    FOG_AllocPool = (FOG_AllocPool_t)GetProcAddress(fogModule, (LPCSTR)10045);
    FOG_FreePool = (FOG_FreePool_t)GetProcAddress(fogModule, (LPCSTR)10046);
    FOG_ReallocPool = (FOG_ReallocPool_t)GetProcAddress(fogModule, (LPCSTR)10047);
    FOG_10050_EnterCriticalSection = (FOG_10050_EnterCriticalSection_t)GetProcAddress(fogModule, (LPCSTR)10050);
    FOG_10055_GetSyncTime = (FOG_10055_GetSyncTime_t)GetProcAddress(fogModule, (LPCSTR)10055);
    FOG_10082_Noop = (FOG_10082_Noop_t)GetProcAddress(fogModule, (LPCSTR)10082);
    FOG_10083_Cos_LUT = (FOG_10083_Cos_LUT_t)GetProcAddress(fogModule, (LPCSTR)10083);
    FOG_10084_Sin_LUT = (FOG_10084_Sin_LUT_t)GetProcAddress(fogModule, (LPCSTR)10084);
    FOG_Decode14BitsFromString = (FOG_Decode14BitsFromString_t)GetProcAddress(fogModule, (LPCSTR)10085);
    FOG_Encode14BitsToString = (FOG_Encode14BitsToString_t)GetProcAddress(fogModule, (LPCSTR)10086);
    FOG_Decode32BitsFromString = (FOG_Decode32BitsFromString_t)GetProcAddress(fogModule, (LPCSTR)10087);
    FOG_Encode32BitsToString = (FOG_Encode32BitsToString_t)GetProcAddress(fogModule, (LPCSTR)10088);
    FOG_AsyncDataInitialize = (FOG_AsyncDataInitialize_t)GetProcAddress(fogModule, (LPCSTR)10089);
    FOG_AsyncDataDestroy = (FOG_AsyncDataDestroy_t)GetProcAddress(fogModule, (LPCSTR)10090);
    FOG_AsyncDataLoadFileEx = (FOG_AsyncDataLoadFileEx_t)GetProcAddress(fogModule, (LPCSTR)10091);
    FOG_AsyncDataTestLoaded = (FOG_AsyncDataTestLoaded_t)GetProcAddress(fogModule, (LPCSTR)10092);
    FOG_AsyncDataWaitAndGetBuffer = (FOG_AsyncDataWaitAndGetBuffer_t)GetProcAddress(fogModule, (LPCSTR)10093);
    FOG_AsyncDataGetBuffer = (FOG_AsyncDataGetBuffer_t)GetProcAddress(fogModule, (LPCSTR)10094);
    FOG_AsyncDataGetBufferSize = (FOG_AsyncDataGetBufferSize_t)GetProcAddress(fogModule, (LPCSTR)10095);
    FOG_AsyncDataSetResults = (FOG_AsyncDataSetResults_t)GetProcAddress(fogModule, (LPCSTR)10096);
    FOG_AsyncDataFree = (FOG_AsyncDataFree_t)GetProcAddress(fogModule, (LPCSTR)10097);
    FOG_AsyncDataSetPriority = (FOG_AsyncDataSetPriority_t)GetProcAddress(fogModule, (LPCSTR)10099);
    FOG_AsyncDataHandlePriorityChanges = (FOG_AsyncDataHandlePriorityChanges_t)GetProcAddress(fogModule, (LPCSTR)10100);
    FOG_MPQSetConfig = (FOG_MPQSetConfig_t)GetProcAddress(fogModule, (LPCSTR)10101);
    FOG_MPQFileOpen = (FOG_MPQFileOpen_t)GetProcAddress(fogModule, (LPCSTR)10102);
    FOG_MPQFileClose = (FOG_MPQFileClose_t)GetProcAddress(fogModule, (LPCSTR)10103);
    FOG_MPQFileRead = (FOG_MPQFileRead_t)GetProcAddress(fogModule, (LPCSTR)10104);
    FOG_MPQFileGetSize = (FOG_MPQFileGetSize_t)GetProcAddress(fogModule, (LPCSTR)10105);
    FOG_CreatePathHierarchy = (FOG_CreatePathHierarchy_t)GetProcAddress(fogModule, (LPCSTR)10114);
    FOG_GetSavePath = (FOG_GetSavePath_t)GetProcAddress(fogModule, (LPCSTR)10115);
    FOG_GetInstallPath = (FOG_GetInstallPath_t)GetProcAddress(fogModule, (LPCSTR)10116);
    FOG_UseDirect = (FOG_UseDirect_t)GetProcAddress(fogModule, (LPCSTR)10117);
    FOG_ComputeStringCRC16 = (FOG_ComputeStringCRC16_t)GetProcAddress(fogModule, (LPCSTR)10137);
    FOG_CreateNewPoolSystem = (FOG_CreateNewPoolSystem_t)GetProcAddress(fogModule, (LPCSTR)10142);
    FOG_DestroyMemoryPoolSystem = (FOG_DestroyMemoryPoolSystem_t)GetProcAddress(fogModule, (LPCSTR)10143);
    FOG_GetMemoryUsage = (FOG_GetMemoryUsage_t)GetProcAddress(fogModule, (LPCSTR)10147);
    FOG_InitializeServer = (FOG_InitializeServer_t)GetProcAddress(fogModule, (LPCSTR)10149);
    FOG_SetMaxClientsPerGame = (FOG_SetMaxClientsPerGame_t)GetProcAddress(fogModule, (LPCSTR)10151);
    FOG_10152 = (FOG_10152_t)GetProcAddress(fogModule, (LPCSTR)10152);
    FOG_WaitForSingleObject = (FOG_WaitForSingleObject_t)GetProcAddress(fogModule, (LPCSTR)10154);
    FOG_10156 = (FOG_10156_t)GetProcAddress(fogModule, (LPCSTR)10156);
    FOG_10157 = (FOG_10157_t)GetProcAddress(fogModule, (LPCSTR)10157);
    FOG_10158 = (FOG_10158_t)GetProcAddress(fogModule, (LPCSTR)10158);
    FOG_10159 = (FOG_10159_t)GetProcAddress(fogModule, (LPCSTR)10159);
    FOG_10161 = (FOG_10161_t)GetProcAddress(fogModule, (LPCSTR)10161);
    FOG_10162 = (FOG_10162_t)GetProcAddress(fogModule, (LPCSTR)10162);
    FOG_10163 = (FOG_10163_t)GetProcAddress(fogModule, (LPCSTR)10163);
    FOG_10164 = (FOG_10164_t)GetProcAddress(fogModule, (LPCSTR)10164);
    FOG_10165 = (FOG_10165_t)GetProcAddress(fogModule, (LPCSTR)10165);
    FOG_10166 = (FOG_10166_t)GetProcAddress(fogModule, (LPCSTR)10166);
    FOG_10170 = (FOG_10170_t)GetProcAddress(fogModule, (LPCSTR)10170);
    FOG_10171 = (FOG_10171_t)GetProcAddress(fogModule, (LPCSTR)10171);
    FOG_10172 = (FOG_10172_t)GetProcAddress(fogModule, (LPCSTR)10172);
    FOG_10173 = (FOG_10173_t)GetProcAddress(fogModule, (LPCSTR)10173);
    FOG_10175 = (FOG_10175_t)GetProcAddress(fogModule, (LPCSTR)10175);
    FOG_10177 = (FOG_10177_t)GetProcAddress(fogModule, (LPCSTR)10177);
    FOG_SetHackListEnabled = (FOG_SetHackListEnabled_t)GetProcAddress(fogModule, (LPCSTR)10178);
    FOG_10180 = (FOG_10180_t)GetProcAddress(fogModule, (LPCSTR)10180);
    FOG_10181 = (FOG_10181_t)GetProcAddress(fogModule, (LPCSTR)10181);
    FOG_10182_Return = (FOG_10182_Return_t)GetProcAddress(fogModule, (LPCSTR)10182);
    FOG_10183_Return = (FOG_10183_Return_t)GetProcAddress(fogModule, (LPCSTR)10183);
    FOG_10186 = (FOG_10186_t)GetProcAddress(fogModule, (LPCSTR)10186);
    FOG_10187 = (FOG_10187_t)GetProcAddress(fogModule, (LPCSTR)10187);
    FOG_10207 = (FOG_10207_t)GetProcAddress(fogModule, (LPCSTR)10207);
    FOG_CreateBinFile = (FOG_CreateBinFile_t)GetProcAddress(fogModule, (LPCSTR)10208);
    FOG_FreeBinFile = (FOG_FreeBinFile_t)GetProcAddress(fogModule, (LPCSTR)10209);
    FOG_GetRecordCountFromBinFile = (FOG_GetRecordCountFromBinFile_t)GetProcAddress(fogModule, (LPCSTR)10210);
    FOG_AllocLinker = (FOG_AllocLinker_t)GetProcAddress(fogModule, (LPCSTR)10211);
    FOG_FreeLinker = (FOG_FreeLinker_t)GetProcAddress(fogModule, (LPCSTR)10212);
    FOG_GetLinkIndex = (FOG_GetLinkIndex_t)GetProcAddress(fogModule, (LPCSTR)10213);
    FOG_GetStringFromLinkIndex = (FOG_GetStringFromLinkIndex_t)GetProcAddress(fogModule, (LPCSTR)10214);
    FOG_10215 = (FOG_10215_t)GetProcAddress(fogModule, (LPCSTR)10215);
    FOG_10216_AddRecordToLinkingTable = (FOG_10216_AddRecordToLinkingTable_t)GetProcAddress(fogModule, (LPCSTR)10216);
    FOG_GetRowFromTxt = (FOG_GetRowFromTxt_t)GetProcAddress(fogModule, (LPCSTR)10217);
    FOG_10219 = (FOG_10219_t)GetProcAddress(fogModule, (LPCSTR)10219);
    FOG_10222 = (FOG_10222_t)GetProcAddress(fogModule, (LPCSTR)10222);
    FOG_10223 = (FOG_10223_t)GetProcAddress(fogModule, (LPCSTR)10223);
    FOG_10224 = (FOG_10224_t)GetProcAddress(fogModule, (LPCSTR)10224);
    FOG_IsExpansion = (FOG_IsExpansion_t)GetProcAddress(fogModule, (LPCSTR)10227);
    FOG_ComputeChecksum = (FOG_ComputeChecksum_t)GetProcAddress(fogModule, (LPCSTR)10229);
    FOG_PopCount = (FOG_PopCount_t)GetProcAddress(fogModule, (LPCSTR)10230);
    FOG_10233 = (FOG_10233_t)GetProcAddress(fogModule, (LPCSTR)10233);
    FOG_LeadingZeroesCount = (FOG_LeadingZeroesCount_t)GetProcAddress(fogModule, (LPCSTR)10252);
    FOG_10255 = (FOG_10255_t)GetProcAddress(fogModule, (LPCSTR)10255);
}
