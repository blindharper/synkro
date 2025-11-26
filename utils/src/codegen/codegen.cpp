//==============================================================================
// Performs automatic code generation from the supplied description file.
//==============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <time.h>
#include <io.h>

using namespace std;

// Interface description.
struct IfaceDesc
{
	string				Name;
	string				Base;
	vector<string>		NameSpaces;
	vector<string>		Methods;
};

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
vector<string> ReadHeader( const string& fh)
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

IfaceDesc ReadIfaceDesc( const string& fileID )
{
	IfaceDesc desc;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, fileID.c_str(), "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			line = line.substr( 0, line.length()-1 );

			size_t pos = string::npos;
			if ( (pos = line.find("namespace ")) != string::npos )
			{
				string ns = line.substr( pos+10 );
				desc.NameSpaces.push_back( ns );
			}
			else if ( (pos = line.find("iface ")) != string::npos )
			{
				string iface = line.substr( pos+6, line.length()-8 );
				desc.Name = iface;
			}
			else if ( (pos = line.find("\tpublic ")) != string::npos )
			{
				string base = line.substr( pos+8, line.length()-2 );
				desc.Base = base;
			}
			else if ( (pos = line.find("\tvirtual ")) != string::npos )
			{
				string method = line.substr( pos+9, line.length()-14 );
				desc.Methods.push_back( method );
			}
		}
		fclose( file );
	}

	return desc;
}

map<string,string> ReadConfig( const string& fileCfg )
{
	map<string,string> cfg;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, fileCfg.c_str(), "rt" );
	if ( file )
	{
		int c = 0;
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			size_t pos = string::npos;
			if ( (pos = line.find(":")) != string::npos )
			{
				string key = line.substr( 0, pos );
				if ( key.find("Const") != string::npos )
				{
					char buf[16];
					_itoa_s( c++, buf, 10 );
					key.assign( key.append(buf) );
				}
				string val = line.substr( pos+1 );
				cfg[key] = val.substr(0, val.length()-1);
			}
		}
		fclose( file );
	}

	return cfg;
}

string GenerateIncGuard( const string& name, const vector<string>& ns )
{
	string inc = "_";
	char buf[100];

	for ( size_t i = 0; i < ns.size(); ++i )
	{
		string tmp = ns[i];
		strcpy_s( buf, tmp.c_str() );
		_strupr_s( buf );
		inc.append( buf ).append("_");
	}
	string nam = name;
	strcpy_s( buf, nam.c_str() );
	_strupr_s( buf );
	inc.append( buf ).append("_");

	return inc;
}

string ReplaceText( const string& str, const string& from, const string& to )
{
	size_t pos = str.find( from );
	string tmp = str;
	while ( pos != string::npos )
	{
		tmp.replace( pos, from.length(), to );
		pos = tmp.find( from, pos );
	}
	return tmp;
}

string ReplaceTextFirst( const string& str, const string& from, const string& to )
{
	size_t pos = str.find( from );
	string tmp = str;
	if ( pos != string::npos )
	{
		tmp.replace( pos, from.length(), to );
		pos = tmp.find( from, pos+1 );
	}
	return tmp;
}


