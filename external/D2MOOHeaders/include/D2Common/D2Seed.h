#pragma once

#include <D2BasicTypes.h>
#include <D2Common.h>

#pragma pack(1)

struct D2SeedStrc
{
	union
	{
		struct
		{
			uint32_t nLowSeed;					//0x00
			uint32_t nHighSeed;					//0x04
		};
		uint64_t lSeed;		//0x00
	};
};
#pragma pack()

inline uint64_t __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
	uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;

	pSeed->lSeed = lSeed;

	return lSeed;
}

//D2Common.0x6FD7D3E0
inline uint32_t __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
	if (nMax > 0)
	{
		if ((nMax - 1) & nMax)
		{
			return (unsigned int)SEED_RollRandomNumber(pSeed) % nMax;
		}
		else
		{
			return SEED_RollRandomNumber(pSeed) & (nMax - 1);
		}
	}

	return 0;
}

inline uint32_t SEED_RollPercentage(D2SeedStrc* pSeed)
{
	return (SEED_RollRandomNumber(pSeed) % 100);
}
