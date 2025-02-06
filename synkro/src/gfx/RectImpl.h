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
// Purpose: Generic rectangle implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RECTIMPL_
#define _SYNKRO_GFX_RECTIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <lang/Rect.h>


namespace synkro
{


namespace gfx
{


// Generic scissor rectangle implementation.
template <class T>
class RectImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RectImpl( Int left, Int top, Int right, Int bottom );
	virtual ~RectImpl();

	// IRect methods.
	virtual void											SetBounds( Int left, Int top, Int right, Int bottom );
	virtual void											SetLocation( Int left, Int top );
	virtual void											SetSize( UInt width, UInt height );
	virtual void											GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const;
	virtual void											GetLocation( Int& left, Int& top ) const;
	virtual void											GetSize( UInt& width, UInt& height ) const;

protected:
	Bool													_dirty;
	lang::Rect												_rect;
};


#include "RectImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RECTIMPL_
