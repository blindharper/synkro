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
// Purpose: 'Mesh Converter' tool.
//==============================================================================
#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::scene;
using namespace synkro;

//------------------------------------------------------------------------------


void ProcessStream( ISceneManager* sceneManager, IStream* stream, IStreamDirectory* outDir, const DataMode& mode, const String& type )
{
	PtrTriangleMesh mesh = sceneManager->LoadMesh( stream, nullptr );
	if ( mesh != nullptr )
	{
		IStreamDirectory* dir = (outDir != nullptr) ? outDir : stream->GetDirectory();
		UInt idxDot = stream->GetName().LastIndexOf( L'.' );
		String ext = stream->GetName().Substring( idxDot+1 );
		PtrStream streamOut = dir->CreateStream( stream->GetName().TrimEnd(ext).Append(type) );
		mesh->Save( streamOut, mode, type );
	}
}

void PrintUsage( const wchar_t* message, ... )
{
	va_list argptr;

	va_start( argptr, message );
	wprintf( message, argptr );
	va_end( argptr );

	wprintf( L"\nUsage: MeshConverter.exe /d directory [/o outdir] [/m mask] /f mode /t type" );
}

int main( int argc, char* argv[] )
{
	try
	{
		// Parse command line.
		int idxPath = -1; int idxOut = -1; int idxMask = -1; int idxMode = -1; int idxType = -1;
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

					case 'o': case 'O':
						idxOut = i+1;
						break;

					case 'm': case 'M':
						idxMask = i+1;
						break;

					case 'f': case 'F':
						idxMode = i+1;
						break;

					case 't': case 'T':
						idxType = i+1;
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

		if ( idxMode == -1 )
		{
			PrintUsage( L"Output data format is not specified." );
			return 1;
		}

		if ( idxType == -1 )
		{
			PrintUsage( L"Output mesh codec is not specified." );
			return 1;
		}

		// Initialize Synkro.
		PtrSynkro synkro = SynkroCreate( SYNKRO_VERSION, nullptr );
		PtrConfiguration cfg = synkro->GetConfiguration()->Clone();
		cfg->Set( Param::ImagingEnable, false );
		synkro->Initialize( cfg );

		// Prepare parameters.
		String path( argv[idxPath] );
		String out = (idxOut != -1) ? String( argv[idxOut] ) : String::Empty;
		String type( argv[idxType] );
		String mask = (idxMask != -1) ? String( argv[idxMask] ) : String::Empty;
		DataMode mode = DataMode( String(argv[idxMode]) );
		if ( mode == DataMode::Unknown )
			throw Exception( L"Unknown data mode." );

		// Perform processing.
		PtrStreamDirectory dir = synkro->GetStreamSystem()->MapDirectory( path, false );
		if ( dir == nullptr )
			throw Exception( L"Specified directory does not exist." );

		PtrStreamDirectory outDir = !out.IsEmpty() ? synkro->GetStreamSystem()->MapDirectory( out, false ) : nullptr;
		if ( !mask.IsEmpty() )
		{
			PtrStreamSet streams = dir->GetStreams( mask );
			for ( UInt i = 0; i < streams->GetSize(); ++i )
			{
				ProcessStream( synkro->GetSceneManager(), streams->Get(i), outDir, mode, type );
			}
		}
		else
		{
			for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
			{
				ProcessStream( synkro->GetSceneManager(), dir->GetStream(i), outDir, mode, type );
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
