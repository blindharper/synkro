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
// Purpose: Logical slider widget.
//==============================================================================
SYNKRO_INLINE void Slider::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<ISlider>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Slider::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<ISlider>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Slider::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<ISlider>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE ISlider* Slider::AsSlider() const
{
	return (ISlider*)this;
}

SYNKRO_INLINE void Slider::Highlight( Bool highlight )
{
	_slider->Highlight( highlight );
}

SYNKRO_INLINE void Slider::SetMinPosition( UInt minPosition )
{
	assert( minPosition <= _slider->GetMaxPosition() );

	if ( minPosition > _slider->GetMaxPosition() )
		throw lang::BadArgumentException( L"Minimum position cannot be greater than the maximum one.", L"minPosition" );

	_slider->SetMinPosition( minPosition );
	AdjustPercentage( 0.0f );
}

SYNKRO_INLINE void Slider::SetMaxPosition( UInt maxPosition )
{
	assert( maxPosition >= _slider->GetMinPosition() );

	if ( maxPosition < _slider->GetMinPosition() )
		throw lang::BadArgumentException( L"Maximum position cannot be less than the minimum one.", L"maxPosition" );

	_slider->SetMaxPosition( maxPosition );
	AdjustPercentage( 0.0f );
}

SYNKRO_INLINE void Slider::SetPosition( UInt position )
{
	assert( position >= _slider->GetMinPosition() );
	assert( position <= _slider->GetMaxPosition() );

	if ( (position < _slider->GetMinPosition()) || (position > _slider->GetMaxPosition()) )
		throw lang::BadArgumentException( L"Position does not fit allowed range.", L"position", lang::String(CastInt(position)) );

	_slider->SetPosition( position );
}

SYNKRO_INLINE Orientation Slider::GetOrientation() const
{
	return _slider->GetOrientation();
}

SYNKRO_INLINE UInt Slider::GetMinPosition() const
{
	return _slider->GetMinPosition();
}

SYNKRO_INLINE UInt Slider::GetMaxPosition() const
{
	return _slider->GetMaxPosition();
}

SYNKRO_INLINE UInt Slider::GetPosition() const
{
	return _slider->GetPosition();
}

SYNKRO_INLINE void Slider::GetThumbSize( lang::Size& size ) const
{
	_slider->GetThumbSize( size );
}

SYNKRO_INLINE UiEvent Slider::OnMouseScroll( Int delta )
{
	return AdjustPercentage( 0.0001f*CastFloat(delta) ) ? UI_EVENT_VALUE_CHANGED : UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Slider::OnMouseEnter()
{
	_slider->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Slider::OnMouseLeave()
{
	_slider->Highlight( false );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Slider::OnMouseDown( const lang::Point& location )
{
	_down = true;
	_moved = false;
	_cursorOrg = _cursor;
	return UI_EVENT_NONE;
}
