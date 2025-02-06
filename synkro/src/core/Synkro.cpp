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
#include "config.h"
#include "Synkro.h"
#include <io/Path.h>
#include <io/TextReader.h>
#include <io/TextWriter.h>
#include <io/StreamSystemEx.h>
#include <io/NullStreamSystem.h>
#include <io/IStreamSystemFactory.h>
#include <io/IStreamDirectoryFactory.h>
#include <net/INetworkSystemFactory.h>
#include <cons/IConsoleCommandFactory.h>
#include <lang/Convert.h>
#include <diag/BaseLog.h>
#include <core/IResource.h>
#include <core/Param.h>
#include <core/TimerListener.h>
#include <gfx/GraphicsSystem.h>
#include <core/VersionException.h>
#include "ParamTypeConst.h"
#include "Resource.h"
#include "ConfigurationEditor.h"
#include "ExceptionHandler.h"
#include "PlainLogFile.h"
#include "RichLogFile.h"
#include "List/StringList.h"
#include "List/NodeList.h"
#include "List/TriangleMeshList.h"
#ifdef SYNKRO_STATIC
#include "BaseFactory.h"
#include "BaseResource.h"
#endif // SYNKRO_STATIC
#include <resource.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::cons;
using namespace synkro::db;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::mem;
using namespace synkro::net;
using namespace synkro::over;
using namespace synkro::prf;
using namespace synkro::scene;
using namespace synkro::script;
using namespace synkro::sound;
using namespace synkro::ui;
using namespace synkro::view;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


UInt GetStdParamCount();
Bool GetStdParam( UInt i, Param* param );


#ifdef SYNKRO_STATIC
	BaseFactory* _Factories = nullptr;
	BaseResource* _Resources = nullptr;
#endif // SYNKRO_STATIC


//------------------------------------------------------------------------------


Synkro::Synkro( Pointer module, UInt version, SynkroListener* listener ) :
	_created( false ),
	_inited( false ),
	_time( 0.0 ),
	_frame( 0 ),
	_language( Language::English ),
	_module( module ),
	_libs( A(P(Library)) ),
	_systems( A(ISystem*) ),
	_timers( A(TimerDesc) ),
	_listener( listener ),
	_updateListener( true ),
	_config( new Configuration() ),
	_diag( new Diag() ),
	_threadPool( nullptr ),
	Logger( nullptr, LogFacility::Core )
{
	SynkroCall( "Synkro.Synkro", String::Empty );
	SynkroProfile( "Synkro.Synkro" );

	ExceptionHandler::Initialize( _module, this );

	try
	{
		// Check library version for compatibility.
		const Version ver( version );
		if ( !ver.IsCompatible(Version::Current) )
			throw VersionException( ver );

		// Get default log.
		_log = _diag->GetLog();
		_facility = LogFacility::Core;

		// Retrieve library paths.
		GetPaths();

		// Register standard configuration parameters.
		RegisterParams();

		// Load libraries.
		LoadLibraries();

		// Initialize subsystems.
		_streamSystem = new StreamSystemEx( new NullStreamSystem(), _diag->GetLog() );
		InitWindowSystem( _config );

		// Everything went fine.
		_created = true;
	}
	catch ( const Exception& ex )
	{
		HandleException( ex );
	}	
}

Synkro::~Synkro()
{
	LogInfo( MessagePriority::Highest, Formatter::Format(L"Total objects allocated: {0}.", Platform::NextID()-1) );

	if ( _threadPool != nullptr )
	{
		LogInfo( MessagePriority::Highest, Formatter::Format(L"Total working threads created: {0}.", _threadPool->GetThreadCount()) );
		delete _threadPool;
	}
}

INodeList* Synkro::CreateNodeList()
{
	return new NodeList();
}

ITriangleMeshList* Synkro::CreateTriangleMeshList()
{
	return new TriangleMeshList();
}

String Synkro::ReadString( IStream* stream )
{
	TextReader rd( stream );
	return rd.ReadToEnd();
}

void Synkro::WriteString( IStream* stream, const String& text )
{
	TextWriter wr( stream );
	wr.Write( text );
}

IStringList* Synkro::SplitString( const String& str, Char delim )
{
	return new StringList( str, delim );
}

void Synkro::Run( const Bool& running )
{
	SynkroProfile( "Synkro.Run" );
	
	try
	{
		// Do not run until we're properly initialized.
		if ( !_inited )
			throw InvalidOperationException( L"Initialize() method is not called." );

		// Let UI and  console get the ultimate control over input.
		if ( _ui != nullptr )
		{
			_ui->InitInput();
		}

		// Enter main loop.
		_time = 0.0; _frame = 0;
		Double delta = _timer.GetElapsedSeconds();
		for ( ; running ; ++_frame )
		{
			SynkroProfile( "Synkro.Run.Step" );

			// Update subsystems.
			SynkroProfileBegin( "Synkro.Run.Step.Systems" );
			delta = _timer.GetElapsedSeconds();
			_time += delta;
			for ( UInt i = 0; i < _systems.Size(); ++i )
			{
				// Exit loop, if needed.
				if ( !_systems[i]->Update(delta) )
					return;
			}
			SynkroProfileEnd();

			// Update system event listeners.
			SynkroProfileBegin( "Synkro.Run.Step.Listener" );
			if ( (_listener != nullptr) && _updateListener )
			{
				_listener->OnSynkroUpdate( delta );
			}
			SynkroProfileEnd();

			// Update timers.
			SynkroProfileBegin( "Synkro.Run.Step.Timers" );
			for ( UInt i = 0; i < _timers.Size(); ++i )
			{
				TimerDesc& timer = _timers[i];
				timer.Time -= delta;
				if ( timer.Time <= 0.0 )
				{
					timer.Time += CastDouble(timer.Interval)*0.001;
					timer.Listener->OnTimerTick( timer.ID );
				}
			}
			SynkroProfileEnd();
		}
	}
	catch ( const Exception& ex )
	{
		HandleException( ex );
	}
}

