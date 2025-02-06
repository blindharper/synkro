//------------------------------------------------------------------------------
// File: red.fs
//
// Purpose: "Red channel" post-processing filter
//------------------------------------------------------------------------------
#include "filter.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 c = texImage.Sample( samImage, fragment.tex );
	return float4( c.r, c.r, c.r, 1.0f );
}
