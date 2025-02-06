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
// Purpose: Defines stream of 4x4 matrices.
//==============================================================================
#include "config.h"
#include "Matrix4x4Stream.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Matrix4x4Stream::Matrix4x4Stream( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length, Bool transposed ) :
	DataStreamImpl<IMatrix4x4Stream, Matrix4x4>( buffer, type, offset, length ),
	_transposed( transposed )
{
}

void Matrix4x4Stream::Read( Matrix4x4* data, UInt count )
{
	if ( _transposed )
	{
		for ( UInt i = 0; i < count; ++i )
		{
			Matrix4x4 mat = data[i].Transpose();
			_buffer->GetData( (Byte*)&mat, sizeof(Matrix4x4), _offset, _position+i, 1 );
		}
	}
	else
	{
		_buffer->GetData( (Byte*)data, sizeof(Matrix4x4), _offset, _position, count );
	}
	_position += count;
}

void Matrix4x4Stream::Write( const Matrix4x4* data, UInt count )
{
	if ( _transposed )
	{
		for ( UInt i = 0; i < count; ++i )
		{
			Matrix4x4 mat = data[i].Transpose();
			_buffer->SetData( (const Byte*)&mat, sizeof(Matrix4x4), _offset, _position+i, 1 );
		}
	}
	else
	{
		_buffer->SetData( (const Byte*)data, sizeof(Matrix4x4), _offset, _position, count );
	}
	_position += count;
}

void Matrix4x4Stream::Set( const Matrix4x4& value, UInt count )
{
	if ( _transposed )
	{
		Matrix4x4 mat = value.Transpose();
		for ( UInt i = 0; i < count; ++i )
		{
			_buffer->SetData( (const Byte*)&mat, sizeof(Matrix4x4), _offset, _position+i, 1 );
		}
	}
	else
	{
		for ( UInt i = 0; i < count; ++i )
		{
			_buffer->SetData( (const Byte*)&value, sizeof(Matrix4x4), _offset, _position+i, 1 );
		}
	}
}


} // gfx


} // synkro
