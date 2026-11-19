#include "../Demo.h"


class Blur :
	public Demo
{
public:
	Blur() :
		Demo( L"Blur" )
	{
	}

	void InitScene() override
	{
		// Load model.
		PtrStream stream = GetStream( L"tiny.x" );
		PtrSkeleton skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_tiny = _scene->LoadMesh( stream, skeleton );
		const Float sphere = _tiny->GetBoundSphere();
		_tiny->SetScale( 45.0f/sphere );

		// Animate model.
		_skeletonCtrl = _tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl->SetMode( AnimationMode::Loop );
		_skeletonCtrl->SetDirection( AnimationDirection::Forward );
		_skeletonCtrl->SetLoopCount( 0 );
		_skeletonCtrl->SetSpeed( 4.0 );
		_skeletonCtrl->Start( true );
	}

	void InitView() override
	{
		// Setup camera and viewport.
		_camera->SetPosition( Vector3(0.0f, 50.0f, -150.0f) );
		_camera->LookAt( Vector3(1.0f, 1.0f, 1.0f) );

		// Setup post-processing filter.
		_filterBlur = _viewport->CreateFilter( ViewportFilter::Blur )->AsKernel3x3();
	}

	void InitUi() override
	{
		_labelPassCount = CreateLabel( Point(_widgetLeft, 120), String::Empty );
		_sliderPassCount = CreateSlider( none, Point(_widgetLeft, 150), 0, 500, 0 );
		SetPassCount( 0 );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _sliderPassCount )
		{
			SetPassCount( _sliderPassCount->GetPosition() );
			return true;
		}

		return false;
	}

	void SetPassCount( UInt passCount )
	{
		_filterBlur->SetPassCount( passCount );
		_labelPassCount->SetText( String::Format(L"Pass Count: {0}", passCount) );
	}

private:
	PtrKernel3x3Filter										_filterBlur;

	PtrTriangleMesh											_tiny;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrLabel												_labelPassCount;
	PtrSlider												_sliderPassCount;
};

SYNKRO_DEMO_BEGIN
	Blur demo;
	demo.Run();
SYNKRO_DEMO_END
