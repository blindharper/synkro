#include "../Demo.h"


class EdgeDetection :
	public Demo
{
public:
	EdgeDetection() :
		Demo( L"Edge Detection" )
	{
	}

	void InitScene() override
	{
		Random rnd;

		// Load model.
		PtrStream stream = GetStream( L"cytovirus.x" );
		_virus = _scene->LoadMesh( stream );
		const Float radius = _virus->GetBoundSphere();
		_virus->SetScale( 45.0f/radius );

		// Animate model.
		PtrNodeAnimationController ctrlMesh = _virus->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothUp );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 0.125f );
		PtrWaveFloatTrack trackPitch = ctrlMesh->CreateOrientationPitchTrack( AnimationTrack::FloatWave )->AsWave();
		trackPitch->SetType( WaveType::SawtoothUp );
		trackPitch->SetAmplitude( Math::TwoPi );
		trackPitch->SetFrequency( 0.125f );
		PtrWaveFloatTrack trackRoll = ctrlMesh->CreateOrientationRollTrack( AnimationTrack::FloatWave )->AsWave();
		trackRoll->SetType( WaveType::SawtoothUp );
		trackRoll->SetAmplitude( Math::TwoPi );
		trackRoll->SetFrequency( 0.125f );
		ctrlMesh->SetMode( AnimationMode::Loop );
		ctrlMesh->Start( true );

		PtrSimpleMaterialAnimationController ctrlMat = _virus->GetMaterial()->CreateAnimationController( nullptr, nullptr )->AsSimple();
		PtrNoiseColorTrack trackDiffuse = ctrlMat->CreateDiffuseColorTrack( AnimationTrack::ColorNoise )->AsNoise();
		trackDiffuse->SetSeed( rnd.GetUInt() );
		ctrlMat->SetMode( AnimationMode::Loop );
		ctrlMat->Start( true );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 50.0f, -150.0f) );
		_camera->LookAt( Vector3(1.0f, 1.0f, 1.0f) );

		// Create viewport filters.
		_filterLaplacian = CreateViewportFilter( ViewportFilter::Laplacian );
		_filterPrewitt = CreateViewportFilter( ViewportFilter::Prewitt );
		_filterSobel = CreateViewportFilter( ViewportFilter::Sobel );
	}

	void InitUi() override
	{
		_labelFilter = CreateLabel(Point(_widgetLeft-96, 102), L"Filter:");
		_listFilter = CreateDropList( Point(_widgetLeft, 100), Size(150, 25) );
		_listFilter->AddItem( L"None" );
		_listFilter->AddItem( L"Laplacian" );
		_listFilter->AddItem( L"Prewitt" );
		_listFilter->AddItem( L"Sobel" );
		_listFilter->SetListHeight( _listFilter->GetItemCount() );
		_listFilter->SelectItem( 0 );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listFilter )
		{
			const FilterType type = (FilterType)_listFilter->GetSelectedItem();
			EnableViewportFilter( _filterLaplacian, type == LAPLACIAN );
			EnableViewportFilter( _filterPrewitt, type == PREWITT );
			EnableViewportFilter( _filterSobel, type == SOBEL );
			return true;
		}

		return false;
	}

	IViewportFilter* CreateViewportFilter( const ViewportFilter& type )
	{
		IViewportFilter* filter = _viewport->CreateFilter( type );
		filter->Enable( false );
		return filter;
	}

	void EnableViewportFilter( IViewportFilter* filter, Bool enabled )
	{
		filter->SetOrder( enabled ? 0 : 1 );
		filter->Enable( enabled );
	}

private:
	enum FilterType
	{
		NONE		= 0,
		LAPLACIAN	= 1,
		PREWITT		= 2,
		SOBEL		= 3,
	};

	PtrTriangleMesh											_virus;

	PtrLabel												_labelFilter;
	PtrDropList												_listFilter;

	PtrViewportFilter										_filterLaplacian;
	PtrViewportFilter										_filterPrewitt;
	PtrViewportFilter										_filterSobel;
};

SYNKRO_DEMO_BEGIN
	EdgeDetection demo;
	demo.Run();
SYNKRO_DEMO_END