//------------------------------------------------------------------------------
// CreateIfaceImpl
//------------------------------------------------------------------------------
void CreateIfaceImpl( map<string,string>& cfg )
{
	string strIface = cfg["Iface"];
	string strPurpose = cfg["Purpose"];
	string strDescription = cfg["Description"];
	string strName = cfg["Name"];
	string strBase = cfg["Base"];
	string strNamespace = cfg["Namespace"];
	string strDestination = cfg["Destination"];
	vector<string> ns;
	size_t posDot = strNamespace.find(".");
	if ( posDot == string::npos )
	{
		ns.push_back( strNamespace );
	}
	else
	{
		string ns1 = strNamespace.substr( 0, posDot );
		string ns2 = strNamespace.substr( posDot+1 );
		ns.push_back( ns1 );
		ns.push_back( ns2 );
	}

	// Read interface description.
	IfaceDesc descIface = ReadIfaceDesc( strIface );

	// Read header.
	vector<string> hdr = ReadHeader( "data\\header.txt" );

	// Write source file (.h)
	string txtH;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtH.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtH.append( hdr[i] );

		txtH.append( "\n" );
	}

	// Write inclusion guard.
	string inc = GenerateIncGuard( strName, ns );
	txtH.append("#ifndef ").append(inc).append("\n");
	txtH.append("#define ").append(inc).append("\n");
	txtH.append("\n").append("\n");

	// Write includes.
	txtH.append( "#include \"config.h\"\n" );
	txtH.append( "#include <" ).append(ReplaceText(strBase, "::", "/")).append(".h>\n");
	txtH.append("\n").append("\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtH.append("namespace ").append(ns[i]).append("\n{\n");
		txtH.append("\n").append("\n");
	}

	// Write class description and declaration.
	txtH.append("// ").append( strDescription ).append(".\n");
	txtH.append("template <class T>\n");
	txtH.append("class ").append(strName).append(" :\n");
	txtH.append("\tpublic ").append(strBase).append("<T>\n");
	txtH.append("{\n");
	txtH.append("public:\n");
	txtH.append("\t// Constructor & destructor.\n");
	txtH.append("\t").append(strName).append("();\n");
	txtH.append("\tvirtual ~").append(strName).append("();\n\n");

	// Write methods.
	txtH.append("\t// ").append(descIface.Name).append(" methods.\n");
	for ( size_t i = 0; i < descIface.Methods.size(); ++i )
	{
		txtH.append("\tvirtual ").append(descIface.Methods[i]).append(";\n");
	}
	txtH.append("\n");
	txtH.append("protected:\n");
	txtH.append("};\n");
	txtH.append("\n");
	txtH.append("\n");

	// Write inline include.
	txtH.append("#include \"").append(strName).append(".inl\"\n");

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtH.append("\n");
		txtH.append("\n");
		txtH.append("} // ").append(ns[i]).append("\n");
	}

	// Close inclusion guard.
	txtH.append("\n");
	txtH.append("\n");
	txtH.append("#endif // ").append(inc);
	txtH.append("\n");

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".h", txtH );

	//--------------------------------------------------------------------------

	// Write source file (.inl)
	string txtInl;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtInl.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtInl.append( hdr[i] );

		txtInl.append( "\n" );
	}

	// Write constructor.
	txtInl.append("template <class T>\n");
	txtInl.append("SYNKRO_INLINE ").append(strName).append("<T>::").append(strName).append("()\n");
	txtInl.append("{\n");
	txtInl.append("}\n");
	txtInl.append("\n");

	// Write destructor.
	txtInl.append("template <class T>\n");
	txtInl.append("SYNKRO_INLINE ").append(strName).append("<T>::~").append(strName).append("()\n");
	txtInl.append("{\n");
	txtInl.append("}\n");

	// Write methods.
	for ( size_t i = 0; i < descIface.Methods.size(); ++i )
	{
		string method(" ");
		method.append(strName).append("<T>::");
		method = ReplaceTextFirst( descIface.Methods[i], "\t", method );
		method = ReplaceText( method, "\t", "" );

		txtInl.append("\ntemplate <class T>\n");
		txtInl.append("SYNKRO_INLINE ").append(method).append("\n");
		txtInl.append("{\n");
		txtInl.append("\t// TODO:\n");
		if ( method.find("void") == string::npos )
		{
			txtInl.append("\treturn 0;\n");
		}
		txtInl.append("}\n");
	}

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".inl", txtInl );
}

