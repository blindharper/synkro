#include "config.h"
#include "Test.h"
#include <lang/Stack.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

typedef Allocator<Long> IntAllocator;

class TestStack :
	public Test
{
public:
	TestStack() : Test( "TestStack", 301 ) {}

	void Run()
	{
		// Creation.
		IntAllocator ialloc( __FILE__ );
		Stack<Long> stk( ialloc, 50 );

		Assert( stk.Size() == 0 );
		Assert( stk.Capacity() == 50 );

		// Pushing.
		stk.Push( 6 );
		stk.Push( 3 );
		stk.Push( 8 );
		stk.Push( 2 );
		stk.Push( 1 );
		stk.Push( 9 );
		stk.Push( 4 );
		stk.Push( 7 );
		Assert( stk.Size() == 8 );
		Assert( stk.Top() == 7 );

/**************************************
	This is how the stack should look by now.

	[6]-[3]-[8]-[5]-[6]-[1]-[9]-[4]-[7] <- top

***************************************/

		// Copying.
		Stack<Long> stk1( stk );
		Assert( stk1.Capacity() == stk.Capacity() );
		Assert( stk1.Size() == stk.Size() );
		Assert( stk1.Top() == stk.Top() );

		// Popping.
		stk.Pop();
		Assert( stk.Size() == 7 );
		Assert( stk.Top() == 4 );

		stk.Pop();
		Assert( stk.Size() == 6 );
		Assert( stk.Top() == 9 );

		stk.Pop();
		Assert( stk.Size() == 5 );
		Assert( stk.Top() == 1 );

		stk.Pop();
		Assert( stk.Size() == 4 );
		Assert( stk.Top() == 2 );

		stk.Pop();
		Assert( stk.Size() == 3 );
		Assert( stk.Top() == 8 );

		stk.Pop();
		Assert( stk.Size() == 2 );
		Assert( stk.Top() == 3 );

		stk.Pop();
		Assert( stk.Size() == 1 );
		Assert( stk.Top() == 6 );

		stk.Pop();
		Assert( stk.Size() == 0 );

		// Stack underflow interception.		
		try
		{
			stk.Pop();
			FatalError( "Failed to intercept stack underflow." );
		}
		catch ( StackUnderflowException& )
		{
		}

		// Stack overflow interception.		
		try
		{
			for ( ; ; )
			{
				stk1.Push( 44 );
			}

			// We should never get here.
			FatalError( "Failed to intercept stack overflow." );
		}
		catch ( StackOverflowException& )
		{
		}
	}

} _tst;
