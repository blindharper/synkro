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
template <class T, class A>
SYNKRO_INLINE Btree<T,A>::Btree( UInt nodeSize, const A& alloc ) :
	_allocItem( Allocator<BtreeItem<T> >( __FILE__, __LINE__ ) ),
	_alloc( alloc ),
	_root( nullptr ),
	_nodeSize( nodeSize ),
	_size( 0 ),
	_depth( 0 )
{
	assert( _nodeSize > 1 );

	_minSize = _nodeSize - (_nodeSize+1)/2;
}

template <class T, class A>
SYNKRO_INLINE Btree<T,A>::~Btree()
{
	Clear();
}

template <class T, class A>
SYNKRO_INLINE BtreeIterator<T> Btree<T,A>::Insert( const T& elem )
{
	BtreeNode<T>* node = Root(); BtreeItem<T>* pos = nullptr;
	BtreeItem<T>* item = FindItem( &node, &pos, elem, true );
	return BtreeIterator<T>( (item == 0) ? Insert(node, pos, elem) : item );
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Remove( const T& elem )
{
	BtreeNode<T>* node = Root(); BtreeItem<T>* pos = nullptr;
	BtreeItem<T>* item = FindItem( &node, &pos, elem, true );
	if ( item != nullptr )
	{
		Remove( item );
	}
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Clear()
{
	if ( _root != nullptr )
	{
		Delete( _root );
		_alloc.Deallocate( _root );
		_root = nullptr;
	}
	_size = 0;
	_depth = 0;
}

template <class T, class A>
SYNKRO_INLINE BtreeIterator<T> Btree<T,A>::Find( const T& elem )
{
	BtreeNode<T>* node = Root(); BtreeItem<T>* pos = nullptr;
	BtreeItem<T>* item = FindItem( &node, &pos, elem, true );
	return BtreeIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE BtreeIterator<T> Btree<T,A>::First() const
{
	if ( _root == nullptr )
		return 0;

	BtreeItem<T>* item = First( _root );
	return BtreeIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE BtreeIterator<T> Btree<T,A>::Last() const
{
	if ( _root == nullptr )
		return 0;

	BtreeItem<T>* item = Last( _root );
	return BtreeIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE UInt Btree<T,A>::Depth() const
{
	return _depth;
}

template <class T, class A>
SYNKRO_INLINE UInt Btree<T,A>::Size() const
{
	return _size;
}

template <class T, class A>
SYNKRO_INLINE UInt Btree<T,A>::NodeSize() const
{
	return _nodeSize;
}

template <class T, class A>
SYNKRO_INLINE Bool Btree<T,A>::IsEmpty() const
{
	return (_root == nullptr) || (_root->size == 0);
}

template <class T, class A>
SYNKRO_INLINE BtreeNode<T>* Btree<T,A>::Root() const
{
	if ( _root == nullptr )
	{
		_root = _alloc.Allocate( 1 );
	}

	return _root;
}

template <class T, class A>
SYNKRO_INLINE BtreeItem<T>* Btree<T,A>::First( BtreeNode<T>* node ) const
{
	return (node->first != nullptr) && (node->first->child != nullptr) ? First(node->first->child) : node->first;
}

template <class T, class A>
SYNKRO_INLINE BtreeItem<T>* Btree<T,A>::Last( BtreeNode<T>* node ) const
{
	return (node->last->child != nullptr) ? Last(node->last->child) : node->last->prev;
}

template <class T, class A>
SYNKRO_INLINE BtreeItem<T>* Btree<T,A>::FindItem( BtreeNode<T>** node, BtreeItem<T>** pos, const T& elem, Bool recurse )
{
	BtreeItem<T>* item = (*node)->first;
	*pos = nullptr;

	for ( ; item != nullptr; )
	{
		if ( item != (*node)->last )
		{
			// If the element is already there, return it.
			if ( item->value == elem )
				return item;

			if ( elem < item->value )
			{
				if ( recurse )
				{
					if ( item->child != nullptr )
					{
						*node = item->child;
						return FindItem( node, pos, elem, true );
					}
				}
				return nullptr;
			}

			*pos = item;
		}

		// Go to the next element of the node.
		item = item->next;
	}

	// Search in child nodes.
	if ( recurse )
	{
		if ( (item != nullptr) && (item->child != nullptr) )
		{
			*node = item->child;
			return FindItem( node, pos, elem, true );
		}
		else if ( (item == nullptr) && (*node)->last->child != nullptr )
		{
			*node = (*node)->last->child;
			return FindItem( node, pos, elem, true );
		}
	}

	return item;
}

template <class T, class A>
SYNKRO_INLINE BtreeItem<T>* Btree<T,A>::Insert( BtreeNode<T>* node, BtreeItem<T>* pos, const T& elem )
{
	BtreeItem<T>* item = _allocItem.Allocate( 1 );
	item->value = elem;
	_size += 1;
	Link( node, pos, item );
	if ( node->size > _nodeSize )
	{
		Split( node );
	}
	return item;
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Link( BtreeNode<T>* node, BtreeItem<T>* pos, BtreeItem<T>* item )
{
	if ( pos != nullptr )
	{
		pos->next->prev = item;
		item->next = pos->next;
		pos->next = item;
	}
	else
	{
		item->next = node->first;
		if ( node->first != nullptr )
		{
			node->first->prev = item;
		}
		node->first = item;
	}
	node->size += 1;
	item->prev = pos;
	item->owner = node;
	if ( node->size == 1 )
	{
		node->last->prev = node->first;
		node->first->next = node->last;
	}
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Link( BtreeItem<T>* parent, BtreeNode<T>* child )
{
	child->parent = parent;
	parent->child = child;
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Split( BtreeNode<T>* nodeLeft )
{
	// Unlink median element.
	BtreeItem<T>* itemMedian = nodeLeft->first;
	UInt cnt = _nodeSize/2;
	for ( UInt i = 0; i < cnt; ++i )
	{
		itemMedian = itemMedian->next;
	}
	Unlink( itemMedian );

	// Split the node into 2 parts.
	BtreeNode<T>* nodeRight = _alloc.Allocate( 1 );
	nodeRight->first = itemMedian->next;
	nodeRight->first->prev = nullptr;
	nodeRight->size = (_nodeSize+1)/2;
	nodeLeft->size = _nodeSize - nodeRight->size;
	if ( nodeLeft->last->child != nullptr )
	{
		nodeRight->last->child = nodeLeft->last->child;
		nodeRight->last->child->parent = nodeRight->last;
	}
	Update( nodeRight );
	itemMedian->prev->next = nodeLeft->last;
	nodeLeft->last->prev = itemMedian->prev;
	nodeLeft->last->owner = nodeLeft;

	// Create new top node, if needed.
	BtreeNode<T>* nodeTop = (nodeLeft->parent != nullptr) ? nodeLeft->parent->owner : nullptr;
	if ( nodeTop == nullptr )
	{
		nodeTop = _alloc.Allocate( 1 );
		_root = nodeTop;
		_depth += 1;
	}

	// Insert median item into the top node.
	BtreeItem<T>* pos = nullptr;
	FindItem( &nodeTop, &pos, itemMedian->value, false );
	Link( nodeTop, pos, itemMedian );

	// Re-link median's child to left node.
	nodeLeft->last->child = itemMedian->child;
	if ( nodeLeft->last->child != nullptr )
	{
		nodeLeft->last->child->parent = nodeLeft->last;
	}

	// Create vertical links between nodes.
	nodeLeft->parent = itemMedian;
	itemMedian->child = nodeLeft;
	nodeRight->parent = itemMedian->next;
	itemMedian->next->child = nodeRight;

	// Handle top node overflow.
	if ( nodeTop->size > _nodeSize )
	{
		Split( nodeTop );
	}
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Remove( BtreeItem<T>* item )
{
	assert( item != nullptr );

	BtreeNode<T>* node = item->owner;
	BtreeItem<T>* prev = item->prev;
	BtreeItem<T>* next = item->next;

	// Delete item.
	Unlink( item );

	// Re-balance tree, if needed.
	if ( item->child != nullptr )	// Internal or root node
	{
		BtreeItem<T>* leftChild = Last( item->child );
		BtreeItem<T>* rightChild = First( next->child );
		if ( leftChild->owner->size > _minSize )
		{
			// Borrow element from leaf node.
			BtreeItem<T>* itemNext = leftChild->next;
			BtreeItem<T>* itemPrev = leftChild->prev;
			BtreeNode<T>* itemOwner = leftChild->owner;

			Unlink( leftChild );
			Link( node, prev, leftChild );
			leftChild->child = item->child;
			item->child->parent = leftChild;

			// Re-balance leaf node.
			BalanceLeaf( itemOwner, true );
		}
		else
		{
			// Borrow element from leaf node.
			BtreeItem<T>* itemNext = rightChild->next;
			BtreeItem<T>* itemPrev = rightChild->prev;
			BtreeNode<T>* itemOwner = rightChild->owner;

			Unlink( rightChild );
			Link( node, prev, rightChild );
			rightChild->child = item->child;
			item->child->parent = rightChild;

			// Re-balance leaf node.
			BalanceLeaf( itemOwner, true );
		}
	}
	else if ( node->parent != nullptr ) // Leaf node
	{
		BalanceLeaf( node, true );
	}

	// Deallocate item.
	_size -= 1;
	_allocItem.Deallocate( item );
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Unlink( BtreeItem<T>* item )
{
	assert( item != nullptr );
	assert( item->next != nullptr );

	BtreeNode<T>* node = item->owner;
	item->next->prev = item->prev;
	if ( item->prev != nullptr )
	{
		item->prev->next = item->next;
	}
	else
	{
		node->first = node->first->next;
	}
	node->size -= 1;
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::MergeLeft( BtreeNode<T>* nodeLeft, BtreeNode<T>* nodeRight )
{
	assert( nodeLeft != nullptr );
	assert( nodeRight != nullptr );
	
	nodeLeft->last->prev->next = nodeRight->first;
	nodeRight->first->prev = nodeLeft->last->prev;
	nodeLeft->last->child = nodeRight->last->child;
	if ( nodeLeft->last->child != nullptr )
	{
		nodeLeft->last->child->parent = nodeLeft->last;
	}
	nodeLeft->size += nodeRight->size;
	Update( nodeLeft );
	_alloc.Deallocate( nodeRight );
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::MergeRight( BtreeNode<T>* nodeLeft, BtreeNode<T>* nodeRight )
{
	assert( nodeLeft != nullptr );
	assert( nodeRight != nullptr );
	
	nodeLeft->last->prev->next = nodeRight->first;
	nodeRight->first->prev = nodeLeft->last->prev;
	nodeRight->first = nodeLeft->first;
	nodeRight->size += nodeLeft->size;
	Update( nodeRight );
	_alloc.Deallocate( nodeLeft );
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::BalanceLeaf( BtreeNode<T>* node, Bool leaf )
{
	if ( node->size >= _minSize )
		return;

	BtreeItem<T>* parent = node->parent;
	BtreeItem<T>* parentPrev = node->parent->prev;
	BtreeItem<T>* parentNext = node->parent->next;
	BtreeNode<T>* nodeTop = node->parent->owner;
	BtreeNode<T>* nodeLeft = (parentPrev != nullptr) ? parentPrev->child : nullptr;
	BtreeNode<T>* nodeRight = (parentNext != nullptr) ? parentNext->child : nullptr;
	if ( (nodeLeft != nullptr) && (nodeLeft->size > _minSize) )
	{
		// Borrow separator item.
		Unlink( parentPrev );
		Link( node, nullptr, parentPrev );
		BtreeNode<T>* leftChild = nodeLeft->last->child;

		// Re-link child.
		parentPrev->child = leaf ? nullptr : leftChild;
		if ( parentPrev->child != nullptr )
		{
			parentPrev->child->parent = parentPrev;
		}

		// Borrow last item from left sibling.
		BtreeItem<T>* nodeLeftLast = nodeLeft->last->prev;
		Unlink( nodeLeftLast );

		BtreeItem<T>* pos = nullptr;
		FindItem( &nodeTop, &pos, nodeLeftLast->value, false );
		Link( nodeTop, pos, nodeLeftLast );

		// Link last item's child.
		nodeLeft->last->child = leaf ? nullptr : nodeLeftLast->child;
		if ( nodeLeft->last->child != nullptr )
		{
			nodeLeft->last->child->parent = nodeLeft->last;
		}

		// Link borrowed item to its former owner.
		Link( nodeLeftLast, nodeLeft );
	}
	else if ( (nodeRight != nullptr) && (nodeRight->size > _minSize) )
	{
		// Borrow separator item.
		Unlink( parent );
		Link( node, node->last->prev, parent );

		BtreeNode<T>* rightChild = nodeRight->first->child;
		parent->child = leaf ? nullptr : parent->child->last->child;
		if ( parent->child != nullptr )
		{
			parent->child->parent = parent;
		}

		// Re-link child.
		parent->next->child = leaf ? nullptr : rightChild;
		if ( parent->next->child != nullptr )
		{
			parent->next->child->parent = parent->next;
		}

		// Borrow first item from right sibling.
		BtreeItem<T>* nodeRightFirst = nodeRight->first;
		Unlink( nodeRightFirst );

		BtreeItem<T>* pos = nullptr;
		FindItem( &nodeTop, &pos, nodeRightFirst->value, false );
		Link( nodeTop, pos, nodeRightFirst );
		Link( nodeRightFirst, node );
	}
	else if ( nodeRight != nullptr )
	{
		// Borrow separator item.
		Unlink( parent );
		Link( node, node->last->prev, parent );
		parent->child = leaf ? nullptr : parent->child->last->child;
		if ( parent->child != nullptr )
		{
			parent->child->parent = parent;
		}

		// Merge with right node.
		MergeLeft( node, nodeRight );
		parentNext->child = node;
		node->parent = parentNext;

		// Re-balance top node.
		BalanceNode( nodeTop );
	}
	else if ( nodeLeft != nullptr )
	{
		// Borrow separator item.
		Unlink( parentPrev );
		Link( node, nullptr, parentPrev );
		parentPrev->child = leaf ? nullptr : parentPrev->child->last->child;
		if ( parentPrev->child != nullptr )
		{
			parentPrev->child->parent = parentPrev;
		}

		// Merge with left node.
		MergeRight( nodeLeft, node );

		// Re-balance top node.
		BalanceNode( nodeTop );
	}
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::BalanceNode( BtreeNode<T>* node )
{
	assert( node != nullptr );

	if ( node->parent == nullptr )
	{
		assert( node == _root );

		if ( node->size == 0 )
		{
			// Replace empty root with its only child.
			_root = node->last->child;
			_root->parent = nullptr;
			_depth -= 1;

			// Deallocate empty node.
			_alloc.Deallocate( node );
		}
	}
	else
	{
		BalanceLeaf( node, false );
	}
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Update( BtreeNode<T>* node )
{
	assert( node != nullptr );
	assert( node->first != nullptr );

	BtreeItem<T>* item = node->first;
	for ( ; item != nullptr; item = item->next )
	{
		item->owner = node;
		if ( item->next != nullptr )
		{
			node->last->prev = item;
		}
	}
	node->last->prev->next = node->last;
}

template <class T, class A>
SYNKRO_INLINE void Btree<T,A>::Delete( BtreeNode<T>* node )
{
	assert( node != nullptr );

	BtreeItem<T>* item = node->first;
	for ( ; item != nullptr; )
	{
		if ( item->child != nullptr )
		{
			Delete( item->child );
			_alloc.Deallocate( item->child );
		}
		BtreeItem<T>* tmp = item;
		item = item->next;
		if ( tmp != node->last )
		{
			_allocItem.Deallocate( tmp );
		}
	}
}
