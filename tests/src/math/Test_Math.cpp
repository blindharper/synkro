#include "config.h"
#include "Test.h"
#include <math/Math.h>

//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace synkro;

//------------------------------------------------------------------------------

class TestMath :
	public Test
{
public:
	TestMath() : Test( "TestMath", 700 ) {}

	void Run()
	{
		// Main functions.
		Assert( Math::Abs(1.5f) == 1.5f );
		Assert( Math::Abs(-14.5678f) == 14.5678f );
		
		Assert( Math::Ceil(11.7f) == 12.0f );
		Assert( Math::Ceil(-11.7f) == -11.0f );
		
		Assert( Math::Floor(11.7f) == 11.0f );
		Assert( Math::Floor(-11.7f) == -12.0f );

		Assert( Math::Sqrt(121.0f) == 11.0f );
		Assert( Math::Sqrt(0.0f) == 0.0f );
		
		Assert( Math::Pow(11.0f, 0) == 1.0f );
		Assert( Math::Pow(-11.0f, 2) == 121.0f );
		Assert( Math::Pow(-11.0f, 3) == -1331.0f );
		Assert( Math::Pow(9.0f, 0.5f) == 3.0f );

		// Exponential and logarithmic functions.
		Assert( Math::Abs(Math::Exp(1.0f) - Math::E) < Math::Eps );
		Assert( Math::Abs(Math::Exp(0.0f) - 1.0f) < Math::Eps );

		Assert( Math::Abs(Math::Log(Math::E) - 1.0f) < Math::Eps );
		Assert( Math::Log10( 1000 ) == 3.0f );

		// Trigonomertic functions.
		Assert( Math::Abs(Math::Atan(1.0f) - Math::QuarterPi) < Math::Eps );

		Assert( Math::Sin(0.0f) == 0.0f );
		Assert( Math::Cos(0.0f) == 1.0f );

		Assert( Math::Abs(Math::Sin(Math::QuarterPi) - Math::Cos(Math::QuarterPi)) < Math::Eps );
		Assert( Math::Abs(Math::Tan(Math::QuarterPi) - 1.0f) < Math::Eps );

		Assert( Math::Abs(Math::Asin(Math::Sin(Math::QuarterPi)) - Math::QuarterPi) < Math::Eps );
		Assert( Math::Abs(Math::Acos(Math::Cos(Math::QuarterPi)) - Math::QuarterPi) < Math::Eps );

		// Comparison.
		Assert( Math::Max(-145.3f, 0.75665f) == 0.75665f );
		Assert( Math::Min(-145.3f, 0.75665f) == -145.3f );
	}

} _tst;
