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
// Purpose: Default edit widget implementation.
//==============================================================================
#include "config.h"
#include "DefaultEdit.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultEdit::DefaultEdit( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, const String& text ) :
	WidgetImpl<IEdit>( ui, parent, location, size ),
	_style( EditStyle::Normal ),
	_minValue( 0.0f ),
	_maxValue( 0.0f ),
	_maxLength( 0 ),
	_scrollOffset( 0 )
{
	// Setup text.
	_text = _ui->GetFont()->CreateText( Color::White, Point(), text, Order::High, Order::Highest );
	_text->EnableRect( true );

	// Setup edit.
	_object = _ui->CreateObject( PrimitiveType::TriangleList, IndexType::Short, 16, 54, _zOrder );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	SetColor( Color::White );
	_effect = _ui->CreateEffect( _object, nullptr, _text );
	_object->SetScissorRect( _scissorRect );
	SetIndicesCentered( _object );
	Rect rect; _ui->Theme()->GetEditRect( rect );
	Rect center; _ui->Theme()->GetEditCenter( center );
	SetTextureCoordinates( _object, rect, center );
	Update();
}

void DefaultEdit::Update()
{
	Rect rect; _ui->Theme()->GetEditRect( rect );
	Rect center; _ui->Theme()->GetEditCenter( center );
	SetPositions( _object, _rect.TopLeft(), _size, rect, center );
	_text->SetLocation( Point(_rect.Left+2, _rect.Top+6) );
	_text->SetRect( _visibleRect );
}


} // ui


} // synkro
