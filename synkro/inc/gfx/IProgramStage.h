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
// Purpose: Defines graphics program stage.
//==============================================================================
#ifndef _SYNKRO_GFX_IPROGRAMSTAGE_
#define _SYNKRO_GFX_IPROGRAMSTAGE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics program stage.
 */
iface IProgramStage :
	public core::IObject
{
public:
	/**
	 * Retrieves parameter collection for the stage.
	 */
	virtual IParameterSet*									GetParameters() const = 0;

	/**
	 * Retrieves input resources for the stage.
	 */
	virtual IResourceSet*									GetResources() const = 0;

	/**
	 * Retrieves samplers used by the stage.
	 */
	virtual ISamplerStateSet*								GetSamplers() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPROGRAMSTAGE_
