//------------------------------------------------------------------------------
// File: gouraud.vsh
//
// Purpose: Gouraud lighting algorithm
//------------------------------------------------------------------------------
#ifndef _GOURAUD_VSH_
#define _GOURAUD_VSH_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "../viewport_lit.vsh"

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

// Calculates lighting
Lighting CalcLighting( Material mat, float4 worldNormal, float4 worldPos, float4 cameraPos )
{
	float fAtten = 1.0f;
	float fSpot = 1.0f;
	float4 dir = float4( 0.0f, 0.0f, 0.0f, 0.0f );
	float4 dirCamSpace = float4( 0.0f, 0.0f, 0.0f, 0.0f );
	float4 toLight;
	float dist;
	float rho = 1.0f;
	float4 halfAngle;
	Lighting output = (Lighting)0.0;

	// Apply ambient light and material emissive color.
	output.diffuse = mat.ambient*sp_lightAmbient + mat.emissive;

	for ( int i = 0; i < sp_lightCount; ++i )
	{
		fAtten = 1.0f;
		fSpot = 1.0f;
		rho = 1.0f;
		dir = float4( 0.0f, 0.0f, 0.0f, 0.0f );

		if ( lights[i].type == LIGHTTYPE_DIRECT )
		{
			dir = lights[i].dir;
		}
		else
		{
			// Calculate distance to light source.
			toLight = lights[i].pos - worldPos;
			dist = length( toLight );

			// Filter out distant lights.
			if ( dist > lights[i].range )
				continue;

			// Calculate light attenuation factor.
			dir = normalize( toLight );
			fAtten = 1.0f / (lights[i].atten_const + lights[i].atten_linear*dist + lights[i].atten_quadratic*dist*dist);

			// Calculate spotlight factor.
			if ( lights[i].type == LIGHTTYPE_CONE )
			{
				dirCamSpace = mul( lights[i].dir, sp_proj );
				rho = dot( normalize(-dirCamSpace), normalize(toLight) );
				if ( rho > cos(0.5f*lights[i].theta) )
				{
					fSpot = 1.0f;
				}
				else if ( rho <= cos(0.5f*lights[i].phi) )
				{
					fSpot = 0.0f;
				}
				else
				{
					fSpot = pow( (rho-cos(0.5f*lights[i].phi)) / (cos(0.5f*lights[i].theta)-cos(0.5f*lights[i].phi)), lights[i].falloff );
				}
			}
		}

		halfAngle = normalize( normalize(-cameraPos) + dir );
		output.diffuse  += max( 0, mat.diffuse * lights[i].diffuse * dot(dir, worldNormal) * fAtten * fSpot ) + mat.ambient*lights[i].ambient;
		output.specular += max( 0, mat.specular * lights[i].specular * pow(abs(dot(halfAngle, worldNormal)), mat.power) * fAtten * fSpot );
	}

	return output;
}

#endif // _GOURAUD_VSH_
