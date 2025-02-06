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
// Purpose: Generic rendering object implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderObjectImpl<T>::RenderObjectImpl( IProgram* program ) :
	_program( program ),
	_enabled( true ),
	_dirty( true )
{
}

template <class T>
SYNKRO_INLINE RenderObjectImpl<T>::~RenderObjectImpl()
{
}

template <class T>
SYNKRO_INLINE void RenderObjectImpl<T>::Enable( Bool enable )
{
	_enabled = enable;
}

template <class T>
SYNKRO_INLINE Bool RenderObjectImpl<T>::IsEnabled() const
{
	return _enabled;
}

template <class T>
SYNKRO_INLINE IProgram* RenderObjectImpl<T>::GetProgram() const
{
	return _program;
}

template <class T>
SYNKRO_INLINE IPrimitiveEx* RenderObjectImpl<T>::GetData() const
{
	return _data;
}

template <class T>
SYNKRO_INLINE void RenderObjectImpl<T>::ResetDirty()
{
	_dirty = false;
}

template <class T>
SYNKRO_INLINE Bool RenderObjectImpl<T>::IsDirty() const
{
	return _dirty;
}
