#include "../Demo.h"


class PurpleHaze :
	public Demo
{
public:
	PurpleHaze() :
		Demo( L"Purple Haze" )
	{
	}

	void InitScene() override
	{
		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_materialFloor = CreateMaterial( diffuseMap );

		// Create floor.
		constexpr Float FLOOR_SIZE = 500.0f;
		_floor = CreatePlane( nullptr, _materialFloor, FLOOR_SIZE, FLOOR_SIZE, 16, Matrix4x4::Identity, Vector3::Origin );

		// Create models.
		PtrStream stream = GetStream( L"tiny.x" );
		ISkeleton* skeleton = _synkro->GetSceneManager()->CreateSkeleton();
		_tiny = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		_tiny2 = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		_tiny3 = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		_tiny4 = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		const Float sphere = _tiny->GetBoundSphere();
		Vector3 center; _tiny->GetCenter( center );
		const Float sign = center.y/Math::Abs(center.y);

		_tiny->SetScale( 35.0f/sphere );
		_tiny->SetPosition( Vector3(-15.0f, 35.0f, -120.0f) );

		_tiny2->SetScale( 35.0f/sphere );
		_tiny2->SetPosition( Vector3(15.0f, 35.0f, 150.0f) );

		_tiny3->SetScale( 35.0f/sphere );
		_tiny3->SetPosition( Vector3(-100.0f, 35.0f, 50.0f) );

		_tiny4->SetScale( 35.0f/sphere );
		_tiny4->SetPosition( Vector3(70.0f, 35.0f, -50.0f) );

		// Launch models animation.
		_skeletonCtrl = _tiny->GetSkeleton()->CreateAnimationController( nullptr, nullptr );
		_skeletonCtrl->SetMode( AnimationMode::Loop );
		_skeletonCtrl->SetDirection( AnimationDirection::Forward );
		_skeletonCtrl->SetLoopCount( 0 );
		_skeletonCtrl->SetSpeed( 4.0 );
		_skeletonCtrl->Start( true );

		// Setup vertex fog.
		_vertexFog = _scene->GetFog();
		_vertexFogCtrl = _vertexFog->CreateAnimationController( nullptr, nullptr );
		_vertexFogColorTrack = _vertexFogCtrl->CreateColorTrack();
		_vertexFogCtrl->SetMode( AnimationMode::Single );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 100.0f, -300.0f) );
		_camera->LookAt( Vector3(1.0f, 1.0f, 1.0f) );

		_viewportCtrl = _viewport->CreateAnimationController( nullptr, nullptr );
		_viewportColorTrack = _viewportCtrl->CreateColorTrack();
		_viewportCtrl->SetMode( AnimationMode::Single );

		// Setup fragment fog.
		_fragmentFog = _viewport->CreateFilter(ViewportFilter::Fog)->AsDepth()->AsFog();
		_fragmentFog->SetCamera( _camera );
		_fragmentFog->SetDepthMap( _viewport->CreateDepthTarget() );
		_fragmentFogCtrl = _fragmentFog->CreateAnimationController( nullptr, nullptr )->AsFog();
		_fragmentFogColorTrack = _fragmentFogCtrl->CreateColorTrack();
		_fragmentFogCtrl->SetMode( AnimationMode::Single );
	}

	void InitUi() override
	{
		_switchEnable = CreateSwitch( Point(_widgetLeft, 120), 150, L"Enable Fog", true );

		_labelTechnique = CreateLabel( Point(_widgetLeft-114, 152), L"Technique:" );
		_listTechnique = CreateDropList( Point(_widgetLeft, 150), Size(150, 25) );
		_listTechnique->AddItem( L"Vertex" );
		_listTechnique->AddItem( L"Fragment" );
		_listTechnique->SetListHeight( _listTechnique->GetItemCount() );

		_labelType = CreateLabel( Point(_widgetLeft-94, 182), L"Type:" );
		_listType = CreateDropList( Point(_widgetLeft, 180), Size(150, 25) );
		_listType->AddItem( FogType::Linear.ToString() );
		_listType->AddItem( FogType::Exponential.ToString() );
		_listType->AddItem( FogType::ExponentialSquared.ToString() );
		_listType->SetListHeight( _listType->GetItemCount() );
		
		_labelColor = CreateLabel( Point(_widgetLeft-96, 212), L"Color:" );
		_listColor = CreateDropList( Point(_widgetLeft, 210), Size(150, 25) );
		_listColor->AddItem( Color::DarkPurple.ToString() );
		_listColor->AddItem( Color::DimGray.ToString() );
		_listColor->AddItem( Color::LightGray.ToString() );
		_listColor->AddItem( Color::PaleBrown.ToString() );
		_listColor->AddItem( Color::PastelPink.ToString() );
		_listColor->AddItem( Color::Black.ToString() );
		_listColor->SetListHeight( _listColor->GetItemCount() );

		_labelDensity = CreateLabel( Point(_widgetLeft, 240), String::Empty );
		_sliderDensity = CreateSlider( none, Point(_widgetLeft, 260), 0, 1000, 500 );
		SetDensity( 0.01f );

		_labelStart = CreateLabel( Point(_widgetLeft, 240), String::Empty );
		_sliderStart = CreateSlider( none, Point(_widgetLeft, 260), 0, 1000, 0 );
		SetStart( 0.0f );

		_labelEnd = CreateLabel( Point(_widgetLeft, 290), String::Empty );
		_sliderEnd = CreateSlider( none, Point(_widgetLeft, 310), 0, 1000, 500 );
		SetEnd( 500.0f );

		_listTechnique->SelectItem( 0 );
		_listType->SelectItem( 0 );
		_listColor->SelectItem( 0 );
		UpdateWidgets();
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _switchEnable )
		{
			const Bool enabled = _switchEnable->IsOn();
			const FogType type = FogType( _listType->GetText() );
			const UInt technique = _listTechnique->GetSelectedItem();
			_vertexFog->SetType( enabled && (technique == TECHNIQUE_VERTEX) ? type : FogType::None );
			_fragmentFog->SetType( enabled && (technique == TECHNIQUE_FRAGMENT) ? type : FogType::None );
			_viewport->SetColor( enabled ? Color(_listColor->GetText()) : Color::DimGray );
			UpdateWidgets();
			return true;
		}
		else if ( (sender == _listTechnique) || (sender == _listType) )
		{
			const FogType type = FogType( _listType->GetText() );
			const UInt technique = _listTechnique->GetSelectedItem();
			_vertexFog->SetType( (technique == TECHNIQUE_VERTEX) ? type : FogType::None );
			_fragmentFog->SetType( (technique == TECHNIQUE_FRAGMENT) ? type : FogType::None );
			UpdateWidgets();
			return true;
		}
		else if ( sender == _listColor )
		{
			const Color color( _listColor->GetText() );
			SetColor( color );
			return true;
		}
		else if ( sender == _sliderDensity )
		{
			const Float density = 0.02f*CastFloat(_sliderDensity->GetPosition()) / CastFloat(_sliderDensity->GetMaxPosition());
			SetDensity( density );
			return true;
		}
		else if ( sender == _sliderStart )
		{
			const Float start = CastFloat(_sliderStart->GetPosition());
			SetStart( start );
			return true;
		}
		else if ( sender == _sliderEnd )
		{
			const Float end = CastFloat(_sliderEnd->GetPosition());
			SetEnd( end );
			return true;
		}

		return false;
	}

	void SetColor( const Color& color )
	{
		Color col; _vertexFog->GetColor( col );
		const Bool animate = (_viewportColorTrack->GetKeyCount() > 0);
		SetupColorAnimation( _viewportCtrl, _viewportColorTrack, col, color, animate );
		SetupColorAnimation( _vertexFogCtrl, _vertexFogColorTrack, col, color, animate );
		SetupColorAnimation( _fragmentFogCtrl, _fragmentFogColorTrack, col, color, animate );
		if ( !animate )
		{
			_viewport->SetColor( color );
			_vertexFog->SetColor( color );
			_fragmentFog->SetColor( color );
		}
	}

	void SetupColorAnimation( IController* ctrl, IKeyframedColorTrack* track, const Color& from, const Color& to, Bool start )
	{
		track->Clear();
		track->SetKey( 0.0, from );
		track->SetKey( 1.0, to, Interpolation::EaseIn );
		ctrl->Reset();
		ctrl->Start( start );
	}

	void SetDensity( Float density )
	{
		_vertexFog->SetDensity( density );
		_fragmentFog->SetDensity( density );
		_labelDensity->SetText( String::Format(L"Density: {0,0.000}", density) );
	}

	void SetStart( Float start )
	{
		_vertexFog->SetStart( start );
		_fragmentFog->SetStart( start );
		_labelStart->SetText( String::Format(L"Start: {0,0.000}", start) );
	}

	void SetEnd( Float end )
	{
		_vertexFog->SetEnd( end );
		_fragmentFog->SetEnd( end );
		_labelEnd->SetText( String::Format(L"End: {0,0.000}", end) );
	}

	void UpdateWidgets()
	{
		const Bool enabled = _switchEnable->IsOn();
		const UInt technique = _listTechnique->GetSelectedItem();
		const FogType type = (technique == TECHNIQUE_VERTEX) ? _vertexFog->GetType() : _fragmentFog->GetType();
		const Bool linear = (type == FogType::Linear);

		_labelTechnique->Show( enabled );
		_listTechnique->Show( enabled );
		_labelType->Show( enabled );
		_listType->Show( enabled );
		_labelColor->Show( enabled );
		_listColor->Show( enabled );
		_labelDensity->Show( enabled && !linear );
		_sliderDensity->Show( enabled && !linear );
		_labelStart->Show( enabled && linear );
		_sliderStart->Show( enabled && linear );
		_labelEnd->Show( enabled && linear );
		_sliderEnd->Show( enabled && linear );
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		return material;
	}

