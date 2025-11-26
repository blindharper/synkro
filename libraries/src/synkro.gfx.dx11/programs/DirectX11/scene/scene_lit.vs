//------------------------------------------------------------------------------
// File: scene_lit.vs
//
// Purpose: Scene vertex shader
//------------------------------------------------------------------------------
#include "scene_lit.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;
};

struct Fragment
{
	float4 pos	: SV_POSITION;
	float3 tex	: TEXCOORD0;
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;
	
	float4 loc = float4( vertex.pos, lights[0].phi );
	float4 loc2 = sp_lightAmbient;
	float4 loc3 = float4( vertex.pos, sp_lightCount );
	float4 loc4 = lights[0].diffuse;
	fragment.pos = mul(loc, sp_world) + mul(loc2, sp_world) + mul(loc3, sp_world) + mul(loc4, sp_world) + mul(loc, sp_world);
	fragment.tex = float3( 0.0f, 0.0f, 0.0f );

	return fragment;
}
