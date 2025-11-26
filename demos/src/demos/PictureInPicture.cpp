#include "../Demo.h"


class PictureInPicture :
	public Demo,
	public TimerListener
{
public:
	PictureInPicture() :
		Demo( L"Picture-In-Picture" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		IImage* imageTwinPeaks = GetImage( L"twin_peaks.jpg" );
		_material = CreateMaterial( diffuseMap );
		_materialFloor = CreateFloorMaterial( imageTwinPeaks );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, 1.0f, 0.0f) );

		// Create world node.
		_world = _scene->CreateDummy( nullptr, L"World" );
		_worldCtrl = _world->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = _worldCtrl->CreateOrientationYawTrack(AnimationTrack::FloatWave)->AsWave();
		trackYaw->SetType( WaveType::SawtoothUp );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 0.00125f );
		_worldCtrl->SetMode( AnimationMode::Loop );
		_worldCtrl->SetSpeed( 100.0 );
		_worldCtrl->Start( true );
		
		// Create floor and primitives.
		constexpr Float DISTANCE = 30.0f; constexpr Float FLOOR_SIZE = 250.0f;
		_floor = CreatePlane( nullptr, _materialFloor, FLOOR_SIZE, FLOOR_SIZE, 16, Matrix4x4::Identity, Vector3::Origin );
		constexpr Float TORUS_RADIUS = 5.0f; constexpr Float SPHERE_RADIUS = 10.0f; constexpr Float CUBE_SIDE = 18.0f; constexpr Float PYRAMID_HEIGHT = 18.0f; constexpr Float CYLINDER_HEIGHT = 18.0f;
		_torus = CreateTorus( _world, _material, TORUS_RADIUS, 2.0f*TORUS_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(0.0f, TORUS_RADIUS, 0.0f) );
		_sphere = CreateSphere( _world, _material, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(DISTANCE, SPHERE_RADIUS, 0.0f) );
		_cube = CreateCube( _world, _material, CUBE_SIDE, Matrix4x4::Identity, Vector3(-DISTANCE, 0.5f*CUBE_SIDE, 0.0f) );
		_pyramid = CreatePyramid( _world, _material, PYRAMID_HEIGHT, PYRAMID_HEIGHT, PYRAMID_HEIGHT, Matrix4x4::Identity, Vector3(0.0f, 0.0f, DISTANCE) );
		_cylinder = CreateCylinder( _world, _material, 8.0f, CYLINDER_HEIGHT, 40, 40, Matrix4x4::Identity, Vector3(0.0f, 0.5f*CYLINDER_HEIGHT, -DISTANCE) );

		// Setup timer.
		_timer = _synkro->CreateTimer( 3000, this );
	}

	void InitView() override
	{
		// Setup viewport and cameras.
		_viewport->SetColor( Color::RoyalBlue );
		_viewport->SetLabelColor( Color::Red );
		_viewport->ShowLabel( true );
		_camera->SetPosition( Vector3(0.0f, 50.0f, -170.0f) );
		_camera->LookAt( Vector3::Origin );
		_camera->SetFront( 1.0f );
		_camera->SetBack( 1000.0f );

		// Setup picture-in-picture.
		_camera2 = _scene->CreateCamera( nullptr, String::Empty );
		_camera2->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
		_camera2->SetAspect( _displayModeWindowed.AspectFactor() );
		_camera2->SetFront( 0.1f );
		_camera2->SetBack( 10000.0f );
		_camera2->SetPosition( Vector3(0.0f, 180.0f, -10.0f) );
		_camera2->LookAt( Vector3::Origin );

		IWindow* window = _synkro->GetWindowSystem()->GetFrameWindow( 0 );
		_picture = _synkro->GetViewportManager()->CreateViewport( _window, Rect(Point(window->GetWidth()-330, window->GetHeight()-250), Size(320, 240)), _camera2, Color::LightGray );
		_picture->SetBorderColor( Color::Red );
		_picture->SetLabelColor( Color::DarkOrange );
		_picture->ShowBorder( true );
		_picture->ShowLabel( true );
		_picture->SetOpacity( 1.0f );

		// Choose light ambient color.
		PickAmbientColor();
	}

	void InitUi() override
	{
		_labelSpeed = CreateLabel(Point(_widgetLeft, 440), L"Animation Speed");
		_sliderSpeed = CreateSlider( none, Point(_widgetLeft, 460), 0, 200, 100 );

		_labelOpacity = CreateLabel( Point(_widgetLeft, 490), L"Picture Opacity" );
		_sliderOpacity = CreateSlider( none, Point(_widgetLeft, 510), 0, 1000, 1000 );

		_optionCamera = CreateOption( none, Point(_widgetLeft, 540), L"Camera #1", null, false );
		_optionCamera2 = CreateOption( none, Point(_widgetLeft, 570), L"Camera #2", null, true );

		_switchBorder = CreateSwitch( Point(_widgetLeft, 600), 150, L"Show Border", true );
		_switchLabel = CreateSwitch( Point(_widgetLeft, 630), 150, L"Show Label", true );
		_switchDepth = CreateSwitch( Point(_widgetLeft, 660), 150, L"Show Depth", false );
	}

	void OnDisplayModeChanged( const DisplayMode& displayMode ) override
	{
		_picture->SetLocation( Point(displayMode.Width-330, displayMode.Height-250) );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _sliderSpeed )
		{
			_worldCtrl->SetSpeed( CastDouble(_sliderSpeed->GetPosition()) );
			return true;
		}
		else if ( sender == _sliderOpacity )
		{
			_picture->SetOpacity( CastFloat(_sliderOpacity->GetPosition())*0.001f );
			return true;
		}
		else if ( sender == _optionCamera )
		{
			_picture->SetCamera( _camera );
			return true;
		}
		else if ( sender == _optionCamera2 )
		{
			_picture->SetCamera( _camera2 );
			return true;
		}
		else if ( sender == _switchBorder )
		{
			_picture->ShowBorder( _switchBorder->IsOn() );
			return true;
		}
		else if ( sender == _switchLabel )
		{
			_picture->ShowLabel( _switchLabel->IsOn() );
			return true;
		}
		else if ( sender == _switchDepth )
		{
			_viewport->SetViewMode( _switchDepth->IsOn() ? ViewMode::Depth : ViewMode::Color );
			return true;
		}

		return false;
	}

	// TimerListener methods.
	void OnTimerTick( UInt timer )
	{
		if ( timer == _timer )
		{
			PickAmbientColor();
		}
	}

	IOpaqueMaterial* CreateFloorMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetSpecularColor( Color::Black );
		material->SetSpecularPower( 10.0f );
		return material;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		material->SetSpecularPower( 10.0f );
		return material;
	}

	void PickAmbientColor()
	{
		Color color = Color::Random();
		_light->SetAmbientColor( color );
		_viewport->SetLabelText( color.ToString() );
	}

private:
	PtrOpaqueMaterial										_materialFloor;
	PtrOpaqueMaterial										_material;
	PtrDirectLight											_light;
	PtrNode													_world;
	INodeAnimationController*								_worldCtrl;
	PtrTriangleMesh											_floor;
	PtrTriangleMesh											_torus;
	PtrTriangleMesh											_sphere;
	PtrTriangleMesh											_cube;
	PtrTriangleMesh											_pyramid;
	PtrTriangleMesh											_cylinder;
	PtrViewport												_picture;
	PtrCamera												_camera2;

	PtrLabel												_labelSpeed;
	PtrSlider												_sliderSpeed;
	PtrLabel												_labelOpacity;
	PtrSlider												_sliderOpacity;
	PtrOption												_optionCamera;
	PtrOption												_optionCamera2;
	PtrSwitch												_switchBorder;
	PtrSwitch												_switchLabel;
	PtrSwitch												_switchDepth;

	UInt													_timer;
};

SYNKRO_DEMO_BEGIN
	PictureInPicture demo;
	demo.Run();
SYNKRO_DEMO_END
