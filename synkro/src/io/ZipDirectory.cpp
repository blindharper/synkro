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
// Purpose: Defines directory of zip file streams.
//==============================================================================
#include "config.h"
#include "ZipDirectory.h"
#include "ZipFolder.h"
#include "ZipStream.h"
#include "SeekOriginConst.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


ZipDirectory::ZipDirectory( IStream* stream, Bool write ) :
	StreamDirectoryImpl<IStreamDirectory>( nullptr, stream ),
	_readonly( !write ),
	_handleRead( 0 ),
	_handleWrite( 0 )
{
	if ( _readonly )
	{
		Init();
	}
}

ZipDirectory::~ZipDirectory()
{
	Close();
}

IStreamDirectory* ZipDirectory::CreateDirectory( const String& name )
{
	return new ZipFolder( this, this, name );
}

IStream* ZipDirectory::CreateStream( const String& name )
{
	return new ZipStream( this, this, name );
}

Bool ZipDirectory::FileOpen( const String& name, const OpenMode& mode )
{
	char buf[260] = {};
	int ret = UNZ_OK;

	name.GetBytes( buf, 260 );
	if ( mode.IsSet(OpenMode::Read) )
	{
		if ( !_handleRead )
		{
			_handleRead = unzOpen( _stream );
		}
		else
		{
			unzCloseCurrentFile( _handleRead );
		}

		ret = unzLocateFile( _handleRead, buf, 2 ); // 2 = case-insensitive comparison.
		if ( ret == UNZ_OK )
			ret = unzOpenCurrentFile( _handleRead );
		return ret == UNZ_OK;
	}
	else if ( mode.IsSet(OpenMode::Write) )
	{
		if ( _readonly )
			throw IoException( String::Format(L"Failed to open stream '{0}' for writing.", name) );

		if ( !_handleWrite )
		{
			_handleWrite = zipOpen( _stream, 0 ); // 0 = overwrite
		}
		else
		{
			zipCloseFileInZip( _handleWrite );
		}

		zip_fileinfo info;
		memset( &info, 0, sizeof(info) );
		info.dosDate = 1;
		ret = zipOpenNewFileInZip( _handleWrite, buf, &info, nullptr, 0, nullptr, 0, nullptr, Z_DEFLATED, Z_BEST_COMPRESSION );
		return ret == ZIP_OK;
	}
	else
	{
		throw IoException( String::Format(L"Failed to open stream '{0}'. Unsupported open mode.", name) );
	}
}

void ZipDirectory::FileClose()
{
	if ( _handleRead )
		unzCloseCurrentFile( _handleRead );

	if ( _handleWrite )
		zipCloseFileInZip( _handleWrite );
}

UInt ZipDirectory::FileRead( void* data, UInt size )
{
	if ( !_handleRead )
		throw IoException( L"Stream is not open for reading." );

	const Int bytesRead = unzReadCurrentFile( _handleRead, data, size );
	if ( bytesRead < 0 )
		throw IoException( L"Zip stream read error." );

	return CastUInt( bytesRead );
}

UInt ZipDirectory::FileWrite( const void* data, UInt size )
{
	if ( !_handleWrite )
		throw IoException( L"Stream is not open for writing." );

	if ( zipWriteInFileInZip(_handleWrite, (const voidp)data, size) < 0 )
		throw IoException( L"Zip stream write error." );

	return size;
}

Int ZipDirectory::FileSeek( const String& name, UInt size, UInt position, Int bytes, const SeekOrigin& origin )
{
	if ( _handleRead )
	{
		// Re-open current stream.
		unzCloseCurrentFile( _handleRead );
		if ( !FileOpen(name, OpenMode::Read) )
			return 0;

		// Determine new stream position.
		UInt bytesLeft = 0;
		switch ( origin )
		{
			case SEEK_ORIGIN_START:
				bytesLeft = CastUInt( bytes );
				break;

			case SEEK_ORIGIN_CURRENT:
				bytesLeft = position + bytes;
				break;

			case SEEK_ORIGIN_END:
				bytesLeft = size - bytes;
				break;
		}

		// Move stream to new position.
		Byte buf[1024] = {};
		while ( bytesLeft > 0 )
		{
			const UInt bytesToRead = (bytesLeft > 1024) ? 1024 : bytesLeft;
			const Int bytesRead = unzReadCurrentFile( _handleRead, buf, bytesToRead );
			bytesLeft -= bytesRead;
		}
	}
	else if ( _handleWrite )
	{
		throw NotSupportedException( L"Zip streams do not support seeking in write mode." );
	}

	return bytes;
}

Bool ZipDirectory::FileReset( const String& name )
{
	if ( _handleRead )
	{
		char buf[260] = {};
		unzCloseCurrentFile( _handleRead );
		name.GetBytes( buf, 260 );
		int ret = unzLocateFile( _handleRead, buf, 2 ); // 2 = case-insensitive comparison.
		if ( ret == UNZ_OK )
			ret = unzOpenCurrentFile( _handleRead );
		return ret == UNZ_OK;
	}

	return false;
}

Bool ZipDirectory::IsDirectory( IStream* stream )
{
	unzFile handle = unzOpen( stream );
	const Bool isDir = (handle != nullptr);
	if ( isDir )
	{
		unzClose( handle );
	}
	return isDir;
}

void ZipDirectory::Init()
{
	char buf[260] = {};

	unzFile handle = unzOpen( _stream );
	if ( handle != nullptr )
	{
		int ret = unzGoToFirstFile( handle );
		if ( ret == UNZ_OK )
		{
			unz_file_info fi;
			do
			{
				unzGetCurrentFileInfo( handle, &fi, buf, 260, 0, 0, 0, 0 );
				Path pathName( buf );
				String name( buf );
				String slash( L'/' );
				String strBase = pathName.GetBase();
				if ( !strBase.IsEmpty() )
				{
					// Find base folder among the top-level folders.
					ZipFolder* folder = nullptr;
					for ( UInt i = 0; i < _dirs.Size(); ++i )
					{
						if ( _dirs[i]->GetName() == strBase )
						{
							folder = (ZipFolder*)_dirs[i].AsPtr();
							break;
						}
					}

					// Create folder if one does not exist.
					if ( folder == nullptr )
					{
						folder = new ZipFolder( this, this, strBase );
						_dirs.Add( folder );
					}

					// Add entry to the folder.
					String strName = pathName.RemoveBase();
					if ( strName.IsEmpty() )
					{
						strName = pathName.GetPath();
					}
					folder->AddEntry( name, strName, CastUInt(fi.uncompressed_size) );
				}
				else
				{
					// Add entry to a top-level collection.
					if ( name.EndsWith(slash) )
					{
						_dirs.Add( new ZipFolder(this, this, name.TrimEnd(slash)) );
					}
					else
					{
						_streams.Add( new ZipStream(this, this, name, name, CastUInt(fi.uncompressed_size)) );
					}
				}
			} while ( unzGoToNextFile(handle) != UNZ_END_OF_LIST_OF_FILE );
		}
		unzClose( handle );
	}
}

void ZipDirectory::Close()
{
	if ( _handleRead )
	{
		unzCloseCurrentFile( _handleRead );
		unzClose( _handleRead );
		_handleRead = 0;
	}

	if ( _handleWrite )
	{
		zipCloseFileInZip( _handleWrite );
		zipClose( _handleWrite, 0 );
		_handleWrite = 0;
	}
}


} // io


} // synkro
