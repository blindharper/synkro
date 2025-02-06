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
// Purpose: Generic program parameter set implementation.
//==============================================================================
template <class T, class P>
SYNKRO_INLINE ParameterSetImpl<T, P>::ParameterSetImpl( const ProgramStageType& type ) :
	_params( lang::Allocator<lang::MapPair<lang::String, P> >( __FILE__, __LINE__ ) ),
	_names( A(lang::String) ),
	_data( A(Byte) ),
	_type( type )
{
}

template <class T, class P>
SYNKRO_INLINE ParameterSetImpl<T, P>::~ParameterSetImpl()
{
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, Bool value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const Bool* value, UInt count )
{
	_data.Set( ((P*)param)->Offset, (const Byte*)value, count*sizeof(Bool) );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, Int value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const Int* value, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		Int val = (Int)value[i];
		_data.Set( ((P*)param)->Offset+(i*sizeof(Int)), (const Byte*)&val, sizeof(Int) );
	}
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, Float value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const Float* value, UInt count )
{
	_data.Set( ((P*)param)->Offset, (const Byte*)value, count*sizeof(Float) );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector2& value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector2* value, UInt count )
{
	_data.Set( ((P*)param)->Offset, (const Byte*)value, 2*count*sizeof(Float) );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector3& value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector3* value, UInt count )
{
	_data.Set( ((P*)param)->Offset, (const Byte*)value, 3*count*sizeof(Float) );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector4& value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Vector4* value, UInt count )
{
	_data.Set( ((P*)param)->Offset, (const Byte*)value, 4*count*sizeof(Float) );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Matrix4x4& value )
{
	Set( param, &value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const math::Matrix4x4* value, UInt count )
{
	P* p = (P*)param;
	if ( p->Type == ProgramDataType::Matrix4x4 )
	{
		_data.Set( p->Offset, (const Byte*)value, 16*count*sizeof(Float) );
	}
	else if ( p->Type == ProgramDataType::Matrix4x4Transposed )
	{
		math::Matrix4x4 mat;
		for ( UInt i = 0; i < count; ++i )
		{
			mat = value[i].Transpose();
			_data.Set( p->Offset+(i*16*sizeof(Float)), (const Byte*)&mat, 16*sizeof(Float) );
		}
	}
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const Byte* value, UInt size )
{
	Set( param, value, size, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Set( ProgramParam* param, const Byte* value, UInt size, UInt count )
{
	_data.Set( ((P*)param)->Offset, value, size*count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Bool* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Bool* value, UInt count ) const
{
	Copy<Bool>( value, (const Bool*)(_data.Begin()+((P*)param)->Offset), count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Int* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Int* value, UInt count ) const
{
	for ( UInt i = 0; i < count; ++i )
	{
		Int val;
		Copy<Int>( &val, (const Int*)(_data.Begin()+((P*)param)->Offset), 1 );
		value[i] = val;
	}
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Float* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, Float* value, UInt count ) const
{
	Copy<Float>( value, (const Float*)(_data.Begin()+((P*)param)->Offset), count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector2* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector2* value, UInt count ) const
{
	Copy<Float>( &value->v[0], (const Float*)(_data.Begin()+((P*)param)->Offset), 2*count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector3* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector3* value, UInt count ) const
{
	Copy<Float>( &value->v[0], (const Float*)(_data.Begin()+((P*)param)->Offset), 3*count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector4* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Vector4* value, UInt count ) const
{
	Copy<Float>( &value->v[0], (const Float*)(_data.Begin()+((P*)param)->Offset), 4*count );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Matrix4x4* value ) const
{
	Get( param, value, 1 );
}

template <class T, class P>
SYNKRO_INLINE void ParameterSetImpl<T, P>::Get( ProgramParam* param, math::Matrix4x4* value, UInt count ) const
{
	P* p = (P*)param;
	if ( p->Type == ProgramDataType::Matrix4x4 )
	{
		Copy<Float>( &value->d[0], (const Float*)(_data.Begin()+((P*)param)->Offset), 16*count );
	}
	else if ( p->Type == ProgramDataType::Matrix4x4Transposed )
	{
		math::Matrix4x4 mat;
		for ( UInt i = 0; i < count; ++i )
		{
			Copy<Float>( &mat.d[0], (const Float*)(_data.Begin()+((P*)param)->Offset+(i*16*sizeof(Float))), 16*count );
			value[i] = mat.Transpose();
		}
	}
}

template <class T, class P>
SYNKRO_INLINE UInt ParameterSetImpl<T, P>::GetParamCount() const
{
	return _params.Size();
}

template <class T, class P>
SYNKRO_INLINE lang::String ParameterSetImpl<T, P>::GetParamName( UInt index ) const
{
	return _names[index];
}

template <class T, class P>
SYNKRO_INLINE lang::String ParameterSetImpl<T, P>::GetParamName( ProgramParam* param ) const
{
	return ((P*)param)->Name;
}

template <class T, class P>
SYNKRO_INLINE ProgramDataType ParameterSetImpl<T, P>::GetParamType( ProgramParam* param ) const
{
	return ((P*)param)->Type;
}

template <class T, class P>
SYNKRO_INLINE UInt ParameterSetImpl<T, P>::GetParamSize( ProgramParam* param ) const
{
	return ((P*)param)->Size;
}

template <class T, class P>
SYNKRO_INLINE UInt ParameterSetImpl<T, P>::GetParamElementCount( ProgramParam* param ) const
{
	return ((P*)param)->ElementCount;
}

template <class T, class P>
SYNKRO_INLINE ProgramParam* ParameterSetImpl<T, P>::GetParam( const lang::String& name ) const
{
	return _params.ContainsKey(name) ? (ProgramParam*)&_params[name] : nullptr;
}
