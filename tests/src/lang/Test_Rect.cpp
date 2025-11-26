#include "config.h"
#include "Test.h"
#include <lang/Rect.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestRect :
	public Test
{
public:
	TestRect() : Test( "TestRect", 108 ) {}

	void Run()
	{
		// Creation.
		Rect rc0;
		Assert( rc0.IsEmpty() );
		Assert( rc0.IsNull() );

		Rect rc1( 5, 13, 25, 30 );
		Assert( !rc1.IsEmpty() );
		Assert( !rc1.IsNull() );
		Assert( rc1.Left == 5 );
		Assert( rc1.Top == 13 );
		Assert( rc1.Right == 25 );
		Assert( rc1.Bottom == 30 );
		Assert( rc1.Width() == 20 );
		Assert( rc1.Height() == 17 );

		Rect rc2( rc1 );
		Assert( rc2 == rc1 );
		Assert( rc2 != rc0 );

		// Dimensions & position.
		rc2.Set( 2, 1, 40, 19 );
		Assert( rc2.Left == 2 );
		Assert( rc2.Top == 1 );
		Assert( rc2.Right == 40 );
		Assert( rc2.Bottom == 19 );

		rc2.Move( -5, 11 );
		Assert( rc2.Left == -5 );
		Assert( rc2.Top == 11 );
		Assert( rc2.Right == 33 );
		Assert( rc2.Bottom == 29 );

		rc2.Offset( 1, -2 );
		Assert( rc2.Left == -4 );
		Assert( rc2.Top == 9 );
		Assert( rc2.Right == 34 );
		Assert( rc2.Bottom == 27 );

		rc2.SetSize( 10, 20 );
		Assert( rc2.Left == -4 );
		Assert( rc2.Top == 9 );
		Assert( rc2.Right == 6 );
		Assert( rc2.Bottom == 29 );

		rc2.Inflate( 1, 2 );
		Assert( rc2.Left == -5 );
		Assert( rc2.Top == 7 );
		Assert( rc2.Right == 7 );
		Assert( rc2.Bottom == 31 );

		rc2.Deflate( 2, 1 );
		Assert( rc2.Left == -3 );
		Assert( rc2.Top == 8 );
		Assert( rc2.Right == 5 );
		Assert( rc2.Bottom == 30 );

		rc2.Empty();
		Assert( rc2.IsEmpty() );
		Assert( rc2.IsNull() );

		Rect rcBig( 5, 4, 25, 34 );
		Rect rcSmall( 0, 0, 10, 8 );
		rcSmall.Center( rcBig );

		Assert( rcSmall.Left == 10 );
		Assert( rcSmall.Top == 15 );
		Assert( rcSmall.Width() == 10 );
		Assert( rcSmall.Height() == 8 );
	}

} _tst;
