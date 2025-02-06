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
// Purpose: Generic mesh batch implementation.
//==============================================================================
template <class T, class I>
SYNKRO_INLINE MeshBatchImpl<T,I>::MeshBatchImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, UInt capacity ) :
	MeshImpl<T>( scene, context, name ),
	_instances( A(InstanceDesc), capacity ),
	_range( 0 )
{
}

template <class T, class I>
SYNKRO_INLINE MeshBatchImpl<T,I>::~MeshBatchImpl()
{
}

template <class T, class I>
SYNKRO_INLINE INode* MeshBatchImpl<T,I>::GetParent() const
{
	throw lang::InvalidOperationException( L"Mesh batches are not a part of scene hierarchy." );
}

template <class T, class I>
SYNKRO_INLINE void MeshBatchImpl<T,I>::SetRange( const lang::Range& range )
{
	if ( range != _range )
	{
		for ( UInt i = 0; i < _subsets.Size(); ++i )
		{
			_subsets[i].Primitive->SetInstanceRange( range );
		}
		_range = range;
	}
}

template <class T, class I>
SYNKRO_INLINE UInt MeshBatchImpl<T,I>::GetCapacity() const
{
	return _instances.Capacity();
}

template <class T, class I>
SYNKRO_INLINE UInt MeshBatchImpl<T,I>::GetInstanceCount() const
{
	return _instances.Size();
}

template <class T, class I>
SYNKRO_INLINE I* MeshBatchImpl<T,I>::GetInstance( UInt index ) const
{
	assert( index < _instances.Size() );

	if ( index >= _instances.Size() )
		throw lang::OutOfRangeException( index, _instances.Size() );

	return (I*)_instances[index].Mesh;
}

template <class T, class I>
SYNKRO_INLINE void MeshBatchImpl<T,I>::GetRange( lang::Range& range ) const
{
	range = _range;
}
