#include "config.h"
#include "Test.h"
#include <lang/ASCII7Encoding.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestASCII7Encoding :
	public Test
{
public:
	TestASCII7Encoding() : Test( "TestASCII7Encoding", 201 ) {}

	void Run()
	{
		ASCII7Encoding enc;

		// Decode.
		char bufSrc[] = "Test ASCII-7 string\0";
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
		Assert( wcscmp(L"Test ASCII-7 string", bufDst) == 0 );

		// Encode.
		Char bufSrc2[] = L"Test ASCII-7 string\0";
		UInt srcLenUsed2;
		UInt dstLenUsed2;
		char bufDst2[64];
		Zero( bufDst2, 64 );
		UInt d2 = 0;
		UInt s2 = 0;

		enc.Encode( (const Char*)bufSrc2, (UInt)wcslen(bufSrc2), &srcLenUsed2, (Byte*)bufDst2, 64, &dstLenUsed2 );
		Assert( strcmp("Test ASCII-7 string", (const char*)bufDst2) == 0 );
	}

} _tst;
