//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:info@synkro.org
//
// Purpose: 'Image Converter' tool.
//==============================================================================
#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------


void ProcessStream( IImageManager* imageManager, IStream* stream, const PixelFormat& format, const String& type )
{
	PixelFormat fmt = PixelFormat::Unknown;
	PtrImage image = imageManager->LoadImage( stream, fmt );
	if ( image != nullptr )
	{
		UInt idxDot = stream->GetName().LastIndexOf( L'.' );
		String ext = stream->GetName().Substring( idxDot+1 );
		PtrStream streamOut = stream->GetDirectory()->CreateStream( stream->GetName().TrimEnd(ext).Append(type) );
		image->Save( streamOut, format, type );
	}
}

void PrintUsage( const wchar_t* message, ... )
{
	va_list argptr;

	va_start( argptr, message );
	wprintf( message, argptr );
	va_end( argptr );

	wprintf( L"\nUsage: ImageConverter.exe /d directory [/m mask] /f format /t type [/q quality]" );
}

int main( int argc, char* argv[] )
{
	try
	{
		// Parse command line.
		int idxPath = -1; int idxMask = -1; int idxFormat = -1; int idxType = -1; int idxQuality = -1;
		for ( int i = 0; i < argc; ++i )
		{
			char* arg = argv[i];
			if ( (arg[0] == '-') || (arg[0] == '/') )
			{
				if ( strlen(arg) != 2 )
				{
					PrintUsage( L"Invalid command-line switch format." );
					return 1;
				}

				switch ( arg[1] )
				{
					case 'd': case 'D':
						idxPath = i+1;
						break;

					case 'm': case 'M':
						idxMask = i+1;
						break;

					case 'f': case 'F':
						idxFormat = i+1;
						break;

					case 't': case 'T':
						idxType = i+1;
						break;

					case 'q': case 'Q':
						idxQuality = i+1;
						break;

					default:
						PrintUsage( L"'%s' is an invalid command-line switch.", arg[1] );
						return 1;
				}

				if ( i+1 >= argc )
				{
					PrintUsage( L"'%s' switch has no value.\n", arg[1] );
					return 1;
				}
			}
		}

		// Validate required parameters.
		if ( idxPath == -1 )
		{
			PrintUsage( L"Input directory is not specified." );
			return 1;
		}

		if ( idxFormat == -1 )
		{
			PrintUsage( L"Output pixel format is not specified." );
			return 1;
		}

		if ( idxType == -1 )
		{
			PrintUsage( L"Output image codec is not specified." );
			return 1;
		}

		// Initialize Synkro.
		PtrSynkro synkro = SynkroCreate( SYNKRO_VERSION, nullptr );
		PtrConfiguration cfg = synkro->GetConfiguration()->Clone();
		cfg->Set( Param::ImagingEnable, true );
		if ( idxQuality != -1 )
		{
			cfg->Set( Param::ImagingCodecQuality, String(argv[idxQuality]) );
		}
		synkro->Initialize( cfg );

		// Prepare parameters.
		String path( argv[idxPath] );
		String type( argv[idxType] );
		String mask = (idxMask != -1) ? String( argv[idxMask] ) : String::Empty;
		PixelFormat format = PixelFormat( String(argv[idxFormat]) );
		if ( format == PixelFormat::Unknown )
			throw Exception( L"Unknown pixel format." );

		// Perform processing.
		P(synkro::io::IStreamDirectory) dir = synkro->GetStreamSystem()->MapDirectory( path, false );
		if ( dir == nullptr )
			throw Exception( L"Specified directory does not exist." );

		if ( !mask.IsEmpty() )
		{
			PtrStreamSet streams = dir->GetStreams( mask );
			for ( UInt i = 0; i < streams->GetSize(); ++i )
			{
				ProcessStream( synkro->GetImageManager(), streams->Get(i), format, type );
			}
		}
		else
		{
			for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
			{
				ProcessStream( synkro->GetImageManager(), dir->GetStream(i), format, type );
			}
		}
	}
	catch ( Exception& ex )
	{
		Char msg[1024];
		ex.Message().GetChars( 0, 1024, msg );
		wprintf( L"Exception: %s\n", msg );
	}

	return 0;
}
