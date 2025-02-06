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
// Purpose: Generic blend state implementation.
//==============================================================================
SYNKRO_INLINE void BlendStateEx::Enable( Bool enable )
{
	if ( enable != _enabled )
	{
		_enabled = enable;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetSrcMode( const BlendMode& mode )
{
	SetColorSrcMode( mode );
	SetAlphaSrcMode( mode );
}

SYNKRO_INLINE void BlendStateEx::SetColorSrcMode( const BlendMode& mode )
{
	if ( mode != _colorSrcMode )
	{
		_colorSrcMode = mode;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetAlphaSrcMode( const BlendMode& mode )
{
	if ( mode != _alphaSrcMode )
	{
		_alphaSrcMode = mode;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetDstMode( const BlendMode& mode )
{
	SetColorDstMode( mode );
	SetAlphaDstMode( mode );
}

SYNKRO_INLINE void BlendStateEx::SetColorDstMode( const BlendMode& mode )
{
	if ( mode != _colorDstMode )
	{
		_colorDstMode = mode;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetAlphaDstMode( const BlendMode& mode )
{
	if ( mode != _alphaDstMode )
	{
		_alphaDstMode = mode;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetOperation( const BlendOperation& operation )
{
	SetColorOperation( operation );
	SetAlphaOperation( operation );
}

SYNKRO_INLINE void BlendStateEx::SetColorOperation( const BlendOperation& operation )
{
	if ( operation != _colorBlendOp )
	{
		_colorBlendOp = operation;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetAlphaOperation( const BlendOperation& operation )
{
	if ( operation != _alphaBlendOp )
	{
		_alphaBlendOp = operation;
		_dirty = true;
	}
}

SYNKRO_INLINE void BlendStateEx::SetWriteChannels( const img::PixelChannel& channels )
{
	if ( channels != _channels )
	{
		_channels = channels;
		_dirty = true;
	}
}

SYNKRO_INLINE Bool BlendStateEx::IsEnabled() const
{
	return _enabled;
}

SYNKRO_INLINE BlendMode BlendStateEx::GetColorSrcMode() const
{
	return _colorSrcMode;
}

SYNKRO_INLINE BlendMode BlendStateEx::GetAlphaSrcMode() const
{
	return _alphaSrcMode;
}

SYNKRO_INLINE BlendMode BlendStateEx::GetColorDstMode() const
{
	return _colorDstMode;
}

SYNKRO_INLINE BlendMode BlendStateEx::GetAlphaDstMode() const
{
	return _alphaDstMode;
}

SYNKRO_INLINE BlendOperation BlendStateEx::GetColorOperation() const
{
	return _colorBlendOp;
}

SYNKRO_INLINE BlendOperation BlendStateEx::GetAlphaOperation() const
{
	return _alphaBlendOp;
}

SYNKRO_INLINE img::PixelChannel BlendStateEx::GetWriteChannels() const
{
	return _channels;
}

SYNKRO_INLINE void BlendStateEx::ResetDirty()
{
	_dirty = false;
}

SYNKRO_INLINE Bool BlendStateEx::IsDirty() const
{
	return _dirty;
}

SYNKRO_INLINE BlendStateEx* BlendStateEx::Clone() const
{
	return new BlendStateEx( *this );
}
