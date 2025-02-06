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
#ifndef _SYNKRO_IO_BINARYREADER_
#define _SYNKRO_IO_BINARYREADER_


#include "config.h"
#include "StreamReader.h"
#include <lang/Vector.h>
#include <internal/Reverse.h>


namespace synkro
{


namespace io
{


// Binary data reader.
class BinaryReader :
	public StreamReader
{
public:
	// Constructor.
	BinaryReader( IStream* stream );

	// Methods.
	UInt													ReadBytes( lang::Vector<Byte>& bytes, UInt count );
	UInt													ReadBytes( lang::Vector<Byte>& bytes );
	UInt													ReadBytes( void* bytes, UInt count );
	Byte													ReadByte();
	Bool													ReadBoolean();
	Float													ReadFloat();
	Double													ReadDouble();
	Short													ReadShort();
	UShort													ReadUShort();
	Int														ReadInt();
	UInt													ReadUInt();
	Long													ReadLong();
	ULong													ReadULong();
};


#include "BinaryReader.inl"


} // io


} // synkro


#endif // _SYNKRO_IO_BINARYREADER_
