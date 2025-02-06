#include "config.h"
#include "Test.h"
#include <lang/Tree.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

typedef Allocator< TreeItem<Long> > IntAllocator;

class TestTree :
	public Test
{
public:
	TestTree() : Test( "TestTree", 304 ) {}

	void Run()
	{
		Long e[] = { 0,1,2,3,4,5,6,7,8,9 };

		// Creation.
		IntAllocator ialloc( __FILE__ );
		Tree<Long> tree( ialloc );
		
		TreeIterator<Long> root, it, it1, it2, it3, it4, it5, it6, it7, it8;
		root = tree.Root();
		Assert( !root.IsValid() );
		Assert( tree.IsEmpty() );

		// Insertion.
		it3 = tree.Add( e[3] );

		it7 = tree.Add( it3, e[7] );
		it2 = tree.Add( it3, e[2] );
		it6 = tree.Add( it3, e[6] );

		it5 = tree.Add( it7, e[5] );
		it4 = tree.Add( it2, e[4] );
		it1 = tree.Add( it2, e[1] );
		it8 = tree.Add( it2, e[8] );

		Assert( tree.Size() == 8 );

/**************************************
	This is how the tree should look by now.
	[3]
	 |_______
	 |	 |   |
	[7] [2] [6]
	 |	 |_______
	 |	 |	 |   |
	[5]	[4] [1] [8]
***************************************/
		
		// Children count.
		Assert( tree.ChildrenCount( it3, true ) == 7 );
		Assert( tree.ChildrenCount( it3 ) == 3 );

		Assert( tree.ChildrenCount( it7, true ) == 1 );
		Assert( tree.ChildrenCount( it7 ) == 1 );

		Assert( tree.ChildrenCount( it2, true ) == 3 );
		Assert( tree.ChildrenCount( it2 ) == 3 );

		Assert( tree.ChildrenCount( it6, true ) == 0 );
		Assert( tree.ChildrenCount( it6 ) == 0 );

		Assert( tree.HasChildren( it3 ) == true );
		Assert( tree.HasChildren( it7 ) == true );
		Assert( tree.HasChildren( it6 ) == false );
		Assert( tree.HasChildren( it1 ) == false );

		// Depth level.
		Assert( tree.Depth( it3 ) == 0 );
		Assert( tree.Depth( it7 ) == 1 );
		Assert( tree.Depth( it8 ) == 2 );

		// Traversal.
		it = it3;

		it = tree.TraverseDepth( it );
		Assert( it == it7 );

		it = tree.TraverseDepth( it );
		Assert( it == it5 );

		it = tree.TraverseDepth( it );
		Assert( it == it2 );

		it = tree.TraverseDepth( it );
		Assert( it == it4 );

		it = tree.TraverseDepth( it );
		Assert( it == it1 );

		it = tree.TraverseDepth( it );
		Assert( it == it8 );

		it = tree.TraverseDepth( it );
		Assert( it == it6 );

		it = tree.TraverseDepth( it );
		Assert( !it.IsValid() );

		// Searching.
		it = tree.Find( e[4], true );
		Assert( it == it4 );

		it = tree.Find( e[4] );
		Assert( !it.IsValid() );

		it = tree.Find( it2, e[4], true );
		Assert( it == it4 );

		it = tree.Find( it2, e[4] );
		Assert( it == it4 );

		it = tree.Find( it2, e[6], true );
		Assert( !it.IsValid() );

		it = tree.Find( it2, e[6] );
		Assert( !it.IsValid() );

		// Removal.
		tree.Remove( it1 );
		Assert( tree.Size() == 7 );
		Assert( tree.ChildrenCount( it2 ) == 2 );

		tree.RemoveChildren( it2 );
		Assert( tree.Size() == 5 );
		Assert( tree.ChildrenCount( it2 ) == 0 );

		tree.Clear();
		Assert( tree.Size() == 0 );
	}

} _tst;
