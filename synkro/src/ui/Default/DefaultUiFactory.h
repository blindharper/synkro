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
// Purpose: Default user interface factory.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTUIFACTORY_
#define _SYNKRO_UI_DEFAULTUIFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <core/IContext.h>
#include <ui/IUiFactory.h>
#include <ui/UiType.h>
#include "DefaultUi.h"


namespace synkro
{


namespace ui
{


// Default user interface factory.
SYNKRO_FACTORY_BEGIN( DefaultUiFactory, IUiFactory, Ui, UiType::Default )
	IUi*	Create( core::IContext* context, ITheme* theme, diag::ILog* log ) { return new DefaultUi(context->GetGraphicsSystem(), context->GetAnimationSystem(), context->GetOverlayManager(), theme, log); }
SYNKRO_FACTORY_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTUIFACTORY_
