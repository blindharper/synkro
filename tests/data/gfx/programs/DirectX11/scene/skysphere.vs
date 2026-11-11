//------------------------------------------------------------------------------
// File: skysphere.vs
//
// Purpose: Vertex shader for skysphere
//------------------------------------------------------------------------------
#include "viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float2 tex	: TEXCOORD0;		// Texture coordinates
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	fragment.pos = mul( float4(vertex.pos, 1.0f), sp_worldViewProj );
	fragment.tex = vertex.tex;

	return fragment;
}
