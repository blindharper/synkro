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
// Purpose: Synkro object implementation.
//==============================================================================
SYNKRO_INLINE anim::IAnimationSystem* Synkro::GetAnimationSystem() const
{
	SynkroCall( "Synkro.GetAnimationSystem", lang::String::Empty );

	if ( _animationSystem == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Animation system", Param::AnimationEnable) );

	return _animationSystem;
}

SYNKRO_INLINE audio::IAudioSystemEx* Synkro::GetAudioSystem() const
{
	SynkroCall( "Synkro.GetAudioSystem", lang::String::Empty );

	return _audioSystem;
}

SYNKRO_INLINE cons::IConsole* Synkro::GetConsole() const
{
	SynkroCall( "Synkro.GetConsole", lang::String::Empty );

	if ( _console == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Console", Param::ConsoleEnable) );

	return _console;
}

SYNKRO_INLINE db::IDatabaseSystemEx* Synkro::GetDatabaseSystem() const
{
	SynkroCall( "Synkro.GetDatabaseSystem", lang::String::Empty );

	if ( _databaseSystem == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Database system", Param::DatabaseEnable) );

	return _databaseSystem;
}

SYNKRO_INLINE diag::IDiag* Synkro::GetDiag() const
{
	return _diag;
}

SYNKRO_INLINE gfx::IGraphicsSystemEx* Synkro::GetGraphicsSystem() const
{
	return _graphicsSystem;
}

SYNKRO_INLINE img::IImageManager* Synkro::GetImageManager() const
{
	SynkroCall( "Synkro.GetImageManager", lang::String::Empty );

	if ( _imageManager == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Image manager", Param::ImagingEnable) );

	return _imageManager;
}

SYNKRO_INLINE input::IInputSystemEx* Synkro::GetInputSystem() const
{
	SynkroCall( "Synkro.GetInputSystem", lang::String::Empty );

	if ( _inputSystem == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Input system", Param::InputEnable) );

	return _inputSystem;
}

SYNKRO_INLINE mat::IMaterialManager* Synkro::GetMaterialManager() const
{
	return _materialManager;
}

SYNKRO_INLINE net::INetworkSystemEx* Synkro::GetNetworkSystem() const
{
	SynkroCall( "Synkro.GetNetworkSystem", lang::String::Empty );

	if ( _networkSystem == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Network system", Param::NetworkEnable) );

	return _networkSystem;
}

SYNKRO_INLINE over::IOverlayManager* Synkro::GetOverlayManager() const
{
	return _overlayManager;
}

SYNKRO_INLINE scene::ISceneManager* Synkro::GetSceneManager() const
{
	return _sceneManager;
}

SYNKRO_INLINE script::IScriptSystemEx* Synkro::GetScriptSystem() const
{
	SynkroCall( "Synkro.GetScriptSystem", lang::String::Empty );

	if ( _scriptSystem == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Script system", Param::ScriptEnable) );

	return _scriptSystem;
}

SYNKRO_INLINE sound::ISoundManager* Synkro::GetSoundManager() const
{
	SynkroCall( "Synkro.GetSoundManager", lang::String::Empty );

	if ( _soundManager == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"Sound manager", Param::AudioEnable) );

	return _soundManager;
}

SYNKRO_INLINE io::IStreamSystemEx* Synkro::GetStreamSystem() const
{
	return _streamSystem;
}

SYNKRO_INLINE ui::IUiEx* Synkro::GetUi() const
{
	SynkroCall( "Synkro.GetUi", lang::String::Empty );

	if ( _ui == nullptr )
		throw lang::InvalidOperationException( lang::String::Format(Str::SubsystemDisabled, L"User interface", Param::UiEnable) );

	return _ui;
}

SYNKRO_INLINE view::IViewportManager* Synkro::GetViewportManager() const
{
	return _viewportManager;
}

SYNKRO_INLINE win::IWindowSystemEx* Synkro::GetWindowSystem() const
{
	return _windowSystem;
}

SYNKRO_INLINE IConfiguration* Synkro::GetConfiguration() const
{
	return _config;
}

SYNKRO_INLINE UInt Synkro::GetLibraryCount() const
{
	return _libs.Size();
}

SYNKRO_INLINE ILibrary* Synkro::GetLibrary( UInt index ) const
{
	assert( index < _libs.Size() );

	if ( index >= _libs.Size() )
		throw lang::OutOfRangeException( index, _libs.Size() );

	return (index < _libs.Size()) ? _libs[index] : nullptr;
}

SYNKRO_INLINE UInt Synkro::GetResourceCount( const ResourceType& type ) const
{
	return _resources.Exists(type) ? _resources.Get(type).GetResourceCount() : 0;
}

SYNKRO_INLINE IResource* Synkro::GetResource( const ResourceType& type, UInt index ) const
{
	return _resources.Exists(type) ? _resources.Get(type).GetResource( index ) : nullptr;
}

SYNKRO_INLINE IResource* Synkro::GetResource( UInt id ) const
{
	return _resources.Get(ResourceType::Unknown).GetResourceById( id );
}

SYNKRO_INLINE UInt Synkro::GetFactoryCount( const Iface& ifaceID ) const
{
	return _factories.Exists(ifaceID) ? _factories.Get(ifaceID).GetFactoryCount() : 0;
}

SYNKRO_INLINE IFactory* Synkro::GetFactory( const Iface& ifaceID, UInt index ) const
{
	return _factories.Exists(ifaceID) ? _factories.Get(ifaceID).GetFactory( index ) : nullptr;
}

SYNKRO_INLINE IFactory* Synkro::GetFactory( const Iface& ifaceID, const lang::Enum& classID ) const
{
	return _factories.Exists(ifaceID) ? _factories.Get(ifaceID).GetFactory( classID ) : nullptr;
}

SYNKRO_INLINE Pointer Synkro::GetModule() const
{
	return _module;
}

SYNKRO_INLINE UInt Synkro::GetFrame() const
{
	return _frame;
}

SYNKRO_INLINE Double Synkro::GetTime() const
{
	return _time;
}

SYNKRO_INLINE Language Synkro::GetLanguage() const
{
	return _language;
}

SYNKRO_INLINE io::IStreamDirectory* Synkro::LoadResource( const ResourceType& type, UInt index )
{
	return _resources.Exists(type) ? _resources.Get(type).LoadResource( index ) : nullptr;
}
