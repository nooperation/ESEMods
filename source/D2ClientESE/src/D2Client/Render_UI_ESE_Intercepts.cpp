#include "D2Client/Render_UI_ESE_Intercepts.h"
#include "LibESE.h"
#include "../D2ClientExports.h"

// void __fastcall D2Client_RenderUI_6FB21B70(D2ViewStruct *pRenderer)
extern D2Client_RenderUI_6FB21B70_t D2Client_RenderUI_6FB21B70_Original = nullptr;

//D2Client.0x6FB21B70 ()
void __fastcall ESE_INTERCEPT_D2Client_RenderUI_6FB21B70(D2ViewStruct* pRenderer)
{
    //auto result = ESE_D2Client_RenderUI_6FB21B70(pRenderer);
    D2Client_RenderUI_6FB21B70_Original(pRenderer);
}
