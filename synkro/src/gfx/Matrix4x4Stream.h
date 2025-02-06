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
#ifndef _SYNKRO_GFX_MATRIX4X4STREAM_
#define _SYNKRO_GFX_MATRIX4X4STREAM_


#include "config.h"
#include "DataStreamImpl.h"
#include <gfx/IMatrix4x4Stream.h>


namespace synkro
{


namespace gfx
{


// Stream of 4x4 matrices.
class Matrix4x4Stream :
	public DataStreamImpl<IMatrix4x4Stream, math::Matrix4x4>
{
public:
	// Constructor.
	Matrix4x4Stream( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length, Bool transposed );

	// IMatrix4x4Stream methods.
	void													Read( math::Matrix4x4* data, UInt count );
	void													Write( const math::Matrix4x4* data, UInt count );
	void													Set( const math::Matrix4x4& value, UInt count );

private:
	Bool													_transposed;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_MATRIX4X4STREAM_
