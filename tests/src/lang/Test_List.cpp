#include "config.h"
#include "Test.h"
#include <lang/List.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

typedef Allocator< ListItem<Long> > IntAllocator;

class TestList :
	public Test
{
public:
	TestList() : Test( "TestList", 302 ) {}
	
	void Run()
	{
		Long e[] = { 0,1,2,3,4,5,6,7,8,9 };

		// Creation.
		IntAllocator ialloc( __FILE__ );
		List<Long> lst( ialloc );
		
		ListIterator<Long> itBegin, itEnd;
		itBegin = lst.Begin();
		itEnd = lst.End();
		Assert( lst.IsEmpty() );
		Assert( lst.Size() == 0 );
		
		// Append.
		lst.Add( e[6] );
		lst.Add( e[3] );
		lst.Add( e[8] );
		lst.Add( e[2] );
		lst.Add( e[1] );
		lst.Add( e[9] );
		lst.Add( e[4] );
		lst.Add( e[7] );
		Assert( lst.Size() == 8 );

		// Search.
		ListIterator<Long> it, it0;
		itBegin = lst.Begin();

		it = lst.Find( e[0], itBegin );
		Assert( it == lst.End() );

		it = lst.Find( e[2] );
		Assert( it != lst.End() );

		it0 = lst.FindLast( e[6], it );
		Assert( it0 == lst.Begin() );

		it0 = lst.FindLast( e[3] );
		Assert( it0 != lst.End() );

		// Insertion.
		lst.Insert( e[7] );
		lst.Insert( e[5], it );
		lst.Insert( e[6], it );
		Assert( lst.Size() == 11 );

		// Removal.
		lst.Remove( lst.Begin() );
		lst.Remove( it );
		Assert( lst.Size() == 9 );

/**************************************
	This is how the list should look by now.

	[6]-[3]-[8]-[5]-[6]-[1]-[9]-[4]-[7]-[end]

***************************************/

		// Iterators.
		it = lst.Begin();
		Assert( *it == e[6] );
		it++;
		Assert( *it == e[3] );
		++it;
		Assert( *it++ == e[8] );
		Assert( *it == e[5] );
		
		it = lst.End();
		Assert( *(--it) == e[7] );
		it--;
		Assert( *(it--) == e[4] );
		Assert( *it == e[9] );

		// Copying.
		List<Long> lst1( lst );
		Assert( lst1.Size() == lst.Size() )
	}

} _tst;
