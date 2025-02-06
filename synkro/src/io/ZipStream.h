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
// Purpose: Defines zip file based stream.
//==============================================================================
#ifndef _SYNKRO_IO_ZIPSTREAM_
#define _SYNKRO_IO_ZIPSTREAM_


#include "config.h"
#include "StreamImpl.h"
#include <io/IStream.h>
#include "BaseDirectory.h"


namespace synkro
{


namespace io
{


// Zip stream.
class ZipStream :
	public StreamImpl<IStream>
{
public:
	// Constructors.
	ZipStream( BaseDirectory* zip, IStreamDirectory* directory, const lang::String& path, const lang::String& name, UInt size );
	ZipStream( BaseDirectory* zip, IStreamDirectory* directory, const lang::String& name );

	// IStream methods.
	void													Open( const OpenMode& mode );
	void													Close();
	void													Flush();
	UInt													Read( void* data, UInt size );
	UInt													Write( const void* data, UInt size );
	Int														Seek( Int bytes, const SeekOrigin& origin );
	Bool													Reset();
	void													SetLength( UInt length );
	UInt													GetLength() const;
	UInt													GetPosition() const;

private:
	BaseDirectory*											_zip;
	lang::String											_path;
	UInt													_pos;
	UInt													_size;
};


#include "ZipStream.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_ZIPSTREAM_
