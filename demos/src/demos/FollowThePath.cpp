#include "../Demo.h"


class FollowThePath :
	public Demo
{
public:
	FollowThePath() :
		Demo( L"Follow The Path" )
	{
	}

	DebugMode GetDebugMode() const override
	{
		return DebugMode::Curves;
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
		_materialCube = CreateMaterial( diffuseMap );
		_materialCube->SetDiffuseColor( Color::LamborghiniYellow );
		_materialCube2 = CreateMaterial( diffuseMap );
		_materialCube2->SetDiffuseColor( Color::FerrariRed );
		_materialCube3 = CreateMaterial( diffuseMap );
		_materialCube3->SetDiffuseColor( Color::KiwiGreen );
		_materialFloor = CreateFloorMaterial( imageTwinPeaks );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetAmbientColor( Color::DimGray );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, 1.0f, 0.0f) );

		// Create floor and primitives.
		constexpr Float FLOOR_SIZE = 250.0f;
		_floor = CreatePlane( nullptr, _materialFloor, FLOOR_SIZE, FLOOR_SIZE, 16, Matrix4x4::Identity, Vector3::Origin );
		constexpr Float CUBE_SIDE = 8.0f;
		_cube = CreateCube( nullptr, _materialCube, CUBE_SIDE, Matrix4x4::Identity, Vector3(30.0f, 0.5f*CUBE_SIDE, 0.0f) );
		_cube2 = CreateCube( nullptr, _materialCube2, CUBE_SIDE, Matrix4x4::Identity, Vector3(30.0f, 0.5f*CUBE_SIDE, 0.0f) );
		_cube3 = CreateCube( nullptr, _materialCube3, CUBE_SIDE, Matrix4x4::Identity, Vector3(30.0f, 0.5f*CUBE_SIDE, 0.0f) );

		// Create paths.
		_path1 = _scene->CreateCurve( nullptr, L"Path1" );
		_path1->SetColor( Color::LamborghiniYellow );

		constexpr UInt LOOP_COUNT = 5;
		constexpr UInt STEP_COUNT = 72;
		constexpr Float RADIUS = 30.0f;
		const Float dt = Math::TwoPi/CastFloat(STEP_COUNT);
		Float h = 4.0f;
		constexpr Float dh = 60.0f/CastFloat(LOOP_COUNT*STEP_COUNT);
		for ( UInt i = 0; i < LOOP_COUNT; ++i )
		{
			for ( UInt j = 0; j <= STEP_COUNT; ++j )
			{
				const Float a = CastFloat(j)*dt;
				const Float x = RADIUS*Math::Cos( a );
				const Float z = RADIUS*Math::Sin( a );
				_path1->AddPoint( Vector3(x, h, z) );
				h += dh;
			}
		}

		_path2 = _scene->CreateCurve( nullptr, L"Path2" );
		_path2->SetColor( Color::FerrariRed );

		_path2->AddPoint(Vector3(30.0f, 0.5f*CUBE_SIDE, 30.0f));
		_path2->AddPoint( Vector3(30.0f, 0.5f*CUBE_SIDE, -30.0f) );
		_path2->AddPoint( Vector3(-30.0f, 0.5f*CUBE_SIDE, -30.0f) );
		_path2->AddPoint( Vector3(-30.0f, 0.5f*CUBE_SIDE, 30.0f) );
		_path2->AddPoint( Vector3(30.0f, 0.5f*CUBE_SIDE, 30.0f) );

		_path3 = _scene->CreateCurve( nullptr, L"Path3" );
		_path3->SetColor( Color::KiwiGreen );
		_path3->AddPoint( Vector3(-90.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-90.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-80.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-80.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-70.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-70.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-60.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-60.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-50.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-50.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-40.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-40.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-30.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-30.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-20.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(-20.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-10.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(-10.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(0.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(0.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(10.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(10.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(20.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(20.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(30.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(30.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(40.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(40.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(50.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(50.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(60.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(60.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(70.0f, 12.0f, 60.0f));
		_path3->AddPoint( Vector3(70.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(80.0f, 20.0f, 60.0f));
		_path3->AddPoint( Vector3(80.0f, 12.0f, 60.0f));

		_cube->SetPath( _path1 );
		_cube2->SetPath( _path2 );
		_cube3->SetPath( _path3 );
		_path = _path1;

		INodeAnimationController* cubeCtrl = _cube->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackPhase = cubeCtrl->CreatePathPhaseTrack( AnimationTrack::FloatWave )->AsWave();
		trackPhase->SetType( WaveType::SawtoothUp );
		trackPhase->SetAmplitude( 1.0f );
		trackPhase->SetLength( 4.0 );
		cubeCtrl->SetMode( AnimationMode::PingPong );
		cubeCtrl->SetSpeed( 0.1 );
		cubeCtrl->Start( true );

		INodeAnimationController* cubeCtrl2 = _cube2->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackPhase2 = cubeCtrl2->CreatePathPhaseTrack( AnimationTrack::FloatWave )->AsWave();
		trackPhase2->SetType( WaveType::SawtoothUp );
		trackPhase2->SetAmplitude( 1.0f );
		cubeCtrl2->SetMode( AnimationMode::Loop );
		cubeCtrl2->SetSpeed( 0.2 );
		cubeCtrl2->Start( true );

		INodeAnimationController* cubeCtrl3 = _cube3->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackPhase3 = cubeCtrl3->CreatePathPhaseTrack( AnimationTrack::FloatWave )->AsWave();
		trackPhase3->SetType( WaveType::SawtoothUp );
		trackPhase3->SetAmplitude( 1.0f );
		trackPhase3->SetLength( 6.0 );
		cubeCtrl3->SetMode( AnimationMode::PingPong );
		cubeCtrl3->SetSpeed( 0.15 );
		cubeCtrl3->Start( true );
	}

	void InitView() override
	{
		// Setup viewport and cameras.
		_viewport->SetColor( Color::RoyalBlue );
		_camera->SetPosition( Vector3(0.0f, 50.0f, -170.0f) );
		_camera->LookAt( Vector3(0.0f, 15.0f, 100.0f) );
	}

	void InitUi() override
	{
		_optionPath1 = CreateOption( none, Point(_widgetLeft, 110), L"Path 1", 0, true, Color::LamborghiniYellow );
		_optionPath2 = CreateOption( none, Point(_widgetLeft, 130), L"Path 2", 0, false, Color::FerrariRed );
		_optionPath3 = CreateOption( none, Point(_widgetLeft, 150), L"Path 3", 0, false, Color::KiwiGreen );
		_labelPoint = CreateLabel( Point(_widgetLeft, 170), L"Point: 1" );
		_sliderPoint = CreateSlider( none, Point(_widgetLeft, 190), 0, _path->GetPointCount()-1, 0 );
		_labelTension = CreateLabel( Point(_widgetLeft, 210), L"Tension: 0.0" );
		_sliderTension = CreateSlider( none, Point(_widgetLeft, 230), 0, 2000, 1000 );
		_labelContinuity = CreateLabel( Point(_widgetLeft, 250), L"Continuity: 0.0" );
		_sliderContinuity = CreateSlider( none, Point(_widgetLeft, 270), 0, 2000, 1000 );
		_labelBias = CreateLabel( Point(_widgetLeft, 290), L"Bias: 0.0" );
		_sliderBias = CreateSlider( none, Point(_widgetLeft, 310), 0, 2000, 1000 );
		_switchDebugHelpers = CreateSwitch( Point(_widgetLeft, 340), 150, L"Debug helpers", true );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _optionPath1 )
		{
			_path->SelectPoint( none );
			_path = _path1;
			_path->SelectPoint( 0 );
			_sliderPoint->SetPosition( 0 );
			_sliderPoint->SetMaxPosition( _path->GetPointCount()-1 );
			return true;
		}
		else if ( sender == _optionPath2 )
		{
			_path->SelectPoint( none );
			_path = _path2;
			_path->SelectPoint( 0 );
			_sliderPoint->SetPosition( 0 );
			_sliderPoint->SetMaxPosition( _path->GetPointCount()-1 );
			return true;
		}
		else if ( sender == _optionPath3 )
		{
			_path->SelectPoint( none );
			_path = _path3;
			_path->SelectPoint( 0 );
			_sliderPoint->SetPosition( 0 );
			_sliderPoint->SetMaxPosition( _path->GetPointCount()-1 );
			return true;
		}
		else if ( sender == _sliderPoint )
		{
			_path->SelectPoint( _sliderPoint->GetPosition() );
			_labelPoint->SetText( String::Format(L"Point: {0}", _sliderPoint->GetPosition()) );

			const Float t = _path->GetTension( _sliderPoint->GetPosition() );
			SetSliderPosition( _sliderTension, _labelTension, L"Tension: ", t );

			const Float c = _path->GetContinuity( _sliderPoint->GetPosition() );
			SetSliderPosition( _sliderContinuity, _labelContinuity, L"Continuity: ", c );

			const Float b = _path->GetBias( _sliderPoint->GetPosition() );
			SetSliderPosition( _sliderBias, _labelBias, L"Bias: ", b );

			return true;
		}
		else if ( sender == _sliderTension )
		{
			const Float value = SliderPositionToLabel( _sliderTension, _labelTension, L"Tension: " );
			_path->SetTension( _sliderPoint->GetPosition(), value );
			return true;
		}
		else if ( sender == _sliderContinuity )
		{
			const Float value = SliderPositionToLabel( _sliderContinuity, _labelContinuity, L"Continuity: " );
			_path->SetContinuity( _sliderPoint->GetPosition(), value );
			return true;
		}
		else if ( sender == _sliderBias )
		{
			const Float value = SliderPositionToLabel( _sliderBias, _labelBias, L"Bias: " );
			_path->SetBias( _sliderPoint->GetPosition(), value );
			return true;
		}
		else if ( sender == _switchDebugHelpers )
		{
			_scene->GetRenderQueue()->GetLineQueue()->Enable( _switchDebugHelpers->IsOn() );
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateFloorMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetSpecularColor( Color::Black );
		material->GetDiffuseMap()->SetImage( diffuse );
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

	Float SliderPositionToLabel( ISlider* slider, ILabel* label, const Char* prefix )
	{
		Double value = CastDouble((CastInt(slider->GetPosition())-1000))*0.001;
		label->SetText( String::Format(L"{0}{1,0.000}", prefix, value) );
		return CastFloat(value);
	}

	void SetSliderPosition( ISlider* slider, ILabel* label, const Char* prefix, Float value )
	{
		UInt pos = CastUInt(value*1000.0f + 1000.0f);
		slider->SetPosition( pos );
		label->SetText( String::Format(L"{0}{1,0.000}", prefix, CastDouble(value)) );
	}

private:
	PtrDirectLight											_light;
	PtrOpaqueMaterial										_materialFloor;
	PtrOpaqueMaterial										_materialCube;
	PtrOpaqueMaterial										_materialCube2;
	PtrOpaqueMaterial										_materialCube3;
	PtrTriangleMesh											_floor;
	PtrTriangleMesh											_cube;
	PtrTriangleMesh											_cube2;
	PtrTriangleMesh											_cube3;

	PtrCurve												_path1;
	PtrCurve												_path2;
	PtrCurve												_path3;
	PtrCurve												_path;

	PtrOption												_optionPath1;
	PtrOption												_optionPath2;
	PtrOption												_optionPath3;

	PtrLabel												_labelPoint;
	PtrSlider												_sliderPoint;

	PtrLabel												_labelTension;
	PtrSlider												_sliderTension;

	PtrLabel												_labelContinuity;
	PtrSlider												_sliderContinuity;

	PtrLabel												_labelBias;
	PtrSlider												_sliderBias;

	PtrSwitch												_switchDebugHelpers;
};

SYNKRO_DEMO_BEGIN
	FollowThePath demo;
	demo.Run();
SYNKRO_DEMO_END
