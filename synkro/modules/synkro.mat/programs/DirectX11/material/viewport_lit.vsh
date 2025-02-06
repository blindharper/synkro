//------------------------------------------------------------------------------
// File: viewport_lit.vsh
//
// Purpose: Shared viewport stuff
//------------------------------------------------------------------------------
#ifndef _VIEWPORT_LIT_VSH_
#define _VIEWPORT_LIT_VSH_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "scene_lit.vsh"

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb1 : register( b1 )
{
	float4x4 	sp_view			: packoffset(c0);	// View matrix
	float4x4 	sp_proj			: packoffset(c4);	// Projection matrix
	float4x4 	sp_worldView		: packoffset(c8);	// World * View matrix
	float4x4 	sp_worldViewProj	: packoffset(c12);	// World * View * Projection matrix
	float4x4 	sp_invWorldViewProj	: packoffset(c16);	// Inverse World * View * Projection matrix
};

#endif // _VIEWPORT_LIT_VSH_
