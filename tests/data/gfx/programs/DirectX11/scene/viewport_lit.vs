//------------------------------------------------------------------------------
// File: viewport_lit.vs
//
// Purpose: Viewport vertex shader
//------------------------------------------------------------------------------
#include "viewport_lit.vsh"

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;
};

struct Fragment
{
	float4 pos	: SV_POSITION;
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	float4 loc = mul( vertex.pos, sp_view );
	float4 loc2 = mul( vertex.pos, sp_proj );
	float4 loc3 = mul( vertex.pos, sp_worldView );
	float4 loc4 = mul( vertex.pos, sp_worldViewProj );
	fragment.pos = loc + loc2 + loc3 + loc4;
	
	return fragment;
}
