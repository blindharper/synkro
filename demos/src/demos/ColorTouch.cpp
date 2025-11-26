#include "../Demo.h"


class ColorTouch :
	public Demo
{
public:
	ColorTouch() :
		Demo( L"Color Touch" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create environment.
		PtrStream stream = GetStream( L"cell.x" );
		_cell = _scene->LoadMesh( stream, nullptr, nullptr, 0 );
		_cell->SetScale( 2.0f );
		INodeAnimationController* ctrlCell = _cell->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = ctrlCell->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothDown );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0f/60.0f );
		ctrlCell->SetMode( AnimationMode::Loop );
		ctrlCell->Start( true );

		// Create materials.
		_materialNucleus = CreateMaterial( Color::NeonFuchsia );
		_materialElectron = CreateMaterial( Color::BritishRacingGreen );

		// Create nucleus.
		constexpr Float NUCLEUS_RADIUS = 0.5f;
		_nucleus = CreateSphere( nullptr, _materialNucleus, NUCLEUS_RADIUS, 40, 40, Matrix4x4::Identity, Vector3::Origin );

		// Create electrons.
		_centers = _synkro->CreateNodeList();
		_electrons = _synkro->CreateTriangleMeshList();
		constexpr Float ELECTRON_RADIUS = 0.15f;
		_centers->Add( _scene->CreateDummy(_nucleus, String::Empty) );
		_centers->Get(0)->SetOrientationYaw( Math::HalfPi );		
		INodeAnimationController* centerCtrl = _centers->Get(0)->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw2 = centerCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw2->SetType( WaveType::SawtoothDown );
		trackYaw2->SetAmplitude( Math::TwoPi );
		trackYaw2->SetFrequency( 1.0f/Math::Pi );
		centerCtrl->SetMode( AnimationMode::Loop );
		centerCtrl->SetSpeed( 0.5 );
		centerCtrl->Start( true );
		_electrons->Add( CreateSphere(_centers->Get(0), _materialElectron, ELECTRON_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(2.0f, 0.0f, 0.0f)) );

		_centers->Add( _scene->CreateDummy(_nucleus, String::Empty) );
		_centers->Get(1)->SetOrientationPitch( Math::HalfPi );
		centerCtrl = _centers->Get(1)->CreateAnimationController( nullptr, nullptr );
		trackYaw2 = centerCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw2->SetType( WaveType::SawtoothUp );
		trackYaw2->SetAmplitude( Math::TwoPi );
		trackYaw2->SetFrequency( 1.0f/Math::Pi );
		trackYaw2->SetPhase( Math::Pi );
		centerCtrl->SetMode( AnimationMode::Loop );
		centerCtrl->SetSpeed( 0.5 );
		centerCtrl->Start( true );
		_electrons->Add( CreateSphere(_centers->Get(1), _materialElectron, ELECTRON_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(1.7f, 0.0f, 0.0f)) );

		_centers->Add( _scene->CreateDummy(_nucleus, String::Empty) );
		_centers->Get(2)->SetOrientationPitch( Math::QuarterPi );		
		centerCtrl = _centers->Get(2)->CreateAnimationController( nullptr, nullptr );
		trackYaw2 = centerCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw2->SetType( WaveType::SawtoothUp );
		trackYaw2->SetAmplitude( Math::TwoPi );
		trackYaw2->SetFrequency( 1.0f/Math::Pi );
		trackYaw2->SetPhase( Math::HalfPi );
		centerCtrl->SetMode( AnimationMode::Loop );
		centerCtrl->SetSpeed( 0.5 );
		centerCtrl->Start( true );
		_electrons->Add( CreateSphere(_centers->Get(2), _materialElectron, ELECTRON_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(2.0f, 0.0f, 0.0f)) );

		// Create light source.
		_scene->SetAmbientLightColor( Color::White );
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, 1.0f, 0.0f) );
	}

	void InitView() override
	{
		_filterGrayscale = _viewport->CreateFilter( ViewportFilter::Grayscale );
		_camera->SetPosition( Vector3(0.0f, 1.5f, -8.0f) );
		_camera->LookAt( Vector3(0.0f, 0.0f, 0.0f) );
	}

	void InitUi() override
	{
		_switchNucleusColored = CreateSwitch( Point(_widgetLeft-10, 120), 160, L"Colorize nucleus", false );
		_switchElectron1Colored = CreateSwitch( Point(_widgetLeft-10, 150), 160, L"Colorize electron #1", false );
		_switchElectron2Colored = CreateSwitch( Point(_widgetLeft-10, 180), 160, L"Colorize electron #2", false );
		_switchElectron3Colored = CreateSwitch( Point(_widgetLeft-10, 210), 160, L"Colorize electron #3", false );
		_switchGrayscaleEbabled = CreateSwitch( Point(_widgetLeft-10, 240), 160, L"Enable grayscale", true );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchNucleusColored )
		{
			_viewport->MakeOverlay( _nucleus, _switchNucleusColored->IsOn() );
			return true;
		}
		else if ( sender == _switchElectron1Colored )
		{
			_viewport->MakeOverlay( _electrons->Get(0), _switchElectron1Colored->IsOn() );
			return true;
		}
		else if ( sender == _switchElectron2Colored )
		{
			_viewport->MakeOverlay( _electrons->Get(1), _switchElectron2Colored->IsOn() );
			return true;
		}
		else if ( sender == _switchElectron3Colored )
		{
			_viewport->MakeOverlay( _electrons->Get(2), _switchElectron3Colored->IsOn() );
			return true;
		}
		else if ( sender == _switchGrayscaleEbabled )
		{
			_filterGrayscale->Enable( _switchGrayscaleEbabled->IsOn() );
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateMaterial( const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetAmbientColor( color );
		material->SetDiffuseColor( color );
		material->SetSpecularColor( Color::White );
		material->SetSpecularPower( 10.0f );
		return material;
	}

private:
	PtrViewportFilter										_filterGrayscale;

	PtrDirectLight											_light;
	PtrTriangleMesh											_cell;

	PtrOpaqueMaterial										_materialNucleus;
	PtrTriangleMesh											_nucleus;

	PtrOpaqueMaterial										_materialElectron;
	PtrNodeList												_centers;
	PtrTriangleMeshList										_electrons;

	PtrSwitch												_switchNucleusColored;
	PtrSwitch												_switchElectron1Colored;
	PtrSwitch												_switchElectron2Colored;
	PtrSwitch												_switchElectron3Colored;
	PtrSwitch												_switchGrayscaleEbabled;
};

SYNKRO_DEMO_BEGIN
	ColorTouch demo;
	demo.Run();
SYNKRO_DEMO_END
