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
// Purpose: Defines binary data writer.
//==============================================================================
SYNKRO_INLINE BinaryWriter::BinaryWriter( IStream* stream, Bool append, Bool autoFlush ) :
	StreamWriter( stream, append, autoFlush )
{
}

SYNKRO_INLINE BinaryWriter::BinaryWriter( IStream* stream, Bool append ) :
	StreamWriter( stream, append )
{
}

SYNKRO_INLINE BinaryWriter::BinaryWriter( IStream* stream ) :
	StreamWriter( stream )
{
}

SYNKRO_INLINE void BinaryWriter::Write( void* bytes, UInt count )
{
#if SYNKRO_ENDIAN == SYNKRO_ENDIAN_BIG
	Reverse<Byte>( bytes, count );
#endif // SYNKRO_ENDIAN == SYNKRO_ENDIAN_BIG

	StreamWriter::Write( bytes, count );
}

SYNKRO_INLINE void BinaryWriter::Write( Bool value )
{
	Write( &value, 1L );
}

SYNKRO_INLINE void BinaryWriter::Write( Float value )
{
	Write( &value, 4L );
}

SYNKRO_INLINE void BinaryWriter::Write( Double value )
{
	Write( &value, 8L );
}

SYNKRO_INLINE void BinaryWriter::Write( Short value )
{
	Write( &value, 2L );
}

SYNKRO_INLINE void BinaryWriter::Write( UShort value )
{
	Write( &value, 2L );
}

SYNKRO_INLINE void BinaryWriter::Write( Int value )
{
	Write( &value, 4L );
}

SYNKRO_INLINE void BinaryWriter::Write( UInt value )
{
	Write( &value, 4L );
}

SYNKRO_INLINE void BinaryWriter::Write( Long value )
{
	Write( &value, 8L );
}

SYNKRO_INLINE void BinaryWriter::Write( ULong value )
{
	Write( &value, 8L );
}
