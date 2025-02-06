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
// Purpose: Logical resource set.
//==============================================================================
#include "config.h"
#include "ResourceSet.h"
#include "BaseResource.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


ResourceSet::ResourceSet( const ProgramStageType& type, IResourceSet* set ) :
	ResourceSetImpl<IResourceSet, IResource>( type ),
	_set( set ),
	_readonly( true ),
	_dirty( true )
{
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_resources.Add( _set->Get(i) );
	}
}

ResourceSet::ResourceSet( const ProgramStageType& type, const ResourceSet& other, UInt ownerID ) :
	ResourceSetImpl<IResourceSet, IResource>( other._type ),
	_set( other._set->Clone(ownerID) ),
	_readonly( false ),
	_dirty( true )
{
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_resources.Add( other.Get(i) );
	}
}

void ResourceSet::Set( UInt index, IResource* resource )
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default resource set." );

	// NB: Check old and new resources at slot 'index'.

	// Call base implementation.
	ResourceSetImpl<IResourceSet, IResource>::Set( index, resource );

	if ( _resources[index] != nullptr )
	{
		BaseResource* res = AsBaseResource( (IResource*)_resources[index] );
		if ( res != nullptr )
			res->RemoveParent( this );
	}

	if ( resource != nullptr )
	{
		BaseResource* res = AsBaseResource( resource );
		if ( res != nullptr )
		{
			res->AddParent( this );
			_set->Set( index, res->AsResource() );
		}
	}
	else
	{
		_set->Set( index, nullptr );
	}

	_dirty = true;
}


} // gfx


} // synkro
