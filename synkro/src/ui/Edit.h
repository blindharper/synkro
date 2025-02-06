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
// Purpose: Logical edit widget.
//==============================================================================
#ifndef _SYNKRO_UI_EDIT_
#define _SYNKRO_UI_EDIT_


#include "config.h"
#include "WidgetWrapperImpl.h"
#include <ui/IEdit.h>
#include <over/IText.h>
#include <over/ITextAnimationController.h>
#include <lang/Vector.h>
#include "BaseWidgetImpl.h"
#include "BaseAnchoredObjectImpl.h"


namespace synkro
{


namespace ui
{


// Logical edit widget.
class Edit :
	public WidgetWrapperImpl<IEdit>,
	public BaseWidgetImpl<BaseWidget>,
	public BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>
{
public:
	// Constructor.
	Edit( BaseUiEx* ui, UInt id, IFrame* parent, IEdit* widget, const EditStyle& style );

	// IWidget methods.
	void													Activate( Bool activate );
	void													Enable( Bool enable );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetAnchor( const Anchor& anchor );
	IEdit*													AsEdit() const;

	// IEdit methods.
	void													Clear();
	void													SetText( const lang::String& text );
	void													SetStyle( const EditStyle& style );
	void													SetValue( Float value );
	void													SetMinValue( Float minValue );
	void													SetMaxValue( Float maxValue );
	void													SetMaxLength( UInt maxLength );
	void													SetScrollOffset( UInt offset );
	Bool													IsEmpty() const;
	lang::String											GetText() const;
	EditStyle												GetStyle() const;
	Float													GetValue() const;
	Float													GetMinValue() const;
	Float													GetMaxValue() const;
	UInt													GetMaxLength() const;
	UInt													GetScrollOffset() const;

	// BaseWidget methods.
	UiEvent													OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control );
	UiEvent													OnKeyPress( Char key );
	UiEvent													OnMouseDown( const lang::Point& location );

private:
	P(IEdit)												_edit;
	P(over::IText)											_caret;
	over::ITextAnimationController*							_caretCtrl;
	UInt													_caretPos;
	lang::String											_badChars;
	lang::Vector<Int>										_widths;

	void													SetCaretPosition( UInt pos );
	void													SetCaretPosition( const lang::Point& location );
	void													CalcWidths();
	void													VerifyNumeric() const;
};


#include "Edit.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_EDIT_
