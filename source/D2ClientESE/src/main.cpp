#include <Windows.h>
#include <../D2MooHeaders.h>
#include <../D2CommonExports.h>
#include "LibESE.h"

BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		InitD2MooHeaders();
		InitD2CommonExports();
		InitD2FogExports();
		InitD2WinExports();
		InitD2ClientExports();
		break;
	}
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
