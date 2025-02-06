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
// Purpose: Logical blend state.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDSTATE_
#define _SYNKRO_GFX_BLENDSTATE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IBlendState.h>


namespace synkro
{


namespace gfx
{


// Logical blend state.
class BlendState :
	public core::ObjectImpl<IBlendState>
{
public:
	// Constructor.
	BlendState( IBlendState* state, Bool readonly );

	// IBlendState methods.
	void													Enable( Bool enable );
	void													SetSrcMode( const BlendMode& mode );
	void													SetColorSrcMode( const BlendMode& mode );
	void													SetAlphaSrcMode( const BlendMode& mode );
	void													SetDstMode( const BlendMode& mode );
	void													SetColorDstMode( const BlendMode& mode );
	void													SetAlphaDstMode( const BlendMode& mode );
	void													SetOperation( const BlendOperation& operation );
	void													SetColorOperation( const BlendOperation& operation );
	void													SetAlphaOperation( const BlendOperation& operation );
	void													SetWriteChannels( const img::PixelChannel& channels );
	Bool													IsEnabled() const;
	BlendMode												GetColorSrcMode() const;
	BlendMode												GetAlphaSrcMode() const;
	BlendMode												GetColorDstMode() const;
	BlendMode												GetAlphaDstMode() const;
	BlendOperation											GetColorOperation() const;
	BlendOperation											GetAlphaOperation() const;
	img::PixelChannel										GetWriteChannels() const;

private:
	P(IBlendState)											_state;
	Bool													_readonly;

	void													PreventModify();
};


#include "BlendState.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDSTATE_
