//------------------------------------------------------------------------------
// File: lit[flat].vs
//
// Purpose: Vertex shader for lit simple material
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
};

// Geometry shader input data
struct Geometry
{
	float4 pos	: SV_POSITION;		// Transformed position
	float4 diffuse	: COLOR0;		// Diffuse color
	float4 specular	: COLOR1;		// Specular color
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
	float4x4 p_transform;			// Object's transformation matrix
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Geometry main( Vertex vertex )
{
	Geometry geometry;

	// Transform the position from object space to homogeneous projection space.
	float4 localPos = mul( float4(vertex.pos, 1.0f), p_transform );
	float4 worldPos = localPos;
	float4 cameraPos = mul( worldPos, sp_view );
	geometry.pos = mul( localPos, sp_worldViewProj );

	// Calculate lighting.
	Material mat = { sp_diffuse, sp_ambient, sp_specular, sp_emissive, sp_power };
	float4 worldNormal = float4( normalize(mul(vertex.norm, (float3x3)p_transform)), 1.0f );
	Lighting lights = CalcLighting( mat, worldNormal, worldPos, cameraPos );
	geometry.diffuse = lights.diffuse;
	geometry.specular = lights.specular;

	return geometry;
}
