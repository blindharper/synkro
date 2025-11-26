//------------------------------------------------------------------------------
// File: scene.fs
//
// Purpose: Scene fragment shader	
//------------------------------------------------------------------------------
#include "scene.fsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;
	float3 tex	: TEXCOORD0;
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 color = float4( fragment.tex.r, fragment.tex.g, fragment.tex.b, fragment.pos.x );
	float fog = CalcFogFactor( sp_fog.type );
	return lerp( sp_fog.color, color, fog );
}
