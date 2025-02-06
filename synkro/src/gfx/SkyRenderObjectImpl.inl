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
// Purpose: Generic sky object implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SkyRenderObjectImpl<T>::SkyRenderObjectImpl( IGraphicsSystemEx* graphicsSystem, IProgram* program ) :
	RenderObjectImpl<T>( program ),
	_elementCount( 0 )
{
}

template <class T>
SYNKRO_INLINE SkyRenderObjectImpl<T>::~SkyRenderObjectImpl()
{
}

template <class T>
SYNKRO_INLINE void SkyRenderObjectImpl<T>::SetFragmentResources( IResourceSet* resources )
{
	_fragmentResources = resources;
}

template <class T>
SYNKRO_INLINE void SkyRenderObjectImpl<T>::SetFragmentSamplers( ISamplerStateSet* samplers )
{
	_fragmentSamplers = samplers;
}

template <class T>
SYNKRO_INLINE IDepthStencilState* SkyRenderObjectImpl<T>::GetDepthStencilState() const
{
	return _depthStencilState;
}

template <class T>
SYNKRO_INLINE IRasterizerState* SkyRenderObjectImpl<T>::GetRasterizerState() const
{
	return _rasterizerState;
}

template <class T>
SYNKRO_INLINE IResourceSet* SkyRenderObjectImpl<T>::GetFragmentResources() const
{
	return _fragmentResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SkyRenderObjectImpl<T>::GetFragmentSamplers() const
{
	return _fragmentSamplers;
}

template <class T>
SYNKRO_INLINE UInt SkyRenderObjectImpl<T>::GetElementCount() const
{
	return _elementCount;
}
