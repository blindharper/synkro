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
// Purpose: Defines sampler state.
//==============================================================================
#ifndef _SYNKRO_GFX_ISAMPLERSTATE_
#define _SYNKRO_GFX_ISAMPLERSTATE_


#include "config.h"
#include <core/IObject.h>
#include <math/Vector4.h>
#include <gfx/TextureFilter.h>
#include <gfx/TextureAddress.h>


namespace synkro
{


namespace gfx
{


/**
 * Sampler state.
 */
iface ISamplerState :
	public core::IObject
{
public:
	/**
	 * Sets minification, magnification and mipmap filtering mode. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets minification texture filtering mode. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMinFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets magnification texture filtering mode. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMagFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets mipmap texture filtering mode. Default is Point.
	 * @param filter Texture filtering mode.
	 */
	virtual void											SetMipFilter( const TextureFilter& filter ) = 0;

	/**
	 * Sets clamping value used with Anisotropic texture filter. Default is 16.
	 * @param anisotropy Anisotropy value.
	 */
	virtual void											SetMaxAnisotropy( UInt anisotropy ) = 0;

	/**
	 * Sets texture addressing mode for all coordinates. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddress( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the U coordinate. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressU( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the V coordinate. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressV( const TextureAddress& address ) = 0;

	/**
	 * Sets texture addressing mode for the W coordinate. Default is Wrap.
	 * @param address Texture addressing mode.
	 */
	virtual void											SetAddressW( const TextureAddress& address ) = 0;

	/**
	 * Sets texture border color. Default is black.
	 * @param color Texture border color.
	 */
	virtual void											SetBorderColor( const math::Vector4& color ) = 0;

	/**
	 * Retrieves minification texture filtering mode.
	 */
	virtual TextureFilter									GetMinFilter() const = 0;

	/**
	 * Retrieves magnification texture filtering mode.
	 */
	virtual TextureFilter									GetMagFilter() const = 0;

	/**
	 * Retrieves mipmap texture filtering mode.
	 */
	virtual TextureFilter									GetMipFilter() const = 0;

	/**
	 * Retrieves clamping value used with Anisotropic texture filter.
	 */
	virtual UInt											GetMaxAnisotropy() const = 0;

	/**
	 * Retrieves texture addressing mode for the U coordinate.
	 */
	virtual TextureAddress									GetAddressU() const = 0;

	/**
	 * Retrieves texture addressing mode for the V coordinate.
	 */
	virtual TextureAddress									GetAddressV() const = 0;

	/**
	 * Retrieves texture addressing mode for the W coordinate.
	 */
	virtual TextureAddress									GetAddressW() const = 0;

	/**
	 * Retrieves texture border color.
	 * @param [out] color Texture border color.
	 */
	virtual void											GetBorderColor( math::Vector4& color ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISAMPLERSTATE_
