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
// Purpose: Emboss filter implementation.
//==============================================================================
SYNKRO_INLINE IEmbossFilter* EmbossFilter::AsEmboss() const
{
	return (IEmbossFilter*)this;
}

SYNKRO_INLINE void EmbossFilter::SetDepth( Float depth )
{
	_params->Set( _paramDepth, Clamp(depth, 0.0f, 1.0f) );
}

SYNKRO_INLINE Float EmbossFilter::GetAngle() const
{
	return _angle;
}

SYNKRO_INLINE Float EmbossFilter::GetDepth() const
{
	Float depth;
	_params->Get( _paramDepth, &depth );
	return depth;
}
