#pragma once

#pragma warning(push)
#pragma warning(disable:4820 4121)
#include <Winsock2.h>
#pragma warning(pop)

#include <D2BasicTypes.h>
#include <Fog.h>

#pragma pack(1)

struct FSafeSock
{
	BOOL bConnected;
	BOOL bConnecting;
	SOCKET nSocket;
	CRITICAL_SECTION tCriticalSection;
	HANDLE hThread;
	DWORD nThreadId;
	BOOL bStopping;
	DWORD nFogErrorCode;
	DWORD nWSALastError;
	char szName[64];
};

#pragma pack()
