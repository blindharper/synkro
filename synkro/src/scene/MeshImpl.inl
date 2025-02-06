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
// Purpose: Generic mesh implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE MeshImpl<T>::MeshImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize ) :
	NodeImpl<T>( scene, context, name, visualize ),
	_subsets( A(SubsetDesc) ),
	_visible( true )
{
}

template <class T>
SYNKRO_INLINE MeshImpl<T>::~MeshImpl()
{
}

template <class T>
SYNKRO_INLINE IMesh* MeshImpl<T>::AsMesh() const
{
	return (IMesh*)this;
}

template <class T>
SYNKRO_INLINE void MeshImpl<T>::Show( Bool show )
{
	_visible = show;
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->Show( _visible );
	}
}

template <class T>
SYNKRO_INLINE UInt MeshImpl<T>::GetSubsetCount() const
{
	return _subsets.Size();
}

template <class T>
SYNKRO_INLINE lang::String MeshImpl<T>::GetSubsetName( UInt index ) const
{
	assert( index < _subsets.Size() );

	return _subsets[index].Name;
}

template <class T>
SYNKRO_INLINE IPrimitive* MeshImpl<T>::GetSubset( UInt index ) const
{
	assert( index < _subsets.Size() );

	return _subsets[index].Primitive;
}

template <class T>
SYNKRO_INLINE IPrimitive* MeshImpl<T>::GetSubset( const lang::String& name ) const
{
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		if ( _subsets[i].Name.EqualsTo(name, true) )
			return _subsets[i].Primitive;
	}
	return nullptr;
}

template <class T>
SYNKRO_INLINE void MeshImpl<T>::GetCenter( math::Vector3& center ) const
{
	if ( _base.Primitive != nullptr )
	{
		_base.Primitive->GetCenter( center );
		return;
	}

	math::Vector3 total;
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		math::Vector3 vec;
		_subsets[i].Primitive->GetCenter( vec );
		total += vec;
	}
	center = total/CastFloat((_subsets.Size() > 0.0f) ? _subsets.Size() : 1);
}

template <class T>
SYNKRO_INLINE Float MeshImpl<T>::GetBoundSphere() const
{
	if ( _base.Primitive != nullptr )
		return _base.Primitive->GetBoundSphere();

	Float boundSphere = 0.0f;

	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		Float primitiveSphere = _subsets[i].Primitive->GetBoundSphere();
		if ( boundSphere < primitiveSphere )
		{
			boundSphere = primitiveSphere;
		}
	}

	return boundSphere;
}

template <class T>
SYNKRO_INLINE Bool MeshImpl<T>::IsVisible() const
{
	return _visible;
}

template <class T>
SYNKRO_INLINE IPointMesh* MeshImpl<T>::AsPoint() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILineMesh* MeshImpl<T>::AsLine() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ITriangleMesh* MeshImpl<T>::AsTriangle() const
{
	return nullptr;
}
