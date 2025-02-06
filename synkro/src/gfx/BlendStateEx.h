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
// Purpose: Blend state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDSTATEEX_
#define _SYNKRO_GFX_BLENDSTATEEX_


#include "config.h"
#include "RenderStateImpl.h"
#include <gfx/IBlendState.h>


namespace synkro
{


namespace gfx
{


// Blend state implementation.
class SYNKRO_API BlendStateEx :
	public RenderStateImpl<IBlendState>
{
public:
	// Constructors.
	BlendStateEx();
	BlendStateEx( const BlendStateEx& other );

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

	// Other methods.
	void													ResetDirty();
	Bool													IsDirty() const;
	BlendStateEx*											Clone() const;

protected:
	Bool													_enabled;
	BlendMode												_colorSrcMode;
	BlendMode												_colorDstMode;
	BlendOperation											_colorBlendOp;
	BlendMode												_alphaSrcMode;
	BlendMode												_alphaDstMode;
	BlendOperation											_alphaBlendOp;
	img::PixelChannel										_channels;
};


#include "BlendStateEx.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDSTATEEX_
