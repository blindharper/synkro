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
// Purpose: Defines widget anchors.
//==============================================================================
#ifndef _SYNKRO_UI_ANCHOR_
#define _SYNKRO_UI_ANCHOR_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace ui
{


/**
 * Widget's anchors.
 */
SYNKRO_FLAG_BEGIN( Anchor )
	/** Widget is not anchored. */
	SYNKRO_FLAG_CONST( Anchor, None )

	/** Widget is anchored to the left side of its parent. */
	SYNKRO_FLAG_CONST( Anchor, Left )

	/** Widget is anchored to the right side of its parent. */
	SYNKRO_FLAG_CONST( Anchor, Right )

	/** Widget is anchored to the top side of its parent. */
	SYNKRO_FLAG_CONST( Anchor, Top )

	/** Widget is anchored to the bottom side of its parent. */
	SYNKRO_FLAG_CONST( Anchor, Bottom )

	/** Widget is anchored to the top-left corner of its parent. */
	SYNKRO_FLAG_CONST( Anchor, TopLeft )

	/** Widget is anchored to the top-right corner of its parent. */
	SYNKRO_FLAG_CONST( Anchor, TopRight )

	/** Widget is anchored to the bottom-left corner of its parent. */
	SYNKRO_FLAG_CONST( Anchor, BottomLeft )

	/** Widget is anchored to the bottom-right corner of its parent. */
	SYNKRO_FLAG_CONST( Anchor, BottomRight )

	/** Widget is anchored to all sides of its parent. */
	SYNKRO_FLAG_CONST( Anchor, All )

	/** Creates widget's anchor from string. */
	Anchor( const lang::String& anchor );

	/** Converts widget's anchor to string. */
	lang::String								ToString() const;
SYNKRO_FLAG_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_ANCHOR_
