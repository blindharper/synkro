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
#include "config.h"
#include "ZipFolder.h"
#include "ZipStream.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


ZipFolder::ZipFolder( IStreamDirectory* parent, BaseDirectory* zip, const String& path ) :
	StreamDirectoryImpl<IStreamDirectory>( parent, path ),
	_zip( zip )
{
}

IStreamDirectory* ZipFolder::CreateDirectory( const String& name )
{
	return new ZipFolder( this, _zip, name );
}

IStream* ZipFolder::CreateStream( const String& name )
{
	return new ZipStream( _zip, this, name );
}

void ZipFolder::AddEntry( const String& path, const String& name, UInt size )
{
	Path pathName( name );
	String strBase = pathName.GetBase();
	if ( !strBase.IsEmpty() )
	{
		// Find base folder.
		ZipFolder* folder = nullptr;
		for ( UInt i = 0; i < _dirs.Size(); ++i )
		{
			if ( _dirs[i]->GetName() == strBase )
			{
				folder = (ZipFolder*)_dirs[i].AsPtr();
				break;
			}
		}

		// Create folder if one does not exist.
		if ( folder == nullptr )
		{
			folder = new ZipFolder( this, _zip, strBase );
			_dirs.Add( folder );
		}

		// Add entry to the folder.
		String strName = pathName.RemoveBase();
		if ( strName.IsEmpty() )
		{
			strName = pathName.GetPath();
		}
		folder->AddEntry( path, strName, size );
	}
	else
	{
		String slash( L'/' );
		if ( name.EndsWith(slash) )
		{
			_dirs.Add( new ZipFolder(this, _zip, name.TrimEnd(slash)) );
		}
		else
		{
			_streams.Add( new ZipStream(_zip, this, path, name, size) );
		}
	}
}


} // io


} // synkro
