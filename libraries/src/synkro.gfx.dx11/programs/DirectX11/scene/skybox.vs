//------------------------------------------------------------------------------
// File: skybox.vs
//
// Purpose: Vertex shader for skybox
//------------------------------------------------------------------------------
#include "viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float4 pos	: POSITION;		// Vertex position
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float3 tex	: TEXCOORD0;		// Texture coordinates
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	fragment.pos = vertex.pos;
	fragment.tex = normalize( mul(vertex.pos, sp_invWorldViewProj) );

	return fragment;
}
