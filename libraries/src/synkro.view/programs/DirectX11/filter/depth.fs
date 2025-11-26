//------------------------------------------------------------------------------
// File: depth.fs
//
// Purpose: "Depth" post-processing filter
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------
struct Fragment
{
	float4 pos	: SV_POSITION;		// Vertex position in fragment space
	float2 tex	: TEXCOORD0;		// Vertex texture coordinates
};

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb0 : register( b0 )
{
	float     	p_front;		// Near clipping plane
	float     	p_back;			// Far clipping plane
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
Texture2D 	texDepth;			// "Depth" texture

//------------------------------------------------------------------------------
// Samplers
//------------------------------------------------------------------------------
SamplerState	samDepth;			// Sampler state

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float depth = texDepth.Sample( samDepth, fragment.tex ).r;
	
	// Linearize depth.
	float d = 2.0f*depth - 1.0f;
	d = 2.0f*p_front/( p_back + p_front - d*(p_back - p_front) );
	
	return float4( d, d, d, 1.0f );
}
