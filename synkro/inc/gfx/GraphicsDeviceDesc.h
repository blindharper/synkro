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
// Purpose: Defines graphics device description.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSDEVICEDESC_
#define _SYNKRO_GFX_GRAPHICSDEVICEDESC_


#include "config.h"
#include <gfx/GraphicsDeviceType.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics device description.
 */
class SYNKRO_API GraphicsDeviceDesc
{
public:
	/** Creates default device description. */
	GraphicsDeviceDesc();

	/** Creates device description with the specified properties. */
	GraphicsDeviceDesc( const lang::String& name, const GraphicsDeviceType& type );

	/** User-friendly device name. */
	lang::String											Name;

	/** Device type. */
	GraphicsDeviceType										Type;

	/** Major feature level. */
	UInt													LevelMajor;

	/** Minor feature level. */
	UInt													LevelMinor;

	/** Indicates whether the screen should be reversed. */
	Bool													TopDown;

	/** Indicates whether tesselation is supported. */
	Bool													Tesselation;

	/** Indicates whether geometry stage is enabled. */
	Bool													GeometryStage;

	/** Indicates whether output buffers are enabled. */
	Bool													OutputBuffer;

	/** Number of simultaneously active rendering targets supported by the device. */
	UInt													RenderTargetCount;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSDEVICEDESC_
