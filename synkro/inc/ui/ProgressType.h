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
// Purpose: Defines progress widget types.
//==============================================================================
#ifndef _SYNKRO_UI_PROGRESSTYPE_
#define _SYNKRO_UI_PROGRESSTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Progress widget types.
 */
SYNKRO_ENUM_BEGIN( ProgressType )
	/** Progress bar. */
	SYNKRO_ENUM_CONST( ProgressType, Bar )

	/** Progress circle. */
	SYNKRO_ENUM_CONST( ProgressType, Circle )

	/** Creates progress type from string. */
	ProgressType( const lang::String& type );

	/** Converts progress type to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_PROGRESSTYPE_
