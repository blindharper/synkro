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
// Purpose: Defines progress listener.
//==============================================================================
#ifndef _SYNKRO_CORE_PROGRESSLISTENER_
#define _SYNKRO_CORE_PROGRESSLISTENER_


#include "config.h"


namespace synkro
{


namespace core
{


/**
 * Progress listener.
 */
iface ProgressListener
{
public:
	/**
	 * Handles 'Progress Begin' event.
	 * @param context Event context.
	 * @param total Estimated operation length.
	 */
	virtual void											OnProgressBegin( IObject* context, UInt total ) = 0;

	/**
	 * Handles 'Progress Update' event.
	 * @param context Event context.
	 * @param current Current operation progress.
	 */
	virtual void											OnProgressUpdate( IObject* context, UInt current ) = 0;

	/**
	 * Handles 'Progress End' event.
	 * @param context Event context.
	 */
	virtual void											OnProgressEnd( IObject* context ) = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_PROGRESSLISTENER_
