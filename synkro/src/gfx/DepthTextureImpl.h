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
// Purpose: Generic depth texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DEPTHTEXTUREIMPL_
#define _SYNKRO_GFX_DEPTHTEXTUREIMPL_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/DepthFormat.h>
#include <gfx/GraphicsException.h>


namespace synkro
{


namespace gfx
{


// Depth texture implementation.
template <class T>
class DepthTextureImpl :
	public ResourceImpl<T>
{
public:
	// Constructors & destructor.
	DepthTextureImpl( const DepthFormat& format, Bool stencil );
	virtual ~DepthTextureImpl();

	// IResource methods.
	virtual IDepthTexture*									AsDepthTexture() const;	

	// IDepthTexture methods.
	virtual	void											SetDefaultDepth( Float depth );
	virtual	void											SetDefaultStencil( Byte stencil );
	virtual	Float											GetDefaultDepth() const;
	virtual	Byte											GetDefaultStencil() const;
	virtual DepthFormat										GetFormat() const;
	virtual Bool											HasStencil() const;
	virtual IPlainDepthTexture*								AsPlain() const;
	virtual ICubeDepthTexture*								AsCube() const;

protected:
	Float													_defaultDepth;
	Byte													_defaultStencil;
	DepthFormat												_format;
	Bool													_stencil;
};


#include "DepthTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DEPTHTEXTUREIMPL_
