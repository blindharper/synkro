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
// Purpose: Default button widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultButton.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultButton::DefaultButton( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const String& text, const Color& color ) :
	WidgetImpl<IButton>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_pressed( false ),
	_highlighted( false )
{
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	_text = _ui->GetFont()->CreateText( _textColors[WidgetState::Normal], Point(), text, Order::High, Order::Highest );
	_text->EnableRect( true );
	_effect = _ui->CreateEffect( _object, nullptr, _text );
	_object->SetScissorRect( _scissorRect );
	SetTheme( _ui->Theme() );
	SetIndicesCentered( _object );
	Rect rect; Rect center;
	_ui->Theme()->GetButtonRect( rect );
	_ui->Theme()->GetButtonCenter( center );
	SetTextureCoordinates( _object, rect, center );
	Update( 0 );
}

void DefaultButton::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IButton>::Activate( activate );

	const WidgetState from = activate ? WidgetState::Normal : WidgetState::Active;
	const WidgetState to = activate ? WidgetState::Active : WidgetState::Normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultButton::Highlight( Bool highlight )
{
	_highlighted = highlight;
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = _highlighted ? normal : WidgetState::Hovered;
	const WidgetState to = _highlighted ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultButton::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_text->SetColor( _textColors[state] );
}

void DefaultButton::Update( Int delta )
{
	Rect rect; Rect center;
	_ui->Theme()->GetButtonRect( rect );
	_ui->Theme()->GetButtonCenter( center );
	SetPositions( _object, Point(_rect.Left+delta, _rect.Top+delta), _size, rect, center );
	Rect rectText( _visibleRect );
	rectText.Offset( delta, delta );
	rectText.Deflate( 1, 1 );
	_text->SetRect( rectText );
	CenterText( delta );
}

void DefaultButton::CenterText( Int delta )
{
	Size sz;
	_ui->GetFont()->GetTextSize( _text->GetText(), sz );
	const Int left = _rect.Left + delta + (CastInt(_size.Width) - CastInt(sz.Width))/2;
	const Int top = _rect.Top + delta + (CastInt(_size.Height) - CastInt(sz.Height))/2;
	_text->SetLocation( Point(left, top) );
}


} // ui


} // synkro
