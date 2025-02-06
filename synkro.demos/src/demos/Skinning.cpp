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
		_tiny = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		const Float radius = _tiny->GetBoundSphere();
		_tiny->SetScale( 45.0f/radius );
		_tiny->SetPositionX( -30.0f );

		PtrSkeleton skeleton2 = _synkro->GetSceneManager()->CreateSkeleton(); 
		_tiny2 = _scene->LoadMesh( stream, nullptr, skeleton2, 0 );
		_tiny2->SetScale( 35.0f/radius );
		_tiny2->SetPositionX( 30.0f );

		PtrSkeleton skeleton3 = _synkro->GetSceneManager()->CreateSkeleton(); 
		_tiny3 = _scene->LoadMesh( stream, nullptr, skeleton3, 0 );
		_tiny3->SetScale( 35.0f/radius );
		_tiny3->SetPositionZ( 50.0f );

		_tiny4 = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
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
		_skeletonCtrl2->SetOffset( _skeletonCtrl2->GetAnimation()->GetLength()*0.5 );
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
	}

private:
	PtrTriangleMesh											_tiny;
	PtrTriangleMesh											_tiny2;
	PtrTriangleMesh											_tiny3;
	PtrTriangleMesh											_tiny4;

	PtrSkeletonAnimationController							_skeletonCtrl;
	PtrSkeletonAnimationController							_skeletonCtrl2;
	PtrSkeletonAnimationController							_skeletonCtrl3;
};

SYNKRO_DEMO_BEGIN
	Skinning demo;
	demo.Run();
SYNKRO_DEMO_END
