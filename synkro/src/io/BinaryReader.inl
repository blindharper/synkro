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
// Purpose: Defines binary data reader.
//==============================================================================
SYNKRO_INLINE BinaryReader::BinaryReader( IStream* stream ) :
	StreamReader( stream )
{
}

SYNKRO_INLINE UInt BinaryReader::ReadBytes( lang::Vector<Byte>& bytes, UInt count )
{
	bytes.SetSize( count );
	return CastUInt( StreamReader::Read(bytes.Begin(), count) );
}

SYNKRO_INLINE UInt BinaryReader::ReadBytes( lang::Vector<Byte>& bytes )
{
	bytes.SetSize( _stream->GetLength() );
	return CastUInt( StreamReader::Read(bytes.Begin(), bytes.Size()) );
}

SYNKRO_INLINE UInt BinaryReader::ReadBytes( void* bytes, UInt count )
{
	UInt res = StreamReader::Read( bytes, count );

#if SYNKRO_ENDIAN == SYNKRO_ENDIAN_BIG
	Reverse<Byte>( bytes, count );
#endif // SYNKRO_ENDIAN == SYNKRO_ENDIAN_BIG

	return res;
}

SYNKRO_INLINE Byte BinaryReader::ReadByte()
{
	Byte byte;
	ReadBytes( &byte, 1L );
	return byte;
}

SYNKRO_INLINE Bool BinaryReader::ReadBoolean()
{
	return (ReadByte() != 0);
}

SYNKRO_INLINE Float BinaryReader::ReadFloat()
{
	Float num;
	ReadBytes( &num, 4L );
	return num;
}

SYNKRO_INLINE Double BinaryReader::ReadDouble()
{
	Double num;
	ReadBytes( &num, 8L );
	return num;
}

SYNKRO_INLINE Short BinaryReader::ReadShort()
{
	Short num;
	ReadBytes( &num, 2L );
	return num;
}

SYNKRO_INLINE UShort BinaryReader::ReadUShort()
{
	UShort num;
	ReadBytes( &num, 2L );
	return num;
}

SYNKRO_INLINE Int BinaryReader::ReadInt()
{
	Int num;
	ReadBytes( &num, 4L );
	return num;
}

SYNKRO_INLINE UInt BinaryReader::ReadUInt()
{
	UInt num;
	ReadBytes( &num, 4L );
	return num;
}

SYNKRO_INLINE Long BinaryReader::ReadLong()
{
	Long num;
	ReadBytes( &num, 8L );
	return num;
}

SYNKRO_INLINE ULong BinaryReader::ReadULong()
{
	ULong num;
	ReadBytes( &num, 8L );
	return num;
}
