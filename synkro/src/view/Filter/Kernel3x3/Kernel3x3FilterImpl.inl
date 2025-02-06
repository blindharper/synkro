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
// Purpose: Generic 3x3-kernel filter implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE Kernel3x3FilterImpl<T>::Kernel3x3FilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program ) :
	ViewportFilterImpl<T>( viewport, animationSystem, program )
{
	// Prepare offsets.
	Int left; Int top; Int right; Int bottom;
	viewport->GetView()->GetBounds( left, top, right, bottom );
	const Float dx = 1.0f / (right-left);
	const Float dy = 1.0f / (bottom-top);
	constexpr UInt SIZE = 3;
	math::Vector2 offsets[SIZE*SIZE];
	for ( UInt i = 0; i < SIZE; ++i )
	{
		for ( UInt j = 0; j < SIZE; ++j )
		{
			offsets[(i*SIZE)+j].x = (CastFloat(i)-1.0f)*dx;
			offsets[(i*SIZE)+j].y = (CastFloat(j)-1.0f)*dy;
		}
	}

	// Pass offsets to the program.
	ProgramParam* paramOffset = _params->GetParam( L"p_offset" );
	_params->Set( paramOffset, offsets, SIZE*SIZE );
}

template <class T>
SYNKRO_INLINE void Kernel3x3FilterImpl<T>::SetPassCount( UInt count )
{
	_filter->SetPassCount( count );
}

template <class T>
SYNKRO_INLINE UInt Kernel3x3FilterImpl<T>::GetPassCount() const
{
	return _filter->GetPassCount();
}

template <class T>
SYNKRO_INLINE IKernel3x3Filter* Kernel3x3FilterImpl<T>::AsKernel3x3() const
{
	return (IKernel3x3Filter*)this;
}

template <class T>
SYNKRO_INLINE IEmbossFilter* Kernel3x3FilterImpl<T>::AsEmboss() const
{
	return nullptr;
}
