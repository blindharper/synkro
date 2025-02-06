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
// Purpose: Defines binary stream.
//==============================================================================
#ifndef _SYNKRO_IO_BINARYSTREAM_
#define _SYNKRO_IO_BINARYSTREAM_


#include "config.h"
#include "StreamImpl.h"
#include <io/IStream.h>
#include <lang/Vector.h>


namespace synkro
{


namespace io
{


// Binary stream.
class SYNKRO_API BinaryStream :
	public StreamImpl<IStream>
{
public:
	// Constructors.
	BinaryStream( const Byte* data, UInt size );
	BinaryStream( IStreamDirectory* directory );
	BinaryStream();

	// IStream methods.
	void													Open( const OpenMode& mode );
	void													Flush();
	UInt													Read( void* data, UInt size );
	UInt													Write( const void* data, UInt size );
	Int														Seek( Int bytes, const SeekOrigin& origin );
	Bool													Reset();
	void													SetLength( UInt length );
	UInt													GetLength() const;
	UInt													GetPosition() const;

private:
	lang::Vector<Byte>										_buffer;
	UInt													_position;
};


} // io


} // synkro


#endif // _SYNKRO_IO_BINARYSTREAM_
