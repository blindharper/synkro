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
// Purpose: Logical list widget.
//==============================================================================
#ifndef _SYNKRO_UI_LIST_
#define _SYNKRO_UI_LIST_


#include "config.h"
#include "ListWrapperImpl.h"
#include <ui/IList.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical list widget.
class List :
	public ListWrapperImpl<IList>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	List( BaseUiEx* ui, UInt id, IFrame* parent, IList* list );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IList*													AsList() const;

	// BaseWidget methods.
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnKeyPress( Char key );
	UiEvent													OnMouseClick( const lang::Point& location );
	UiEvent													OnMouseDoubleClick( const lang::Point& location );
};


#include "List.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_LIST_
