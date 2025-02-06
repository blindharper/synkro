#include "App.h"
#include "../Networking.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::net;
using namespace synkro::scene;

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true )
{
}

void App::Run()
{
	// Create configuration.
	Configure();

	// Create main window.
	String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
	_displayModeWindowed = DisplayMode( mode, false );
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Animation Client", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	InitScene();
	InitView();
	InitNetwork();

	// Setup timer.
	_timer = _synkro->CreateTimer( 1000, this );
}

void App::OnSynkroUpdate( Double delta )
{
	// Do nothing.
}

Bool App::OnSynkroException( const Exception& ex )
{
	return false;
}

Bool App::OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const NetworkMessage* message, UInt size )
{
	if ( message->Type == SERVER_RESPONSE )
	{
		ServerResponse* res = (ServerResponse*)message;
		if ( _animationSet != res->Animation )
		{
			_skeletonCtrl->SetAnimationSet( res->Animation );
			_skeletonCtrl->Restart();
			_animationSet = res->Animation;
		}
		return true;
	}
	return false;
}

void App::OnTimerTick( UInt timer )
{
	if ( timer == _timer )
	{
		NetworkMessage msg( CLIENT_CONNECT );
		_client->Send( _server, &msg, sizeof(msg) );
	}
}

void App::Configure()
{
	// Set configuration parameters.
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, true );
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::Medium.Index() );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::LogFileName, String(L"AnimationClient.txt") );
	_config->Set( Param::LogFilePlain, true );
	_config->Set( Param::LogFileAppend, false );
	_config->Set( Param::LogLevel, LogLevel::Extensive );
	_config->Set( Param::LogMode, LogMode::All );
	_config->Set( Param::StreamPath, String(L"../../media") );
	_config->Set( Param::NetworkEnable, true );
	_config->Set( Param::NetworkSystem, NetworkSystem::WinSock2 );
	_config->Set( Param::UiEnable, false );
}

void App::InitScene()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, false );

	// Setup camera.
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_camera->SetAspect( _displayModeWindowed.AspectFactor() );
	_camera->SetPosition( Vector3(0.0f, 100.0f, -150.0f) );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );
	_camera->LookAt( Vector3(0.0f, 25.0f, 0.0f) );

	// Load model.
	PtrStream stream = GetStream( L"tiny_anim.x" );
	ISkeleton* skeleton = _synkro->GetSceneManager()->CreateSkeleton();
	_tiny = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
	const Float radius = _tiny->GetBoundSphere();
	_tiny->SetScale( 45.0f/radius );
	_tiny->SetOrientationPitch( Math::HalfPi );
	_tiny->SetOrientationRoll( Math::Pi );

	// Animate model.
	_skeletonCtrl = _tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
	_skeletonCtrl->SetMode( AnimationMode::Loop );
	_skeletonCtrl->SetDirection( AnimationDirection::Forward );
	_skeletonCtrl->SetLoopCount( 0 );
	_skeletonCtrl->SetSpeed( 4.0 );
}

void App::InitView()
{
	// Setup viewport.
	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetFrameWindow(0)->GetView(0) );
	_viewport->SetCamera( _camera );
	_viewport->SetColor( Color::DirectXDemo );
}

void App::InitNetwork()
{
	PtrStream streamIP = GetStream( IP_ADDRESS_FILE );
	NetworkAddress ip( _synkro->ReadString(streamIP) );
	INetworkDevice* dev = _synkro->GetNetworkSystem()->CreateRemoteDevice( ip.Address );
	_server = dev->CreatePeer( SERVER_PORT );

	_client = _synkro->GetNetworkSystem()->CreateDevice( 0 )->CreatePeer( CLIENT_PORT );
	_synkro->GetNetworkSystem()->GetDevice()->ListenEvent( this, SERVER_RESPONSE );
	_synkro->GetNetworkSystem()->GetDevice()->ListenPort( CLIENT_PORT );
}

IStream* App::GetStream( const String& name )
{
	PtrStream stream = _synkro->GetStreamSystem()->GetStream( name );
	if ( stream == nullptr )
		throw FileNotFoundException( name );
	return stream;
}
