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
// Purpose: Resource implementation.
//==============================================================================
#include "config.h"
#include "Resource.h"
#include <io/BinaryStream.h>
#include <io/ZipDirectory.h>


//------------------------------------------------------------------------------

using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


Resource::Resource( const ResourceType& type, const Byte* data, UInt size ) :
	_type( type ),
	_data( data ),
	_size( size ),
	_id( 0 )
{
#ifdef SYNKRO_STATIC
	Init();
#endif // SYNKRO_STATIC
}

Resource::Resource( UInt id, const Byte* data, UInt size ) :
	_type( ResourceType::Unknown ),
	_data( data ),
	_size( size ),
	_id( id )
{
#ifdef SYNKRO_STATIC
	Init();
#endif // SYNKRO_STATIC
}

IStreamDirectory* Resource::Load()
{
	return new ZipDirectory( new BinaryStream(_data, _size), false );
}

ResourceType Resource::GetType() const
{
	return _type;
}

UInt Resource::ID() const
{
	return _id;
}

#ifdef SYNKRO_STATIC
void Resource::Init()
{
	BaseResource::Next = _Resources;
	BaseResource::Res = this;
	_Resources = this;
}
#endif // SYNKRO_STATIC


} // core


} // synkro
