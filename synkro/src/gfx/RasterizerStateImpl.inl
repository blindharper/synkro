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
// Purpose: Generic rasterizer state implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RasterizerStateImpl<T>::RasterizerStateImpl() :
	_cull( CullMode::Back ),
	_fill( FillMode::Solid ),
	_depthBias( 0.0f ),
	_depthBiasClamp( 0.0f ),
	_slopeScaledDepthBias( 0.0f ),
	_scissorEnabled( false ),
	_multisampleEnabled( false ),
	_antialiasingEnabled( false )
{
}

template <class T>
SYNKRO_INLINE RasterizerStateImpl<T>::~RasterizerStateImpl()
{
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::SetCullMode( const CullMode& cull )
{
	if ( cull != _cull )
	{
		_cull = cull;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::SetFillMode( const FillMode& fill )
{
	if ( fill != _fill )
	{
		_fill = fill;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::SetDepthBias( Float bias )
{
	if ( bias != _depthBias )
	{
		_depthBias = bias;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::SetDepthBiasClamp( Float clamp )
{
	if ( clamp != _depthBiasClamp )
	{
		_depthBiasClamp = clamp;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::SetSlopeScaledDepthBias( Float bias )
{
	if ( bias != _slopeScaledDepthBias )
	{
		_slopeScaledDepthBias = bias;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::EnableScissor( Bool enable )
{
	if ( enable != _scissorEnabled )
	{
		_scissorEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::EnableMultisample( Bool enable )
{
	if ( enable != _multisampleEnabled )
	{
		_multisampleEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RasterizerStateImpl<T>::EnableAntialiasing( Bool enable )
{
	if ( enable != _antialiasingEnabled )
	{
		_antialiasingEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE CullMode RasterizerStateImpl<T>::GetCullMode() const
{
	return _cull;
}

template <class T>
SYNKRO_INLINE FillMode RasterizerStateImpl<T>::GetFillMode() const
{
	return _fill;
}

template <class T>
SYNKRO_INLINE Float RasterizerStateImpl<T>::GetDepthBias() const
{
	return _depthBias;
}

template <class T>
SYNKRO_INLINE Float RasterizerStateImpl<T>::GetDepthBiasClamp() const
{
	return _depthBiasClamp;
}

template <class T>
SYNKRO_INLINE Float RasterizerStateImpl<T>::GetSlopeScaledDepthBias() const
{
	return _slopeScaledDepthBias;
}

template <class T>
SYNKRO_INLINE Bool RasterizerStateImpl<T>::IsScissorEnabled() const
{
	return _scissorEnabled;
}

template <class T>
SYNKRO_INLINE Bool RasterizerStateImpl<T>::IsMultisampleEnabled() const
{
	return _multisampleEnabled;
}

template <class T>
SYNKRO_INLINE Bool RasterizerStateImpl<T>::IsAntialiasingEnabled() const
{
	return _antialiasingEnabled;
}
