#include "../Demo.h"


class Emboss :
	public Demo
{
public:
	Emboss() :
		Demo( L"Emboss" )
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
		_filterEmboss = _viewport->CreateFilter( ViewportFilter::Emboss )->AsKernel3x3()->AsEmboss();
		_filterEmboss->SetAngle( 0.0f );
	}

	void InitUi() override
	{
		_labelAngle = CreateLabel( Point(_widgetLeft, 120), L"Angle" );
		_angle = CreateAngle( none, Point(_widgetLeft+46, 140) );
		_angle->SetValue( 0.0f );

		_labelDepth = CreateLabel( Point(_widgetLeft, 210), String::Empty );
		_sliderDepth = CreateSlider( none, Point(_widgetLeft, 240), 0, 1000, 500 );
		SetDepth( 500.0f );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _angle )
		{
			_filterEmboss->SetAngle( _angle->GetValue() );
			return true;
		}
		else if ( sender == _sliderDepth )
		{
			SetDepth( CastFloat(_sliderDepth->GetPosition()) );
			return true;
		}

		return false;
	}

	void SetDepth( Float depth )
	{
		depth = 0.001f*depth;
		_filterEmboss->SetDepth( depth );
		_labelDepth->SetText( String::Format(L"Depth: {0,0.000}", depth) );
	}

private:
	PtrEmbossFilter											_filterEmboss;

	PtrTriangleMesh											_tiny;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrLabel												_labelAngle;
	PtrAngle												_angle;

	PtrLabel												_labelDepth;
	PtrSlider												_sliderDepth;
};

SYNKRO_DEMO_BEGIN
	Emboss demo;
	demo.Run();
SYNKRO_DEMO_END
