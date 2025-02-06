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
#ifndef _SYNKRO_CORE_SYNKRO_
#define _SYNKRO_CORE_SYNKRO_


#include "config.h"
#include <cfg/SynkroVersion.h>
#include <core/IFactory.h>
#include <core/IResource.h>
#include <core/SynkroListener.h>
#include <anim/AnimationSystem.h>
#include <audio/AudioSystemEx.h>
#include <db/DatabaseSystemEx.h>
#include <gfx/GraphicsSystemEx.h>
#include <img/ImageManager.h>
#include <input/InputSystemEx.h>
#include <scene/SceneManager.h>
#include <mat/MaterialManager.h>
#include <net/NetworkSystemEx.h>
#include <script/ScriptSystemEx.h>
#include <io/StreamSystemEx.h>
#include <over/OverlayManager.h>
#include <sound/SoundManager.h>
#include <cons/Console.h>
#include <view/ViewportManager.h>
#include <win/WindowSystemEx.h>
#include <win/WindowListener.h>
#include <diag/Diag.h>
#include <ui/UiEx.h>
#include <core/ISynkro.h>
#include <core/Param.h>
#include <internal/Timer.h>
#include "FactoryTable.h"
#include "ResourceTable.h"
#include "Configuration.h"
#include "ThreadPool.h"
#include "Library.h"
#include "CallStack.h"


