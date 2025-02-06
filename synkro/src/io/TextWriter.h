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
// Purpose: Defines text writer.
//==============================================================================
#ifndef _SYNKRO_IO_TEXTWRITER_
#define _SYNKRO_IO_TEXTWRITER_


#include "config.h"
#include "StreamWriter.h"
#include <lang/Encoding.h>
#include <lang/Vector.h>


namespace synkro
{


namespace io
{


// Text writer.
class SYNKRO_API TextWriter :
	public StreamWriter
{
public:
	// Constructors.
	TextWriter( IStream* stream, const char* encoding, Bool append, Bool autoFlush );
	TextWriter( IStream* stream, const char* encoding, Bool append );
	TextWriter( IStream* stream, const char* encoding );
	TextWriter( IStream* stream, Bool append, Bool autoFlush );
	TextWriter( IStream* stream, Bool append );
	TextWriter( IStream* stream );

	// Methods.
	void													Write( const lang::String& text );
	void													WriteLine( const lang::String& text );

private:
	enum
	{
		BUFFER_CAPACITY = 512,
	};

	lang::Vector<Byte>										_buffer;
	lang::Encoding*											_encoding;
};


} // io


} // synkro


#endif // _SYNKRO_IO_TEXTWRITER_
