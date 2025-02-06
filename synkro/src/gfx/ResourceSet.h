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
#ifndef _SYNKRO_GFX_RESOURCESET_
#define _SYNKRO_GFX_RESOURCESET_


#include "config.h"
#include "ResourceSetImpl.h"
#include "BaseResource.h"
#include <gfx/IResourceSet.h>
#include <gfx/IResource.h>


namespace synkro
{


namespace gfx
{


// Logical resource set.
class ResourceSet :
	public ResourceSetImpl<IResourceSet, IResource>
{
public:
	// Constructors.
	ResourceSet( const ProgramStageType& type, IResourceSet* set );
	ResourceSet( const ProgramStageType& type, const ResourceSet& other, UInt ownerID );

	// IResourceSet methods.
	void													Bind();
	void													Unbind();
	virtual void											Set( UInt index, IResource* resource );
	IResourceSet*											Clone( UInt ownerID ) const;

	// Other methods.
	void													SetDirty();		// NB: Remove !!!
	Bool													IsDirty() const;

private:
	P(IResourceSet)											_set;
	Bool													_readonly;
	Bool													_dirty;
};


#include "ResourceSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RESOURCESET_
