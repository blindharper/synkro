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
// Purpose: Logical graphics device.
//==============================================================================
SYNKRO_INLINE Bool GraphicsDevice::IsSupported( const img::PixelFormat& format ) const
{
	if ( !_formats.ContainsKey(format) )
	{
		_formats[format] = _device->IsSupported( format );
	}
	return _formats[format];
}

SYNKRO_INLINE IBlendStateSet* GraphicsDevice::GetBlendStates() const
{
	return _blendStates;
}

SYNKRO_INLINE IDepthStencilState* GraphicsDevice::GetDepthStencilState() const
{
	return _depthStencilState;
}

SYNKRO_INLINE IRasterizerState* GraphicsDevice::GetRasterizerState() const
{
	return _rasterizerState;
}

SYNKRO_INLINE void GraphicsDevice::GetDesc( GraphicsDeviceDesc& desc ) const
{
	return _device->GetDesc( desc );
}

SYNKRO_INLINE void GraphicsDevice::SetDepthFormat( const DepthFormat& depthFormat )
{
	_depthFormat = depthFormat;
}

SYNKRO_INLINE DepthFormat GraphicsDevice::GetDepthFormat() const
{
	return _depthFormat;
}

SYNKRO_INLINE UInt GraphicsDevice::GetIndex() const
{
	return _index;
}
