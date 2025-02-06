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
// Purpose: Logical rectangle implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RECTEX_
#define _SYNKRO_GFX_RECTEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IRect.h>


namespace synkro
{


namespace gfx
{


// Logical scissor rectangle implementation.
class RectEx :
	public core::ObjectImpl<IRect>
{
public:
	// Constructor.
	RectEx( IRect* rect );

	// IRect methods.
	void													Bind();
	void													SetBounds( Int left, Int top, Int right, Int bottom );
	void													SetLocation( Int left, Int top );
	void													SetSize( UInt width, UInt height );
	void													GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const;
	void													GetLocation( Int& left, Int& top ) const;
	void													GetSize( UInt& width, UInt& height ) const;

private:
	P(IRect)												_rect;
};


#include "RectEx.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RECTEX_