void Synkro::Execute( Task* task )
{
	if ( _threadPool != nullptr )
	{
		_threadPool->AddTask( task );
	}
}

Bool Synkro::Configure( IConfiguration* config )
{
	SynkroCall( "Synkro.Configure", String::Empty );
	SynkroProfile( "Synkro.Configure" );

	AsBaseLog( _diag->GetLog() )->Pause( true );

	// Create temporary configuration.
	P(IConfiguration) cfg = _config->Clone();
	cfg->Set( Param::CoreThreadPoolCapacity, CastUInt(1) );
	cfg->Set( Param::AnimationEnable, true );
	cfg->Set( Param::ImagingEnable, true );
	cfg->Set( Param::GraphicsSampleCount, CastUInt(8) );

	// Initialize thread pool.
	InitThreadPool( cfg );

	// Initialize core subsystems.
	InitAnimationSystem( cfg );
	InitWindowSystem( cfg );

	// Initialize editor and environment.
	ConfigurationEditor::Initialize( _module, this );
	InitGraphicsSystem( cfg );
	InitImageManager( cfg );
	InitMaterialManager( cfg );
	InitOverlayManager( cfg );
	InitSceneManager( cfg );
	InitViewportManager( cfg );
	_systems.Add( _graphicsSystem );
	_inited = true;

	// Run environment.
	_updateListener = false;
	ConfigurationEditor::Show( config );
	_updateListener = true;
	_inited = false;
	_timers.Clear();

	// Remove graphics system.
	_systems.Remove( _systems.Size()-1 );

	// Finalize editor.
	ConfigurationEditor::Finalize();
	Destroy();

	AsBaseLog( _diag->GetLog() )->Pause( false );

	// Get user's choice.
	return ConfigurationEditor::GetResult();
}

IResource* Synkro::CreateResource( const Byte* data, UInt size )
{
	return new Resource( none, data, size );
}

UInt Synkro::CreateTimer( UInt interval, TimerListener* listener )
{
	assert( listener != nullptr );

	UInt id = _timers.Size();
	_timers.Add( TimerDesc(id, interval, listener) );
	return id;
}

void Synkro::Initialize( IConfiguration* config )
{
	SynkroCall( "Synkro.Initialize", String::Empty );
	SynkroProfile( "Synkro.Initialize" );

	if ( !_created || _inited )
		return;

	try
	{
		// Dump actual configuration.
		Dump( config );

		// Initialize thread pool.
		InitThreadPool( config );

		// Initialize required sub-systems.
		InitDiag( config );
		InitAnimationSystem( config );
		InitStreamSystem( config );
		InitDatabaseSystem( config );
		InitWindowSystem( config );
		InitInputSystem( config );
		InitAudioSystem( config );
		InitNetworkSystem( config );
		InitGraphicsSystem( config );
		InitImageManager( config );
		InitMaterialManager( config );
		InitSoundManager( config );
		InitOverlayManager( config );
		InitSceneManager( config );
		InitViewportManager( config );
		InitScriptSystem( config );
		InitUi( config );
		InitConsole( config );

		// Make sure graphics system is the last in the sub-systems list.
		if ( _graphicsSystem != nullptr )
		{
			_systems.Add( _graphicsSystem );
		}

		// Subscribe to frame window events.
		if ( _windowSystem->GetFrameWindowCount() > 0 )
		{
			_windowSystem->GetFrameWindow(0)->Listen( this );
		}

		// Initialize application.
		if ( _listener != nullptr )
		{
			_listener->OnSynkroInitialize();
		}

		_inited = true;
	}
	catch ( const Exception& ex )
	{
		HandleException( ex );
		_inited = false;
	}
}

void Synkro::OnWindowResize( UInt window, UInt width, UInt height )
{
}

void Synkro::OnWindowCommand( UInt window, UInt command )
{
}

void Synkro::OnWindowActivate( UInt window, Bool active )
{
	if ( active )
	{
		_timer.GetElapsedSeconds();
	}
}

Bool Synkro::OnWindowClosing( UInt window )
{
	return true;
}