namespace synkro
{


namespace core
{


// ISynkro implementation.
class Synkro :
	public ObjectImpl<ISynkro>,
	public win::WindowListener,
	public Logger
{
public:
	// Constructor & destructor.
	Synkro( Pointer module, UInt version, SynkroListener* listener );
	~Synkro();

	// IContext methods.
	anim::IAnimationSystem*									GetAnimationSystem() const;
	audio::IAudioSystemEx*									GetAudioSystem() const;
	cons::IConsole*											GetConsole() const;
	db::IDatabaseSystemEx*									GetDatabaseSystem() const;
	diag::IDiag*											GetDiag() const;
	gfx::IGraphicsSystemEx*									GetGraphicsSystem() const;
	img::IImageManager*										GetImageManager() const;
	input::IInputSystemEx*									GetInputSystem() const;
	mat::IMaterialManager*									GetMaterialManager() const;
	net::INetworkSystemEx*									GetNetworkSystem() const;
	over::IOverlayManager*									GetOverlayManager() const;
	scene::ISceneManager*									GetSceneManager() const;
	script::IScriptSystemEx*								GetScriptSystem() const;
	sound::ISoundManager*									GetSoundManager() const;
	io::IStreamSystemEx*									GetStreamSystem() const;
	ui::IUiEx*												GetUi() const;
	view::IViewportManager*									GetViewportManager() const;
	win::IWindowSystemEx*									GetWindowSystem() const;

	// IContextEx methods.
	INodeList*												CreateNodeList();
	ITriangleMeshList*										CreateTriangleMeshList();
	lang::String											ReadString( io::IStream* stream );
	void													WriteString( io::IStream* stream, const lang::String& text );
	IStringList*											SplitString( const lang::String& str, Char delim );

	// ISynkro methods.
	void													Run( const Bool& running );
	void													Execute( Task* task );
	Bool													Configure( IConfiguration* config );
	IResource*												CreateResource( const Byte* data, UInt size );
	UInt													CreateTimer( UInt interval, TimerListener* listener );
	void													Initialize( IConfiguration* config );
	IConfiguration*											GetConfiguration() const;
	UInt													GetLibraryCount() const;
	ILibrary*												GetLibrary( UInt index ) const;
	UInt													GetResourceCount( const ResourceType& type ) const;
	IResource*												GetResource( const ResourceType& type, UInt index ) const;
	IResource*												GetResource( UInt id ) const;
	UInt													GetFactoryCount( const Iface& ifaceID ) const;
	IFactory*												GetFactory( const Iface& ifaceID, UInt index ) const;
	IFactory*												GetFactory( const Iface& ifaceID, const lang::Enum& classID ) const;
	Pointer													GetModule() const;
	UInt													GetFrame() const;
	Double													GetTime() const;
	Language												GetLanguage() const;

	// WindowListener methods.
	void													OnWindowResize( UInt window, UInt width, UInt height );
	void													OnWindowCommand( UInt window, UInt command );
	void													OnWindowActivate( UInt window, Bool active );
	Bool													OnWindowClosing( UInt window );

	// Other methods.
	void													Destroy();
	void													InitThreadPool( IConfiguration* config );
	void													InitAnimationSystem( IConfiguration* config );
	void													InitAudioSystem( IConfiguration* config );
	void													InitConsole( IConfiguration* config );
	void													InitDatabaseSystem( IConfiguration* config );
	void													InitDiag( IConfiguration* config );
	void													InitGraphicsSystem( IConfiguration* config );
	void													InitImageManager( IConfiguration* config );
	void													InitInputSystem( IConfiguration* config );
	void													InitMaterialManager( IConfiguration* config );
	void													InitNetworkSystem( IConfiguration* config );
	void													InitOverlayManager( IConfiguration* config );
	void													InitSceneManager( IConfiguration* config );	
	void													InitScriptSystem( IConfiguration* config );
	void													InitSoundManager( IConfiguration* config );
	void													InitStreamSystem( IConfiguration* config );
	void													InitUi( IConfiguration* config );
	void													InitViewportManager( IConfiguration* config );
	void													InitWindowSystem( IConfiguration* config );
	io::IStreamDirectory*									LoadResource( const ResourceType& type, UInt index );

private:
	struct TimerDesc
	{
		TimerDesc( UInt id, UInt interval, TimerListener* listener ) :
			ID( id ),
			Interval( interval ),
			Time( CastDouble(interval)*0.001 ),
			Listener( listener )
		{
		}

		TimerDesc() :
			ID( none ),
			Interval( none ),
			Time( 0.0 ),
			Listener( nullptr )
		{
		}

		UInt			ID;
		UInt			Interval;
		Double			Time;
		TimerListener*	Listener;
	};

	Bool													_created;
	Bool													_inited;
	Double													_time;
	UInt													_frame;
	Pointer													_module;
	Language												_language;
	P(Configuration)										_config;
	P(IObject)												_logFile;

	lang::String											_pathMain;
	lang::String											_pathStart;
	lang::Vector<P(Library)>								_libs;

	Timer													_timer;
	FactoryTable											_factories;
	ResourceTable											_resources;
	ThreadPool*												_threadPool;

	lang::Vector<ISystem*>									_systems;
	lang::Vector<TimerDesc>									_timers;
	SynkroListener*											_listener;
	Bool													_updateListener;
	P(diag::Diag)											_diag;
	P(anim::AnimationSystem)								_animationSystem;
	P(io::StreamSystemEx)									_streamSystem;
	P(win::WindowSystemEx)									_windowSystem;
	P(db::DatabaseSystemEx)									_databaseSystem;
	P(gfx::GraphicsSystemEx)								_graphicsSystem;
	P(audio::AudioSystemEx)									_audioSystem;
	P(input::InputSystemEx)									_inputSystem;
	P(net::NetworkSystemEx)									_networkSystem;
	P(img::ImageManager)									_imageManager;
	P(mat::MaterialManager)									_materialManager;
	P(sound::SoundManager)									_soundManager;
	P(view::ViewportManager)								_viewportManager;
	P(script::ScriptSystemEx)								_scriptSystem;
	P(over::OverlayManager)									_overlayManager;
	P(scene::SceneManager)									_sceneManager;
	P(ui::UiEx)												_ui;
	P(cons::Console)										_console;

	void													RegisterParams();
	void													RegisterResource( IResource* res );
	void													RegisterFactory( IFactory* fact );
	Bool													RegisterLibrary( ILibrary* lib );
	void													LoadLibraries();
	void													GetPaths();
	void													HandleException( const lang::Exception& ex );
	Bool													ExistsOrDisabled( ISystem* system, IConfiguration* config, const lang::String& param ) const;
	void													Dump( IConfiguration* config );
	io::IStreamDirectory*									CreatePath( const lang::String& path );
};


#include "Synkro.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_SYNKRO_
