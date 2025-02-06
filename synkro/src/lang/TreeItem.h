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
// Purpose: Defines tree item.
//==============================================================================
#ifndef _SYNKRO_LANG_TREEITEM_
#define _SYNKRO_LANG_TREEITEM_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data structure representing leaf of a tree.
template <class T>
class TreeItem
{
public:
	T				value;
	TreeItem<T>*	parent;
	TreeItem<T>*	child;
	TreeItem<T>*	lastChild; // Hint to ease adding to the end of children list.
	TreeItem<T>*	next;
	TreeItem<T>*	prev;

	TreeItem( const T& val = T() ) :
		value( val ),
		parent( 0 ),
		child( 0 ),
		lastChild( 0 ),
		next( 0 ),
		prev( 0 )
	{
	}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_TREEITEM_
