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
// Purpose: Logical drop list widget.
//==============================================================================
#ifndef _SYNKRO_UI_DROPLIST_
#define _SYNKRO_UI_DROPLIST_


#include "config.h"
#include "ListWrapperImpl.h"
#include <ui/IDropList.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical drop list widget.
class DropList :
	public ListWrapperImpl<IDropList>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	DropList( BaseUiEx* ui, UInt id, IFrame* parent, IDropList* dropList );

	// IWidget methods.
	void													Activate( Bool activate );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IDropList*												AsDropList() const;

	// IList methods.
	void													SelectItem( UInt index );

	// IDropList methods.
	void													Expand( Bool expand );
	void													Highlight( Bool highlight );
	void													HighlightItem( UInt index );
	void													SetListHeight( UInt height );
	Bool													IsExpanded() const;
	UInt													GetHighlightedItem() const;
	UInt													GetListHeight() const;
	lang::String											GetText() const;

	// BaseWidget methods.
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnKeyPress( Char key );
	UiEvent													OnMouseClick( const lang::Point& location );
	UiEvent													OnMouseMove( const lang::Point& location );
	UiEvent													OnMouseEnter();
	UiEvent													OnMouseLeave();

private:
	IDropList*												_dropList;
};


#include "DropList.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DROPLIST_
