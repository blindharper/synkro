#ifndef _TESTER_
#define _TESTER_


class Test;


// Tester used to register and run a set of tests.
class Tester
{
public:
	// Registers a test to be run by the tester.
	// @param test Test to register in the tester.
	// @param name Name of the test.
	// @param priority Test priority.
	// @return True if test has been registered, false otherwise.
	static bool			AddTest( Test* test, const char* name, int priority );

	// Runs all registered tests.
	static void			RunTests();
};


#endif // _TESTER_
