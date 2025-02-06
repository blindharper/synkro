//==============================================================================
// This file stream a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Implements generic stream interface.
//==============================================================================
#include "config.h"
#include "stream.h"

#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

#include <io/IStream.h>
#include <io/IStreamDirectory.h>

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

#else

#include <stdio.h>

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )


void* streamopen( void* stream, const char* mode )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	bool a = false;
	bool r = false;
	bool w = false;
	bool p = false;

	OpenMode m;
	size_t len = strlen( mode );
	for ( unsigned int i = 0; i < len; ++i )
	{
			 if ( mode[i] == 'a' ) { a = true; }
		else if ( mode[i] == 'r' ) { r = true; }
		else if ( mode[i] == 'w' ) { w = true; }
		else if ( mode[i] == '+' ) { p = true; }
	}

	if ( a )
	{
		m.Set( OpenMode::Append );
		if ( p )
			m.Set( OpenMode::Read );
	}
	else if ( r )
	{
		m.Set( OpenMode::Read );
		if ( p )
			m.Set( OpenMode::Write );
	}
	else if ( w )
	{
		m.Set( OpenMode::Write );
	}

	IStream* s = (IStream*)stream;
	s->Open( m );
	return s;

#else

	FILE* file = nullptr;
	fopen_s( &file, (const char*)stream, mode );
	return file;

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

void* streamcloneappend( void* stream, const char* suffix )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	String name = s->GetName().Append( suffix );
	return (void*)s->GetDirectory()->CreateStream( name );

#else

	FILE* file = nullptr;
	char buf[200];
	strcpy_s( buf, (const char*)stream );
	strcat_s( buf, suffix );
	fopen_s( &file, buf, "w" );
	return file;

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

void streamclose( void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->Close();

#else

	fclose( (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

void streamflush( void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->Flush();

#else

	fflush( (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

void streamdelete( void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->Delete();

#else

	remove( (const char*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

void streamsetsize( void* stream, unsigned int size )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->SetLength( CastUInt(size) );

#else

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamsize( void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	return (unsigned int)s->GetLength();

#else

	unsigned int pos = ftell( (FILE*)stream );
	fseek( (FILE*)stream, 0, SEEK_END );
	unsigned int size = ftell( (FILE*)stream );
	fseek( (FILE*)stream, pos, SEEK_SET );
	return size;

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamtell( void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	return (unsigned int)s->GetPosition();

#else

	return ftell( (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamseek( void* stream, long offset, int origin )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	SeekOrigin org;
	if ( origin == SEEK_SET )
		org = SeekOrigin::Start;
	else if ( origin == SEEK_CUR )
		org = SeekOrigin::Current;
	else if ( origin == SEEK_END )
		org = SeekOrigin::End;

	IStream* s = (IStream*)stream;
	s->Seek( offset, org );
	return (unsigned int)0;

#else

	return fseek( (FILE*)stream, offset, origin );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamread( void* buffer, unsigned int size, unsigned int count, void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	synkro::UInt bytes = s->Read( buffer, (synkro::UInt)size*count );
	return (unsigned int)(bytes/size);

#else

	return fread( buffer, size, count, (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamreadoffset( void* buffer, unsigned int size, unsigned int count, long offset, void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->Seek( offset, SeekOrigin::Start );
	synkro::UInt bytes = s->Read( buffer, (synkro::UInt)size*count );
	return (unsigned int)(bytes/size);

#else

	fseek( (FILE*)stream, offset, SEEK_SET );
	return fread( buffer, size, count, (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamwrite( const void* buffer, unsigned int size, unsigned int count, void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	synkro::UInt bytes = s->Write( buffer, (synkro::UInt)size*count );
	return (unsigned int)(bytes/size);

#else

	return fwrite( buffer, size, count, (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}

unsigned int streamwriteoffset( const void* buffer, unsigned int size, unsigned int count, long offset, void* stream )
{
#if defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )

	IStream* s = (IStream*)stream;
	s->Seek( offset, SeekOrigin::Start );
	synkro::UInt bytes = s->Write( buffer, (synkro::UInt)size*count );
	return (unsigned int)(bytes/size);

#else

	fseek( (FILE*)stream, offset, SEEK_SET );
	return fwrite( buffer, size, count, (FILE*)stream );

#endif // defined( SYNKRO_EXPORTS ) || defined( SYNKROLIB_EXPORTS )
}
