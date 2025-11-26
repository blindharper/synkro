#include "config.h"
#include "Test.h"
#include <lang/Convert.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestConvert :
	public Test
{
public:
	TestConvert() : Test( "TestConvert", 105 ) {}

	void Run()
	{
		// Conversion to String.
		String strLong = Convert::ToString( 451 );
		Assert( strLong == "451" );

		String strFloat = Convert::ToString( 3.14 );
		Assert( strFloat == "3.14" );

		String strDouble = Convert::ToString( 12.73 );
		Assert( strDouble == "12.73" );

		// Conversion to numbers.
		Long numLong = Convert::ToLong( "538" );
		Assert( numLong == 538 );

		Float numFloat = Convert::ToFloat( "10359.76936" );
		Assert( (10359.76936 - numFloat ) < 1e-6 );

		Double numDouble = Convert::ToDouble( ".043788" );
		Assert( (.043788 - numDouble ) < 1e-6 );

		// Conversion to date/time.
		DateTime dt = Convert::ToDateTime( "06/21/2008", "d" );
		Assert( dt.Month() == 6 );
		Assert( dt.Day() == 21 );
		Assert( dt.Year() == 2008 );

		dt = Convert::ToDateTime( "06/21/2008 17:23", "g" );
		Assert( dt.Month() == 6 );
		Assert( dt.Day() == 21 );
		Assert( dt.Year() == 2008 );
		Assert( dt.Hour() == 17 );
		Assert( dt.Minute() == 23 );
		Assert( dt.Second() == 0 );

		dt = Convert::ToDateTime( "Sat Jun 21 2008 14:59:37", "r" );
		Assert( dt.Month() == 6 );
		Assert( dt.Day() == 21 );
		Assert( dt.Year() == 2008 );
		Assert( dt.Hour() == 14 );
		Assert( dt.Minute() == 59 );
		Assert( dt.Second() == 37 );
	}

} _tst;
