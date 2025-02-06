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
// Purpose: Generic visual material implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE VisualMaterialImpl<T>::VisualMaterialImpl( core::IContext* context ) :
	_context( context ),
	_colored( false )
{
}

template <class T>
SYNKRO_INLINE VisualMaterialImpl<T>::~VisualMaterialImpl()
{
}

template <class T>
SYNKRO_INLINE IVisualMaterialAnimationController* VisualMaterialImpl<T>::CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener )
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE scene::ITriangleSet* VisualMaterialImpl<T>::CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return CreateTriangleSet( gfx::PrimitiveType::TriangleList, mesh, index, vertexCount, indexCount, adjacency );
}

template <class T>
SYNKRO_INLINE scene::ITriangleSet* VisualMaterialImpl<T>::CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return CreateTriangleSet( gfx::PrimitiveType::TriangleStrip, mesh, index, vertexCount, indexCount, adjacency );
}

template <class T>
SYNKRO_INLINE void VisualMaterialImpl<T>::SetColored( Bool colored )
{
	_colored = colored;
}

template <class T>
SYNKRO_INLINE Bool VisualMaterialImpl<T>::IsColored() const
{
	return _colored;
}

template <class T>
SYNKRO_INLINE UInt VisualMaterialImpl<T>::GetSubsetCount() const
{
	return 1;
}

template <class T>
SYNKRO_INLINE ISimpleMaterial* VisualMaterialImpl<T>::AsSimple() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IMultiMaterial* VisualMaterialImpl<T>::AsMulti() const
{
	return nullptr;
}
