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
// Purpose: Defines directory of file streams.
//==============================================================================
SYNKRO_INLINE IStreamDirectory* StreamDirectoryEx::CreateDirectory( const lang::String& name )
{
	return (_dir != nullptr) ? _dir->CreateDirectory( name ) : nullptr;
}

SYNKRO_INLINE IStream* StreamDirectoryEx::CreateStream( const lang::String& name )
{
	return (_dir != nullptr) ? _dir->CreateStream( name ) : nullptr;
}

SYNKRO_INLINE IStream* StreamDirectoryEx::GetStream( const lang::String& name ) const
{
	return (_dir != nullptr) ? _dir->GetStream( name ) : nullptr;
}
