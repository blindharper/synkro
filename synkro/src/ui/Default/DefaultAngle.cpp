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
// Purpose: Default angle widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultAngle.h"
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultAngle::DefaultAngle( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const Color& color ) :
	WidgetImpl<IAngle>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_value( 0.0f )
{
	// Create circle.
	_object = _ui->CreateObject( PrimitiveType::TriangleStrip, IndexType::None, 4, 0, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	_object->SetScissorRect( _scissorRect );

	// Create thumb.
	_object2 = _ui->CreateObject( PrimitiveType::TriangleStrip, IndexType::None, 4, 0, _zOrder-1 );
	_paramColor2 = _object2->GetFragmentParameters()->GetParam( L"p_color" );
	_object2->SetScissorRect( _scissorRect );

	// Create text.
	_text = _ui->GetFont()->CreateText( _textColors[WidgetState::Normal], Point(), L"360°", Order::High, Order::Highest );

	// Perform initialization.
	_ui->Theme()->GetAngleRect( _rectCircle );
	_ui->Theme()->GetAngleThumb( _rectThumb );
	_effect = _ui->CreateEffect( _object, _object2, _text );
	UpdateTextureCoordinates();
	UpdateCircle();
	SetValue( _value );
	SetColor( _widgetColors[WidgetState::Normal] );
}

void DefaultAngle::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<IAngle>::Activate( activate );

	const WidgetState from = activate ? WidgetState::Normal : WidgetState::Active;
	const WidgetState to = activate ? WidgetState::Active : WidgetState::Normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultAngle::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<IAngle>::Enable( enable );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
}

void DefaultAngle::SetLocation( const Point& location )
{
	// Call base implementation.
	WidgetImpl<IAngle>::SetLocation( location );

	UpdateCircle();
	SetValue( _value );
}

void DefaultAngle::Highlight( Bool highlight )
{
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = highlight ? normal : WidgetState::Hovered;
	const WidgetState to = highlight ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to], _textColors[from], _textColors[to] );
}

void DefaultAngle::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	_object2->SetFragmentResources( theme->GetResources() );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
	_text->SetColor( _textColors[state] );
}

void DefaultAngle::UpdateTextureCoordinates()
{
	RectF rectCircle;
	_ui->Theme()->ToRectF( _rectCircle, rectCircle );
	Vector2 coordsCircle[] = 
	{
		Vector2( rectCircle.Left, rectCircle.Top ),
		Vector2( rectCircle.Left, rectCircle.Bottom ),
		Vector2( rectCircle.Right, rectCircle.Top ),
		Vector2( rectCircle.Right, rectCircle.Bottom ),
	};
	SetTextureCoordinates( coordsCircle, 0, 4 );

	RectF rectThumb;
	_ui->Theme()->ToRectF( _rectThumb, rectThumb );
	Vector2 coordsThumb[] = 
	{
		Vector2( rectThumb.Left, rectThumb.Top ),
		Vector2( rectThumb.Left, rectThumb.Bottom ),
		Vector2( rectThumb.Right, rectThumb.Top ),
		Vector2( rectThumb.Right, rectThumb.Bottom ),
	};
	SetTextureCoordinates2( coordsThumb, 0, 4 );
}

void DefaultAngle::UpdateCircle()
{
	const Float left = _rect.Left;
	const Float top = _rect.Top;
	const Float width = CastFloat(_rectCircle.Width());
	const Float height = CastFloat(_rectCircle.Height());
	Vector4 pos[] =
	{
		Vector4( left,			top,		0.0f, 1.0f ),
		Vector4( left,			top+height,	0.0f, 1.0f ),
		Vector4( left+width,	top,		0.0f, 1.0f ),
		Vector4( left+width,	top+height,	0.0f, 1.0f ),
	};
	SetPositions( pos, 0, 4 );
}

void DefaultAngle::UpdateThumb()
{
	const Float orgX = CastFloat((_rect.Width()-_rectThumb.Width())/2) + 1;
	const Float orgY = CastFloat((_rect.Height()-_rectThumb.Height())/2) + 1;

	const Float r = orgX + 1;
	const Float a = Math::ToRadians( _value );
	const Float x = r*Math::Cos( a );
	const Float y = r*Math::Sin( a );

	const Float left = orgX + CastFloat(_rect.Left) + x;
	const Float top = orgY + CastFloat(_rect.Top) - y;
	const Float width = CastFloat(_rectThumb.Width());
	const Float height = CastFloat(_rectThumb.Height());
	Vector4 pos[] =
	{
		Vector4( left,			top,		0.0f, 1.0f ),
		Vector4( left,			top+height,	0.0f, 1.0f ),
		Vector4( left+width,	top,		0.0f, 1.0f ),
		Vector4( left+width,	top+height,	0.0f, 1.0f ),
	};
	SetPositions2( pos, 0, 4 );

	_text->SetLocation( Point(_rect.Left+orgX, _rect.Top+orgY) );
	_text->SetText( String::Format(L"{0}°", Math::Round(_value)) );
	CenterText();
}

void DefaultAngle::CenterText()
{
	Size sz;
	_ui->GetFont()->GetTextSize( _text->GetText(), sz );
	const Int left = _rect.Left + (CastInt(_size.Width) - CastInt(sz.Width))/2 + 1;
	const Int top = _rect.Top + (CastInt(_size.Height) - CastInt(sz.Height))/2 + 1;
	_text->SetLocation( Point(left, top) );
}


} // ui


} // synkro
