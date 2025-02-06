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
// Purpose: Picture widget implementation.
//==============================================================================
#include "config.h"
#include "Picture.h"
#include "Frame.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Picture::Picture( BaseUiEx* ui, IFrame* parent, UInt id, const Point& location, const Size& size, IImage* image ) :
	WidgetImpl<IPicture>( nullptr, ((Frame*)parent)->GetInnerFrame(), location, size ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( this ),
	_widgetID( id )
{
	_tabOrder = none;
	_picture = ui->CreateSprite( image, _rect.TopLeft(), _size );
	((Frame*)parent)->AddWidget( this );
}

void Picture::SetLocation( const Point& location )
{
	// Call base implementation.
	WidgetImpl<IPicture>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
	_picture->SetLocation( _rect.TopLeft() );
}

void Picture::SetSize( const Size& size )
{
	// Call base implementation.
	WidgetImpl<IPicture>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
	_picture->SetSize( size );
}

void Picture::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetImpl<IPicture>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}


} // ui


} // synkro
