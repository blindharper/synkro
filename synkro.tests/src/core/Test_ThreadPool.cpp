#include "config.h"
#include <mem/MemoryManager.h>
#include <core/ThreadPool.h>
#include <core/ObjectImpl.h>

//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro;

//------------------------------------------------------------------------------

// Test task.
class TestTask :
	public ObjectImpl<Task>
{
public:
	TestTask( UInt cnt ) :
		_cnt( cnt )
	{
	}

	void Execute()
	{
		UInt res = 0;
		wprintf( L"Task #%d started...\n", _cnt );
		for ( UInt i = 0; i < _cnt; ++i )
		{
			res += 100;
		}
		wprintf( L"Task #%d ended. Result = %d\n", _cnt, res );
	}

	void Cancel()
	{
	}

private:
	UInt _cnt;
};

int main( int argc, char* argv[] )
{
	SynkroMemoryInit( "synkro.mem", true, nullptr, false, true );	\

	ThreadPool pool( 5, nullptr );
	for ( UInt i = 0; i < 10; ++i )
	{
		pool.AddTask( new TestTask(1000000*i) );
	}
		
	// Wait till the pool is empty.

	wprintf( L"Sleeping...\n" );
	::Sleep( 5000 );
	wprintf( L"Woke up\n" );

	pool.Terminate();
	wprintf( L"Terminated\n" );

	return 0;
}
