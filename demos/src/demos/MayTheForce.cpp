#include "../Demo.h"


class MayTheForce :
	public Demo
{
public:
	MayTheForce() :
		Demo( L"May The Force" )
	{
	}

	void Configure( IConfiguration* config ) override
	{
		config->Set( Param::PhysicsEnable, true );
		config->Set( Param::PhysicsSystem, PhysicsSystem::PhysX );
	}

	void InitScene() override
	{
		// Create materials.
		PtrImage imageCheckers = GetImage( L"checkers.jpg" );
		_materialFloor = CreateTexturedMaterial( imageCheckers, 200 );

		PtrImage imageCrate = GetImage( L"crate.bmp" );
		_materialCrate = CreateTexturedMaterial( imageCrate, 1 );

		_physicsMaterial = _synkro->GetPhysicsSystem()->CreateMaterial( 0.5f, 0.5f, 0.6f );

		// Create floor actor.
		constexpr Float FLOOR_SIZE = 20000.0f;
		_floor = CreatePlane( nullptr, _materialFloor, FLOOR_SIZE, FLOOR_SIZE, 250, Matrix4x4::Identity, Vector3::Origin );
		IShape* shape = _synkro->GetPhysicsSystem()->CreatePlaneShape( _physicsMaterial, Vector3(0.0f, -1.0f, 0.0f), 0.0f );
		Matrix4x4 transform; shape->GetTransform( transform );
		_actorFloor = _scene->GetPhysicsEnvironment()->CreateStaticActor( transform, shape );

		// Create crate actors.
		constexpr Float CRATE_SIDE = 30.0f;
		_crate = CreateCrate( CRATE_SIDE, 10.0f, Vector3(-30.0f, 180.0f, 0.0f), Vector3(15.0f, 15.0f, 0.0f) );
		_crate2 = CreateCrate( CRATE_SIDE, 10.0f, Vector3(30.0f, 160.0f, 10.0f), Vector3(-35.0f, 15.0f, 0.0f) );
	}

	void InitView() override
	{
		// Setup cameras and viewports.
		_camera->SetPosition( Vector3(0.0f, 150.0f, -600.0f) );
		_camera->LookAt( Vector3(0.0f, 25.0f, 300.0f) );
	}

	ITriangleMesh* CreateCrate( Float size, Float density, const Vector3 position, const Vector3 velocity )
	{
		ITriangleMesh* crate = CreateCube( nullptr, _materialCrate, size, Matrix4x4::Identity, Vector3::Origin );
		IShape* shape = _synkro->GetPhysicsSystem()->CreateBoxShape( _physicsMaterial, size, size, size );
		Matrix4x4 transform; transform.SetTranslation( position );
		IDynamicActor* actor = _scene->GetPhysicsEnvironment()->CreateDynamicActor( transform, shape, density );
		actor->SetLinearVelocity( velocity );
		crate->SetActor( actor );
		return crate;
	}

	IOpaqueMaterial* CreateTexturedMaterial( IImage* diffuse, UInt tiling )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( tiling );
		material->SetTilingVertical( tiling );
		return material;
	}

private:
	PtrPhysicsMaterial										_physicsMaterial;
	PtrOpaqueMaterial										_materialFloor;
	PtrOpaqueMaterial										_materialCrate;
	PtrTriangleMesh											_floor;
	PtrTriangleMesh											_crate;
	PtrTriangleMesh											_crate2;
	PtrStaticActor											_actorFloor;
};

SYNKRO_DEMO_BEGIN
	MayTheForce demo;
	demo.Run();
SYNKRO_DEMO_END
