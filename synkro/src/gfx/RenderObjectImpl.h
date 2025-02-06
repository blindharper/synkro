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
// Purpose: Generic rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDEROBJECTIMPL_
#define _SYNKRO_GFX_RENDEROBJECTIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IProgram.h>
#include <gfx/IPrimitiveEx.h>


namespace synkro
{


namespace gfx
{


// Generic rendering object implementation.
template <class T>
class RenderObjectImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderObjectImpl( IProgram* program );
	virtual ~RenderObjectImpl();

	// IRenderObject methods.
	virtual void											Enable( Bool enable );
	virtual Bool											IsEnabled() const;
	virtual IProgram*										GetProgram() const;
	virtual IPrimitiveEx*									GetData() const;

	// Other methods.
	void													ResetDirty();
	Bool													IsDirty() const;

protected:
	P(IPrimitiveEx)											_data;
	IProgram*												_program;
	Bool													_enabled;
	Bool													_dirty;
};


#include "RenderObjectImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDEROBJECTIMPL_
