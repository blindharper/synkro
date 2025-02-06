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
// Purpose: Generic program implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ProgramImpl<T>::ProgramImpl( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat ) :
	_parent( parent ),
	_inputFormat( inputFormat ),
	_outputFormat( outputFormat )
{
}

template <class T>
SYNKRO_INLINE ProgramImpl<T>::~ProgramImpl()
{
}

template <class T>
SYNKRO_INLINE IDataFormat* ProgramImpl<T>::GetInputFormat() const
{
	return _inputFormat;
}

template <class T>
SYNKRO_INLINE IDataFormat* ProgramImpl<T>::GetOutputFormat() const
{
	return _outputFormat;
}

template <class T>
SYNKRO_INLINE IProgramStage* ProgramImpl<T>::GetVertexStage() const
{
	return _vertexStage;
}

template <class T>
SYNKRO_INLINE IProgramStage* ProgramImpl<T>::GetHullStage() const
{
	return _hullStage;
}

template <class T>
SYNKRO_INLINE IProgramStage* ProgramImpl<T>::GetDomainStage() const
{
	return _domainStage;
}

template <class T>
SYNKRO_INLINE IProgramStage* ProgramImpl<T>::GetGeometryStage() const
{
	return _geometryStage;
}

template <class T>
SYNKRO_INLINE IProgramStage* ProgramImpl<T>::GetFragmentStage() const
{
	return _fragmentStage;
}

template <class T>
SYNKRO_INLINE IProgram* ProgramImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE Bool ProgramImpl<T>::IsAscii( const Byte* data, UInt size )
{
	const Byte* end = data + size;

	for ( const Byte* p = data; p < end; ++p )
	{
		if ( *p >= 128 )
			return false;
	}

	return true;
}
