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
// Purpose: Implements plain log file.
//==============================================================================
#include "config.h"
#include "PlainLogFile.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


PlainLogFile::PlainLogFile( const String& version, IStream* stream, UInt maxSize, Bool append ) :
	TextWriter( stream, "UTF-8", append, true ),
	_started( false ),
	_ended( false ),
	_maxSize( maxSize ),
	_version( version )
{
}

void PlainLogFile::OnLogStart( const DateTime& time )
{
	// Prevent emitting multiple start messages.
	if ( _started )
		return;

	_started = true;

	// Check for maximum log size.
	if ( (_maxSize > 0) && (GetStream()->GetLength() > _maxSize*1024) )
	{
		GetStream()->Close();
		GetStream()->Open( OpenMode::Write );
	}

	// Write log header.
	String ruler( L'-', 100 );
	WriteLine( ruler );
	WriteLine( String::Format(L"                                    Synkro {0}", _version) );
	WriteLine( String::Empty );
	WriteLine( String::Format(L"                                    {0,r}", time) );
	WriteLine( ruler );
}

void PlainLogFile::OnLogEnd( const DateTime& time )
{
	// Prevent emitting multiple end messages.
	if ( !_ended )
	{
		_ended = true;
		WriteLine( String::Empty );
	}
}


} // core


} // synkro
