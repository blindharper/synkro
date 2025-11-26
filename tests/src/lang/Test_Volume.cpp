#include "config.h"
#include "Test.h"
#include <lang/Volume.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestVolume :
	public Test
{
public:
	TestVolume() : Test( "TestVolume", 111 ) {}

	void Run()
	{
		// Creation.
		Volume vol0;
		Assert( vol0.IsEmpty() );
		Assert( vol0.IsNull() );

		Volume vol1( 5.0f, 30.0f, 7.0f, 25.0f, 13.0f, 17.0f );
		Assert( !vol1.IsEmpty() );
		Assert( !vol1.IsNull() );
		Assert( vol1.Left == 5.0f );
		Assert( vol1.Top == 30.0f );
		Assert( vol1.Near == 7.0f );
		Assert( vol1.Right == 25.0f );
		Assert( vol1.Bottom == 13.0f );
		Assert( vol1.Far == 17.0f );
		Assert( vol1.Width() == 20.0f );
		Assert( vol1.Height() == 17.0f );
		Assert( vol1.Depth() == 10.0f );

		Volume vol2( vol1 );
		Assert( vol2 == vol1 );
		Assert( vol2 != vol0 );

		// Dimensions.
		vol2.Set( 2.0f, 1.0f, 3.0f, 40.0f, 19.0f, 33.0f );
		Assert( vol2.Left == 2.0f );
		Assert( vol2.Top == 1.0f );
		Assert( vol2.Near == 3.0f );
		Assert( vol2.Right == 40.0f );
		Assert( vol2.Bottom == 19.0f );
		Assert( vol2.Far == 33.0f );

		vol2.Inflate( 1.0f, 2.0f, 1.0f );
		Assert( vol2.Left == 1.0f );
		Assert( vol2.Top == -1.0f );
		Assert( vol2.Near == 2.0f );
		Assert( vol2.Right == 41.0f );
		Assert( vol2.Bottom == 21.0f );
		Assert( vol2.Far == 34.0f );

		vol2.Deflate( 2.0f, 1.0f, 1.0f );
		Assert( vol2.Left == 3.0f );
		Assert( vol2.Top == 0.0f );
		Assert( vol2.Near == 3.0f );
		Assert( vol2.Right == 39.0f );
		Assert( vol2.Bottom == 20.0f );
		Assert( vol2.Far == 33.0f );

		vol2.Empty();
		Assert( vol2.IsEmpty() );
		Assert( vol2.IsNull() );
	}

} _tst;
