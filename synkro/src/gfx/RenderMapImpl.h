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
// Purpose: Generic rendering map implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERMAPIMPL_
#define _SYNKRO_GFX_RENDERMAPIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace gfx
{


// Generic rendering map implementation.
template <class T>
class RenderMapImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderMapImpl( IRenderQueue* queue );
	virtual ~RenderMapImpl();

	// IRenderMap methods.
	virtual void											SetVertexParams( IParameterSet* params );
	virtual IParameterSet*									GetVertexParams() const;
	virtual IRenderQueue*									GetQueue() const;

protected:
	IRenderQueue*											_queue;
	IParameterSet*											_vertexParams;
};


#include "RenderMapImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERMAPIMPL_
