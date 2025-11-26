//------------------------------------------------------------------------------
// File: green.fs
//
// Purpose: "Green channel" post-processing filter
//------------------------------------------------------------------------------
#include "filter.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 c = texImage.Sample( samImage, fragment.tex );
	return float4( c.g, c.g, c.g, 1.0f );
}
