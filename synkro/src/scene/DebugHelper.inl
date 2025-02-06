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
// Purpose: Debug geometry visualizer.
//==============================================================================
SYNKRO_INLINE void DebugHelper::Show( Bool show )
{
	if ( _helper != nullptr )
	{
		_helper->Enable( show );
	}
}

SYNKRO_INLINE Bool DebugHelper::IsCreated() const
{
	return (_helper != nullptr);
}
