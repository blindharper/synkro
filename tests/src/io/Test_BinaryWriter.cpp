#include "config.h"
#include "Test.h"
#include <lang/Vector.h>
#include <io/BinaryWriter.h>
#include <io/BinaryReader.h>
#include <io/BinaryStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;
using namespace synkro;

//------------------------------------------------------------------------------

class TestBinaryWriter :
	public Test
{
public:
	TestBinaryWriter() : Test( "TestBinaryWriter", 501 ) {}

	void Run()
	{
		try
		{
			BinaryStream* stream = new BinaryStream();
			BinaryWriter wr( stream, true );

			wr.Write( false );
			wr.Write( 0.6 );
			wr.Write( (Int)34 );

			BinaryReader rd( stream );
			Bool b = rd.ReadBoolean();
			Assert( b == false );

			Double d = rd.ReadDouble();
			Assert( d == 0.6 );

			Int i = rd.ReadInt();
			Assert( i == 34 );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
