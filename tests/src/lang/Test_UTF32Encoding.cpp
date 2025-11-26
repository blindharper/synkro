#include "config.h"
#include "Test.h"
#include <lang/UTF32Encoding.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestUTF32Encoding :
	public Test
{
public:
	TestUTF32Encoding() : Test( "TestUTF32Encoding", 204 ) {}

	void Run()
	{
		UTF32Encoding enc( false );

		// Encode.
		Char bufSrc2[] = L"Test UTF-32 string\0";
		UInt srcLenUsed2;
		UInt dstLenUsed2;
		char bufDst2[128];
		Zero( bufDst2, 128 );
		UInt d2 = 0;
		UInt s2 = 0;

		enc.Encode( (const Char*)bufSrc2, (UInt)wcslen(bufSrc2), &srcLenUsed2, (Byte*)bufDst2, 128, &dstLenUsed2 );
		//Assert( strcmp("T\0\0\0e\0\0\0s\0\0\0t\0\0\0 \0\0\0U\0\0\0T\0\0\0F\0\0\0-\0\0\03\0\0\02\0\0\0 \0\0\0s\0\0\0t\0\0\0r\0\0\0i\0\0\0n\0\0\0g\0\0\0", (const char*)bufDst2) == 0 );

		// Decode.
		Char bufSrc[] = L"Test UTF-32 string\0";
		UInt srcLenUsed;
		UInt dstLenUsed;
		Char bufDst[64];
		Zero( bufDst, 64 );
		UInt d = 0;
		UInt s = 0;

		while ( enc.Decode((const Byte*)bufDst2 + s, dstLenUsed2-s, &srcLenUsed, (Char*)bufDst + d, 4, &dstLenUsed) )
		{
			s += srcLenUsed;
			d += dstLenUsed;
		}
		Assert( wcscmp(L"Test UTF-32 string", bufDst) == 0 );
	}

} _tst;
