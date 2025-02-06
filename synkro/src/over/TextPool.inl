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
// Purpose: Text pool implementation.
//==============================================================================
SYNKRO_INLINE void TextPool::Enable( Bool enable )
{
	_pool->Enable( enable );
}

SYNKRO_INLINE void TextPool::EnableRect( Bool enable )
{
	_rectEnabled = enable;
	if ( _rectEnabled && (_scissor == nullptr) )
	{
		_scissor = _context->GetGraphicsSystem()->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_pool->SetScissorRect( _rectEnabled ? _scissor : nullptr );
}

SYNKRO_INLINE void TextPool::SetRect( const lang::Rect& rect )
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

SYNKRO_INLINE Bool TextPool::IsEnabled() const
{
	return _pool->IsEnabled();
}

SYNKRO_INLINE Bool TextPool::IsRectEnabled() const
{
	return _rectEnabled;
}

SYNKRO_INLINE UInt TextPool::GetCapacity() const
{
	return _texts.Capacity();
}

SYNKRO_INLINE UInt TextPool::GetTextCount() const
{
	return _texts.Size();
}

SYNKRO_INLINE IText* TextPool::GetText( UInt index ) const
{
	assert( index < _texts2.Size() );

	if ( index >= _texts2.Size() )
		throw lang::OutOfRangeException( index, _texts2.Size() );

	return _texts2[index];
}

SYNKRO_INLINE void TextPool::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

SYNKRO_INLINE void TextPool::GetOffset( lang::Point& offset ) const
{
	offset = _offset;
}

SYNKRO_INLINE Order TextPool::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order TextPool::GetOrder() const
{
	return _order;
}

SYNKRO_INLINE void TextPool::SetOffset( const lang::Point& offset )
{
	if ( offset != _offset )
	{
		_vertexParams->Set( _paramOffset, _ndc->Convert(math::Vector2(CastFloat(offset.X), CastFloat(offset.Y))) );
		_offset = offset;
	}
}

SYNKRO_INLINE IFont* TextPool::GetFont() const
{
	return dynamic_cast<IFont*>( _font );
}

SYNKRO_INLINE void TextPool::InvalidateTexts()
{
	_dirty = true;
}
