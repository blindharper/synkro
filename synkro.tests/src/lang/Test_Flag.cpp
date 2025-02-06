#include "config.h"
#include "Test.h"
#include <core/ParamConstraint.h>

//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------

class TestFlag :
	public Test
{
public:
	TestFlag() : Test( "TestFlag", 110 ) {}

	void Run()
	{
		Assert( ParamConstraint::NonEmpty == ParamConstraint::NonEmpty );
		Assert( ParamConstraint::NonEmpty != ParamConstraint::Positive );

		ParamConstraint pc = ParamConstraint::NonEmpty | ParamConstraint::Positive;
		Assert( pc.IsSet(ParamConstraint::NonEmpty) );
		Assert( pc.IsSet(ParamConstraint::Positive) );
	}

} _tst;
