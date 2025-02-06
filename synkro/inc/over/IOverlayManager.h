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
// Purpose: Defines overlay manager.
//==============================================================================
#ifndef _SYNKRO_OVER_IOVERLAYMANAGER_
#define _SYNKRO_OVER_IOVERLAYMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <core/Language.h>
#include <over/FontStyle.h>


namespace synkro
{


namespace over
{


/**
 * Overlay manager.
 */
iface IOverlayManager :
	public core::ISystem
{
public:
	/**
	 * Creates overlay for a virtual rendering window.
	 * @param window Virtual rendering window to draw the overlay to.
	 * @return Created overlay.
	 */
	virtual IOverlay*										CreateOverlay( gfx::IVirtualRenderWindow* window ) = 0;

	/**
	 * Creates off-screen overlay from the plain rendering image.
	 * @param image Plain rendering image to draw the overlay to.
	 * @return Created overlay.
	 * @exception BadArgumentException Image is not a plain rendering image.
	 */
	virtual IOverlay*										CreateOverlay( img::IImage* image ) = 0;

	/**
	 * Creates vector font resource template. Actual font can be obtained from a particular overlay.
	 * @param name Unique font name.
	 * @param language Font language.
	 * @param family Font family name.
	 * @param style Font style.
	 * @param size Font size, in dots.
	 * @exception BadArgumentException Unknown family name.
	 */
	virtual void											CreateFont( const lang::String& name, const core::Language& language, const lang::String& family, const FontStyle& style, UInt size ) = 0;

	/**
	 * Retrieves an overlay for the given rendering window.
	 * @param window Rendering window holding the overlay.
	 * @return Requested overlay, if one exists, or null otherwise.
	 */
	virtual IOverlay*										GetOverlay( gfx::IRenderWindow* window ) const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_IOVERLAYMANAGER_
