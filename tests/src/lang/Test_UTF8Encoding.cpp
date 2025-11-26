#include "config.h"
#include "Test.h"
#include <lang/UTF8Encoding.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestUTF8Encoding :
	public Test
{
public:
	TestUTF8Encoding() : Test( "TestUTF8Encoding", 202 ) {}

	void Run()
	{
		UTF8Encoding enc;

		// Decode.
		char bufSrc[] = "Test UTF-8 string\0";
		UInt srcLenUsed;
		UInt dstLenUsed;
		Char bufDst[64];
		Zero( bufDst, 64 );
		UInt d = 0;
		UInt s = 0;

		while ( enc.Decode((const Byte*)bufSrc + s, (UInt)strlen(bufSrc)-s, &srcLenUsed, (Char*)bufDst + d, 4, &dstLenUsed) )
		{
			s += srcLenUsed;
			d += dstLenUsed;
		}
		Assert( wcscmp(L"Test UTF-8 string", bufDst) == 0 );

		// Encode.
		Char bufSrc2[] = L"Test UTF-8 string\0";
		UInt srcLenUsed2;
		UInt dstLenUsed2;
		char bufDst2[64];
		Zero( bufDst2, 64 );
		UInt d2 = 0;
		UInt s2 = 0;

		enc.Encode( (const Char*)bufSrc2, (UInt)wcslen(bufSrc2), &srcLenUsed2, (Byte*)bufDst2, 64, &dstLenUsed2 );
		Assert( strcmp("Test UTF-8 string", (const char*)bufDst2) == 0 );
	}

} _tst;
