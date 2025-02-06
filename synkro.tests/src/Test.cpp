#include "config.h"
#include "Test.h"
#include "Tester.h"


Test::Test( const char* name, int priority )
{
	_result = TEST_OK;
	Tester::AddTest( this, name, priority );
}

TestResult Test::Result() const
{
	return _result;
}