//------------------------------------------------------------------------------
// CreateClass
//------------------------------------------------------------------------------
void CreateClass( map<string,string>& cfg )
{
	string strIface = cfg["Iface"];
	string strPurpose = cfg["Purpose"];
	string strDescription = cfg["Description"];
	string strName = cfg["Name"];
	string strBase = cfg["Base"];
	string strBaseIface = cfg["BaseIface"];
	string strNamespace = cfg["Namespace"];
	string strDestination = cfg["Destination"];
	vector<string> ns;
	size_t posDot = strNamespace.find(".");
	if ( posDot == string::npos )
	{
		ns.push_back( strNamespace );
	}
	else
	{
		string ns1 = strNamespace.substr( 0, posDot );
		string ns2 = strNamespace.substr( posDot+1 );
		ns.push_back( ns1 );
		ns.push_back( ns2 );
	}

	// Read interface description.
	IfaceDesc descIface = ReadIfaceDesc( strIface );

	// Read header.
	vector<string> hdr = ReadHeader( "data\\header.txt" );

	// Write source file (.h)
	string txtH;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtH.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtH.append( hdr[i] );

		txtH.append( "\n" );
	}

	// Write inclusion guard.
	string inc = GenerateIncGuard( strName, ns );
	txtH.append("#ifndef ").append(inc).append("\n");
	txtH.append("#define ").append(inc).append("\n");
	txtH.append("\n").append("\n");

	// Write includes.
	txtH.append( "#include \"config.h\"\n" );
	txtH.append( "#include <" ).append(ReplaceText(strBase, "::", "/")).append(".h>\n\n\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtH.append("namespace ").append(ns[i]).append("\n{\n");
		txtH.append("\n").append("\n");
	}

	// Write class description and declaration.
	txtH.append("// ").append( strDescription ).append(".\n");
	txtH.append("class ").append(strName).append(" :\n");
	txtH.append("\tpublic ").append(strBase).append("<").append(strBaseIface).append(">\n");
	txtH.append("{\n");
	txtH.append("public:\n");
	txtH.append("\t// Constructor.\n");
	txtH.append("\t").append(strName).append("();\n\n");

	// Write methods.
	txtH.append("\t// ").append(descIface.Name).append(" methods.\n");
	for ( size_t i = 0; i < descIface.Methods.size(); ++i )
	{
		string method( descIface.Methods[i] );
		method = ReplaceTextFirst( method, "\t", "\t\t" );
		method = ReplaceTextFirst( method, "\t", "\t\t" );
		txtH.append("\t").append(method).append(";\n");
	}
	txtH.append("\n");
	txtH.append("private:\n");
	txtH.append("};\n");

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtH.append("\n");
		txtH.append("\n");
		txtH.append("} // ").append(ns[i]).append("\n");
	}

	// Close inclusion guard.
	txtH.append("\n");
	txtH.append("\n");
	txtH.append("#endif // ").append(inc);
	txtH.append("\n");

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".h", txtH );

	//--------------------------------------------------------------------------

	// Write source file (.cpp)
	string txtCpp;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtCpp.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtCpp.append( hdr[i] );

		txtCpp.append( "\n" );
	}

	// Write includes.
	txtCpp.append( "#include \"config.h\"\n" );
	txtCpp.append( "#include \"" ).append(strName).append(".h\"\n\n\n");

	// Write "using" directives.
	string line( "//------------------------------------------------------------------------------\n\n" );
	txtCpp.append( line );
	txtCpp.append( "using namespace synkro::core;\n\n" );
	txtCpp.append( line ).append( "\n" );

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtCpp.append("namespace ").append(ns[i]).append("\n{\n\n\n");
	}

	// Write constructor.
	txtCpp.append(strName).append("::").append(strName).append("()\n");
	txtCpp.append("{\n");
	txtCpp.append("}\n");

	// Write methods.
	for ( size_t i = 0; i < descIface.Methods.size(); ++i )
	{
		string method(" ");
		method.append(strName).append("::");
		method = ReplaceTextFirst( descIface.Methods[i], "\t", method );
		method = ReplaceText( method, "\t", "" );
		method = ReplaceText( method, "core::", "" );

		txtCpp.append("\n");
		txtCpp.append(method).append("\n");
		txtCpp.append("{\n");
		txtCpp.append("\t// TODO:\n");
		if ( method.find("void") == string::npos )
		{
			txtCpp.append("\treturn 0;\n");
		}
		txtCpp.append("}\n");
	}

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtCpp.append("\n");
		txtCpp.append("\n");
		txtCpp.append("} // ").append(ns[i]).append("\n");
	}

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".cpp", txtCpp );
}

