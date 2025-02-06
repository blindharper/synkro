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
// Purpose: Defines B-tree item.
//==============================================================================
#ifndef _SYNKRO_LANG_BTREEITEM_
#define _SYNKRO_LANG_BTREEITEM_


#include "config.h"
#include "BtreeNode.h"


namespace synkro
{


namespace lang
{


// Data structure representing an item of a B-tree.
template <class T>
class BtreeItem
{
public:
	T				value;
	BtreeNode<T>*	owner;
	BtreeNode<T>*	child;
	BtreeItem<T>*	next;
	BtreeItem<T>*	prev;

	BtreeItem( const T& val = T() ) :
		value( val ),
		owner( nullptr ),
		child( nullptr ),
		next( nullptr ),
		prev( nullptr )
	{
	}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_BTREEITEM_
