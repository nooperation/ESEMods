#pragma once

#include <D2Dll.h>
#include <D2BasicTypes.h>
#include <StormHandles.h>
#include <stdlib.h>

//1.10f Image base: 0x6FF50000

#pragma pack(1)

struct D2TxtLinkNodeStrc
{
	char szText[32];				//0x00
	int nLinkIndex;					//0x20
	D2TxtLinkNodeStrc* pPrevious;	//0x24
	D2TxtLinkNodeStrc* pNext;		//0x28
};

struct D2TxtLinkTblStrc
{
	union
	{
		char szCode[4];				//0x00
		uint32_t dwCode;			//0x00
	};
	int nLinkIndex;					//0x04
};

struct D2TxtLinkStrc
{
	int32_t nRecords;				//0x00
	int32_t nAllocatedCells;		//0x04
	D2TxtLinkTblStrc* pTbl;			//0x08
	D2TxtLinkNodeStrc* pFirstNode;	//0x0C
};


struct D2BinFileStrc
{
	uint8_t* pDataBuffer;			//0x00
	uint8_t* pData;					//0x04
	int32_t nRecordCount;			//0x08
	int32_t nCellCount;				//0x0C
};

enum D2C_TxtFieldTypes : uint32_t
{
	TXTFIELD_NONE,
	TXTFIELD_ASCII,
	TXTFIELD_DWORD,
	TXTFIELD_WORD,
	TXTFIELD_BYTE,
	TXTFIELD_UNKNOWN1,
	TXTFIELD_UNKNOWN2,
	TXTFIELD_BYTE2,
	TXTFIELD_DWORD2,
	TXTFIELD_RAW,
	TXTFIELD_ASCIITOCODE,
	TXTFIELD_UNKNOWN3,
	TXTFIELD_UNKNOWN4,
	TXTFIELD_CODETOBYTE,
	TXTFIELD_UNKNOWN5,
	TXTFIELD_CODETOWORD,
	TXTFIELD_UNKNOWN6,
	TXTFIELD_NAMETOINDEX,
	TXTFIELD_NAMETOINDEX2,
	TXTFIELD_NAMETODWORD,
	TXTFIELD_NAMETOWORD,
	TXTFIELD_NAMETOWORD2,
	TXTFIELD_KEYTOWORD,
	TXTFIELD_CUSTOMLINK,
	TXTFIELD_UNKNOWN7,
	TXTFIELD_CALCTODWORD,
	TXTFIELD_BIT
};

struct D2BinFieldStrc
{
	const char* szFieldName;		//0x00
	D2C_TxtFieldTypes nFieldType;	//0x04
	int32_t nFieldLength;			//0x08
	int32_t nFieldOffset;			//0x0C
	void* pLinkField;				//0x10
};

struct D2UnkExcelStrc
{
	D2UnkExcelStrc* pNext;			//0x00
	uint32_t dwHash;				//0x04
	D2BinFieldStrc* pBinField;		//0x08
};


enum D2C_AsyncDataPriority
{
	ASYNC_DATA_PRIORITY_NORMAL = 0,
	ASYNC_DATA_PRIORITY_HIGH = 1,
};

enum D2C_AsyncDataFlags : uint32_t
{
	ASYNC_DATA_FLAGS_LOADED                    = 0x1,
	ASYNC_DATA_FLAGS_OWNS_BUFFER               = 0x2,
	ASYNC_DATA_FLAGS_POSTPONED_PRIORITY_CHANGE = 0x8,

	ASYNC_DATA_FLAGS_DEBUG_TAG      = 0x41737960,
	ASYNC_DATA_FLAGS_DEBUG_TAG_MASK = 0xFFFFFFF0,
};

struct AsyncDataLoadFileCallback																			   // sizeof(0x1C)
{
	DWORD(__stdcall* callback)(void* pFileData, size_t nDataLength, AsyncDataLoadFileCallback* pCallbackData); // 0x00
	DWORD userData[4];																						   // 0x04
	void* pData;																							   // 0x14
	size_t nFileSize;																						   // 0x18
};

struct AsyncData							 // sizeof(0x54)
{
	HSFILE hFile;							 // 0x00
	void* pMemPool;							 // 0x04
	OVERLAPPED tOverlapped;					 // 0x08
	AsyncDataLoadFileCallback pAsyncOpDesc;	 // 0x1C
	struct AsyncDataEventSlot* pEventSlot;	 // 0x38
	void* pBuffer;							 // 0x3C
	uint32_t nFileSize;						 // 0x40
	uint32_t nPriority;						 // 0x44 D2C_AsyncDataPriority
	uint32_t nFlags;						 // 0x48
	uint32_t nPreviousPriority;				 // 0x4C
	AsyncData* pNextPostponedPriorityChange; // 0x50
};

