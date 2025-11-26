//------------------------------------------------------------------------------
// File: emboss.fs
//
// Purpose: "Emboss" post-processing filter
//------------------------------------------------------------------------------
#include "kernel3x3.fsh"

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb1 : register( b1 )
{
	float		p_weights[9];		// Fragment weights
};

cbuffer cb2 : register( b2 )
{
	float     	p_depth;		// Emboss depth [0.0-1.0]
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 res = float4( 0.0f, 0.0f, 0.0f, 0.0f );
	for ( int i = 0; i < 9; ++i )
	{
		res += p_weights[i] * texImage.Sample( samImage, fragment.tex+p_offset[i] );
	}
	res *= p_depth;
	res.rgb += 0.5f;
	return res;
}