void Synkro::Destroy()
{
	_inited = false;

	// Finalize sub-systems.
	if ( _ui != nullptr ) { _ui->Finalize(); }
	if ( _inputSystem != nullptr ) { _inputSystem->Finalize(); }
	if ( _graphicsSystem != nullptr ) { _graphicsSystem->Finalize(); }
	if ( _audioSystem != nullptr ) { _audioSystem->Finalize(); }
	if ( _windowSystem != nullptr ) { _windowSystem->Finalize(); }
}

void Synkro::InitThreadPool( IConfiguration* config )
{
	Int capacity; config->Get( Param::CoreThreadPoolCapacity, &capacity );

	if ( _threadPool != nullptr )
	{
		delete _threadPool;
	}

	_threadPool = new ThreadPool( capacity, _diag->GetLog() );

	if ( _animationSystem != nullptr )
	{
		_animationSystem->SetThreadPool( _threadPool );
	}

	if ( _imageManager != nullptr )
	{
		_imageManager->SetThreadPool( _threadPool );
	}
}

void Synkro::InitAnimationSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitAnimationSystem", String::Empty );
	SynkroProfile( "Synkro.InitAnimationSystem" );

	// See if the animation system is enabled.
	Bool enabled; config->Get( Param::AnimationEnable, &enabled );
	if ( !enabled )
	{
		if ( _animationSystem != nullptr )
		{
			_systems.Remove( _animationSystem );
			_animationSystem = nullptr;
		}
		return;
	}

	// Update thread pool, if already created.
	if ( _animationSystem != nullptr )
	{
		_animationSystem->SetThreadPool( _threadPool );
		return;
	}

	// Create animation system.
	_systems.Add( _animationSystem = new AnimationSystem(this, _diag->GetLog()) );
	_animationSystem->SetThreadPool( _threadPool );

	// Register animation codecs.
	UInt count = GetFactoryCount( Iface::AnimationCodec );
	for ( UInt i = 0; i < count; ++i )
	{
		_animationSystem->RegisterCodec( (IAnimationCodecFactory*)GetFactory(Iface::AnimationCodec, i) );
	}

	// Register animation track factories.
	count = GetFactoryCount( Iface::AnimationTrack );
	for ( UInt i = 0; i < count; ++i )
	{
		_animationSystem->RegisterTrackFactory( (IAnimationTrackFactory*)GetFactory(Iface::AnimationTrack, i) );
	}
}

void Synkro::InitAudioSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitAudioSystem", String::Empty );
	SynkroProfile( "Synkro.InitAudioSystem" );

	if ( ExistsOrDisabled(_audioSystem, config, Param::AudioEnable) )
		return;

	// Get sound format.
	String fmt; config->Get( Param::AudioFormat, &fmt );
	const SoundFormat soundFormat( fmt );
	_systems.Add( _audioSystem = new AudioSystemEx(soundFormat, _diag->GetLog()) );

	// Create audio system.
	Enum audioSystem; config->Get( Param::AudioSystem, &audioSystem );
	IAudioSystemFactory* factAudioSystem = (IAudioSystemFactory*)GetFactory( Iface::AudioSystem, audioSystem );
	if ( factAudioSystem == nullptr )
		throw Exception( L"Failed to instantiate audio system. System factory is missing." );

	_audioSystem->Initialize( factAudioSystem, soundFormat, GetWindowSystem() );
}

void Synkro::InitConsole( IConfiguration* config )
{
	SynkroCall( "Synkro.InitConsole", String::Empty );
	SynkroProfile( "Synkro.InitConsole" );

	if ( ExistsOrDisabled(_console, config, Param::ConsoleEnable) )
		return;

	// Create console.
	if ( _graphicsSystem->GetFrameWindowCount() > 0 )
	{
		IOverlay* overlay = _overlayManager->GetOverlay( (IRenderWindow*)(IFrameRenderWindow*)_graphicsSystem->GetFrameWindow(0) );
		_console = new Console( this, overlay, _diag->GetLog() );

		// Register console commands.
		const ULong count = GetFactoryCount( Iface::ConsoleCommand );
		for ( ULong i = 0; i < count; ++i )
		{
			_console->RegisterCommand( (IConsoleCommandFactory*)GetFactory(Iface::ConsoleCommand, i) );
		}
	}

	// Initialize console.
	_console->InitInput();
}


void Synkro::InitDatabaseSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitDatabaseSystem", String::Empty );
	SynkroProfile( "Synkro.InitDatabaseSystem" );

	if ( ExistsOrDisabled(_databaseSystem, config, Param::DatabaseEnable) )
		return;

	_systems.Add( _databaseSystem = new DatabaseSystemEx(_diag->GetLog()) );

	// Create database system.
	Enum databaseSystem; config->Get( Param::DatabaseSystem, &databaseSystem );
	IDatabaseSystemFactory* factDatabaseSystem = (IDatabaseSystemFactory*)GetFactory( Iface::DatabaseSystem, databaseSystem );
	if ( factDatabaseSystem == nullptr )
		throw Exception( L"Failed to instantiate database system. System factory is missing." );

	_databaseSystem->Initialize( factDatabaseSystem );
}

