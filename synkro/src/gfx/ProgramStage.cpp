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
// Purpose: Logical program stage.
//==============================================================================
#include "config.h"
#include "ProgramStage.h"
#include "ParameterSet.h"
#include "ResourceSet.h"
#include "SamplerStateSet.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


ProgramStage::ProgramStage( const ProgramStageType& type, IProgramStage* stage )
{
	_params		= new ParameterSet( stage->GetParameters() );
	_resources	= new ResourceSet( type, stage->GetResources() );
	_samplers	= new SamplerStateSet( stage->GetSamplers() );
}


} // gfx


} // synkro
