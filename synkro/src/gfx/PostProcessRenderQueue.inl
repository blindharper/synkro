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
// Purpose: Post-processing rendering queue implementation.
//==============================================================================
SYNKRO_INLINE void PostProcessRenderQueue::SetInput( IResource* input )
{
	assert( input != nullptr );

	_input = input;
}

SYNKRO_INLINE IResource* PostProcessRenderQueue::GetInput() const
{
	return _input;
}

SYNKRO_INLINE void PostProcessRenderQueue::SetDirty()
{
	_dirty = true;
}
