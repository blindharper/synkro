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
// Purpose: Implements diagnostics log.
//==============================================================================
SYNKRO_INLINE LogLevel Log::GetLevel() const
{
	return _level;
}

SYNKRO_INLINE LogMode Log::GetMode() const
{
	return _mode;
}

SYNKRO_INLINE void Log::Pause( Bool pause )
{
	_paused = pause;
}
