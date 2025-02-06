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
// Purpose: Defines linked list iterator.
//==============================================================================
#ifndef _SYNKRO_LANG_LISTITERATOR_
#define _SYNKRO_LANG_LISTITERATOR_


#include "config.h"
#include "ListItem.h"


namespace synkro
{


namespace lang
{


// Iterator for linked list elements.
template <class T>
class ListIterator
{
public:
	// Sets iterator to point to the item.
	ListIterator( ListItem<T>* item );

	// Creates default iterator which is initially invalid.
	ListIterator();

	// Sets iterator to point to the next list element.
	ListIterator<T>&										operator++();

	// Sets iterator to point to the next list element.
	ListIterator<T>											operator++( Int );

	// Sets iterator to point to the previous list element.
	ListIterator<T>&										operator--();

	// Sets iterator to point to the previous list element.
	ListIterator<T>											operator--( Int );

	// Returns true if the iterators point to the same item.
	Bool													operator==( const ListIterator<T>& other ) const;

	// Returns true if the iterators point to different items.
	Bool													operator!=( const ListIterator<T>& other ) const;

	// Provides access to the pointed element.
	T&														operator*() const;

	// Provides access to the pointed element.
	T&														operator->() const;

	// Returns true if the iterator points to a valid element.
	Bool													IsValid() const;

	// Returns underlying item.
	ListItem<T>*											Item() const;

private:
	ListItem<T>*											_item;
};


#include "ListIterator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_LISTITERATOR_
