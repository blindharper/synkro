#include "../Demo.h"


class SkyIsBlue :
	public Demo
{
public:
	SkyIsBlue() :
		Demo( L"Sky Is Blue" )
	{
	}

	void InitScene() override
	{
		// Create sky.
		SetSkySphere();
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3::Origin );
		_camera->SetBack( 16000.0f );

		Random rnd;
		_ctrlCamera = _camera->CreateAnimationController( nullptr, nullptr );
		PtrNoiseQuaternionTrack trackOrientation = _ctrlCamera->CreateOrientationTrack( AnimationTrack::QuaternionNoise )->AsNoise();
		trackOrientation->SetMagnitude( Math::Pi );
		trackOrientation->SetSeed( rnd.GetUInt() );
		_ctrlCamera->SetMode( AnimationMode::Loop );
	}

	void InitUi() override
	{
		// Create UI widgets.
		_btnSkySphere = CreateButton( none, Point( _widgetLeft, 120 ), L"Sky [S]phere", Anchor::TopRight, HotKey( Key::S, true ) );
		_btnSkyBox = CreateButton( none, Point( _widgetLeft, 150 ), L"Sky [B]ox", Anchor::TopRight, HotKey( Key::B, true ) );
		_switchAnimateCamera = CreateSwitch( Point(_widgetLeft, 180), 160, L"[A]nimate camera", HotKey(Key::A, true), false );
	}

	// ArcballListener methods.
	Bool ListenArcballInput() const override
	{
		return true;
	}

	Bool OnArcballOriented( const Quaternion& orientation ) override
	{
		_camera->SetOrientation( orientation );
		return true;
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		// Handle button clicks.
		if ( sender == _btnSkySphere )
		{
			SetSkySphere();
			return true;
		}
		else if ( sender == _btnSkyBox )
		{
			SetSkyBox();
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchAnimateCamera )
		{
			_ctrlCamera->Start( _switchAnimateCamera->IsOn() );
			return true;
		}

		return false;
	}

	void SetSkySphere()
	{
		PtrImage imageSky = GetImage( L"Spherical_Panorama_2560px.jpg" );
		_scene->SetSky( imageSky, 15000.0f );
	}

	void SetSkyBox()
	{
		PtrImage imageSky = GetImage( GetStreams(L"sky", L"sky*.bmp") );
		_scene->SetSky( imageSky, 15000.0f );
	}

private:
	PtrNodeAnimationController								_ctrlCamera;

	PtrButton												_btnSkySphere;
	PtrButton												_btnSkyBox;
	PtrSwitch												_switchAnimateCamera;
};

SYNKRO_DEMO_BEGIN
	SkyIsBlue demo;
	demo.Run();
SYNKRO_DEMO_END
