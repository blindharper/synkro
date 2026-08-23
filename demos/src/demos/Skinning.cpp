#include "../Demo.h"


class Skinning :
	public Demo
{
public:
	Skinning() :
		Demo( L"Skinning" )
	{
	}

	void InitScene() override
	{
		// Load models.
		PtrStream stream = GetStream( L"tiny.x" );
		PtrSkeleton skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_tiny = _scene->LoadMesh( stream, skeleton );
		const Float radius = _tiny->GetBoundSphere();
		_tiny->SetScale( 45.0f/radius );
		_tiny->SetPositionX( -30.0f );

		PtrSkeleton skeleton2 = _synkro->GetSceneManager()->CreateSkeleton(); 
		_tiny2 = _scene->LoadMesh( stream, skeleton2 );
		_tiny2->SetScale( 35.0f/radius );
		_tiny2->SetPositionX( 30.0f );

		PtrSkeleton skeleton3 = _synkro->GetSceneManager()->CreateSkeleton(); 
		_tiny3 = _scene->LoadMesh( stream, skeleton3 );
		_tiny3->SetScale( 35.0f/radius );
		_tiny3->SetPositionZ( 50.0f );

		_tiny4 = _scene->LoadMesh( stream, skeleton );
		_tiny4->SetScale( 35.0f/radius );
		_tiny4->SetPositionX( -60.0f );
		_tiny4->SetPositionZ( 50.0f );

		// Animate models.
		_skeletonCtrl = _tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl->SetMode( AnimationMode::Loop );
		_skeletonCtrl->SetDirection( AnimationDirection::Forward );
		_skeletonCtrl->SetLoopCount( 0 );
		_skeletonCtrl->SetSpeed( 4.0 );
		_skeletonCtrl->Start( true );

		_skeletonCtrl2 = _tiny2->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl2->SetMode( AnimationMode::Loop );
		_skeletonCtrl2->SetDirection( AnimationDirection::Forward );
		_skeletonCtrl2->SetLoopCount( 0 );
		_skeletonCtrl2->SetSpeed( 4.0 );
		_skeletonCtrl2->SetOffset( _skeletonCtrl2->GetAnimations()->GetAnimation(0)->GetLength()*0.5 );
		_skeletonCtrl2->Start( true );

		_skeletonCtrl3 = _tiny3->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl3->SetMode( AnimationMode::Loop );
		_skeletonCtrl3->SetDirection( AnimationDirection::Reverse );
		_skeletonCtrl3->SetLoopCount( 0 );
		_skeletonCtrl3->SetSpeed( 6.0 );
		_skeletonCtrl3->Start( true );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 50.0f, -150.0f) );
		_camera->LookAt( Vector3::Origin );

		// Create viewport filters.
		_filterSepia = CreateViewportFilter( ViewportFilter::Sepia );
		_filterNegative = CreateViewportFilter(ViewportFilter::Negative);
		_filterGrayscale = CreateViewportFilter( ViewportFilter::Grayscale );
		_filterRed = CreateViewportFilter( ViewportFilter::Red );
		_filterGreen = CreateViewportFilter( ViewportFilter::Green );
		_filterBlue = CreateViewportFilter( ViewportFilter::Blue );
		_filterDilation = CreateViewportFilter( ViewportFilter::Dilation );
		_filterErosion = CreateViewportFilter( ViewportFilter::Erosion );
		_filterSharpen = CreateViewportFilter( ViewportFilter::Sharpen );
		_filterLaplacian = CreateViewportFilter( ViewportFilter::Laplacian );
		_filterPrewitt = CreateViewportFilter( ViewportFilter::Prewitt );
		_filterSobel = CreateViewportFilter( ViewportFilter::Sobel );
	}

	void InitUi() override
	{
		_labelFilter = CreateLabel(Point(_widgetLeft-96, 102), L"Filter:");
		_listFilter = CreateDropList( Point(_widgetLeft, 100), Size(150, 25) );
		_listFilter->AddItem( L"None" );
		_listFilter->AddItem( L"Sepia" );
		_listFilter->AddItem( L"Negative" );
		_listFilter->AddItem( L"Grayscale" );
		_listFilter->AddItem( L"Red" );
		_listFilter->AddItem( L"Green" );
		_listFilter->AddItem( L"Blue" );
		_listFilter->AddItem( L"Dilation" );
		_listFilter->AddItem( L"Erosion" );
		_listFilter->AddItem( L"Sharpen" );
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
			EnableViewportFilter( _filterSepia, type == SEPIA );
			EnableViewportFilter( _filterNegative, type == NEGATIVE );
			EnableViewportFilter( _filterGrayscale, type == GRAYSCALE );
			EnableViewportFilter( _filterRed, type == RED );
			EnableViewportFilter( _filterGreen, type == GREEN );
			EnableViewportFilter( _filterBlue, type == BLUE );
			EnableViewportFilter( _filterDilation, type == DILATION );
			EnableViewportFilter( _filterErosion, type == EROSION );
			EnableViewportFilter( _filterSharpen, type == SHARPEN );
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
		SEPIA		= 1,
		NEGATIVE	= 2,
		GRAYSCALE	= 3,
		RED			= 4,
		GREEN		= 5,
		BLUE		= 6,
		DILATION	= 7,
		EROSION		= 8,
		SHARPEN		= 9,
		LAPLACIAN	= 10,
		PREWITT		= 11,
		SOBEL		= 12,
	};

	PtrTriangleMesh											_tiny;
	PtrTriangleMesh											_tiny2;
	PtrTriangleMesh											_tiny3;
	PtrTriangleMesh											_tiny4;

	PtrSkeletonAnimationController							_skeletonCtrl;
	PtrSkeletonAnimationController							_skeletonCtrl2;
	PtrSkeletonAnimationController							_skeletonCtrl3;

	PtrLabel												_labelFilter;
	PtrDropList												_listFilter;

	PtrViewportFilter										_filterSepia;
	PtrViewportFilter										_filterNegative;
	PtrViewportFilter										_filterGrayscale;
	PtrViewportFilter										_filterRed;
	PtrViewportFilter										_filterGreen;
	PtrViewportFilter										_filterBlue;
	PtrViewportFilter										_filterDilation;
	PtrViewportFilter										_filterErosion;
	PtrViewportFilter										_filterSharpen;
	PtrViewportFilter										_filterLaplacian;
	PtrViewportFilter										_filterPrewitt;
	PtrViewportFilter										_filterSobel;
};

SYNKRO_DEMO_BEGIN
	Skinning demo;
	demo.Run();
SYNKRO_DEMO_END
