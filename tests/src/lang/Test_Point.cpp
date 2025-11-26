#include "config.h"
#include "Test.h"
#include <lang/Point.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestPoint :
	public Test
{
public:
	TestPoint() : Test( "TestPoint", 107 ) {}

	void Run()
	{
		// Creation.
		Point pt0;
		Assert( pt0.X == 0 );
		Assert( pt0.Y == 0 );

		Point pt1( 5, -17 );
		Assert( pt1.X == 5 );
		Assert( pt1.Y == -17 );

		Point pt2( pt1 );
		Assert( pt2 == pt1 );
		Assert( pt2 != pt0 );

		// Copying.
		Point pt3;
		pt3 = pt2;
		Assert( pt3 == pt2 );
	}

} _tst;
