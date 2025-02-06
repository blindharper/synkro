#ifndef _TEST_
#define _TEST_


// Debug assertion. Should be used inside tests.
#undef Assert
#define Assert( x )				\
	if ( x != true )			\
	{							\
		printf( "\n\tAssertion failed: ( %s ) at line %d", #x, __LINE__ );	\
		_result = TEST_FAIL;	\
	}


// Fatal error signal. Should be used inside tests.
#undef FatalError
#define FatalError( x )			\
	printf( "\n\t%s", x );		\
	_result = TEST_ERROR;		\
	return


// Possible test results.
enum TestResult
{
	// Test passed.
	TEST_OK,
	// Test failed.
	TEST_FAIL,
	// Fatal error occured.
	TEST_ERROR,
};


// Abstract test class.
class Test
{
public:
	// Registers test in the tester.
	// @param name Name of the test as it will appear in the tester.
	// @param priority Test priority.
	Test( const char* name, int priority = 0 );

	// Runs the test.
	// @see Derived classes should override this to perform actual testing.
	virtual void	Run() = 0;

	// Stores test result.
	// Should be checked by Tester after running the test.
	TestResult		Result() const;

protected:
	TestResult		_result;
};


#endif // _TEST_
