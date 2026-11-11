//------------------------------------------------------------------------------
// File: scene.fsh
//
// Purpose: Shared scene stuff
//------------------------------------------------------------------------------
#ifndef _SCENE_FSH_
#define _SCENE_FSH_

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

#define E			2.71828		// Base of the natural logarithm

// Fog types
#define FOGTYPE_NONE		0		// No fog
#define FOGTYPE_LINEAR		1		// Linear fog
#define FOGTYPE_EXP		2		// Exponential fog
#define FOGTYPE_EXP2		3		// Exponential fog #2

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Fog effect state
struct FogState
{
	float4   	color;			// Fog color
	float    	start;			// Start fog distance
	float    	end;			// End fog distance
	float    	density;		// Fog density
	int      	type;			// Fog type
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb0 : register( b0 )
{
	FogState	sp_fog	: packoffset(c0);// Fog state
};

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

// Calculates fog factor based upon distance
float CalcFogFactor( float d )
{
	float fog = 1.0f;
    
	if ( sp_fog.type == FOGTYPE_LINEAR )
	{
		fog = (sp_fog.end - d)/(sp_fog.end - sp_fog.start);
	}
	else if ( sp_fog.type == FOGTYPE_EXP )
	{
		fog = 1.0f / pow( E, d*sp_fog.density );
	}
	else if ( sp_fog.type == FOGTYPE_EXP2 )
	{
		fog = 1.0f / pow( E, d*d*sp_fog.density*sp_fog.density );
	}
    
	return saturate( fog );
}

#endif // _SCENE_FSH_
