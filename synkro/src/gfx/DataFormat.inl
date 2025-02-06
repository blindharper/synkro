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
// Purpose: Defines data buffer format.
//==============================================================================
SYNKRO_INLINE UInt DataFormat::GetVertexStreamCount() const
{
	return _vertices.Size();
}

SYNKRO_INLINE DataStream DataFormat::GetVertexStreamType( UInt index ) const
{
	assert( index < _vertices.Size() );

	if ( index >= _vertices.Size() )
		throw lang::OutOfRangeException( index, _vertices.Size() );

	return _vertices[index].Type;
}

SYNKRO_INLINE ProgramDataType DataFormat::GetVertexStreamDataType( UInt index ) const
{
	assert( index < _vertices.Size() );

	if ( index >= _vertices.Size() )
		throw lang::OutOfRangeException( index, _vertices.Size() );

	return _vertices[index].DataType;
}

SYNKRO_INLINE UInt DataFormat::GetInstanceStreamCount() const
{
	return _instances.Size();
}

SYNKRO_INLINE DataStream DataFormat::GetInstanceStreamType( UInt index ) const
{
	assert( index < _instances.Size() );

	if ( index >= _instances.Size() )
		throw lang::OutOfRangeException( index, _instances.Size() );

	return _instances[index].Type;
}

SYNKRO_INLINE ProgramDataType DataFormat::GetInstanceStreamDataType( UInt index ) const
{
	assert( index < _instances.Size() );

	if ( index >= _instances.Size() )
		throw lang::OutOfRangeException( index, _instances.Size() );

	return _instances[index].DataType;
}
