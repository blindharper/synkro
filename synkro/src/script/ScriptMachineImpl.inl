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
// Purpose: Generic script machine implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ScriptMachineImpl<T>::ScriptMachineImpl( const lang::String& name ) :
	_name( name ),
	_context( nullptr )
{
}

template <class T>
SYNKRO_INLINE ScriptMachineImpl<T>::~ScriptMachineImpl()
{
}

template <class T>
SYNKRO_INLINE void ScriptMachineImpl<T>::SetContext( IScriptObject* context )
{
	_context = context;
}

template <class T>
SYNKRO_INLINE IScriptObject* ScriptMachineImpl<T>::GetContext() const
{
	return _context;
}

template <class T>
SYNKRO_INLINE lang::String ScriptMachineImpl<T>::GetName() const
{
	return _name;
}
