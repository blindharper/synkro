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
// Purpose: Defines queue item.
//==============================================================================
#ifndef _SYNKRO_LANG_QUEUEITEM_
#define _SYNKRO_LANG_QUEUEITEM_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data structure representing queue item.
template <class T>
class QueueItem
{
public:
	T	value;

	QueueItem( const T& val = T() ) :
		value( val )
	{
	}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_QUEUEITEM_
