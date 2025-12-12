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
// Purpose: Defines window listener.
//==============================================================================
#ifndef _SYNKRO_WIN_WINDOWLISTENER_
#define _SYNKRO_WIN_WINDOWLISTENER_


#include "config.h"


namespace synkro
{


namespace win
{


/**
 * Window events listener.
 */
iface WindowListener
{
public:
	/**
	 * Handles window resizing.
	 * @param handle Window handle.
	 * @param width New window width.
	 * @param height New window height.
	 */
	virtual void											OnWindowResize( Pointer handle, UInt width, UInt height ) = 0;

	/**
	 * Handles window command.
	 * @param handle Window handle.
	 * @param command Command identifier.
	 */
	virtual void											OnWindowCommand( Pointer handle, UInt command ) = 0;

	/**
	 * Handles window activation.
	 * @param handle Window handle.
	 * @param active Window status.
	 */
	virtual void											OnWindowActivate( Pointer handle, Bool active ) = 0;

	/**
	 * Handles window closing.
	 * @param handle Window handle.
	 * @return True to allow window closing, false to prevent it.
	 */
	virtual Bool											OnWindowClosing( Pointer handle ) = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WINDOWLISTENER_