void Synkro::InitDiag( IConfiguration* config )
{
	SynkroCall( "Synkro.InitDiag", String::Empty );
	SynkroProfile( "Synkro.InitDiag" );

	String logFileName; config->Get( Param::LogFileName, &logFileName );
	if ( !logFileName.IsEmpty() )
	{
		Int logLevel; config->Get( Param::LogLevel, &logLevel );
		Int logMode; config->Get( Param::LogMode, &logMode );
		AsBaseLog(_diag->GetLog())->Initialize( LogLevel(logLevel), LogMode(logMode) );

		IStream* stream = GetStreamSystem()->CreateStream( logFileName );
		Bool logPlain; config->Get( Param::LogFilePlain, &logPlain );
		Bool logFileAppend; config->Get( Param::LogFileAppend, &logFileAppend );
		Int logFileMaxSize; config->Get( Param::LogFileMaxSize, &logFileMaxSize );
		if ( logPlain )
		{
			PlainLogFile* logFile = new PlainLogFile( Version::Current.ToString(), stream, CastUInt(logFileMaxSize), logFileAppend );
			_diag->GetLog()->Listen( logFile );
			_logFile = logFile;
		}
		else
		{
			RichLogFile* logFile = new RichLogFile( Version::Current.ToString(), stream, CastUInt(logFileMaxSize), logFileAppend );
			_diag->GetLog()->Listen( logFile );
			_logFile = logFile;
		}
	}
}

void Synkro::InitGraphicsSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitGraphicsSystem", String::Empty );
	SynkroProfile( "Synkro.InitGraphicsSystem" );

	if ( _windowSystem->GetFrameWindowCount() == 0 )
		return;

	if ( _graphicsSystem == nullptr )
	{
		_graphicsSystem = new GraphicsSystemEx( _diag->GetLog() );
	}

	// Create graphics system.
	Enum graphicsSystem; config->Get( Param::GraphicsSystem, &graphicsSystem );
	IGraphicsSystemFactory* factGraphicsSystem = (IGraphicsSystemFactory*)GetFactory( Iface::GraphicsSystem, graphicsSystem );
	if ( factGraphicsSystem == nullptr )
		throw Exception( L"Failed to instantiate graphics system. System factory is missing." );

	Int deviceType; config->Get( Param::GraphicsDevice, &deviceType );
	_graphicsSystem->Initialize( factGraphicsSystem, (GraphicsDeviceType)deviceType, _windowSystem );

	// Add program libraries.
	String systemName = GraphicsSystem(graphicsSystem).ToString();
	const UInt resCount = GetResourceCount( ResourceType::GraphicsProgram );
	for ( UInt i = 0; i < resCount; ++i )
	{
		IStreamDirectory* dir = LoadResource( ResourceType::GraphicsProgram, i );
		_graphicsSystem->AddProgramLibrary( dir, systemName );
	}

	String programLibs; config->Get( Param::GraphicsProgramLibrary, &programLibs );
	if ( !programLibs.IsEmpty() )
	{
		const UInt libCount = programLibs.EntryCount( L'|' );
		for ( UInt i = 0; i < libCount; ++i )
		{
			String lib( programLibs.Entry(i, L'|') );
			IStreamDirectory* dir = _streamSystem->GetDirectory( lib );
			if ( dir == nullptr )
				throw Exception( String::Format(L"Program library {0,q} is not found.", lib) );

			_graphicsSystem->AddProgramLibrary( dir, systemName );
		}
	}

	// Initialize program cache.
	String programCache; config->Get( Param::GraphicsProgramCache, &programCache );
	IStreamDirectory* cache = CreatePath( programCache );
	_graphicsSystem->SetProgramCache( cache );

	// Preload programs.
	String programs; config->Get( Param::GraphicsProgramPreload, &programs );
	if ( !programs.IsEmpty() )
	{
		const UInt programCount = programs.EntryCount( L'|' );
		for ( UInt i = 0; i < programCount; ++i )
		{
			String program = programs.Entry( i, L'|' );
			_graphicsSystem->GetProgram( program );
		}
	}

	String fmtDepth; config->Get( Param::GraphicsDepthFormat, &fmtDepth );
	const DepthFormat depthFormat = DepthFormat( fmtDepth );
	String mode; config->Get( Param::GraphicsDisplayMode, &mode );
	Bool fullscreen; config->Get( Param::GraphicsFullscreen, &fullscreen );
	const DisplayMode displayMode( mode, fullscreen );
	Bool vsync; config->Get( Param::GraphicsVsync, &vsync );
	Int sampleCount; config->Get( Param::GraphicsSampleCount, &sampleCount );
	_graphicsSystem->Init( depthFormat, displayMode, vsync, CastUInt(sampleCount) );
}

void Synkro::InitImageManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitImageManager", String::Empty );
	SynkroProfile( "Synkro.InitImageManager" );

	Bool enabled; config->Get( Param::ImagingEnable, &enabled );
	if ( !enabled )
		return;

	// Update thread pool, if already created.
	if ( _imageManager != nullptr )
	{
		_imageManager->SetThreadPool( _threadPool );
		return;
	}

	// Create image manager.
	Int quality; config->Get( Param::ImagingCodecQuality, &quality );
	_imageManager = new ImageManager( CastFloat(Clamp(quality, 1, 100))/100.0f, _graphicsSystem, _diag->GetLog() );
	_imageManager->SetThreadPool( _threadPool );

	// Register image codecs.
	const UInt count = GetFactoryCount( Iface::ImageCodec );
	for ( UInt i = 0; i < count; ++i )
	{
		_imageManager->RegisterCodec( (IImageCodecFactory*)GetFactory(Iface::ImageCodec, i) );
	}
}

