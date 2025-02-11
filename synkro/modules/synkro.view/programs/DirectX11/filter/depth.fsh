//------------------------------------------------------------------------------
// File: depth.fsh
//
// Purpose: Common stuff for depth filters
//------------------------------------------------------------------------------
#ifndef _DEPTH_FSH_
#define _DEPTH_FSH_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "filter.fsh"

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb0 : register( b0 )
{
	float4x4 	p_invViewProj;		// Inverse (View * Projection) matrix
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
Texture2D 	texDepth;			// "Depth" texture

//------------------------------------------------------------------------------
// Samplers
//------------------------------------------------------------------------------
SamplerState	samDepth;			// Sampler state

#endif // _DEPTH_FSH_
