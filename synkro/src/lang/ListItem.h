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
// Purpose: Defines linked list item.
//==============================================================================
#ifndef _SYNKRO_LANG_LISTITEM_
#define _SYNKRO_LANG_LISTITEM_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data structure representing link of a linked list.
template <class T>
class ListItem
{
public:
	T				value;	
	ListItem<T>*	prev;
	ListItem<T>*	next;

	ListItem( const T& val = T() ) :
		value( val ),
		prev( nullptr ),
		next( nullptr )
	{
	}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_LISTITEM_