void Synkro::InitInputSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitInputSystem", String::Empty );
	SynkroProfile( "Synkro.InitInputSystem" );

	if ( ExistsOrDisabled(_inputSystem, config, Param::InputEnable) )
		return;

	// Create input system.
	if ( _inputSystem == nullptr )
	{
		_systems.Add( _inputSystem = new InputSystemEx(GetModule(), _diag->GetLog()) );
	}

	// Initialize input system.
	Enum inputSystem; config->Get( Param::InputSystem, &inputSystem );
	IInputSystemFactory* factInputSystem = (IInputSystemFactory*)GetFactory( Iface::InputSystem, inputSystem );
	if ( factInputSystem == nullptr )
		throw Exception( L"Failed to instantiate input system. System factory is missing." );

	_inputSystem->Initialize( factInputSystem, _windowSystem );
}

void Synkro::InitMaterialManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitMaterialManager", String::Empty );
	SynkroProfile( "Synkro.InitMaterialManager" );

	// Create material manager.
	if ( _materialManager == nullptr )
	{
		_systems.Add( _materialManager = new MaterialManager(this, _diag->GetLog()) );
	}
}

void Synkro::InitNetworkSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitNetworkSystem", String::Empty );
	SynkroProfile( "Synkro.InitNetworkSystem" );

	if ( ExistsOrDisabled(_networkSystem, config, Param::NetworkEnable) )
		return;

	// Create network system.
	if ( _networkSystem == nullptr )
	{
		_systems.Add( _networkSystem = new NetworkSystemEx(_diag->GetLog()) );
	}

	// Initialize network system.
	Enum networkSystem; config->Get( Param::NetworkSystem, &networkSystem );
	INetworkSystemFactory* factNetworkSystem = (INetworkSystemFactory*)GetFactory( Iface::NetworkSystem, networkSystem );
	if ( factNetworkSystem == nullptr )
		throw Exception( L"Failed to instantiate network system. System factory is missing." );

	_networkSystem->Initialize( factNetworkSystem );
}

void Synkro::InitOverlayManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitOverlayManager", String::Empty );
	SynkroProfile( "Synkro.InitOverlayManager" );

	if ( (_windowSystem == nullptr) || (_graphicsSystem == nullptr) )
		return;

	if ( _overlayManager == nullptr )
	{
		// Create overlay manager.
		_systems.Add( _overlayManager = new OverlayManager(this, _diag->GetLog()) );
	}
	_overlayManager->Init();
}

void Synkro::InitSceneManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitSceneManager", String::Empty );
	SynkroProfile( "Synkro.InitSceneManager" );

	if ( (_sceneManager != nullptr) || (_windowSystem == nullptr) )
		return;

	// Create scene manager.
	_systems.Add( _sceneManager = new SceneManager(this, _diag->GetLog()) );

	// Register scene factories.
	const UInt factoryCount = GetFactoryCount( Iface::Scene );
	for ( UInt i = 0; i < factoryCount; ++i )
	{
		_sceneManager->RegisterSceneFactory( (ISceneFactory*)GetFactory(Iface::Scene, i) );
	}

	// Register mesh builders.
	const UInt builderCount = GetFactoryCount( Iface::MeshBuilder );
	for ( UInt i = 0; i < builderCount; ++i )
	{
		_sceneManager->RegisterMeshBuilder( (IMeshBuilderFactory*)GetFactory(Iface::MeshBuilder, i) );
	}

	// Register mesh codecs.
	const UInt codecCount = GetFactoryCount( Iface::MeshCodec );
	for ( UInt i = 0; i < codecCount; ++i )
	{
		_sceneManager->RegisterMeshCodec( (IMeshCodecFactory*)GetFactory(Iface::MeshCodec, i) );
	}
}

void Synkro::InitScriptSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitScriptSystem", String::Empty );
	SynkroProfile( "Synkro.InitScriptSystem" );

	if ( ExistsOrDisabled(_scriptSystem, config, Param::ScriptEnable) )
		return;

	// Create script system.
	if ( _scriptSystem == nullptr )
	{
		_systems.Add( _scriptSystem = new ScriptSystemEx(_diag->GetLog()) );
	}

	// Initialize script system.
	Enum scriptSystem; config->Get( Param::ScriptSystem, &scriptSystem );
	IScriptSystemFactory* factScriptSystem = (IScriptSystemFactory*)GetFactory( Iface::ScriptSystem, scriptSystem );
	if ( factScriptSystem == nullptr )
		throw Exception( L"Failed to instantiate scripting system. System factory is missing." );

	_scriptSystem->Initialize( factScriptSystem );
}

