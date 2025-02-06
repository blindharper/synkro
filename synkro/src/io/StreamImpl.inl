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
// Purpose: Generic stream implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE StreamImpl<T>::StreamImpl( IStreamDirectory* directory, const lang::String& name ) :
	_directory( directory ),
	_name( name ),
	_accessMode( AccessMode::Default ),
	_mode( OpenMode::None )
{
}

template <class T>
SYNKRO_INLINE StreamImpl<T>::~StreamImpl()
{
	Close();
}

template <class T>
SYNKRO_INLINE void StreamImpl<T>::Open( const OpenMode& mode )
{
	_mode = mode;
}

template <class T>
SYNKRO_INLINE void StreamImpl<T>::Close()
{
	_mode = OpenMode::None;
}

template <class T>
SYNKRO_INLINE void StreamImpl<T>::Delete()
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void StreamImpl<T>::SetAccessMode( const AccessMode& mode )
{
	_accessMode = mode;
}

template <class T>
SYNKRO_INLINE Bool StreamImpl<T>::Exists() const
{
	return true;
}

template <class T>
SYNKRO_INLINE AccessMode StreamImpl<T>::GetAccessMode() const
{
	return _accessMode;
}

template <class T>
SYNKRO_INLINE OpenMode StreamImpl<T>::GetMode() const
{
	return _mode;
}

template <class T>
SYNKRO_INLINE lang::String StreamImpl<T>::GetName() const
{
	return _name;
}

template <class T>
SYNKRO_INLINE IStreamDirectory* StreamImpl<T>::GetDirectory() const
{
	return _directory;
}
