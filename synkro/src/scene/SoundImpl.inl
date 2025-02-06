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
// Purpose: Generic sound implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SoundImpl<T>::SoundImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, sound::ISound3D* sound ) :
	NodeImpl<T>( scene, context, AsBaseScene(scene)->GetSoundName(name) ),
	_sound( sound ),
	_emitter( AsBaseSound3D(sound)->GetEmitter() ),
	_enabled( true )
{
	_audioEnvironment = scene->GetAudioEnvironment();
	if ( _audioEnvironment != nullptr )
	{
		_audioEnvironment->AddEmitter( _emitter );
	}
}

template <class T>
SYNKRO_INLINE SoundImpl<T>::~SoundImpl()
{
}

template <class T>
SYNKRO_INLINE ISound* SoundImpl<T>::AsSound() const
{
	return (ISound*)this;
}

template <class T>
SYNKRO_INLINE void SoundImpl<T>::Enable( Bool enable )
{
	_sound->Play( enable );
}

template <class T>
SYNKRO_INLINE void SoundImpl<T>::SetMinDistance( Float distance )
{
	_sound->SetMinDistance( distance );
}

template <class T>
SYNKRO_INLINE void SoundImpl<T>::SetMaxDistance( Float distance )
{
	_sound->SetMaxDistance( distance );
}

template <class T>
SYNKRO_INLINE Bool SoundImpl<T>::IsEnabled() const
{
	return _sound->IsPlaying();
}

template <class T>
SYNKRO_INLINE Float SoundImpl<T>::GetMinDistance() const
{
	return _sound->GetMinDistance();
}

template <class T>
SYNKRO_INLINE Float SoundImpl<T>::GetMaxDistance() const
{
	return _sound->GetMaxDistance();
}

template <class T>
SYNKRO_INLINE IConeSound* SoundImpl<T>::AsCone() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IOmniSound* SoundImpl<T>::AsOmni() const
{
	return nullptr;
}
