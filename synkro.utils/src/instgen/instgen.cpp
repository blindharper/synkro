//==============================================================================
// Generates installation script.
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

// Retrieves the value of a constant symbol by name.
// e.g. "SYNKRO_VERSION_MAJOR = 1;"
string GetValue( const string& txt, const string& name )
{
	string value;

	const size_t pos = txt.find( name );
	if ( pos != string::npos )
	{
		for ( size_t i = pos+name.length(); txt[i] != ';'; ++i )
		{
			char ch = txt[i];
			if ( (ch >= '0') && (ch <= '9') )
			{
				value.append( string(1, ch) );
			}
		}
	}

	return value;
}

// Extracts Synkro version from SynkroVersion.h file.
string ExtractVersion( const string& filename )
{
	char buf[8192] = {};
	FILE* file = NULL;
	fopen_s( &file, filename.c_str(), "rt" );
	if ( file == NULL )
		return "";

	string txt;
	while ( fgets(buf, 8192, file) )
	{
		string line( buf );
		txt.append( line.substr(0, line.length()-1) );
	}
	fclose( file );

	string major = GetValue( txt, "SYNKRO_VERSION_MAJOR" );
	string minor = GetValue( txt, "SYNKRO_VERSION_MINOR" );
	string patch = GetValue( txt, "SYNKRO_VERSION_PATCH" );
	
	string version;
	version.append( major );
	version.append( "." );
	version.append( minor );
	version.append( "." );
	version.append( patch );

	return version;
}

void GetDirectories( const string& path, vector<string>& dirs )
{
	string fullpath( path );
	fullpath = fullpath.append( "/*" );

	_finddata_t fileinfo;
	intptr_t handle = (intptr_t)_findfirst( fullpath.c_str(), &fileinfo );
	if ( handle == -1 )
		return;

	do
	{
		if ( fileinfo.name[0] == '.' )
			continue;

		if ( (_A_SUBDIR & fileinfo.attrib) == 0 )
			continue;

		string name( fileinfo.name );
		dirs.push_back( name );
	} while ( 0 == _findnext(handle, &fileinfo) );

	_findclose( handle );
}

