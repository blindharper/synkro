//------------------------------------------------------------------------------
// File: dilation.fs
//
// Purpose: "Dilation" post-processing filter
//------------------------------------------------------------------------------
#include "kernel3x3.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 sample = 0.0f;
	float4 value = 0.0f;

	for ( int i = 0; i < 9; ++i )
	{
		sample = texImage.Sample( samImage, fragment.tex+p_offset[i] );
		value = max( sample, value );
	}

	return value;
}
