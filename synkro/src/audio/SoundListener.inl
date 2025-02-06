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
// Purpose: Logical sound listener.
//==============================================================================
SYNKRO_INLINE void SoundListener::Bind()
{
	_listener->Bind();
}

SYNKRO_INLINE void SoundListener::SetPosition( const math::Vector3& position )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default sound listener." );

	_listener->SetPosition( position );
}

SYNKRO_INLINE void SoundListener::SetDirection( const math::Vector3& direction )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default sound listener." );

	_listener->SetDirection( direction );
}

SYNKRO_INLINE void SoundListener::SetVelocity( const math::Vector3& velocity )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default sound listener." );

	_listener->SetVelocity( velocity );
}

SYNKRO_INLINE void SoundListener::SetRolloffFactor( Float factor )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default sound listener." );

	_listener->SetRolloffFactor( factor );
}

SYNKRO_INLINE void SoundListener::SetDopplerFactor( Float factor )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default sound listener." );

	_listener->SetDopplerFactor( factor );
}

SYNKRO_INLINE void SoundListener::GetPosition( math::Vector3& position ) const
{
	_listener->GetPosition( position );
}

SYNKRO_INLINE void SoundListener::GetDirection( math::Vector3& direction ) const
{
	_listener->GetDirection( direction );
}

SYNKRO_INLINE void SoundListener::GetVelocity( math::Vector3& velocity ) const
{
	_listener->GetVelocity( velocity );
}

SYNKRO_INLINE Float SoundListener::GetRolloffFactor() const
{
	return _listener->GetRolloffFactor();
}

SYNKRO_INLINE Float SoundListener::GetDopplerFactor() const
{
	return _listener->GetDopplerFactor();
}

SYNKRO_INLINE ISoundListener* SoundListener::Clone() const
{
	return new SoundListener( *this );
}
