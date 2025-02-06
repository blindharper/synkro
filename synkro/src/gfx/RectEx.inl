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
// Purpose: Logical rectangle implementation.
//==============================================================================
SYNKRO_INLINE void RectEx::Bind()
{
	SynkroProfile( "RectEx.Bind" );

	_rect->Bind();
}

SYNKRO_INLINE void RectEx::SetBounds( Int left, Int top, Int right, Int bottom )
{
	_rect->SetBounds( left, top, right, bottom );
}

SYNKRO_INLINE void RectEx::SetLocation( Int left, Int top )
{
	_rect->SetLocation( left, top );
}

SYNKRO_INLINE void RectEx::SetSize( UInt width, UInt height )
{
	_rect->SetSize( width, height );
}

SYNKRO_INLINE void RectEx::GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const
{
	_rect->GetBounds( left, top, right, bottom );
}

SYNKRO_INLINE void RectEx::GetLocation( Int& left, Int& top ) const
{
	_rect->GetLocation( left, top );
}

SYNKRO_INLINE void RectEx::GetSize( UInt& width, UInt& height ) const
{
	_rect->GetSize( width, height );
}
