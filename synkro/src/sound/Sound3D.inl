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
// Purpose: 3D sound implementation.
//==============================================================================
SYNKRO_INLINE void Sound3D::Play( Bool play )
{
	_emitter->Process( play, true );
}

SYNKRO_INLINE void Sound3D::SetVolume( Int volume )
{
	_emitter->SetAttenuation( volume );
}

SYNKRO_INLINE Bool Sound3D::IsPlaying() const
{
	return _emitter->GetChunk(0)->IsProcessing();
}

SYNKRO_INLINE Int Sound3D::GetVolume() const
{
	return _emitter->GetAttenuation();
}

SYNKRO_INLINE Double Sound3D::GetLength() const
{
	return _length;
}

SYNKRO_INLINE void Sound3D::SetPosition( const math::Vector3& position )
{
	_emitter->SetPosition( position );
}

SYNKRO_INLINE void Sound3D::SetDirection( const math::Vector3& direction )
{
	_emitter->SetDirection( direction );
}

SYNKRO_INLINE void Sound3D::SetVelocity( const math::Vector3& velocity )
{
	_emitter->SetVelocity( velocity );
}

SYNKRO_INLINE void Sound3D::SetInnerAngle( Float angle )
{
	_emitter->SetInnerAngle( angle );
}

SYNKRO_INLINE void Sound3D::SetOuterAngle( Float angle )
{
	_emitter->SetOuterAngle( angle );
}

SYNKRO_INLINE void Sound3D::SetInnerVolume( Float volume )
{
	_emitter->SetInnerAttenuation( volume );
}

SYNKRO_INLINE void Sound3D::SetOuterVolume( Float volume )
{
	_emitter->SetOuterAttenuation( volume );
}

SYNKRO_INLINE void Sound3D::SetInnerReverb( Float reverb )
{
	_emitter->SetInnerReverb( reverb );
}

SYNKRO_INLINE void Sound3D::SetOuterReverb( Float reverb )
{
	_emitter->SetOuterReverb( reverb );
}

SYNKRO_INLINE void Sound3D::SetMinDistance( Float distance )
{
	_emitter->SetMinDistance( distance );
}

SYNKRO_INLINE void Sound3D::SetMaxDistance( Float distance )
{
	_emitter->SetMaxDistance( distance );
}

SYNKRO_INLINE void Sound3D::GetPosition( math::Vector3& position ) const
{
	_emitter->GetPosition( position );
}

SYNKRO_INLINE void Sound3D::GetDirection( math::Vector3& direction ) const
{
	_emitter->GetDirection( direction );
}

SYNKRO_INLINE void Sound3D::GetVelocity( math::Vector3& velocity ) const
{
	_emitter->GetVelocity( velocity );
}

SYNKRO_INLINE Float Sound3D::GetInnerAngle() const
{
	return _emitter->GetInnerAngle();
}

SYNKRO_INLINE Float Sound3D::GetOuterAngle() const
{
	return _emitter->GetOuterAngle();
}

SYNKRO_INLINE Float Sound3D::GetInnerVolume() const
{
	return _emitter->GetInnerAttenuation();
}

SYNKRO_INLINE Float Sound3D::GetOuterVolume() const
{
	return _emitter->GetOuterAttenuation();
}

SYNKRO_INLINE Float Sound3D::GetInnerReverb() const
{
	return _emitter->GetInnerReverb();
}

SYNKRO_INLINE Float Sound3D::GetOuterReverb() const
{
	return _emitter->GetOuterReverb();
}

SYNKRO_INLINE Float Sound3D::GetMinDistance() const
{
	return _emitter->GetMinDistance();
}

SYNKRO_INLINE Float Sound3D::GetMaxDistance() const
{
	return _emitter->GetMaxDistance();
}

SYNKRO_INLINE audio::ISoundEmitter* Sound3D::GetEmitter() const
{
	return _emitter;
}
