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
// Purpose: Implements file-not-found exception.
//==============================================================================
#include "config.h"
#include <io/FileNotFoundException.h>


namespace synkro
{


namespace io
{


FileNotFoundException::FileNotFoundException( const lang::String& message, const lang::String& filename ) :
	IoException( lang::String::Format(L"Cannot access file {0,q}. Reason: {1}", filename, message) ),
	_filename( filename )
{
}

FileNotFoundException::FileNotFoundException( const lang::String& filename ) :
	IoException( lang::String::Format( L"Cannot find file {0,q}.", filename) ),
	_filename( filename )
{
}

lang::String FileNotFoundException::Filename() const
{
	return _filename;
}

lang::String FileNotFoundException::ToString() const
{
	return lang::String::Format( L"Cannot access file {0,q}. Reason: {1}", _filename, _message );
}

FileNotFoundException::FileNotFoundException( const FileNotFoundException& )
{
}

FileNotFoundException& FileNotFoundException::operator=( const FileNotFoundException& )
{
	return *this;
}


} // io


} // synkro
