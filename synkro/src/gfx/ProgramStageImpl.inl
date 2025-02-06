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
// Purpose: Generic program stage implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ProgramStageImpl<T>::ProgramStageImpl()
{
}

template <class T>
SYNKRO_INLINE ProgramStageImpl<T>::~ProgramStageImpl()
{
}

template <class T>
SYNKRO_INLINE IParameterSet* ProgramStageImpl<T>::GetParameters() const
{
	return _params;
}

template <class T>
SYNKRO_INLINE IResourceSet* ProgramStageImpl<T>::GetResources() const
{
	return _resources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* ProgramStageImpl<T>::GetSamplers() const
{
	return _samplers;
}
