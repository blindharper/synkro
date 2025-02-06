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
// Purpose: Defines text reader.
//==============================================================================
#ifndef _SYNKRO_IO_TEXTREADER_
#define _SYNKRO_IO_TEXTREADER_


#include "config.h"
#include "StreamReader.h"
#include <lang/Encoding.h>
#include <lang/Vector.h>


namespace synkro
{


namespace io
{


// Text reader.
class SYNKRO_API TextReader :
	public StreamReader
{
public:
	// Constructors.
	TextReader( IStream* stream, const char* encoding );
	TextReader( IStream* stream );

	// Methods.
	Char													ReadChar();
	lang::String											Read( UInt num );
	lang::String											ReadLine();
	lang::String											ReadToEnd();

private:
	enum
	{
		BUFFER_SIZE = 512,
	};

	lang::Vector<Char>										_buffer;
	lang::Vector<Char>										_buffer2;
	lang::Encoding*											_encoding;
};


} // io


} // synkro


#endif // _SYNKRO_IO_TEXTREADER_
