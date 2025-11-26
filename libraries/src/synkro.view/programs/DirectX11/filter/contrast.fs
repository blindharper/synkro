//------------------------------------------------------------------------------
// File: contrast.fs
//
// Purpose: "Contrast" post-processing filter
//------------------------------------------------------------------------------
#include "simple.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 c = texImage.Sample( samImage, fragment.tex );

	c.r *= p_value;
	c.g *= p_value;
	c.b *= p_value;

	return float4( saturate(c.r), saturate(c.g), saturate(c.b), 1.0f );
}
