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
// Purpose: Generic viewport filter implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ViewportFilterImpl<T>::ViewportFilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program ) :
	_viewport( viewport ),
	_animationSystem( animationSystem )
{
	_filter = _viewport->GetView()->GetPostProcessQueue()->CreateObject( program );
	_params = _filter->GetProgram()->GetFragmentStage()->GetParameters()->Clone( _filter->ID(), true );
	_filter->SetFragmentParameters( _params );
	AsBaseViewport( _viewport )->AddFilter( this );
}

template <class T>
SYNKRO_INLINE ViewportFilterImpl<T>::~ViewportFilterImpl()
{
	AsBaseViewport( _viewport )->RemoveFilter( this );
}

template <class T>
SYNKRO_INLINE IViewportFilterAnimationController* ViewportFilterImpl<T>::CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener )
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::Update()
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::Enable( Bool enable )
{
	_filter->Enable( enable );
}

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::EnableRect( Bool enable )
{
	if ( enable && (_scissor == nullptr) )
	{
		_scissor = _viewport->GetView()->GetWindow()->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_filter->SetScissorRect( enable ? _scissor : nullptr );
}

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::SetRect( const lang::Rect& rect )
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

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::SetOrder( UInt order )
{
	_filter->SetOrder( order );
}

template <class T>
SYNKRO_INLINE Bool ViewportFilterImpl<T>::IsEnabled() const
{
	return _filter->IsEnabled();
}

template <class T>
SYNKRO_INLINE Bool ViewportFilterImpl<T>::IsRectEnabled() const
{
	return (_scissor != nullptr);
}

template <class T>
SYNKRO_INLINE void ViewportFilterImpl<T>::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

template <class T>
SYNKRO_INLINE UInt ViewportFilterImpl<T>::GetOrder() const
{
	return _filter->GetOrder();
}

template <class T>
SYNKRO_INLINE ISimpleFilter* ViewportFilterImpl<T>::AsSimple() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IColorFilter* ViewportFilterImpl<T>::AsColor() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IDepthFilter* ViewportFilterImpl<T>::AsDepth() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IKernel3x3Filter* ViewportFilterImpl<T>::AsKernel3x3() const
{
	return nullptr;
}
