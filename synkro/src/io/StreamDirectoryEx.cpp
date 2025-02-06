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
#include "config.h"
#include "StreamDirectoryEx.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


StreamDirectoryEx::StreamDirectoryEx( BaseStreamSystem* streamSystem, IStreamDirectory* parent, IStreamDirectory* dir, ILog* log ) :
	StreamDirectoryImpl<IStreamDirectory>( parent, dir->GetName() ),
	_dir( dir ),
	Logger( log, LogFacility::StreamSystem )
{
	// Add streams, possibly treating them as directories.
	for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
	{
		// Check if this stream is a directory.
		io::IStream* stream = dir->GetStream( i );
		P(IStreamDirectory) directory = streamSystem->CreateDirectory( stream );
		(directory != nullptr) ? _dirs.Add( directory ) : _streams.Add( stream );
	}

	// Add directories.
	for ( UInt i = 0; i < dir->GetDirectoryCount(); ++i )
	{
		_dirs.Add( new StreamDirectoryEx(streamSystem, dir, dir->GetDirectory(i), log) );
	}
}


} // io


} // synkro
