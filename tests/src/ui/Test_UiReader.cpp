#include "config.h"
#include "Test.h"
#include <ui/UiReader.h>
#include <io/FileStream.h>
#include <img/Color.h>
#include <lang/Exception.h>

//------------------------------------------------------------------------------

using namespace synkro::ui;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestUiReader :
	public Test
{
public:
	TestUiReader() : Test( "TestUiReader", 515 ) {}

	void Run()
	{
		try
		{
			// Initialize.
			P(IStream) stream = new FileStream( "../../data/ui/ui.ui" );
			UiReader rd( stream, 1024, 768 );
			
			// Read frame.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_FRAME );
			Assert( rd.GetLocation() == Point(50,150) );
			Assert( rd.GetSize() == Size(300,300) );
			Assert( rd.GetBool(L"border") );

			// Read label.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_LABEL );
			Assert( rd.GetLocation() == Point(4,4) );
			Assert( rd.GetSize() == Size(190,50) );
			Assert( rd.GetText() == L"Sample text" );

			// Read switch.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_SWITCH );
			Assert( rd.GetID() == 1 );
			Assert( rd.GetLocation() == Point(4,60) );
			Assert( rd.GetSize() == Size(190,25) );
			Assert( rd.GetText() == L"Transparent" );
			Assert( rd.GetBool(L"on") );

			// Read option #1.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_OPTION );
			Assert( rd.GetID() == 2 );
			Assert( rd.GetLocation() == Point(4,90) );
			Assert( rd.GetSize() == Size(190,25) );
			Assert( rd.GetText() == L"Align Left" );
			Assert( rd.GetColor() == Color::Lime );
			Assert( rd.GetBool(L"selected") == false );

			// Read option #2.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_OPTION );
			Assert( rd.GetID() == 3 );
			Assert( rd.GetLocation() == Point(4,120) );
			Assert( rd.GetSize() == Size(190,25) );
			Assert( rd.GetText() == L"Align Center" );
			Assert( rd.GetColor() == Color::Transparent );
			Assert( rd.GetBool(L"selected") == true );

			// Read option #3.
			Assert( rd.Read() );
			Assert( rd.GetType() == WIDGET_OPTION );
			Assert( rd.GetID() == 4 );
			Assert( rd.GetLocation() == Point(4,150) );
			Assert( rd.GetSize() == Size(190,25) );
			Assert( rd.GetText() == L"Align Right" );
			Assert( rd.GetColor() == Color::Transparent );
			Assert( rd.GetBool(L"selected") == false );

			Assert( rd.Read() );
			Assert( !rd.IsStart() );
			Assert( rd.GetType() == WIDGET_FRAME );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
