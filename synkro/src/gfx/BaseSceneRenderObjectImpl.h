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
// Purpose: Generic base scene render object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BASESCENERENDEROBJECTIMPL_
#define _SYNKRO_GFX_BASESCENERENDEROBJECTIMPL_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace gfx
{


// Generic base scene render object implementation.
template <class T>
class BaseSceneRenderObjectImpl :
	public T
{
public:
	// Constructor & destructor.
	BaseSceneRenderObjectImpl();
	virtual ~BaseSceneRenderObjectImpl();

	// BaseSceneRenderObject methods.
	virtual void											SetKeys( const lang::String& resourceKey, const lang::String& dataKey, const lang::String& instanceKey );
	virtual lang::String									GetResourceKey() const;
	virtual lang::String									GetDataKey() const;
	virtual lang::String									GetInstanceKey() const;

protected:
	lang::String											_resourceKey;
	lang::String											_dataKey;
	lang::String											_instanceKey;
};


#include "BaseSceneRenderObjectImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASESCENERENDEROBJECTIMPL_
