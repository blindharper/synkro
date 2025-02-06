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
// Purpose: Defines DDS image codec context.
//==============================================================================
#ifndef _SYNKRO_IMG_DDSIMAGECODECCONTEXT_
#define _SYNKRO_IMG_DDSIMAGECODECCONTEXT_


#include "config.h"
#include "ImageCodecContextEx.h"


namespace synkro
{


namespace img
{


// DDS image codec context.
class DdsImageCodecContext :
	public ImageCodecContextEx
{
public:
	// Creates context.
	DdsImageCodecContext();

	PixelFormat	DstFormat;
	PixelFormat	SrcFormat;
	UInt		DstStride;
	UInt		CellSize;
	UInt		Width;
	UInt		Height;
	UInt		Depth;
	UInt		Stride;
	UInt		ElementCount;
	UInt		LevelCount;
	UInt		Size;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_DDSIMAGECODECCONTEXT_
