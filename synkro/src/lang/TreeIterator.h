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
// Purpose: Defines tree iterator.
//==============================================================================
#ifndef _SYNKRO_LANG_TREEITERATOR_
#define _SYNKRO_LANG_TREEITERATOR_


#include "config.h"
#include "TreeItem.h"


namespace synkro
{


namespace lang
{


// Iterator for tree elements.
template <class T>
class TreeIterator
{
public:
	// Sets iterator to point to the item.
	TreeIterator( TreeItem<T>* item );

	// Creates default iterator which is initially invalid.
	TreeIterator();

	// Sets iterator to point to the parent element.
	TreeIterator<T>&										operator--();

	// Sets iterator to point to the previous sibling element.
	TreeIterator<T>&										operator--( Int );

	// Sets iterator to point to the first child element.
	TreeIterator<T>&										operator++();

	// Sets iterator to point to the next sibling element.
	TreeIterator<T>&										operator++( Int );

	// Returns true if the iterators point to the same item.
	Bool													operator==( const TreeIterator<T>& other ) const;

	// Returns true if the iterators point to different items.
	Bool													operator!=( const TreeIterator<T>& other ) const;

	// Provides access to the pointed element.
	T&														operator*() const;

	// Provides access to the pointed element.
	T&														operator->() const;

	// Returns true if the iterator points to a valid element.
	Bool													IsValid() const;

	// Returns underlying item.
	TreeItem<T>*											Item() const;

private:
	TreeItem<T>*											_item;
};


#include "TreeIterator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_TREEITERATOR_
