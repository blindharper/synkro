//------------------------------------------------------------------------------
// File: filter.vs
//
// Purpose: Common vertex shader for post-processing filters
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
struct Vertex
{
	float4 pos	: POSITION;		// Vertex position
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

struct Fragment
{
	float4 pos	: SV_POSITION;		// Vertex position in fragment space
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;
	
	fragment.pos = vertex.pos;
	fragment.tex = vertex.tex;
	
	return fragment;
}