void Synkro::InitSoundManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitSoundManager", String::Empty );
	SynkroProfile( "Synkro.InitSoundManager" );
	
	if ( (_soundManager != nullptr) || (_audioSystem == nullptr) )
		return;

	// Create sound manager.
	_systems.Add( _soundManager = new SoundManager(this, _diag->GetLog()) );

	// Register sound codecs.
	const UInt count = GetFactoryCount( Iface::SoundCodec );
	for ( UInt i = 0; i < count; ++i )
	{
		_soundManager->RegisterCodec( (ISoundCodecFactory*)GetFactory(Iface::SoundCodec, i) );
	}
}

void Synkro::InitStreamSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitStreamSystem", String::Empty );
	SynkroProfile( "Synkro.InitStreamSystem" );

	// Create underlying stream system.
	Enum streamSystem; config->Get( Param::StreamSystem, &streamSystem );
	IStreamSystemFactory* factStreamSystem = (IStreamSystemFactory*)GetFactory( Iface::StreamSystem, streamSystem );
	if ( factStreamSystem == nullptr )
		throw Exception( L"Failed to instantiate stream system. System factory is missing." );

	_streamSystem->Initialize( factStreamSystem->Create(_diag->GetLog()) );

	// Register stream directory factories.
	const UInt count = GetFactoryCount( Iface::StreamDirectory );
	for ( UInt i = 0; i < count; ++i )
	{
		_streamSystem->RegisterDirectoryFactory( (IStreamDirectoryFactory*)GetFactory(Iface::StreamDirectory, i) );
	}

	// Add search paths.
	String paths; config->Get( Param::StreamPath, &paths );
	if ( !paths.IsEmpty() )
	{
		const UInt pathCount = paths.EntryCount( L'|' );
		for ( UInt i = 0; i < pathCount; ++i )
		{
			String path = paths.Entry( i, L'|' );
			if ( !Path::IsAbsolute(path) )
			{
				path = Path::MakeAbsolute( _pathStart, path );
			}
			_streamSystem->MapDirectory( path, true );
		}
	}
}

void Synkro::InitUi( IConfiguration* config )
{
	SynkroCall( "Synkro.InitUi", String::Empty );
	SynkroProfile( "Synkro.InitUi" );

	if ( ExistsOrDisabled(_ui, config, Param::UiEnable) )
		return;

	if ( _graphicsSystem->GetFrameWindowCount() == 0 )
		throw Exception( L"Failed to create user interface. Frame rendering window is missing." );

	// Create UI.
	if ( _ui == nullptr )
	{
		_systems.Add( _ui = new UiEx(_diag->GetLog()) );
	}

	// Perform initialization.
	Enum uiType; config->Get( Param::UiType, &uiType );
	IUiFactory* factUi = (IUiFactory*)GetFactory( Iface::Ui, uiType );
	if ( factUi == nullptr )
		throw Exception( L"Failed to instantiate user interface. UI factory is missing." );

	Int fontSize; config->Get( Param::UiFontSize, &fontSize );
	_ui->Initialize( factUi, this, _language, fontSize );

	// Add theme libraries.
	const UInt resCount = GetResourceCount( ResourceType::UiTheme );
	for ( UInt i = 0; i < resCount; ++i )
	{
		P(IStreamDirectory) res = GetResource(ResourceType::UiTheme, i)->Load();
		_ui->AddThemeLibrary( res );
	}

	// Add theme resources.
	String themes; config->Get( Param::UiTheme, &themes );
	if ( !themes.IsEmpty() )
	{
		const UInt themeCount = themes.EntryCount( L'|' );
		for ( UInt i = 0; i < themeCount; ++i )
		{
			String lib( themes.Entry(i, L'|') );
			P(IStreamDirectory) dir = _streamSystem->GetDirectory( lib );
			if ( dir == nullptr )
				throw Exception( String::Format(L"Theme library {0,q} is not found.", lib) );

			_ui->AddThemeLibrary( dir );
		}
	}

	// Create internal UI.
	Color widgetColors[4]; Color textColors[4];
	Color color; Color colorNormal; Color colorDefault;

	config->Get( Param::UiColorWidgetNormal, &colorNormal );
	widgetColors[WidgetState::Normal] = colorNormal;
	config->Get( Param::UiColorWidgetActive, &color );
	colorDefault = Color( config->GetParam(Param::UiColorWidgetActive)->DefaultValue );
	widgetColors[WidgetState::Active] = (color != colorDefault) ? color : colorNormal*1.4f;
	config->Get( Param::UiColorWidgetHovered, &color );
	colorDefault = Color( config->GetParam(Param::UiColorWidgetHovered)->DefaultValue );
	widgetColors[WidgetState::Hovered] = (color != colorDefault) ? color : colorNormal*1.5f;
	config->Get( Param::UiColorWidgetDisabled, &color );
	widgetColors[WidgetState::Disabled] = color;

	config->Get( Param::UiColorTextNormal, &colorNormal );
	textColors[WidgetState::Normal] = colorNormal;
	config->Get( Param::UiColorTextActive, &color );
	colorDefault = Color( config->GetParam(Param::UiColorTextActive)->DefaultValue );
	textColors[WidgetState::Active] = (color != colorDefault) ? color : colorNormal*1.4f;
	config->Get( Param::UiColorTextHovered, &color );
	colorDefault = Color( config->GetParam(Param::UiColorTextHovered)->DefaultValue );
	textColors[WidgetState::Hovered] = (color != colorDefault) ? color : colorNormal*1.5f;
	config->Get( Param::UiColorTextDisabled, &color );
	textColors[WidgetState::Disabled] = color;

	Enum themeName; config->Get( Param::UiThemeName, &themeName );
	_ui->Create( (ThemeName)themeName, widgetColors, textColors, 4 );
}

