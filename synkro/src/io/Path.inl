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
SYNKRO_INLINE Path::Path( const lang::String& path ) :
	_path( path )
{
}

SYNKRO_INLINE lang::String Path::GetPath() const
{
	return _path;
}
