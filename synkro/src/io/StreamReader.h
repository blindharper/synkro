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
// Purpose: Defines base stream reader.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMREADER_
#define _SYNKRO_IO_STREAMREADER_


#include "config.h"
#include <lang/Ptr.h>
#include <io/IStream.h>


namespace synkro
{


namespace io
{


// Base stream reader.
class SYNKRO_API StreamReader
{
public:
	// Constructor & destructor.
	StreamReader( IStream* stream );
	virtual ~StreamReader();

	// Methods.
	UInt													Read( void* data, UInt size );
	void													Close();
	IStream*												GetStream() const;
	Bool													Eos() const;

protected:
	P(IStream)												_stream;
};


#include "StreamReader.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMREADER_