void Synkro::InitViewportManager( IConfiguration* config )
{
	SynkroCall( "Synkro.InitViewportManager", String::Empty );
	SynkroProfile( "Synkro.InitViewportManager" );

	if ( _graphicsSystem == nullptr )
		return;

	if ( _viewportManager == nullptr )
	{
		// Create viewport manager.
		_systems.Add( _viewportManager = new ViewportManager(this, _diag->GetLog()) );

		// Register viewport filter factories.
		const UInt filterCount = GetFactoryCount( Iface::ViewportFilter );
		for ( UInt i = 0; i < filterCount; ++i )
		{
			_viewportManager->RegisterViewportFilterFactory( (IViewportFilterFactory*)GetFactory(Iface::ViewportFilter, i) );
		}
	}
	_viewportManager->Init();
}

void Synkro::InitWindowSystem( IConfiguration* config )
{
	SynkroCall( "Synkro.InitWindowSystem", String::Empty );
	SynkroProfile( "Synkro.InitWindowSystem" );

	if ( _windowSystem == nullptr )
	{
		_systems.Add( _windowSystem = new WindowSystemEx(_module, _diag->GetLog()) );
	}

	Enum windowSystem; config->Get( Param::WindowSystem, &windowSystem );
	IWindowSystemFactory* factWindowSystem = (IWindowSystemFactory*)GetFactory( Iface::WindowSystem, windowSystem );
	if ( factWindowSystem == nullptr )
		throw Exception( L"Failed to instantiate window system. System factory is missing." );

	_windowSystem->Initialize( factWindowSystem );
}

void Synkro::RegisterParams()
{
	SynkroCall( "Synkro.RegisterParams", String::Empty );
	SynkroProfile( "Synkro.RegisterParams" );

	assert( _config != nullptr );

	Param param;
	const UInt paramCount = GetStdParamCount();
	for ( UInt i = 0; i < paramCount; ++i )
	{
		if ( GetStdParam(i, &param) )
		{
			_config->RegisterParam( &param );
		}
	}

	// Prevent further modifications.
	_config->Lock();
}

void Synkro::RegisterResource( IResource* res )
{
	SynkroCall( "Synkro.RegisterResource", String::Empty );
	SynkroProfile( "Synkro.RegisterResource" );
	
	if ( res != nullptr )
	{
		const ResourceType type = res->GetType();
		if ( !_resources.Exists( type ) )
		{
			_resources.Add( type, ResourceList() );
		}
		_resources.Get(type).AddResource( res );
	}
}

void Synkro::RegisterFactory( IFactory* fact )
{
	SynkroCall( "Synkro.RegisterFactory", String::Empty );
	SynkroProfile( "Synkro.RegisterFactory" );
	
	if ( fact != nullptr )
	{
		const Iface ifaceID = fact->GetIfaceID();
		if ( !_factories.Exists( ifaceID ) )
		{
			_factories.Add( ifaceID, FactoryList() );
		}
		_factories.Get( ifaceID ).AddFactory( fact );
	}
}

