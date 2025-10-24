#pragma once

#include <D2Client/Render_UI_ESE.h>
#include <../D2MooHeaders.h>
#include <cstdlib>

typedef void (__fastcall* D2Client_RenderUI_6FB21B70_t)(D2ViewStruct* pRenderer);

extern D2Client_RenderUI_6FB21B70_t D2Client_RenderUI_6FB21B70_Original;

void __fastcall ESE_INTERCEPT_D2Client_RenderUI_6FB21B70(D2ViewStruct* pRenderer);
