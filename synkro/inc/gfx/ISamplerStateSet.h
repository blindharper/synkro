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
// Purpose: Defines sampler state set.
//==============================================================================
#ifndef _SYNKRO_GFX_ISAMPLERSTATESET_
#define _SYNKRO_GFX_ISAMPLERSTATESET_


#include "config.h"
#include <gfx/IRenderState.h>
#include <math/Vector4.h>
#include <gfx/TextureFilter.h>
#include <gfx/TextureAddress.h>


namespace synkro
{


namespace gfx
{


/**
 * Sampler state set.
 */
iface ISamplerStateSet :
	public IRenderState
{
public:
	/**
	 * Sets minification, magnification and mipmap filtering mode for all states in the set. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets minification texture filtering mode for all states in the set. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMinFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets magnification texture filtering mode for all states in the set. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMagFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets mipmap texture filtering mode for all states in the set. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMipFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets clamping value used with Anisotropic texture filter for all states in the set. Default is 16.
	 * @param anisotropy Anisotropy value.
	 */
	virtual void											SetMaxAnisotropy( UInt anisotropy ) = 0;

	/**
	 * Sets texture addressing mode for all coordinates for all states in the set. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddress( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the U coordinate for all states in the set. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressU( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the V coordinate for all states in the set. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressV( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the W coordinate for all states in the set. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressW( const TextureAddress& address ) = 0;

	/**
	 * Sets texture border color for all states in the set. Default is black.
	 * @param color Texture border color.
	 */
	virtual void											SetBorderColor( const math::Vector4& color ) = 0;

	/**
	 * Retrieves the total number of sampler states in the set.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves sampler state by index.
	 * @param index Sampler index.
	 * @return Requested sampler state.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ISamplerState*									Get( UInt index ) const = 0;

	/**
	 * Produces an exact copy of sampler state set.
	 * @param ownerID Identifer of the owner. An owner is the object invoking sampler set's methods.
	 * @return Newly created sampler state set.
	 */
	virtual ISamplerStateSet*								Clone( UInt ownerID ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISAMPLERSTATESET_
