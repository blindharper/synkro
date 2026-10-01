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
// Purpose: Extended Scene rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SCENERENDEROBJECTEX_
#define _SYNKRO_GFX_SCENERENDEROBJECTEX_


#include "config.h"
#include "SceneRenderObjectImpl.h"
#include <gfx/ISceneRenderObjectEx.h>
#include "BaseSceneRenderObjectImpl.h"
#include "BaseSceneRenderObject.h"
#include <lang/Vector.h>


namespace synkro
{


namespace gfx
{


// Extended scene rendering object implementation.
class SceneRenderObjectEx :
	public SceneRenderObjectImpl<ISceneRenderObjectEx>,
	public BaseSceneRenderObjectImpl<BaseSceneRenderObject>
{
public:
	// Constructor & destructor.
	SceneRenderObjectEx( SceneRenderQueue* queue );
	~SceneRenderObjectEx();

	// ISceneRenderObject methods.
	ISceneRenderObjectEx*									AsEx() const;

	// ISceneRenderObjectEx methods.
	IPrimitiveEx*											CreateLevel( IPrimitive* data );
	void													SetLevel( IRenderView* view, UInt level );

private:
	lang::Vector<P(IPrimitiveEx)>							_primitives;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SCENERENDEROBJECTEX_
