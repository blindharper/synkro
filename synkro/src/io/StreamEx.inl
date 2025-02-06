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
// Purpose: Defines a particular stream.
//==============================================================================
SYNKRO_INLINE void StreamEx::Open( const OpenMode& mode )
{
	_stream->Open( mode );
}

SYNKRO_INLINE void StreamEx::Close()
{
	_stream->Close();
}

SYNKRO_INLINE void StreamEx::Flush()
{
	_stream->Flush();
}

SYNKRO_INLINE UInt StreamEx::Read( void* data, UInt size )
{
	return _stream->Read( data, size );
}

SYNKRO_INLINE UInt StreamEx::Write( const void* data, UInt size )
{
	return _stream->Write( data, size );
}

SYNKRO_INLINE Int StreamEx::Seek( Int bytes, const SeekOrigin& origin )
{
	return _stream->Seek( bytes, origin );
}

SYNKRO_INLINE Bool StreamEx::Reset()
{
	return _stream->Reset();
}

SYNKRO_INLINE void StreamEx::Delete()
{
	return _stream->Delete();
}

SYNKRO_INLINE void StreamEx::SetAccessMode( const AccessMode& mode )
{
	_stream->SetAccessMode( mode );
}

SYNKRO_INLINE void StreamEx::SetLength( UInt length )
{
	_stream->SetLength( length );
}

SYNKRO_INLINE AccessMode StreamEx::GetAccessMode() const
{
	return _stream->GetAccessMode();
}

SYNKRO_INLINE UInt StreamEx::GetLength() const
{
	return _stream->GetLength();
}

SYNKRO_INLINE UInt StreamEx::GetPosition() const
{
	return _stream->GetPosition();
}

SYNKRO_INLINE OpenMode StreamEx::GetMode() const
{
	return _stream->GetMode();
}
