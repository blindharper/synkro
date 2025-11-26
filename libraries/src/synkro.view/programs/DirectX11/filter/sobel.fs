//------------------------------------------------------------------------------
// File: sharpen.fs
//
// Purpose: Sobel edge detection filter
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

	//    -1 -2 -1       1 0 -1 
	// H = 0  0  0   V = 2 0 -2
	//     1  2  1       1 0 -1
	//
	// result = sqrt(H^2 + V^2)

	float4 horzEdge = sample[6] + sample[7]*2.0f + sample[8] -
                    	 (sample[0] + sample[1]*2.0f + sample[2]);

	float4 vertEdge = sample[0] + sample[3]*2.0f + sample[6] -
                     	 (sample[2] + sample[5]*2.0f + sample[8]);
               
	float4 c = sqrt( horzEdge*horzEdge + vertEdge*vertEdge );
	return float4( c.r, c.g, c.b, 1.0f );
}
