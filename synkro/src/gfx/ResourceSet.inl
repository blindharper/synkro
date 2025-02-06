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
SYNKRO_INLINE void ResourceSet::Bind()
{
	SynkroProfile( "ResourceSet.Bind" );

	_set->Bind();
	_dirty = false;
}

SYNKRO_INLINE void ResourceSet::Unbind()
{
	_set->Unbind();
}

SYNKRO_INLINE IResourceSet* ResourceSet::Clone( UInt ownerID ) const
{
	return new ResourceSet( _type, *this, ownerID );
}

SYNKRO_INLINE void ResourceSet::SetDirty()
{
	_dirty = true;
}

SYNKRO_INLINE Bool ResourceSet::IsDirty() const
{
	return _dirty;
}
