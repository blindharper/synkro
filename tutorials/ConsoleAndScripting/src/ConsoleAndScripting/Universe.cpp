#include "Universe.h"
#include "Scripting.h"
#include <script/ScriptException.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::cons;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::scene;
using namespace synkro::script;
using namespace synkro::view;

//------------------------------------------------------------------------------


SCRIPT_METHOD_BEGIN( Universe_CreateWorld, "createWorld", "s", "o" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		Universe* universe = (Universe*)object;
		World* world = universe->CreateWorld( in[0].GetString() );
		out[0].Set( world->GetObject() );
	}
SCRIPT_METHOD_END( s_universe_createWorld )

SCRIPT_METHOD_BEGIN( Universe_ActivateWorld, "activateWorld", "s", "" )
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		Universe* universe = (Universe*)object;
		universe->ActivateWorld( in[0].GetString() );
	}
SCRIPT_METHOD_END( s_universe_activateWorld )

Universe::Universe( ISynkro* synkro, IScriptMachine* machine, const DisplayMode& displayMode ) :
	_synkro( synkro ),
	_machine( machine ),
	_displayMode( displayMode ),
	_worldCount( 0 )
{
	ScriptMethod* methods[] =
	{
		&s_universe_createWorld,
		&s_universe_activateWorld,
	};
	_object = _machine->CreateObject( this, nullptr, (const ScriptMethod**)&methods, sizeof(methods)/sizeof(methods[0]) );
	_synkro->GetConsole()->SetScriptMachine( _machine );
	_machine->SetContext( _object );
}

Universe::~Universe()
{
	for ( UInt i = 0; i < _worldCount; ++i )
	{
		delete _worlds[i];
	}
}

World* Universe::CreateWorld( const String& name )
{
	if ( _worldCount >= MAX_WORLD_COUNT )
		throw ScriptException( L"World capacity reached" );

	if ( GetWorld(name) != nullptr )
		throw ScriptException( String::Format(L"World with name {0,q} already exists", name) );

	World* world = new World( this, _synkro, name, Color::Random() );
	_worlds[_worldCount++] = world;
	Color color; world->GetColor( color );
	_synkro->GetViewportManager()->GetViewport( CastUInt(0) )->SetColor( color );
	ActivateWorld( name );
	return world;
}

void Universe::ActivateWorld( const String& name )
{
	World* world = GetWorld( name );
	if ( world != nullptr )
	{
		IViewport* viewport = _synkro->GetViewportManager()->GetViewport( CastUInt(0) );
		Color color; world->GetColor( color );
		viewport->SetColor( color );
		viewport->SetCamera( world->GetCamera() );
		_synkro->GetConsole()->SetScriptMachine( world->GetMachine() );
		_synkro->GetConsole()->EnableEcho( true );
		_synkro->GetConsole()->Echo( String::Format(L"World {0,q} activated", world->GetName()) );
	}
}

void Universe::GetDisplayMode( DisplayMode& displayMode ) const
{
	displayMode = _displayMode;
}

IScriptObject* Universe::GetObject() const
{
	return _object;
}

World* Universe::GetWorld( const lang::String& name )
{
	for ( UInt i = 0; i < _worldCount; ++i )
	{
		if ( _worlds[i]->GetName().EqualsTo( name, true ) )
			return _worlds[i];
	}
	return nullptr;
}
