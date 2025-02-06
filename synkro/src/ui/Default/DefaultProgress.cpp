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
// Purpose: Default progress widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultProgress.h"


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


DefaultProgress::DefaultProgress( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const ProgressType& type, const Color& color ) :
	WidgetImpl<IProgress>( ui, parent, location, size ),
	BaseThemeWidgetImpl<BaseThemeWidget>( color ),
	_type( type ),
	_value( 0 ),
	_maxValue( 100 ),
	_textVisible( false )
{
	Rect rect; Rect center;

	// Create empty area.
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	_object->SetScissorRect( _scissorRect );
	_ui->Theme()->GetProgressEmptyRect( rect );
	_ui->Theme()->GetProgressEmptyCenter( center );
	SetTextureCoordinates( _object, rect, center );
	SetIndicesCentered( _object );

	// Create filled area.
	_object2 = ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder-1 );
	_paramColor2 = _object2->GetFragmentParameters()->GetParam( L"p_color" );
	_object2->SetScissorRect( _scissorRect );
	_ui->Theme()->GetProgressFilledRect( rect );
	_ui->Theme()->GetProgressFilledCenter( center );
	SetTextureCoordinates( _object2, rect, center );
	SetIndicesCentered( _object2 );

	SetTheme( _ui->Theme() );
	Update();
}

void DefaultProgress::Show( Bool show )
{
	// Call base implementation.
	WidgetImpl<IProgress>::Show( show );

	ShowText( _textVisible );
}

void DefaultProgress::SetMaxValue( UInt value )
{
	if ( value != _maxValue )
	{
		_maxValue = value;
		if ( _value > _maxValue )
		{
			_value = _maxValue;
			PrintValue();
		}
		Update();
	}
}

void DefaultProgress::SetValue( UInt value )
{
	if ( value != _value )
	{
		_value = value;
		PrintValue();
		Update();
	}
}

void DefaultProgress::ShowText( Bool show )
{
	_textVisible = show;
	if ( show && _visible )
	{
		if ( _text == nullptr )
		{
			_text = _ui->GetFont()->CreateText( _textColors[WidgetState::Normal], Point(), String::Empty, Order::High, Order::Highest );
			_text->EnableRect( true );
			SetTheme( _ui->Theme() );
			PrintValue();
			Update();
		}
	}
	else if ( _text != nullptr )
	{
		_text->Show( false );
	}
}

void DefaultProgress::SetTheme( ITheme* theme )
{
	// Call base implementation.
	BaseThemeWidgetImpl<BaseThemeWidget>::SetTheme( theme );

	_object->SetFragmentResources( theme->GetResources() );
	_object2->SetFragmentResources( theme->GetResources() );
	SetColor( _widgetColors[WidgetState::Normal], true );
	if ( _text != nullptr )
	{
		_text->SetColor( _textColors[WidgetState::Normal] );
	}
}

void DefaultProgress::SetType( const ProgressType& type )
{
	_type = type;
}

void DefaultProgress::Update()
{
	Rect rect; Rect center;
	_ui->Theme()->GetProgressEmptyRect( rect );
	_ui->Theme()->GetProgressEmptyCenter( center );
	SetPositions( _object, _rect.TopLeft(), _size, rect, center );

	const UInt width = CastUInt( CastFloat(_value)*CastFloat(_size.Width)/CastFloat(_maxValue) );
	if ( width != 0 )
	{
		_ui->Theme()->GetProgressFilledRect( rect );
		_ui->Theme()->GetProgressFilledCenter( center );
		SetPositions( _object2, _rect.TopLeft(), Size(width, _size.Height), rect, center );
	}
	_object2->Enable( width != 0 );

	if ( _text != nullptr )
	{
		Rect rc; _parent->GetRect( rc );
		_text->SetRect( rc );
		CenterText();
	}
}

void DefaultProgress::CenterText()
{
	Size sz; _ui->GetFont()->GetTextSize( _text->GetText(), sz );
	const Int left = _rect.Left + (CastInt(_size.Width) - CastInt(sz.Width))/2;
	const Int top = _rect.Top + (CastInt(_size.Height) - CastInt(sz.Height))/2;
	_text->SetLocation( Point(left, top) );
}


} // ui


} // synkro
