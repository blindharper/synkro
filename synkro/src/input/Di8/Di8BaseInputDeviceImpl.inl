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
// Purpose: Generic DirectInput 8 base input device implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE Di8BaseInputDeviceImpl<T>::Di8BaseInputDeviceImpl() :
	_device( nullptr )
{
}

template <class T>
SYNKRO_INLINE Di8BaseInputDeviceImpl<T>::~Di8BaseInputDeviceImpl()
{
	Uninit();
}

template <class T>
SYNKRO_INLINE void Di8BaseInputDeviceImpl<T>::Uninit()
{
	if ( _device != nullptr )
	{
		_device->Unacquire();
		_device->Release();
		_device = nullptr;
	}
}
