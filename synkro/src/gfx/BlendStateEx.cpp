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
// Purpose: Blend state implementation.
//==============================================================================
#include "config.h"
#include "BlendStateEx.h"


//------------------------------------------------------------------------------

using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


BlendStateEx::BlendStateEx() :
	_enabled( false ),
	_colorSrcMode( BlendMode::One ),
	_colorDstMode( BlendMode::Zero ),
	_colorBlendOp( BlendOperation::Add ),
	_alphaSrcMode( BlendMode::One ),
	_alphaDstMode( BlendMode::Zero ),
	_alphaBlendOp( BlendOperation::Add ),
	_channels( PixelChannel::All )
{
}

BlendStateEx::BlendStateEx( const BlendStateEx& other ) :
	_enabled( other._enabled ),
	_colorSrcMode( other._colorSrcMode ),
	_colorDstMode( other._colorDstMode ),
	_colorBlendOp( other._colorBlendOp ),
	_alphaSrcMode( other._alphaSrcMode ),
	_alphaDstMode( other._alphaDstMode ),
	_alphaBlendOp( other._alphaBlendOp ),
	_channels( other._channels )
{
}


} // gfx


} // synkro
