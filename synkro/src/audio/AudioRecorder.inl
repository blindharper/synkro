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
// Purpose: Logical recorder.
//==============================================================================
SYNKRO_INLINE void AudioRecorder::GetDesc( RecorderDesc& desc ) const
{
	_recorder->GetDesc( desc );
}

SYNKRO_INLINE UInt AudioRecorder::GetIndex() const
{
	return _index;
}
