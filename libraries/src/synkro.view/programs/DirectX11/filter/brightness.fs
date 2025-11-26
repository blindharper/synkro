//------------------------------------------------------------------------------
// File: brightness.fs
//
// Purpose: "Brightness" post-processing filter
//------------------------------------------------------------------------------
#include "simple.fsh"

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 c = texImage.Sample( samImage, fragment.tex );
	return float4( c.r+p_value, c.g+p_value, c.b+p_value, 1.0f );
}
