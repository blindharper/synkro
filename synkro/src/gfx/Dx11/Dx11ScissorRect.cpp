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
// Purpose: DX11 based scissor rectangle implementation.
//==============================================================================
#include "config.h"
#include "Dx11ScissorRect.h"


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11ScissorRect::Dx11ScissorRect( Dx11Context* context, Int left, Int top, Int right, Int bottom ) :
	RectImpl<IRect>( left, top, right, bottom ),
	_context( context )
{
}

void Dx11ScissorRect::Bind()
{
	if ( _dirty )
	{
		_rc.left	= _rect.Left;
		_rc.top		= _rect.Top;
		_rc.right	= _rect.Right;
		_rc.bottom	= _rect.Bottom;
		_dirty		= false;
	}
	Dx11Lock( _context );
	_context->RSSetScissorRects( 1, &_rc );
}


} // gfx


} // synkro
