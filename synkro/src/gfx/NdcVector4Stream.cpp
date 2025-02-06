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
// Purpose: Defines stream of 4-component vectors in normalized device coordinates.
//==============================================================================
#include "config.h"
#include "NdcVector4Stream.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


NdcVector4Stream::NdcVector4Stream( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length, Ndc* ndc ) :
	DataStreamImpl<IVector4Stream, Vector4>( buffer, type, offset, length ),
	_data( A(Vector4) ),
	_ndc( ndc )
{
}

void NdcVector4Stream::Read( Vector4* data, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		Vector4 valueNDC;
		_buffer->GetData( (Byte*)&valueNDC, sizeof(Vector4), _offset, _position, count );
		data[i] = _ndc->Convert2( valueNDC );
	}
	_position += count;
}

void NdcVector4Stream::Write( const Vector4* data, UInt count )
{
	_data.SetSize( _position+count );
	for ( UInt i = 0; i < count; ++i )
	{
		_data[_position+i] = data[i];
		Vector4 valueNDC = _ndc->Convert( data[i] );
		_buffer->SetData( (const Byte*)&valueNDC, sizeof(Vector4), _offset, _position+i, 1 );
	}
	_position += count;
}

void NdcVector4Stream::Set( const Vector4& value, UInt count )
{
	_data.SetSize( count, value );
	Vector4 valueNDC = _ndc->Convert( value );
	for ( UInt i = 0; i < count; ++i )
	{
		_buffer->SetData( (const Byte*)&valueNDC, sizeof(Vector4), _offset, _position+i, 1 );
	}
}

void NdcVector4Stream::Update()
{
	if ( Open(OpenMode::Write) )
	{
		for ( UInt i = 0; i < _data.Size(); ++i )
		{
			Vector4 valueNDC = _ndc->Convert( _data[i] );
			_buffer->SetData( (const Byte*)&valueNDC, sizeof(Vector4), _offset, _position+i, 1 );
		}
		Close();
	}
}


} // gfx


} // synkro
