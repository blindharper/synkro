//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: MS compressed stream.
//==============================================================================
#ifndef _SYNKRO_SCENE_MSZIPSTREAM_
#define _SYNKRO_SCENE_MSZIPSTREAM_


#include "config.h"
#include <lang/Ptr.h>
#include <io/IStream.h>
#include <zlib/zlib.h>


namespace synkro
{


namespace scene
{


class MsZipStream
{
public:
	// Constructor.
	MsZipStream( io::IStream* stream, Bool binary, Int windowBits );

	// Methods.
	io::IStream*											Decompress();

private:
	enum
	{
		MSZIP_MAGIC = 0x4b43,
		MSZIP_BLOCK_SIZE = 32786,
	};

	P(io::IStream)											_stream;
	UInt													_size;
	z_stream												_zStream;

	size_t													DecompressBlock( const void *data, size_t in, Byte* out, size_t availableOut );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MSZIPSTREAM_
