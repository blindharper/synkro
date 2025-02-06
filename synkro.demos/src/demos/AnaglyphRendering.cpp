#include "../Demo.h"


class AnaglyphRendering :
	public Demo
{
public:
	AnaglyphRendering() :
		Demo( L"Anaglyph Rendering" ),
		_index( 0 )
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
		_materialOrange = CreateMaterial( diffuseMap, Color::OrangeAerospace );
		_materialPurple = CreateMaterial( diffuseMap, Color::Purple );
		_materialYellow = CreateMaterial( diffuseMap, Color::Lemon );
		_materialGreen = CreateMaterial( diffuseMap, Color::SeaGreen );
		_materialRed = CreateMaterial( diffuseMap, Color::RedDevil );
		_materialBlue = CreateMaterial( diffuseMap, Color::BlueCrayola );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(1.0f, 1.0f, 0.0f) );

		// Create the center of rotation.
		_origin = _scene->CreateDummy( nullptr, L"Origin" );
		_originCtrl = _origin->CreateAnimationController( nullptr, this );
		_trackOrientation = _originCtrl->CreateOrientationTrack();
		_originCtrl->SetMode( AnimationMode::Single );

		// Create primitives.
		_primitives = _synkro->CreateTriangleMeshList();
		constexpr Float RADIUS = 80.0f;

		constexpr Float TORUS_RADIUS = 7.0f;
		_primitives->Add( CreateTorus( _origin, _materialOrange, TORUS_RADIUS, 2.0f*TORUS_RADIUS, 40, 40, Matrix4x4::Identity.RotateZ(Math::HalfPi), GetPosition(RADIUS, GetAngle(0))) );

		// Setup up-down animation and then re-use it for all primitives.
		INodeAnimationController* ctrl = _primitives->Get(_primitives->GetSize()-1)->CreateAnimationController(nullptr, nullptr);
		PtrWaveFloatTrack trackPosition = ctrl->CreatePositionYTrack( AnimationTrack::FloatWave )->AsWave();
		trackPosition->SetType( WaveType::Sine );
		trackPosition->SetAmplitude( 2.0f );
		trackPosition->SetFrequency( 3.0f );
		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );
		IAnimation* animation = ctrl->GetAnimation();

		constexpr Float SPHERE_RADIUS = 20.0f;
		_primitives->Add( CreateSphere( _origin, _materialPurple, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, GetPosition(RADIUS, GetAngle(1))) );
		CreateController( animation );

		constexpr Float CONE_RADIUS = 15.0f; constexpr Float CONE_HEIGHT = 35.0f;
		_primitives->Add( CreateCone( _origin, _materialYellow, CONE_RADIUS, CONE_HEIGHT, 40, 40, Matrix4x4::Identity, GetPosition(RADIUS, GetAngle(2))) );
		CreateController( animation );

		constexpr Float CUBE_SIDE = 25.0f;
		_primitives->Add( CreateCube( _origin, _materialGreen, CUBE_SIDE, Matrix4x4::Identity, GetPosition(RADIUS, GetAngle(3))) );
		CreateController( animation );

		constexpr Float CYLINDER_RADIUS = 12.0f; constexpr Float CYLINDER_HEIGHT = 25.0f;
		_primitives->Add( CreateCylinder( _origin, _materialRed, CYLINDER_RADIUS, CYLINDER_HEIGHT, 40, 40, Matrix4x4::Identity, GetPosition(RADIUS, GetAngle(4))) );
		CreateController( animation );

		constexpr Float PYRAMID_HEIGHT = 25.0f;
		_primitives->Add( CreatePyramid( _origin, _materialBlue, PYRAMID_HEIGHT, PYRAMID_HEIGHT, PYRAMID_HEIGHT, Matrix4x4::Identity, GetPosition(RADIUS, GetAngle(5))) );
		CreateController( animation );
	}

	void InitView() override
	{
		// Setup viewports and cameras.
		_camera->SetEyeDistance( 3.0f );
		_camera->SetPosition( Vector3(300.0f, 150.0f, 0.1f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		_btnSelectTorus = CreateButton( 0, Point(_widgetLeft, 120), L"Select [T]orus", Anchor::TopRight, HotKey(Key::T, true) );
		_btnSelectSphere = CreateButton( 1, Point(_widgetLeft, 150), L"Select [S]phere", Anchor::TopRight, HotKey(Key::S, true) );
		_btnSelectCone = CreateButton( 2, Point(_widgetLeft, 180), L"Select [C]one", Anchor::TopRight, HotKey(Key::C, true) );
		_btnSelectCube = CreateButton( 3, Point(_widgetLeft, 210), L"Select Cu[b]e", Anchor::TopRight, HotKey(Key::B, true) );
		_btnSelectCylinder = CreateButton( 4, Point(_widgetLeft, 240), L"Select Cyli[n]der", Anchor::TopRight, HotKey(Key::N, true) );
		_btnSelectPyramid = CreateButton( 5, Point(_widgetLeft, 270), L"Select [P]yramid", Anchor::TopRight, HotKey(Key::P, true) );

		_labelStereo = CreateLabel( Point(_widgetLeft, 300), L"Anaglyph mode" );
		_listStereo = CreateDropList( Point(_widgetLeft, 320), Size(150, 25) );
		_listStereo->AddItem( StereoMode::None.ToString() );
		_listStereo->AddItem( StereoMode::RedCyan.ToString() );
		_listStereo->AddItem( StereoMode::GreenMagenta.ToString() );
		_listStereo->AddItem( StereoMode::BlueYellow.ToString() );
		_listStereo->AddItem( StereoMode::CyanRed.ToString() );
		_listStereo->AddItem( StereoMode::MagentaGreen.ToString() );
		_listStereo->AddItem( StereoMode::YellowBlue.ToString() );
		_listStereo->SetListHeight( _listStereo->GetItemCount() );
		_listStereo->SelectItem( 0 );
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( _originCtrl->GetState() == ControllerState::Active )
			return false;

		Quaternion orientation;
		_origin->GetOrientation( orientation );
		_trackOrientation->Clear();
		_trackOrientation->SetKey( 0.0, orientation );

		if ( _index == sender->ID() )
			return false;

		_index = sender->ID();
		if ( _index >= _primitives->GetSize() )
			return false;

		for ( UInt i = 0; i < _primitives->GetSize(); ++i )
		{
			GetController( i )->Start( false );
		}

		const Float angle = GetAngle( _index );
		_trackOrientation->SetKey( 2.0, Quaternion(Vector3::Y, -angle), Interpolation::EaseIn );
		_originCtrl->Reset();
		_originCtrl->Start( true );
		return true;
	}

	// Animation listener methods.
	void OnAnimationStop( IAnimationController* sender ) override
	{
		Demo::OnAnimationStop( sender );

		if ( sender == _originCtrl )
		{
			if ( _index < _primitives->GetSize() )
				GetController( _index )->Start( true );
		}
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listStereo )
		{
			const StereoMode stereoMode( _listStereo->GetText() );
			_viewport->SetStereoMode( stereoMode );
			return true;
		}
		return false;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse, const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		material->SetAmbientColor( color );
		material->SetDiffuseColor( color );
		material->SetSpecularColor( Color::White );
		material->SetSpecularPower( 10.0f );
		return material;
	}

	void CreateController( IAnimation* animation )
	{
		INodeAnimationController* ctrl = _primitives->Get(_primitives->GetSize()-1)->CreateAnimationController( animation, nullptr );
		ctrl->SetMode( AnimationMode::Loop );
	}

	INodeAnimationController* GetController( UInt index )
	{
		return _primitives->Get( index )->CreateAnimationController( nullptr, nullptr );
	}

	Vector3 GetPosition( Float radius, Float angle )
	{
		return Vector3( radius*Math::Cos(angle), 0.0f, radius*Math::Sin(angle) );
	}

	Float GetAngle( UInt index )
	{
		return CastFloat(index)*Math::TwoPi/6.0f;
	}

private:
	PtrNode													_origin;
	PtrNodeAnimationController								_originCtrl;
	PtrKeyframedQuaternionTrack								_trackOrientation;
	
	PtrDirectLight											_light;

	PtrOpaqueMaterial										_materialOrange;
	PtrOpaqueMaterial										_materialPurple;
	PtrOpaqueMaterial										_materialYellow;
	PtrOpaqueMaterial										_materialGreen;
	PtrOpaqueMaterial										_materialRed;
	PtrOpaqueMaterial										_materialBlue;

	PtrTriangleMeshList										_primitives;
	UInt													_index;

	PtrButton												_btnSelectTorus;
	PtrButton												_btnSelectSphere;
	PtrButton												_btnSelectCone;
	PtrButton												_btnSelectCube;
	PtrButton												_btnSelectCylinder;
	PtrButton												_btnSelectPyramid;

	PtrLabel												_labelStereo;
	PtrDropList												_listStereo;
};

SYNKRO_DEMO_BEGIN
	AnaglyphRendering demo;
	demo.Run();
SYNKRO_DEMO_END
