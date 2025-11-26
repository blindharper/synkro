#include "testcommon.h"
#include <mat/VisualMaterialReader.h>
#include <io/FileStream.h>
#include <io/ZipDirectory.h>
#include <lang/Exception.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestVisualMaterialReader :
	public tst::Test
{
public:
	TestVisualMaterialReader() : tst::Test( "TestVisualMaterialReader", 513 ) {}

	void Run()
	{
		try
		{
			/*// Initialize.
			P(IStream) stream1 = new FileStream( "../data/mat/materials.dat" );
			VisualMaterialReader rd( new ZipDirectory(stream1, false) );

			// Read material #1.
			Assert( rd.Read() );
			Assert( rd.GetName() == L"concrete" );
			Assert( rd.GetType() == L"standard" );
			Assert( rd.GetParamCount() == 7 );
			Assert( rd.GetMapCount() == 2 );

			Assert( rd.GetMapType(0) == L"diffuse" );
			Assert( rd.GetMapAmount(0) == 80 );
			Assert( rd.GetMapImage(0) == L"images/concrete/diffuse.tga" );

			Assert( rd.GetMapType(1) == L"bump" );
			Assert( rd.GetMapAmount(1) == 30 );
			Assert( rd.GetMapImage(1) == L"images/concrete/bump.tga" );

			// Read material #2.
			Assert( rd.Read() );
			Assert( rd.GetName() == L"rainbow" );
			Assert( rd.GetType() == L"cartoon" );
			Assert( rd.GetParamCount() == 4 );
			Assert( rd.GetMapCount() == 0 );

			// Read material #3.
			Assert( rd.Read() );
			Assert( rd.GetName() == L"wood" );
			Assert( rd.GetType() == L"standard" );
			Assert( rd.GetParamCount() == 6 );
			Assert( rd.GetParamName(4) == L"specular" );
			Assert( rd.GetParamValue(4) == L"C0C0C0" );
			Assert( rd.GetMapCount() == 2 );

			Assert( rd.GetMapImage(0) == L"checkers" );
			Assert( rd.GetParamCount() == 4 );
			Assert( rd.GetParamName(0) == L"tileVert" );
			Assert( rd.GetParamValue(0) == L"4.0" );
			Assert( rd.GetParamName(1) == L"tileHorz" );
			Assert( rd.GetParamValue(1) == L"4.0" );
			Assert( rd.GetParamName(2) == L"color1" );
			Assert( rd.GetParamValue(2) == L"AA0000" );
			Assert( rd.GetParamName(3) == L"color2" );
			Assert( rd.GetParamValue(3) == L"AAAA00" );

			// Read material #4.
			Assert( rd.Read() );
			Assert( rd.GetName() == L"glass" );
			Assert( rd.GetType() == L"raytrace" );
			Assert( rd.GetParamCount() == 1 );
			Assert( rd.GetParamName(0) == L"ior" );
			Assert( rd.GetParamValue(0) == L"1.55" );
			Assert( rd.GetMapCount() == 0 );

			Assert( !rd.Read() );*/
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
