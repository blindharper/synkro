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
#ifndef _SYNKRO_GFX_DATAFORMAT_
#define _SYNKRO_GFX_DATAFORMAT_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <gfx/IDataFormatEx.h>


namespace synkro
{


namespace gfx
{


// Data buffer format.
class DataFormat :
	public core::ObjectImpl<IDataFormatEx>
{
public:
	// Constructor.
	DataFormat();

	// IDataFormat methods.
	UInt													GetVertexStreamCount() const;
	DataStream												GetVertexStreamType( UInt index ) const;
	ProgramDataType											GetVertexStreamDataType( UInt index ) const;
	UInt													GetInstanceStreamCount() const;
	DataStream												GetInstanceStreamType( UInt index ) const;
	ProgramDataType											GetInstanceStreamDataType( UInt index ) const;

	// IDataFormatEx methods.
	void													AddVertexStream( const DataStream& type, const ProgramDataType& dataType );
	void													AddInstanceStream( const DataStream& type, const ProgramDataType& dataType );

private:
	struct Stream
	{
		Stream( const DataStream& type, const ProgramDataType& dataType ) :
			Type( type ),
			DataType( dataType )
		{
		}

		Stream() :
			Type( DataStream::Unknown ),
			DataType( ProgramDataType::Unknown )
		{
		}

		DataStream		Type;
		ProgramDataType	DataType;
	};

	lang::Vector<Stream>									_vertices;
	lang::Vector<Stream>									_instances;
};


#include "DataFormat.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATAFORMAT_
