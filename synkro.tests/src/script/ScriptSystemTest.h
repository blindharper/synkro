#include <script/IScriptSystemFactory.h>
#include <script/IScriptMachine.h>
#include <script/IScriptObject.h>
#include <script/ScriptSystemEx.h>
#include <io/FileStream.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mem;
using namespace synkro::script;
using namespace synkro;

//------------------------------------------------------------------------------

class IConsoleObject
{
public:
	virtual const char* GetName() const = 0;
	virtual IScriptObject* GetScript() const = 0;
};

class IConsole
{
public:
	virtual Double Echo( const char* message ) = 0;
	virtual IConsoleObject*	Spawn( const char* name ) = 0;
};

class Console_Echo :
	public ScriptMethod
{
public:
	Console_Echo() : ScriptMethod( "echo", "s", "n" ) {}
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		out[0].Set( ((IConsole*)object)->Echo( in[0].GetString() ) );
	}
}s_console_echo;

class Console_Spawn :
	public ScriptMethod
{
public:
	Console_Spawn() : ScriptMethod( "spawn", "s", "o" ) {}
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		out[0].Set( ((IConsole*)object)->Spawn( in[0].GetString() )->GetScript() );
	}
}s_console_spawn;

class ConsoleObject_GetName :
	public ScriptMethod
{
public:
	ConsoleObject_GetName() : ScriptMethod( "getName", "", "s" ) {}
	void Call( void* object, const ScriptParam* in, ScriptParam* out )
	{
		out[0].Set( ((IConsoleObject*)object)->GetName() );
	}
}s_console_object_get_name;

class ConsoleObject :
	public IConsoleObject
{
public:
	ConsoleObject( IScriptMachine* vm, const char* name ) :
		_name( name )
	{
		ScriptMethod* methods[] =
		{
			&s_console_object_get_name
		};
		_obj = vm->CreateObject( this, nullptr, (const ScriptMethod**)&methods, sizeof(methods)/sizeof(methods[0]) );
	}

	const char* GetName() const
	{
		return _name;
	}

	IScriptObject* GetScript() const
	{
		return _obj;
	}

private:
	P(IScriptObject) _obj;
	const char* _name;
};

class Console :
	public IConsole
{
public:
	Console( IScriptMachine* vm, IStream* script ) :
		_vm( vm )
	{
		ScriptMethod* methods[] =
		{
			&s_console_echo,
			&s_console_spawn,
		};
		_obj = _vm->CreateObject( this, script, (const ScriptMethod**)&methods, sizeof(methods)/sizeof(methods[0]) );
	}

	Double Echo( const char* message )
	{
		printf( "Console::Echo( \"%s\" )\n", message );
		return (Double)strlen( message );
	}

	IConsoleObject*	Spawn( const char* name )
	{
		return new ConsoleObject( _vm, name );
	}

private:
	IScriptMachine* _vm;
	P(IScriptObject) _obj;
};

class ScriptSystemTest
{
public:
	ScriptSystemTest( const String& name, const String& script, IScriptSystemFactory* factScriptSys ) :
		_name( name ),
		_script( script ),
		_factScriptSys( factScriptSys )
	{
	}

	void Run()
	{
		P(ScriptSystemEx) scriptSys = new ScriptSystemEx( nullptr );
		scriptSys->Initialize( _factScriptSys );
		P(io::IStream) is = new FileStream( _script );
		P(IScriptMachine) vm = scriptSys->CreateMachine( L"vm" );
		Console console( vm, is );
		vm->Execute( "printZ( 'blah-blah!' );" );
		console.Echo( "Testing finished" );
	}

private:
	String					_name;
	String					_script;
	IScriptSystemFactory*	_factScriptSys;
};
