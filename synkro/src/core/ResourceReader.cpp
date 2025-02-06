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
// Purpose: Defines untyped resource reader.
//==============================================================================
#include "config.h"
#include "ResourceReader.h"
#include <lang/Exception.h>
#include <io/IStreamDirectory.h>
#include <io/XmlReader.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ResourceReader::ResourceReader( IStreamDirectory* directory ) :
	_entries( A(StringEntry) ),
	_directory( directory )
{
	Init();
}

IStream* ResourceReader::GetResource( const String& name ) const
{
	return _entries.ContainsKey(name) ? _directory->GetStream(_entries[name]) : nullptr;
}

void ResourceReader::Init()
{
	assert( _directory != nullptr );

	// Get 'manifest.xml' file.
	P(IStream) stream = _directory->GetStream( L"manifest.xml" );
	if ( stream == nullptr )
		throw Exception( L"Bad font resource. Missing 'manifest.xml' file." );

	XmlReader rd( stream );

	// Read <resource> tag.
	if ( !rd.Read() || !rd.GetName().EqualsTo(L"resource", true) )
		throw Exception( L"Bad resource. Missing <resource> tag." );

	// Read all resources.
	while ( rd.Read() && rd.GetName().EqualsTo(L"entry", true) )
	{
		String name = rd.GetAttributeValue( L"name" );
		String path = rd.GetAttributeValue( L"path" );
		_entries[name] = path;
	}
}


} // core


} // synkro
