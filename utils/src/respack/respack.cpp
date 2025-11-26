//==============================================================================
// Performs resource file generation.
//==============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <io.h>
#include <zlib/zip.h>
using namespace std;

static string DoReplace( const string& str, const string& from, const string& to )
{
	string strTarget( str );
	size_t pos = strTarget.find( from );

	while ( pos != string::npos )
	{
		strTarget.replace( pos, from.length(), to );
		pos = strTarget.find( from, pos+to.length() );
	}

	return strTarget;
}

static string GetParentDir( const string& path )
{
	string dir( path );

	dir = DoReplace( dir, "/", "\\" );
	size_t pos = dir.rfind( "\\" );
	if ( pos != string::npos )
	{
		dir = dir.substr( 0, pos );
	}

	return dir;
}

static bool FileExists( const string& filename )
{
	FILE* file = NULL;
	fopen_s( &file, filename.c_str(), "rb" );
	if ( file != NULL )
	{
		fclose( file );
		return true;
	}
	return false;
}

void AddFile( zipFile zip, const string& filename, const string& path )
{
	zip_fileinfo info;
	memset( &info, 0, sizeof(info) );
	info.dosDate = 1;
	int res = zipOpenNewFileInZip( zip, path.c_str(), &info, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_BEST_COMPRESSION );
	if ( res == ZIP_OK )
	{
		char buf[8192];
		size_t bytes;
		FILE* file = NULL;
		fopen_s( &file, filename.c_str(), "rb" );
		if ( file )
		{
			while ( bytes = fread(buf, 1, 8192, file) )
			{
				zipWriteInFileInZip( zip, buf, (unsigned int)bytes );
			}
			fclose( file );
		}
		zipCloseFileInZip( zip );
	}
}

void ProcessDirectory( zipFile zip, const string& dir, const string& path )
{
	string prefix;
	if ( path.length() != 0 )
	{
		prefix.assign( path );
		prefix = prefix.append( "/" );
	}
	string fullpath( dir );
	fullpath = fullpath.append( "\\*.*" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle != -1 )
	{
		do
		{
			if ( fileinfo.name[0] != '.' )
			{
				string tmp( GetParentDir(fullpath) );
				tmp = tmp.append("\\").append(fileinfo.name);

				if ( (_A_SUBDIR & fileinfo.attrib) == 0 )
				{
					string p(prefix);
					p = p.append( fileinfo.name );
					AddFile( zip, tmp, p );
				}
				else
				{
					string p(prefix);
					p = p.append( fileinfo.name );
					ProcessDirectory( zip, tmp, p );
				}
			}
		} while ( _findnext(handle, &fileinfo) == 0 );

		_findclose( handle );
	}
}

int main( int argc, char* argv[] )
{
	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: respack.exe: <path>" << endl;
		return 1;
	}

	// Verify resource directory.
	string manifest( argv[1] );
	manifest = manifest.append( "\\manifest.xml" );
	if ( !FileExists(manifest) )
	{
		cout << "Bad resource directory. Failed to locate file 'manifest.xml'." << endl;
		return 1;
	}

	// Create output file.
	string archive( argv[1] );
	archive = archive.append( ".pak" );
	zipFile zip = zipOpen( (void*)archive.c_str(), 0 );

	// Add files.
	string dir( argv[1] );
	ProcessDirectory( zip, dir, "" );

	// Close archive.
	zipClose( zip, "" );
	return 0;
}
