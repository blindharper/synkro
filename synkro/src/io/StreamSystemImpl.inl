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
// Purpose: Generic stream system implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE StreamSystemImpl<T>::StreamSystemImpl( diag::ILog* log ) :
	_streams( A(P(IStream)) ),
	_dirs( A(P(IStreamDirectory)) ),
	Logger( log, diag::LogFacility::StreamSystem )
{
}

template <class T>
SYNKRO_INLINE StreamSystemImpl<T>::~StreamSystemImpl()
{
}

template <class T>
SYNKRO_INLINE IStream* StreamSystemImpl<T>::GetStream( const lang::String& name ) const
{
	// Search stream list.
	for ( UInt i = 0; i < _streams.Size(); ++i )
	{
		if ( _streams[i]->GetName().EqualsTo(name, true) )
			return _streams[i];
	}

	// Search children directories.
	Path pathName( name );
	lang::String strBase = pathName.GetBase();
	if ( strBase != lang::String::Empty )
	{
		IStreamDirectory* dir = StreamSystemImpl<T>::GetDirectory( strBase );
		if ( dir != nullptr )
		{
			lang::String strName = pathName.RemoveBase();
			if ( strName == lang::String::Empty )
			{
				strName = pathName.GetPath();
			}

			IStream* stream = dir->GetStream( strName );
			if ( stream != nullptr )
				return stream;
		}
	}
		
	for ( UInt i = 0; i < _dirs.Size(); ++i )
	{
		IStream* stream = _dirs[i]->GetStream( name );
		if ( stream != nullptr )
			return stream;
	}

	// Nothing found.
	return nullptr;
}

template <class T>
SYNKRO_INLINE IStreamDirectory* StreamSystemImpl<T>::GetDirectory( const lang::String& name ) const
{
	// Search children directories.
	Path pathName( name );
	lang::String strBase = pathName.GetBase();
	if ( strBase != lang::String::Empty )
	{
		IStreamDirectory* dir = StreamSystemImpl<T>::GetDirectory( strBase );
		if ( dir != nullptr )
		{
			lang::String strName = pathName.RemoveBase();
			if ( strName == lang::String::Empty )
			{
				strName = pathName.GetPath();
			}

			IStreamDirectory* dir0 = dir->GetDirectory( strName );
			if ( dir0 != nullptr )
				return dir0;
		}
	}

	for ( UInt i = 0; i < _dirs.Size(); ++i )
	{
		IStreamDirectory* dir = _dirs[i]->GetDirectory( name );
		if ( dir != nullptr )
			return dir;
	}

	// Nothing found.
	return nullptr;
}
