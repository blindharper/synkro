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
// Purpose: Generic anchored widget implementation.
//=============================================================================
template <class T, class O>
SYNKRO_INLINE BaseAnchoredObjectImpl<T, O>::BaseAnchoredObjectImpl( O* widget ) :
	_anchoredObject( widget )
{
}

template <class T, class O>
SYNKRO_INLINE BaseAnchoredObjectImpl<T, O>::~BaseAnchoredObjectImpl()
{
}

template <class T, class O>
SYNKRO_INLINE void BaseAnchoredObjectImpl<T, O>::SaveAnchors()
{
	const Anchor anchor = _anchoredObject->GetAnchor();
	if ( anchor.IsSet(Anchor::Bottom) || anchor.IsSet(Anchor::Right) )
	{
		lang::Rect rectParent; _anchoredObject->GetParent()->GetRect( rectParent );
		lang::Rect rect; _anchoredObject->GetRect( rect );
		_edges.X = rectParent.Right - rect.Right;
		_edges.Y = rectParent.Bottom - rect.Bottom;
	}
}

template <class T, class O>
SYNKRO_INLINE void BaseAnchoredObjectImpl<T, O>::RestoreAnchors()
{
	const Anchor anchor = _anchoredObject->GetAnchor();
	if ( anchor.IsSet(Anchor::Bottom) || anchor.IsSet(Anchor::Right) )
	{
		lang::Rect rectParent; _anchoredObject->GetParent()->GetRect( rectParent );
		lang::Rect rect; _anchoredObject->GetRect( rect );
		lang::Size size; _anchoredObject->GetSize( size );
		lang::Point loc; _anchoredObject->GetLocation( loc );
		const lang::Size oldSize = size;
		const lang::Point oldLoc = loc;

		if ( anchor.IsSet(Anchor::Right) )
		{
			const Int delta = rectParent.Right - rect.Right - _edges.X;
			if ( anchor.IsSet(Anchor::Left) )
			{
				size.Width += CastUInt( delta );
			}
			else
			{
				loc.X += delta;
			}
		}

		if ( anchor.IsSet(Anchor::Bottom) )
		{
			const Int delta = rectParent.Bottom - rect.Bottom - _edges.Y;
			if ( anchor.IsSet(Anchor::Top) )
			{
				size.Height += CastUInt( delta );
			}
			else
			{
				loc.Y += delta;
			}
		}

		if ( size != oldSize )
		{
			_anchoredObject->SetSize( size );
		}

		if ( loc != oldLoc )
		{
			_anchoredObject->SetLocation( loc );
		}
	}
}
