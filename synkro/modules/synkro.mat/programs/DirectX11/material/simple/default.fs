//------------------------------------------------------------------------------
// File: default.fs
//
// Purpose: Fragment shader for simple material
//------------------------------------------------------------------------------
#include "../scene.fsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float4 col	: COLOR0;		// Fragment color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float fog = CalcFogFactor( fragment.dist );
	return lerp( sp_fog.color, fragment.col, fog );
}
