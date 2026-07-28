#include "../Demo.h"


class Morphing :
	public Demo
{
public:
	Morphing() :
		Demo( L"Morphing" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create center node.
		_center = _scene->CreateDummy( nullptr, L"Center" );
		_center->ShowGizmo( false );
		PtrNodeAnimationController worldCtrl = _center->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = _trackCenterYaw = worldCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothDown );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( Math::OneOverPi );
		PtrWaveFloatTrack trackPosY = worldCtrl->CreatePositionYTrack( AnimationTrack::FloatWave )->AsWave();
		trackPosY->SetType( WaveType::Sine );
		trackPosY->SetAmplitude( 20.0f );
		trackPosY->SetFrequency( 1.0f );
		worldCtrl->SetMode( AnimationMode::Loop );
		worldCtrl->SetSpeed( 0.5 );
		worldCtrl->Start( true );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetAmbientColor( Color::RoyalBlue );
		_light->SetDiffuseColor( Color::RoyalBlue );
		_light->SetSpecularColor( Color::Cyan );
		_light->LookAt( Vector3(0.0f, 0.0f, -1.0f) );

		// Create models.
		_dolphin = CreateDolphin();
		_dolphin2 = CreateDolphin();
		_dolphin->SetPosition( Vector3(0.0f, 30.0f, 100.0f) );
		_dolphin2->SetPosition( Vector3(0.0f, 30.0f, -100.0f) );
		_dolphin->SetOrientationYaw( Math::Pi );
		_ctrlMorph = _dolphin->GetSubset( 0 )->CreateMorphController( nullptr, nullptr );
		_ctrlMorph2 = _dolphin2->GetSubset( 0 )->CreateMorphController( nullptr, nullptr );

		// Setup morphing.
		LoadMorphChannels();
		SetupMorphing( _dolphin );
		SetupMorphing( _dolphin2 );
	}

	void InitView() override
	{
		// Setup cameras and viewports.
		_camera->SetPosition( Vector3(0.0f, 150.0f, -300.0f) );
		_camera->LookAt( Vector3::Origin );
		_viewport->SetColor( Color::Denim );
	}

	void InitUi() override
	{
		_switchEnableMorphing = CreateSwitch( Point(_widgetLeft, 100), 160, L"Enable [m]orphing", HotKey(Key::M, true), true );
		_switchWireframe = CreateSwitch( Point(_widgetLeft, 120), 160, L"[W]ireframe", HotKey(Key::W, true), false );
		_optionCW = CreateOption( none, Point(_widgetLeft, 140), L"CW", null, true );
		_optionCCW = CreateOption( none, Point(_widgetLeft, 160), L"CCW", null, false );
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchEnableMorphing )
		{
			_ctrlMorph->Start( _switchEnableMorphing->IsOn() );
			_ctrlMorph2->Start( _switchEnableMorphing->IsOn() );
			return true;
		}
		else if ( sender == _switchWireframe )
		{
			_viewport->SetWireframe( _switchWireframe->IsOn() );
			return true;
		}
		else if ( sender == _optionCW )
		{
			_trackCenterYaw->SetType( WaveType::SawtoothDown );
			_dolphin->SetOrientationYaw( Math::Pi );
			_dolphin2->SetOrientationYaw( 0.0f );
			return true;
		}
		else if ( sender == _optionCCW )
		{
			_trackCenterYaw->SetType( WaveType::SawtoothUp );
			_dolphin->SetOrientationYaw( 0.0f );
			_dolphin2->SetOrientationYaw( Math::Pi );
			return true;
		}

		return false;
	}

	ITriangleMesh* CreateDolphin()
	{
		PtrStream stream = GetStream( L"dolphin.x" );
		ITriangleMesh* dolphin = _scene->LoadMesh( stream );
		dolphin->SetParent( _center );
		const Float sphere = dolphin->GetBoundSphere();
		dolphin->SetScale( 50.0f/sphere );
		return dolphin;
	}

	void LoadMorphChannels()
	{
		PtrStream stream1 = GetStream( L"dolphin1.x" );
		_model1 = _scene->LoadMesh( stream1 );
		_model1->Show( false );

		PtrStream stream2 = GetStream( L"dolphin2.x" );
		_model2 = _scene->LoadMesh( stream2 );
		_model2->Show( false );

		PtrStream stream3 = GetStream( L"dolphin3.x" );
		_model3 = _scene->LoadMesh( stream3 );
		_model3->Show( false );
	}

	void SetupMorphing( ITriangleMesh* model )
	{
		PtrPrimitiveMorphController ctrlMorph = model->GetSubset( 0 )->CreateMorphController( nullptr, nullptr );
		ctrlMorph->AddChannel( L"First", _model1->GetSubset(0) );
		ctrlMorph->AddChannel( L"Second", _model2->GetSubset(0) );
		ctrlMorph->AddChannel( L"Third", _model3->GetSubset(0) );

		ctrlMorph->CreateChannelWeightTrack( L"First", L"float w = sin(time); return max(0.0, w);" );
		ctrlMorph->CreateChannelWeightTrack( L"Second", L"float w = sin(time); return 1.0 - abs(w);" );
		ctrlMorph->CreateChannelWeightTrack( L"Third", L"float w = sin(time); return abs(min(0.0, w));" );

		ctrlMorph->SetMode( AnimationMode::Loop );
		ctrlMorph->SetSpeed( 5.0 );
		ctrlMorph->Start( true );
	}

private:
	PtrNode													_center;
	PtrWaveFloatTrack										_trackCenterYaw;
	PtrDirectLight											_light;

	PtrTriangleMesh											_dolphin;
	PtrPrimitiveMorphController								_ctrlMorph;

	PtrTriangleMesh											_dolphin2;
	PtrPrimitiveMorphController								_ctrlMorph2;

	PtrTriangleMesh											_model1;
	PtrTriangleMesh											_model2;
	PtrTriangleMesh											_model3;

	PtrSwitch												_switchEnableMorphing;
	PtrSwitch												_switchWireframe;
	PtrOption												_optionCW;
	PtrOption												_optionCCW;
};

SYNKRO_DEMO_BEGIN
	Morphing demo;
	demo.Run();
SYNKRO_DEMO_END
