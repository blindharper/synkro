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
// Purpose: Frame container implementation.
//==============================================================================
#ifndef _SYNKRO_UI_FRAME_
#define _SYNKRO_UI_FRAME_


#include "config.h"
#include "FrameImpl.h"
#include "BaseWidget.h"
#include "BaseFrame.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Frame widget implementation.
class Frame :
	public FrameImpl<IFrame>,
	public BaseFrame,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>
{
public:
	// Constructor.
	Frame( UInt id, IFrame* parent, IFrame* frame );

	// IObject methods.
	UInt													ID() const;

	// IFrame methods.
	void													Show( Bool show );
	void													ShowBorder( Bool show );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );

	// BaseFrame methods.
	void													SetTheme( ITheme* theme );
	void													AddWidget( IWidget* widget );
	void													AddFrame( IFrame* frame );
	void													OnOptionSelected( BaseOption* option );
	void													UpdateTabOrder();
	IWidget*												GetNextWidget( IWidget* widget ) const;
	IWidget*												GetPrevWidget( IWidget* widget ) const;
	IFrame*													GetInnerFrame() const;

private:
	struct ActiveItem
	{
		ActiveItem( IWidget* widget ) :
			Widget( widget )
		{
		}

		ActiveItem()
		{
		}

		Bool operator<( const ActiveItem& other ) const
		{
			return this->Widget->GetTabOrder() < other.Widget->GetTabOrder();
		}

		Bool operator==( const ActiveItem& other ) const
		{
			return this->Widget == other.Widget;
		}

		IWidget*	Widget;
	};

	P(IFrame)												_frame;
	UInt													_frameID;
	lang::Vector<ActiveItem>								_activeWidgets;

	lang::Point												ToLocation( IFrame* frame ) const;
	lang::Size												ToSize( IFrame* frame ) const;
};


#include "Frame.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_FRAME_
