#include "config.h"
#include <io/XmlReader.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestXmlReader :
	public Test
{
public:
	TestXmlReader() : Test( "TestXmlReader", 512 ) {}

	void Run()
	{
		try
		{
			// Initialize.
			XmlReader rd( new FileStream("../../data/io/stream_in.xml"), true );

			// Read <bookstore> tag.
			Assert( rd.Read() );
			Assert( rd.GetName() == "bookstore" );
			Assert( rd.IsStart() );
			Assert( !rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 0 );

			// Read <book genre='novel' ISBN='10-861003-324'>
			Assert( rd.Read() );
			Assert( rd.GetName() == "book" );
			Assert( rd.IsStart() );
			Assert( rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 2 );
			Assert( rd.GetAttributeName(0) == "genre" );
			Assert( rd.GetAttributeValue(0) == "novel" );
			Assert( rd.GetAttributeValue("genre") == "novel" );
			Assert( rd.GetAttributeName(1) == "ISBN" );
			Assert( rd.GetAttributeValue(1) == "10-861003-324" );
			Assert( rd.GetAttributeValue("ISBN") == "10-861003-324" );

			// Read <title>The Handmaid's Tale</title>
			Assert( rd.Read() );
			Assert( rd.GetName() == "title" );
			Assert( rd.GetText() == "The Handmaid's Tale" );
			Assert( !rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 0 );

			// Read <price>19.95</price>
			Assert( rd.Read() );
			Assert( rd.GetName() == "price" );
			Assert( rd.GetText() == "19.95" );
			Assert( !rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 0 );

			// Read </book>
			Assert( rd.Read() );
			Assert( rd.GetName() == "book" );
			Assert( rd.IsEnd() );

			// Read <book genre='novel' ISBN='1-861001-57-5'>
			Assert( rd.Read() );
			Assert( rd.GetName() == "book" );
			Assert( rd.IsStart() );
			Assert( rd.GetAttributeValue("genre") == "novel" );
			Assert( rd.GetAttributeValue("ISBN") == "1-861001-57-5" );

			// Read <title>Pride And Prejudice</title>
			Assert( rd.Read() );
			Assert( rd.GetName() == "title" );
			Assert( rd.GetText() == "Pride And Prejudice" );
			Assert( !rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 0 );

			// Read <price>24.95</price>
			Assert( rd.Read() );
			Assert( rd.GetName() == "price" );
			Assert( rd.GetText() == "24.95" );
			Assert( !rd.HasAttributes() );
			Assert( rd.GetAttributeCount() == 0 );

			// Read </book>
			Assert( rd.Read() );
			Assert( rd.GetName() == "book" );
			Assert( rd.IsEnd() );

			// Read <book genre='fiction' ISBN='9-876543-210'>
			Assert( rd.Read() );
			Assert( rd.GetName() == "book" );
			Assert( rd.GetAttributeValue("genre") == "fiction" );
			Assert( rd.IsStart() );

			// Read </bookstore>
			Assert( rd.Read() );
			Assert( rd.GetName() == "bookstore" );
			Assert( rd.IsEnd() );

			// Read nothing.
			Assert( !rd.Read() );
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
