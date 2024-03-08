#include "../D2ClientExports.h"

D2Client_DrawTextCentered_6FACFCD0_t D2Client_DrawTextCentered_6FACFCD0 = nullptr;
D2Client_sub_6FB0B2C0_t D2Client_sub_6FB0B2C0 = nullptr;
D2Client_sub_6FB0B6F0_t D2Client_sub_6FB0B6F0 = nullptr;
D2Client_sub_6FB0BB10_t D2Client_sub_6FB0BB10 = nullptr;

D2Client_sub_6FB0A950_t D2Client_sub_6FB0A950 = nullptr;
D2Client_sub_6FB0AA00_t D2Client_sub_6FB0AA00 = nullptr;
D2Client_sub_6FB0B580_t D2Client_sub_6FB0B580 = nullptr;
D2Client_sub_6FAAC080_t D2Client_sub_6FAAC080 = nullptr;

int32_t* D2Client_pDWORD_6FBBA748 = nullptr; // 11A748
int32_t* D2Client_pDWORD_6FBBA74C = nullptr; // 11A74C
int32_t* D2Client_pDWORD_6FB740F0 = nullptr; // D40F0
int32_t* D2Client_pDWORD_6FB8CCF8 = nullptr; // ECCF8

void InitD2ClientExports()
{
    auto d2ClientModule = GetModuleHandle("D2Client");

    D2Client_DrawTextCentered_6FACFCD0 = (D2Client_DrawTextCentered_6FACFCD0_t)((char *)d2ClientModule + 0x2FCD0);
    D2Client_sub_6FB0B2C0 = (D2Client_sub_6FB0B2C0_t)((char*)d2ClientModule + 0x6B2C0);
    D2Client_sub_6FB0B6F0 = (D2Client_sub_6FB0B6F0_t)((char*)d2ClientModule + 0x6B6F0);
    D2Client_sub_6FB0BB10 = (D2Client_sub_6FB0BB10_t)((char*)d2ClientModule + 0x6BB10);

    D2Client_sub_6FB0A950 = (D2Client_sub_6FB0A950_t)((char*)d2ClientModule + 0x6A950);
    D2Client_sub_6FB0AA00 = (D2Client_sub_6FB0AA00_t)((char*)d2ClientModule + 0x6AA00);
    D2Client_sub_6FB0B580 = (D2Client_sub_6FB0B580_t)((char*)d2ClientModule + 0x6B580);
    D2Client_sub_6FAAC080 = (D2Client_sub_6FAAC080_t)((char*)d2ClientModule + 0xC080);

    D2Client_pDWORD_6FBBA748 = (int32_t*)((char *)d2ClientModule + 0x11A748);
    D2Client_pDWORD_6FBBA74C = (int32_t*)((char *)d2ClientModule + 0x11A74C);
    D2Client_pDWORD_6FB740F0 = (int32_t*)((char *)d2ClientModule + 0xD40F0);
    D2Client_pDWORD_6FB8CCF8 = (int32_t*)((char *)d2ClientModule + 0xECCF8);
}
