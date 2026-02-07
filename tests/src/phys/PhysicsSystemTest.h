#include <phys/IPhysicsSystemFactory.h>
#include <phys/PhysicsSystemEx.h>
#include <phys/IPhysicsEnvironment.h>
#include <phys/IPhysicsMaterial.h>
#include <phys/IDynamicActor.h>
#include <phys/IStaticActor.h>
#include <phys/IShape.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::mem;
using namespace synkro::phys;
using namespace synkro;

//------------------------------------------------------------------------------


class PhysicsSystemTest
{
public:
	PhysicsSystemTest( const String& name, IPhysicsSystemFactory* factPhysicsSys ) :
		_name( name ),
		_factPhysicsSys( factPhysicsSys )
	{
	}

	void Run()
	{
		Char buf[1024];
		_name.GetChars( 0, 1024, buf );
		wprintf( L"%s\n", buf );

		P(PhysicsSystemEx) physSys = new PhysicsSystemEx( nullptr );
		physSys->Initialize( _factPhysicsSys );

		P(IPhysicsEnvironment) environment = physSys->CreateEnvironment( L"Scene" );
		P(IPhysicsMaterial) material = physSys->CreateMaterial( 0.5f, 0.5f, 0.6f );

		P(IShape) shapePlane = physSys->CreatePlaneShape( material, Vector3(0.0f, -1.0f, 0.0f), 0.0f );
		Matrix4x4 transform; shapePlane->GetTransform( transform );
		P(IStaticActor) actorPlane = environment->CreateStaticActor( transform, shapePlane );

		constexpr Float CUBE_SIDE = 30.0f;
		P(IShape) shapeCube = physSys->CreateBoxShape( material, CUBE_SIDE, CUBE_SIDE, CUBE_SIDE );
		Matrix4x4 transformCube; transformCube.SetTranslation( Vector3(0.0f, 200.0f, 0.0f) );
		P(IDynamicActor) actorCube = environment->CreateDynamicActor( transformCube, shapeCube, 10.0f );
		
		constexpr Double DELTA = 1.0/60.0;
		Double delta = 1.0 - DELTA;
		Float oldY = 201.0f;
		while ( physSys->Update(DELTA) )
		{
			Matrix4x4 transform;
			actorCube->GetWorldTransform( transform );
			Float y = transform.Translation().y;
			if ( Math::Abs(oldY-y) < Math::Eps )
			{
				break;
			}
			oldY = y;

			delta += DELTA;
			if ( delta >= 1.0 )
			{
				wprintf( L"Y-coordinate: %.3f\n", y );
				delta = 0.0;
			}
		}
		wprintf( L"Done\n" );
	}

private:
	String					_name;
	IPhysicsSystemFactory*	_factPhysicsSys;
};