//------------------------------------------------------------------------------
// CreateFlag
//------------------------------------------------------------------------------
void CreateFlag( map<string,string>& cfg )
{
	string strPurpose = cfg["Purpose"];
	string strDescription = cfg["Description"];
	string strName = cfg["Name"];
	string strStart = cfg["Start"];
	string strNamespace = cfg["Namespace"];
	string strDestination = cfg["Destination"];
	vector<string> ns;
	size_t posDot = strNamespace.find(".");
	if ( posDot == string::npos )
	{
		ns.push_back( strNamespace );
	}
	else
	{
		string ns1 = strNamespace.substr( 0, posDot );
		string ns2 = strNamespace.substr( posDot+1 );
		ns.push_back( ns1 );
		ns.push_back( ns2 );
	}

	vector<string> consts;
	vector<string> values;
	for ( int c = 0; ; ++c )
	{
		char buf[16];
		_itoa_s( c, buf, 10 );
		string constName = "Const";
		constName.assign( constName.append(buf) );
		map<string,string>::iterator it = cfg.find( constName );
		if ( it == cfg.end() )
			break;

		string s = cfg[constName];
		size_t p = string::npos;
		if ( (p = s.find("|")) != string::npos )
		{
			string key = s.substr( 0, p );
			string val = s.substr( p+1 );
			consts.push_back( key );
			values.push_back( val );
		}
	}

	// Read header.
	vector<string> hdr = ReadHeader( "data\\header.txt" );

	// Write source file (.h)
	string txtH;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtH.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtH.append( hdr[i] );

		txtH.append( "\n" );
	}

	// Write inclusion guard.
	string inc = GenerateIncGuard( strName, ns );
	txtH.append("#ifndef ").append(inc).append("\n");
	txtH.append("#define ").append(inc).append("\n");
	txtH.append("\n").append("\n");

	// Write includes.
	txtH.append( "#include \"config.h\"\n" );
	txtH.append( "#include <lang/Flag.h>\n");
	txtH.append("\n").append("\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtH.append("namespace ").append(ns[i]).append("\n{\n");
		txtH.append("\n").append("\n");
	}

	// Write class description and declaration.
	txtH.append("/**\n * ").append( strDescription ).append(".\n").append(" */\n");
	txtH.append("SYNKRO_FLAG_BEGIN( ").append(strName).append(" )");

	// Write constants.
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		txtH.append("\n\t/** ").append(values[i]).append(". */\n");
		txtH.append("\tSYNKRO_FLAG_CONST( ").append(strName).append(", ").append(consts[i]).append(" )\n");
	}
	txtH.append("SYNKRO_FLAG_END()\n");

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtH.append("\n");
		txtH.append("\n");
		txtH.append("} // ").append(ns[i]).append("\n");
	}

	// Close inclusion guard.
	txtH.append("\n");
	txtH.append("\n");
	txtH.append("#endif // ").append(inc);
	txtH.append("\n");

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".h", txtH );

	//--------------------------------------------------------------------------

	// Write source file (.cpp)
	string txtCpp;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtCpp.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtCpp.append( hdr[i] );

		txtCpp.append( "\n" );
	}

	// Write includes.
	txtCpp.append( "#include \"config.h\"\n" );
	txtCpp.append( "#include <").append(ns[ns.size()-1]).append("/").append(strName).append(".h>\n");
	txtCpp.append("\n\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtCpp.append("namespace ").append(ns[i]).append("\n{\n");
		txtCpp.append("\n").append("\n");
	}

	// Write consts.
	int v = atoi( strStart.c_str() );
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		char buf[16];
		char num[16];
		_itoa_s(v, buf, 16);
		sprintf_s( num, "%2s", buf );
		string str(num);
		if ( str[0] == ' ' )
		{
			str = str.substr( 1 );
			str = string("0").append(str);
		}
		txtCpp.append("SYNKRO_DEFINE_CONST( ").append(strName).append(", ").append(consts[i]).append(",\t0x").append(str).append(" )\n");
		v <<= 1;
	}

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtCpp.append("\n");
		txtCpp.append("\n");
		txtCpp.append("} // ").append(ns[i]).append("\n");
	}

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".cpp", txtCpp );
}

