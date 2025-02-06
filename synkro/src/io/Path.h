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
// Purpose: Defines file system path.
//==============================================================================
#ifndef _SYNKRO_IO_PATH_
#define _SYNKRO_IO_PATH_


#include "config.h"
#include <lang/String.h>
#include <lang/Vector.h>


namespace synkro
{


namespace io
{


// Abstract path.
class SYNKRO_API Path
{
public:
	// Path delimiter character.
	static const Char										Delimiter;

	// Constructs path from a string.
	explicit Path( const lang::String& path );

	// Retrieves string representation of the path.
	lang::String											GetPath() const;

	// Retrieves path name.
	lang::String											GetName() const;

	// Retrieves file extension with the dot or empty string if file has no extension.
	lang::String											GetExtension() const;

	// Retrieves file extension without the dot or empty string if file has no extension.
	lang::String											GetExtensionWoDot() const;

	// Retrieves path name without extension.
	lang::String											GetNameWoExtension() const;

	// Retrieves base path.
	lang::String											GetBase() const;

	// Retrieves parent path.
	lang::String											GetParent() const;

	// Remove base path.
	lang::String											RemoveBase() const;

	// Determines if the path exists.
	virtual Bool											Exists() const;

	// Performs internal initialization.
	static void												Initialize();

	// Determines if the path is a valid file or directory name.
	static Bool												IsValid( const lang::String& path );

	// Determines if the path is absolute.
	static Bool												IsAbsolute( const lang::String& path );

	// Returns true if the given path is an existing directory.
	static Bool												IsDirectory( const lang::String& path );

	// Returns true if the given path is an existing file.
	static Bool												IsFile( const lang::String& path );

	// Returns a combination of two paths.
	static lang::String										Combine( const lang::String& path1, const lang::String& path2 );

	// Creates an absolute path from a relative path and a base path.
	static lang::String										MakeAbsolute( const lang::String& base, const lang::String& path );

	// Retrieves the list of directories under the specified path.
	static UInt												GetDirs( const lang::String& path, lang::Vector<lang::String>* dirs );

	// Retrieves the list of files under the specified path.
	static UInt												GetFiles( const lang::String& path, const lang::String& mask, lang::Vector<lang::String>* files );

protected:
	lang::String											_path;
};


#include "Path.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_PATH_
