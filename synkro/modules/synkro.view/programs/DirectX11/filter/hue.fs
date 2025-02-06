//------------------------------------------------------------------------------
// File: hue.fs
//
// Purpose: "Hue" post-processing filter
//------------------------------------------------------------------------------
#include "simple.fsh"

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

// Converts RGB color to HSV color
float4 rgb2hsv( float4 c )
{
	float minRGB = min( min(c.r, c.g), c.b );
	float maxRGB = max( max(c.r, c.g), c.b );
	float delta = maxRGB - minRGB;

	float v = maxRGB;
	if ( delta < 0.00001 )
		return float4( 0.0f, 0.0f, v, 1.0f );

	if ( maxRGB == 0.0f )
		return float4( 0.0f, 0.0f, v, 1.0f );

	float s = delta/maxRGB;

	float h = 0.0f;		
	if ( maxRGB == c.r )
		h = (c.g - c.b) / delta;
	else if ( maxRGB == c.g )
		h = 2.0f + (c.b - c.r) / delta;
	else if ( maxRGB == c.b )
		h = 4.0f + (c.r - c.g) / delta;

	h *= 60.0f;
	if ( h < 0.0f )
	{
		h += 360.0f;
	}

	return float4( h, s, v, 1.0f );
}

// Converts HSV color to RGB color
float4 hsv2rgb( float4 c )
{
	float h = c.x;
	float s = c.y;
	float v = c.z;

	if ( v == 0.0f )
		return float4( 0.0f, 0.0f, 0.0f, 1.0f );

	if ( s == 0.0f )
		return float4( v, v, v, 1.0f );

	float hh = h;
	if ( hh >= 360.0f )
		hh -= 360.0f;
	hh /= 60.0f;
	int i = (int)hh;
	float ff = hh - (float)i;

	float p = v * (1.0f - s);
	float q = v * (1.0f - (s * ff));
	float t = v * (1.0f - (s * (1.0f - ff)));

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	switch ( i )
	{
		case 0:
			r = v;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = v;
			b = p;
			break;

		case 2:
			r = p;
			g = v;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = v;
			break;

		case 4:
			r = t;
			g = p;
			b = v;
			break;

		default:
			r = v;
			g = p;
			b = q;
			break;
	}

	return float4( r, g, b, 1.0f );
}

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
float4 main( Fragment fragment ) : SV_TARGET
{
	float4 rgb = texImage.Sample( samImage, fragment.tex );
	float4 hsv = rgb2hsv( rgb );
	hsv.x += p_value;
	rgb = hsv2rgb( hsv );
	return rgb;
}
