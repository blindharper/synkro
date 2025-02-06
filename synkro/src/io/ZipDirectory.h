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
// Purpose: Defines directory of zip file streams.
//==============================================================================
#ifndef _SYNKRO_IO_ZIPDIRECTORY_
#define _SYNKRO_IO_ZIPDIRECTORY_


#include "config.h"
#include "StreamDirectoryImpl.h"
#include <io/IStreamDirectory.h>
#include "BaseDirectory.h"
#include <zlib/unzip.h>
#include <zlib/zip.h>


namespace synkro
{


namespace io
{


// Directory of zip file streams.
class SYNKRO_API ZipDirectory :
	public StreamDirectoryImpl<IStreamDirectory>,
	public BaseDirectory
{
public:
	// Constructor & destructor.
	ZipDirectory( IStream* stream, Bool write );
	~ZipDirectory();

	// IStreamDirectory methods.
	IStreamDirectory*										CreateDirectory( const lang::String& name );
	IStream*												CreateStream( const lang::String& name );

	// BaseDirectory methods.
	Bool													FileOpen( const lang::String& name, const OpenMode& mode );
	void													FileClose();
	UInt													FileRead( void* data, UInt size );
	UInt													FileWrite( const void* data, UInt size );
	Int														FileSeek( const lang::String& name, UInt size, UInt position, Int bytes, const SeekOrigin& origin );
	Bool													FileReset( const lang::String& name );

	// Other methods.
	static Bool												IsDirectory( IStream* stream );

private:
	friend class ZipStream;

	void													Init();
	void													Close();

	Bool													_readonly;
	unzFile													_handleRead;
	zipFile													_handleWrite;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ZIPDIRECTORY_
