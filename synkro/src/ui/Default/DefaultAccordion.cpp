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
// Purpose: Default accordion container implementation.
//==============================================================================
#include "config.h"
#include "DefaultAccordion.h"
#include "DefaultButton.h"
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


DefaultAccordion::DefaultAccordion( BaseUi* ui, IFrame* parent, const Point& location, const Size& size ) :
	FrameImpl<IAccordion>( parent, location, size ),
	_ui( ui )
{
	if ( parent != nullptr )
	{
		AsBaseFrame( parent )->AddFrame( this );
	}
	ShowBorder( true );
}

void DefaultAccordion::Show( Bool show )
{
	// Call base implementation.
	FrameImpl<IAccordion>::Show( show );

	const Bool borderVisible = _borderVisible;
	ShowBorder( _borderVisible && show );
	_borderVisible = borderVisible;
}

void DefaultAccordion::ShowBorder( Bool show )
{
	// Call base implementation.
	FrameImpl<IAccordion>::ShowBorder( show );

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

void DefaultAccordion::SetLocation( const Point& location )
{
	// Call base implementation.
	FrameImpl<IAccordion>::SetLocation( location );

	Arrange();
	UpdateRect();
}

void DefaultAccordion::SetSize( const Size& size )
{
	// Call base implementation.
	FrameImpl<IAccordion>::SetSize( size );

	Arrange();
	UpdateRect();
}

IFrame* DefaultAccordion::CreatePanel( const String& text )
{
	UInt topHeader = BORDER_SIZE;
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		UInt panelHeight = 0;
		if ( IsPanelExpanded(i) )
		{
			Size sz;
			_frames[i]->GetSize( sz );
			panelHeight = sz.Height;
		}
		topHeader += HEADER_HEIGHT + panelHeight + BORDER_SIZE;
	}
	const UInt topPanel = topHeader + HEADER_HEIGHT;

	IButton* header = new DefaultButton( _ui, this, Point(BORDER_SIZE-1, topHeader), Size(_size.Width-2*BORDER_SIZE+1, HEADER_HEIGHT), String::Format(L"►{0}", text), Color::Transparent );
	_widgets.Add( header );

	IFrame* panel = new DefaultFrame( _ui, this, Point(BORDER_SIZE, topPanel), Size(_size.Width-2*BORDER_SIZE, 0), true );
	panel->Show( false );
	_frames.Add( panel );

	return panel;
}

void DefaultAccordion::ExpandPanel( UInt index, Bool expand )
{
	IButton* header = _widgets[index]->AsButton();

	// Update header caption.
	String caption = header->GetText().Substring( 1 );
	header->SetText( String::Format(L"{0}{1}", expand ? L"▼" : L"►", caption) );

	// Calculate panel height based on its widgets.
	if ( expand )
	{
		Int height = 0;
		IFrame* panel = _frames[index];
		for ( UInt i = 0; i < panel->GetWidgetCount(); ++i )
		{
			IWidget* widget = panel->GetWidget( i );
			Point location; widget->GetLocation( location );
			Size size; widget->GetSize( size );
			Int top = location.Y + CastInt(size.Height);
			if ( top > height )
			{
				height = top;
			}
		}
		if ( height > 0 )
		{
			panel->SetSize( Size(_size.Width-2*BORDER_SIZE, CastUInt(height+BORDER_SIZE)) );
		}
	}

	// Update panel.
	_frames[index]->Show( expand );
	Arrange();
}

void DefaultAccordion::SetTheme( ITheme* theme )
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

void DefaultAccordion::AddWidget( IWidget* widget )
{
	// Do nothing.
}

void DefaultAccordion::AddFrame( IFrame* frame )
{
	// Do nothing.
}

void DefaultAccordion::OnOptionSelected( BaseOption* option )
{
	// Do nothing.
}

void DefaultAccordion::UpdateTabOrder()
{
	// Do nothing.
}

IWidget* DefaultAccordion::GetNextWidget( IWidget* widget ) const
{
	return nullptr;
}

IWidget* DefaultAccordion::GetPrevWidget( IWidget* widget ) const
{
	return nullptr;
}

IFrame* DefaultAccordion::GetInnerFrame() const
{
	return nullptr;
}

void DefaultAccordion::UpdateRect()
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

void DefaultAccordion::Arrange()
{
	UInt topHeader = BORDER_SIZE;
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		UInt panelHeight = 0;
		if ( (i > 0) && IsPanelExpanded(i-1) )
		{
			Size sz;
			_frames[i-1]->GetSize( sz );
			panelHeight = sz.Height;
		}

		if ( i > 0 )
		{
			topHeader += HEADER_HEIGHT + panelHeight + BORDER_SIZE;
		}
		_widgets[i]->SetLocation( Point(BORDER_SIZE-1, topHeader) );
		const UInt topPanel = topHeader + HEADER_HEIGHT;
		_frames[i]->SetLocation( Point(BORDER_SIZE, topPanel) );
	}
}

void DefaultAccordion::Update()
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
