//------------------------------------------------------------------------------
// File: motion_blur.fs
//
// Purpose: "Motion blur" post-processing filter
//
// Description: Computes average of N samples according to fragment velocity
//------------------------------------------------------------------------------
#include "depth.fsh"

//------------------------------------------------------------------------------
// Parameters
//------------------------------------------------------------------------------
cbuffer cb1 : register( b1 )
{
	float4x4 	p_prevViewProj;		// Previous frame's (View * Projection) matrix
};

cbuffer cb2 : register( b2 )
{
	int     	p_sampleCount;		// # blur samples
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	// Get the depth buffer value at this fragment.
	float depth = (float)texDepth.Sample( samDepth, fragment.tex );
	float2 texCoord = fragment.tex;

	// Convert fragment position to normalized device coordinates.
	float4 screenPos = float4( 2.0f*fragment.tex.x - 1.0f, 1.0f - 2.0f*fragment.tex.y, depth, 1.0f );

	// Transform by inverse view-projection.
	float4 worldPos = mul( currentPos, p_invViewProj );

	// Divide by w to get the world position.  
	worldPos /= worldPos.w;

	// Use the world position, and transform by the previous view-projection matrix.
	float4 previousPos = mul( worldPos, p_prevViewProj );

	// Convert to nonhomogeneous points [-1,1] by dividing by w.
	previousPos /= previousPos.w;

	// Use this frame's position and last frame's to compute the fragment velocity.
	float2 velocity = (currentPos - previousPos) / 2.0f;

	// Get the initial color at this fragment.
	float4 color = texImage.Sample( samImage, fragment.tex );
	texCoord += velocity;
	int cnt = min(5, p_sampleCount);
	for ( int i = 1; i < cnt; ++i, texCoord += velocity )
	{
		// Sample the color buffer along the velocity vector.
		float4 currentColor = texImage.Sample( samImage, texCoord );

		// Add the current color to color sum.
		color += currentColor;
	}

	// Average all of the samples to get the final blur color.
	return color / cnt;
}
