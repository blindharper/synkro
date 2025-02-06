#include "../Demo.h"


class ThreeIsACrowd :
	public Demo
{
public:
	ThreeIsACrowd() :
		Demo( L"Three Is A Crowd" )
	{
	}

	void InitScene() override
	{
		// Load models.
		PtrStream stream = GetStream( L"tiny_anim.x" );
		ISkeleton* skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_tinyTemplate = _scene->LoadMesh( stream, nullptr, skeleton, WIDTH*DEPTH )->AsBatch();
		_tinyTemplate->SetOrientationPitch( Math::Pi );
		_tinyTemplate->SetOrientationRoll( Math::Pi );
		_tinyTemplate->SetScale( Vector3(0.11f, 0.1f, 0.1f) );

		Double lengths[3];
		Double deltaLengths[3];
		Double offsets[3];
		for ( UInt i = 0; i < 3; ++i )
		{
			lengths[i] = skeleton->GetAnimationSet(i)->GetAnimation(0)->GetLength();
			deltaLengths[i] = lengths[i]/CastDouble(_tinyTemplate->GetCapacity());
			offsets[i] = 0.0;
		}

		Random rnd;

		Matrix4x4 trans;
		constexpr Float startX = -580.0f;
		constexpr Float startZ = -600.0f;
		Float z = startZ;
		
		for ( UInt j = 0; j < DEPTH; ++j )
		{
			Float x = startX;
			for ( UInt i = 0; i < WIDTH; ++i )
			{
				trans.SetTranslation( Vector3(x, 0.0f, z) );
				x += 40.0f;
				ITriangleMesh* tiny = _tinyTemplate->CreateInstance( nullptr, trans, Color::Random() );
				Int idx = rnd.GetInt()%3;

				ISkeletonAnimationController* skeletonCtrl = tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
				skeletonCtrl->SetAnimationSet( idx );
				skeletonCtrl->SetMode( AnimationMode::Loop );
				skeletonCtrl->SetDirection( AnimationDirection::Forward );
				skeletonCtrl->SetLoopCount( 0 );
				skeletonCtrl->SetSpeed( 4.0 );
				skeletonCtrl->SetOffset( offsets[idx]);
				skeletonCtrl->Start( true );
				offsets[idx] += deltaLengths[idx];
			}
			z += 40.0f;
		}
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 800.0f, -1900.0f) );
		_camera->LookAt( Vector3::Origin );
	}

private:
	enum
	{
		WIDTH = 30,
		DEPTH = 30,
	};

	PtrTriangleMeshBatch									_tinyTemplate;
};

SYNKRO_DEMO_BEGIN
	ThreeIsACrowd demo;
	demo.Run();
SYNKRO_DEMO_END
