#include "../Demo.h"


class MayTheForce :
	public Demo,
	public PhysicsListener
{
public:
	MayTheForce() :
		Demo( L"May The Force" ),
		_activeActorCount( 0 )
	{
	}

	void Configure( IConfiguration* config ) override
	{
		config->Set( Param::PhysicsEnable, true );
		config->Set( Param::PhysicsSystem, PhysicsSystem::PhysX );
		config->Set( Param::PhysicsSpeed, CastUInt(12) );
	}

	void InitScene() override
	{
		// Create materials.
		PtrImage imageCheckers = GetImage( L"checkers.jpg" );
		_materialFloor = CreateTexturedMaterial( imageCheckers, Color::White, 200 );

		PtrImage imageCrate = GetImage( L"crate.bmp" );
		_materialCrate = CreateTexturedMaterial( imageCrate, Color::Lime, 1 );
		_materialCrate2 = CreateTexturedMaterial( imageCrate, Color::Orange, 1 );

		IPhysicsSystemEx* physicsSystem = _synkro->GetPhysicsSystem();
		_physicsMaterial = physicsSystem->CreateMaterial( 0.5f, 0.5f, 0.6f );

		// Listen to environment events.
		IPhysicsEnvironmentEx* physicsEnvironment = _scene->GetPhysicsEnvironment();
		physicsEnvironment->Listen( this );

		// Create floor actor.
		constexpr Float FLOOR_SIZE = 20000.0f;
		_floor = CreatePlane( nullptr, _materialFloor, FLOOR_SIZE, FLOOR_SIZE, 250, Matrix4x4::Identity, Vector3::Origin );
		IShape* shape = physicsSystem->CreatePlaneShape( _physicsMaterial, Vector3(0.0f, 1.0f, 0.0f), 0.0f );
		Matrix4x4 transform; shape->GetTransform( transform );
		_actorFloor = physicsEnvironment->CreateStaticActor( transform, shape );

		// Create crate actors.
		constexpr Float CRATE_SIDE = 40.0f;
		_crate = CreateCrate( _materialCrate, CRATE_SIDE, 15.0f );
		_crate2 = CreateCrate( _materialCrate2, CRATE_SIDE, 10.0f );
		_actor = _crate->GetActor()->AsRigid()->AsBody()->AsDynamic();
		_actor2 = _crate2->GetActor()->AsRigid()->AsBody()->AsDynamic();

		// Set initial conditions.
		RunSimulation();
	}

	void InitView() override
	{
		// Setup cameras and viewports.
		_camera->SetPosition( Vector3(-60.0f, 150.0f, -800.0f) );
		_camera->LookAt( Vector3(0.0f, 25.0f, 300.0f) );
	}

	void InitUi() override
	{
		_btnReplay = CreateButton( Point(_widgetLeft, 120), L"[R]eplay", Anchor::TopRight, HotKey(Key::R, true) );
		_btnReplay->Enable( false );
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( sender == _btnReplay )
		{
			_btnReplay->Enable( false );
			RunSimulation();
			return true;
		}

		return false;
	}

	// PhysicsListener methods.
	void OnPhysicsActorWake( IDynamicActor* actor ) override
	{
		if ( actor == _actor )
		{
			_materialCrate->SetDiffuseColor( Color::Lime );
		}
		else if ( actor == _actor2 )
		{
			_materialCrate2->SetDiffuseColor( Color::Orange );
		}

		++_activeActorCount;
	}

	void OnPhysicsActorSleep( IDynamicActor* actor ) override
	{
		if ( actor == _actor )
		{
			_materialCrate->SetDiffuseColor( Color::DimGray );
		}
		else if ( actor == _actor2 )
		{
			_materialCrate2->SetDiffuseColor( Color::DimGray );
		}

		if ( --_activeActorCount == 0 )
		{
			_btnReplay->Enable( true );
		}
	}

	void RunSimulation()
	{
		Matrix4x4 transform;
		transform.SetTranslation( Vector3(-30.0f, 180.0f, 0.0f) );
		_actor->SetWorldTransform( transform );
		_actor->SetLinearVelocity( Vector3(15.0f, 15.0f, 0.0f) );

		transform.SetTranslation( Vector3(30.0f, 160.0f, 10.0f) );
		_actor2->SetWorldTransform( transform );
		_actor2->SetLinearVelocity( Vector3(-35.0f, 15.0f, 0.0f) );
	}

	ITriangleMesh* CreateCrate( IVisualMaterial* material, Float size, Float density )
	{
		Matrix4x4 transform;
		ITriangleMesh* crate = CreateCube( nullptr, material, size, Matrix4x4::Identity, Vector3::Origin );
		IShape* shape = _synkro->GetPhysicsSystem()->CreateBoxShape( _physicsMaterial, size, size, size );
		IDynamicActor* actor = _scene->GetPhysicsEnvironment()->CreateDynamicActor( transform, shape, density );
		crate->SetActor( actor );
		return crate;
	}

	IOpaqueMaterial* CreateTexturedMaterial( IImage* diffuse, const Color& color, UInt tiling )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetDiffuseColor( color );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTiling( tiling );
		return material;
	}

private:
	PtrPhysicsMaterial										_physicsMaterial;
	PtrOpaqueMaterial										_materialFloor;
	PtrOpaqueMaterial										_materialCrate;
	PtrOpaqueMaterial										_materialCrate2;

	PtrTriangleMesh											_floor;
	PtrStaticActor											_actorFloor;

	PtrTriangleMesh											_crate;
	PtrDynamicActor											_actor;
	PtrTriangleMesh											_crate2;
	PtrDynamicActor											_actor2;

	PtrButton												_btnReplay;
	UInt													_activeActorCount;
};

SYNKRO_DEMO_BEGIN
	MayTheForce demo;
	demo.Run();
SYNKRO_DEMO_END
