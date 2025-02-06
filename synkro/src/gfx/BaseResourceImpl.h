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
// Purpose: Generic base resource implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BASERESOURCEIMPL_
#define _SYNKRO_GFX_BASERESOURCEIMPL_


#include "config.h"
#include <lang/Map.h>
#include "ResourceSet.h"


namespace synkro
{


namespace gfx
{


// Generic base resource implementation.
template <class T>
class BaseResourceImpl :
	public T
{
public:
	// Constructor & destructor.
	BaseResourceImpl();
	virtual ~BaseResourceImpl();

	// BaseResource methods.
	virtual void											AddParent( ResourceSet* parent );
	virtual void											RemoveParent( ResourceSet* parent );
	virtual void											Invalidate();
	virtual IResource*										AsResource() const;

protected:
	typedef lang::MapPair<Pointer, UInt>					ParentEntry;

	lang::Map<Pointer, UInt>								_parents;
	IResource*												_resource;
	Bool													_dirty;
};


#include "BaseResourceImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASERESOURCEIMPL_