void GenerateScript( const string& path )
{
	const char* RULER = ";-------------------------------------------------------------------------------\n";
	string txt;

	// Extract version.
	string ver( path );
	ver.append( "\\synkro\\inc\\cfg\\SynkroVersion.h" );
	const string version = ExtractVersion( ver );

	// Header.
	txt.append( RULER );
	txt.append( "; NSIS Modern User Interface Synkro installation script\n" );
	txt.append( RULER );
	txt.append( "\n" );

	// Compression.
	txt.append( RULER );
	txt.append( "; Compression type\n\n" );
	txt.append( "  SetCompressor /SOLID lzma\n\n" );

	// Includes.
	txt.append( RULER );
	txt.append( "; Include Modern UI\n\n" );
	txt.append( "  !include \"MUI2.nsh\"\n\n" );

	// General.
	txt.append( RULER );
	txt.append( "; General\n\n" );
	txt.append( "  ;Name and file\n" );
	txt.append( "  Name \"synkro " );
	txt.append( version );
	txt.append( "\"\n" );

	txt.append( "  OutFile \"..\\bin\\synkro_" );
	txt.append( version );
	txt.append( ".exe\"\n" );
	txt.append( "  Unicode True\n\n" );

	txt.append( "  ;Default installation folder\n" );
	txt.append( "  InstallDir \"$PROGRAMFILES\\synkro\\" );
	txt.append( version );
	txt.append( "\"\n\n" );

	txt.append( "  ;Get installation folder from registry if available\n" );
	txt.append( "  InstallDirRegKey HKCU \"Software\\synkro\\" );
	txt.append( version );
	txt.append( "\" \"\"\n\n" );

	txt.append( "  ;Request application privileges\n" );
	txt.append( "  RequestExecutionLevel admin\n" );

	// Interface settings.
	txt.append( RULER );
	txt.append( "; Interface Settings\n\n" );

	txt.append( "  !define MUI_ABORTWARNING\n" );
	txt.append( "  !define MUI_UNABORTWARNING\n" );
	txt.append( "  !define MUI_HEADERIMAGE\n" );
	txt.append( "  !define MUI_HEADERIMAGE_BITMAP \"..\\images\\install-header.bmp\"\n" );
	txt.append( "  !define MUI_HEADERIMAGE_UNBITMAP \"..\\images\\uninstall-header.bmp\"\n" );
	txt.append( "  !define MUI_ICON \"..\\images\\install.ico\"\n" );
	txt.append( "  !define MUI_UNICON \"..\\images\\uninstall.ico\"\n" );
	txt.append( "  !define MUI_BGCOLOR FFFFFF\n\n" );

	// Pages.
	txt.append( RULER );
	txt.append( "; Pages\n\n" );
	txt.append( "  !define MUI_WELCOMEFINISHPAGE_BITMAP \"..\\images\\install-welcome.bmp\"\n" );
	txt.append( "  !insertmacro MUI_PAGE_WELCOME \n\n" );

	txt.append( "  !insertmacro MUI_PAGE_DIRECTORY\n\n" );

	txt.append( "  !define MUI_INSTFILESPAGE_PROGRESSBAR smooth\n" );
	txt.append( "  !insertmacro MUI_PAGE_INSTFILES\n\n" );

	txt.append( "  !define MUI_FINISHPAGE_NOAUTOCLOSE\n" );
	txt.append( "  !insertmacro MUI_PAGE_FINISH\n\n" );

	txt.append( "  !define MUI_UNWELCOMEFINISHPAGE_BITMAP \"..\\images\\uninstall-welcome.bmp\"\n\n" );

	txt.append( "  !insertmacro MUI_UNPAGE_WELCOME\n" );
	txt.append( "  !insertmacro MUI_UNPAGE_CONFIRM\n" );
	txt.append( "  !insertmacro MUI_UNPAGE_INSTFILES\n\n" );

	txt.append( "  !define MUI_UNFINISHPAGE_NOAUTOCLOSE\n" );
	txt.append( "  !insertmacro MUI_UNPAGE_FINISH\n\n" );

	// Languages.
	txt.append( RULER );
	txt.append( "; Languages\n\n" );
	txt.append( "  !insertmacro MUI_LANGUAGE \"English\" # first language is the default language\n\n" );

	// Installer sections.
	txt.append( RULER );
	txt.append( "; Installer sections\n\n" );

	// Main section.
	txt.append( "Section \"Main Files\" SecMain\n\n" );

	txt.append( "  ;Store installation folder\n" );
	txt.append( "  WriteRegStr HKCU \"Software\\synkro\\" );
	txt.append( version );
	txt.append( "\" \"\" $INSTDIR\n\n" );

	txt.append( "  ;Copy main files\n" );
	txt.append( "  SetOutPath \"$INSTDIR\"\n\n" );

	txt.append( "  ;Create uninstaller\n" );
	txt.append( "  WriteUninstaller \"$INSTDIR\\Uninstall.exe\"\n\n" );

	txt.append( "  ;Binary files\n" );
	txt.append( "  SetOutPath \"$INSTDIR\\synkro\\bin\\win32\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win32\\synkro.lib\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win32\\synkro.res\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win32\\*.dll\"\n\n" );

	txt.append( "  SetOutPath \"$INSTDIR\\synkro\\bin\\win64\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win64\\synkro.lib\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win64\\synkro.res\"\n" );
	txt.append( "  File \"..\\..\\synkro\\bin\\win64\\*.dll\"\n\n" );

	txt.append( "  ;Header files\n" );
	txt.append( "  SetOutPath \"$INSTDIR\\synkro\\inc\"\n" );
	txt.append( "  File \"..\\..\\synkro\\inc\\*.h\"\n\n" );

	string inc( path );
	inc.append( "\\synkro\\inc" );
	vector<string> dirs;
	GetDirectories( inc, dirs );
	for ( size_t i = 0; i < dirs.size(); ++i )
	{
		txt.append( "  SetOutPath \"$INSTDIR\\synkro\\inc\\" );
		txt.append( dirs[i] );
		txt.append( "\"\n" );

		txt.append( "  File \"..\\..\\synkro\\inc\\" );
		txt.append( dirs[i] );
		txt.append( "\\*.h\"\n\n" );
	}

	// Demos.
	txt.append( "  ;Demo projects\n" );
	txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\build\"\n" );
	txt.append( "  File \"..\\..\\synkro.demos\\build\\*.sln\"\n\n" );

	string dmo( path );
	dmo.append( "\\synkro.demos\\build" );
	vector<string> demos;
	GetDirectories( dmo, demos );
	for ( size_t i = 0; i < demos.size(); ++i )
	{
		txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\"\n" );

		txt.append( "  File \"..\\..\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\\" );
		txt.append( demos[i] );
		txt.append( "_msvs2022.vcxproj\"\n" );

		txt.append( "  File \"..\\..\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\\" );
		txt.append( demos[i] );
		txt.append( "_msvs2022.vcxproj.filters\"\n" );

		txt.append( "  File \"..\\..\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\\" );
		txt.append( demos[i] );
		txt.append( "_msvs2022.vcxproj.user\"\n\n" );
	}

	// Demo binaries.
	txt.append( "  ;Demo binaries\n" );
	txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\bin\\win32\"\n" );
	txt.append( "  File \"..\\..\\synkro.demos\\bin\\win32\\_DemoConfig.txt\"\n" );

	for ( size_t i = 0; i < demos.size(); ++i )
	{
		txt.append( "  File \"..\\..\\synkro.demos\\bin\\win32\\" );
		txt.append( demos[i] );
		txt.append( ".exe\"\n" );
	}
	txt.append( "\n" );

	txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\bin\\win64\"\n" );
	txt.append( "  File \"..\\..\\synkro.demos\\bin\\win64\\_DemoConfig.txt\"\n" );

	for ( size_t i = 0; i < demos.size(); ++i )
	{
		txt.append( "  File \"..\\..\\synkro.demos\\bin\\win64\\" );
		txt.append( demos[i] );
		txt.append( ".exe\"\n" );
	}
	txt.append( "\n" );

	// Demo sources.
	txt.append( "  ;Demo sources\n" );
	txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\src\"\n" );
	txt.append( "  File \"..\\..\\synkro.demos\\src\\*.*\"\n\n" );

	txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\src\\demos\"\n" );
	txt.append( "  File \"..\\..\\synkro.demos\\src\\demos\\*.cpp\"\n\n" );

	// Demo media.
	txt.append( "  ;Demo media\n" );

	string md( path );
	md.append( "\\synkro.demos\\media" );
	vector<string> media;
	GetDirectories( md, media );
	for ( size_t i = 0; i < media.size(); ++i )
	{
		txt.append( "  SetOutPath \"$INSTDIR\\synkro.demos\\media\\" );
		txt.append( media[i] );
		txt.append( "\"\n" );

		txt.append( "  File \"..\\..\\synkro.demos\\media\\" );
		txt.append( media[i] );
		txt.append( "\\*.*\"\n\n" );
	}

	// Tutorials.
	txt.append( "  ;Tutorials\n" );

	string tut( path );
	tut.append( "\\synkro.tutorials" );
	vector<string> tutorials;
	GetDirectories( tut, tutorials );
	for ( size_t i = 0; i < tutorials.size(); ++i )
	{
		string phas( path );
		phas.append( "\\synkro.tutorials\\" );
		phas.append( tutorials[i] );
		phas.append( "\\build" );
		vector<string> phases;
		GetDirectories( phas, phases );

		txt.append( "  SetOutPath \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\build\"\n" );

		txt.append( "  File \"..\\..\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\build\\" );
		txt.append( tutorials[i] );
		txt.append( "_msvs2022.sln\"\n\n" );

		for ( size_t p = 0; p < phases.size(); ++p )
		{
			txt.append( "  SetOutPath \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\build\\" );
			txt.append( phases[p] );
			txt.append( "\"\n" );

			txt.append( "  File \"..\\..\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\build\\" );
			txt.append( phases[p] );
			txt.append( "\\*.*\"\n\n" );
		}

		txt.append( "  SetOutPath \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\media\"\n" );

		txt.append( "  File \"..\\..\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\media\\*.*\"\n\n" );

		for ( size_t p = 0; p < phases.size(); ++p )
		{
			txt.append( "  SetOutPath \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\src\\" );
			txt.append( phases[p] );
			txt.append( "\"\n" );

			txt.append( "  File \"..\\..\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\src\\" );
			txt.append( phases[p] );
			txt.append( "\\*.*\"\n\n" );
		}
	}

	// Add search paths.
	txt.append( "  EnVar::SetHKLM\n" );
	txt.append( "  EnVar::AddValue \"Path\" \"$INSTDIR\\synkro\\bin\\win32\"\n" );
	txt.append( "  EnVar::AddValue \"Path\" \"$INSTDIR\\synkro\\bin\\win64\"\n\n" );

	txt.append( "SectionEnd\n\n" );

	// Shortcuts section.
	txt.append( "Section \"Start Menu Shortcuts\" SecShortcuts\n" );
	txt.append( "  SectionIn 1 2\n\n" );

	txt.append( "  SetDetailsPrint textonly\n" );
	txt.append( "  DetailPrint \"Installing Start Menu Shortcuts...\"\n" );
	txt.append( "  SetDetailsPrint listonly\n\n" );

	txt.append( "  SetOutPath $INSTDIR\n\n" );

	txt.append( "  CreateDirectory \"$SMPROGRAMS\\synkro\"\n" );
	txt.append( "  CreateShortCut \"$SMPROGRAMS\\synkro\\Uninstall.lnk\" \"$INSTDIR\\Uninstall.exe\"\n\n" );

	txt.append( "  WriteRegExpandStr HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"UninstallString\" '\"$INSTDIR\\Uninstall.exe\"'\n" );
	txt.append( "  WriteRegExpandStr HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"InstallLocation\" \"$INSTDIR\"\n" );
	txt.append( "  WriteRegStr HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"DisplayName\" \"synkro\"\n" );
	txt.append( "  WriteRegStr HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"DisplayIcon\" \"$INSTDIR\\Uninstall.exe,0\"\n" );
	txt.append( "  WriteRegDWORD HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"NoModify\" \"1\"\n" );
	txt.append( "  WriteRegDWORD HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\" \"NoRepair\" \"1\"\n\n" );

	txt.append( "SectionEnd\n\n" );

	// Uninstaller section.
	txt.append( RULER );
	txt.append( "; Uninstaller section\n" );

	txt.append( "Section \"Uninstall\"\n\n" );

	txt.append( "  ;Remove files\n" );
	txt.append( "  Delete \"$INSTDIR\\synkro\\bin\\win32\\*.*\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro\\bin\\win32\"\n\n" );

	txt.append( "  Delete \"$INSTDIR\\synkro\\bin\\win64\\*.*\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro\\bin\\win64\"\n\n" );

	txt.append( "  RMDir \"$INSTDIR\\synkro\\bin\"\n\n" );

	for ( size_t i = 0; i < dirs.size(); ++i )
	{
		txt.append( "  Delete \"$INSTDIR\\synkro\\inc\\" );
		txt.append( dirs[i] );
		txt.append( "\\*.h\"\n" );

		txt.append( "  RMDir \"$INSTDIR\\synkro\\inc\\" );
		txt.append( dirs[i] );
		txt.append( "\"\n\n" );
	}

	txt.append( "  Delete \"$INSTDIR\\synkro\\inc\\*.h\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro\\inc\"\n\n" );

	txt.append( "  RMDir \"$INSTDIR\\synkro\"\n\n" );

	// Demos.
	for ( size_t i = 0; i < media.size(); ++i )
	{
		txt.append( "  Delete \"$INSTDIR\\synkro.demos\\media\\" );
		txt.append( media[i] );
		txt.append( "\\*.*\"\n" );

		txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\media\\" );
		txt.append( media[i] );
		txt.append( "\"\n\n" );
	}
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\media\"\n\n" );

	txt.append( "  Delete \"$INSTDIR\\synkro.demos\\src\\demos\\*.cpp\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\src\\demos\"\n\n" );

	txt.append( "  Delete \"$INSTDIR\\synkro.demos\\src\\*.*\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\src\"\n\n" );

	txt.append( "  Delete \"$INSTDIR\\synkro.demos\\bin\\win32\\*.*\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\bin\\win32\"\n\n" );
	
	txt.append( "  Delete \"$INSTDIR\\synkro.demos\\bin\\win64\\*.*\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\bin\\win64\"\n\n" );

	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\bin\"\n\n" );

	for ( size_t i = 0; i < demos.size(); ++i )
	{
		txt.append( "  Delete \"$INSTDIR\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\\*.*\"\n" );

		txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\build\\" );
		txt.append( demos[i] );
		txt.append( "\"\n\n" );
	}

	txt.append( "  Delete \"$INSTDIR\\synkro.demos\\build\\*.sln\"\n" );
	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\\build\"\n\n" );

	txt.append( "  RMDir \"$INSTDIR\\synkro.demos\"\n\n" );

	// Tutorials.
	for ( size_t i = 0; i < tutorials.size(); ++i )
	{
		string phas( path );
		phas.append( "\\synkro.tutorials\\" );
		phas.append( tutorials[i] );
		phas.append( "\\build" );
		vector<string> phases;
		GetDirectories( phas, phases );

		txt.append( "  Delete \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\build\\*.sln\"\n\n" );

		for ( size_t p = 0; p < phases.size(); ++p )
		{
			txt.append( "  Delete \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\build\\" );
			txt.append( phases[p] );
			txt.append( "\\*.*\"\n" );

			txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\build\\" );
			txt.append( phases[p] );
			txt.append( "\"\n\n" );
		}

		txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\build\"\n\n" );

		txt.append( "  Delete \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\media\\*.*\"\n" );
		
		txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\media\"\n\n" );

		for ( size_t p = 0; p < phases.size(); ++p )
		{
			txt.append( "  Delete \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\src\\" );
			txt.append( phases[p] );
			txt.append( "\\*.*\"\n" );

			txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
			txt.append( tutorials[i] );
			txt.append( "\\src\\" );
			txt.append( phases[p] );
			txt.append( "\"\n\n" );
		}
		
		txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\\src\"\n\n" );

		txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\\" );
		txt.append( tutorials[i] );
		txt.append( "\"\n\n" );
	}
	txt.append( "  RMDir \"$INSTDIR\\synkro.tutorials\"\n\n" );

	txt.append( "  Delete \"$INSTDIR\\Uninstall.exe\"\n" );
	txt.append( "  RMDir \"$INSTDIR\"\n\n" );

	txt.append( "  DeleteRegKey HKLM \"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\synkro\"\n" );
	txt.append( "  DeleteRegKey HKLM \"Software\\synkro\"\n\n" );

	txt.append( "  SetShellVarContext all\n" );
	txt.append( "  Delete \"$SMPROGRAMS\\synkro\\*.*\"\n" );
	txt.append( "  RMDir /r \"$SMPROGRAMS\\synkro\"\n\n" );

	txt.append( "  SetShellVarContext current\n" );
	txt.append( "  Delete \"$SMPROGRAMS\\synkro\\*.*\"\n" );
	txt.append( "  RMDir /r \"$SMPROGRAMS\\synkro\"\n\n" );

	txt.append( "  DeleteRegKey /ifempty HKCU \"Software\\synkro\\" );
	txt.append( version );
	txt.append( "\"\n\n" );

	// Remove search paths.
	txt.append( "  EnVar::SetHKLM\n" );
	txt.append( "  EnVar::DeleteValue \"Path\" \"$INSTDIR\\synkro\\bin\\win32\"\n" );
	txt.append( "  EnVar::DeleteValue \"Path\" \"$INSTDIR\\synkro\\bin\\win64\"\n\n" );

	txt.append( "SectionEnd\n\n" );

	txt.append( RULER );
	txt.append( "; End of script\n" );
	txt.append( RULER );

	string dir( path );
	WriteFile( dir.append("\\synkro.output\\src\\synkro.nsi"), txt );
}

int main( int argc, char* argv[] )
{
	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: instgen.exe: <path>";
		return 1;
	}

	GenerateScript( argv[1] );

	return 0;
}