struct AsyncDataEventSlot  // sizeof(0x0C)
{
	HANDLE hEvent;		   // 0x00
	DWORD bSlotAvailable;  // 0x04
	AsyncData* pAsyncOp;   // 0x08
};


struct QServer;

#pragma pack()

#define D2_ALLOC(size) FOG_Alloc((size), __FILE__, __LINE__, 0)
#define D2_CALLOC(size) memset(FOG_Alloc(size, __FILE__, __LINE__, 0), 0x00, size)
#define D2_ALLOC_STRC(type) (type*)FOG_Alloc(sizeof(type), __FILE__, __LINE__, 0)
#define D2_CALLOC_STRC(type) (type*)memset(FOG_Alloc(sizeof(type), __FILE__, __LINE__, 0), 0x00, sizeof(type))
#define D2_FREE(ptr) FOG_Free(ptr, __FILE__, __LINE__, 0)


#define D2_ALLOC_POOL(pMemPool, size) FOG_AllocPool(pMemPool, size, __FILE__, __LINE__, 0)
#define D2_CALLOC_POOL(pMemPool, size) memset(FOG_AllocPool(pMemPool, size, __FILE__, __LINE__, 0),0x00,size)
#define D2_REALLOC_POOL(pMemPool, pMem, size) FOG_ReallocPool(pMemPool, pMem, size, __FILE__, __LINE__, 0)
#define D2_ALLOC_STRC_POOL(pMemPool, type) (type*)FOG_AllocPool(pMemPool, sizeof(type), __FILE__, __LINE__, 0)
#define D2_CALLOC_STRC_POOL(pMemPool, type) (type*)memset(FOG_AllocPool(pMemPool, sizeof(type), __FILE__, __LINE__, 0), 0x00, sizeof(type))
#define D2_FREE_POOL(pMemPool, ptr) FOG_FreePool(pMemPool, ptr, __FILE__, __LINE__, 0)

#ifndef NDEBUG
// Assert that an expression must be true, otherwise assume the program state will not be recoverable.
// In debug builds, this will trigger a log and exit, in release this is used as a hint for performance optimization.
// Do NOT use this if the program can recover when expr if false, as it is used as a hint for performance and can impact generated code.
// For recoverable errors, use D2_VERIFY
#define D2_DISPLAY_ASSERT_THEN_BREAK(msg) (FOG_DisplayAssert(msg, __FILE__, __LINE__), __debugbreak())
#define D2_ASSERT(expr) (void)( (!!(expr)) || (D2_DISPLAY_ASSERT_THEN_BREAK(#expr), exit(-1) , 0)); _Analysis_assume_(expr)
#define D2_ASSERTM(expr,msg) (void)( (!!(expr)) || (D2_DISPLAY_ASSERT_THEN_BREAK(msg), exit(-1) , 0)); _Analysis_assume_(expr)
#define D2_CHECK(expr) (void)( (!!(expr)) || (FOG_DisplayWarning(#expr, __FILE__, __LINE__), 0)); _Analysis_assume_(expr)


// Assert that an expression must be true, even though the program may be recoverable.
// Contrary to D2_ASSERT, this is still evaluated in release builds, and can be used anywhere the expression would be valid.
// This is to be used when one can recover from an error
// Example:
// if(D2_VERIFY(ptr != nullptr)) ptr->method(); // The only difference between debug and release build is the logging and breakpoint
#define D2_VERIFY(expr) ((!!(expr)) || (D2_DISPLAY_ASSERT_THEN_BREAK(#expr), false))
#define D2_VERIFYM(expr,msg) ((!!(expr)) || (D2_DISPLAY_ASSERT_THEN_BREAK(msg), false))
#else
#if defined(__clang__)
// the argument to '__builtin_assume' has side effects that will be discarded
#pragma clang diagnostic ignored "-Wassume"
#endif // defined(__clang__)
#define D2_ASSERT(expr) (__assume(expr), (void)0)
#define D2_ASSERTM(expr,msg) (__assume(expr), (void)0)
#define D2_VERIFY(expr) (!!(expr))
#define D2_VERIFYM(expr,msg) (!!(expr))
#define D2_CHECK(expr) (__assume(expr), (void)0)
#endif
#define D2_UNREACHABLE D2_ASSERT(false)


#define D2_LOCK(pCriticalSection) D2_ASSERT(pCriticalSection); FOG_10050_EnterCriticalSection(pCriticalSection, __LINE__);
#define D2_UNLOCK(pCriticalSection) D2_ASSERT(pCriticalSection); LeaveCriticalSection(pCriticalSection);
