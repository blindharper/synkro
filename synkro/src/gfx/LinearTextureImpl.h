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
// Purpose: Generic linear texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_LINEARTEXTUREIMPL_
#define _SYNKRO_GFX_LINEARTEXTUREIMPL_


#include "config.h"
#include "TextureImpl.h"


namespace synkro
{


namespace gfx
{


// Generic linear texture implementation.
template <class T>
class LinearTextureImpl :
	public TextureImpl<T>
{
public:
	// Constructor & destructor.
	LinearTextureImpl( UInt length, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	virtual ~LinearTextureImpl();

	// ITexture methods.
	virtual ILinearTexture*									AsLinear() const;

	// ILinearTexture methods.
	virtual UInt											GetLength() const;

protected:
	UInt													_length;
};


#include "LinearTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINEARTEXTUREIMPL_
