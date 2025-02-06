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
// Purpose: Implements generic animation codec.
//==============================================================================
template <class T>
SYNKRO_INLINE AnimationCodecImpl<T>::AnimationCodecImpl( core::IContext* context ) :
	_context( context )
{
}

template <class T>
SYNKRO_INLINE AnimationCodecImpl<T>::~AnimationCodecImpl()
{
}

template <class T>
SYNKRO_INLINE IAnimationSet* AnimationCodecImpl<T>::Load( io::IStream* stream )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to load animation. Bad stream.", L"stream" );

	return nullptr;
}

template <class T>
SYNKRO_INLINE void AnimationCodecImpl<T>::Save( const IAnimationSet* animation, io::IStream* stream )
{
	assert( stream != nullptr );
	assert( animation != nullptr );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to save animation. Bad stream.", L"stream" );

	if ( animation == nullptr )
		throw lang::BadArgumentException( L"Failed to save animation. Bad animation set.", L"animation" );
}
