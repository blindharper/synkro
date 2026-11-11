//------------------------------------------------------------------------------
// File: point.vs
//
// Purpose: Vertex shader for monochrome point primitive
//------------------------------------------------------------------------------
#include "viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
};

// Geometry shader input data
struct Point
{
	float4 pos	: SV_POSITION;		// Point position
	float4 col	: COLOR0;		// Point color
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2
{
	float4	 sp_color;			// Point color
};

cbuffer cb3
{
	float4x4 p_transform;			// Object's transformation matrix
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Point main( Vertex vertex )
{
	Point pt;

	float4 localPos = mul( float4(vertex.pos, 1.0f), p_transform );
	pt.pos = mul( localPos, sp_worldViewProj );
	pt.col = sp_color;

	return pt;
}
