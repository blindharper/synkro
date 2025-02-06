//==============================================================================
// Generates preliminary interface declarations.
//==============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <io.h>

using namespace std;

// Writes a piece of text to the specified file.
void WriteFile( const string& fw, const string& text )
{
	FILE* file = NULL;
	fopen_s( &file, fw.c_str(), "wt" );
	if ( file )
	{ 
		fwrite( text.c_str(), 1, text.length(), file );
		fclose( file );
	}
}

// Reads source file header from the specified file.
vector<string> ReadHeader( const string& fh )
{
	vector<string> hdr;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, fh.c_str(), "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			hdr.push_back( line.substr(0, line.length()-1) );
		}
		fclose( file );
	}

	return hdr;
}

bool IsValid( const string& name )
{
	if ( (name[0] == 'I') && isupper(name[1]) )
		return true;

	if ( name.find("Listener") != string::npos )
		return true;

	if ( name.find("Context") != string::npos )
		return true;

	size_t pos = name.find( "Message" );
	if ( (pos != string::npos) && (pos != 0) )
		return true;

	if ( name.find("Method") != string::npos )
		return true;

	if ( name.find("Param") != string::npos )
		return true;

	if ( name.find("Task") != string::npos )
		return true;
	
	return false;
}

void ExploreNamespace( const string& path, vector<string>& ifaces )
{
	string fullpath( path );
	fullpath = fullpath.append( "/*" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle == -1 )
		return;

	do
	{
		string name( fileinfo.name );
		if ( name.length() < 4 )
			continue;

		name = name.substr( 0, name.length()-2 );
		if ( IsValid(name) )
		{
			ifaces.push_back( name );
		}
	} while ( 0 == _findnext( handle, &fileinfo ) );

	_findclose( handle );
}

void ExploreDirectory( const string& path, const string& pathHdr )
{
	string dir( path );
	string fullpath( path );
	fullpath = fullpath.append( "/*" );

	// Read header.
	vector<string> hdr = ReadHeader( pathHdr );

	// Write header.
	string txt;
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txt.append( hdr[i] ).append( "Preliminary declarations of Synkro interfaces" ).append(".");
		else
			txt.append( hdr[i] );

		txt.append( "\n" );
	}

	txt.append( "namespace synkro" );
	txt.append( "\n" );
	txt.append( "{\n\n\n" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle == -1 )
		return;

	do
	{
		if ( fileinfo.name[0] != '.' )
		{
			string tmp( dir );
			tmp = tmp.append("/").append(fileinfo.name);

			if ( (_A_SUBDIR & fileinfo.attrib) != 0 )
			{
				vector<string> ifaces;
				ExploreNamespace( tmp, ifaces );
				if ( ifaces.size() > 0 )
				{
					txt.append("namespace ");
					txt.append(fileinfo.name);
					txt.append("\n");
					txt.append( "{\n\n" );

					for ( size_t i = 0; i < ifaces.size(); ++i )
					{
						txt.append("iface ");
						txt.append(ifaces[i]);
						txt.append(";\n");
					}

					txt.append("\n");
					txt.append("} // ");
					txt.append(fileinfo.name);
					txt.append("\n\n");
				}
			}
		}
	} while ( 0 == _findnext( handle, &fileinfo ) );

	_findclose( handle );

	txt.append("\n");
	txt.append("} // synkro");
	txt.append("\n");

	WriteFile( dir.append("\\cfg\\Interfaces.h"), txt );
}

int main( int argc, char* argv[] )
{
	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: ifacegen.exe: <path>";
		return 1;
	}

	string pathHdr( argv[0] );
	pathHdr = pathHdr.substr( 0, pathHdr.length()-12 );
	pathHdr.append( "\\data\\header.txt" );
	ExploreDirectory( argv[1], pathHdr );

	return 0;
}
