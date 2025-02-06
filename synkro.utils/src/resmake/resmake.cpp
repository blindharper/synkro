//==============================================================================
// Assembles packed resource files.
//==============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <io.h>
using namespace std;

string DoReplace( const string& str, const string& from, const string& to )
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

string GetParentDir( const string& path )
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

const char* GetExtension( const char* filename )
{
	const char* dot = strrchr( filename, '.' );
	if ( dot != 0 )
	{
		return dot+1;
	}
	return "";
}

void GetLastModified( const char* path, __time64_t* time )
{
	*time = -1;

	_finddata_t fileinfo;
	long handle = (long)_findfirst( path, &fileinfo );
	if ( handle != -1 )
	{
		*time = fileinfo.time_write;
		_findclose( handle );
	}
}

bool BuildRequired( const char* path, __time64_t time )
{
	string dir( path );
	string fullpath( path );
	fullpath = fullpath.append( "\\*" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle != -1 )
	{
		do
		{
			if ( fileinfo.name[0] != '.' )
			{
				string tmp( dir );
				tmp = tmp.append("\\").append(fileinfo.name);

				if ( (_A_SUBDIR & fileinfo.attrib) != 0 )
				{
					bool ok = BuildRequired( tmp.c_str(), time );
					if ( ok )
						return true;
				}
				else
				{
					if ( fileinfo.time_write > time )
						return true;
				}
			}
		} while ( 0 == _findnext( handle, &fileinfo ) );

		_findclose( handle );
	}

	return false;
}

int main( int argc, char* argv[] )
{
	FILE* file = NULL;				// input file handle.
	const char* makefile = "";		// makefile name.
	char outfile[260];				// output file name.
	char tmpfile[260];				// temporary file name.
	char indir[260];				// input directory name.

	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: resmake.exe: <makefile>" << endl;
		return 1;
	}

	// Extract makefile name.
	makefile = argv[1];
	int len = strlen( makefile );

	string parentDir = GetParentDir( argv[0] );
	parentDir = GetParentDir( parentDir );

	// Locate output file and extract its modification date.
	strcpy_s( tmpfile, makefile );
	tmpfile[len-3] = 'p';
	tmpfile[len-2] = 'a';
	tmpfile[len-1] = 'k';

	strcpy_s( outfile, makefile );
	outfile[len-3] = 'c';
	outfile[len-2] = 'p';
	outfile[len-1] = 'p';
	__time64_t dt_last_build = -1;
	GetLastModified( outfile, &dt_last_build );

	// Scan input directory and see if there're any modified files.
	strcpy_s( indir, makefile );
	indir[len-4] = 0;
	if ( (dt_last_build != -1) && !BuildRequired(indir, dt_last_build) )
		return 0;

	// Remove outdated output files.
	cout << "Building resource '" << makefile << "'..." << endl;
	_unlink( outfile );
	_unlink( tmpfile );
	
	// Use respack.exe to create .pak file.
	string cmdPack( argv[0] );	
	cmdPack = DoReplace( cmdPack, "resmake", "respack" );
	cmdPack = cmdPack.append( " \"" );
	cmdPack = cmdPack.append( indir );
	cmdPack = cmdPack.append( "\"" );
	system( cmdPack.c_str() );

	// Use resgen.exe to create output file.
	string cmdGen( argv[0] );
	cmdGen = DoReplace( cmdGen, "resmake", "resgen" );
	cmdGen = cmdGen.append( " \"" );
	cmdGen = cmdGen.append( tmpfile );
	cmdGen = cmdGen.append( "\"" );
	system( cmdGen.c_str() );

	// Remove temporary file.
	_unlink( tmpfile );

	return 0;
}
