#include "config.h"
#include "Test.h"
#include <lang/Btree.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

typedef Allocator< BtreeNode<Int> > IntAllocator;

class TestBtree :
	public Test
{
public:
	TestBtree() : Test( "TestBtree", 305 ) {}
	
	void Run()
	{
		return;

		// Creation.
		IntAllocator alloc( __FILE__ );
		Btree<Int> tree( 10, alloc );

		InsertRandom( tree, 7, 32000 );
		/*PrintTree( tree );*/
		printf( "\nDepth: %d Size: %d", tree.Depth(), tree.Size() );
		RemoveRandom( tree, 7, 32000 );
		/*PrintElements( tree );
		printf( "\nDepth: %d Size: %d", tree.Depth(), tree.Size() );*/

		// InsertSequence( tree );
		//RemoveSequence( tree );
		
		/*tree.Insert( 1 );
		tree.Insert( 2 );
		tree.Insert( 3 );
		tree.Insert( 4 );
		tree.Insert( 5 );
		tree.Insert( 6 );
		tree.Insert( 7 );
		tree.Insert( 8 );
		tree.Insert( 9 );
		tree.Insert( 10 );
		tree.Insert( 11 );*/

		/*tree.Insert( 11 );
		tree.Insert( 10 );
		tree.Insert( 7 );
		tree.Insert( 6 );
		tree.Insert( 5 );
		tree.Insert( 4 );
		tree.Insert( 3 );
		//tree.Insert( 8 );
		//tree.Insert( 9 );
		tree.Insert( 2 );
		tree.Insert( 1 );*/

		//PrintTree( tree );
		//PrintElements( tree );

		/*tree.Remove( 3 );
		PrintTree( tree );
		PrintElements( tree );
		tree.Remove( 7 );
		PrintTree( tree );
		PrintElements( tree );

		tree.Remove( 8 );
		PrintTree( tree );
		PrintElements( tree );*/

		/*tree.Remove( 3 );
		PrintTree( tree );

		tree.Remove( 4 );
		PrintTree( tree );
		PrintElements( tree );*/
	}

	void InsertSequence( Btree<Int>& tree )
	{
		tree.Insert( 1 );
		tree.Insert( 3 );
		tree.Insert( 10 );
		tree.Insert( 7 );
		tree.Insert( 5 );
		tree.Insert( 4 );
		tree.Insert( 13 );
		tree.Insert( 11 );
		tree.Insert( 9 );
		tree.Insert( 2 );
		tree.Insert( 12 );
		tree.Insert( 8 );

		tree.Insert( 16 );
		tree.Insert( 22 );
		tree.Insert( 14 );
		tree.Insert( 20 );
		tree.Insert( 19 );
		tree.Insert( 15 );
		tree.Insert( 17 );
		tree.Insert( 6 );

		/*tree.Insert( 9 );
		tree.Insert( 10 );
		tree.Insert( 11 );
		tree.Insert( 12 );
		tree.Insert( 13 );
		tree.Insert( 14 );
		tree.Insert( 15 );
		tree.Insert( 16 );
		tree.Insert( 22 );
		tree.Insert( 14 );
		tree.Insert( 20 );
		tree.Insert( 19 );
		tree.Insert( 15 );
		tree.Insert( 17 );
		tree.Insert( 18 );
		tree.Insert( 21 );*/
	}

	void InsertRandom( Btree<Int>& tree, unsigned int seed, UInt count )
	{
		srand( seed );
		for ( UInt i = 0; i < count; ++i )
		{
			Int elem = (Int)rand();
			/*printf( "\nelem: %d", elem );*/
			tree.Insert( elem );
		}
		/*printf( "\nDepth: %d", tree.Depth() );*/
	}

	void RemoveSequence( Btree<Int>& tree )
	{
		//tree.Remove( 3 );

		//tree.Insert( 18 );
		//tree.Insert( 21 );

		//tree.Remove( 1 );
		//tree.Remove( 6 );
		
		//tree.Remove( 0 );
		//tree.Remove( 2 );
		//tree.Remove( 3 );
		//tree.Remove( 4 );
	}

	void RemoveRandom( Btree<Int>& tree, unsigned int seed, UInt count )
	{
		srand( seed );
		for ( UInt i = 0; i < count; ++i )
		{
			Int elem = (Int)rand();
			printf( "\nelem: %d", elem );
			/*if ( elem == 31193 )
			{
				elem = -1;
			}*/
			tree.Remove( elem );
			/*PrintTree( tree );
			PrintElements( tree );*/
			printf( "\nDepth: %d Size: %d", tree.Depth(), tree.Size() );
		}
		/*printf( "\nDepth: %d", tree.Depth() );*/
	}

	void PrintElements( const Btree<Int>& tree )
	{
		printf( "\n===================================================\n" );

		if ( tree.Size() == 0 )
			return;

		Int prev = 0;
		BtreeIterator<Int> it = tree.First();
		while ( it.IsValid() )
		{
			prev = it._item->value;
			printf( "\nelem: %d", it._item->value );

			it++;
			if ( it.IsValid() && (prev >= it._item->value) )
			{
				Assert( prev >= it._item->value );
				printf( "\nWrong element order: %d\n", it._item->value );
			}
		}
	}

	void PrintTree( const Btree<Int>& tree )
	{
		printf( "\n===================================================\n" );

		if ( tree.Size() == 0 )
			return;

		char buf[20]; char fmt[20];
		BtreeIterator<Int> itLast = tree.Last();
		sprintf( buf, "%d", itLast._item->value );
		UInt itemWidth = (UInt)strlen( buf );
		UInt nodeWidth = (itemWidth+1)*tree.NodeSize() + 1;
		sprintf( fmt, "%%.%dd", itemWidth );

		for ( UInt i = 0; i <= tree.Depth(); ++i )
		{
			PrintLevel( tree, fmt, itemWidth, nodeWidth, i );
		}
	}

	void PrintLevel( const Btree<Int>& tree, const char* fmt, UInt itemWidth, UInt nodeWidth, Int level )
	{
		PrintNode( tree.Root(), fmt, itemWidth, nodeWidth, tree.NodeSize(), tree.Depth(), level, 0 );
		printf( "\n\n" );
	}

	UInt GetNodeOffset( const BtreeNode<Int>* node, UInt nodeWidth )
	{
		UInt offset = 0;

		if ( node->first->child != 0 )
		{
			UInt tmp = GetNodeOffset( node->first->child, nodeWidth );
			UInt width = GetChildrenWidth( node, nodeWidth );
			offset = tmp + (width - nodeWidth)/2;
		}

		return offset;
	}

	UInt GetChildrenWidth( const BtreeNode<Int>* node, UInt nodeWidth )
	{
		UInt width = 0;

		if ( node->first->child != 0 )
		{
			const BtreeItem<Int>* it = node->first;
			for ( ; it != 0; it = it->next )
			{
				if ( it->child != 0 )
				{
					width += GetChildrenWidth( it->child, nodeWidth ) + 1;
				}
			}
			--width;
		}
		else
		{
			width += nodeWidth;
		}

		return width;
	}

	void PrintNode( const BtreeNode<Int>* node, const char* fmt, UInt itemWidth, UInt nodeWidth, UInt nodeSize, UInt depth, Int level, Int current )
	{
		BtreeItem<Int>* item = node->first;

		if ( level == current )
		{
			UInt cnt = GetNodeOffset( node, nodeWidth );
			for ( UInt i = 0; i < cnt; ++i )
			{
				printf( " " );
			}

			printf( "[" );
			for ( ; (item != 0) && (item->next != 0); item = item->next )
			{
				if ( item != node->first )
				{
					printf( " " );
				}
				printf( fmt, item->value );
			}
			UInt sz = node->size;
			if ( sz == 0 )
			{
				for ( UInt i = 0; i < itemWidth; ++i )
				{
					printf( "_" );
				}
				++sz;
			}
			for ( ; sz < nodeSize; ++sz )
			{
				printf( " " );
				for ( UInt i = 0; i < itemWidth; ++i )
				{
					printf( "_" );
				}
			}
			printf( "]" );

			UInt cntTotal = GetChildrenWidth( node, nodeWidth );
			if ( cntTotal > 0 )
			{
				cntTotal -= nodeWidth;
				for ( UInt i = cnt; i < cntTotal; ++i )
				{
					printf( " " );
				}
			}
			printf( " " );
		}
		else
		{
			if ( item->child != 0 )
			{
				for ( ; item != 0; item = item->next )
				{
					PrintNode( item->child, fmt, itemWidth, nodeWidth, nodeSize, depth, level, current+1 );
				}
			}
		}
	}
} _tst;
