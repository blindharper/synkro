//------------------------------------------------------------------------------
// File: textured.vs
//
// Purpose: Vertex shader for textured overlay
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
struct Vertex
{
	float4 pos	: POSITION;
	float2 tex	: TEXCOORD0;
};

struct Fragment
{
	float4 pos	: SV_POSITION;
	float2 tex	: TEXCOORD0;
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb0 : register( b0 )
{
	float2 		p_offset;		// Vertex offset
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment;

	fragment.pos = float4( vertex.pos.x+p_offset.x, vertex.pos.y+p_offset.y, vertex.pos.z, vertex.pos.w );
	fragment.tex = vertex.tex;

	return fragment;
}
