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
// Purpose: Defines hash set iterator.
//==============================================================================
#ifndef _SYNKRO_LANG_SETITERATOR_
#define _SYNKRO_LANG_SETITERATOR_


#include "config.h"
#include "SetItem.h"


namespace synkro
{


namespace lang
{


// Forward iterator of Set elements. 
template <class K>
class SetIterator
{
public:
	// Creates iterator for given map pair.
	SetIterator( SetItem<K>* data, Int cap, Int index );

	// Creates default iterator which is initially invalid.
	SetIterator();

	// Sets the iterator to point to the next element.
	SetIterator<K>&											operator++();

	// Returns true if the iterators point to the same item.
	Bool													operator==( const SetIterator<K>& other ) const;

	// Returns true if the iterators point to different items.
	Bool													operator!=( const SetIterator<K>& other ) const;

	// Return item key.
	const K&												Key() const;

private:
	SetItem<K>*												_data;
	Int														_last;
	Int														_index;
	SetItem<K>*												_item;
};


#include "SetIterator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_SETITERATOR_