//------------------------------------------------------------------------------
// CreateEnum
//------------------------------------------------------------------------------
void CreateEnum( map<string,string>& cfg )
{
	string strPurpose = cfg["Purpose"];
	string strDescription = cfg["Description"];
	string strName = cfg["Name"];
	string strStart = cfg["Start"];
	string strNamespace = cfg["Namespace"];
	string strDestination = cfg["Destination"];
	vector<string> ns;
	size_t posDot = strNamespace.find(".");
	if ( posDot == string::npos )
	{
		ns.push_back( strNamespace );
	}
	else
	{
		string ns1 = strNamespace.substr( 0, posDot );
		string ns2 = strNamespace.substr( posDot+1 );
		ns.push_back( ns1 );
		ns.push_back( ns2 );
	}

	vector<string> consts;
	vector<string> values;
	for ( int c = 0; ; ++c )
	{
		char buf[16];
		_itoa_s(c, buf, 10);
		string constName = "Const";
		constName.assign( constName.append(buf) );
		map<string,string>::iterator it = cfg.find( constName );
		if ( it == cfg.end() )
			break;

		string s = cfg[constName];
		size_t p = string::npos;
		if ( (p = s.find("|")) != string::npos )
		{
			string key = s.substr( 0, p );
			string val = s.substr( p+1 );
			consts.push_back( key );
			values.push_back( val );
		}
	}

	// Read header.
	vector<string> hdr = ReadHeader( "data\\header.txt" );

	// Write source file (.h)
	string txtH;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtH.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtH.append( hdr[i] );

		txtH.append( "\n" );
	}

	// Write inclusion guard.
	string inc = GenerateIncGuard( strName, ns );
	txtH.append("#ifndef ").append(inc).append("\n");
	txtH.append("#define ").append(inc).append("\n");
	txtH.append("\n").append("\n");

	// Write includes.
	txtH.append( "#include \"config.h\"\n" );
	txtH.append( "#include <lang/Enum.h>\n");
	txtH.append("\n").append("\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtH.append("namespace ").append(ns[i]).append("\n{\n");
		txtH.append("\n").append("\n");
	}

	// Write class description and declaration.
	txtH.append("/**\n * ").append( strDescription ).append(".\n").append(" */\n");
	txtH.append("SYNKRO_ENUM_BEGIN( ").append(strName).append(" )");

	// Write constants.
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		txtH.append("\n\t/** ").append(values[i]).append(". */\n");
		txtH.append("\tSYNKRO_ENUM_CONST( ").append(strName).append(", ").append(consts[i]).append(" )\n");
	}
	txtH.append("SYNKRO_ENUM_END()\n");

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtH.append("\n");
		txtH.append("\n");
		txtH.append("} // ").append(ns[i]).append("\n");
	}

	// Close inclusion guard.
	txtH.append("\n");
	txtH.append("\n");
	txtH.append("#endif // ").append(inc);
	txtH.append("\n");

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".h", txtH );

	//--------------------------------------------------------------------------

	// Write source file (.cpp)
	string txtCpp;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtCpp.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtCpp.append( hdr[i] );

		txtCpp.append( "\n" );
	}

	// Write includes.
	txtCpp.append( "#include \"config.h\"\n" );
	txtCpp.append( "#include <").append(ns[ns.size()-1]).append("/").append(strName).append(".h>\n");
	txtCpp.append("\n\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtCpp.append("namespace ").append(ns[i]).append("\n{\n");
		txtCpp.append("\n").append("\n");
	}

	// Write consts.
	int v = atoi( strStart.c_str() );
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		char buf[16];
		_itoa_s(v, buf, 10);
		txtCpp.append("SYNKRO_DEFINE_CONST( ").append(strName).append(", ").append(consts[i]).append(",\t").append(string(buf)).append(" )\n");
		++v;
	}

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtCpp.append("\n");
		txtCpp.append("\n");
		txtCpp.append("} // ").append(ns[i]).append("\n");
	}

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".cpp", txtCpp );
}