Bool Synkro::RegisterLibrary( ILibrary* lib )
{
	// Skip release libraries in debug version and vice versa.
#ifdef SYNKRO_DEBUG
	if ( !lib->IsDebug() )
		return false;
#else
	if ( lib->IsDebug() )
		return false;
#endif // SYNKRO_DEBUG

	// Skip non-perf libraries in perf version and vice versa.
#ifdef SYNKRO_PERF
	if ( !lib->IsPerf() )
		return false;
#else
	if ( lib->IsPerf() )
		return false;
#endif // SYNKRO_PERF

	// Register resource strings.
	if ( lib->IsString() )
	{
		// Skip incompatible libraries.
		if ( lib->GetCoreVersion() != SYNKRO_VERSION )
			return false;

		const Language language = Language( lib->GetLanguage() );
		if ( language != Language::Unknown )
		{
			_language = language;
		}

		for ( UInt i = 0; i < lib->GetStringCount(); ++i )
		{
			Str::RegisterString( lib->GetStringName(i), lib->GetStringValue(i) );
		}
	}

	// Dump library name and version.
	const Version ver( lib->GetVersion() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Loading library: {0,q} {1}.{2}.{3}", lib->GetName(), CastDouble(ver.Major), CastDouble(ver.Minor), CastDouble(ver.Patch)) );

	// Skip incompatible libraries.
	if ( lib->GetCoreVersion() != SYNKRO_VERSION )
	{
		LogInfoEnd( Formatter::Format(L". Failed due to incompatible core version") );
		return false;
	}

	// Register object factories.
	if ( lib->IsObject() )
	{
		LogInfoContinue( Formatter::Format(L". Factory count: {0}", lib->GetFactoryCount()) );
		for ( UInt f = 0; f < lib->GetFactoryCount(); ++f )
		{
			RegisterFactory( lib->GetFactory(f) );
		}
	}

	// Register exported resources.
	if ( lib->IsResource() )
	{
		LogInfoContinue( Formatter::Format(L". Resource count: {0}", lib->GetResourceCount()) );
		for ( UInt r = 0; r < lib->GetResourceCount(); ++r )
		{
			RegisterResource( lib->GetResource(r) );
		}
	}

	LogInfoContinue( Formatter::Format(L". ") );
	LogInfoEnd( Formatter::Format(Str::Done) );
	return true;
}

void Synkro::LoadLibraries()
{
	SynkroCall( "Synkro.LoadLibraries", String::Empty );
	SynkroProfile( "Synkro.LoadLibraries" );

#ifdef SYNKRO_STATIC

	// Register object factories.
	BaseFactory* fact = _Factories;
	for ( ; fact != nullptr ; fact = fact->Next )
	{
		fact->Init();
		RegisterFactory( fact->Fact );
	}

	// Register exported resources.
	BaseResource* res = _Resources;
	for ( ; res != nullptr ; res = res->Next )
	{
		RegisterResource( res->Res );
	}

#else

	// Get the list of files in the current directory.
	String ext( Platform::DynamicLibraryExtension );
	Vector<String> files( A(String) );
	Path::GetFiles( _pathMain, String(L'*').Append(ext), &files );
	for ( UInt i = 0; i < files.Size(); ++i )
	{
		files[i] = files[i].Substring( 0, files[i].Length()-ext.Length() );
	}
	files.Sort();

	// Try registering found libraries.
	_libs.Clear();
	for ( UInt i = 0; i < files.Size(); ++i )
	{
		P(Library) lib = new Library( files[i].Append(ext) );
		if ( lib->IsValid() && RegisterLibrary(lib) )
		{
			_libs.Add( lib );
		}
	}

#endif // SYNKRO_STATIC
}

void Synkro::GetPaths()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	Char fileModule[MAX_PATH];
	::GetModuleFileNameW( (HINSTANCE)_module, fileModule, MAX_PATH );
	_pathMain = Path(fileModule).GetParent();

	Char dir[MAX_PATH];
	::GetCurrentDirectoryW( MAX_PATH, dir );
	_pathStart = Path( dir ).GetPath();
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void Synkro::HandleException( const Exception& ex )
{
	LogError( MessagePriority::Highest, ex.ToString() );

	// Let the listener do custom handling.
	if ( (_listener != nullptr) && _listener->OnSynkroException(ex) )
		return;

	// Do default handling.
	ex.Show();
}

Bool Synkro::ExistsOrDisabled( ISystem* system, IConfiguration* config, const String& param ) const
{
	Bool enabled = false;
	return (system != nullptr) || (config->Get(param, &enabled), !enabled);
}

void Synkro::Dump( IConfiguration* config )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Dumping configuration...") );

	String name = config->GetFirstParam();
	Int valueInt = 0; Bool valueBool = false; String valueStr; UInt entryCount = 0;
	for ( ; !name.IsEmpty(); name = config->GetNextParam() )
	{
		const Param* param = config->GetParam( name );
		switch ( param->Type )
		{
			case PARAM_TYPE_INTEGER:
				config->Get( name, &valueInt );
				LogInfo( MessagePriority::Lowest, Formatter::Format(L"Param: {0,q} Value: {1}", name, valueInt) );
				break;

			case PARAM_TYPE_BOOLEAN:
				config->Get( name, &valueBool );
				LogInfo( MessagePriority::Lowest, Formatter::Format(L"Param: {0,q} Value: {1}", name, valueBool ? L"true" : L"false"));
				break;

			case PARAM_TYPE_LIST:
				config->Get( name, &valueStr );
				entryCount = valueStr.EntryCount( L'|' );
				for ( UInt i = 0; i < entryCount; ++i )
				{
					LogInfo( MessagePriority::Lowest, Formatter::Format(L"Param: {0,q} Value: {1}", name, valueStr.Entry(i, L'|')) );
				}
				break;

			default:
				config->Get( name, &valueStr );
				LogInfo( MessagePriority::Lowest, Formatter::Format(L"Param: {0,q} Value: {1}", name, valueStr) );
				break;
		}
	}
}

IStreamDirectory* Synkro::CreatePath( const String& path )
{
	IStreamDirectory* dir = nullptr;

	if ( !path.IsEmpty() )
	{
		String pathAbs( path );
		if ( !Path::IsAbsolute(pathAbs) )
		{
			pathAbs = Path::MakeAbsolute( _pathStart, pathAbs );
		}

		dir = _streamSystem->MapDirectory( pathAbs, true );
		if ( dir == nullptr )
		{
			dir = _streamSystem->BuildDirectory( pathAbs );
		}
	}

	return dir;
}


} // core


} // synkro
