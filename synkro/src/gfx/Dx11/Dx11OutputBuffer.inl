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
// Purpose: DX11 output buffer implementation.
//==============================================================================
SYNKRO_INLINE Bool Dx11OutputBuffer::Map( const MapMode& mode )
{
	return false;
}

SYNKRO_INLINE Bool Dx11OutputBuffer::Unmap()
{
	return false;
}

SYNKRO_INLINE void Dx11OutputBuffer::Resize( UInt count )
{
	// Do nothing.
}

SYNKRO_INLINE void Dx11OutputBuffer::SetData( const Byte* data, UInt size, UInt offset, UInt start, UInt count )
{
	// Do nothing.
}

SYNKRO_INLINE void Dx11OutputBuffer::GetData( Byte* data, UInt size, UInt offset, UInt start, UInt count )
{
	// Do nothing.
}

SYNKRO_INLINE UInt Dx11OutputBuffer::GetStride() const
{
	return _stride;
}

SYNKRO_INLINE UInt Dx11OutputBuffer::GetSize() const
{
	return _size;
}
