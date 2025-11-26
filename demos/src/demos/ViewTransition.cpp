#include "../Demo.h"


class ViewTransition :
	public Demo
{
public:
	ViewTransition() :
		Demo( L"View Transition" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		PtrStream stream = GetStream( L"cell.x" );
		_cell = _scene->LoadMesh( stream, nullptr, nullptr, 0 );
		_cell->SetScale( 2.0f );

		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_materialPurple = CreateMaterial( diffuseMap, Color::Purple );
		_materialOrange = CreateMaterial( diffuseMap, Color::OrangeAerospace );
		_materialGreen = CreateMaterial( diffuseMap, Color::BritishRacingGreen );
		_materialBlue = CreateMaterial( diffuseMap, Color::ImperialBlue );

		// Animate materials.
		_ctrlPurple = AnimateMaterial( _materialPurple, Color::PinkFlamingo, 2.0 );
		_ctrlOrange = AnimateMaterial( _materialOrange, Color::Orange, 3.0 );
		_ctrlGreen = AnimateMaterial( _materialGreen, Color::Lime, 4.0 );
		_ctrlBlue = AnimateMaterial( _materialBlue, Color::RoyalBlue, 5.0 );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetAmbientColor( Color::DimGray );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, -1.0f, 0.0f) );

		// Create torus.
		constexpr Float TORUS_RADIUS = 0.5f;
		_torus = CreateTorus( nullptr, _materialPurple, TORUS_RADIUS, 2.0f*TORUS_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(-2.0f, -4.0f, 2.0f) );

		// Create cone.
		constexpr Float CONE_HEIGHT = 3.0f;
		_cone = CreateCone( nullptr, _materialOrange, 1.0f, CONE_HEIGHT, 40, 40, Matrix4x4::Identity, Vector3(3.0f, -2.0f, 0.0f) );

		// Create sphere.
		constexpr Float SPHERE_RADIUS = 1.5f;
		_sphere = CreateSphere( nullptr, _materialGreen, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(0.0f, 0.0f, 4.0f) );

		// Create box.
		constexpr Float BOX_SIDE = 1.5f;
		_box = CreateBox( nullptr, _materialBlue, 0.5f*BOX_SIDE, BOX_SIDE, 3.0F*BOX_SIDE, Matrix4x4::Identity, Vector3(-3.8f, -2.0f, -2.0f) );
	}

	void InitView() override
	{
		// Setup viewport and cameras.
		Size size; _viewport->GetSize( size );
		_viewport->SetColor( Color::White );
		_viewport->ShowLabel( true );
		_camera->SetPosition( Vector3(0.0f, 2.6f, -18.0f) );
		_camera->LookAt( Vector3::Origin );

		// Create extra viewports.
		_viewport2 = CreateViewport( Vector3(5.0f, 1.0f, -10.0f), Vector3::Origin, size );
		_viewport3 = CreateViewport( Vector3(5.0f, 3.0f, -7.0f), Vector3(-2.0f, -2.0f, 2.0f), size );
		_viewport4 = CreateViewport( Vector3(3.0f, 4.0f, 20.0f), Vector3(-4.0f, -2.0f, -2.0f), size );
		_viewportBlack = _synkro->GetViewportManager()->CreateViewport(_window, Rect(Point(0, 0), size), nullptr, Color::Black );
		_viewportBlack->SetOpacity( 0.0f );
		_viewportBlack->ShowLabel( false );

		// Setup transition controllers.
		_ctrlTransition1 = _synkro->GetViewportManager()->CreateTransitionController( nullptr );
		_ctrlTransition1->SetKey( 0.0, _viewport, TransitionEffect::Blend );
		_ctrlTransition1->SetKey( 3.0, _viewport2, TransitionEffect::Blend );
		_ctrlTransition1->SetKey( 6.0, _viewport3, TransitionEffect::Blend );
		_ctrlTransition1->SetKey( 9.0, _viewport4, TransitionEffect::Blend );
		_ctrlTransition1->SetKey( 12.0, _viewport2, TransitionEffect::Blend );
		_ctrlTransition1->SetLoopCount( 0 );

		_ctrlTransition2 = _synkro->GetViewportManager()->CreateTransitionController( nullptr );
		_ctrlTransition2->SetKey( 0.0, _viewport, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 2.0, _viewportBlack, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 4.0, _viewport4, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 6.0, _viewportBlack, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 8.0, _viewport2, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 9.0, _viewportBlack, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 11.0, _viewportBlack, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 12.0, _viewport3, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 14.0, _viewportBlack, TransitionEffect::Blend );
		_ctrlTransition2->SetKey( 16.0, _viewport, TransitionEffect::Blend );
		_ctrlTransition2->SetLoopCount( 0 );

		_ctrlTransition3 = _synkro->GetViewportManager()->CreateTransitionController( nullptr );
		_ctrlTransition3->SetKey( 0.0, _viewport, TransitionEffect::Step );
		_ctrlTransition3->SetKey( 1.5, _viewport4, TransitionEffect::Step );
		_ctrlTransition3->SetKey( 3.0, _viewport2, TransitionEffect::Step );
		_ctrlTransition3->SetKey( 4.5, _viewport3, TransitionEffect::Step );
		_ctrlTransition3->SetKey( 6.0, _viewport, TransitionEffect::Step );
		_ctrlTransition3->SetLoopCount( 0 );
	}

	void InitUi() override
	{
		_btnSequence1 = CreateButton( Point(_widgetLeft, 120), L"Sequence [1]", Anchor::TopRight, HotKey(Key::D1, true) );
		_btnSequence2 = CreateButton( Point(_widgetLeft, 150), L"Sequence [2]", Anchor::TopRight, HotKey(Key::D2, true) );
		_btnSequence3 = CreateButton( Point(_widgetLeft, 180), L"Sequence [3]", Anchor::TopRight, HotKey(Key::D3, true) );
		_switchAnimate = CreateSwitch( Point(_widgetLeft, 210), 150, L"Animate materials", false );
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		_viewportBlack->SetOpacity( 0.0f );
		if ( sender == _btnSequence1 )
		{
			_ctrlTransition2->Start( false );
			_ctrlTransition3->Start( false );
			_ctrlTransition1->Start( true );
			return true;
		}
		else if ( sender == _btnSequence2 )
		{
			_ctrlTransition1->Start( false );
			_ctrlTransition3->Start( false );
			_ctrlTransition2->Start( true );
			return true;
		}
		else if ( sender == _btnSequence3 )
		{
			_ctrlTransition1->Start( false );
			_ctrlTransition2->Start( false );
			_ctrlTransition3->Start( true );
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchAnimate )
		{
			Bool animate = _switchAnimate->IsOn();
			_ctrlPurple->Start( animate );
			_ctrlOrange->Start( animate );
			_ctrlGreen->Start( animate );
			_ctrlBlue->Start( animate );
			if ( !animate )
			{
				_materialPurple->SetEmissiveColor( Color::Black );
				_materialOrange->SetEmissiveColor( Color::Black );
				_materialGreen->SetEmissiveColor( Color::Black );
				_materialBlue->SetEmissiveColor( Color::Black );
			}
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse, const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetAmbientColor( color );
		material->SetDiffuseColor( color );
		material->SetSpecularColor( Color::White );
		material->SetSpecularPower( 10.0f );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		return material;
	}

	IViewport* CreateViewport( const Vector3& eye, const Vector3& at, const Size& size )
	{
		ICamera* camera = _scene->CreateCamera( nullptr, String::Empty );
		camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
		camera->SetAspect( _displayModeWindowed.AspectFactor() );
		camera->SetFront( 0.1f );
		camera->SetBack( 10000.0f );
		camera->SetPosition( eye );
		camera->LookAt( at );

		IViewport* viewport = _synkro->GetViewportManager()->CreateViewport(_window, Rect(Point(0, 0), size), camera, Color::White );
		viewport->SetOpacity( 0.0f );
		viewport->ShowLabel( true );
		return viewport;
	}

	ISimpleMaterialAnimationController* AnimateMaterial( IOpaqueMaterial* material, const Color& color, Double duration )
	{
		ISimpleMaterialAnimationController* ctrl = material->CreateAnimationController( nullptr, nullptr )->AsSimple();
		IKeyframedColorTrack* trackColor = ctrl->CreateEmissiveColorTrack();
		trackColor->SetKey( 0.0, Color::Black );
		trackColor->SetKey( 0.5*duration, color );
		trackColor->SetKey( duration, Color::Black );
		ctrl->SetMode( AnimationMode::Loop );
		return ctrl;
	}

private:
	PtrOpaqueMaterial										_materialPurple;
	PtrOpaqueMaterial										_materialOrange;
	PtrOpaqueMaterial										_materialGreen;
	PtrOpaqueMaterial										_materialBlue;

	PtrSimpleMaterialAnimationController					_ctrlPurple;
	PtrSimpleMaterialAnimationController					_ctrlOrange;
	PtrSimpleMaterialAnimationController					_ctrlGreen;
	PtrSimpleMaterialAnimationController					_ctrlBlue;

	PtrDirectLight											_light;
	PtrTriangleMesh											_cell;
	PtrTriangleMesh											_torus;
	PtrTriangleMesh											_cone;
	PtrTriangleMesh											_sphere;
	PtrTriangleMesh											_box;

	PtrViewport												_viewportBlack;
	PtrViewport												_viewport2;
	PtrViewport												_viewport3;
	PtrViewport												_viewport4;
	PtrViewportTransitionController							_ctrlTransition1;
	PtrViewportTransitionController							_ctrlTransition2;
	PtrViewportTransitionController							_ctrlTransition3;

	PtrButton												_btnSequence1;
	PtrButton												_btnSequence2;
	PtrButton												_btnSequence3;
	PtrSwitch												_switchAnimate;
};

SYNKRO_DEMO_BEGIN
	ViewTransition demo;
	demo.Run();
SYNKRO_DEMO_END
