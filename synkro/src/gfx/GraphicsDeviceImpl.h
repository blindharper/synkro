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
// Purpose: Generic graphics device implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSDEVICEIMPL_
#define _SYNKRO_GFX_GRAPHICSDEVICEIMPL_


#include "config.h"
#include <lang/Map.h>
#include <core/ObjectImpl.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>
#include <gfx/GraphicsDeviceDesc.h>
#include <io/IStreamDirectory.h>
#include <io/IStreamSet.h>


namespace synkro
{


namespace gfx
{


// Generic graphics device implementation.
template <class T>
class GraphicsDeviceImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor & destructors.
	GraphicsDeviceImpl( const GraphicsDeviceDesc& desc, diag::ILog* log );
	virtual ~GraphicsDeviceImpl();

	// IGraphicsDevice methods.
	virtual IBlendStateSet*									GetBlendStates() const;
	virtual IDepthStencilState*								GetDepthStencilState() const;
	virtual IRasterizerState*								GetRasterizerState() const;
	virtual void											GetDesc( GraphicsDeviceDesc& desc ) const;

	// Other methods.
	void													AddShader( io::IStream* stream, void* shader, void* data );
	void*													GetShader( io::IStream* stream ) const;
	void*													GetShaderData( io::IStream* stream ) const;

protected:
	struct ShaderDesc
	{
		ShaderDesc( void* shader, void* data ) :
			Shader( shader ),
			Data( data )
		{
		}

		ShaderDesc() :
			Shader( nullptr ),
			Data( nullptr )
		{
		}

		void*	Shader;
		void*	Data;
	};

	typedef lang::MapPair<UInt, ShaderDesc>				ShaderEntry;

	lang::Map<UInt, ShaderDesc>							_shaders;
	GraphicsDeviceDesc										_desc;
	P(IBlendStateSet)										_blendStates;
	P(IDepthStencilState)									_depthStencilState;
	P(IRasterizerState)										_rasterizerState;
	P(io::IStreamDirectory)									_programDir;
};


#include "GraphicsDeviceImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSDEVICEIMPL_
