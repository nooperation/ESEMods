#include "../D2ClientExports.h"

D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0 = nullptr;
D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0 = nullptr;
D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0 = nullptr;

int32_t* D2Client_pDWORD_6FBBA748 = nullptr; // 11A748
int32_t* D2Client_pDWORD_6FBBA74C = nullptr; // 11A74C
int32_t* D2Client_pDWORD_6FB740F0 = nullptr; // D40F0
int32_t* D2Client_pDWORD_6FB8CCF8 = nullptr; // ECCF8

void InitD2ClientExports()
{
    auto d2ClientModule = GetModuleHandle("D2Client");

    D2Client_DrawTextCentered_6FACFCD0 = (D2Client_DrawTextCentered_6FACFCD0_t)((char *)d2ClientModule + 0x2FCD0);
    D2Client_sub_6FB0B2C0 = (D2Client_sub_6FB0B2C0_t)((char *)d2ClientModule + 0x6B2C0);
    D2Client_sub_6FB0B6F0 = (D2Client_sub_6FB0B6F0_t)((char *)d2ClientModule + 0x6B6F0);

    D2Client_pDWORD_6FBBA748 = (int32_t*)((char *)d2ClientModule + 0x11A748);
    D2Client_pDWORD_6FBBA74C = (int32_t*)((char *)d2ClientModule + 0x11A74C);
    D2Client_pDWORD_6FB740F0 = (int32_t*)((char *)d2ClientModule + 0xD40F0);
    D2Client_pDWORD_6FB8CCF8 = (int32_t*)((char *)d2ClientModule + 0xECCF8);
}
