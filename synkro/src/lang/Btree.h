//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines B-tree.
//==============================================================================
#ifndef _SYNKRO_LANG_BTREE_
#define _SYNKRO_LANG_BTREE_


#include "config.h"
#include "Allocator.h"
#include "BtreeIterator.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


// B-tree container holding elements of type T.
template <class T, class A = Allocator<BtreeNode<T> > >
class Btree
{
public:
	// Constructs an empty tree.
	explicit Btree( UInt nodeSize, const A& alloc );

	// Frees all allocated resources.
	~Btree();

	// Inserts element into the tree.
	BtreeIterator<T>										Insert( const T& elem );

	// Removes element from the tree.
	void													Remove( const T& elem );
	
	// Removes all elements from the tree.
	void													Clear();

	// Finds element with the given value.
	BtreeIterator<T>										Find( const T& elem );

	// Retrieves first item of the tree.
	BtreeIterator<T>										First() const;

	// Retrieves last item of the tree.
	BtreeIterator<T>										Last() const;

	// Returns the number of levels in the tree.
	UInt													Depth() const;

	// Returns the total number of elements in the tree.
	UInt													Size() const;

	// Returns the maximum number of elements in a node.
	UInt													NodeSize() const;

	// Returns true if the tree has no elements.
	Bool													IsEmpty() const;

	// Retrieves root node.
	BtreeNode<T>*											Root() const;

private:
	mutable BtreeNode<T>*									_root;
	Allocator<BtreeItem<T> >								_allocItem;
	mutable A												_alloc;
	UInt													_nodeSize;
	UInt													_minSize;
	UInt													_size;
	UInt													_depth;

	BtreeItem<T>*											First( BtreeNode<T>* node ) const;
	BtreeItem<T>*											Last( BtreeNode<T>* node ) const;
	BtreeItem<T>*											FindItem( BtreeNode<T>** node, BtreeItem<T>** pos, const T& elem, Bool recurse );
	BtreeItem<T>*											Insert( BtreeNode<T>* node, BtreeItem<T>* pos, const T& elem );
	void													Link( BtreeNode<T>* node, BtreeItem<T>* pos, BtreeItem<T>* item );
	void													Link( BtreeItem<T>* parent, BtreeNode<T>* child );
	void													Split( BtreeNode<T>* nodeLeft );
	void													Remove( BtreeItem<T>* item );
	void													Unlink( BtreeItem<T>* item );
	void													MergeLeft( BtreeNode<T>* nodeLeft, BtreeNode<T>* nodeRight );
	void													MergeRight( BtreeNode<T>* nodeLeft, BtreeNode<T>* nodeRight );
	void													BalanceLeaf( BtreeNode<T>* node, Bool leaf );
	void													BalanceNode( BtreeNode<T>* node );
	void													Update( BtreeNode<T>* node );
	void													Delete( BtreeNode<T>* node );

	Btree( const Btree<T,A>& other );
	Btree<T,A>&												operator=( const Btree<T,A>& other );
};


#include "Btree.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_BTREE_
