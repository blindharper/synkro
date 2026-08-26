//------------------------------------------------------------------------------
// File: billboard.vs
//
// Purpose: Vertex shader for billboard
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
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2
{
	float4x4 p_transform;			// Object's transformation matrix
};


//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	float4 localPos = mul( float4(vertex.pos, 1.0f), p_transform );
	fragment.pos = mul( localPos, sp_worldViewProj );
	fragment.tex = vertex.tex;

	return fragment;
}
