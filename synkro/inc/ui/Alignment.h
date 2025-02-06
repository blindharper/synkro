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
// Purpose: Defines content alignment.
//==============================================================================
#ifndef _SYNKRO_UI_ALIGNMENT_
#define _SYNKRO_UI_ALIGNMENT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Content alignment.
 */
SYNKRO_ENUM_BEGIN( Alignment )
	/** No alignment. */
	SYNKRO_ENUM_CONST( Alignment, None )

	/** Content is aligned at the top left corner. */
	SYNKRO_ENUM_CONST( Alignment, TopLeft )

	/** Content is aligned at the top border. */
	SYNKRO_ENUM_CONST( Alignment, Top )

	/** Content is aligned at the top right corner. */
	SYNKRO_ENUM_CONST( Alignment, TopRight )

	/** Content is aligned at the left border. */
	SYNKRO_ENUM_CONST( Alignment, Left )

	/** Content is aligned at the center. */
	SYNKRO_ENUM_CONST( Alignment, Center )

	/** Content is aligned at the right border. */
	SYNKRO_ENUM_CONST( Alignment, Right )

	/** Content is aligned at the bottom left corner. */
	SYNKRO_ENUM_CONST( Alignment, BottomLeft )

	/** Content is aligned at the bottom border. */
	SYNKRO_ENUM_CONST( Alignment, Bottom )

	/** Content is aligned at the bottom right corner. */
	SYNKRO_ENUM_CONST( Alignment, BottomRight )

	/** Creates alignment from string. */
	Alignment( const lang::String& alignment );

	/** Converts alignment to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_ALIGNMENT_
