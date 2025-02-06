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
#ifndef _SYNKRO_GFX_DX11CONTEXT_
#define _SYNKRO_GFX_DX11CONTEXT_


#include "config.h"
#include <d3d11.h>
#include <internal/BinarySemaphore.h>


#define Dx11Lock( CONTEXT ) Dx11ContextLock _dx11lock( &CONTEXT )


namespace synkro
{


namespace gfx
{


// DX11 device context.
class Dx11Context
{
public:
	// Constructor & destructor.
	Dx11Context( const Dx11Context* other );
	~Dx11Context();

	// Methods.
	void													Lock();
	void													Unlock();
	ID3D11Device*											Device() const;
	ID3D11DeviceContext*									operator->() const;

protected:
	Bool													_owner;
	ID3D11Device*											_device;
	ID3D11DeviceContext*									_context;
	BinarySemaphore*										_contextLock;

	Dx11Context();

private:
	Dx11Context( const Dx11Context& );
	Dx11Context& operator=( const Dx11Context& );
};


// Helper object for context locking/unlocking.
class Dx11ContextLock
{
public:
	SYNKRO_INLINE Dx11ContextLock( Dx11Context* context ) :
		_context( context )
	{
		_context->Lock();
	}

	SYNKRO_INLINE ~Dx11ContextLock()
	{
		_context->Unlock();
	}

private:
	Dx11Context* _context;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11CONTEXT_
