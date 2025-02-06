#include "config.h"
#include "Test.h"
#include <io/XmlWriter.h>
#include <io/FileStream.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------

class TestXmlWriter :
	public Test
{
public:
	TestXmlWriter() : Test( "TestXmlWriter", 513 ) {}

	void Run()
	{
		try
		{
			// Initialize.
			XmlWriter wr( new FileStream("../../data/io/stream_out.xml") );

			// Write declaration.
			wr.WriteDeclaration( "1.0", true );

			// Write start tag.
			wr.WriteStartElement( "bookstore" );

			// Write a comment.
			wr.WriteComment( "First book" );

			// Write first book data.
			wr.WriteStartElement( "book" );
			wr.WriteAttribute( "genre", "novel" );
			wr.WriteAttribute( "ISBN", "10-861003-324" );
			wr.WriteString( "title", "The Handmaid's Tale" );
			wr.WriteString( "price", "19.95" );
			wr.WriteEndElement(); // book

			// Write a comment.
			wr.WriteComment( "Second book" );

			// Write second book data.
			wr.WriteStartElement( "book" );
			wr.WriteAttribute( "genre", "novel" );
			wr.WriteAttribute( "ISBN", "1-861001-57-5" );
			wr.WriteString( "title", "Pride And Prejudice" );
			wr.WriteString( "price", "24.95" );
			wr.WriteEndElement(); // book

			// Write third book data.
			wr.WriteStartElement( "book" );
			wr.WriteAttribute( "genre", "fiction" );
			wr.WriteAttribute( "ISBN", "9-876543-210" );
			wr.WriteEndElement(); // book

			wr.WriteEndElement(); // bookstore
		}
		catch ( Exception& ex )
		{
			char buf[260];
			ex.Message().GetBytes( buf, 260 );
			FatalError( buf );
		}
	}

} _tst;
