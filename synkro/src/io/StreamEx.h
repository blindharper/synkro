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
// Purpose: Defines a particular stream.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMEX_
#define _SYNKRO_IO_STREAMEX_


#include "config.h"
#include "StreamImpl.h"
#include <io/IStream.h>


namespace synkro
{


namespace io
{


// Logical file stream.
class StreamEx :
	public StreamImpl<IStream>
{
public:
	// Constructors.
	StreamEx( IStreamDirectory* dir, IStream* stream );

	// IStream methods.
	void													Open( const OpenMode& mode );
	void													Close();
	void													Flush();
	UInt													Read( void* data, UInt size );
	UInt													Write( const void* data, UInt size );
	Int														Seek( Int bytes, const SeekOrigin& origin );
	Bool													Reset();
	void													Delete();
	void													SetAccessMode( const AccessMode& mode );
	void													SetLength( UInt length );
	AccessMode												GetAccessMode() const;
	UInt													GetLength() const;
	UInt													GetPosition() const;
	OpenMode												GetMode() const;

private:
	P(IStream)												_stream;
};


#include "StreamEx.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMEX_
