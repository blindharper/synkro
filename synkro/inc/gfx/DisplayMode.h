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
// Purpose: Defines display mode.
//==============================================================================
#ifndef _SYNKRO_GFX_DISPLAYMODE_
#define _SYNKRO_GFX_DISPLAYMODE_


#include "config.h"
#include <gfx/Aspect.h>
#include <gfx/DisplayModeFormat.h>


namespace synkro
{


namespace gfx
{


/**
 * Display mode.
 */
class SYNKRO_API DisplayMode
{
public:
	/** Smallest display mode. */
	static const DisplayMode								Minimum;

	/** Display mode below medium. */
	static const DisplayMode								BelowMedium;

	/** Middle display mode. */
	static const DisplayMode								Medium;

	/** Display mode above medium. */
	static const DisplayMode								AboveMedium;

	/** Greatest display mode. */
	static const DisplayMode								Maximum;

	/** Creates display mode with the specified parameters. */
	DisplayMode( UInt width, UInt height, UInt depth, Bool fullscreen );

	/** Creates display mode with the specified parameters. */
	DisplayMode( const lang::String& mode, Bool fullscreen );

	/** Creates windowed display mode of the specified dimensions. */
	DisplayMode( UInt width, UInt height );

	/** Creates default display mode. */
	DisplayMode();

	/** Returns true if two display modes are equal. */
	Bool													operator==( const DisplayMode& other ) const;

	/** Returns true if two display modes are not equal. */
	Bool													operator!=( const DisplayMode& other ) const;

	/** Returns mode index. Only meaningful for standard modes. */
	UInt													Index() const;

	/** Returns width to height ratio. */
	Float													AspectFactor() const;

	/**
	 * Converts display mode to a string of a given format.
	 * @param format Display mode format.
	 */
	lang::String											ToString( const DisplayModeFormat& format ) const;

	/** Converts display mode to a string. */
	lang::String											ToString() const;

	/** Retrieves the number of display modes supported by the graphics device. */
	static UInt												GetModeCount();

	/** Retrieves display mode by index. */
	static void												GetMode( UInt index, DisplayMode& mode );

	/** Retrieves the number of display modes with the given aspect supported by the graphics device. */
	static UInt												GetModeCount( const Aspect& aspect );

	/** Retrieves display mode with the given aspect by index. */
	static void												GetMode( UInt index, const Aspect& aspect, DisplayMode& mode );

	/** Frame buffer width. */
	UInt													Width;

	/** Frame buffer height. */
	UInt													Height;

	/** Frame buffer color depth. */
	UInt													Depth;

	/** Specifies whether to perform rendering in full screen. */
	Bool													Fullscreen;

	/** Width to height ratio constant. */
	Aspect													AspectRatio;
};


/**
 * Compares two display modes.
 * @param first First display mode.
 * @param second Second display mode.
 * @return true if the first display mode is better than the second one.
 */
SYNKRO_API Bool operator<( const DisplayMode& first, const DisplayMode& second );


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DISPLAYMODE_
