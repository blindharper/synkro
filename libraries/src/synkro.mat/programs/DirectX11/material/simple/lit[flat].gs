//------------------------------------------------------------------------------
// File: lit[flat].gs
//
// Purpose: Geometry shader for lit simple material
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Geometry shader input data
struct Geometry
{
	float4 pos	: SV_POSITION;		// Transformed position
	float4 diffuse	: COLOR0;		// Diffuse color
	float4 specular	: COLOR1;		// Specular color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
[maxvertexcount(3)]
void main( triangle Geometry input[3], inout TriangleStream<Geometry> stream )
{
	Geometry output;

	float4 diffuse = (input[0].diffuse+input[1].diffuse+input[2].diffuse)/3.0f;
	float4 specular = (input[0].specular+input[1].specular+input[2].specular)/3.0f;
	float dist = (input[0].dist+input[1].dist+input[2].dist)/3.0f;
	for ( int i = 0; i < 3; ++i )
	{
		output = input[i];
		output.diffuse = diffuse;
		output.specular = specular;
		output.dist = dist;
		stream.Append( output );
	}
	stream.RestartStrip();
}
