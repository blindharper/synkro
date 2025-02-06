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
// Purpose: Logical angle widget.
//==============================================================================
SYNKRO_INLINE void Angle::SetLocation( const lang::Point& location )
{
	// Call base implementation.
	WidgetWrapperImpl<IAngle>::SetLocation( location );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Angle::SetSize( const lang::Size& size )
{
	// Call base implementation.
	WidgetWrapperImpl<IAngle>::SetSize( size );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE void Angle::SetAnchor( const Anchor& anchor )
{
	// Call base implementation.
	WidgetWrapperImpl<IAngle>::SetAnchor( anchor );
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>::SaveAnchors();
}

SYNKRO_INLINE IAngle* Angle::AsAngle() const
{
	return (IAngle*)this;
}

SYNKRO_INLINE void Angle::Highlight( Bool highlight )
{
	_angle->Highlight( highlight );
}

SYNKRO_INLINE void Angle::SetValue( Float value )
{
	_angle->SetValue( Clamp(value, 0.0f, 360.0f) );
}

SYNKRO_INLINE Float Angle::GetValue() const
{
	return _angle->GetValue();
}

SYNKRO_INLINE UiEvent Angle::OnMouseScroll( Int delta )
{
	AdjustValue( 0.01f*CastFloat(delta) );
	return UI_EVENT_VALUE_CHANGED;
}

SYNKRO_INLINE UiEvent Angle::OnMouseEnter()
{
	_angle->Highlight( true );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Angle::OnMouseLeave()
{
	_angle->Highlight( false );
	return UI_EVENT_NONE;
}

SYNKRO_INLINE UiEvent Angle::OnMouseDown( const lang::Point& location )
{
	_down = true;
	_moved = false;
	_cursorOrg = _cursor;
	return UI_EVENT_NONE;
}
