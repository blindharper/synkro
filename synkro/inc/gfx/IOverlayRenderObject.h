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
// Purpose: Defines overlay rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_IOVERLAYRENDEROBJECT_
#define _SYNKRO_GFX_IOVERLAYRENDEROBJECT_


#include "config.h"
#include <gfx/IRenderObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Overlay rendering object.
 */
iface IOverlayRenderObject :
	public IRenderObject
{
public:
	/**
	 * Enables/disables smoothing. Default is true.
	 */
	virtual void											EnableSmoothing( Bool enable ) = 0;

	/**
	 * Sets scissor rectangle used to render the object.
	 */
	virtual void											SetScissorRect( IRect* rect ) = 0;

	/**
	 * Sets blend states used to render the object.
	 */
	virtual void											SetBlendStates( IBlendStateSet* states ) = 0;

	/**
	 * Sets parameters for program's vertex stage.
	 */
	virtual void											SetVertexParameters( IParameterSet* params ) = 0;

	/**
	 * Sets parameters for program's fragment stage.
	 */
	virtual void											SetFragmentParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's fragment stage.
	 */
	virtual void											SetFragmentResources( IResourceSet* resources ) = 0;

	/**
	 * Sets the number of elements to render.
	 */
	virtual void											SetElementCount( UInt count ) = 0;

	/**
	 * Sets object's z-order.
	 */
	virtual void											SetOrder( UInt order ) = 0;

	/**
	 * Indcates whether the smoothing is enabled.
	 */
	virtual Bool											IsSmoothingEnabled() const = 0;

	/**
	 * Retrieves scissor rectangle used to render the object.
	 */
	virtual IRect*											GetScissorRect() const = 0;

	/**
	 * Retrieves blend states used to render the object.
	 */
	virtual IBlendStateSet*									GetBlendStates() const = 0;

	/**
	 * Retrieves parameters for program's vertex stage.
	 */
	virtual IParameterSet*									GetVertexParameters() const = 0;

	/**
	 * Retrieves parameters for program's fragment stage.
	 */
	virtual IParameterSet*									GetFragmentParameters() const = 0;

	/**
	 * Retrieves resources for program's fragment stage.
	 */
	virtual IResourceSet*									GetFragmentResources() const = 0;

	/**
	 * Retrieves the number of elements to render.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves object's z-order.
	 */
	virtual UInt											GetOrder() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IOVERLAYRENDEROBJECT_
