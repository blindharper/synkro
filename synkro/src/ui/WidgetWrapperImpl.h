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
// Purpose: Generic user interface widget wrapper implementation.
//==============================================================================
#ifndef _SYNKRO_UI_WIDGETWRAPPERIMPL_
#define _SYNKRO_UI_WIDGETWRAPPERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <ui/IWidget.h>
#include <ui/IFrame.h>
#include "BaseFrame.h"
#include "BaseUiEx.h"


namespace synkro
{


namespace ui
{


// Generic user interface widget wrapper implementation.
template <class T>
class WidgetWrapperImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor and destructor.
	WidgetWrapperImpl( BaseUiEx* ui, UInt id, IFrame* parent, IWidget* widget );
	virtual ~WidgetWrapperImpl();

	// IObject methods.
	virtual	UInt											ID() const;

	// IWidget methods.
	virtual	void											Activate( Bool activate );
	virtual	void											Enable( Bool enable );
	virtual	void											Show( Bool show );
	virtual void											SetOpacity( Float opacity );
	virtual void											SetLocation( const lang::Point& location );
	virtual void											SetSize( const lang::Size& size );
	virtual void											SetHotKey( const HotKey& key );
	virtual void											SetAnchor( const Anchor& anchor );
	virtual void											SetZOrder( UInt order );
	virtual void											SetTabOrder( UInt order );
	virtual void											SetData( Pointer data );
	virtual Bool											IsActive() const;
	virtual Bool											IsEnabled() const;
	virtual Bool											IsVisible() const;
	virtual Float											GetOpacity() const;
	virtual void											GetLocation( lang::Point& location ) const;
	virtual void											GetSize( lang::Size& size ) const;
	virtual void											GetRect( lang::Rect& rect ) const;
	virtual void											GetVisibleRect( lang::Rect& rect ) const;
	virtual void											GetHotKey( HotKey& key ) const;
	virtual Anchor											GetAnchor() const;
	virtual UInt											GetZOrder() const;
	virtual UInt											GetTabOrder() const;
	virtual Pointer											GetData() const;
	virtual CursorType										GetCursor() const;
	virtual IFrame*											GetParent() const;
	virtual IAngle*											AsAngle() const;
	virtual IButton*										AsButton() const;
	virtual IDropList*										AsDropList() const;
	virtual IEdit*											AsEdit() const;
	virtual ILabel*											AsLabel() const;
	virtual IList*											AsList() const;
	virtual IOption*										AsOption() const;
	virtual IPicture*										AsPicture() const;
	virtual IProgress*										AsProgress() const;
	virtual ISlider*										AsSlider() const;
	virtual ISwitch*										AsSwitch() const;

protected:
	BaseUiEx*												_ui;
	IFrame*													_parent;
	IWidget*												_widget;
	UInt													_widgetID;
	HotKey													_hotkey;

	Bool													IsHot( const HotKey& key ) const;
};


#include "WidgetWrapperImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_WIDGETWRAPPERIMPL_
