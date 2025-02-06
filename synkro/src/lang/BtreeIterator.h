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
// Purpose: Defines B-tree iterator.
//==============================================================================
#ifndef _SYNKRO_LANG_BTREEITERATOR_
#define _SYNKRO_LANG_BTREEITERATOR_


#include "config.h"
#include "BtreeItem.h"


namespace synkro
{


namespace lang
{


// Iterator for B-tree elements.
template <class T>
class BtreeIterator
{
public:
	BtreeItem<T>*											_item;

	// Sets iterator to point to the item.
	BtreeIterator( BtreeItem<T>* item );

	// Creates default iterator which is initially invalid.
	BtreeIterator();

	// Returns true if the iterator points to a valid element.
	Bool													IsValid() const;

	// Returns true if the iterators point to the same item.
	Bool													operator==( const BtreeIterator<T>& other ) const;

	// Returns true if the iterators point to different items.
	Bool													operator!=( const BtreeIterator<T>& other ) const;

	// Provides access to the pointed element.
	T&														operator*() const;

	// Sets iterator to point to the next element.
	BtreeIterator<T>&										operator++( Int );
};


#include "BtreeIterator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_BTREEITERATOR_
