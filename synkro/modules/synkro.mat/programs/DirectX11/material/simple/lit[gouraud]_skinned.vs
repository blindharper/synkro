//------------------------------------------------------------------------------
// File: lit[gouraud]_textured_skinned.vs
//
// Purpose: Vertex shader for lit skinned simple material
//------------------------------------------------------------------------------
#include "../lighting/gouraud.vsh"

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
	float3 norm	: NORMAL;		// Normal to vertex
	float4 weights	: WEIGHTS;		// Bone weights
	uint4 bones	: BONES;		// Bone indices
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float4 diffuse	: COLOR0;		// Diffuse color
	float4 specular	: COLOR1;		// Specular color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb2 : register( b2 )
{
	float4	sp_diffuse;			// Material's diffuse color
	float4	sp_ambient;			// Material's ambient color
	float4	sp_specular;			// Material's specular color
	float4	sp_emissive;			// Material's emissive color
	float	sp_power;			// Material's specular highlights power
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
	float4 norm = float4( vertex.norm, 1.0f );
	float4 normal = float4( 0.0f, 0.0f, 0.0f, 0.0f );

	// Transform vertex with bones.
	fragment.pos += vertex.weights.x * mul( pos, p_bones[vertex.bones.x] );
	fragment.pos += vertex.weights.y * mul( pos, p_bones[vertex.bones.y] );
	fragment.pos += vertex.weights.z * mul( pos, p_bones[vertex.bones.z] );
	fragment.pos += vertex.weights.w * mul( pos, p_bones[vertex.bones.w] );

	// Transform normal with bones.
	normal += vertex.weights.x * mul( norm, p_bones[vertex.bones.x] );
	normal += vertex.weights.y * mul( norm, p_bones[vertex.bones.y] );
	normal += vertex.weights.z * mul( norm, p_bones[vertex.bones.z] );
	normal += vertex.weights.w * mul( norm, p_bones[vertex.bones.w] );

	// Calculate lighting.
	float4 worldPos = fragment.pos;
	float4 cameraPos = mul( fragment.pos, sp_view );
	float4 worldNormal = normalize( normal );
	Material mat = { sp_diffuse, sp_ambient, sp_specular, sp_emissive, sp_power };
	Lighting lights = CalcLighting( mat, worldNormal, worldPos, cameraPos );
	fragment.diffuse = lights.diffuse;
	fragment.specular = lights.specular;

	// Pass through position and texture coordinates.
	fragment.pos = mul( fragment.pos, sp_worldViewProj );
	fragment.dist = cameraPos.z;

	return fragment;
}
