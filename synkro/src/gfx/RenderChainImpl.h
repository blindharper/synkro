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
// Purpose: Generic render chain implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERCHAINIMPL_
#define _SYNKRO_GFX_RENDERCHAINIMPL_


#include "config.h"
#include <lang/Ptr.h>
#include <lang/Vector.h>
#include <gfx/IPlainRenderTexture.h>


namespace synkro
{


namespace gfx
{


// Generic render chain implementation.
template <class T>
class RenderChainImpl :
	public T
{
public:
	// Constructor & destructor.
	RenderChainImpl();
	virtual ~RenderChainImpl();

	// RenderChain methods.
	virtual Bool											Begin( IPlainRenderTexture* target );
	virtual void											Present();
	virtual Bool											End();
	virtual IResource*										GetBackBuffer() const;

protected:
	lang::Vector<P(IPlainRenderTexture)>					_targets;
	IPlainRenderTexture*									_target;
	IPlainRenderTexture*									_backBuffer;
	UInt													_targetIndex;
	Bool													_began;
};


#include "RenderChainImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERCHAINIMPL_
