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
// Purpose: Null stream system implementation.
//==============================================================================
#ifndef _SYNKRO_IO_NULLSTREAMSYSTEM_
#define _SYNKRO_IO_NULLSTREAMSYSTEM_


#include "config.h"
#include "StreamSystemImpl.h"
#include <io/IStreamSystem.h>


namespace synkro
{


namespace io
{


// Null stream system.
class NullStreamSystem :
	public StreamSystemImpl<IStreamSystem>
{
public:
	// Constructor.
	NullStreamSystem();

	// ISystem methods.
	Bool													Update( Double delta );

	// IStreamSystem methods.
	IStreamDirectory*										MapDirectory( const lang::String& path, Bool recursive );
	IStreamDirectory*										BuildDirectory( const lang::String& path );
	IStream*												MapStream( const lang::String& path );
	IStream*												CreateStream( const lang::String& name );
	IStream*												GetStream( const lang::String& name ) const;
	IStreamDirectory*										GetDirectory( const lang::String& name ) const;
};


} // io


} // synkro


#endif // _SYNKRO_IO_NULLSTREAMSYSTEM_
