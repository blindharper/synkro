//------------------------------------------------------------------------------
// File: textured.fs
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
	float2 tex	: TEXCOORD0;		// Texture coordinates
	float4 col	: COLOR0;		// Diffuse color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb1
{
	float	sp_amountDiffuse;		// Diffuse map strength [0.0-1.0]
	float	sp_tilingHorizontal;		// Horizontal map tiling
	float	sp_tilingVertical;		// Vertical map tiling
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
Texture2D 	texDiffuse;			// Diffuse map texture
                                        
//------------------------------------------------------------------------------
// Samplers
//------------------------------------------------------------------------------
SamplerState	samDiffuse;			// Sampler state

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float2 tex;
	tex.x = sp_tilingHorizontal * fragment.tex.x;
	tex.y = sp_tilingVertical * fragment.tex.y;
	float4 diffuse = (sp_amountDiffuse > 0.0f) ? sp_amountDiffuse*texDiffuse.Sample(samDiffuse, tex) * fragment.col : fragment.col;
	float fog = CalcFogFactor( fragment.dist );
	float4 color = lerp( sp_fog.color, diffuse, fog );
	return color;
}
