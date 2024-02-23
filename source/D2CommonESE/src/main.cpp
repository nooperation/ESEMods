#include <Windows.h>
#include <../D2MooHeaders.h>
#include <../D2CommonExports.h>
#include "ESEDamageCalc.h"

typedef uint32_t(__fastcall* PacketHandlerFunc_t)(const char* packet, uint32_t packetLength);

struct PacketHandlerEntry
{
	PacketHandlerFunc_t Callback;
	uint32_t PacketSize;
	uint32_t UnknownFlag;
};

BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		InitD2MooHeaders();
		InitD2CommonExports();
		InitD2FogExports();

		auto d2NetHandle = GetModuleHandle("D2Net.dll");
		volatile int32_t* pServerPacketSizeTable = (volatile int32_t*)((unsigned char*)d2NetHandle + 0x8148);
		pServerPacketSizeTable[0x44] = sizeof(D2DamageReportPacket);
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
