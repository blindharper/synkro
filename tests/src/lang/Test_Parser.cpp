#include "config.h"
#include "Test.h"
#include <lang/Parser.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestParser :
	public Test
{
public:
	TestParser() : Test( "TestParser", 104 ) {}

	void Run()
	{
		Int width; Int height; Int depth; String fullscreen;
		Bool ok = Parser::Parse( L"1024x768x32 Fullscreen", L"{0}x{1}x{2} {3}", width, height, depth, fullscreen );
		Assert( ok == true );
		Assert( width == 1024 );
		Assert( height == 768 );
		Assert( depth == 32 );
		Assert( fullscreen == L"Fullscreen" );

		Int samples; Int bits; Int channels;
		ok = Parser::Parse( L"44kHz16bit2Ch", L"{0}kHz{1}bit{2}Ch", samples, bits, channels );
		Assert( ok == true );
		Assert( samples == 44 );
		Assert( bits == 16 );
		Assert( channels == 2 );

		String name; Int surname;
		Parser p1( L"{0} x {1}" );
		p1.Map( name, surname );
		ok = p1.ParseText( "Eugene x 78" );
		Assert( ok == true );
		Assert( name == L"Eugene" );
		Assert( surname == 78 );

		ok = p1.ParseText( "John x 67" );
		Assert( ok == true );
		Assert( name == L"John" );
		Assert( surname == 67 );

		ok = p1.ParseText( "Alex 33" );
		Assert( ok == false );
	}

} _tst;
