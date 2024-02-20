#pragma once

#include <Units/Units.h>


#pragma pack(push, 1)

enum D2C_TaskConstants {
    TASKQSLOTS = 0x20
};

enum D2C_TaskTypes
{
    TASK_PROCESSGAME = 0x0,
};

// Note: comes from D2Headers/Linklist.h
struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2TaskStrc
{
	int32_t nTaskQ;								//0x00
	int32_t nType;								//0x04 D2C_TaskTypes, but somehow also used for timeout ?
	D2LinkStrc pTaskBalanceLink;				//0x08 May actually link to &pTaskQueueLink !
	D2LinkStrc pTaskQueueLink;					//0x10
};

struct CRITICAL_SECTION_WRAPPER
{
    CRITICAL_SECTION cs;

    CRITICAL_SECTION_WRAPPER() { InitializeCriticalSection(&cs); }
    ~CRITICAL_SECTION_WRAPPER() { DeleteCriticalSection(&cs); }
};
#pragma pack(pop)
