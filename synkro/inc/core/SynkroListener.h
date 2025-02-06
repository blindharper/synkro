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
// Purpose: Defines Synkro listener.
//==============================================================================
#ifndef _SYNKRO_CORE_SYNKROLISTENER_
#define _SYNKRO_CORE_SYNKROLISTENER_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace core
{


/**
 * Synkro events listener.
 */
iface SynkroListener
{
public:
	/**
	 * Handles Synkro initialization. Used to create scene, nodes, etc.
	 */
	virtual void											OnSynkroInitialize() = 0;

	/**
	 * Handles main loop iteration.
	 * @param delta Time, in seconds, elapsed since the last update.
	 */
	virtual void											OnSynkroUpdate( Double delta ) = 0;

	/**
	 * Handles exception caught by Synkro.
	 * @param ex Exception to be handled.
	 * @return True if the exception has been handled by the listener, or false otherwise.
	 */
	virtual Bool											OnSynkroException( const lang::Exception& ex ) = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_SYNKROLISTENER_
