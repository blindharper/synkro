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
#include "config.h"
#include "Edit.h"
#include "EditStyleConst.h"
#include <input/KeyConst.h>
#include <anim/IKeyframedBoolTrack.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Edit::Edit( BaseUiEx* ui, UInt id, IFrame* parent, IEdit* widget, const EditStyle& style ) :
	WidgetWrapperImpl<IEdit>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_edit( widget ),
	_caretPos( 0 ),
	_badChars( L"\r\n\t\b`" ),
	_widths( A(Int) )
{
	// Setup caret.
	Size sz; _ui->GetFont()->GetTextSize( _edit->GetText(), sz );
	Rect rect; _edit->GetRect( rect );
	_caret = _ui->GetFont()->CreateText( Color::White, Point(rect.Left+sz.Width, rect.Top+4), L"|", Order::High, Order::Highest );
	_caret->EnableRect( true );
	_caretCtrl =  _caret->CreateAnimationController( nullptr, nullptr );
	_caretCtrl->SetMode( AnimationMode::Loop );
	IKeyframedBoolTrack* track = _caretCtrl->CreateVisibilityTrack();
	track->SetKey( 0.0, false );
	track->SetKey( 0.5, true );
	track->SetKey( 1.0, false );
	_caretCtrl->Start( false );
	_caret->Show( false );
	CalcWidths();
	SetCaretPosition( _edit->GetText().Length() );
	SetStyle( style );
}

void Edit::Activate(Bool activate)
{
	// Call base implementation.
	WidgetWrapperImpl<IEdit>::Activate( activate );

	if ( activate )
	{
		Key keys[] = { Key::Home, Key::Numpad7, Key::End, Key::Numpad1, Key::Left, Key::Right, Key::Delete, Key::Decimal, Key::Back };
		_ui->ListenKeyDown( keys, SizeOf(keys), true );
		_ui->ListenKeyPress();
	}

	_caretCtrl->Start( activate );
	_caret->Show( activate );
}

void Edit::SetStyle( const EditStyle& style )
{
	_edit->SetStyle( style );
	String text = _edit->GetText();
	
	switch ( style )
	{
		case EDIT_STYLE_UPPER:
			_edit->SetText( text.ToUpper() );
			CalcWidths();
			break;

		case EDIT_STYLE_LOWER:
			_edit->SetText( text.ToLower() );
			CalcWidths();
			break;

		case EDIT_STYLE_INTEGER:
			if ( !text.IsInteger() )
				_edit->SetText( String::Empty );
			break;

		case EDIT_STYLE_DECIMAL:
			if ( !text.IsDecimal() )
				_edit->SetText( String::Empty );
			break;

		case EDIT_STYLE_HEXADECIMAL:
			if ( !text.IsHexadecimal() )
				_edit->SetText( String::Empty );
			break;
	}

	if ( _edit->GetText().IsEmpty() )
	{
		CalcWidths();
		SetCaretPosition( 0 );
	}
}

void Edit::SetValue( Float value )
{
	String text;
	const Float minValue = GetMinValue();
	const Float maxValue = GetMaxValue();
	if ( (minValue != 0.0f) && (maxValue != 0.0f) )
	{
		value = Clamp( value, minValue, maxValue );
	}
	switch ( _edit->GetStyle() )
	{
		case EDIT_STYLE_DECIMAL:
			text = String( value );

		case EDIT_STYLE_INTEGER:
		case EDIT_STYLE_HEXADECIMAL:
			text = String( CastInt(value) );
	}
	_edit->SetText( text );
}

void Edit::SetMinValue( Float minValue )
{
	if ( GetValue() < minValue )
	{
		SetValue( minValue );
	}
	_edit->SetMinValue( minValue );
}

void Edit::SetMaxValue( Float maxValue )
{
	if ( GetValue() > maxValue )
	{
		SetValue( maxValue );
	}
	_edit->SetMaxValue( maxValue );
}

Float Edit::GetValue() const
{
	VerifyNumeric();
	
	String text = _edit->GetText();
	switch ( _edit->GetStyle() )
	{
		case EDIT_STYLE_DECIMAL:
			return text.ToDecimal();

		case EDIT_STYLE_INTEGER:
		case EDIT_STYLE_HEXADECIMAL:
			return CastFloat(text.ToInteger());
	}
	return 0.0f;
}

