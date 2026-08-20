//------------------------------------------------------------------------------
// File: depth.fs
//
// Purpose: "Depth" post-processing filter
//------------------------------------------------------------------------------
#include "camera.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float depth = texImage.Sample( samImage, fragment.tex ).r;
	
	// Linearize depth.
	float d = 2.0f*depth - 1.0f;
	d = 2.0f*p_front/( p_back + p_front - d*(p_back - p_front) );
	
	return float4( d, d, d, 1.0f );
}
