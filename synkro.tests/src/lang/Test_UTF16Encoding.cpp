#include "config.h"
#include "Test.h"
#include <lang/UTF16Encoding.h>
#include <internal/Zero.h>

//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class TestUTF16Encoding :
	public Test
{
public:
	TestUTF16Encoding() : Test( "TestUTF16Encoding", 203 ) {}

	void Run()
	{
		UTF16Encoding enc( false );

		// Encode.
		Char bufSrc2[] = L"Test UTF-16 string\0";
		UInt srcLenUsed2;
		UInt dstLenUsed2;
		char bufDst2[64];
		Zero( bufDst2, 64 );
		UInt d2 = 0;
		UInt s2 = 0;

		enc.Encode( (const Char*)bufSrc2, (UInt)wcslen(bufSrc2), &srcLenUsed2, (Byte*)bufDst2, 64, &dstLenUsed2 );
		//Assert( strcmp("T\0e\0s\0t\0 \0U\0T\0F\0-\01\06\0 \0s\0t\0r\0i\0n\0g", (const char*)bufDst2) == 0 );

		// Decode.
		char bufSrc[] = "Test UTF-16 string\0";
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
		Assert( wcscmp(L"Test UTF-16 string", bufDst) == 0 );
	}

} _tst;
