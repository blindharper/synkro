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
// Purpose: Defines B-tree node.
//==============================================================================
#ifndef _SYNKRO_LANG_BTREENODE_
#define _SYNKRO_LANG_BTREENODE_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data structure representing an item of a B-tree.
template <class T>
class BtreeItem;


// Data structure representing a node of a B-tree.
template <class T>
class BtreeNode
{
public:
	BtreeItem<T>*	parent;
	BtreeItem<T>*	first;
	BtreeItem<T>*	last;
	UInt			size;

	BtreeNode() :
		parent( nullptr ),
		first( nullptr ),
		size( 0 )
	{
		data.owner = this;
		last = &data;
	}

private:
	BtreeItem<T> data;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_BTREENODE_
