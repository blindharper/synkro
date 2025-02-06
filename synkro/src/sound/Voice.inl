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
// Purpose: Voice implementation.
//==============================================================================
SYNKRO_INLINE Bool Voice::IsRecording() const
{
	return _recording;
}

SYNKRO_INLINE Double Voice::GetLength() const
{
	return _length;
}
