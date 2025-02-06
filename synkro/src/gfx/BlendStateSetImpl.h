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
// Purpose: Generic blend state set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDSTATESETIMPL_
#define _SYNKRO_GFX_BLENDSTATESETIMPL_


#include "config.h"
#include <lang/Vector.h>
#include "RenderStateImpl.h"
#include "BlendStateEx.h"


namespace synkro
{


namespace gfx
{


// Generic blend state set implementation.
template <class T>
class BlendStateSetImpl :
	public RenderStateImpl<T>
{
public:
	// Constructor & destructor.
	BlendStateSetImpl( UInt capacity );
	virtual ~BlendStateSetImpl();

	// IBlendStateSet methods.
	virtual void											Enable( Bool enable );
	virtual void											EnableAlphaToCoverage( Bool enable );
	virtual void											SetSrcMode( const BlendMode& mode );
	virtual void											SetColorSrcMode( const BlendMode& mode );
	virtual void											SetAlphaSrcMode( const BlendMode& mode );
	virtual void											SetDstMode( const BlendMode& mode );
	virtual void											SetColorDstMode( const BlendMode& mode );
	virtual void											SetAlphaDstMode( const BlendMode& mode );
	virtual void											SetOperation( const BlendOperation& operation );
	virtual void											SetColorOperation( const BlendOperation& operation );
	virtual void											SetAlphaOperation( const BlendOperation& operation );
	virtual void											SetWriteChannels( const img::PixelChannel& channels );
	virtual Bool 											IsAlphaToCoverageEnabled() const;
	virtual UInt											GetSize() const;
	virtual IBlendState*									Get( UInt index ) const;

protected:
	lang::Vector<P(IBlendState)>							_states;
	Bool													_alphaToCoverageEnabled;
};


#include "BlendStateSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDSTATESETIMPL_
