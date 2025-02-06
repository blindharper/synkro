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
// Purpose: Null stream system implementation.
//==============================================================================
#include "config.h"
#include "NullStreamSystem.h"
#include "FileStream.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


NullStreamSystem::NullStreamSystem() :
	StreamSystemImpl<IStreamSystem>( nullptr )
{
}

Bool NullStreamSystem::Update( Double delta )
{
	return true;
}

IStreamDirectory* NullStreamSystem::MapDirectory( const String& path, Bool recursive )
{
	return nullptr;
}

IStreamDirectory* NullStreamSystem::BuildDirectory( const String& path )
{
	return nullptr;
}

IStream* NullStreamSystem::MapStream( const String& path )
{
	return nullptr;
}

IStream* NullStreamSystem::CreateStream( const String& name )
{
	return new FileStream( name );
}

IStream* NullStreamSystem::GetStream( const String& name ) const
{
	return nullptr;
}

IStreamDirectory* NullStreamSystem::GetDirectory( const String& name ) const
{
	return nullptr;
}


} // io


} // synkro
