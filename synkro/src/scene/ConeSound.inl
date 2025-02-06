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
// Purpose: Cone sound node implementation.
//==============================================================================
SYNKRO_INLINE IConeSound* ConeSound::AsCone() const
{
	return (IConeSound*)this;
}

SYNKRO_INLINE void ConeSound::SetInnerAngle( Float angle )
{
	_sound->SetInnerAngle( angle );
}

SYNKRO_INLINE void ConeSound::SetOuterAngle( Float angle )
{
	_sound->SetOuterAngle( angle );
}

SYNKRO_INLINE void ConeSound::SetInnerVolume( Float volume )
{
	_sound->SetInnerVolume( volume );
}

SYNKRO_INLINE void ConeSound::SetOuterVolume( Float volume )
{
	_sound->SetOuterVolume( volume );
}

SYNKRO_INLINE void ConeSound::SetInnerReverb( Float reverb )
{
	_sound->SetInnerReverb( reverb );
}

SYNKRO_INLINE void ConeSound::SetOuterReverb( Float reverb )
{
	_sound->SetOuterReverb( reverb );
}

SYNKRO_INLINE Float ConeSound::GetInnerAngle() const
{
	return _sound->GetInnerAngle();
}

SYNKRO_INLINE Float ConeSound::GetOuterAngle() const
{
	return _sound->GetOuterAngle();
}

SYNKRO_INLINE Float ConeSound::GetInnerVolume() const
{
	return _sound->GetInnerVolume();
}

SYNKRO_INLINE Float ConeSound::GetOuterVolume() const
{
	return _sound->GetOuterVolume();
}

SYNKRO_INLINE Float ConeSound::GetInnerReverb() const
{
	return _sound->GetInnerReverb();
}

SYNKRO_INLINE Float ConeSound::GetOuterReverb() const
{
	return _sound->GetOuterReverb();
}
