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
// Purpose: Generic sound codec implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SoundCodecImpl<T>::SoundCodecImpl()
{
}

template <class T>
SYNKRO_INLINE SoundCodecImpl<T>::~SoundCodecImpl()
{
}

template <class T>
SYNKRO_INLINE Double SoundCodecImpl<T>::Load( SoundCodecContext* context, SoundFormat& format )
{
	assert( context != nullptr );
	assert( context->Stream != nullptr );

	if ( (context == nullptr) || (context->Stream == nullptr) )
		throw lang::BadArgumentException( L"Failed to load sound. Bad decoding context.", L"context" );

	return 0.0;
}

template <class T>
SYNKRO_INLINE void SoundCodecImpl<T>::Save( SoundCodecContext* context, const SoundFormat& format )
{
	assert( context != nullptr );
	assert( context->Stream != nullptr );

	if ( (context == nullptr) || (context->Stream == nullptr) )
		throw lang::BadArgumentException( L"Failed to save sound. Bad encoding context.", L"context" );
}
