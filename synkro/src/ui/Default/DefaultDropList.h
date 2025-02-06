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
// Purpose: Default drop list widget implementation.
//==============================================================================
#ifndef _SYNKRO_UI_DEFAULTDROPLIST_
#define _SYNKRO_UI_DEFAULTDROPLIST_


#include "config.h"
#include <ui/ListImpl.h>
#include <ui/IDropList.h>
#include <ui/BaseThemeWidgetImpl.h>
#include <ui/BaseThemeWidget.h>


namespace synkro
{


namespace ui
{


// Default drop list widget.
class DefaultDropList :
	public ListImpl<IDropList>,
	public BaseThemeWidgetImpl<BaseThemeWidget>
{
public:
	// Constructor.
	DefaultDropList( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size, UInt capacity );
	
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
	UInt													GetItemAt( const lang::Point& location ) const;

	// IDropList methods.
	void													Expand( Bool expand );
	void													Highlight( Bool highlight );
	void													HighlightItem( UInt index );
	void													SetListHeight( UInt height );
	Bool													IsExpanded() const;
	UInt													GetHighlightedItem() const;
	UInt													GetListHeight() const;
	lang::String											GetText() const;

	// BaseThemeWidget methods.
	void													SetTheme( ITheme* theme );
	void													UpdateRect();

private:
	P(over::ITextPool)										_texts;
	lang::Vector<over::IText*>								_texts2;
	P(over::IText)											_arrow;
	P(over::IQuad)											_highlight;
	UInt													_highlightedIndex;
	UInt													_itemHeight;
	UInt													_listHeight;
	Bool													_expanded;
	lang::Size												_collapsedSize;

	void													Update();
	void													UpdateSelection( UInt index );
	void													UpdateHighlight();
};


#include "DefaultDropList.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_DEFAULTDROPLIST_
