//------------------------------------------------------------------------------
// File: filter.fsh
//
// Purpose: Common stuff for post-processing filters
//------------------------------------------------------------------------------
#ifndef _FILTER_FSH_
#define _FILTER_FSH_

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
struct Fragment
{
	float4 pos	: SV_POSITION;		// Vertex position in fragment space
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
Texture2D 	texImage;			// Input texture

//------------------------------------------------------------------------------
// Samplers
//------------------------------------------------------------------------------
SamplerState	samImage;			// Sampler state

#endif // _FILTER_FSH_
