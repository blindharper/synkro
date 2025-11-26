//------------------------------------------------------------------------------
// File: lit.fs
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
	float4 diffuse	: COLOR0;		// Diffuse color
	float4 specular	: COLOR1;		// Specular color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{	
	float fog = CalcFogFactor( fragment.dist );
	float4 color = fragment.diffuse + fragment.specular;
	return lerp( sp_fog.color, color, fog );
}
