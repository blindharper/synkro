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
// Purpose: Logical sound emitter.
//==============================================================================
SYNKRO_INLINE void SoundEmitter::Update()
{
	_emitter->Update();
}

SYNKRO_INLINE void SoundEmitter::Process( Bool start, Bool loop )
{
	_emitter->Process( start, loop );
}

SYNKRO_INLINE void SoundEmitter::GetFormat( sound::SoundFormat& format ) const
{
	_emitter->GetFormat( format );
}

SYNKRO_INLINE void SoundEmitter::SetPan( Int pan )
{
	_emitter->SetPan( pan );
}

SYNKRO_INLINE void SoundEmitter::SetAttenuation( Int attenuation )
{
	_emitter->SetAttenuation( attenuation );
}

SYNKRO_INLINE void SoundEmitter::SetFrequency( UInt frequency )
{
	_emitter->SetFrequency( frequency );
}

SYNKRO_INLINE Int SoundEmitter::GetPan() const
{
	return _emitter->GetPan();
}

SYNKRO_INLINE Int SoundEmitter::GetAttenuation() const
{
	return _emitter->GetAttenuation();
}

SYNKRO_INLINE UInt SoundEmitter::GetFrequency() const
{
	return _emitter->GetFrequency();
}

SYNKRO_INLINE void SoundEmitter::Bind()
{
	_emitter->Bind();
}

SYNKRO_INLINE void SoundEmitter::SetPosition( const math::Vector3& position )
{
	_emitter->SetPosition( position );
}

SYNKRO_INLINE void SoundEmitter::SetDirection( const math::Vector3& direction )
{
	_emitter->SetDirection( direction );
}

SYNKRO_INLINE void SoundEmitter::SetVelocity( const math::Vector3& velocity )
{
	_emitter->SetVelocity( velocity );
}

SYNKRO_INLINE void SoundEmitter::SetInnerAngle( Float angle )
{
	_emitter->SetInnerAngle( angle );
}

SYNKRO_INLINE void SoundEmitter::SetOuterAngle( Float angle )
{
	_emitter->SetOuterAngle( angle );
}

SYNKRO_INLINE void SoundEmitter::SetInnerAttenuation( Int volume )
{
	_emitter->SetInnerAttenuation( volume );
}

SYNKRO_INLINE void SoundEmitter::SetOuterAttenuation( Int volume )
{
	_emitter->SetOuterAttenuation( volume );
}

SYNKRO_INLINE void SoundEmitter::SetInnerReverb( Float reverb )
{
	_emitter->SetInnerReverb( reverb );
}

SYNKRO_INLINE void SoundEmitter::SetOuterReverb( Float reverb )
{
	_emitter->SetOuterReverb( reverb );
}

SYNKRO_INLINE void SoundEmitter::SetMinDistance( Float distance )
{
	_emitter->SetMinDistance( distance );
}

SYNKRO_INLINE void SoundEmitter::SetMaxDistance( Float distance )
{
	_emitter->SetMaxDistance( distance );
}

SYNKRO_INLINE void SoundEmitter::GetPosition( math::Vector3& position ) const
{
	_emitter->GetPosition( position );
}

SYNKRO_INLINE void SoundEmitter::GetDirection( math::Vector3& direction ) const
{
	_emitter->GetDirection( direction );
}

SYNKRO_INLINE void SoundEmitter::GetVelocity( math::Vector3& velocity ) const
{
	_emitter->GetVelocity( velocity );
}

SYNKRO_INLINE Float SoundEmitter::GetInnerAngle() const
{
	return _emitter->GetInnerAngle();
}

SYNKRO_INLINE Float SoundEmitter::GetOuterAngle() const
{
	return _emitter->GetOuterAngle();
}

SYNKRO_INLINE Int SoundEmitter::GetInnerAttenuation() const
{
	return _emitter->GetInnerAttenuation();
}

SYNKRO_INLINE Int SoundEmitter::GetOuterAttenuation() const
{
	return _emitter->GetOuterAttenuation();
}

SYNKRO_INLINE Float SoundEmitter::GetInnerReverb() const
{
	return _emitter->GetInnerReverb();
}

SYNKRO_INLINE Float SoundEmitter::GetOuterReverb() const
{
	return _emitter->GetOuterReverb();
}

SYNKRO_INLINE Float SoundEmitter::GetMinDistance() const
{
	return _emitter->GetMinDistance();
}

SYNKRO_INLINE Float SoundEmitter::GetMaxDistance() const
{
	return _emitter->GetMaxDistance();
}