UiEvent Edit::OnKeyDown( Double deltaTime, const Key& key, Bool alt, Bool shift, Bool control )
{
	String text = _edit->GetText();
	String start;
	String end;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			SetCaretPosition( 0 );
			break;

		case KEY_END:
		case KEY_NUMPAD1:
			SetCaretPosition( text.Length() );
			break;

		case KEY_LEFT:
			if ( _caretPos > 0 )
				SetCaretPosition( _caretPos-1 );
			break;

		case KEY_RIGHT:
			if ( _caretPos < text.Length() )
				SetCaretPosition( _caretPos+1 );
			break;

		case KEY_DELETE:
		case KEY_DECIMAL:
			start = text.Substring( 0, _caretPos );
			end = text.Substring( _caretPos+1 );
			SetText( start + end );
			SetCaretPosition( _caretPos );
			return UI_EVENT_VALUE_CHANGED;

		case KEY_BACK:
			if ( _caretPos > 0 )
			{
				start = text.Substring( 0, _caretPos-1 );
				end = text.Substring( _caretPos );
				SetText( start + end );
				SetCaretPosition( _caretPos-1 );
				return UI_EVENT_VALUE_CHANGED;
			}
			break;
	}

	return UI_EVENT_NONE;
}

UiEvent Edit::OnKeyPress( Char key )
{
	if ( _badChars.Contains(key) )
		return UI_EVENT_NONE;

	String ch( key );
	ch.MakePermanent();
	String text = _edit->GetText();
	String middle = String::Empty;

	// Check length limit.
	const UInt maxLength = _edit->GetMaxLength();
	if ( (maxLength > 0) && (text.Length() == maxLength) )
		return UI_EVENT_NONE;

	String start = text.Substring( 0, _caretPos );
	String end = text.Substring( _caretPos );

	switch ( _edit->GetStyle() )
	{
		case EDIT_STYLE_UPPER:
			middle = ch.ToUpper();
			break;

		case EDIT_STYLE_LOWER:
			middle = ch.ToLower();
			break;

		case EDIT_STYLE_INTEGER:
			if ( String(start+ch+end).IsInteger() || ((key == L'-') && text.IsEmpty()) )
				middle = ch;
			break;

		case EDIT_STYLE_DECIMAL:
			if ( String(start+ch+end).IsDecimal() || ((key == L'-') && text.IsEmpty()) )
				middle = ch;
			break;

		case EDIT_STYLE_HEXADECIMAL:
			if ( ch.IsHexadecimal() )
				middle = ch;
			break;

		default:
			middle = ch;
			break;
	}

	if ( !middle.IsEmpty() )
	{
		SetText( start + middle + end );
		SetCaretPosition( _caretPos+1 );
	}

	return UI_EVENT_VALUE_CHANGED;
}

void Edit::SetCaretPosition( UInt pos )
{
	_caretPos = pos;
	Rect rect; _edit->GetRect( rect );
	const Int width = rect.Width()-3;
	const Int length = _widths.LastValue();
	Int scrollOffset = CastInt( _edit->GetScrollOffset() );
	const Int visibleLength = length - scrollOffset;
	Int delta = _widths[_caretPos] - scrollOffset;
	if ( delta < 0 )
	{
		scrollOffset += delta;
	}
	else if ( delta >= width )
	{
		scrollOffset += (delta - width);
	}
	else if ( length <= width )
	{
		scrollOffset = 0;
	}
	else if ( visibleLength < width )
	{
		scrollOffset += (visibleLength - width);
	}
	else if ( scrollOffset > 0 )
	{
		scrollOffset = (length - width);
	}
	delta = _widths[_caretPos] - scrollOffset;
	_edit->SetScrollOffset( scrollOffset );
	_caret->SetLocation( Point(rect.Left+delta, rect.Top+4) );
	_edit->GetVisibleRect( rect );
	_caret->SetRect( rect );
}

void Edit::SetCaretPosition( const Point& location )
{
	Rect rect; _edit->GetRect( rect );
	const Int scrollOffset = CastInt( _edit->GetScrollOffset() );
	const Int x = location.X - rect.Left + scrollOffset;
	_caretPos = _widths.Size()-1;
	for ( UInt i = 0; i < _widths.Size(); ++i )
	{
		if ( x < _widths[i] )
		{
			_caretPos = i-1;
			break;
		}
	}
	const Int delta = _widths[_caretPos] - scrollOffset;
	_caret->SetLocation( Point(rect.Left+delta, rect.Top+4) );
	_edit->GetVisibleRect( rect );
	_caret->SetRect( rect );
}

void Edit::CalcWidths()
{
	String text; Size sz;
	String str = _edit->GetText();
	switch ( _edit->GetStyle() )
	{
		case EDIT_STYLE_UPPER:
			str = str.ToUpper();
			break;

		case EDIT_STYLE_LOWER:
			str = str.ToLower();
			break;
	}
	UInt len = _edit->GetText().Length();
	_widths.SetSize( len+1, 0 );
	for ( UInt i = 0; i < len; ++i )
	{
		text = text.Append( str[i] );
		_ui->GetFont()->GetTextSize( text, sz );
		_widths[i+1] = sz.Width;
	}
}

void Edit::VerifyNumeric() const
{
	switch ( _edit->GetStyle() )
	{
		case EDIT_STYLE_INTEGER:
		case EDIT_STYLE_DECIMAL:
		case EDIT_STYLE_HEXADECIMAL:
			break;

		default:
			throw InvalidOperationException( L"Edit is not numeric." );
	}
}


} // ui


} // synkro
