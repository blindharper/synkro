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
// Purpose: Defines post-process rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_IPOSTPROCESSRENDERQUEUE_
#define _SYNKRO_GFX_IPOSTPROCESSRENDERQUEUE_


#include "config.h"
#include <gfx/IRenderQueue.h>


namespace synkro
{


namespace gfx
{


/**
 * Post-process rendering queue.
 */
iface IPostProcessRenderQueue :
	public IRenderQueue
{
public:
	/**
	 * Creates rendering object and adds it to the queue.
	 * @param program Program used to perform post-processing.
	 * @return Created rendering object.
	 * @exception Exception Program is null.
	 */
	virtual IPostProcessRenderObject*						CreateObject( IProgram* program ) = 0;

	/**
	 * Sets input resource for the post-processing.
	 * @param input Post-processing input resource.
	 * @exception BadArgumentException input is null.
	 */
	virtual void											SetInput( IResource* input ) = 0;

	/**
	 * Retrieves input resource for the post-processing.
	 */
	virtual IResource*										GetInput() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPOSTPROCESSRENDERQUEUE_
