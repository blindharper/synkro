//------------------------------------------------------------------------------
// File: monochrome.vs
//
// Purpose: Vertex shader for monochrome overlay
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
struct Vertex
{
	float4 pos	: POSITION;
};

struct Fragment
{
	float4 pos	: SV_POSITION;
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

	return fragment;
}
