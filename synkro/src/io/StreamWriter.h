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
// Purpose: Defines base stream writer.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMWRITER_
#define _SYNKRO_IO_STREAMWRITER_


#include "config.h"
#include <lang/Ptr.h>
#include <io/IStream.h>


namespace synkro
{


namespace io
{


// Base stream writer.
class SYNKRO_API StreamWriter
{
public:
	// Constructors & destructor.
	StreamWriter( IStream* stream, Bool append, Bool autoFlush );
	StreamWriter( IStream* stream, Bool append );
	StreamWriter( IStream* stream );
	virtual ~StreamWriter();

	// Methods.
	void													Write( const void* data, UInt size );
	void													Close();
	void													Flush();
	void													SetAutoFlush( Bool autoFlush );
	Bool													GetAutoFlush() const;
	IStream*												GetStream() const;

protected:
	P(IStream)												_stream;
	Bool													_autoFlush;
};


#include "StreamWriter.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMWRITER_
