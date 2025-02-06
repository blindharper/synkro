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
// Purpose: Viewport implementation.
//==============================================================================
SYNKRO_INLINE void Viewport::EnableRect( Bool enable )
{
	if ( enable && (_scissor == nullptr) )
	{
		_scissor = _context->GetGraphicsSystem()->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_view->SetScissorRect( enable ? _scissor : nullptr );
}

SYNKRO_INLINE void Viewport::SetLocation( const lang::Point& location )
{
	if ( location != _location )
	{
		_location = location;
		_boundsDirty = true;
	}
}

SYNKRO_INLINE void Viewport::SetSize( const lang::Size& size )
{
	if ( size != _size )
	{
		_size = size;
		_boundsDirty = true;
	}
}

SYNKRO_INLINE void Viewport::SetRect( const lang::Rect& rect )
{
	if ( rect != _rect )
	{
		if ( _scissor != nullptr )
		{
			_scissor->SetBounds( rect.Left, rect.Top, rect.Right, rect.Bottom );
		}
		_rect = rect;
	}
}

SYNKRO_INLINE void Viewport::SetColor( const img::Color& color )
{
	_view->SetBackColor( ToVector(color, GetOpacity()) );
}

SYNKRO_INLINE void Viewport::SetBorderColor( const img::Color& color )
{
	_borderColor = color;
	if ( _border != nullptr )
	{
		_border->SetColor( color );
	}
}

SYNKRO_INLINE void Viewport::SetLabelColor( const img::Color& color )
{
	_labelColor = color;
	if ( _label != nullptr )
	{
		_label->SetColor( color );
	}
}

SYNKRO_INLINE void Viewport::SetLabelText( const lang::String& text )
{
	_labelText = text;
	if ( _label != nullptr )
	{
		lang::String txt = text;
		if ( txt.IsNullOrEmpty() && (_camera != nullptr) )
		{
			txt = _camera->GetName();
		}
		_label->SetText( txt );
	}
}

SYNKRO_INLINE void Viewport::SetOpacity( Float opacity )
{
	img::Color color; GetColor( color );
	opacity = Clamp( opacity, 0.0f, 1.0f );
	_view->SetOverlayColor( ToVector(color, opacity) );
	if ( _label != nullptr )
	{
		_label->SetOpacity( opacity );
	}
	if ( _border != nullptr )
	{
		_border->SetOpacity( opacity );
	}
}

SYNKRO_INLINE void Viewport::SetWireframe( Bool wireframe )
{
	_view->SetFillMode( wireframe ? gfx::FillMode::Wireframe : gfx::FillMode::Solid );
}

SYNKRO_INLINE Bool Viewport::IsRectEnabled() const
{
	return (_scissor != nullptr);
}

SYNKRO_INLINE scene::ICamera* Viewport::GetCamera() const
{
	return _camera;
}

SYNKRO_INLINE ViewMode Viewport::GetViewMode() const
{
	return _viewMode;
}

SYNKRO_INLINE StereoMode Viewport::GetStereoMode() const
{
	return _stereoMode;
}

SYNKRO_INLINE void Viewport::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void Viewport::GetSize( lang::Size& size ) const
{
	Int left; Int top; Int right; Int bottom;
	_view->GetBounds( left, top, right, bottom );
	_size.Width = (right-left);
	_size.Height = (bottom-top);
	size = _size;
}

SYNKRO_INLINE void Viewport::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

SYNKRO_INLINE void Viewport::GetColor( img::Color& color ) const
{
	math::Vector4 vec;
	_view->GetBackColor( vec );
	color = ToColor( vec );
}

SYNKRO_INLINE void Viewport::GetBorderColor( img::Color& color ) const
{
	color = _borderColor;
}

SYNKRO_INLINE void Viewport::GetLabelColor( img::Color& color ) const
{
	color = _labelColor;
}

SYNKRO_INLINE lang::String Viewport::GetLabelText() const
{
	return (_label != nullptr) ? _label->GetText() : _labelText;
}

SYNKRO_INLINE Float Viewport::GetOpacity() const
{
	math::Vector4 vec;
	_view->GetOverlayColor( vec );
	return vec.w;
}

SYNKRO_INLINE Bool Viewport::IsWireframe() const
{
	return (_view->GetFillMode() == gfx::FillMode::Wireframe);
}

SYNKRO_INLINE Bool Viewport::IsBorderVisible() const
{
	return IsVisible() && _borderVisible;
}

SYNKRO_INLINE Bool Viewport::IsLabelVisible() const
{
	return IsVisible() && _labelVisible;
}

SYNKRO_INLINE Bool Viewport::IsVisible() const
{
	return _view->IsVisible();
}

SYNKRO_INLINE IDepthMap* Viewport::GetDepthTarget() const
{
	return _depthTarget;
}

SYNKRO_INLINE UInt Viewport::GetFilterCount() const
{
	return _filters.Size();
}

SYNKRO_INLINE IViewportFilter* Viewport::GetFilter( UInt index ) const
{
	assert( index < _filters.Size() );

	if ( index >= _filters.Size() )
		throw lang::OutOfRangeException( index, _filters.Size() );

	return _filters[index];
}

SYNKRO_INLINE gfx::IRenderView* Viewport::GetView() const
{
	return _view;
}

SYNKRO_INLINE IViewport* Viewport::AsViewport() const
{
	return (IViewport*)this;
}

SYNKRO_INLINE Bool Viewport::Call( IViewportFilter* filter )
{
	if ( filter->IsEnabled() )
	{
		filter->Update();
	}
	return true;
}
