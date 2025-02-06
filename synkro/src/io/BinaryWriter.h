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
// Purpose: Defines binary data writer.
//==============================================================================
#ifndef _SYNKRO_IO_BINARYWRITER_
#define _SYNKRO_IO_BINARYWRITER_


#include "config.h"
#include <io/StreamWriter.h>
#include <internal/Reverse.h>


namespace synkro
{


namespace io
{


// Binary data writer.
class BinaryWriter :
	public StreamWriter
{
public:
	// Constructors.
	BinaryWriter( IStream* stream, Bool append, Bool autoFlush );
	BinaryWriter( IStream* stream, Bool append );
	BinaryWriter( IStream* stream );

	// Methods.
	void													Write( void* bytes, UInt count );
	void													Write( Bool value );
	void													Write( Float value );
	void													Write( Double value );
	void													Write( Short value );
	void													Write( UShort value );
	void													Write( Int value );
	void													Write( UInt value );
	void													Write( Long value );
	void													Write( ULong value );
};


#include "BinaryWriter.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_BINARYWRITER_
