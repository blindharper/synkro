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
// Purpose: Generic plain depth texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINDEPTHTEXTUREIMPL_
#define _SYNKRO_GFX_PLAINDEPTHTEXTUREIMPL_


#include "config.h"
#include "DepthTextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic plain depth texture implementation.
template <class T>
class PlainDepthTextureImpl :
	public DepthTextureImpl<T>
{
public:
	// Constructors & destructor.
	PlainDepthTextureImpl( UInt width, UInt height, const DepthFormat& format, Bool stencil );
	virtual ~PlainDepthTextureImpl();

	// IDepthTexture methods.
	virtual IPlainDepthTexture*								AsPlain() const;

	// IPlainDepthTexture methods.
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;

protected:
	UInt													_width;
	UInt													_height;
};


#include "PlainDepthTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINDEPTHTEXTUREIMPL_
