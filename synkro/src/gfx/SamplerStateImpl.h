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
// Purpose: Generic sampler state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SAMPLERSTATEIMPL_
#define _SYNKRO_GFX_SAMPLERSTATEIMPL_


#include "config.h"
#include "RenderStateImpl.h"
#include <math/Vector4.h>
#include <gfx/TextureFilter.h>
#include <gfx/TextureAddress.h>
#include <gfx/GraphicsException.h>


namespace synkro
{


namespace gfx
{


// Generic sampler state implementation.
template <class T>
class SamplerStateImpl :
	public RenderStateImpl<T>
{
public:
	// Constructor & destructor.
	SamplerStateImpl();
	virtual ~SamplerStateImpl();

	// ISamplerState methods.
	virtual void											SetFilter( const TextureFilter& filter );
	virtual void											SetMinFilter( const TextureFilter& filter );
	virtual void											SetMagFilter( const TextureFilter& filter );
	virtual void											SetMipFilter( const TextureFilter& filter );
	virtual void											SetMaxAnisotropy( UInt anisotropy );
	virtual void											SetAddress( const TextureAddress& address );
	virtual void											SetAddressU( const TextureAddress& address );
	virtual void											SetAddressV( const TextureAddress& address );
	virtual void											SetAddressW( const TextureAddress& address );
	virtual void											SetBorderColor( const math::Vector4& color );
	virtual TextureFilter									GetMinFilter() const;
	virtual TextureFilter									GetMagFilter() const;
	virtual TextureFilter									GetMipFilter() const;
	virtual UInt											GetMaxAnisotropy() const;
	virtual TextureAddress									GetAddressU() const;
	virtual TextureAddress									GetAddressV() const;
	virtual TextureAddress									GetAddressW() const;
	virtual void											GetBorderColor( math::Vector4& color ) const;

protected:
	Bool													_dirty;
	TextureFilter											_filterMin;
	TextureFilter											_filterMag;
	TextureFilter											_filterMip;
	UInt													_anisotropy;
	TextureAddress											_addressU;
	TextureAddress											_addressV;
	TextureAddress											_addressW;
	math::Vector4											_borderColor;
};


#include "SamplerStateImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SAMPLERSTATEIMPL_
