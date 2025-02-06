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
// Purpose: Default list widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTLIST_
#define _SYNKRO_UI_DEFAULTLIST_


#include "config.h"
#include <ui/ListImpl.h>
#include <ui/IList.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default list widget.
class DefaultList :
	public ListImpl<IList>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultList( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, UInt capacity );
	
	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													Show( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );

	// IList methods.
	void													AddItem( const ListItem& item );
	void													InsertItem( UInt index, const ListItem& item );
	void													SetItemText( UInt index, const lang::String& text );
	void													SelectItem( UInt index );
	void													RemoveItem( UInt index );
	void													Clear();
	void													ClearSelection();
	UInt													GetItemAt( const lang::Point& location ) const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	P(over::ITextPool)										_texts;
	lang::Vector<over::IText*>								_texts2;
	P(over::IQuad)											_highlight;
	UInt													_itemHeight;

	void													Update();
	void													UpdateSelection( const lang::Point& location );
	void													UpdateSelection( UInt index );
	void													UpdateHighlight();
};


#include "DefaultList.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTLIST_
