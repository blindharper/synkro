#include "config.h"
#include "Test.h"
#include <core/ParamType.h>

//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestEnum :
	public Test
{
public:
	TestEnum() : Test( "TestEnum", 109 ) {}

	void Run()
	{
		Assert( ParamType::String == ParamType::String );
		Assert( ParamType::String != ParamType::Integer );
	}

} _tst;
