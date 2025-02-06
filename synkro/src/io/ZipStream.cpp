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
#include "config.h"
#include "ZipStream.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


ZipStream::ZipStream( BaseDirectory* zip, IStreamDirectory* directory, const String& path, const String& name, UInt size ) :
	StreamImpl<IStream>( directory, name ),
	_path( path ),
	_zip( zip ),
	_pos( 0L ),
	_size( size )
{
	assert( _zip != nullptr );
}

ZipStream::ZipStream( BaseDirectory* zip, IStreamDirectory* directory, const String& name ) :
	StreamImpl<IStream>( directory, name ),
	_path( name ),
	_zip( zip ),
	_pos( 0L ),
	_size( 0L )
{
	assert( _zip != nullptr );
}


} // io


} // synkro
