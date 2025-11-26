#include "../Demo.h"


class ColorShift :
	public Demo
{
public:
	ColorShift() :
		Demo( L"Color Shift" )
	{
	}

	void InitScene() override
	{
		// Load model.
		PtrStream stream = GetStream( L"tiny.x" );
		ISkeleton* skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_tiny = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
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
		_filterHue = _viewport->CreateFilter( ViewportFilter::Hue )->AsSimple();
		_filterHue->EnableRect( true );
		_filterHue->SetValue( 0.0f );
		SetFilterRect();
	}

	void InitUi() override
	{
		_labelHue = CreateLabel( Point(_widgetLeft, 120), L"Shift" );
		_angleHue = CreateAngle( none, Point(_widgetLeft+46, 140) );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _angleHue )
		{
			_filterHue->SetValue( _angleHue->GetValue() );
			return true;
		}

		return false;
	}

	void OnDisplayModeChanged( const DisplayMode& displayMode ) override
	{
		SetFilterRect();
	}

	void SetFilterRect()
	{
		Size sz; _viewport->GetSize( sz );
		const Point pt( sz.Width/2, 0 );
		const Size size( sz.Width/2, sz.Height );
		_filterHue->SetRect( Rect(pt, size) );
	}

private:
	PtrSimpleFilter											_filterHue;

	PtrTriangleMesh											_tiny;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrLabel												_labelHue;
	PtrAngle												_angleHue;
};

SYNKRO_DEMO_BEGIN
	ColorShift demo;
	demo.Run();
SYNKRO_DEMO_END
