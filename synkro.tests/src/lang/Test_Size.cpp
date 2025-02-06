#include "config.h"
#include "Test.h"
#include <lang/Size.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestSize :
	public Test
{
public:
	TestSize() : Test( "TestSize", 107 ) {}

	void Run()
	{
		// Creation.
		Size sz0;
		Assert( sz0.Width == 0 );
		Assert( sz0.Height == 0 );

		Size sz1( 5, -17 );
		Assert( sz1.Width == 5 );
		Assert( sz1.Height == -17 );

		Size sz2( sz1 );
		Assert( sz2 == sz1 );
		Assert( sz2 != sz0 );

		// Copying.
		Size sz3;
		sz3 = sz2;
		Assert( sz3 == sz2 );
	}

} _tst;
