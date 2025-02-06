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
// Purpose: DX11 device context.
//==============================================================================
#include "config.h"
#include "Dx11Context.h"
#include <internal/SafeDelete.h>
#include <internal/SafeRelease.h>


namespace synkro
{


namespace gfx
{


Dx11Context::Dx11Context() :
	_owner( true ),
	_contextLock( new BinarySemaphore(true) ),
	_device( nullptr ),
	_context( nullptr )
{
}

Dx11Context::~Dx11Context()
{
	if ( _owner )
	{
		SafeDelete( _contextLock );
		SafeRelease( _context );
		SafeRelease( _device );
	}
}

Dx11Context::Dx11Context( const Dx11Context* other ) :
	_owner( false ),
	_contextLock( other->_contextLock ),
	_device( other->_device ),
	_context( other->_context )
{
}

void Dx11Context::Lock()
{
	_contextLock->Wait();
}

void Dx11Context::Unlock()
{
	_contextLock->Signal();
}

ID3D11Device* Dx11Context::Device() const
{
	return _device;
}

ID3D11DeviceContext* Dx11Context::operator->() const
{
	return _context;
}


} // gfx


} // synkro
