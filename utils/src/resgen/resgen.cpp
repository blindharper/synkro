//==============================================================================
// Performs resource file generation.
//==============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main( int argc, char* argv[] )
{
	FILE* fileIn = NULL;		// input stream.
	FILE* fileOut = NULL;		// output stream.
	const char* file = "";		// input filename.
	char fileRes[260];			// resource filename.
	char filename[260];			// output filename.
	char name[260];				// filename w/o extension.
	const char* var = "";		// resource variable name.

	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: resgen.exe: <filename>" << endl;
		return 1;
	}

	// Extract input filename.
	file = argv[1];
	strcpy_s( fileRes, file );
	const char* p = strrchr( fileRes, '.' );
	if ( p )
	{
		int idx = p-fileRes;
		strncpy_s( name, fileRes, idx );
		name[idx] = 0;
	}
	else
	{
		strcpy_s( name, fileRes );
	}
	strcpy_s( filename, name );
	strcat_s( filename, ".cpp" );

	cout << "Generating binary resource file '" << filename << "'" << endl;

	fopen_s( &fileOut, filename, "wt" );
	if ( !fileOut )
	{
		cout << "Error: Failed to open file " << filename << " for writing." << endl;
		return 1;
	}

	// Get variable names.
	char* q = strrchr( name, '\\' );
	*q = '_';
	
	for ( size_t i = 0; i < 2; ++i )
	{
		q = strrchr( name, '.' );
		if ( q )
			*q = '_';
	}

	var = strrchr( name, '\\' );
	if ( var )
		++var;
	else
		var = name;

	fprintf( fileOut, "#include \"config.h\"\n\n" );
	fprintf( fileOut, "unsigned __int8 res_%s[] = \n{\n", var );

	// Open input file.
	fopen_s( &fileIn, file, "rb" );
	if ( fileIn )
	{
		unsigned __int8 ch;
		char buf[32];
		memset( buf, 0, 32 );
		int count = 0;
		while ( fread(&ch, 1, 1, fileIn) > 0 )
		{
			fprintf( fileOut, "0x%2.2X, ", ch );
			if ( ++count >= 16 )
			{
				fputs( "\n", fileOut );
				count = 0;
			}
		}
		if ( count > 0 )
		{
			fputs( "\n", fileOut );
		}

		fclose( fileIn );
	}

	fprintf( fileOut, "};\n" );
	fprintf( fileOut, "unsigned __int32 res_%s_size = sizeof( res_%s );\n", var, var );
	fclose( fileOut );
	return 0;
}
