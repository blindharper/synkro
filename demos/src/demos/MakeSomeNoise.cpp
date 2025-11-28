#include "../Demo.h"


class MakeSomeNoise :
	public Demo
{
public:
	MakeSomeNoise() :
		Demo( L"Make Some Noise" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		Random rnd;

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetAmbientColor( Color::DimGray );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, 0.0f, -1.0f) );

		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_material = CreateMaterial( diffuseMap, Color::OrangeAerospace );
		_material2 = CreateMaterial( diffuseMap, Color::BritishRacingGreen );

		// Create meshes.
		_mesh = CreateEllipsoid( nullptr, _material, 40.0f, 20.0f, 30.0f, 40, 40, Matrix4x4::Identity, Vector3(-80.0f, 0.0f, 0.0f) );
		_mesh2 = CreateEllipsoid( nullptr, _material2, 40.0f, 20.0f, 30.0f, 40, 40, Matrix4x4::Identity, Vector3(80.0f, 0.0f, 0.0f) );

		// Setup animations.
		_ctrlMesh = _mesh->CreateAnimationController( nullptr, nullptr );
		_trackMeshYaw = _ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshYaw->SetMagnitude( Math::Pi );
		_trackMeshYaw->SetSeed( 20 );
		_trackMeshPitch = _ctrlMesh->CreateOrientationPitchTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshPitch->SetMagnitude( Math::Pi );
		_trackMeshPitch->SetSeed( 50 );
		_trackMeshRoll = _ctrlMesh->CreateOrientationRollTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshRoll->SetMagnitude( Math::Pi );
		_trackMeshRoll->SetSeed( 10 );

		PtrNoiseFloatTrack trackPosY = _ctrlMesh->CreatePositionYTrack( AnimationTrack::FloatNoise )->AsNoise();
		trackPosY->SetMagnitude( 50.0f );
		trackPosY->SetSeed( rnd.GetUInt() );
		PtrNoiseFloatTrack trackScale = _ctrlMesh->CreateScaleUniformTrack( AnimationTrack::FloatNoise )->AsNoise();
		trackScale->SetMagnitude( 0.5f );
		trackScale->SetShift( 1.0f );
		trackScale->SetSeed( rnd.GetUInt() );

		_ctrlMesh->SetMode( AnimationMode::Loop );
		_ctrlMesh->Start( true );

		_ctrlMesh2 = _mesh2->CreateAnimationController( nullptr, nullptr );
		_trackMeshYaw2 = _ctrlMesh2->CreateOrientationYawTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshYaw2->SetMagnitude( _trackMeshYaw->GetMagnitude() );
		_trackMeshYaw2->SetSeed( _trackMeshYaw->GetSeed() );
		_trackMeshPitch2 = _ctrlMesh2->CreateOrientationPitchTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshPitch2->SetMagnitude( _trackMeshPitch->GetMagnitude() );
		_trackMeshPitch2->SetSeed( _trackMeshPitch->GetSeed() );
		_trackMeshRoll2 = _ctrlMesh2->CreateOrientationRollTrack( AnimationTrack::FloatNoise )->AsNoise();
		_trackMeshRoll2->SetMagnitude( _trackMeshRoll->GetMagnitude() );
		_trackMeshRoll2->SetSeed( _trackMeshRoll->GetSeed() );

		PtrNoiseVector3Track trackPosition = _ctrlMesh2->CreatePositionTrack( AnimationTrack::Vector3Noise )->AsNoise();
		trackPosition->SetMagnitude( 20.0f );
		trackPosition->SetShift( Vector3(80.0f, 0.0f, 0.0f) );
		trackPosition->SetSeed( rnd.GetUInt() );

		_ctrlMesh2->SetMode( AnimationMode::Loop );
		_ctrlMesh2->Start( true );

		PtrSimpleMaterialAnimationController ctrl = _material2->CreateAnimationController( nullptr, nullptr )->AsSimple();
		PtrNoiseColorTrack trackDiffuse = ctrl->CreateDiffuseAmbientColorTrack( AnimationTrack::ColorNoise )->AsNoise();
		trackDiffuse->SetSeed( rnd.GetUInt() );
		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 0.0f, -300.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		_btnRandomize = CreateButton( Point(_widgetLeft, 100), L"[R]andomize seed", Anchor::TopRight, HotKey(Key::R, true) );
		_btnSynchronize = CreateButton( Point(_widgetLeft, 130), L"[S]ynchronize seed", Anchor::TopRight, HotKey(Key::S, true) );
		_switchShiftTime = CreateSwitch( Point(_widgetLeft, 160), 160, L"Shift [t]ime", HotKey(Key::T, true), false );
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( sender == _btnRandomize )
		{
			Random rnd;
			_trackMeshYaw2->SetSeed( rnd.GetUInt() );
			_trackMeshPitch2->SetSeed( rnd.GetUInt() );
			_trackMeshRoll2->SetSeed( rnd.GetUInt() );
			_switchShiftTime->Show( false );
			return true;
		}
		else if ( sender == _btnSynchronize )
		{
			_trackMeshYaw2->SetSeed( _trackMeshYaw->GetSeed() );
			_trackMeshPitch2->SetSeed( _trackMeshPitch->GetSeed() );
			_trackMeshRoll2->SetSeed( _trackMeshRoll->GetSeed() );
			_switchShiftTime->Show( true );
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchShiftTime )
		{
			_ctrlMesh2->SetOffset( _switchShiftTime->IsOn() ? -0.2 : 0 );
			_ctrlMesh2->Restart();
			_ctrlMesh->Restart();
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse, const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetAmbientColor( color );
		material->SetDiffuseColor( color );
		material->SetSpecularColor( Color::White );
		material->SetSpecularPower( 10.0f );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );

		return material;
	}

private:
	PtrDirectLight											_light;

	PtrOpaqueMaterial										_material;
	PtrTriangleMesh											_mesh;
	PtrNoiseFloatTrack										_trackMeshYaw;
	PtrNoiseFloatTrack										_trackMeshPitch;
	PtrNoiseFloatTrack										_trackMeshRoll;
	PtrNodeAnimationController								_ctrlMesh;

	PtrOpaqueMaterial										_material2;
	PtrTriangleMesh											_mesh2;
	PtrNoiseFloatTrack										_trackMeshYaw2;
	PtrNoiseFloatTrack										_trackMeshPitch2;
	PtrNoiseFloatTrack										_trackMeshRoll2;
	PtrNodeAnimationController								_ctrlMesh2;

	PtrButton												_btnRandomize;
	PtrButton												_btnSynchronize;
	PtrSwitch												_switchShiftTime;
};

SYNKRO_DEMO_BEGIN
	MakeSomeNoise demo;
	demo.Run();
SYNKRO_DEMO_END
