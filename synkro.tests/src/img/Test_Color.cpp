#include "config.h"
#include "Test.h"
#include <img/Color.h>
#include <math/Math.h>

//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::math;

//------------------------------------------------------------------------------

class TestColor :
	public Test
{
public:
	TestColor() : Test( "TestColor", 900 ) {}

	void Run()
	{
		// Creation.
		Color col0;
		Assert( col0.R == 0.0f );
		Assert( col0.G == 0.0f );
		Assert( col0.B == 0.0f );

		Color col1( 0.234f, 0.718f, 0.5f );
		Assert( col1.R == 0.234f );
		Assert( col1.G == 0.718f );
		Assert( col1.B == 0.5f );

		Color col2( col1 );
		Assert( col2 == col1 );
		Assert( col2 != col0 );

		Color col3( L"Pink" );
		Assert( col3 == Color::Pink );

		Color col4( L"7FC03D" );
		Assert( Math::Abs(col4.R - 127.0f/255.0f) < Math::Eps );
		Assert( Math::Abs(col4.G - 192.0f/255.0f) < Math::Eps );
		Assert( Math::Abs(col4.B - 61.0f/255.0f) < Math::Eps );

		// Well known colors.
		Assert( Color::LightGoldenrodYellow.R == 0.980392f );
		Assert( Color::LightGoldenrodYellow.G == 0.980392f );
		Assert( Color::LightGoldenrodYellow.B == 0.823529f );

		// Conversion.
		Assert( Color::AliceBlue.ToString() == L"AliceBlue" );
		Assert( Color(L"AliceBlue") == Color::AliceBlue );

		// Comparison.
		Assert( Color::Black == Color(0.0f, 0.0f, 0.0f) );
		Assert( Color::Black != Color::White );
	}

} _tst;
