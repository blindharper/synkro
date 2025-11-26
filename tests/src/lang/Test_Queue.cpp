#include "config.h"
#include "Test.h"
#include <lang/Queue.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

typedef Allocator< QueueItem<Long> > IntAllocator;

class TestQueue :
	public Test
{
public:
	TestQueue() : Test( "TestQueue", 306 ) {}

	void Run()
	{
		// Creation.
		IntAllocator ialloc( __FILE__ );
		Queue<Long> q( ialloc, 50 );

		Assert( q.Size() == 0 );
		Assert( q.Capacity() == 50 );

		// Adding.
		q.Add( 6 );
		q.Add( 3 );
		q.Add( 8 );
		q.Add( 5 );
		q.Add( 6 );
		q.Add( 1 );
		q.Add( 9 );
		q.Add( 4 );
		q.Add( 7 );
		Assert( q.Size() == 9 );

/**************************************
	This is how the queue should look by now.

	[6]-[3]-[8]-[5]-[6]-[1]-[9]-[4]-[7]

***************************************/

		// Copying.
		Queue<Long> q1( q );
		Assert( q1.Capacity() == q.Capacity() );
		Assert( q1.Size() == q.Size() );

		// Removing.
		Assert( q.Remove() == 6 );
		Assert( q.Size() == 8 );

		Assert( q.Remove() == 3 );
		Assert( q.Size() == 7 );

		Assert( q.Remove() == 8 );
		Assert( q.Size() == 6 );

		Assert( q.Remove() == 5 );
		Assert( q.Size() == 5 );

		Assert( q.Remove() == 6 );
		Assert( q.Size() == 4 );

		Assert( q.Remove() == 1 );
		Assert( q.Size() == 3 );

		Assert( q.Remove() == 9 );
		Assert( q.Size() == 2 );

		Assert( q.Remove() == 4 );
		Assert( q.Size() == 1 );

		Assert( q.Remove() == 7 );
		Assert( q.Size() == 0 );
	}

} _tst;
