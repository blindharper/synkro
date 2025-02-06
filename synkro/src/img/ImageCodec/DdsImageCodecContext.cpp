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
// Purpose: Implements DDS image codec context.
//==============================================================================
#include "config.h"
#include "DdsImageCodecContext.h"


namespace synkro
{


namespace img
{


DdsImageCodecContext::DdsImageCodecContext() :
	DstStride( 0 ),
	CellSize( 0 ),
	Width( 0 ),
	Height( 0 ),
	Depth( 0 ),
	Stride( 0 ),
	ElementCount( 0 ),
	LevelCount( 0 ),
	Size( 0 )
{
}


} // img


} // synkro
