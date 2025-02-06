//------------------------------------------------------------------------------
// File: default.vs
//
// Purpose: Vertex shader for monochrome simple material
//------------------------------------------------------------------------------
#include "../viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float4 col	: COLOR0;		// Fragment color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2
{
	float4	 sp_color;			// Material diffuse color
};

cbuffer cb3
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
	float4 worldPos = localPos;
	float4 cameraPos = mul( worldPos, sp_view );

	fragment.pos = mul( localPos, sp_worldViewProj );
	fragment.col = sp_color;
	fragment.dist = cameraPos.z;

	return fragment;
}
