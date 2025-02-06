#include "config.h"
#include "Test.h"
#include <ui/ThemeReader.h>
#include <io/FileStream.h>
#include <io/ZipDirectory.h>
#include <lang/Exception.h>
#include <img/Color.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::ui;
using namespace synkro::img;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestThemeReader :
	public Test
{
public:
	TestThemeReader() : Test( "TestThemeReader", 516 ) {}

	void Run()
	{
		try
		{
			// Initialize.
			P(IStream) stream = new FileStream( "../../data/ui/themes.zip" );
			P(IStreamDirectory) dir = new ZipDirectory( stream, false );
			ThemeReader rd( dir );

			// Read.
			Assert( rd.Read() );
			Assert( rd.GetName() == L"glass" );
			Assert( dir->GetStream(rd.GetImage()) != null );
			Assert( dir->GetStream(rd.GetAlpha()) != null );
			
			Assert( rd.GetCursorRect() == Rect(65,17,83,40) );
			
			Assert( rd.GetButtonRect() == Rect(0,0,40,40) );
			Assert( rd.GetButtonCenter() == Rect(2,2,38,38) );
			
			Assert( rd.GetEditRect() == Rect(0,50,40,73) );
			Assert( rd.GetEditCenter() == Rect(2,52,38,71) );
			
			Assert( rd.GetListRect() == Rect(0,50,40,73) );
			Assert( rd.GetListCenter() == Rect(2,52,38,71) );
			
			Assert( rd.GetOptionRect(false) == Rect(1,74,20,93) );
			Assert( rd.GetOptionCenter(false) == Rect(3,76,18,91) );
			Assert( rd.GetOptionRect(true) == Rect(21,74,40,93) );
			Assert( rd.GetOptionCenter(true) == Rect(23,76,38,91) );
			
			Assert( rd.GetProgressEmptyRect() == Rect(0,50,40,73) );
			Assert( rd.GetProgressEmptyCenter() == Rect(2,52,38,71) );
			Assert( rd.GetProgressFilledRect() == Rect(41,50,64,73) );
			Assert( rd.GetProgressFilledCenter() == Rect(43,52,62,71) );
			
			Assert( rd.GetSliderRect(Orientation::Horizontal) == Rect(0,41,40,49) );
			Assert( rd.GetSliderCenter(Orientation::Horizontal) == Rect(2,43,38,47) );
			Assert( rd.GetSliderThumb(Orientation::Horizontal) == Rect(50,17,63,40) );
			Assert( rd.GetSliderRect(Orientation::Vertical) == Rect(41,0,49,40) );
			Assert( rd.GetSliderCenter(Orientation::Vertical) == Rect(43,2,47,38) );
			Assert( rd.GetSliderThumb(Orientation::Vertical) == Rect(50,0,73,13) );

			Assert( rd.GetSwitchRect(false) == Rect(1,94,20,113) );
			Assert( rd.GetSwitchCenter(false) == Rect(3,96,18,111) );
			Assert( rd.GetSwitchRect(true) == Rect(21,94,40,113) );
			Assert( rd.GetSwitchCenter(true) == Rect(23,96,38,111) );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
