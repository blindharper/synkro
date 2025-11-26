#include "config.h"
#include "Test.h"
#include <lang/Mask.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestMask :
	public Test
{
public:
	TestMask() : Test( "TestMask", 109 ) {}

	void Run()
	{
		Mask mask1( L"*.*" );
		Mask mask2( L"*.?s" );

		String file1( L"image.bmp" );
		String file2( L"program.vs" );
		String file3( L"program.vp" );

		Assert( mask1.Matches(file1) );
		Assert( mask1.Matches(file2) );
		Assert( mask1.Matches(file3) );
		Assert( !mask2.Matches(file1) );
		Assert( mask2.Matches(file2) );
		Assert( !mask2.Matches(file3) );
	}

} _tst;
