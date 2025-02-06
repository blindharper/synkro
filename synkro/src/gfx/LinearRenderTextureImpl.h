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
// Purpose: Generic linear rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_LINEARRENDERTEXTUREIMPL_
#define _SYNKRO_GFX_LINEARRENDERTEXTUREIMPL_


#include "config.h"
#include "RenderTextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic linear rendering texture implementation.
template <class T>
class LinearRenderTextureImpl :
	public RenderTextureImpl<T>
{
public:
	// Constructor & destructor.
	LinearRenderTextureImpl( UInt length, const img::PixelFormat& format );
	virtual ~LinearRenderTextureImpl();

	// ILinearRenderTexture methods.
	virtual UInt											GetLength() const;

protected:
	UInt													_length;
};


#include "LinearRenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINEARRENDERTEXTUREIMPL_
