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
// Purpose: Defines console.
//==============================================================================
#ifndef _SYNKRO_CONS_ICONSOLE_
#define _SYNKRO_CONS_ICONSOLE_


#include "config.h"
#include <core/ISystem.h>
#include <img/Color.h>


namespace synkro
{


namespace cons
{


/**
 * Console. Provides means to manage application from command line.
 */
iface IConsole :
	public core::ISystem
{
public:
	/**
	 * Clears console buffer.
	 */
	virtual void											Clear() = 0;

	/**
	 * Activates or deactivates the console.
	 * @param active Set to true to activate the console, or to false to deactivate it.
	 */
	virtual void											Activate( Bool active ) = 0;

	/**
	 * Enables or disables echo.
	 * @param enable Set to true to enable echo, or to false to disable it.
	 */
	virtual void											EnableEcho( Bool enable ) = 0;

	/**
	 * Enables or disables sound.
	 * @param enable Set to true to enable sound, or to false to disable it.
	 */
	virtual void											EnableSound( Bool enable ) = 0;

	/**
	 * Sets console text color.
	 * @param color Console text color.
	 */
	virtual void											SetTextColor( const img::Color& color ) = 0;

	/**
	 * Sets degree of console opacity [1-100]. Default is 100.
	 * @param opacity Opacity degree.
	 */
	virtual void											SetOpacity( UInt opacity ) = 0;

	/**
	 * Sets scripting machine to which scripts are re-directed.
	 * @param machine Scripting machine.
	 */
	virtual void											SetScriptMachine( script::IScriptMachine* machine ) = 0;

	/**
	 * Outputs help on the console commands.
	 * @param command Optional command to display help on.
	 */
	virtual void											ShowHelp( const lang::String& command ) = 0;

	/**
	 * Outputs a message to the console.
	 * @param message Message to print.
	 */
	virtual void											Echo( const lang::String& message ) = 0;

	/**
	 * Indicates if the console is currently active.
	 */
	virtual Bool											IsActive() const = 0;

	/**
	 * Indicates if the echo is currently enabled.
	 */
	virtual Bool											IsEchoEnabled() const = 0;

	/**
	 * Indicates if the sound is currently enabled.
	 */
	virtual Bool											IsSoundEnabled() const = 0;

	/**
	 * Retrieves text color.
	 * @param [out] color Text color.
	 */
	virtual void											GetTextColor( img::Color& color ) const = 0;

	/**
	 * Retrieves degree of console opacity [1-100]. 
	 */
	virtual UInt											GetOpacity() const = 0;

	/**
	 * Retrieves scripting machine to which scripts are re-directed.
	 */
	virtual script::IScriptMachine*							GetScriptMachine() const = 0;
};


} // cons


} // synkro


#endif // _SYNKRO_CONS_ICONSOLE_
