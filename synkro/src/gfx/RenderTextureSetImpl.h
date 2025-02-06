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
// Purpose: Generic rendering texture set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERTEXTURESETIMPL_
#define _SYNKRO_GFX_RENDERTEXTURESETIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IRenderTexture.h>
#include <lang/Vector.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


// Generic rendering texture set implementation.
template <class T>
class RenderTextureSetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderTextureSetImpl();
	virtual ~RenderTextureSetImpl();

	// IRenderTextureSet methods.
	virtual Bool											Present();
	virtual void											Set( UInt index, IRenderTexture* texture );
	virtual	void											SetDefaultColor( const math::Vector4& color );
	virtual	void											GetDefaultColor( math::Vector4& color ) const;
	virtual UInt											GetSize() const;
	virtual IRenderTexture*									Get( UInt index ) const;

protected:
	lang::Vector<P(IRenderTexture)>							_textures;
	math::Vector4											_defaultColor;
};


#include "RenderTextureSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERTEXTURESETIMPL_
