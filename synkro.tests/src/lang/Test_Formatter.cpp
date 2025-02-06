#include "config.h"
#include "Test.h"
#include <lang/Formatter.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------

class TestFormatter :
	public Test
{
public:
	TestFormatter() : Test( "TestFormatter", 104 ) {}

	void Run()
	{
		String res;

		String s1 = "string";
		String s2 = "Works";

		// Static formatter.
		res = Formatter::Format( L"test {0} pattern: {1} ok!", s1, s2 ).ToString();
		Assert( res == L"test string pattern: Works ok!" );

		res = Formatter::Format( L"test {0,uq} pattern: {1,l} ok!", s1, s2 ).ToString();
		Assert( res == L"test 'STRING' pattern: works ok!" );

		res = Formatter::Format( L"{0} times {1} is {2}", 11, 12, 11*12 ).ToString();
		Assert( res == L"11 times 12 is 132" );

		res = Formatter::Format( L"test numeric '{0,x}' pattern!", 255 ).ToString();
		Assert( res == L"test numeric 'ff' pattern!" );

		res = Formatter::Format( L"test numeric '{0,0.##}' pattern!", .1f ).ToString();
		Assert( res == L"test numeric '0.10' pattern!" );

		// Instanced formatter.
		Formatter fmt( L"This is {0,u} #{1}" );
		fmt.Map( L"info", 745 );
		res = fmt.ToString();
		Assert( res == L"This is INFO #745" );

		fmt.Map( L"warning", 321 );
		res = fmt.ToString();
		Assert( res == L"This is WARNING #321" );
	}

} _tst;
