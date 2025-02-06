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
// Purpose: Generic script object implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ScriptObjectImpl<T>::ScriptObjectImpl( IScriptMachine* machine ) :
	_machine( machine )
{
}

template <class T>
SYNKRO_INLINE ScriptObjectImpl<T>::~ScriptObjectImpl()
{
}

template <class T>
SYNKRO_INLINE IScriptMachine* ScriptObjectImpl<T>::GetMachine() const
{
	return _machine;
}
