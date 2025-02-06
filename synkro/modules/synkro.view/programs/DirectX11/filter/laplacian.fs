//------------------------------------------------------------------------------
// File: laplacian.fs
//
// Purpose: Laplacian edge detection filter
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

	//   -1 -1 -1
	//   -1  8 -1
	//   -1 -1 -1

	return (sample[4] * 8.0) - 
               (sample[0] + sample[1] + sample[2] + 
                sample[3] + sample[5] + 
                sample[6] + sample[7] + sample[8]);
}
