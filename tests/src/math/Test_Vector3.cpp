#include "config.h"
#include "Test.h"
#include <math/Vector3.h>

//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace synkro;

//------------------------------------------------------------------------------

class TestVector3 :
	public Test
{
public:
	TestVector3() : Test( "TestVector3", 701 ) {}

	void Run()
	{
		// Creation.
		Float vec[] = { 17.5f, -3.14f, 8.0f };
		Vector3 vec0( vec );
		Assert( vec0.x == 17.5f && vec0.y == -3.14f && vec0.z == 8.0f );

		Vector3 vec1;
		Assert( vec1.x == 0.0f && vec1.y == 0.0f && vec1.z == 0.0f );
		Assert( vec1.Length() == 0.0f );
		
		// Copying.
		vec1 = Vector3( 3.0f, 4.0f, 0.0f );
		Assert( vec1.x == 3.0f && vec1.y == 4.0f && vec1.z == 0.0f );
		Assert( vec1.Length() == 5.0f );

		// Normalization.
		vec1.Normalize();
		Assert( vec1.Length() == 1.0f );

		// Addition.
		Vector3 vec2( 7.6f, -0.35f, 1.17f );
		vec2 += Vector3( -5.1f, 1.0f, -1.17f );
		Assert( vec2 == Vector3( 2.5f, 0.65f, 0.0f ) );

		// Inversion.
		Vector3 vec4( -vec2 );
		Assert( vec4 == Vector3( -2.5f, -0.65f, -0.0f ) );

		// Scaling.
		Vector3 vec5( vec4*2.0f );
		Assert( vec5 == Vector3( -5.0f, -1.3f, 0.0f ) );

		Vector3 vec6( vec5/2.0f );
		Assert( vec6 == vec4 );

		// Cross product.
		Vector3 vec7( 5.0f, 0.0f, 0.0f );
		Vector3 vec8( 0.0f, 5.0f, 0.0f );
		Vector3 vec9 = vec7^vec8;
		Assert( (vec9.x = vec9.y == 0.0f) && (vec9.z != 0.0f) );

		// Dot product.
		Float dot = vec7*vec8;
		Assert( dot == 0.0f );
	}

} _tst;
