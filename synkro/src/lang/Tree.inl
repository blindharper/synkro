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
// Purpose: Defines generic tree container.
//==============================================================================
template <class T, class A>
SYNKRO_INLINE Tree<T,A>::Tree( const A& alloc ) :
	_alloc( alloc ),
	_root( nullptr )
{
}

template <class T, class A>
SYNKRO_INLINE Tree<T,A>::Tree( const Tree<T,A>& other ) :
	_alloc( other._alloc )
{
	if ( other._root )
	{
		Copy( other );
	}
}

template <class T, class A>
SYNKRO_INLINE Tree<T,A>::~Tree()
{
	Clear();
}

template <class T, class A>
SYNKRO_INLINE Tree<T,A>& Tree<T,A>::operator=( const Tree<T,A>& other )
{
	if ( this != &other )
	{
		Clear();
		_alloc = other._alloc;
		if ( other._root )
		{
			Copy( other );
		}
	}
	return *this;
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Find( const TreeIterator<T>& item, const T& elem, Bool recurse )
{
	if ( !item.IsValid() )
		return 0;

	TreeItem<T>* it = item.Item()->child;

	for ( ; it != 0 ; it = it->next )
	{
		if ( it->value == elem )
			break;

		if ( recurse && (it->child != 0) )
		{
			TreeIterator<T> res = Find( it, elem, recurse );
			if ( res.IsValid() && (*res == elem) )
				return res;
		}
	}

	return it;
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Find( const TreeIterator<T>& item, const T& elem )
{
	return Find( item, elem, false );
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Find( const T& elem, Bool recurse )
{
	return Find( _root, elem, recurse );
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Find( const T& elem )
{
	return Find( _root, elem, false );
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Add( const TreeIterator<T>& item, const T& elem )
{
	TreeItem<T>* parent = item.Item();
	TreeItem<T>* it;

	if ( parent == nullptr )	
	{
		if ( _root != nullptr )
			return Add( _root, elem );

		_root = _alloc.Allocate();
		_root->value = elem;
		return _root;
	}

	it = _alloc.Allocate();
	it->parent = parent;
	it->value = elem;
	it->prev = parent->lastChild;

	if ( parent->child == nullptr )
	{
		parent->child = it;
	}

	if ( parent->lastChild != nullptr )
	{
		parent->lastChild->next = it;
	}

	parent->lastChild = it;

	return it;
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Add( const T& elem )
{
	return Add( _root, elem );
}

template <class T, class A>
SYNKRO_INLINE Bool Tree<T,A>::Remove( const TreeIterator<T>& item )
{
	if ( !item.IsValid() )
		return false;

	if ( !RemoveChildren( item ) )
		return false;

	TreeItem<T>* it = item.Item();

	if ( it->prev != nullptr )
	{
		it->prev->next = it->next;
	}

	if ( it->next != nullptr )
	{
		it->next->prev = it->prev;
	}

	if ( it->parent != nullptr )
	{
		if ( it == it->parent->child )
		{
			it->parent->child = it->next;
		}

		if ( it == it->parent->lastChild )
		{
			it->parent->lastChild = it->prev;
		}
	}

	_alloc.Deallocate( it );

	return true;
}

template <class T, class A>
SYNKRO_INLINE Bool Tree<T,A>::RemoveChildren( const TreeIterator<T>& item )
{
	if ( !item.IsValid() )
		return false;

	TreeItem<T>* it = item.Item();

	if ( it->child != nullptr )
	{
		TreeItem<T>* ch = it->child;
		for ( ; ch != nullptr ; )
		{
			if ( ch->child && !RemoveChildren( ch ) )
				return false;

			TreeItem<T>* tmp = ch;
			ch = ch->next;
			_alloc.Deallocate( tmp );
		}
	}

	it->child = it->lastChild = nullptr;

	return true;
}

template <class T, class A>
SYNKRO_INLINE void Tree<T,A>::Clear()
{
	Remove( _root );
	_root = nullptr;
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::TraverseDepth( const TreeIterator<T>& item )
{
	if ( !item.IsValid() )
		return nullptr;

	TreeItem<T>* it = item.Item();

	// Return first child.
	if ( it->child != nullptr )
		return it->child;

	// Return next sibling.
	if ( it->next != nullptr )
		return it->next;

	// Go up until next valid sibling of the parent item is found.
	if ( it != nullptr )
	{
		it = it->parent;
		for ( ; it != nullptr ; it = it->parent )
		{
			if ( it->next != nullptr )
				return it->next;
		}
	}

	return it;
}

template <class T, class A>
SYNKRO_INLINE TreeIterator<T> Tree<T,A>::Root()
{
	return _root;
}

template <class T, class A>
SYNKRO_INLINE const TreeIterator<T> Tree<T,A>::Root() const
{
	return _root;
}

template <class T, class A>
SYNKRO_INLINE UInt Tree<T,A>::Size() const
{
	return _root ? 1+ChildrenCount( _root, true ) : 0;
}

template <class T, class A>
SYNKRO_INLINE Bool Tree<T,A>::IsEmpty() const
{
	return _root == nullptr;
}

template <class T, class A>
SYNKRO_INLINE UInt Tree<T,A>::Depth( const TreeIterator<T>& item ) const
{
	if ( !item.IsValid() )
		return 0;

	UInt depth = 0;
	TreeItem<T>* it = item.Item();
	
	it = it->parent;
	for ( ; it ; it = it->parent )
	{
		++depth;
	}

	return depth;
}

template <class T, class A>
SYNKRO_INLINE UInt Tree<T,A>::ChildrenCount( const TreeIterator<T>& item, Bool recurse ) const
{
	if ( !item.IsValid() )
		return 0;	

	UInt count = 0;
	TreeItem<T>* ch = item.Item()->child;

	for ( ; ch != nullptr ; ch = ch->next )
	{
		if ( recurse && (ch->child != nullptr) )
		{
			count += ChildrenCount( ch, recurse );
		}
		++count;
	}

	return count;
}

template <class T, class A>
SYNKRO_INLINE UInt Tree<T,A>::ChildrenCount( const TreeIterator<T>& item ) const
{
	return ChildrenCount( item, false );
}

template <class T, class A>
SYNKRO_INLINE Bool Tree<T,A>::HasChildren( const TreeIterator<T>& item ) const
{
	return item.IsValid() && item.Item()->child;
}

template <class T, class A>
SYNKRO_INLINE void Tree<T,A>::Copy( const Tree<T,A>& other )
{
	InternalCopy( &_root, other._root );
}

template <class T, class A>
SYNKRO_INLINE void Tree<T,A>::InternalCopy( TreeItem<T>** dst, TreeItem<T>* src )
{
	assert( src != nullptr );

	if ( src != nullptr )
	{
		*dst = _alloc.Allocate();
		(*dst)->value = src->value;

		TreeItem<T>* it = (*dst)->child;
		TreeItem<T>* ch = src->child;

		for ( ; ch != nullptr; ch = ch->next, it = it->next )
		{
			InternalCopy( &it, ch );
		}
	}
	else
	{
		*dst = nullptr;
	}
}
