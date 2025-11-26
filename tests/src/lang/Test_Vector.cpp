#include "config.h"
#include "Test.h"
#include <lang/Vector.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestVector :
	public Test
{
public:
	TestVector() : Test( "TestVector", 300 ) {}

	void Run()
	{
		typedef Allocator<Long> IntAllocator;
		typedef Vector<Long> IntVector;

		// Creation.
		IntAllocator numAlloc( __FILE__ );
		IntVector numbers( numAlloc );

		Assert( numbers.Size() == 0 );
		Assert( numbers.IsEmpty() );

		numbers.Add( 17 );
		numbers.Add( 56 );
		numbers.Add( 93 );
		numbers.Add( -1 );
		numbers.Add( 93 );
		numbers.Add( 45 );
		numbers.Add( 56 );

		Assert( numbers.Size() == 7 );
		Assert( !numbers.IsEmpty() );

		// Access.
		numbers[1] = 313;
		Assert( numbers[1] == 313 );

		numbers[1] = numbers[6];
		Assert( numbers[1] == 56 );

		// Searching.
		Assert( numbers.IndexOf( 93 ) == 2 );
		Assert( numbers.IndexOf( 93, 3 ) == 4 );
		Assert( numbers.IndexOf( 77 ) == -1 );

		Assert( numbers.LastIndexOf( 56 ) == 6 );
		Assert( numbers.LastIndexOf( 56, 5 ) == 1 );
		Assert( numbers.LastIndexOf( 45, 4 ) == -1 );

		// Resizing.
		numbers.SetSize( 8, 112 );
		Assert( numbers[7] == 112 );

		numbers.SetSize( 10 );
		Assert( numbers[9] == 0 );

		numbers.TrimToSize();
		Assert( numbers.Capacity() == numbers.Size() );

		// Copying.
		IntVector numbers1( numbers );
		Assert( numbers1.Size() == 10 );

		for ( int i = 0; i < 10; ++i )
		{
			Assert( numbers[i] == numbers1[i] );
		}

		// Clearing.
		numbers.Clear();
		Assert( numbers.IsEmpty() );
		Assert( numbers.Size() == 0 );
	}

} _tst;
