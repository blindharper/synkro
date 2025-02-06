//------------------------------------------------------------------------------
// File: textured_skinned.vs
//
// Purpose: Vertex shader for monochrome textured skinned simple material
//------------------------------------------------------------------------------
#include "../viewport.vsh"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

#define MAX_BONE_COUNT	50			// Maximum number of bone matrices

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float4 weights	: WEIGHTS;		// Bone weights
	uint4 bones	: BONES;		// Bone indices
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float2 tex	: TEXCOORD0;		// Texture coordinates
	float4 col	: COLOR0;		// Diffuse color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2 : register( b2 )
{
	float4	sp_color;			// Material diffuse color
};

cbuffer cb3
{
	float4x4 p_bones[MAX_BONE_COUNT];	// Bones transformations
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment = (Fragment)0.0f;
	float4 pos = float4( vertex.pos, 1.0f );	

	fragment.pos += vertex.weights.x * mul( pos, p_bones[vertex.bones.x] );
	fragment.pos += vertex.weights.y * mul( pos, p_bones[vertex.bones.y] );
	fragment.pos += vertex.weights.z * mul( pos, p_bones[vertex.bones.z] );
	fragment.pos += vertex.weights.w * mul( pos, p_bones[vertex.bones.w] );

	float4 worldPos = fragment.pos;
	float4 cameraPos = mul( worldPos, sp_view );	

	fragment.pos = mul( fragment.pos, sp_worldViewProj );
	fragment.tex = vertex.tex;
	fragment.col = sp_color;
	fragment.dist = cameraPos.z;

	return fragment;
}
