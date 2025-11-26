//------------------------------------------------------------------------------
// File: lit[gouraud]_instanced.vs
//
// Purpose: Vertex shader for lit instanced simple material
//------------------------------------------------------------------------------
#include "../lighting/gouraud.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float3 norm	: NORMAL;		// Normal to vertex
	float4x4 trans	: TRANSFORM0;		// Instance transformation matrix (TRANSFORM0-TRANSFORM3)
	float4 col	: COLOR0;		// Instance color
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
cbuffer cb2
{
	float4	sp_diffuse;			// Material's diffuse color
	float4	sp_ambient;			// Material's ambient color
	float4	sp_specular;			// Material's specular color
	float4	sp_emissive;			// Material's emissive color
	float	sp_power;			// Material's specular highlights power
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	// Transform the position from object space to homogeneous projection space.
	float4 localPos = mul( float4(vertex.pos, 1.0f), vertex.trans );
	float4 worldPos = localPos;
	float4 cameraPos = mul( worldPos, sp_view );
	fragment.pos = mul( localPos, sp_worldViewProj );
	fragment.dist = cameraPos.z;

	// Calculate lighting.
	Material mat = { sp_diffuse, sp_ambient, sp_specular, sp_emissive, sp_power };
	float4 worldNormal = float4( normalize(mul(vertex.norm, (float3x3)vertex.trans)), 1.0f );
	Lighting lights = CalcLighting( mat, worldNormal, worldPos, cameraPos );
	fragment.diffuse = lights.diffuse*vertex.col;
	fragment.specular = lights.specular;

	return fragment;
}
