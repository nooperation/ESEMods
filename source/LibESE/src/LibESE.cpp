#include <iostream>
#include "LibESE.h"
#include "../D2MooHeaders.h"
#include <D2Game/MISSILES/MissMode_ESE.h>
#include <codecvt>
#include <DataTbls/StringIds.h>

std::wstring FormatWideString(const wchar_t* fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	size_t required = std::vswprintf(NULL, 0, fmt, ap);
	va_end(ap);

	va_start(ap, fmt);
	std::wstring buffer(required, L'\0');
	std::vswprintf(&buffer[0], buffer.size() + 1, fmt, ap);
	va_end(ap);

	return buffer;
}

void AppendFormattedWideString(std::wstring& outBuff, const wchar_t* fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	size_t required = std::vswprintf(NULL, 0, fmt, ap);
	va_end(ap);

	va_start(ap, fmt);
	std::wstring buffer(required, L'\0');
	std::vswprintf(&buffer[0], buffer.size() + 1, fmt, ap);
	va_end(ap);

	outBuff.append(buffer);
}

std::wstring ToWideString(const char* source)
{
	std::string str(source);
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	return converter.from_bytes(str);
}

void AppendString(std::wstring& dest, const char* source)
{
	std::string str(source);
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	dest.append(converter.from_bytes(str));
}

void ColorizeString(std::wstring& str, int32_t color)
{
	auto colorCodeToken = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
	std::wstring colorStr(colorCodeToken);
	colorStr.append(std::to_wstring(color));

	str.insert(0, colorStr);
}

void AppendColorizedString(std::wstring& dest, const std::wstring& src, int32_t color)
{
	auto colorCodeToken = (const wchar_t*)D2LANG_GetStringFromTblIndex(STR_IDX_3994_colorcode);
	dest.append(colorCodeToken);
	dest.append(std::to_wstring(color));
	dest.append(src);
}

ESE_D2DamageStrc::ESE_D2DamageStrc()
{
	dwHitFlags = 0;
	wResultFlags = 0;
	wExtra = 0;
	dwPhysDamage = 0;
	dwEnDmgPct = 0;
	dwFireDamage = 0;
	dwBurnDamage = 0;
	dwBurnLen = 0;
	dwLtngDamage = 0;
	dwMagDamage = 0;
	dwColdDamage = 0;
	dwPoisDamage = 0;
	dwPoisLen = 0;
	dwColdLen = 0;
	dwFrzLen = 0;
	dwLifeLeech = 0;
	dwManaLeech = 0;
	dwStamLeech = 0;
	dwStunLen = 0;
	dwAbsLife = 0;
	dwDmgTotal = 0;
	unk0x50 = 0;
	dwPiercePct = 0;
	dwDamageRate = 0;
	unk0x5C = 0;
	dwHitClass = 0;
	nHitClassActiveSet = 0;
	nConvType = 0;
	unk0x66[0] = 0;
	unk0x66[1] = 0;
	dwConvPct = 0;
	nOverlay = 0;
}

ESE_D2DamageStrc::ESE_D2DamageStrc(const D2DamageStrc* src)
{
	dwHitFlags = src->dwHitFlags;
	wResultFlags = src->wResultFlags;
	wExtra = src->wExtra;
	dwPhysDamage = src->dwPhysDamage;
	dwEnDmgPct = src->dwEnDmgPct;
	dwFireDamage = src->dwFireDamage;
	dwBurnDamage = src->dwBurnDamage;
	dwBurnLen = src->dwBurnLen;
	dwLtngDamage = src->dwLtngDamage;
	dwMagDamage = src->dwMagDamage;
	dwColdDamage = src->dwColdDamage;
	dwPoisDamage = src->dwPoisDamage;
	dwPoisLen = src->dwPoisLen;
	dwColdLen = src->dwColdLen;
	dwFrzLen = src->dwFrzLen;
	dwLifeLeech = src->dwLifeLeech;
	dwManaLeech = src->dwManaLeech;
	dwStamLeech = src->dwStamLeech;
	dwStunLen = src->dwStunLen;
	dwAbsLife = src->dwAbsLife;
	dwDmgTotal = src->dwDmgTotal;
	unk0x50 = src->unk0x50;
	dwPiercePct = src->dwPiercePct;
	dwDamageRate = src->dwDamageRate;
	unk0x5C = src->unk0x5C;
	dwHitClass = src->dwHitClass;
	nHitClassActiveSet = src->nHitClassActiveSet;
	nConvType = src->nConvType;
	unk0x66[0] = src->unk0x66[0];
	unk0x66[1] = src->unk0x66[1];
	dwConvPct = src->dwConvPct;
	nOverlay = src->nOverlay;
}

void ESE_D2DamageStrc::WriteToOriginalStruct(D2DamageStrc* dest)
{
	dest->dwHitFlags = dwHitFlags;
	dest->wResultFlags = wResultFlags;
	dest->wExtra = wExtra;
	dest->dwPhysDamage = dwPhysDamage;
	dest->dwEnDmgPct = dwEnDmgPct;
	dest->dwFireDamage = dwFireDamage;
	dest->dwBurnDamage = dwBurnDamage;
	dest->dwBurnLen = dwBurnLen;
	dest->dwLtngDamage = dwLtngDamage;
	dest->dwMagDamage = dwMagDamage;
	dest->dwColdDamage = dwColdDamage;
	dest->dwPoisDamage = dwPoisDamage;
	dest->dwPoisLen = dwPoisLen;
	dest->dwColdLen = dwColdLen;
	dest->dwFrzLen = dwFrzLen;
	dest->dwLifeLeech = dwLifeLeech;
	dest->dwManaLeech = dwManaLeech;
	dest->dwStamLeech = dwStamLeech;
	dest->dwStunLen = dwStunLen;
	dest->dwAbsLife = dwAbsLife;
	dest->dwDmgTotal = dwDmgTotal;
	dest->unk0x50 = unk0x50;
	dest->dwPiercePct = dwPiercePct;
	dest->dwDamageRate = dwDamageRate;
	dest->unk0x5C = unk0x5C;
	dest->dwHitClass = dwHitClass;
	dest->nHitClassActiveSet = nHitClassActiveSet;
	dest->nConvType = nConvType;
	dest->unk0x66[0] = unk0x66[0];
	dest->unk0x66[1] = unk0x66[1];
	dest->dwConvPct = dwConvPct;
	dest->nOverlay = nOverlay;
}


int64_t __fastcall ESE_ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int64_t nMax)
{
	if (nMax > 0)
	{
		if ((nMax - 1) & nMax)
		{
			return SEED_RollRandomNumber(pSeed) % nMax;
		}
		else
		{
			return SEED_RollRandomNumber(pSeed) & (nMax - 1);
		}
	}

	return 0;
}

int64_t __fastcall ESE_DATATBLS_ApplyRatio(int64_t nValue, int64_t nMultiplier, int64_t nDivisor)
{
	if (nDivisor == 0)
	{
		return 0;
	}
	
	if (nValue <= 0xB504F333LL)
	{
		if (nMultiplier <= 0xB504F333LL)
		{
			return nMultiplier * nValue / nDivisor;
		}

		if (nDivisor <= (nMultiplier >> 4))
		{
			return nValue * (nMultiplier / nDivisor);
		}
	}
	else
	{
		if (nDivisor <= (nValue >> 4))
		{
			return nMultiplier * (nValue / nDivisor);
		}
	}

	return nMultiplier * nValue / nDivisor;
}
