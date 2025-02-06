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
// Purpose: Generic user interface frame implementation.
//==============================================================================
#ifndef _SYNKRO_UI_FRAMEIMPL_
#define _SYNKRO_UI_FRAMEIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <ui/IWidget.h>
#include <ui/IFrame.h>


namespace synkro
{


namespace ui
{


// Generic user interface frame implementation.
template <class T>
class FrameImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor and destructor.
	FrameImpl( IFrame* parent, const lang::Point& location, const lang::Size& size );
	virtual ~FrameImpl();

	// IFrame methods.
	virtual void											Show( Bool show );
	virtual void											ShowBorder( Bool show );
	virtual void											SetLocation( const lang::Point& location );
	virtual void											SetSize( const lang::Size& size );
	virtual void											SetAnchor( const Anchor& anchor );
	virtual UInt											GetWidgetCount() const;
	virtual IWidget*										GetWidget( UInt index ) const;
	virtual UInt											GetFrameCount() const;
	virtual IFrame*											GetFrame( UInt index ) const;
	virtual void											GetLocation( lang::Point& location ) const;
	virtual void											GetSize( lang::Size& size ) const;
	virtual void											GetRect( lang::Rect& rect ) const;
	virtual void											GetVisibleRect( lang::Rect& rect ) const;
	virtual Anchor											GetAnchor() const;
	virtual IFrame*											GetParent() const;
	virtual Bool											IsVisible() const;
	virtual Bool											IsBorderVisible() const;
	virtual IAccordion*										AsAccordion() const;

protected:
	lang::Vector<P(IWidget)>								_widgets;
	lang::Vector<P(IFrame)>									_frames;
	IFrame*													_parent;
	lang::Point												_location;
	lang::Size												_size;
	lang::Rect												_rect;
	lang::Rect												_visibleRect;
	Anchor													_anchor;
	Bool													_visible;
	Bool													_borderVisible;

	void													CalcRect();
};


#include "FrameImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_FRAMEIMPL_
