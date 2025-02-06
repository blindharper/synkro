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
// Purpose: Implements graphics device description.
//==============================================================================
#include "config.h"
#include <gfx/GraphicsDeviceDesc.h>


namespace synkro
{


namespace gfx
{


GraphicsDeviceDesc::GraphicsDeviceDesc() :
	Type( GraphicsDeviceType::Unknown ),
	LevelMajor( 0 ),
	LevelMinor( 0 ),
	TopDown( false ),
	Tesselation( false ),
	GeometryStage( false ),
	OutputBuffer( false ),
	RenderTargetCount( 0 )
{
}

GraphicsDeviceDesc::GraphicsDeviceDesc( const lang::String& name, const GraphicsDeviceType& type ) :
	Name( name ),
	Type( type ),
	LevelMajor( 0 ),
	LevelMinor( 0 ),
	TopDown( false ),
	Tesselation( false ),
	GeometryStage( false ),
	OutputBuffer( false ),
	RenderTargetCount( 0 )
{
}


} // gfx


} // synkro
