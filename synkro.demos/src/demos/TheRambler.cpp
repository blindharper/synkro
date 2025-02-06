#include "../Demo.h"


class TheRambler :
	public Demo
{
public:
	TheRambler() :
		Demo( L"The Rambler" )
	{
	}

	void InitScene() override
	{
		// Create materials.
		IImage* imageCheckers = GetImage( L"checkers.jpg" );
		_materialFloor = CreateTexturedMaterial( imageCheckers );

		_materialRed = CreateColoredMaterial( Color::Red );
		_materialGreen = CreateColoredMaterial( Color::Green );
		_materialBlue = CreateColoredMaterial( Color::Blue );
		_materialYellow = CreateColoredMaterial( Color::Yellow );

		// Create floor.
		Matrix4x4 trans;
		constexpr Float FLOOR_SIZE = 250.0f;
		_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _materialFloor, nullptr );
		_synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(250, 0), Matrix4x4::Identity );

		// Create targets.
		Matrix4x4 matPosition;
		constexpr Float TARGET_RADIUS = 10.0f;
		constexpr Float TARGET_HEIGHT = 0.25f;
		
		_targetRed = _scene->CreateTriangleMesh( _floor, L"TargetRed", _materialRed, nullptr );
		_dummyRed = _scene->CreateDummy( _targetRed, L"DummyRed" );
		_synkro->GetSceneManager()->BuildMesh( _targetRed, MeshBuilder::Cylinder, Vector4(TARGET_RADIUS, TARGET_HEIGHT, 0.0f, 0.0f), Size(1, 40), Matrix4x4::Identity );
		_targetRed->SetPosition( Vector3(-75.0f, 0.0f, 75.0f) );
		_dummyRed->SetPositionY( 31.0f );

		_targetGreen = _scene->CreateTriangleMesh( _floor, L"TargetGreen", _materialGreen, nullptr );
		_dummyGreen = _scene->CreateDummy( _targetGreen, L"DummyGreen" );
		_synkro->GetSceneManager()->BuildMesh( _targetGreen, MeshBuilder::Cylinder, Vector4(TARGET_RADIUS, TARGET_HEIGHT, 0.0f, 0.0f), Size(1, 40), Matrix4x4::Identity );
		_targetGreen->SetPosition( Vector3(75.0f, 0.0f, 75.0f) );
		_dummyGreen->SetPositionY( 31.0f );

		_targetBlue = _scene->CreateTriangleMesh( _floor, L"TargetBlue", _materialBlue, nullptr );
		_dummyBlue = _scene->CreateDummy( _targetBlue, L"DummyBlue" );
		_synkro->GetSceneManager()->BuildMesh( _targetBlue, MeshBuilder::Cylinder, Vector4(TARGET_RADIUS, TARGET_HEIGHT, 0.0f, 0.0f), Size(1, 40), Matrix4x4::Identity );
		_targetBlue->SetPosition( Vector3(75.0f, 0.0f, -75.0f) );
		_dummyBlue->SetPositionY( 31.0f );

		_targetYellow = _scene->CreateTriangleMesh( _floor, L"TargetYellow", _materialYellow, nullptr );
		_dummyYellow = _scene->CreateDummy( _targetYellow, L"DummyYellow" );
		_synkro->GetSceneManager()->BuildMesh( _targetYellow, MeshBuilder::Cylinder, Vector4(TARGET_RADIUS, TARGET_HEIGHT, 0.0f, 0.0f), Size(1, 40), Matrix4x4::Identity );
		_targetYellow->SetPosition( Vector3(-75.0f, 0.0f, -75.0f) );
		_dummyYellow->SetPositionY( 31.0f );

		// Create model.
		PtrStream stream = GetStream( L"tiny.x" );
		PtrSkeleton skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_model = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		const Float sphere = _model->GetBoundSphere();
		_model->SetScale( 45.0f/sphere );
		_model->SetPositionY( _dummyYellow->GetPositionY() );

		// Animate model.
		_skeletonCtrl = _model->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl->SetMode( AnimationMode::Loop );
		_skeletonCtrl->SetDirection( AnimationDirection::Forward );
		_skeletonCtrl->SetLoopCount( 0 );
		_skeletonCtrl->SetSpeed( 4.0 );

		// Create constraint and controller.
		_lookAt = _model->CreateLookAtConstraint( nullptr );
		_moveTo = _model->CreateAnimationController( nullptr, this );
		_moveTo->SetMode( AnimationMode::Single );
		_trackPosition = _moveTo->CreatePositionTrack();
	}

	void InitView() override
	{
		// Setup cameras and viewports.
		_camera->SetPosition( Vector3(0.0f, 150.0f, -300.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		// Create UI widgets.
		_btnMoveToRed = CreateButton( _dummyRed->ID(), Point(_widgetLeft, 120), L"Move to [R]ed", Anchor::TopRight, HotKey(Key::R, true), Color::Red);
		_btnMoveToGreen = CreateButton( _dummyGreen->ID(), Point(_widgetLeft, 150), L"Move to [G]reen", Anchor::TopRight, HotKey(Key::G, true), Color::Green );
		_btnMoveToBlue = CreateButton( _dummyBlue->ID(), Point(_widgetLeft, 180), L"Move to [B]lue", Anchor::TopRight, HotKey(Key::B, true), Color::Blue );\
		_btnMoveToYellow = CreateButton( _dummyYellow->ID(), Point(_widgetLeft, 210), L"Move to [Y]ellow", Anchor::TopRight, HotKey(Key::Y, true), Color::Yellow );
	}

	// AnimationListener methods.
	void OnAnimationStop( IAnimationController* sender ) override
	{
		Demo::OnAnimationStop( sender );

		if ( (sender == _moveTo) && (_moveTo->GetState() == ControllerState::Inactive) )
		{
			_skeletonCtrl->Start( false );
		}
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		// Handle button clicks.
		INode* target = _scene->GetNode( sender->ID() );
		if ( target != nullptr )
		{
			MoveTo( target );
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateTexturedMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		return material;
	}

	IOpaqueMaterial* CreateColoredMaterial( const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetDiffuseColor( color );
		return material;
	}

	void MoveTo( INode* target )
	{
		_lookAt->SetTarget( target );

		Matrix4x4 transModel;
		Matrix4x4 transTarget;
		_model->GetWorldTransform( transModel );
		target->GetWorldTransform( transTarget );

		const Vector3 posModel = transModel.Translation();
		const Vector3 posTarget = transTarget.Translation();
		const Float distance = (posTarget - posModel).Length();
		constexpr Float SPEED = 40.0f;

		_trackPosition->Clear();
		_trackPosition->SetKey( 0.0, posModel, Interpolation::Linear );
		_trackPosition->SetKey( CastDouble(distance/SPEED), posTarget, Interpolation::Linear );
		_moveTo->Reset();
		_moveTo->Start( true );

		_skeletonCtrl->Start( true );
	}

private:
	PtrOpaqueMaterial										_materialFloor;
	PtrTriangleMesh											_floor;

	PtrOpaqueMaterial										_materialRed;
	PtrTriangleMesh											_targetRed;
	PtrNode													_dummyRed;

	PtrOpaqueMaterial										_materialGreen;
	PtrTriangleMesh											_targetGreen;
	PtrNode													_dummyGreen;

	PtrOpaqueMaterial										_materialBlue;
	PtrTriangleMesh											_targetBlue;
	PtrNode													_dummyBlue;

	PtrOpaqueMaterial										_materialYellow;
	PtrTriangleMesh											_targetYellow;
	PtrNode													_dummyYellow;

	PtrTriangleMesh											_model;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrLookAtConstraint										_lookAt;
	PtrNodeAnimationController								_moveTo;
	PtrKeyframedVector3Track								_trackPosition;
	PtrButton												_btnMoveToRed;
	PtrButton												_btnMoveToGreen;
	PtrButton												_btnMoveToBlue;
	PtrButton												_btnMoveToYellow;
};

SYNKRO_DEMO_BEGIN
	TheRambler demo;
	demo.Run();
SYNKRO_DEMO_END
