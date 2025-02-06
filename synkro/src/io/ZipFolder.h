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
// Purpose: Internal zip archive directory.
//==============================================================================
#ifndef _SYNKRO_IO_ZIPFOLDER_
#define _SYNKRO_IO_ZIPFOLDER_


#include "config.h"
#include "StreamDirectoryImpl.h"
#include <io/IStreamDirectory.h>
#include "BaseDirectory.h"


namespace synkro
{


namespace io
{


// Internal zip archive directory.
class ZipFolder :
	public StreamDirectoryImpl<IStreamDirectory>
{
public:
	// Constructor.
	ZipFolder( IStreamDirectory* parent, BaseDirectory* zip, const lang::String& path );

	// IStreamDirectory methods.
	IStreamDirectory*										CreateDirectory( const lang::String& name );
	IStream*												CreateStream( const lang::String& name );

	// Other methods.
	void													AddEntry( const lang::String& path, const lang::String& name, UInt size );

private:
	BaseDirectory*											_zip;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ZIPFOLDER_
