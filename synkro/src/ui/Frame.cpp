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
// Purpose: Frame container implementation.
//==============================================================================
#include "config.h"
#include "Frame.h"
#include "BaseAnchoredObject.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Frame::Frame( UInt id, IFrame* parent, IFrame* frame ) :
	FrameImpl<IFrame>( parent, ToLocation(frame), ToSize(frame) ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>( frame ),
	_frame( frame ),
	_frameID( id ),
	_activeWidgets( A(ActiveItem) )
{
	if ( parent != nullptr )
	{
		((Frame*)parent)->AddFrame( this );
	}
	_visible = frame->IsVisible();
	_borderVisible = frame->IsBorderVisible();
}

void Frame::SetSize( const Size& size )
{
	// Call base implementation.
	FrameImpl<IFrame>::SetSize( size );

	_frame->SetSize( size );

	BaseAnchoredObjectImpl<BaseAnchoredObject, IFrame>::SaveAnchors();

	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		AsBaseAnchoredObject( _widgets[i].AsPtr() )->RestoreAnchors();
	}

	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		AsBaseAnchoredObject( _frames[i].AsPtr() )->RestoreAnchors();
	}
}

void Frame::AddWidget( IWidget* widget )
{
	assert( widget != nullptr );

	widget->Show( IsVisible() );
	_widgets.Add( widget );

	if ( widget->GetTabOrder() != none )
	{
		widget->SetTabOrder( _activeWidgets.Size() );
		_activeWidgets.Add( widget );
	}
}

void Frame::OnOptionSelected( BaseOption* option )
{
	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		BaseOption* opt = AsBaseOption( _widgets[i].AsPtr() );
		if ( (opt != nullptr) && (opt != option) )
		{
			opt->Unselect();
		}
	}
}

IWidget* Frame::GetNextWidget( IWidget* widget ) const
{
	// Search widgets.
	UInt index = (_activeWidgets.Size() > 0) ? 0 : none;
	if ( widget != nullptr )
	{
		index = _activeWidgets.IndexOf( widget );
		if ( index != none )
		{
			widget = nullptr;
			++index;
		}
	}
	for ( ; index < _activeWidgets.Size(); ++index )
	{
		IWidget* w = _activeWidgets[index].Widget;
		if ( w->IsEnabled() && w->IsVisible() )
			return w;
	}

	// Search in children frames.
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		BaseFrame* frame = AsBaseFrame( _frames[i].AsPtr() );
		IWidget* next = frame->GetNextWidget( widget );
		if ( next != nullptr )
			return next;
	}

	return nullptr;
}

IWidget* Frame::GetPrevWidget( IWidget* widget ) const
{
	// Search widgets.
	UInt index = (_activeWidgets.Size() > 0) ? _activeWidgets.Size()-1 : none;
	if ( widget != nullptr )
	{
		index = _activeWidgets.IndexOf( widget );
		if ( index == 0 )
		{
			return nullptr;
		}
		else if ( index != none )
		{
			--index;
			IWidget* w = _activeWidgets[index].Widget;
			if ( w->IsEnabled() && w->IsVisible() )
				return w;
		}
		else
		{
			index = _activeWidgets.Size()-1;
		}
	}

	// Search in children frames.
	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		BaseFrame* frame = AsBaseFrame( _frames[_frames.Size()-1-i].AsPtr() );
		IWidget* prev = frame->GetPrevWidget( widget );
		if ( prev != nullptr )
			return prev;
	}

	for ( ; index >= 0; --index )
	{
		IWidget* w = _activeWidgets[index].Widget;
		if ( w->IsEnabled() && w->IsVisible() )
			return w;
	}

	return nullptr;
}


} // ui


} // synkro
