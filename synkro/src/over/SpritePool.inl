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
// Purpose: Sprite pool implementation.
//==============================================================================
SYNKRO_INLINE void SpritePool::Enable( Bool enable )
{
	_pool->Enable( enable );
}

SYNKRO_INLINE void SpritePool::EnableRect( Bool enable )
{
	_rectEnabled = enable;
	if ( _rectEnabled && (_scissor == nullptr) )
	{
		_scissor = _context->GetGraphicsSystem()->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_pool->SetScissorRect( _rectEnabled ? _scissor : nullptr );
}

SYNKRO_INLINE void SpritePool::SetRect( const lang::Rect& rect )
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

SYNKRO_INLINE Bool SpritePool::IsEnabled() const
{
	return _pool->IsEnabled();
}

SYNKRO_INLINE Bool SpritePool::IsRectEnabled() const
{
	return _rectEnabled;
}

SYNKRO_INLINE UInt SpritePool::GetCapacity() const
{
	return _sprites.Capacity();
}

SYNKRO_INLINE UInt SpritePool::GetSpriteCount() const
{
	return _sprites.Size();
}

SYNKRO_INLINE ISprite* SpritePool::GetSprite( UInt index ) const
{
	assert( index < _sprites.Size() );

	if ( index >= _sprites.Size() )
		throw lang::OutOfRangeException( index, _sprites.Size() );

	return (ISprite*)(PoolSprite*)_sprites[index];
}

SYNKRO_INLINE void SpritePool::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

SYNKRO_INLINE Order SpritePool::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order SpritePool::GetOrder() const
{
	return _order;
}

SYNKRO_INLINE img::IImage* SpritePool::GetImage() const
{
	return _image;
}

SYNKRO_INLINE void SpritePool::InvalidateSprites()
{
	_dirty = true;
}

SYNKRO_INLINE void SpritePool::SetOpacity( gfx::IVector4Stream* stream, UInt idx, Float opacity )
{
	stream->SetPosition( idx*6 );
	stream->Set( ToVector(img::Color::White, opacity), 6 );
}
