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
// Purpose: Default switch widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultSwitch.h"


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


DefaultSwitch::DefaultSwitch( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const String& text, const Color& color ) :
	WidgetImpl<ISwitch>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_on( false ),
	_highlighted( false )
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

void DefaultSwitch::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<ISwitch>::Activate( activate );

	const WidgetState from = activate ? WidgetState::Normal : WidgetState::Active;
	const WidgetState to = activate ? WidgetState::Active : WidgetState::Normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultSwitch::Highlight( Bool highlight )
{
	_highlighted = highlight;
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = _highlighted ? normal : WidgetState::Hovered;
	const WidgetState to = _highlighted ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultSwitch::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_text->SetColor( _textColors[state] );
}

void DefaultSwitch::Update()
{
	Rect rect; Rect center;
	_ui->Theme()->GetSwitchRect( _on, rect );
	_ui->Theme()->GetSwitchCenter( _on, center );
	SetTextureCoordinates( _object, rect, center );
	SetPositions( _object, _rect.TopLeft(), Size(_size.Height, _size.Height), rect, center );

	Rect rc; GetVisibleRect( rc );
	rc.Right = rc.Left + _size.Width;
	_text->SetRect( rc );
	const Int left = _rect.Left + _rect.Height() + 4;
	_text->SetLocation( Point(left, _rect.Top) );
}


} // ui


} // synkro
