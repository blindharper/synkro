#include "config.h"
#include "Test.h"
#include <io/Path.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestPath :
	public Test
{
public:
	TestPath() : Test( "TestPath", 400 ) {}

	void Run()
	{
		// Creation.
		Path p0( "..\\tmp" );
		Path p1( "d:\\temp\\" );
		Path p2( "c|:\\tmp>" );
		Path p3( "develop\\tests\\file.txt" );

		// Properties.
		Assert( p0.GetPath() == "..\\tmp" );
		Assert( p1.GetPath() == "d:\\temp\\" );
		Assert( p2.GetPath() == "c|:\\tmp>" );

		Assert( !Path::IsAbsolute( p0.GetPath() ) );
		Assert( Path::IsAbsolute( p1.GetPath() ) );

		// Validation.
		Assert( Path::IsValid( p1.GetPath() ) );
		Assert( !Path::IsValid( p2.GetPath() ) );

		// Combination.
		Path root( "d:\\" );
		Path temp( "\\temp" );
		Path bak( "bak\\" );
		Path file( "file.txt" );
		Path base( "C:\\develop\\synkro\\synkro.demos\\bin\\win64\\" );
		Path dir( "..\\..\\programs\\DirectX11" );

		Assert( Path::Combine(root.GetPath(), temp.GetPath()) == "d:\\temp" );
		Assert( Path::Combine(bak.GetPath(), temp.GetPath()) == "bak\\temp" );
		Assert( Path::Combine(temp.GetPath(), file.GetPath()) == "\\temp\\file.txt" );
		Assert( Path::Combine(base.GetPath(), dir.GetPath()) == "C:\\develop\\synkro\\synkro.demos\\programs\\DirectX11" );

		Assert( p3.GetBase() == "develop" );
		Assert( p3.RemoveBase() == "tests\\file.txt" );

		// Parent paths.
		Path parent( p1.GetParent() );
		Assert( parent.GetPath() == "d:" );
	}

} _tst;
