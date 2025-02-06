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
// Purpose: Defines line rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_ILINERENDEROBJECT_
#define _SYNKRO_GFX_ILINERENDEROBJECT_


#include "config.h"
#include <gfx/IRenderObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Line rendering object.
 */
iface ILineRenderObject :
	public IRenderObject
{
public:
	/**
	 * Sets parameters for program's vertex stage.
	 */
	virtual void											SetVertexParameters( IParameterSet* params ) = 0;

	/**
	 * Sets index of the first element and the number of elements to render.
	 */
	virtual void											SetElementRange( UInt start, UInt count ) = 0;

	/**
	 * Sets index of the first instance and the number of instances to render.
	 */
	virtual void											SetInstanceRange( UInt start, UInt count ) = 0;

	/**
	 * Retrieves parameters for program's vertex stage.
	 */
	virtual IParameterSet*									GetVertexParameters() const = 0;

	/**
	 * Retrieves index of the first element to render.
	 */
	virtual UInt											GetStartElement() const = 0;

	/**
	 * Retrieves the number of elements to render.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves index of the first instance to render.
	 */
	virtual UInt											GetStartInstance() const = 0;

	/**
	 * Retrieves the number of instances to render.
	 */
	virtual UInt											GetInstanceCount() const = 0;

	/**
	 * Retrieves the owner queue.
	 */
	virtual ILineRenderQueue*								GetQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ILINERENDEROBJECT_
