#include "config.h"
#include "Tester.h"
#include "Test.h"
#include <time.h>
#include <stdio.h>
#include <internal/Sort.h>


// Link of the test list.
struct TestEntry
{
	const char*	name;
	Test*		test;
	TestEntry*	next;
	int			priority;

	TestEntry( const char* n = "", Test* t = 0, int p = 0 ) :
		name( n ),
		test( t ),
		next( 0 ),
		priority( p )
	{
	}

	synkro::Bool operator<( const TestEntry& other )
	{
		return priority < other.priority;
	}
};

// Global linked list of tests.
static TestEntry* s_tests = 0;
static TestEntry* s_end = 0;

// Number of the currently registered tests.
static int s_count = 0;

// Horizontal line used in formatting output.
static const char* s_line = "--------------------------------------------------------------------------------\n";

static void PrintHeader()
{
	printf( s_line );

	time_t t; time( &t );
	struct tm *newtime; newtime = localtime( &t );
	printf( "                            %sTesting started.\n", asctime( newtime ) );

	printf( s_line );
}

static void PrintResult( const char* result, int position )
{
	static char fmt[8];
	static int maxChars = 80;
	sprintf( fmt, "%%%ds\n", maxChars - position );
	
	if ( position == 0 )
		printf( "\n" );

	printf( fmt, result );
}

static void PrintFooter( int passed, int failed, int errors )
{
	printf( s_line );
	printf( "Testing finished.\nTotal tests run: %d. Passed: %d. Failed: %d. Errors: %d.\n", 
			(passed + failed + errors), passed, failed, errors );
	printf( s_line );
}

//------------------------------------------------------------------------------

bool Tester::AddTest( Test* test, const char* name, int priority )
{
	// See if a valid test is passed.
	if ( !test )
		return false;

	// Create new test entry.
	TestEntry* entry = (TestEntry*)malloc( sizeof(TestEntry) );
	entry->name = name;
	entry->test = test;
	entry->next = 0;
	entry->priority = priority;

	// Append test to the end of the list.
	if ( !s_tests )
		s_tests = entry;
	if ( s_end )
		s_end->next = entry;
	s_end = entry;

	// Update test count.
	++s_count;

	return true;
}

void Tester::RunTests()
{
	int fails = 0;
	int errors = 0;

	if ( s_count < 1 )
	{
		printf( "No tests to run.\n" );
		return;
	}

	PrintHeader();

	// Sort tests by priority.
	int testCount = 0;
	TestEntry* tests = (TestEntry*)malloc( sizeof(TestEntry)*256 );
	for ( TestEntry* entry = s_tests; entry; entry = entry->next )
	{
		tests[testCount++] = *entry;
	}
	Sort( tests, testCount );

	// Run tests.
	for ( int i = 0; i < testCount; ++i )
	{
		const char* strResult = "";

		int chars = printf( "Running test %i: %s ...", i+1, tests[i].name );
		tests[i].test->Run();

		switch ( tests[i].test->Result() )
		{
			case TEST_OK:		strResult = "Ok"; break;
			case TEST_FAIL:		strResult = "Fail"; chars = 0; ++fails; break;
			case TEST_ERROR:	strResult = "Error"; chars = 0; ++errors; break;
		}
		PrintResult( strResult, chars );
	}

	PrintFooter( s_count - (fails + errors), fails, errors );

	free( tests );
}
