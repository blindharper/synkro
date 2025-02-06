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
#ifndef _SYNKRO_GFX_NDCVECTOR4STREAM_
#define _SYNKRO_GFX_NDCVECTOR4STREAM_


#include "config.h"
#include "DataStreamImpl.h"
#include <gfx/IVector4Stream.h>
#include <lang/Vector.h>
#include "Ndc.h"


namespace synkro
{


namespace gfx
{


// Stream of 4-component vectors in normalized device coordinates.
class NdcVector4Stream :
	public DataStreamImpl<IVector4Stream, math::Vector4>
{
public:
	// Constructor.
	NdcVector4Stream( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length, Ndc* ndc );

	// IVector4Stream methods.
	void													Read( math::Vector4* data, UInt count );
	void													Write( const math::Vector4* data, UInt count );
	void													Set( const math::Vector4& value, UInt count );

	// Other methods.
	void													Update();

private:
	lang::Vector<math::Vector4>								_data;
	Ndc*													_ndc;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_NDCVECTOR4STREAM_
