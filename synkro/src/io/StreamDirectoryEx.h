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
// Purpose: Defines directory of file streams.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMDIRECTORYEX_
#define _SYNKRO_IO_STREAMDIRECTORYEX_


#include "config.h"
#include "StreamDirectoryImpl.h"
#include <io/IStreamDirectory.h>
#include "BaseStreamSystem.h"


namespace synkro
{


namespace io
{


// Directory of file streams.
class StreamDirectoryEx :
	public StreamDirectoryImpl<IStreamDirectory>,
	public Logger
{
public:
	// Constructors.
	StreamDirectoryEx( BaseStreamSystem* streamSystem, IStreamDirectory* parent, IStreamDirectory* dir, diag::ILog* log );

	// IStreamDirectory methods.
	IStreamDirectory*										CreateDirectory( const lang::String& name );
	IStream*												CreateStream( const lang::String& name );
	IStream*												GetStream( const lang::String& name ) const;

private:
	P(IStreamDirectory)										_dir;
};


#include "StreamDirectoryEx.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMDIRECTORYEX_
