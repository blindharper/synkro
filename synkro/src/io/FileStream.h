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
// Purpose: Defines file-based stream.
//==============================================================================
#ifndef _SYNKRO_IO_FILESTREAM_
#define _SYNKRO_IO_FILESTREAM_


#include "config.h"
#include "StreamImpl.h"
#include <io/IStream.h>


namespace synkro
{


namespace io
{


// File stream.
class SYNKRO_API FileStream :
	public StreamImpl<IStream>
{
public:
	// Constructor.
	FileStream( const lang::String& path );

	// IStream methods.
	void													Open( const OpenMode& mode );
	void													Close();
	void													Flush();
	UInt													Read( void* data, UInt size );
	UInt													Write( const void* data, UInt size );
	Int														Seek( Int bytes, const SeekOrigin& origin );
	Bool													Reset();
	void													SetLength( UInt length );
	Bool													Exists() const;
	UInt													GetLength() const;
	UInt													GetPosition() const;

private:
	lang::String											_dir;
	FILE*													_stream;

	static lang::String										PathToDir( const lang::String& path );
	static lang::String										PathToName( const lang::String& path );
};


} // io


} // synkro


#endif // _SYNKRO_IO_FILESTREAM_
