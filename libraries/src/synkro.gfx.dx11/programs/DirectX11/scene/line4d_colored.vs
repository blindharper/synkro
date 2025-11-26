//------------------------------------------------------------------------------
// File: line4d_colored.vs
//
// Purpose: Vertex shader for colored line primitive in 4D
//------------------------------------------------------------------------------
#include "viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float4 pos	: POSITION;		// Vertex position
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

	float4 localPos = mul( vertex.pos, p_transform );
	localPos *= 1.0/(1.0-localPos.w);
	fragment.pos = mul( float4(localPos.x, localPos.y, localPos.z, 1.0f), sp_worldViewProj );
	fragment.col = vertex.col;

	return fragment;
}
