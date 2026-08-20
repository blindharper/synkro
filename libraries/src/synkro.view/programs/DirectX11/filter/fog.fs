//------------------------------------------------------------------------------
// File: fog.fs
//
// Purpose: "Fog" post-processing filter
//
// Description: Modulates input texture with a fog color based on distance
//------------------------------------------------------------------------------
#include "depth.fsh"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

#define E			2.71828		// Base of the natural logarithm

// Fog types
#define FOGTYPE_LINEAR		1		// Linear fog
#define FOGTYPE_EXP		2		// Exponential fog
#define FOGTYPE_EXP2		3		// Exponential fog #2

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb1 : register( b1 )
{
	float4   	p_color;		// Fog color
	float    	p_start;		// Start fog distance
	float    	p_end;			// End fog distance
	float    	p_density;		// Fog density
	int      	p_type;			// Fog type
};

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

// Calculates fog factor based upon distance
float CalcFogFactor( float d )
{
	float fog = 1.0f;
    
	if ( p_type == FOGTYPE_LINEAR )
	{
		fog = (p_end - d)/(p_end - p_start);
	}
	else if ( p_type == FOGTYPE_EXP )
	{
		fog = 1.0f / pow( E, d*p_density );
	}
	else if ( p_type == FOGTYPE_EXP2 )
	{
		fog = 1.0f / pow( E, d*d*p_density*p_density );
	}
    
	return saturate( fog );
}

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 color = texImage.Sample( samImage, fragment.tex );
	float depth = texDepth.Sample( samDepth, fragment.tex ).r;

	// Convert fragment position to normalized device coordinates.
	float4 screenPos = float4( 2.0f*fragment.tex.x - 1.0f, 1.0f - 2.0f*fragment.tex.y, depth, 1.0f );

	// Transform by inverse view-projection.
	float4 worldPos = mul( screenPos, p_invViewProj );

	// Divide z by w to get the world position.  
	float d = worldPos.z/worldPos.w;
	float fog = CalcFogFactor( d );

	// Blend scene and fog.
	return lerp( p_color, color, fog );
}