private:
	enum
	{
		TECHNIQUE_VERTEX = 0,
		TECHNIQUE_FRAGMENT = 1,
	};

	PtrOpaqueMaterial										_materialFloor;
	PtrTriangleMesh											_floor;
	PtrFog													_vertexFog;
	PtrFogAnimationController								_vertexFogCtrl;
	PtrKeyframedColorTrack									_vertexFogColorTrack;
	PtrFogFilter											_fragmentFog;
	PtrFogFilterAnimationController							_fragmentFogCtrl;
	PtrKeyframedColorTrack									_fragmentFogColorTrack;
	PtrViewportAnimationController							_viewportCtrl;
	PtrKeyframedColorTrack									_viewportColorTrack;
	PtrTriangleMesh											_tiny;
	PtrTriangleMesh											_tiny2;
	PtrTriangleMesh											_tiny3;
	PtrTriangleMesh											_tiny4;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrSwitch												_switchEnable;
	PtrLabel												_labelTechnique;
	PtrDropList												_listTechnique;
	PtrLabel												_labelType;
	PtrDropList												_listType;
	PtrLabel												_labelColor;
	PtrDropList												_listColor;
	PtrLabel												_labelDensity;
	PtrSlider												_sliderDensity;
	PtrLabel												_labelStart;
	PtrSlider												_sliderStart;
	PtrLabel												_labelEnd;
	PtrSlider												_sliderEnd;
};

SYNKRO_DEMO_BEGIN
	PurpleHaze demo;
	demo.Run();
SYNKRO_DEMO_END
