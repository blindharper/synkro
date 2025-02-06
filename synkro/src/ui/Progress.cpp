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
// Purpose: Logical progress widget.
//==============================================================================
#include "config.h"
#include "Progress.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Progress::Progress( BaseUiEx* ui, UInt id, IFrame* parent, IProgress* widget ) :
	WidgetWrapperImpl<IProgress>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_progress( widget )
{
}


} // ui


} // synkro
