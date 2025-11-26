//------------------------------------------------------------------------------
// File: scene_lit.vsh
//
// Purpose: Lighting stuff
//------------------------------------------------------------------------------
#ifndef _SCENE_LIT_VSH_
#define _SCENE_LIT_VSH_

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

// Light types
#define LIGHTTYPE_OMNI		1		// Omni light
#define LIGHTTYPE_CONE		2		// Cone light
#define LIGHTTYPE_DIRECT	3		// Directional light

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Material properties
struct Material
{
	float4	 	diffuse;		// Material's diffuse color
	float4	 	ambient;		// Material's ambient color
	float4	 	specular;		// Material's specular color
	float4	 	emissive;		// Material's emissive color
	float	 	power;			// Material's specular highlights power
};

// Light source state
struct LightState
{
	float4	 	diffuse;		// Light source diffuse color
	float4	 	ambient;		// Light source ambient color
	float4	 	specular;		// Light source specular color
	float4	 	pos;			// Light source position
	float4	 	dir;			// Light source direction
	float	 	range;			// Distance beyond which the light has no effect
	float	 	atten_const;		// Constant attenuation factor
	float	 	atten_linear;		// Linear attenuation factor
	float	 	atten_quadratic;	// Quadratic attenuation factor
	float		falloff;		// Decrease in illumination between theta and phi
	float		theta;			// Inner cone angle, in radians
	float		phi;			// Outer cone angle, in radians
	int		type;			// Light source type
};

// Map
struct Map
{
	float		amount;			// Map amount
	float		tileHorz;		// Horizontal tiling
	float		tileVert;		// Vertical tiling
};

// Lighting calculation output
struct Lighting
{
	float4		diffuse;		// Diffuse light color
	float4		specular;		// Specular light color
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb0 : register( b0 )
{
	float4x4	sp_world		: packoffset(c0); // World matrix
	int	 	sp_lightCount		: packoffset(c4); // Number of active light sources
	float4	 	sp_lightAmbient		: packoffset(c5); // Ambient light color
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
StructuredBuffer<LightState>	lights : register( t0 ); // Light sources

#endif // _SCENE_LIT_VSH_
