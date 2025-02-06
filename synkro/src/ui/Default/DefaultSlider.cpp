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
// Purpose: Default slider widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultSlider.h"
#include <ui/OrientationConst.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultSlider::DefaultSlider( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const Color& color ) :
	WidgetImpl<ISlider>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_orientation( orientation ),
	_minPosition( minPosition ),
	_maxPosition( maxPosition ),
	_position( minPosition )
{
	// Create slider.
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	_object->SetScissorRect( _scissorRect );

	// Create thumb.
	_object2 = _ui->CreateObject( PrimitiveType::TriangleStrip, IndexType::None, 4, 0, _zOrder-1 );
	_paramColor2 = _object2->GetFragmentParameters()->GetParam( L"p_color" );
	_object2->SetScissorRect( _scissorRect );

	// Perform initialization.
	_effect = _ui->CreateEffect( _object, _object2, _text );
	SetIndicesCentered( _object );
	SetColor( _widgetColors[WidgetState::Normal] );
	SetOrientation( _orientation );
}

void DefaultSlider::Activate( Bool activate )
{
	// Call base implementation.
	WidgetImpl<ISlider>::Activate( activate );

	const WidgetState from = activate ? WidgetState::Normal : WidgetState::Active;
	const WidgetState to = activate ? WidgetState::Active : WidgetState::Normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to] );
}

void DefaultSlider::Enable( Bool enable )
{
	// Call base implementation.
	WidgetImpl<ISlider>::Enable( enable );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state] );
}

void DefaultSlider::SetLocation( const Point& location )
{
	// Call base implementation.
	WidgetImpl<ISlider>::SetLocation( location );

	UpdateRails();
	SetPosition( _position );
}

void DefaultSlider::SetSize( const Size& size )
{
	// Call base implementation.
	WidgetImpl<ISlider>::SetSize( size );

	UpdateSize();
	UpdateRails();
	SetPosition( _position );
}

void DefaultSlider::Highlight( Bool highlight )
{
	const WidgetState normal = _active ? WidgetState::Active : WidgetState::Normal;
	const WidgetState from = highlight ? normal : WidgetState::Hovered;
	const WidgetState to = highlight ? WidgetState::Hovered : normal;
	_effect->Fade( _widgetColors[from], _widgetColors[to] );
}

void DefaultSlider::SetPosition( UInt position )
{
	_position = position;
	const Float percentage = CastFloat(_position-_minPosition)/CastFloat(_maxPosition-_minPosition);
	Float start = 0.0f; Float end = 0.0f; Point pos( _rect.Left, _rect.Top );
	switch ( _orientation )
	{
		case ORIENTATION_HORIZONTAL:
			start = CastFloat(_rect.Left);
			end = CastFloat(_rect.Left+CastInt(_size.Width)-_rectThumb.Width());
			pos.X = start + percentage*(end-start);
			break;

		case ORIENTATION_VERTICAL:
			start = CastFloat(_rect.Top+CastInt(_size.Height)-_rectThumb.Height());
			end = CastFloat(_rect.Top);
			pos.Y = start + percentage*(end-start);
			break;
	}
	UpdateThumb( pos );
}

void DefaultSlider::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	_object2->SetFragmentResources( theme->GetResources() );

	const WidgetState state = _enabled ? WidgetState::Normal : WidgetState::Disabled;
	SetColor( _widgetColors[state], true );
}

void DefaultSlider::SetOrientation( const Orientation& orientation )
{
	_orientation = orientation;
	_ui->Theme()->GetSliderRect( _orientation, _rectRails );
	_ui->Theme()->GetSliderCenter( _orientation, _rectRailsCenter );
	_ui->Theme()->GetSliderThumb( _orientation, _rectThumb );
	UpdateTextureCoordinates();
	UpdateSize();
	UpdateRails();
	SetPosition( _position );
}

void DefaultSlider::UpdateTextureCoordinates()
{
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
	SetTextureCoordinates( _object, _rectRails, _rectRailsCenter );
}

void DefaultSlider::UpdateSize()
{
	switch ( _orientation )
	{
		case ORIENTATION_HORIZONTAL:
			_size.Height = _rectThumb.Height();
			break;

		case ORIENTATION_VERTICAL:
			_size.Width = _rectThumb.Width();
			break;
	}
}

void DefaultSlider::UpdateRails()
{
	Float left = _rect.Left;
	Float top = _rect.Top;
	Float width = CastFloat(_rectRails.Width());
	Float height = CastFloat(_rectRails.Height());
	switch ( _orientation )
	{
		case ORIENTATION_HORIZONTAL:
			top += 0.5f*CastFloat(_rectThumb.Height() - _rectRails.Height());
			width = _size.Width;
			break;

		case ORIENTATION_VERTICAL:
			left += 0.5f*CastFloat(_rectThumb.Width() - _rectRails.Width());
			height = _size.Height;
			break;
	}
	SetPositions( _object, Point(left, top), Size(width, height), _rectRails, _rectRailsCenter );
}

void DefaultSlider::UpdateThumb( const Point& location )
{
	const Float left = CastFloat(location.X);
	const Float top = CastFloat(location.Y);
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
}


} // ui


} // synkro
