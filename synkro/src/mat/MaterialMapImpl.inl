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
// Purpose: Generic map implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE MaterialMapImpl<T>::MaterialMapImpl() :
	_amount( 0.0f )
{
}

template <class T>
SYNKRO_INLINE MaterialMapImpl<T>::~MaterialMapImpl()
{
}

template <class T>
SYNKRO_INLINE void MaterialMapImpl<T>::SetImage( img::IImage* image )
{
	assert( image != nullptr );

	_image = image;
	if ( _amount == 0.0f )
	{
		_amount = 1.0f;
	}
}

template <class T>
SYNKRO_INLINE void MaterialMapImpl<T>::SetAmount( Float amount )
{
	_amount = Clamp( amount, 0.0f, 1.0f );
}

template <class T>
SYNKRO_INLINE void MaterialMapImpl<T>::SetName( const lang::String& name )
{
	_name = name;
}

template <class T>
SYNKRO_INLINE img::IImage* MaterialMapImpl<T>::GetImage() const
{
	return _image;
}

template <class T>
SYNKRO_INLINE Float MaterialMapImpl<T>::GetAmount() const
{
	return _amount;
}

template <class T>
SYNKRO_INLINE lang::String MaterialMapImpl<T>::GetName() const
{
	return _name;
}
