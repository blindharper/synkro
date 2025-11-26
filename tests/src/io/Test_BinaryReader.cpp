#include "config.h"
#include "Test.h"
#include <lang/Vector.h>
#include <io/BinaryReader.h>
#include <io/BinaryStream.h>

//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestBinaryReader :
	public Test
{
public:
	TestBinaryReader() : Test( "TestBinaryReader", 500 ) {}

	void Run()
	{
		try
		{
			Double nums[] = { 1.34, 56.1, -0.12, 4.1763, 0.03, -25.7 };
			Vector<Byte> buffer( (const Byte*)nums, sizeof(nums), A(Byte) );
			BinaryReader rd( new BinaryStream(buffer.Begin(), buffer.Size()) );

			Double d;
			int cnt = sizeof(nums)/sizeof(nums[0]);
			for ( int i = 0; i < cnt; ++i )
			{
				d = rd.ReadDouble();
				Assert( d == nums[i] );
			}
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
