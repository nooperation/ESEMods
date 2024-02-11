#include "ESEDamageCalc.h"

int64_t MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(int64_t nValue, int64_t nPercentage, int64_t divisor)
{
    if (nValue <= 0x100000)
    {
        if (nPercentage <= 0x10000)
        {
            return (nValue * nPercentage) / divisor;
        }
        if ((nPercentage >> 4) >= divisor)
        {
            return nValue * (nPercentage / divisor);
        }
    }
    else if ((nPercentage >> 4) >= divisor)
    {
        return nPercentage * (nValue / divisor);
    }

    return nValue * (__int64)nPercentage / divisor;
}

int32_t __fastcall MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc(int32_t nValue, int32_t nPercentage, int32_t divisor)
{
    const auto result = MONSTERUNIQUE_CalculatePercentage_ESEDamageCalc_64(nValue, nPercentage, divisor);
    if (result > INT32_MAX)
    {
        return INT32_MAX;
    }

    if (result < INT32_MIN)
    {
        return INT32_MIN;
    }

    return (int32_t)result;
}
