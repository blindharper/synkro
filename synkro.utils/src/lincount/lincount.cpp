//==============================================================================
// Calculates the total number of lines in the c++ files.
//==============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <io.h>

using namespace std;

int CountLines( const char* filename )
{
	int lines = 0;
	
	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename, "rt" );
	if ( file )
	{ 
		bool comment = false;
		++lines;
		while ( fgets(buf, 8192, file) )
		{
			size_t pos;
			string line( buf );
			while ( (pos = line.find('\t') == 0) )
			{
				line.assign( line.substr(1) );
			}
			while ( (pos = line.rfind('\t') == line.length()-1) )
			{
				line.assign( line.substr(0, line.length()-1) );
			}

			if ( line.find("//") == 0 )
				continue;

			if ( comment )
			{
				pos = line.find("*/");
				if ( pos+2 == line.length() )
					comment = false;
			}

			if ( line.find("/*") == 0 )
				comment = true;

			if ( !comment )
				++lines;
		}
		fclose( file );
	}

	return lines;
}

bool EndsWith( const string& str, const string& end )
{
	size_t pos = str.rfind( end );
	if ( pos == string::npos )
		return false;

	return pos+end.length() == str.length();
}

void ExploreDirectory( const char* path, int& folders, int& files, int& lines, _fsize_t& size )
{
	string dir( path );
	string fullpath( path );
	fullpath = fullpath.append( "/*" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle != -1 )
	{
		do
		{
			if ( fileinfo.name[0] != '.' )
			{
				string tmp( dir );
				tmp = tmp.append("/").append(fileinfo.name);

				if ( (_A_SUBDIR & fileinfo.attrib) != 0 )
				{
					if ( EndsWith(tmp, "external") || EndsWith(tmp, "tests") ||
						 EndsWith(tmp, "bin") || EndsWith(tmp, "build") ||
						 EndsWith(tmp, "lib") || EndsWith(tmp, "obj") )
						continue;

					++folders;
					ExploreDirectory( tmp.c_str(), folders, files, lines, size );
				}
				else
				{
					// Skip fake header files.
					bool isH = EndsWith(tmp, ".h");
					if ( isH && EndsWith(tmp, "config.h") )
						continue;

					// Skip generated resources.
					bool isCpp = EndsWith(tmp, ".cpp");
					if ( isCpp && (EndsWith(tmp, "programs.cpp") || EndsWith(tmp, "resources.cpp")) )
						continue;

					// Count only source files.
					bool ok = isH || isCpp || 
						EndsWith(tmp, ".inl") || EndsWith(tmp, ".c") ||
						EndsWith(tmp, ".vs") || EndsWith(tmp, ".vsh") ||
						EndsWith(tmp, ".gs") || EndsWith(tmp, ".gsh") ||
						EndsWith(tmp, ".hs") || EndsWith(tmp, ".hsh") ||
						EndsWith(tmp, ".ds") || EndsWith(tmp, ".dsh") ||
						EndsWith(tmp, ".fs") || EndsWith(tmp, ".fsh");
					if ( !ok )
						continue;

					++files;
					lines += CountLines( tmp.c_str() );
					size += fileinfo.size;
				}
			}
		} while ( 0 == _findnext( handle, &fileinfo ) );

		_findclose( handle );
	}
}

int main( int argc, char* argv[] )
{
	const char* path = "";		// Input path.
	int folders = 0; int files = 0; int lines = 0; _fsize_t size = 0;

	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: lincount.exe: <path>";
		return 1;
	}

	path = argv[1];
	ExploreDirectory( path, folders, files, lines, size );

	char buf[128];
	time_t t; time( &t );
	tm newtime; localtime_s( &newtime, &t );
	char asc[128];
	asctime_s( asc, &newtime );
	sprintf_s( buf, "%s", asc );

	cout << buf << "Total folders: " << folders << ". Total files: " << files << ". Total lines: " << lines << ". Total size: " << size << "." << endl << endl;

	return 0;
}
