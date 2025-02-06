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
// Purpose: Logical typed buffer resource.
//==============================================================================
#ifndef _SYNKRO_GFX_TYPEDBUFFER_
#define _SYNKRO_GFX_TYPEDBUFFER_


#include "config.h"
#include "BaseResourceImpl.h"
#include "BaseResource.h"
#include "TypedBufferImpl.h"
#include <gfx/ITypedBuffer.h>


namespace synkro
{


namespace gfx
{


// Logical typed buffer resource.
class TypedBuffer :
	public TypedBufferImpl<ITypedBuffer>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	TypedBuffer( ITypedBuffer* buffer );

	// ITypedBuffer methods.
	void													Set( const Float* value, UInt count );
	void													Set( const math::Vector2* value, UInt count );
	void													Set( const math::Vector3* value, UInt count );
	void													Set( const math::Vector4* value, UInt count );
	void													Set( const math::Matrix4x4* value, UInt count );

private:
	P(ITypedBuffer)											_buffer;
};


#include "TypedBuffer.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_TYPEDBUFFER_
