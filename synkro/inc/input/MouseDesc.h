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
// Purpose: Defines mouse description.
//==============================================================================
#ifndef _SYNKRO_INPUT_MOUSEDESC_
#define _SYNKRO_INPUT_MOUSEDESC_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace input
{


/**
 * Mouse device description.
 */
class SYNKRO_API MouseDesc
{
public:
	/** Creates default mouse description. */
	MouseDesc();

	/** Creates mouse description with the specified properties. */
	MouseDesc( const lang::String& name, UInt axisCount, UInt buttonCount );

	/** User-friendly device name. */
	lang::String											Name;

	/** Total number of axes in the mouse. */
	UInt													AxisCount;

	/** Total number of buttons in the mouse. */
	UInt													ButtonCount;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSEDESC_
