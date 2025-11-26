//------------------------------------------------------------------------------
// File: blur.fs
//
// Purpose: "Blur" post-processing filter
//------------------------------------------------------------------------------
#include "kernel3x3.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 sample[9];

	for ( int i = 0; i < 9; ++i )
	{
		sample[i] = texImage.Sample( samImage, fragment.tex+p_offset[i] );
	}

	//   1 2 1
	//   2 1 2   / 13
	//   1 2 1

	return (sample[0]      + sample[1]*2.0f + sample[2]      + 
                sample[3]*2.0f + sample[4]      + sample[5]*2.0f + 
                sample[6]      + sample[7]*2.0f + sample[8])     / 13.0f;
}
