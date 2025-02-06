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
// Purpose: Generic mesh codec implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE MeshCodecImpl<T>::MeshCodecImpl( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager, anim::IAnimationSystem* animationSystem ) :
	_sceneManager( sceneManager ),
	_materialManager( materialManager ),
	_imageManager( imageManager ),
	_animationSystem( animationSystem )
{
}

template <class T>
SYNKRO_INLINE MeshCodecImpl<T>::~MeshCodecImpl()
{
}

template <class T>
SYNKRO_INLINE ITriangleMesh* MeshCodecImpl<T>::Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to load mesh. Bad stream.", L"stream" );

	return nullptr;
}

template <class T>
SYNKRO_INLINE ISkeleton* MeshCodecImpl<T>::Load( io::IStream* stream )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to load skeleton. Bad stream.", L"stream" );

	return nullptr;
}

template <class T>
SYNKRO_INLINE void MeshCodecImpl<T>::Save( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode )
{
	assert( mesh != nullptr );
	assert( stream != nullptr );

	if ( mesh == nullptr )
		throw lang::BadArgumentException( L"Failed to save mesh. Bad mesh.", L"mesh" );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to save mesh. Bad stream.", L"stream" );
}

template <class T>
SYNKRO_INLINE void MeshCodecImpl<T>::Save( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode )
{
	assert( skeleton != nullptr );
	assert( stream != nullptr );

	if ( skeleton == nullptr )
		throw lang::BadArgumentException( L"Failed to save skeleton. Bad skeleton.", L"skeleton" );

	if ( stream == nullptr )
		throw lang::BadArgumentException( L"Failed to save skeleton. Bad stream.", L"stream" );
}
