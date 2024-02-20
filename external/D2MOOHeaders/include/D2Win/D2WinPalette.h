#pragma once

#include <cstdint>

#include <Windows.h>


#pragma pack(push, 1)
struct D2ShadowLightGammaPaletteStrc
{
	union
	{
		struct
		{
			PALETTEENTRY shadowsPalette[32][64];
			PALETTEENTRY lightPalette[16][64];
			PALETTEENTRY gammaPalette[64];
		};

		PALETTEENTRY palettes[49][64];
	};
};
#pragma pack(pop)
