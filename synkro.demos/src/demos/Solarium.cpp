#include "../Demo.h"


// Planet textures: https://planetpixelemporium.com
class Solarium :
	public Demo
{
public:
	Solarium() :
		Demo( L"Solarium" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create space.
		PtrImage imageSky = GetImage( L"space.jpg" );
		_scene->SetSky( imageSky, 5000.0f );

		// Create sunlight.
		_sunlight = _scene->CreateOmniLight( nullptr, L"Sunlight" );
		_sunlight->SetPosition( Vector3::Origin );
		_sunlight->SetAmbientColor( Color::DimGray );
		_sunlight->SetDiffuseColor( Color::Silver );

		// Create the Sun.
		constexpr Float SUN_RADIUS = 200.0f;
		PtrImage imageSun = GetImage( L"sunmap.jpg" );
		_materialSun = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		_materialSun->GetDiffuseMap()->SetImage( imageSun );
		_materialSun->SetAmbientColor( Color::Yellow );
		_materialSun->SetDiffuseColor( Color::Yellow );
		_materialSun->SetEmissiveColor( Color::Yellow );
		_sun = CreateSphere( nullptr, _materialSun, SUN_RADIUS, 40, 40, Matrix4x4::Identity, Vector3::Origin );

		// Create planets.
		_planets = _synkro->CreateTriangleMeshList();
		_centerMercury = CreateCenter( 0.42 );
		CreatePlanet( _centerMercury, L"Mercury", L"mercurymap.jpg", 20.0f, Vector3(0.0f, 0.0f, 400.0f) );

		_centerVenus = CreateCenter( 0.37 );
		CreatePlanet( _centerVenus, L"Venus", L"venusmap.jpg", 35.0f, Vector3(0.0f, 0.0f, 500.0f) );

		_centerEarth = CreateCenter( 0.34 );
		CreatePlanet( _centerEarth, L"Earth", L"earthmap1k.jpg", 36.0f, Vector3(0.0f, 0.0f, 600.0f) );

		_centerMars = CreateCenter( 0.33 );
		CreatePlanet( _centerMars, L"Mars", L"marsmap1k.jpg", 30.0f, Vector3(0.0f, 0.0f, 700.0f) );

		_centerJupiter = CreateCenter( 0.3 );
		CreatePlanet( _centerJupiter, L"Jupiter", L"jupitermap.jpg", 100.0f, Vector3(0.0f, 0.0f, 900.0f) );

		_centerSaturn = CreateCenter( 0.31 );
		CreatePlanet( _centerSaturn, L"Saturn", L"saturnmap.jpg", 85.0f, Vector3(0.0f, 0.0f, 1200.0f) );

		_centerUranus = CreateCenter( 0.32 );
		CreatePlanet( _centerUranus, L"Uranus", L"uranusmap.jpg", 45.0f, Vector3(0.0f, 0.0f, 1400.0f) );

		_centerNeptune = CreateCenter( 0.29 );
		CreatePlanet( _centerNeptune, L"Neptune", L"neptunemap.jpg", 45.0f, Vector3(0.0f, 0.0f, 1600.0f) );
	}

	void InitView() override
	{
		// Setup viewports and cameras.
		_camera->SetPosition( Vector3(0.0f, 0.0f, 0.0f) );
		_camera->LookAt( Vector3(0.0f, 0.0f, 200.0f) );

		// Setup additional viewport
		_camera2 = _scene->CreateCamera( nullptr, String::Empty );
		_camera2->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
		_camera2->SetAspect( _displayModeWindowed.AspectFactor() );
		_camera2->SetFront( 0.1f );
		_camera2->SetBack( 10000.0f );
		_camera2->SetPosition( Vector3(0.0f, 5000.0f, -10.0f) );
		_camera2->LookAt( Vector3::Origin );

		IWindow* window = _synkro->GetWindowSystem()->GetFrameWindow( 0 );
		_viewport2 = _synkro->GetViewportManager()->CreateViewport( _window, Rect(Point(window->GetWidth()-420, window->GetHeight()-420), Size(400, 400)), _camera2, Color::LightGray );
		_viewport2->SetBorderColor( Color::Yellow );
		_viewport2->ShowBorder( true );
		_viewport2->SetOpacity( 1.0f );
	}

	void OnDisplayModeChanged( const DisplayMode& displayMode ) override
	{
		_viewport2->SetLocation( Point(displayMode.Width-420, displayMode.Height-420) );
	}

	void OnSynkroUpdate( Double delta ) override
	{
		Demo::OnSynkroUpdate( delta );

		// Hightlight planets only if they are in the view.
		for ( UInt i = 0; i < _planets->GetSize(); ++i )
		{
			PtrTriangleMesh planet = _planets->Get( i );
			Vector3 center; planet->GetCenter( center );
			Matrix4x4 trans; planet->GetWorldTransform( trans );
			const Float radius = planet->GetBoundSphere();
			Vector3 position = trans.Translation();
			Bool ok = _camera->IsInView( position+center, radius );
			planet->GetMaterial()->AsSimple()->SetEmissiveColor( ok ? Color::White : Color::Black );
		}
	}

	INode* CreateCenter( Double speed )
	{
		INode* center = _scene->CreateDummy( nullptr, String::Empty );
		INodeAnimationController* centerCtrl = center->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = centerCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothUp );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0f/Math::Pi );
		centerCtrl->SetMode( AnimationMode::Loop );
		centerCtrl->SetSpeed( speed );
		centerCtrl->Start( true );
		return center;
	}

	ITriangleMesh* CreatePlanet( INode* parent, const String& name, const String& map, Float radius, const Vector3& position )
	{
		PtrImage image = GetImage( map );
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetAmbientColor( Color::DimGray );
		material->SetDiffuseColor( Color::White );
		material->SetEmissiveColor( Color::White );
		material->GetDiffuseMap()->SetImage( image );

		ITriangleMesh* planet = _scene->CreateTriangleMesh( parent, name, material, nullptr );
		_synkro->GetSceneManager()->BuildMesh( planet, MeshBuilder::Ellipsoid, Vector4(radius, radius, radius, 0.0f), Size(40, 40), Matrix4x4::Identity );
		planet->SetPosition( position );
		_planets->Add( planet );
		return planet;
	}

private:
	PtrOmniLight											_sunlight;
	PtrOpaqueMaterial										_materialSun;
	PtrTriangleMesh											_sun;

	PtrCamera												_camera2;
	PtrViewport												_viewport2;

	PtrNode													_centerMercury;
	PtrNode													_centerVenus;
	PtrNode													_centerEarth;
	PtrNode													_centerMars;
	PtrNode													_centerJupiter;
	PtrNode													_centerSaturn;
	PtrNode													_centerUranus;
	PtrNode													_centerNeptune;
	PtrTriangleMeshList										_planets;
};

SYNKRO_DEMO_BEGIN
	Solarium demo;
	demo.Run();
SYNKRO_DEMO_END
