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
// Purpose: Generic resource set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RESOURCESETIMPL_
#define _SYNKRO_GFX_RESOURCESETIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <gfx/IResource.h>
#include <gfx/ProgramStageType.h>


namespace synkro
{


namespace gfx
{


// Generic resource set implementation.
template <class T, class R>
class ResourceSetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ResourceSetImpl( const ProgramStageType& type );
	virtual ~ResourceSetImpl();

	// IResourceSet methods.
	virtual void											Set( UInt index, IResource* resource );
	virtual UInt											GetSize() const;
	virtual IResource*										Get( UInt index ) const;

protected:
	lang::Vector<R*>										_resources;
	ProgramStageType										_type;
};


#include "ResourceSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RESOURCESETIMPL_
