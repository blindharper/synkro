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
// Purpose: Default frame container implementation.
//==============================================================================
#include "config.h"
#include "DefaultFrame.h"
#include <ui/BaseThemeWidget.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector4Stream.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


DefaultFrame::DefaultFrame( BaseUi* ui, IFrame* parent, const Point& location, const Size& size, Bool showBorder ) :
	FrameImpl<IFrame>( parent, location, size ),
	_ui( ui )
{
	if ( parent != nullptr )
	{
		AsBaseFrame( parent )->AddFrame( this );
	}

	if ( showBorder )
	{
		ShowBorder( true );
	}
}

void DefaultFrame::Show( Bool show )
{
	// Call base implementation.
	FrameImpl<IFrame>::Show( show );

	const Bool borderVisible = _borderVisible;
	ShowBorder( _borderVisible && show );
	_borderVisible = borderVisible;
}

void DefaultFrame::ShowBorder( Bool show )
{
	// Call base implementation.
	FrameImpl<IFrame>::ShowBorder( show );

	if ( _borderVisible )
	{
		if ( _border == nullptr )
		{
			_border = _ui->CreateLineObject( PrimitiveType::LineStrip, 5, Order::GetValue(Order::Highest, Order::AboveNormal) );
			_paramColor = _border->GetFragmentParameters()->GetParam( L"p_color" );
			_border->GetFragmentParameters()->Set( _paramColor, ToVector(Color::Black) );
			if ( _parent != nullptr )
			{
				Rect rect; _parent->GetRect( rect );
				_scissorRect = _ui->CreateScissorRect( rect.Left, rect.Top, rect.Right, rect.Bottom );
				_border->SetScissorRect( _scissorRect );
			}
			Update();
		}
	}

	if ( _border != nullptr )
	{
		_border->Enable( _borderVisible );
	}
}

void DefaultFrame::SetTheme( ITheme* theme )
{
	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		AsBaseThemeWidget( _widgets[i].AsPtr() )->SetTheme( theme );
	}

	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		((DefaultFrame*)_frames[i].AsPtr())->SetTheme( theme );
	}
}

void DefaultFrame::UpdateRect()
{
	Update();

	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		AsBaseThemeWidget( _widgets[i].AsPtr() )->UpdateRect();
	}

	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		((DefaultFrame*)_frames[i].AsPtr())->UpdateRect();
	}
}

void DefaultFrame::Update()
{
	const Rect rc = _rect;
	const Float left = CastFloat(rc.Left);
	const Float top = CastFloat(rc.Top);
	const Float width = CastFloat(rc.Width());
	const Float height = CastFloat(rc.Height());
	Vector4 pos[] =
	{
		Vector4( left,			top,		0.0f, 1.0f ),
		Vector4( left+width,	top,		0.0f, 1.0f ),
		Vector4( left+width,	top+height,	0.0f, 1.0f ),
		Vector4( left,			top+height,	0.0f, 1.0f ),
		Vector4( left,			top-1.0f,	0.0f, 1.0f ),
	};
	if ( _border != nullptr )
	{
		P(IVector4Stream) stream = (IVector4Stream*)_border->GetData()->GetVertexStream( DataStream::Position2D, 0 );
		if ( stream->Open(OpenMode::Write) )
		{
			stream->Write( pos, 5 );
			stream->Close();
		}
	}

	if ( _scissorRect != nullptr )
	{
		Rect rect; _parent->GetRect( rect );
		_scissorRect->SetBounds( rect.Left, rect.Top, rect.Right, rect.Bottom );
	}
}


} // ui


} // synkro
