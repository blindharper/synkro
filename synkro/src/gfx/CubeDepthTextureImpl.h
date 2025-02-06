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
// Purpose: Generic cube depth texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBEDEPTHTEXTUREIMPL_
#define _SYNKRO_GFX_CUBEDEPTHTEXTUREIMPL_


#include "config.h"
#include "DepthTextureImpl.h"
#include <gfx/CubeFace.h>


namespace synkro
{


namespace gfx
{


// Generic cube depth texture implementation.
template <class T>
class CubeDepthTextureImpl :
	public DepthTextureImpl<T>
{
public:
	// Constructor & destructor.
	CubeDepthTextureImpl( UInt length, const DepthFormat& format, Bool stencil );
	virtual ~CubeDepthTextureImpl();

	// IDepthTexture methods.
	virtual ICubeDepthTexture*								AsCube() const;

	// ICubeDepthTexture methods.
	virtual Bool											BindFace( const CubeFace& face );
	virtual UInt											GetLength() const;

protected:
	UInt													_length;
};


#include "CubeDepthTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBEDEPTHTEXTUREIMPL_
