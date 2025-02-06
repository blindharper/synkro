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
// Purpose: Extended stream system.
//=============================================================================
#ifndef _SYNKRO_IO_STREAMSYSTEMEX_
#define _SYNKRO_IO_STREAMSYSTEMEX_


#include "config.h"
#include "StreamSystemImpl.h"
#include <io/IStreamSystemEx.h>
#include <io/IStreamDirectoryFactory.h>
#include "BinaryStream.h"
#include "TextStream.h"
#include "BaseStreamSystem.h"
#include <lang/Map.h>


namespace synkro
{


namespace io
{


// Extended stream system.
class StreamSystemEx :
	public StreamSystemImpl<IStreamSystemEx>,
	public BaseStreamSystem
{
public:
	// Constructor & destructor.
	StreamSystemEx( IStreamSystem* streamSystem, diag::ILog* log );
	~StreamSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IStreamSystem methods.
	IStreamDirectory*										MapDirectory( const lang::String& path, Bool recursive );
	IStreamDirectory*										BuildDirectory( const lang::String& path );
	IStream*												MapStream( const lang::String& path );
	IStream*												CreateStream( const lang::String& path );

	// IStreamSystemEx methods.
	IStreamDirectory*										CreateDirectory( IStream* stream, const StreamDirectory& type, Bool write );
	IStreamDirectory*										CreateDirectory( const lang::String& path, const StreamDirectory& type );
	IStream*												CreateBinaryStream( const Byte* data, UInt size );
	IStream*												CreateBinaryStream();
	IStream*												CreateTextStream( const lang::String& data, const char* encoding );
	IStream*												CreateTextStream( const char* encoding );
	IStream*												CreateTextStream();

	// BaseStreamSystem methods.
	IStreamDirectory*										CreateDirectory( IStream* stream );

	// Other methods.
	void													Initialize( IStreamSystem* streamSystem );
	void													RegisterDirectoryFactory( IStreamDirectoryFactory* factory );

private:
	typedef lang::MapPair<UInt, IStreamDirectoryFactory*>	FactoryEntry;

	P(IStreamSystem)										_streamSystem;
	lang::Map<UInt, IStreamDirectoryFactory*>				_dirFactories;
};


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMSYSTEMEX_
