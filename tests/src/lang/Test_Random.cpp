#include "config.h"
#include "Test.h"
#include <lang/Random.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestRandom :
	public Test
{
public:
	TestRandom() : Test( "TestRandom", 310 ) {}

	void Run()
	{
		Random rnd;

		Double d = rnd.GetDouble();
		Assert( d >= 0.0 );
		Assert( d <= 1.0 );

		Long i = rnd.GetInt( 1000, 2000 );
		Assert( i >= 1000 );
		Assert( i <= 2000 );
	}

} _tst;
