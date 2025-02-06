#include "../Demo.h"


class Picking :
	public Demo
{
public:
	Picking() :
		Demo( L"Picking" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetAmbientColor( Color::DimGray );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, 0.0f, -1.0f) );

		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_material = CreateMaterial( diffuseMap, Color::OrangeAerospace );
		_material2 = CreateMaterial( diffuseMap, Color::LamborghiniYellow );
		_material3 = CreateMaterial( diffuseMap, Color::BrightNavyBlue );
		_material4 = CreateMaterial( diffuseMap, Color::BritishRacingGreen );

		// Create meshes.
		_mesh = CreateEllipsoid( nullptr, _material, 40.0f, 20.0f, 30.0f, 40, 40, Matrix4x4::Identity, Vector3(-80.0f, 0.0f, 0.0f) );
		_mesh2 = CreateCylinder( nullptr, _material2, 10.0f, 30.0f, 40, 40, Matrix4x4::Identity, Vector3(0.0f, 30.0f, 0.0f) );
		_mesh3 = CreatePyramid( nullptr, _material3, 10.0f, 30.0f, 15.0f, Matrix4x4::Identity, Vector3(50.0f, -70.0f, 0.0f) );
		_mesh4 = CreateTorus( nullptr, _material4, 10.0f, 30.0f, 30, 30, Matrix4x4::Identity, Vector3(60.0f, -10.0f, 0.0f) );

		// Setup animations.
		PtrNodeAnimationController ctrlMesh = _mesh->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackMesh = ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackMesh->SetType( WaveType::SawtoothDown );
		trackMesh->SetAmplitude( Math::TwoPi );
		trackMesh->SetFrequency( 1.0f/Math::Pi );
		ctrlMesh->SetMode( AnimationMode::Loop );
		ctrlMesh->Start( true );

		PtrNodeAnimationController ctrlMesh2 = _mesh2->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackMesh2 = ctrlMesh2->CreateOrientationPitchTrack( AnimationTrack::FloatWave )->AsWave();
		trackMesh2->SetType( WaveType::SawtoothUp );
		trackMesh2->SetAmplitude( Math::TwoPi );
		trackMesh2->SetFrequency( 1.0f/Math::Pi );
		ctrlMesh2->SetMode( AnimationMode::Loop );
		ctrlMesh2->Start( true );

		PtrNodeAnimationController ctrlMesh3 = _mesh3->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackMesh3 = ctrlMesh3->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackMesh3->SetType( WaveType::SawtoothUp );
		trackMesh3->SetAmplitude( Math::TwoPi );
		trackMesh3->SetFrequency( 1.0f/Math::Pi );
		ctrlMesh3->SetMode( AnimationMode::Loop );
		ctrlMesh3->Start( true );

		PtrNodeAnimationController ctrlMesh4 = _mesh4->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackMesh4 = ctrlMesh4->CreateOrientationPitchTrack( AnimationTrack::FloatWave )->AsWave();
		trackMesh4->SetType( WaveType::SawtoothDown );
		trackMesh4->SetAmplitude( Math::TwoPi );
		trackMesh4->SetFrequency( 1.0f/Math::Pi );
		ctrlMesh4->SetMode( AnimationMode::Loop );
		ctrlMesh4->Start( true );

		// Subscribe for mouse events.
		_synkro->GetInputSystem()->GetMouse( 0 )->ListenClick( this, MouseButton::Left );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 0.0f, -300.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	// MouseListener methods.
	Bool ListenMouseInput() const
	{
		return true;
	}

	Bool OnMouseClick( UInt device, const MouseButton& buttons )
	{
		if ( Demo::OnMouseClick(device, buttons) )
			return true;

		Point loc;
		_synkro->GetUi()->GetCursor()->GetLocation( loc );
		IViewport* viewport = _synkro->GetViewportManager()->GetViewport( _window, loc );
		if ( viewport != nullptr )
		{
			Float distance = 0.0f;
			if ( _pickedMesh != nullptr )
			{
				_pickedMesh->GetMaterial()->AsSimple()->SetEmissiveColor( Color::Black );
			}
			_pickedMesh = viewport->PickMesh( loc, &distance );
			if ( _pickedMesh != nullptr )
			{	
				viewport->SetLabelText( String::Format(L"{0}. X: {1} Y: {2}. Distance: {3,0.000}", _pickedMesh->GetName(), loc.X, loc.Y, distance) );
				_pickedMesh->GetMaterial()->AsSimple()->SetEmissiveColor( Color::DimGray );
			}			
			else
			{
				viewport->SetLabelText( String::Format(L"NOTHING PICKED. X: {0} Y: {1}", loc.X, loc.Y) );
			}
			viewport->ShowLabel( true );
		}

		return true;
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

private:
	PtrDirectLight											_light;

	PtrTriangleMesh											_pickedMesh;

	PtrOpaqueMaterial										_material;
	PtrTriangleMesh											_mesh;

	PtrOpaqueMaterial										_material2;
	PtrTriangleMesh											_mesh2;

	PtrOpaqueMaterial										_material3;
	PtrTriangleMesh											_mesh3;

	PtrOpaqueMaterial										_material4;
	PtrTriangleMesh											_mesh4;
};

SYNKRO_DEMO_BEGIN
	Picking demo;
	demo.Run();
SYNKRO_DEMO_END