//------------------------------------------------------------------------------
// CreateConsts
//------------------------------------------------------------------------------
void CreateConsts( map<string,string>& cfg )
{
	string strPurpose = cfg["Purpose"];
	string strDescription = cfg["Description"];
	string strName = cfg["Name"];
	string strNamespace = cfg["Namespace"];
	string strDestination = cfg["Destination"];
	vector<string> ns;
	size_t posDot = strNamespace.find(".");
	if ( posDot == string::npos )
	{
		ns.push_back( strNamespace );
	}
	else
	{
		string ns1 = strNamespace.substr( 0, posDot );
		string ns2 = strNamespace.substr( posDot+1 );
		ns.push_back( ns1 );
		ns.push_back( ns2 );
	}

	vector<string> consts;
	vector<string> values;
	for ( int c = 0; ; ++c )
	{
		char buf[16];
		_itoa_s(c, buf, 10);
		string constName = "Const";
		constName.assign( constName.append(buf) );
		map<string,string>::iterator it = cfg.find( constName );
		if ( it == cfg.end() )
			break;

		string s = cfg[constName];
		size_t p = string::npos;
		if ( (p = s.find("|")) != string::npos )
		{
			string key = s.substr( 0, p );
			string val = s.substr( p+1 );
			consts.push_back( key );
			values.push_back( val );
		}
	}

	// Read header.
	vector<string> hdr = ReadHeader( "data\\header.txt" );

	// Write source file (.h)
	string txtH;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtH.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtH.append( hdr[i] );

		txtH.append( "\n" );
	}

	// Write inclusion guard.
	string inc = GenerateIncGuard( strName, ns );
	txtH.append("#ifndef ").append(inc).append("\n");
	txtH.append("#define ").append(inc).append("\n");
	txtH.append("\n").append("\n");

	// Write includes.
	txtH.append( "#include \"config.h\"\n" );
	txtH.append("\n").append("\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtH.append("namespace ").append(ns[i]).append("\n{\n");
		txtH.append("\n").append("\n");
	}

	// Write class description and declaration.
	txtH.append("/**\n * ").append( strDescription ).append(".\n").append(" */\n");
	txtH.append("class SYNKRO_API ").append(strName).append("\n{");

	// Write constants.
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		txtH.append("\n\t/** ").append(values[i]).append(". */\n");
		txtH.append("\tstatic const Char* ").append(consts[i]).append(";\n");
	}
	txtH.append("};\n");

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtH.append("\n");
		txtH.append("\n");
		txtH.append("} // ").append(ns[i]).append("\n");
	}

	// Close inclusion guard.
	txtH.append("\n");
	txtH.append("\n");
	txtH.append("#endif // ").append(inc);
	txtH.append("\n");

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".h", txtH );

	//--------------------------------------------------------------------------

	// Write source file (.cpp)
	string txtCpp;

	// Write header.
	for ( size_t i = 0; i < hdr.size(); ++i )
	{
		if ( hdr[i].find("// Purpose:") != string::npos )
			txtCpp.append( hdr[i] ).append( strPurpose ).append(".");
		else
			txtCpp.append( hdr[i] );

		txtCpp.append( "\n" );
	}

	// Write includes.
	txtCpp.append( "#include \"config.h\"\n" );
	txtCpp.append( "#include <").append(ns[ns.size()-1]).append("/").append(strName).append(".h>\n");
	txtCpp.append("\n\n");

	// Write namespaces.
	for ( size_t i = 0; i < ns.size(); ++i )
	{
		txtCpp.append("namespace ").append(ns[i]).append("\n{\n");
		txtCpp.append("\n").append("\n");
	}

	// Write consts.
	for ( size_t i = 0; i < consts.size(); ++i )
	{
		txtCpp.append("const Char* ").append(strName).append("::").append(consts[i]).append("\t= L\"").append(consts[i]).append("\";\n");
	}

	// Close namespaces.
	for ( int i = (int)ns.size()-1; i >= 0; --i )
	{
		txtCpp.append("\n");
		txtCpp.append("\n");
		txtCpp.append("} // ").append(ns[i]).append("\n");
	}

	// Write to file.
	WriteFile( strDestination+"\\"+strName+".cpp", txtCpp );
}

int main( int argc, char* argv[] )
{
	// Make sure there is exactly one command line argument passed.
	if ( argc != 2 )
	{
		cout << "Usage: codegen.exe: <configfile>";
		return 1;
	}

	// Read configuration from an external file.
	map<string,string> cfg = ReadConfig( string(argv[1]) );

	// Analyze class type and generate source code.
	string strType = cfg["Type"];
	if ( strType.find("IfaceImpl") != string::npos ) CreateIfaceImpl( cfg );
	else if ( strType.find("Class") != string::npos ) CreateClass( cfg );
	else if ( strType.find("Flag") != string::npos ) CreateFlag( cfg );
	else if ( strType.find("Enum") != string::npos ) CreateEnum( cfg );
	else if ( strType.find("Consts") != string::npos ) CreateConsts( cfg );
	
	return 0;
}
