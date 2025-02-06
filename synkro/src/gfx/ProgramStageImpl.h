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
// Purpose: Generic program stage implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMSTAGEIMPL_
#define _SYNKRO_GFX_PROGRAMSTAGEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>


namespace synkro
{


namespace gfx
{


// Generic program stage implementation.
template <class T>
class ProgramStageImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ProgramStageImpl();
	virtual ~ProgramStageImpl();

	// IProgramStage methods.
	virtual IParameterSet*									GetParameters() const;
	virtual IResourceSet*									GetResources() const;
	virtual ISamplerStateSet*								GetSamplers() const;

protected:
	P(IParameterSet)										_params;
	P(IResourceSet)											_resources;
	P(ISamplerStateSet)										_samplers;
};


#include "ProgramStageImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMSTAGEIMPL_
