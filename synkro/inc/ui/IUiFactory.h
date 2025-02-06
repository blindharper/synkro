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
// Purpose: Defines User interface factory.
//==============================================================================
#ifndef _SYNKRO_UI_IUIFACTORY_
#define _SYNKRO_UI_IUIFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace ui
{


/**
 * User interface factory.
 */
iface IUiFactory :
	public core::IFactory
{
public:
	/**
	 * Creates user interface.
	 * @param context Framework context.
	 * @param theme User interface theme resource.
	 * @param log Log to write debug messages to.
	 * @return Created user interface.
	 */
	virtual IUi*											Create( core::IContext* context, ITheme* theme, diag::ILog* log ) = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IUIFACTORY_
