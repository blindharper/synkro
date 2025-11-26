#include "config.h"
#include "Test.h"
#include <math/Quaternion.h>

//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------

class TestQuaternion :
	public Test
{
public:
	TestQuaternion() : Test( "TestQuaternion", 703 ) {}

	void Run()
	{
		// Creation.
		Quaternion q1;
		Assert( (q1.x == 0.0f) && (q1.y == 0.0f) && (q1.z == 0.0f) && (q1.w == 1.0f) );
	}

} _tst;
