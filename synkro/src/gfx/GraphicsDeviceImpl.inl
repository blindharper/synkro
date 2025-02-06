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
template <class T>
SYNKRO_INLINE GraphicsDeviceImpl<T>::GraphicsDeviceImpl( const GraphicsDeviceDesc& desc, diag::ILog* log ) :
	_shaders( A(ShaderEntry) ),
	_desc( desc ),
	Logger( log, diag::LogFacility::GraphicsSystem )
{
}

template <class T>
SYNKRO_INLINE GraphicsDeviceImpl<T>::~GraphicsDeviceImpl()
{
}

template <class T>
SYNKRO_INLINE IBlendStateSet* GraphicsDeviceImpl<T>::GetBlendStates() const
{
	return _blendStates;
}

template <class T>
SYNKRO_INLINE IDepthStencilState* GraphicsDeviceImpl<T>::GetDepthStencilState() const
{
	return _depthStencilState;
}

template <class T>
SYNKRO_INLINE IRasterizerState* GraphicsDeviceImpl<T>::GetRasterizerState() const
{
	return _rasterizerState;
}

template <class T>
SYNKRO_INLINE void GraphicsDeviceImpl<T>::GetDesc( GraphicsDeviceDesc& desc ) const
{
	desc = _desc;
}

template <class T>
SYNKRO_INLINE void GraphicsDeviceImpl<T>::AddShader( io::IStream* stream, void* shader, void* data )
{
	UInt key = stream->ID();
	_shaders[key] = ShaderDesc( shader, data );
}

template <class T>
SYNKRO_INLINE void* GraphicsDeviceImpl<T>::GetShader( io::IStream* stream ) const
{
	UInt key = stream->ID();
	return _shaders.ContainsKey(key) ? _shaders[key].Shader : nullptr;
}

template <class T>
SYNKRO_INLINE void* GraphicsDeviceImpl<T>::GetShaderData( io::IStream* stream ) const
{
	UInt key = stream->ID();
	return _shaders.ContainsKey(key) ? _shaders[key].Data : nullptr;
}
