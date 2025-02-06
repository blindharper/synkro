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
// Purpose: Defines hash set item.
//==============================================================================
#ifndef _SYNKRO_LANG_SETITEM_
#define _SYNKRO_LANG_SETITEM_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data structure used by the Set implementation.
template <class K>
class SetItem
{
public:
	K			key;
	SetItem<K>*	next;
	Bool		used;

	SetItem() :
		next( nullptr ),
		used( false )
	{
	}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_SETITEM_
