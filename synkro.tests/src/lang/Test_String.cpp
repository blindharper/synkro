#include "config.h"
#include "Test.h"
#include <lang/String.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestString :
	public Test
{
public:
	TestString() : Test( "TestString", 102 ) {}

	void Run()
	{
		// Creation.
		String se1;
		String se2(L"");
		Assert( se1.Length() == 0 );
		Assert( se1 == se2 );
		Assert( se1 == String::Empty );
		Assert( se1 != String::Null );

		String snull = String::Null;
		Assert( snull == String::Null );
		Assert( snull.IsNull() );
		Assert( snull != String::Empty );
		Assert( !snull.IsEmpty() );

		String s1( L"Eugene" );
		String s2( L"Eugene" );
		Assert( s1.Length() == 6 );
		Assert( !s1.IsEmpty() );
		Assert( s1 == s2 );

		// Comparison.
		String s3(s2);
		Assert( s1 == s3 );

		String s4( L"Alex" );
		s1 = s4;

		String s5( L"Alexis" );
		Assert( s1 != s5 );

		// Concatenation.
		String hello = "Hello, ";
		String world = "world!";
		String concat = hello + world;
		Assert( concat == "Hello, world!" );

		String app = "Bye, " + world;
		Assert( app == "Bye, world!" );

		Assert( app.StartsWith("Bye") );
		Assert( app.EndsWith("world!") );

		// Search.
		Assert( s2.IndexOf('Z') == -1 );
		Assert( s2.IndexOf('e') == 3 );
		Assert( s2.IndexOf('e', 4) == 5 );

		Assert( s5.IndexOfAny("drbm") == -1 );
		Assert( s5.IndexOfAny("xis") == 3 );

		Assert( s5.LastIndexOf('B') == -1 );
		Assert( s5.LastIndexOf('e') == 2 );
		Assert( s5.LastIndexOf('A', 3) == 0 );

		Assert( s5.LastIndexOfAny("drbm") == -1 );
		Assert( s5.LastIndexOfAny("leA") == 2 );

		Assert( app.IndexOf(',') == 3 );
		Assert( app.IndexOf('Z') == -1 );

		Assert( concat.IndexOf("l") == 2 );
		Assert( concat.IndexOf("lo") == 3 );
		Assert( concat.IndexOf("l", 3) == 3 );
		Assert( concat.IndexOf("e", 4) == -1 );

		Assert( concat.LastIndexOf('l') == 10 );
		Assert( concat.LastIndexOf("world") == 7 );

		String rev = s2.Reverse();
		Assert( rev == "eneguE" );

		String upper = rev.ToUpper();
		Assert( upper == "ENEGUE" );

		String lower = upper.ToLower();
		Assert( lower == "enegue" );

		// Substrings.
		String sub = s3.Substring( 2, 3 );
		Assert( sub.Length() == 3 );
		Assert( sub[0] == Char('g') );

		String subClone = sub;
		subClone = "Attack of clones";
		Assert( subClone.Length() == 16 );

		// Replacement.
		String helloWorld = "Hello, world!";
		Assert( helloWorld.Replace('l', 'n') == "Henno, wornd!" );
		Assert( helloWorld.Replace("ll", "n") == "Heno, world!" );

		// Entries.
		String lst;

		lst = "zero,one,two,,four,five";
		Assert( lst.EntryCount() == 6 );
		Assert( lst.Entry(0) == "zero" );
		Assert( lst.Entry(1) == "one" );
		Assert( lst.Entry(2) == "two" );
		Assert( lst.Entry(3) == "" );
		Assert( lst.Entry(4) == "four" );
		Assert( lst.Entry(5) == "five" );

		Assert( lst.EntryIndex("zero") == 0 );
		Assert( lst.EntryIndex("one") == 1 );
		Assert( lst.EntryIndex("two") == 2 );
		Assert( lst.EntryIndex("three") == -1 );
		Assert( lst.EntryIndex("four") == 4 );
		Assert( lst.EntryIndex("five") == 5 );

		lst = "bread|butter|onion|tomato|cucumber";
		Assert( lst.EntryCount() == 1 );
		Assert( lst.EntryCount('|') == 5 );
		Assert( lst.Entry(3, '|') == "tomato" );
		Assert( lst.Entry(6, '|') == "" );
		Assert( lst.Entry(-1, '|') == "" );
		Assert( lst.Entry(0) == lst );

		Assert( lst.EntryIndex("tomato", '|') == 3 );

		// Comparison.
		subClone = s4;
		Assert( subClone == "Alex" );

		String s6 = "Eugene";
		Assert( s6 > subClone );

		// Trimming.
		String strIntact = "Intact";
		Assert( strIntact.TrimStart() == strIntact );

		String strTrimStart = "   world!";
		Assert( strTrimStart.TrimStart() == "world!" );
		Assert( strTrimStart.TrimStart() == world );

		String strTrimEnd = "world!   ";
		Assert( strTrimEnd.TrimEnd() == "world!" );
		Assert( strTrimEnd.TrimEnd() == world );

		String strTrim = "  world!   ";
		Assert( strTrim.Trim() == "world!" );
		Assert( strTrim.Trim() == world );

		String strPath = "\\path1\\path2/";
		Assert( strPath.Trim("\\") == "path1\\path2/" );
		Assert( strPath.Trim("\\/") == "path1\\path2" );

		// Long strings allocation.
		String ExtremelyLongString = L"The Microsoft DirectX software development kit (SDK) is your backstage pass to multimedia applications that sizzle. DirectX is a set of low-level application programming interfaces (APIs) for creating games and other high-performance multimedia applications. It includes support for high-performance 2-D and 3-D graphics, sound, and input.";

		String strChar = String((Char)'Z');
		Assert( strChar == "Z" );
	}

} _tst;
