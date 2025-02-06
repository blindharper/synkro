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
// Purpose: Implements image.
//==============================================================================
SYNKRO_INLINE void Image::SignalLoad()
{
	if ( _texture == nullptr )
	{
		_lock.Signal();
	}
	_loaded = true;
}

SYNKRO_INLINE UInt Image::GetSize() const
{
	return _data.Size();
}
