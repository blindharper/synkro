#include "../Demo.h"


class LevelsOfDetail :
	public Demo
{
public:
	LevelsOfDetail() :
		Demo( L"Levels Of Detail" )
	{
	}

	void InitScene() override
	{
		// TODO:
		/*// Create mesh.
		PtrStream streamModel = GetStream( L"hammerlod3.obj" );
		_mesh = _scene->LoadMesh( streamModel );
		_mesh->SetPosition( Vector3(0.0f, 200.0f, 700.0f) );
		_mesh->SetOrientationYaw( Math::HalfPi );*/

		// Create material.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_material = CreateMaterial( diffuseMap, Color::Yellow );

		// Create mesh set.
		_meshSet = _scene->CreateTriangleMeshSet( nullptr, L"Mesh", _material );
		_synkro->GetSceneManager()->BuildMesh( _meshSet, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(40, 40), Matrix4x4::Identity );
		_synkro->GetSceneManager()->BuildMesh( _meshSet, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(30, 30), Matrix4x4::Identity );
		_synkro->GetSceneManager()->BuildMesh( _meshSet, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(20, 20), Matrix4x4::Identity );
		_synkro->GetSceneManager()->BuildMesh( _meshSet, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(10, 10), Matrix4x4::Identity );
		_meshSet->SetPosition( Vector3(0.0f, 0.0f, 0.0f) );
		_meshSet->SetMinimumLevelSize( 0, 500.0f );
		_meshSet->SetMinimumLevelSize( 1, 400.0f );
		_meshSet->SetMinimumLevelSize( 2, 300.0f );
		_meshSet->SetMinimumLevelSize( 3, 200.0f );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 0.0f, 100.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		_labelDistance = CreateLabel( Point(_widgetLeft, 120), L"Distance:" );
		_sliderDistance = CreateSlider( none, Point(_widgetLeft, 140), 100, 1600, 600 );
		_switchWireframe = CreateSwitch( Point(_widgetLeft, 170), 160, L"[W]ireframe", HotKey(Key::W, true), false );
		SetDistance( 600.0f );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _sliderDistance )
		{
			SetDistance( CastFloat(_sliderDistance->GetPosition()) );
			return true;
		}
		else if ( sender == _switchWireframe )
		{
			_viewport->SetWireframe( _switchWireframe->IsOn() );
			return true;
		}

		return false;
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse, const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud, true );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetDiffuseColor( color );
		material->SetTiling( 8 );
		return material;
	}

	void SetDistance( Float distance )
	{
		_camera->SetPosition( Vector3(0.0f, 0.0f, distance) );
		_labelDistance->SetText( String::Format(L"Distance: {0,0.000}", distance) );
	}

private:
	PtrOpaqueMaterial										_material;
	PtrTriangleMeshSet										_meshSet;

	PtrLabel												_labelDistance;
	PtrSlider												_sliderDistance;
	PtrSwitch												_switchWireframe;
};

SYNKRO_DEMO_BEGIN
	LevelsOfDetail demo;
	demo.Run();
SYNKRO_DEMO_END
