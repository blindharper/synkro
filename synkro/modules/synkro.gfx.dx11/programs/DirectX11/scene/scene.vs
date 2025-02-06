//------------------------------------------------------------------------------
// File: scene.vs
//
// Purpose: Scene vertex shader
//------------------------------------------------------------------------------
#include "scene.vsh"

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

	fragment.pos = mul( vertex.pos, sp_world );
	fragment.tex = float3( 0.0f, 0.0f, 0.0f );

	return fragment;
}
