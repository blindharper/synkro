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
// Purpose: Default option widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultOption.h"


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


DefaultOption::DefaultOption( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const String& text, const Color& color ) :
	WidgetImpl<IOption>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_selected( false )
{
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	_text = _ui->GetFont()->CreateText( _textColors[WidgetState::Normal], Point(), text, Order::High, Order::Highest );
	_text->EnableRect( true );
	_effect = _ui->CreateEffect( _object, nullptr, _text );
	_object->SetScissorRect( _scissorRect );
	SetIndicesCentered( _object );
	SetTheme( _ui->Theme() );
	Update();
}

void DefaultOption::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IOption>::Activate( activate );

	const WidgetState from = activate ? WidgetState::Normal : WidgetState::Active;
	const WidgetState to = activate ? WidgetState::Active : WidgetState::Normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultOption::Highlight( Bool highlight )
{
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = highlight ? normal : WidgetState::Hovered;
	const WidgetState to = highlight ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultOption::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_text->SetColor( _textColors[state] );
}

void DefaultOption::Update()
{
	Rect rect; Rect center;
	_ui->Theme()->GetOptionRect( _selected, rect );
	_ui->Theme()->GetOptionCenter( _selected, center );
	SetTextureCoordinates( _object, rect, center );
	SetPositions( _object, _rect.TopLeft(), Size(_size.Height, _size.Height), rect, center );

	Rect rc; GetRect( rc );
	_text->SetRect( rc );
	Size sz; _ui->GetFont()->GetTextSize( _text->GetText(), sz );
	const Int left = _rect.Left + _rect.Height() + 4;
	const Int top = _rect.Top + (CastInt(_size.Height) - CastInt(sz.Height))/2;
	_text->SetLocation( Point(left, top) );
}


} // ui


} // synkro
