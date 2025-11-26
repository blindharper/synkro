#include "../Demo.h"


class Instancing :
	public Demo
{
public:
	Instancing() :
		Demo( L"Instancing" ),
		_rotationMode( CUBE ),
		_colorMode( RANDOM )
	{
	}

	void Configure( IConfiguration* config ) override
	{
		config->Set( Param::GraphicsVsync, false );
	}

	void InitScene() override
	{
		_scene2 = _synkro->GetSceneManager()->CreateScene( L"Instanced", DebugMode::None, false );
		CreateCubeArray();
		CreateCubeInstanced();
	}

	void InitView() override
	{
		_camera2 = _scene2->CreateCamera( nullptr, String::Empty );
		_camera2->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
		_camera2->SetAspect( _displayModeWindowed.AspectFactor() );
		_camera2->SetFront( 0.1f );
		_camera2->SetBack( 10000.0f );

		const Vector3 cameraPos( -24.0f, 36.0f, -36.0f );
		const Vector3 cameraTarget = Vector3::Origin;

		_camera->SetPosition( cameraPos );
		_camera->LookAt( cameraTarget );
		
		_camera2->SetPosition( cameraPos );
		_camera2->LookAt( cameraTarget );
	}

	void InitUi() override
	{
		const UInt count = CAPACITY/2;
		_labelCount = CreateLabel( Point(_widgetLeft, 100), String::Empty );
		CreateSlider( ID_SLIDER_COUNT, Point(_widgetLeft, 120), 1, CAPACITY, count );
		SetCount( count );

		_btnRotationMode = CreateButton( Point(_widgetLeft, 150), L"Rotate instances" );
		_btnColorize = CreateButton( Point(_widgetLeft, 180), L"Gradient color" );
		_switchTexture = CreateSwitch( ID_SWITCH_TEXTURE, Point(_widgetLeft, 210), 150, L"Show texture", true );
		CreateOption( ID_OPTION_ARRAY, Point(_widgetLeft, 240), L"Array", (Pointer)_camera.AsPtr(), true );
		CreateOption( ID_OPTION_INSTANCING, Point(_widgetLeft, 270), L"Instancing", (Pointer)_camera2.AsPtr(), false );
	}

	void OnDisplayModeChanged( const DisplayMode& displayMode ) override
	{
		_camera2->SetAspect( displayMode.AspectFactor() );
	}

	// ArcballListener methods.
	Bool ListenArcballInput() const override
	{
		return true;
	}

	Bool OnArcballOriented( const Quaternion& orientation ) override
	{
		Demo::OnArcballOriented( orientation );

		switch ( _rotationMode )
		{
			case CUBE:
				_cubesArray->Get(0)->GetParent()->SetOrientation( orientation );
				_cubesInstanced->Get(0)->GetParent()->SetOrientation( orientation );
				break;

			case INSTANCES:
				for ( UInt i = 0; i < CAPACITY; ++i )
				{
					_cubesArray->Get(i)->SetOrientation( orientation );
					_cubesInstanced->Get(i)->SetOrientation( orientation );
				}
				break;
		}
		return true;
	}

	Bool OnArcballZoom( Int delta ) override
	{
		Demo::OnArcballZoom( delta );

		_camera2->SetHorizontalFieldOfView( Math::ToRadians(_orgFov -= 0.005f * CastFloat(delta)) );
		return true;
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( sender == _btnRotationMode )
		{
			_rotationMode = (_rotationMode == CUBE) ? INSTANCES : CUBE;
			_btnRotationMode->SetText( (_rotationMode == CUBE) ? L"Rotate instances" : L"Rotate cube" );
			return true;
		}
		else if ( sender == _btnColorize )
		{
			_colorMode = (_colorMode == RANDOM) ? GRADIENT : RANDOM;
			_btnColorize->SetText( (_colorMode==RANDOM) ? L"Gradient color" : L"Random color" );
			Colorize();
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		switch ( sender->ID() )
		{
			case ID_SLIDER_COUNT:
				SetCount( sender->AsSlider()->GetPosition() );
				return true;

			case ID_SWITCH_TEXTURE:
				ShowTexture( sender->AsSwitch()->IsOn() );
				return true;

			case ID_OPTION_ARRAY:
			case ID_OPTION_INSTANCING:
				_viewport->SetCamera( (ICamera*)sender->AsOption()->GetData() );
				return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Unknown );
		material->GetDiffuseMap()->SetImage( diffuse );
		return material;
	}

	void CreateCubeArray()
	{
		_cubesArray = _synkro->CreateTriangleMeshList();
		_cubesArray->SetSize( CAPACITY );

		constexpr Float CUBE_SIDE = 16.0f;
		constexpr Float DELTA = 0.5f;
		constexpr Float side = (CUBE_SIDE - DELTA*(CastFloat(SIDE_LENGTH)-1.0f))/CastFloat(SIDE_LENGTH);
		_center = _scene->CreateDummy( nullptr, L"Center" );
		IImage* diffuseMap = GetImage( L"crate.bmp" );
		constexpr Float start = -(CastFloat(SIDE_LENGTH)-1.0f)*(side+DELTA)*0.5f;
		Float y = start; Matrix4x4 trans;
		for ( UInt i = 0; i < SIDE_LENGTH; ++i )
		{
			Float x = start;
			for ( UInt j = 0; j < SIDE_LENGTH; ++j )
			{
				Float z = start;
				for ( UInt k = 0; k < SIDE_LENGTH; ++k )
				{
					trans.SetTranslation( Vector3(x, y, z) );
					ITriangleMesh* mesh = _scene->CreateTriangleMesh( _center, String::Empty, CreateMaterial(diffuseMap), nullptr );
					_synkro->GetSceneManager()->BuildMesh( mesh, MeshBuilder::Box, Vector4(side, side, side, 0.0f), Size(), trans );
					_cubesArray->Set( SIDE_LENGTH*(SIDE_LENGTH*i+j)+k, mesh );
					z += side+DELTA;
				}
				x += side+DELTA;
			}
			y += side+DELTA;
		}
	}

	void CreateCubeInstanced()
	{
		_cubesInstanced = _synkro->CreateTriangleMeshList();
		_cubesInstanced->SetSize( CAPACITY );

		constexpr Float CUBE_SIDE = 16.0f;
		constexpr Float DELTA = 0.5f;
		constexpr Float side = (CUBE_SIDE - DELTA*(CastFloat(SIDE_LENGTH)-1.0f))/CastFloat(SIDE_LENGTH);
		_center2 = _scene2->CreateDummy( nullptr, L"Center" );
		IImage* diffuseMap = GetImage( L"crate.bmp" );
		_cube = _scene2->CreateTriangleMeshBatch( CreateMaterial(diffuseMap), nullptr, CAPACITY );
		_synkro->GetSceneManager()->BuildMesh( _cube, MeshBuilder::Box, Vector4(side, side, side, 0.0f), Size(), Matrix4x4::Identity );
		constexpr Float start = -(CastFloat(SIDE_LENGTH)-1.0f)*(side+DELTA)*0.5f;
		Float y = start; Matrix4x4 trans;
		for ( UInt i = 0; i < SIDE_LENGTH; ++i )
		{
			Float x = start;
			for ( UInt j = 0; j < SIDE_LENGTH; ++j )
			{
				Float z = start;
				for ( UInt k = 0; k < SIDE_LENGTH; ++k )
				{
					trans.SetTranslation( Vector3(x, y, z) );
					_cubesInstanced->Set(SIDE_LENGTH*(SIDE_LENGTH*i+j)+k, _cube->CreateInstance(_center, trans, Color::White) );
					z += side+DELTA;
				}
				x += side+DELTA;
			}
			y += side+DELTA;
		}
	}

	void SetCount( UInt count )
	{
		_cube->SetRange( Range(0, count) );
		for ( UInt i = 0; i < CAPACITY; ++i )
		{
			_cubesArray->Get(i)->Show( i < count );
			_cubesInstanced->Get(i)->Show( i < count );
		}
		_labelCount->SetText( String::Format(L"# cubes: {0}", count) );
	}

	void ShowTexture( Bool show )
	{
		IImage* image = GetImage( show ? L"crate.bmp" : L"blank.bmp" );
		_cube->GetMaterial()->AsSimple()->GetDiffuseMap()->SetImage( image );
		for ( UInt i = 0; i < CAPACITY; ++i )
		{
			_cubesArray->Get(i)->GetMaterial()->AsSimple()->GetDiffuseMap()->SetImage( image );
		}
	}

	void Colorize()
	{
		Color color;
		for ( UInt i = 0; i < SIDE_LENGTH; ++i )
		{
			for ( UInt j = 0; j < SIDE_LENGTH; ++j )
			{
				for ( UInt k = 0; k < SIDE_LENGTH; ++k )
				{
					switch ( _colorMode )
					{
						case RANDOM:
							color = Color::Random();
							break;

						case GRADIENT:
							color.R = CastFloat(j)/CastFloat(SIDE_LENGTH-1);
							color.G = CastFloat(i)/CastFloat(SIDE_LENGTH-1);
							color.B = CastFloat(k)/CastFloat(SIDE_LENGTH-1);
							break;
					}
					const UInt index = SIDE_LENGTH*(SIDE_LENGTH*k+j)+i;
					_cubesArray->Get(index)->GetMaterial()->AsSimple()->SetDiffuseColor( color );
					_cubesInstanced->Get(index)->GetMaterial()->AsSimple()->SetDiffuseColor( color );
				}
			}
		}
	}

private:
	enum RotationMode
	{
		CUBE,
		INSTANCES,
	};

	enum ColorMode
	{
		RANDOM,
		GRADIENT,
	};

	enum
	{
		SIDE_LENGTH = 7,
		CAPACITY = SIDE_LENGTH*SIDE_LENGTH*SIDE_LENGTH,
	};

	enum
	{
		ID_SLIDER_COUNT			= 100,
		ID_SWITCH_TEXTURE		= 101,
		ID_OPTION_ARRAY			= 102,
		ID_OPTION_INSTANCING	= 103,
	};

	PtrSceneEx												_scene2;
	PtrCamera												_camera2;
	PtrNode													_center;
	PtrNode													_center2;

	PtrTriangleMeshBatch									_cube;
	PtrTriangleMeshList										_cubesArray;
	PtrTriangleMeshList										_cubesInstanced;

	PtrLabel												_labelCount;
	PtrButton												_btnRotationMode;
	PtrButton												_btnColorize;
	PtrSwitch												_switchTexture;

	RotationMode											_rotationMode;
	ColorMode												_colorMode;
};

SYNKRO_DEMO_BEGIN
	Instancing demo;
	demo.Run();
SYNKRO_DEMO_END
