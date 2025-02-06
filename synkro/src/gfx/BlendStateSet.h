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
// Purpose: Logical blend state set.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDSTATESET_
#define _SYNKRO_GFX_BLENDSTATESET_


#include "config.h"
#include "BlendStateSetImpl.h"
#include <gfx/IBlendStateSet.h>


namespace synkro
{


namespace gfx
{


// Logical blend state set.
class BlendStateSet :
	public BlendStateSetImpl<IBlendStateSet>
{
public:
	// Constructors.
	BlendStateSet( IBlendStateSet* set );
	BlendStateSet( const BlendStateSet& other );

	// IRenderState methods.
	void													Bind();

	// IBlendStateSet methods.
	void													Enable( Bool enable );
	void													EnableAlphaToCoverage( Bool enable );
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
	Bool 													IsAlphaToCoverageEnabled() const;
	IBlendStateSet*											Clone() const;

private:
	P(IBlendStateSet)										_set;
	Bool													_readonly;
};


#include "BlendStateSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDSTATESET_
