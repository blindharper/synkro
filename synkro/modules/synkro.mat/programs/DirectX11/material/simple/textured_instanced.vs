//------------------------------------------------------------------------------
// File: textured_instanced.vs
//
// Purpose: Vertex shader for textured instanced simple material
//------------------------------------------------------------------------------
#include "../viewport.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
	float4x4 trans	: TRANSFORM0;		// Instance transformation matrix (TRANSFORM0-TRANSFORM3)
	float4 col	: COLOR0;		// Instance color
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float2 tex	: TEXCOORD0;		// Texture coordinates
	float4 col	: COLOR0;		// Fragment color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	float4 localPos = mul( float4(vertex.pos, 1.0f), vertex.trans );
	float4 worldPos = localPos;
	float4 cameraPos = mul( worldPos, sp_view );

	fragment.pos = mul( localPos, sp_worldViewProj );
	fragment.tex = vertex.tex;
	fragment.col = vertex.col;
	fragment.dist = cameraPos.z;

	return fragment;
}
