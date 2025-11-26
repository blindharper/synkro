//------------------------------------------------------------------------------
// File: alpha.fs
//
// Purpose: "Alpha channel" post-processing filter
//------------------------------------------------------------------------------
#include "filter.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 c = texImage.Sample( samImage, fragment.tex );
	return float4( c.a, c.a, c.a, 1.0f );
}
