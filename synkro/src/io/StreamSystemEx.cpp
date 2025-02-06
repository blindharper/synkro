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
#include "config.h"
#include "StreamSystemEx.h"
#include "StreamDirectoryEx.h"
#include "StreamEx.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


StreamSystemEx::StreamSystemEx( IStreamSystem* streamSystem, ILog* log ) :
	StreamSystemImpl<IStreamSystemEx>( log ),
	_streamSystem( streamSystem ),
	_dirFactories( A(FactoryEntry) )
{
}

StreamSystemEx::~StreamSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying stream system...") );
}

Bool StreamSystemEx::Update( Double delta )
{
	return _streamSystem->Update( delta );
}

IStreamDirectory* StreamSystemEx::MapDirectory( const String& path, Bool recursive )
{
	Path p( path );
	IStreamDirectory* dir = _streamSystem->GetDirectory( p.GetName() );
	if ( dir != nullptr )
		return dir;

	dir = _streamSystem->MapDirectory( path, recursive );	
	if ( dir != nullptr )
	{
		IStreamDirectory* wrapperDir = new StreamDirectoryEx( this, nullptr, dir, _log );
		_dirs.Add( wrapperDir );
		return wrapperDir;
	}

	return nullptr;
}

IStreamDirectory* StreamSystemEx::BuildDirectory( const String& path )
{
	return _streamSystem->BuildDirectory( path );
}

IStream* StreamSystemEx::MapStream( const String& path )
{
	Path filename( path );
	IStreamDirectory* dir = MapDirectory( filename.GetParent(), false );
	IStream* stream = _streamSystem->MapStream( path );

	if ( stream != nullptr )
	{
		IStream* wrapperStream = new StreamEx( dir, stream );
		_streams.Add( wrapperStream );
		return wrapperStream;
	}

	return nullptr;
}

IStream* StreamSystemEx::CreateStream( const String& path )
{
	return _streamSystem->CreateStream( path );
}

IStreamDirectory* StreamSystemEx::CreateDirectory( IStream* stream, const StreamDirectory& type, Bool write )
{
	if ( !_dirFactories.ContainsKey(type) )
		return nullptr;

	IStreamDirectoryFactory* factory = _dirFactories[type];
	return factory->Create( stream, write );
}

IStreamDirectory* StreamSystemEx::CreateDirectory( const String& path, const StreamDirectory& type )
{
	if ( !_dirFactories.ContainsKey(type) )
		return nullptr;

	IStreamDirectoryFactory* factory = _dirFactories[type];
	IStream* stream = _streamSystem->CreateStream( path );
	return factory->Create( stream, true );
}

IStream* StreamSystemEx::CreateBinaryStream( const Byte* data, UInt size )
{
	return new BinaryStream( data, size );
}

IStream* StreamSystemEx::CreateBinaryStream()
{
	return new BinaryStream();
}

IStream* StreamSystemEx::CreateTextStream( const String& data, const char* encoding )
{
	return new TextStream( data, encoding );
}

IStream* StreamSystemEx::CreateTextStream( const char* encoding )
{
	return new TextStream( encoding );
}

IStream* StreamSystemEx::CreateTextStream()
{
	return new TextStream();
}

IStreamDirectory* StreamSystemEx::CreateDirectory( IStream* stream )
{
	IStreamDirectory* dir = nullptr;

	MapIterator<UInt, IStreamDirectoryFactory*> it = _dirFactories.Begin();
	const MapIterator<UInt, IStreamDirectoryFactory*> itEnd = _dirFactories.End();
	for ( ; it != itEnd ; ++it )
	{
		dir = it.Value()->Create( stream, false );
		if ( dir != nullptr )
			break;
	}

	return dir;
}

void StreamSystemEx::Initialize( IStreamSystem* streamSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating stream system...") );
	_streamSystem = streamSystem;
}

void StreamSystemEx::RegisterDirectoryFactory( IStreamDirectoryFactory* factory )
{
	assert( factory != nullptr );

	const StreamDirectory type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering stream directory of type {0,q}...", type.ToString()) );
	if ( !_dirFactories.ContainsKey(type) )
	{
		try
		{
			_dirFactories[type] = factory;
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Factory already registered.") );
	}
}


} // io


} // synkro
