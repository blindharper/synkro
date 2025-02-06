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
// Purpose: Defines hash map iterator.
//==============================================================================
#ifndef _SYNKRO_LANG_MAPITERATOR_
#define _SYNKRO_LANG_MAPITERATOR_


#include "config.h"
#include "MapPair.h"


namespace synkro
{


namespace lang
{


// Forward iterator of Map elements. 
template <class K, class T> 
class MapIterator
{
public:
	// Creates iterator for given map pair.
	MapIterator( MapPair<K,T>* data, Int cap, Int index );

	// Creates default iterator which is initially invalid.
	MapIterator();

	// Sets the iterator to point to the next element.
	MapIterator<K,T>&										operator++();

	// Returns true if the iterators point to the same item.
	Bool													operator==( const MapIterator<K,T>& other ) const;

	// Returns true if the iterators point to different items.
	Bool													operator!=( const MapIterator<K,T>& other ) const;

	// Return item key.
	const K&												Key() const;

	// Return item value.
	T&														Value() const;

private:
	MapPair<K,T>*											_data;
	Int														_last;
	Int														_index;
	MapPair<K,T>*											_item;
};


#include "MapIterator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_MAPITERATOR_
