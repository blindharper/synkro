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
// Purpose: Transparent material implementation.
//==============================================================================
SYNKRO_INLINE ITransparentMaterial* TransparentMaterial::AsTransparent() const
{
	return (ITransparentMaterial*)this;
}

SYNKRO_INLINE Float TransparentMaterial::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterial::GetColorSourceMode() const
{
	return _colorSourceMode;
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterial::GetAlphaSourceMode() const
{
	return _alphaSourceMode;
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterial::GetColorDestinationMode() const
{
	return _colorDestinationMode;
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterial::GetAlphaDestinationMode() const
{
	return _alphaDestinationMode;
}

SYNKRO_INLINE gfx::BlendOperation TransparentMaterial::GetColorOperation() const
{
	return _colorOperation;
}

SYNKRO_INLINE gfx::BlendOperation TransparentMaterial::GetAlphaOperation() const
{
	return _alphaOperation;
}

SYNKRO_INLINE IMaterialMap* TransparentMaterial::GetOpacityMap() const
{
	return _opacityMap;
}

SYNKRO_INLINE ITransparentMaterial* TransparentMaterial::Clone() const
{
	return new TransparentMaterial( *this );
}
