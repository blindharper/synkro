#include "../Demo.h"


class LookAtMe :
	public Demo
{
public:
	LookAtMe() :
		Demo( L"Look At Me" )
	{
	}

	DebugMode GetDebugMode() const override
	{
		return DebugMode::Gizmos | DebugMode::Helpers | DebugMode::Constraints;
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create shared material.
		IImage* imageCheckers = GetImage( L"checkers.jpg" );
		IImage* imageTwinPeaks = GetImage( L"twin_peaks.jpg" );
		_materialFloor = CreateTexturedMaterial( imageTwinPeaks );
		_materialFloor->SetSpecularColor( Color::Black );

		// Create world node.
		_world = _scene->CreateDummy( nullptr, L"Center" );
		_world->SetPosition( Vector3(0.0f, 1.0f, -70.0f) );
		_world->ShowGizmo( false );
		INodeAnimationController* worldCtrl = _world->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = worldCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothUp );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0f/Math::Pi );
		trackYaw->SetPhase( Math::ToRadians(30.0f) );
		worldCtrl->SetMode( AnimationMode::Loop );
		worldCtrl->SetSpeed( 0.5 );
		worldCtrl->Start( true );

		// Create floor.
		Matrix4x4 trans;
		constexpr Float FLOOR_SIZE = 250.0f;
		_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _materialFloor, nullptr );
		_synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(250, 0), Matrix4x4::Identity );
		_floor->ShowGizmo( false );

		// Create sphere.
		constexpr Float SPHERE_RADIUS = 5.0f;
		IOpaqueMaterial* sphereMat = CreateTexturedMaterial( imageCheckers );
		sphereMat->SetTilingHorizontal( 8 );
		sphereMat->SetTilingVertical( 8 );
		sphereMat->SetAmbientColor( Color::OrangeAerospace );
		sphereMat->SetDiffuseColor( Color::OrangeAerospace );
		sphereMat->SetSpecularColor( Color::White );
		sphereMat->SetSpecularPower( 50.0f );
		_sphere = CreateSphere( _world, sphereMat, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(0.0f, SPHERE_RADIUS, 10.0f) );
		_sphere->ShowGizmo( false );

		// Create box.
		constexpr Float HEAD_SIDE = 18.0f;
		IImage* imageFace = GetImage( L"face.jpg" );
		IOpaqueMaterial* materialFace = CreateTexturedMaterial( imageFace );
		materialFace->SetDiffuseColor( Color::White );
		materialFace->SetAmbientColor( Color::White );
		materialFace->SetEmissiveColor( Color::White );
		IOpaqueMaterial* materialGray = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		materialGray->SetAmbientColor( Color::Gray );
		materialGray->SetDiffuseColor( Color::Gray );
		PtrMultiMaterial mat = _synkro->GetMaterialManager()->CreateMultiMaterial( 6 );
		mat->SetSubset( 0, materialGray );
		mat->SetSubset( 1, materialGray );
		mat->SetSubset( 2, materialGray );
		mat->SetSubset( 3, materialGray );
		mat->SetSubset( 4, materialGray );
		mat->SetSubset( 5, materialFace );
		_head = _scene->CreateTriangleMesh( nullptr, L"Head", mat, nullptr );
		_synkro->GetSceneManager()->BuildMesh( _head , MeshBuilder::Box, Vector4(HEAD_SIDE, 0.5f*HEAD_SIDE, HEAD_SIDE, 0.0f), Size(), trans );
		_head->SetPosition( Vector3(-20.0f, HEAD_SIDE, -20.0f) );
		_head->SetGizmoSize( 15.0f );

		// Create projector.
		_projector = _scene->CreateConeLight( nullptr, L"Projector" );
		_projector->SetDiffuseColor( Color::Yellow );
		_projector->SetSpecularColor( Color::White );
		_projector->SetInnerAngle( Math::ToRadians(15.0f) );
		_projector->SetOuterAngle( Math::ToRadians(90.0f) );
		_projector->SetPosition( Vector3(0.0f, 40.0f, -70.0f) );
		_projector->LookAt( Vector3(0.0f, 1.0f, -70.0f) );

		// Setup projector blinking animation.
		_projectorCtrl = _projector->CreateAnimationController( nullptr, nullptr )->AsLight();
		PtrWaveFloatTrack trackIntensity = _projectorCtrl->CreateIntensityTrack( AnimationTrack::FloatWave )->AsWave();
		trackIntensity->SetType( WaveType::Square );
		trackIntensity->SetOffset( 0.5f );
		trackIntensity->SetAmplitude( 0.5f );
		trackIntensity->SetFrequency( 5.0f );
		_projectorCtrl->SetMode( AnimationMode::Loop );
		_projectorCtrl->Start( false );
	}

	void InitView() override
	{
		// Setup viewports and cameras.
		_camera->SetPosition( Vector3(0.0f, 100.0f, -200.0f) );
		_viewport->SetColor( Color::RoyalBlue );

		// Make camera, head and projector follow the sphere.
		_cameraLookAt = _camera->CreateLookAtConstraint( _sphere );
		_headLookAt = _head->CreateLookAtConstraint( _sphere );
		_projectorLookAt = _projector->CreateLookAtConstraint( _sphere );
	}

	void InitUi() override
	{
		_switchCameraLookAt = CreateSwitch( Point(_widgetLeft-10, 120), 150, L"Camera constraint", true );
		_switchHeadLookAt = CreateSwitch( Point(_widgetLeft-10, 150), 150, L"Head constraint", true );
		_switchProjectorLookAt = CreateSwitch( Point(_widgetLeft-10, 180), 160, L"Projector constraint", true );
		_switchProjectorBlinking = CreateSwitch( Point(_widgetLeft-10, 210), 150, L"Projector blinking", false );
		_switchDebugHelpers = CreateSwitch( Point(_widgetLeft-10, 240), 150, L"Debug helpers", true );
	}

	// SynkroListener methods.
	Bool OnSynkroException( const Exception& ex ) override
	{
		constexpr UInt BUF_SIZE = 512;
		Char msg[BUF_SIZE] = {};
		ex.ToString().GetChars( 0, BUF_SIZE, msg );
		Platform::Error( msg );
		return true;
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchCameraLookAt )
		{
			_cameraLookAt->Enable( _switchCameraLookAt->IsOn() );
			return true;
		}
		else if ( sender == _switchHeadLookAt )
		{
			_headLookAt->Enable( _switchHeadLookAt->IsOn() );
			return true;
		}
		else if ( sender == _switchProjectorLookAt )
		{
			_projectorLookAt->Enable( _switchProjectorLookAt->IsOn() );
			return true;
		}
		else if ( sender == _switchProjectorBlinking )
		{
			_projectorCtrl->Start( _switchProjectorBlinking->IsOn() );
			if ( !_switchProjectorBlinking->IsOn() )
			{
				_projector->Enable( true );
				_projector->SetIntensity( 1.0f );
			}
			return true;
		}
		else if ( sender == _switchDebugHelpers )
		{
			_scene->GetRenderQueue()->GetLineQueue()->Enable( _switchDebugHelpers->IsOn() );
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateTexturedMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		return material;
	}

private:
	PtrOpaqueMaterial										_materialFloor;
	PtrNode													_world;
	PtrTriangleMesh											_floor;

	PtrTriangleMesh											_sphere;
	PtrLookAtConstraint										_cameraLookAt;
	PtrSwitch												_switchCameraLookAt;

	PtrTriangleMesh											_head;
	PtrLookAtConstraint										_headLookAt;
	PtrSwitch												_switchHeadLookAt;

	PtrConeLight											_projector;
	PtrLookAtConstraint										_projectorLookAt;
	PtrLightAnimationController								_projectorCtrl;
	PtrSwitch												_switchProjectorLookAt;
	PtrSwitch												_switchProjectorBlinking;
	
	PtrSwitch												_switchDebugHelpers;
};

SYNKRO_DEMO_BEGIN
	LookAtMe demo;
	demo.Run();
SYNKRO_DEMO_END
