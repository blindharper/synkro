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
#ifndef _SYNKRO_GFX_PROGRAMSTAGE_
#define _SYNKRO_GFX_PROGRAMSTAGE_


#include "config.h"
#include "ProgramStageImpl.h"
#include <gfx/IProgramStage.h>
#include <gfx/ProgramStageType.h>


namespace synkro
{


namespace gfx
{


// Logical program stage.
class ProgramStage :
	public ProgramStageImpl<IProgramStage>
{
public:
	// Constructor.
	ProgramStage( const ProgramStageType& type, IProgramStage* stage );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMSTAGE_
