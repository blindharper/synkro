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
#ifndef _SYNKRO_UI_PROGRESS_
#define _SYNKRO_UI_PROGRESS_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/IProgress.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical progress widget.
class Progress :
	public WidgetWrapperImpl<IProgress>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Progress( BaseUiEx* ui, UInt id, IFrame* parent, IProgress* widget );

	// IWidget methods.
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IProgress*												AsProgress() const;

	// IProgress methods.
	void													SetMaxValue( UInt value );
	void													SetValue( UInt value );
	void													ShowText( Bool show );
	ProgressType											GetType() const;
	UInt													GetMaxValue() const;
	UInt													GetValue() const;
	Bool													IsTextVisible() const;

private:
	P(IProgress)											_progress;
};


#include "Progress.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_PROGRESS_
