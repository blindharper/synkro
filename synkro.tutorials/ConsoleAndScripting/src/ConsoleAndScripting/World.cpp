#include "World.h"
#include "Universe.h"
#include "Scripting.h"
#include <script/ScriptException.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::cons;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::scene;
using namespace synkro::script;

//------------------------------------------------------------------------------


SCRIPT_METHOD_BEGIN( World_CreateTiny, "createTiny", "snn", "o" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		World* world = (World*)object;
		Tiny* tiny = world->CreateTiny( in[0].GetString(), CastFloat(in[1].GetNumber()), CastFloat(in[2].GetNumber()) );
		out[0].Set( tiny->GetObject() );
	}
SCRIPT_METHOD_END( s_world_createTiny )

SCRIPT_METHOD_BEGIN( World_GetTiny, "getTiny", "s", "o" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		World* world = (World*)object;
		Tiny* tiny = world->GetTiny( in[0].GetString() );
		out[0].Set( (tiny != nullptr) ? tiny->GetObject() : nullptr );
	}
SCRIPT_METHOD_END( s_world_getTiny )

SCRIPT_METHOD_BEGIN( World_Load, "load", "s", "" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		World* world = (World*)object;
		world->Load( in[0].GetString() );
	}
SCRIPT_METHOD_END( s_world_load )

World::World( Universe* universe, ISynkro* synkro, const String& name, const Color& color ) :
	_universe( universe ),
	_synkro( synkro ),
	_name( name ),
	_color( color ),
	_tinyCount( 0 )
{
	ScriptMethod* methods[] =
	{
		&s_world_createTiny,
		&s_world_getTiny,
		&s_world_load,
	};
	_machine = _synkro->GetScriptSystem()->CreateMachine( name );
	_object = _machine->CreateObject( this, nullptr, (const ScriptMethod**)&methods, sizeof(methods)/sizeof(methods[0]));
	_machine->SetContext( _object );
	
	// Create scene.
	DisplayMode displayMode;
	_universe->GetDisplayMode( displayMode );
	_scene = _synkro->GetSceneManager()->CreateScene( name, DebugMode::None, false );

	// Create materials.
	PtrImage imageFloor = GetImage( L"floor.jpg" );
	_materialFloor = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_materialFloor->GetDiffuseMap()->SetImage( imageFloor );
	_materialFloor->SetTilingHorizontal( 4 );
	_materialFloor->SetTilingVertical( 4 );

	// Create floor.
	constexpr Float FLOOR_SIZE = 250.0f;
	Matrix4x4 trans;
	trans.SetTranslation( Vector3(FLOOR_SIZE/2.0f, 0.0f, FLOOR_SIZE/2.0f) );
	_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _materialFloor, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(250, 0), trans );

	// Create camera.
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_camera->SetAspect( displayMode.AspectFactor() );
	_camera->SetPosition( Vector3(125.0f, 150.0f, -350.0f) );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );
	_camera->LookAt( Vector3(125.0f, 0.0f, 125.0f) );
}

World::World() :
	_universe( nullptr ),
	_synkro( nullptr )
{
}

World::~World()
{
	for ( UInt i = 0; i < _tinyCount; ++i )
	{
		delete _tinys[i];
	}
}

void World::Load( const char* script )
{
	PtrStream stream = GetStream( script );
	_machine->Execute( stream );
}

Tiny* World::CreateTiny( const char* name, Float x, Float y )
{
	if ( _tinyCount >= MAX_TINY_COUNT )
		throw ScriptException( L"Character capacity reached" );

	if ( GetTiny(name) != nullptr )
		throw ScriptException( String::Format(L"Tiny with name {0,q} already exists", name) );

	Tiny* tiny = new Tiny( _synkro, _machine, _scene, name, x, y );
	_tinys[_tinyCount++] = tiny;
	return tiny;
}

Tiny* World::GetTiny( const char* name ) const
{
	for ( UInt i = 0; i < _tinyCount; ++i )
	{
		Tiny* tiny = _tinys[i];
		if ( tiny->GetName().EqualsTo(name, true) )
			return tiny;
	}
	return nullptr;
}

String World::GetName() const
{
	return _name;
}

void World::GetColor( Color& color ) const
{
	color = _color;
}

ICamera* World::GetCamera() const
{
	return _camera;
}

IScriptMachine* World::GetMachine() const
{
	return _machine;
}

IScriptObject* World::GetObject() const
{
	return _object;
}

IImage* World::GetImage( const String& name )
{
	PixelFormat fmt = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->GetClientPixelFormat();
	return _synkro->GetImageManager()->LoadImageAsync( GetStream(name), fmt, nullptr );
}

IStream* World::GetStream( const String& name )
{
	PtrStream stream = _synkro->GetStreamSystem()->GetStream( name );
	if ( stream == nullptr )
		throw FileNotFoundException( name );
	return stream;
}
