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
// Purpose: Generic stream directory implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE StreamDirectoryImpl<T>::StreamDirectoryImpl( IStreamDirectory* parent, const lang::String& path ) :
	_parent( parent ),
	_path( path ),
	_streams( A(P(IStream)) ),
	_dirs( A(P(IStreamDirectory)) )
{
	Path p( path );
	_name = p.GetName();
	if ( _name == lang::String::Empty )
		_name = p.GetPath();
}

template <class T>
SYNKRO_INLINE StreamDirectoryImpl<T>::StreamDirectoryImpl( IStreamDirectory* parent, IStream* stream ) :
	_parent( parent ),
	_stream( stream ),
	_streams( A(P(IStream)) ),
	_dirs( A(P(IStreamDirectory)) )
{
	_name = _stream->GetName();
}

template <class T>
SYNKRO_INLINE StreamDirectoryImpl<T>::StreamDirectoryImpl() :
	_streams( A(P(IStream)) ),
	_dirs( A(P(IStreamDirectory)) )
{
}

template <class T>
SYNKRO_INLINE StreamDirectoryImpl<T>::~StreamDirectoryImpl()
{
}

template <class T>
SYNKRO_INLINE UInt StreamDirectoryImpl<T>::GetStreamCount() const
{
	return _streams.Size();
}

template <class T>
SYNKRO_INLINE IStream* StreamDirectoryImpl<T>::GetStream( UInt index ) const
{
	assert( index < _streams.Size() );

	if ( index >= _streams.Size() )
		throw lang::OutOfRangeException( index, _streams.Size() );

	return _streams[index];
}

template <class T>
SYNKRO_INLINE IStream* StreamDirectoryImpl<T>::GetStream( const lang::String& name ) const
{
	Path pathName( name );
	lang::String strBase = pathName.GetBase();
	if ( strBase.EqualsTo(L"..") )
	{
		// Search parent directories.
		IStreamDirectory* parent = _parent;
		do
		{
			pathName = Path( pathName.RemoveBase() );
			IStream* stream = parent->GetStream( pathName.GetPath() );
			if ( stream != nullptr )
				return stream;

			parent = parent->GetParent();
		} while ( parent != nullptr );
	}
	else if ( strBase != lang::String::Empty )
	{
		// Search children directories or current directory.
		const IStreamDirectory* dir = strBase.EqualsTo(L".") ? this : StreamDirectoryImpl<T>::GetDirectory( strBase );
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

	// Search stream list.
	for ( UInt i = 0; i < _streams.Size(); ++i )
	{
		if ( _streams[i]->GetName().EqualsTo(name, true) )
			return _streams[i];
	}

	// Search children directories.
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
SYNKRO_INLINE IStreamSet* StreamDirectoryImpl<T>::GetStreams( const lang::String& pattern ) const
{
	IStreamSet* streams = new StreamSet();

	lang::Mask mask( pattern );
	for ( UInt i = 0; i < _streams.Size(); ++i )
	{
		if ( mask.Matches(_streams[i]->GetName()) )
			streams->Add( _streams[i] );
	}

	return streams;
}

template <class T>
SYNKRO_INLINE IStreamSet* StreamDirectoryImpl<T>::GetStreams() const
{
	return GetStreams( L"*" );
}

template <class T>
SYNKRO_INLINE UInt StreamDirectoryImpl<T>::GetDirectoryCount() const
{
	return _dirs.Size();
}

template <class T>
SYNKRO_INLINE IStreamDirectory* StreamDirectoryImpl<T>::GetDirectory( UInt index ) const
{
	assert( index < _dirs.Size() );

	if ( index >= _dirs.Size() )
		throw lang::OutOfRangeException( index, _dirs.Size() );

	return _dirs[index];
}

template <class T>
SYNKRO_INLINE IStreamDirectory* StreamDirectoryImpl<T>::GetDirectory( const lang::String& name ) const
{
	if ( _name.EqualsTo(name, true) )
		return (IStreamDirectory*)this;

	// Search children directories.
	Path pathName( name );
	lang::String strBase = pathName.GetBase();
	if ( strBase != lang::String::Empty )
	{
		IStreamDirectory* dir = StreamDirectoryImpl<T>::GetDirectory( strBase );
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

template <class T>
SYNKRO_INLINE IStreamDirectory* StreamDirectoryImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE lang::String StreamDirectoryImpl<T>::GetName() const
{
	return _name;
}
