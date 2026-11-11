//------------------------------------------------------------------------------
// File: line_colored.vs
//
// Purpose: Vertex shader for colored line primitive
//------------------------------------------------------------------------------
#include "viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float4 col	: COLOR0;		// Vertex color
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float4 col	: COLOR0;		// Fragment color
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2
{
	float4x4	p_transform;		// Object's transformation matrix
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	float4 localPos = mul( float4(vertex.pos, 1.0f), p_transform );
	fragment.pos = mul( localPos, sp_worldViewProj );
	fragment.col = vertex.col;

	return fragment;
}
