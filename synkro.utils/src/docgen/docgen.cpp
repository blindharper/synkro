//==============================================================================
// API documentation generator.
//==============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <direct.h>
#include <process.h>
#include <io.h>
using namespace std;

// Method exception description.
struct ExceptionDesc
{
	string				Type;
	string				Desc;
};

// Enmeration constant description.
struct ConstDesc
{
	string				Name;
	string				Desc;
};

// Method parameter description.
struct ParamDesc
{
	ParamDesc() :
		Const( false ),
		Modifier( ' ' )
	{
	}

	string				NameSpace;
	string				Type;
	string				Name;
	string				Desc;
	string				Direction;	// '[in], [out], [in,out]'
	bool				Const;		// 'const'
	char				Modifier;	// ' ', '*' or '&'
};

// Method description.
struct MethodDesc
{
	MethodDesc() :
		Index( 0 ),
		Const( false ),
		Static( false )
	{
	}

	int					Index;		// Overload index.
	string				Desc;
	string				Remarks;
	string				Name;
	bool				Const;		// 'const'
	bool				Static;		// 'static'
	vector<ParamDesc>	Params;
	vector<ExceptionDesc> Exceptions;
	ParamDesc			Return;
};

// Interface description.
struct IfaceDesc
{
	string				Desc;
	string				Remarks;
	string				Name;
	string				Base;
	vector<string>		NameSpaces;
	vector<MethodDesc>	Methods;
	map<string, int>	MethodCounts;
};

// Class description.
struct ClassDesc
{
	string				Desc;
	string				Remarks;
	string				Name;
	string				Base;
	vector<string>		NameSpaces;
	vector<ParamDesc>	Members;
	vector<MethodDesc>	Methods;
	map<string, int>	MethodCounts;
};

// Enumeration description.
struct EnumDesc
{
	string				Desc;
	string				Remarks;
	string				Name;
	vector<string>		NameSpaces;
	vector<ConstDesc>	Consts;
	vector<MethodDesc>	Methods;
	map<string, int>	MethodCounts;
};

// Namespace description.
struct NamespaceDesc
{
	string					Name;
	string					Desc;
	map<string, IfaceDesc>	Ifaces;
	map<string, ClassDesc>	Classes;
	map<string, EnumDesc>	Enums;
};

map<string, NamespaceDesc> g_namespaces;	// global namespace table.

void JsonWrite( string& json, const string& key, const string& value, bool delim = true )
{
	if ( value.empty() )
		return;

	json.append( "\"" );
	json.append( key );
	json.append( "\":\"" );
	json.append( value );
	json.append( "\"" );
	if ( delim )
	{
		json.append( ", " );
	}
}

void JsonWrite( string& json, const string& key, bool value, bool delim = true )
{
	if ( !value )
		return;

	json.append( "\"" );
	json.append( key );
	json.append( "\":" );
	json.append( "1" );
	if ( delim )
	{
		json.append( ", " );
	}
}

void JsonWrite( string& json, const ParamDesc& param )
{
	json.append( "{" );
	JsonWrite( json, "type", param.Type );
	JsonWrite( json, "const", param.Const );
	JsonWrite( json, "modifier", string(&param.Modifier, 1) );
	JsonWrite( json, "desc", param.Desc, false );
	json.append( "}" );
}

void JsonWrite( string& json, const vector<ParamDesc>& params )
{
	json.append( "[" );
	for ( size_t i = 0; i < params.size(); ++i )
	{
		const ParamDesc& p = params[i];

		json.append( "{" );
		JsonWrite( json, "name", p.Name );
		JsonWrite( json, "desc", p.Desc );
		JsonWrite( json, "type", p.Type );
		JsonWrite( json, "const", p.Const );
		JsonWrite( json, "modifier", string(&p.Modifier, 1) );
		JsonWrite( json, "direction", p.Direction, false );
		json.append( "}" );
		if ( i != params.size()-1 )
		{
			json.append( ", " );
		}
	}
	json.append( "]" );
}

void JsonWrite( string& json, const vector<ExceptionDesc>& exceptions )
{
	json.append( "[" );
	for ( size_t i = 0; i < exceptions.size(); ++i )
	{
		const ExceptionDesc& e = exceptions[i];

		json.append( "{" );
		JsonWrite( json, "type", e.Type );
		JsonWrite( json, "desc", e.Desc, false );
		json.append( "}" );
		if ( i != exceptions.size()-1 )
		{
			json.append( ", " );
		}
	}
	json.append( "]" );
}

void JsonWrite( string& json, const MethodDesc& method )
{
	json.append( "{" );
	JsonWrite( json, "name", method.Name );
	JsonWrite( json, "desc", method.Desc );
	JsonWrite( json, "remarks", method.Remarks );
	JsonWrite( json, "const", method.Const );
	JsonWrite( json, "static", method.Static );
	json.append( "\"return\": " );
	JsonWrite( json, method.Return );
	json.append( ", " );
	json.append( "\"params\": " );
	JsonWrite( json, method.Params );
	json.append( ", " );
	json.append( "\"exceptions\": " );
	JsonWrite( json, method.Exceptions );
	json.append( "}" );
}

void JsonWrite( string& json, const IfaceDesc& iface )
{
	json.append( "\t\t\t{" );
	json.append( "\n\t\t\t\t" );
	JsonWrite( json, "name", iface.Name );
	JsonWrite( json, "desc", iface.Desc );
	JsonWrite( json, "remarks", iface.Remarks );
	json.append( "\n\t\t\t\t\"methods\": [\n" );
	for ( size_t i = 0; i < iface.Methods.size(); ++i )
	{
		json.append( "\t\t\t\t\t" );
		JsonWrite( json, iface.Methods[i] );
		if ( i != iface.Methods.size()-1 )
		{
			json.append( "," );
		}
		json.append( "\n" );
	}
	json.append( "\t\t\t\t]\n" );
	json.append( "\t\t\t}" );
}

void JsonAppend( string& json, const string& name, const string& value )
{
	json.append( "\"" );
	json.append( name );
	json.append( "\": \"" );
	json.append( value );
	json.append( "\"" );
}

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

string GetFilename( const string& path )
{
	string name( path );

	name = DoReplace( name, "/", "\\" );
	size_t pos = name.rfind( "\\" );
	if ( pos != string::npos )
	{
		name = name.substr( pos+1 );
	}

	return name;
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

bool FileContains( const string& filename, const string& text )
{
	bool ok = false;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename.c_str(), "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			if ( line.find(text) != string::npos )
			{
				ok = true;
				break;
			}
		}
		fclose( file );
	}

	return ok;
}

string ParseComment( const string& comment )
{
	string desc( comment );

	desc = DoReplace( desc, "/**", "" );
	desc = DoReplace( desc, "/*", "" );
	desc = DoReplace( desc, " */", "" );
	desc = DoReplace( desc, "*/", "" );
	desc = DoReplace( desc, " * ", "" );
	desc = DoReplace( desc, " *", "" );
	desc = DoReplace( desc, "* ", "" );
	desc = DoReplace( desc, "\t", "" );
	desc = DoReplace( desc, "  ", " " );
	if ( !desc.empty() && (desc[0] == ' ') )
	{
		desc = desc.substr( 1, desc.length()-1 );
	}

	return desc;
}

void ParseParamList( const string& str, vector<ParamDesc>& params )
{
	size_t start = 0;
	size_t end = 0;
	size_t pos = 0;
	size_t pos2 = 0;
	string tmp;

	while ( (end = str.find(",", end)) != string::npos )
	{
		ParamDesc desc;
		tmp = str.substr( start, (end-start) );
		start = ++end;

		pos = tmp.find_last_of( " " );
		if ( pos != string::npos )
		{
			desc.Name = tmp.substr( pos+1 );

			pos2 = pos;
			pos = tmp.find_last_of( " ", pos-1 );
			if ( pos != string::npos )
			{
				desc.Type = tmp.substr( pos+1, (pos2-pos-1) );
				desc.Modifier = desc.Type[desc.Type.length()-1];
				if ( (desc.Modifier == '*') || (desc.Modifier == '&') )
				{
					desc.Type = desc.Type.substr( 0, desc.Type.length()-1 );
				}
				else
				{
					desc.Modifier = ' ';
				}
				desc.Const = (tmp.find("const ") != string::npos);
			}
			pos2 = desc.Type.find( "::" );
			if ( pos2 != string::npos )
			{
				desc.NameSpace = desc.Type.substr( 0, pos2 );
				desc.Type = desc.Type.substr( pos2+2 );
			}

			params.push_back( desc );
		}
	}
}

void ParseMethodComments( const string& str, const string& ifaceName, MethodDesc& method )
{
	size_t start = 0;
	size_t end = 0;
	size_t pos = 0;
	size_t pos2 = 0;
	size_t idxParam = 0;
	size_t idxException = 0;
	string tmp;

	while ( (end = str.find("@", end)) != string::npos )
	{
		tmp = str.substr( start, (end-start) );
		if ( tmp.find("remarks") == 0 )
		{
			method.Remarks = tmp.substr( 8 );
		}
		else if ( tmp.find("param") == 0 )
		{
			if ( idxParam < method.Params.size() )
			{
				string s = tmp.substr( 6 );
				size_t p = s.find( " " );
				if ( p != string::npos )
				{
					string n = s.substr( 0, p );
					if ( (n == "[in]") || (n == "[out]") || (n == "[in,out]") )
					{
						s = s.substr( p+1 );
						p = s.find( " " );
						if ( p != string::npos )
						{
							n = s.substr( 0, p );
						}
						method.Params[idxParam].Direction = n;
					}
					else
					{
						method.Params[idxParam].Direction = "[in]";
					}
					if ( n != method.Params[idxParam].Name )
					{
						cout << "Warning: Parameter '" << method.Params[idxParam].Name << "' in method '" << ifaceName << "::" << method.Name << "' has wrong comments" << endl;
					}

					method.Params[idxParam].Desc = DoReplace( s.substr(p+1), "\"", "'" );
				}
				else
				{
					method.Params[idxParam].Direction = "[in]";
					method.Params[idxParam].Desc = DoReplace( s, "\"", "'" );
				}
				++idxParam;
			}
			else
			{
				cout << "Warning: Method '" << ifaceName << "::" << method.Name << "' has mismatched parameter comments" << endl;
			}
		}
		else if ( tmp.find("exception") == 0 )
		{
			ExceptionDesc ex;
			string s = tmp.substr( 10 );
			size_t p = s.find( " " );
			if ( p != string::npos )
			{
				ex.Type = s.substr( 0, p );
				ex.Desc = DoReplace( s.substr(p+1), "\"", "'" );
			}
			else
			{
				ex.Type = s;
			}
			method.Exceptions.push_back( ex );
		}
		else if ( tmp.find("return") == 0 )
		{
			method.Return.Desc = DoReplace( tmp.substr(7), "\"", "'" );
		}
		else
		{
			method.Desc = DoReplace( tmp, "\"", "'" );
		}
		start = ++end;
	}
}

void AnalyzeIface( const char* filename )
{
	IfaceDesc iface;
	vector<string> methods;
	map<string, int> methodCounts;
	bool insideComment = false;
	string comment;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename, "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			line = line.substr( 0, line.length()-1 );

			size_t pos = string::npos;
			if ( (pos = line.find("/**")) != string::npos )
			{
				insideComment = true;
				comment.assign( line );
			}
			else if ( (pos = line.find("*/")) != string::npos )
			{
				insideComment = false;
				comment = comment.append( line );
			}
			else if ( (pos = line.find("namespace ")) != string::npos )
			{
				iface.NameSpaces.push_back( line.substr(pos+10) );
			}
			else if ( (pos = line.find("iface ")) != string::npos )
			{
				iface.Desc = DoReplace( ParseComment(comment), "\"", "'" );
				if ( line.find(":") != string::npos )
					iface.Name = line.substr( pos+6, line.length()-8 );
				else
					iface.Name = line.substr( pos+6 );
			}
			else if ( (pos = line.find("class ")) != string::npos )
			{
				iface.Desc = DoReplace( ParseComment(comment), "\"", "'" );
				if ( line.find(":") != string::npos )
					iface.Name = line.substr( pos+6, line.length()-8 );
				else
					iface.Name = line.substr( pos+6 );
			}
			else if ( (pos = line.find("\tpublic ")) != string::npos )
			{
				iface.Base = line.substr( pos+8, line.length()-2 );
			}
			else if ( (pos = line.find("\tvirtual ")) != string::npos )
			{
				MethodDesc method;

				size_t posTab = line.find_last_of( "\t" );
				string methodName = line.substr( posTab+1 );
				size_t posPar = methodName.find( "(" );
				size_t posPar2 = methodName.find( ")" );
				if ( posPar2 != posPar+1 )
				{
					string paramList = methodName.substr( posPar+1, (posPar2-posPar-2) );
					paramList = paramList.append( "," );
					ParseParamList( paramList, method.Params );
				}

				method.Name = methodName.substr( 0, posPar );
				method.Const = (line.find("const = 0") != string::npos);
				comment = ParseComment( comment );
				comment = string( "@" ).append( comment );
				comment = comment.append( "@" );
				ParseMethodComments( comment, iface.Name, method );

				string ret = line.substr( 9, (posTab-9) );
				ret = DoReplace( ret, "\t", "" );

				size_t pos2 = pos;
				pos = ret.find_last_of( " ", pos-1 );
				method.Return.Type = (pos != string::npos) ? ret.substr( pos2, (pos-pos2) ) : ret;
				method.Return.Modifier = method.Return.Type[method.Return.Type.length()-1];
				if ( (method.Return.Modifier == '*') || (method.Return.Modifier == '&') )
				{
					method.Return.Type = method.Return.Type.substr( 0, method.Return.Type.length()-1 );
				}
				else
				{
					method.Return.Modifier = ' ';
				}
				pos2 = method.Return.Type.find( "::" );
				if ( pos2 != string::npos )
				{
					method.Return.NameSpace = method.Return.Type.substr( 0, pos2 );
					method.Return.Type = method.Return.Type.substr( pos2+2 );
				}
				method.Return.Const = (ret.find("const ") != string::npos);

				int methodCount = 0;
				map<string, int>::const_iterator cit = iface.MethodCounts.find( method.Name );
				if ( cit != iface.MethodCounts.end() )
				{
					methodCount = cit->second;
				}
				iface.MethodCounts[method.Name] = ++methodCount;
				method.Index = methodCount-1;
				iface.Methods.push_back( method );
			}
			else if ( (pos = line.find("\tvirtual\t")) != string::npos )
			{
				cout << "Warning: File '" << filename << " Line: " << line << endl;
			}
			else if ( insideComment )
			{
				comment = comment.append( line );
			}
		}
		fclose( file );
	}

	// Store interface definition.
	string ns = (iface.NameSpaces.size() == 2) ? iface.NameSpaces[iface.NameSpaces.size()-1] : "";
	if ( ns.length() > 0 )
	{
		if ( g_namespaces.find(ns) == g_namespaces.end() )
		{
			NamespaceDesc desc;
			desc.Name = ns;
			g_namespaces[ns] = desc;
		}
		g_namespaces[ns].Ifaces[iface.Name] = iface;
	}
}

void AnalyzeClass( const char* filename )
{
	ClassDesc cls;
	vector<string> methods;
	map<string, int> methodCounts;
	bool insideComment = false;
	bool insidePublic = true;
	string comment;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename, "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			// Skip private stuff.
			if ( !insidePublic )
				continue;

			string line( buf );
			line = line.substr( 0, line.length()-1 );

			size_t pos = string::npos;
			if ( (pos = line.find("/**")) != string::npos )
			{
				insideComment = (line.find("*/") == string::npos);
				comment.assign( line );
			}
			else if ( (pos = line.find("*/")) != string::npos )
			{
				insideComment = false;
				comment = comment.append( line );
			}
			else if ( (pos = line.find("public:")) != string::npos )
			{
				insidePublic = true;
			}
			else if ( (pos = line.find("private:")) != string::npos )
			{
				insidePublic = false;
			}
			else if ( (pos = line.find("protected:")) != string::npos )
			{
				insidePublic = false;
			}
			else if ( (pos = line.find("namespace ")) != string::npos )
			{
				cls.NameSpaces.push_back( line.substr(pos+10) );
			}
			else if ( (pos = line.find("class SYNKRO_API ")) != string::npos )
			{
				cls.Desc = DoReplace( ParseComment(comment), "\"", "'" );
				if ( line.find(":") != string::npos )
					cls.Name = line.substr( pos+17, line.length()-13 );
				else
					cls.Name = line.substr( pos+17 );
			}
			else if ( (pos = line.find("\tpublic ")) != string::npos )
			{
				cls.Base = line.substr( pos+8, line.length()-2 );
			}
			else if ( ((pos = line.find("\t")) != string::npos) && ((pos = line.find(";")) != string::npos) )
			{
				if ( ((pos = line.find("(")) != string::npos) && ((pos = line.find(")")) != string::npos) )
				{
					MethodDesc method;

					size_t posTab = line.find_last_of( "\t" );
					string methodName = line.substr( posTab+1 );
					size_t posPar = methodName.find( "(" );
					size_t posPar2 = methodName.find( ")" );
					if ( posPar2 != posPar+1 )
					{
						string paramList = methodName.substr( posPar+1, (posPar2-posPar-2) );
						paramList = paramList.append( "," );
						ParseParamList( paramList, method.Params );
					}

					method.Name = methodName.substr( 0, posPar );
					method.Name = DoReplace( method.Name, "virtual ~", "~" );
					method.Name = DoReplace( method.Name, "explicit ", "" );
					method.Const = (line.find("const;") != string::npos);
					comment = ParseComment( comment );
					comment = string( "@" ).append( comment );
					comment = comment.append( "@" );
					ParseMethodComments( comment, cls.Name, method );

					string ret = line.substr( 0, (posTab) );
					ret = DoReplace( ret, "\t", "" );

					size_t pos2 = pos;
					pos = ret.find_last_of( " ", pos-1 );
					method.Return.Type = (pos != string::npos) ? ret.substr( pos+1, (pos2-pos-1) ) : ret;
					method.Return.Modifier = (method.Return.Type.length() > 0) ? method.Return.Type[method.Return.Type.length()-1] : ' ';
					if ( (method.Return.Modifier == '*') || (method.Return.Modifier == '&') )
					{
						method.Return.Type = method.Return.Type.substr( 0, method.Return.Type.length()-1 );
					}
					else
					{
						method.Return.Modifier = ' ';
					}
					pos2 = method.Return.Type.find( "::" );
					if ( pos2 != string::npos )
					{
						method.Return.NameSpace = method.Return.Type.substr( 0, pos2 );
						method.Return.Type = method.Return.Type.substr( pos2+2 );
					}
					method.Return.Const = (ret.find("const ") != string::npos);

					int methodCount = 0;
					map<string, int>::const_iterator cit = cls.MethodCounts.find( method.Name );
					if ( cit != cls.MethodCounts.end() )
					{
						methodCount = cit->second;
					}
					cls.MethodCounts[method.Name] = ++methodCount;
					method.Index = methodCount-1;
					cls.Methods.push_back( method );
				}
				else
				{
					ParamDesc member;

					size_t posTab = line.find_last_of( "\t" );
					string memberName = line.substr( posTab+1 );
					member.Name = memberName.substr( 0, memberName.length()-1 );
					member.Desc = comment = DoReplace( ParseComment(comment), "\"", "'" );

					string ret = line.substr( 0, (posTab) );
					ret = DoReplace( ret, "\t", "" );

					size_t pos2 = pos;
					pos = ret.find_last_of( " ", pos-1 );
					member.Type = (pos != string::npos) ? ret.substr( pos+1, (pos2-pos-1) ) : ret;
					member.Modifier = (member.Type.length() > 0) ? member.Type[member.Type.length()-1] : ' ';
					if ( (member.Modifier == '*') || (member.Modifier == '&') )
					{
						member.Type = member.Type.substr( 0, member.Type.length()-1 );
					}
					else
					{
						member.Modifier = ' ';
					}
					pos2 = member.Type.find( "::" );
					if ( pos2 != string::npos )
					{
						member.NameSpace = member.Type.substr( 0, pos2 );
						member.Type = member.Type.substr( pos2+2 );
					}
					member.Const = (ret.find("const ") != string::npos);
					cls.Members.push_back( member );
				}
			}
			else if ( insideComment )
			{
				comment = comment.append( line );
			}
		}
		fclose( file );
	}

	// Store class definition.
	string ns = (cls.NameSpaces.size() == 2) ? cls.NameSpaces[cls.NameSpaces.size()-1] : "";
	if ( ns.length() > 0 )
	{
		if ( g_namespaces.find(ns) == g_namespaces.end() )
		{
			NamespaceDesc desc;
			desc.Name = ns;
			g_namespaces[ns] = desc;
		}
		g_namespaces[ns].Classes[cls.Name] = cls;
	}
}

void AnalyzeEnum( const char* filename )
{
	EnumDesc en;
	vector<string> methods;
	map<string, int> methodCounts;
	bool insideComment = false;
	string comment;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename, "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			line = line.substr( 0, line.length()-1 );

			size_t pos = string::npos;
			if ( (pos = line.find("/**")) != string::npos )
			{
				insideComment = (line.find("*/") == string::npos);
				comment.assign( line );
			}
			else if ( (pos = line.find("*/")) != string::npos )
			{
				insideComment = false;
				comment = comment.append( line );
			}
			else if ( (pos = line.find("namespace ")) != string::npos )
			{
				en.NameSpaces.push_back( line.substr(pos+10) );
			}
			else if ( (pos = line.find("_BEGIN( ")) != string::npos )
			{
				en.Desc = DoReplace( ParseComment(comment), "\"", "'" );
				en.Name = line.substr( pos+8 );
				en.Name = en.Name.substr( 0, en.Name.length()-2 );
			}
			else if ( (pos = line.find("_CONST( ")) != string::npos )
			{
				ConstDesc c;
				c.Desc = DoReplace( ParseComment(comment), "\"", "'" );
				c.Name = line.substr( pos+10+en.Name.length() );
				c.Name = c.Name.substr( 0, c.Name.length()-2 );
				en.Consts.push_back( c );
			}
			else if ( insideComment )
			{
				comment = comment.append( line );
			}
		}
		fclose( file );
	}

	// Store enumeration definition.
	string ns = (en.NameSpaces.size() == 2) ? en.NameSpaces[en.NameSpaces.size()-1] : "";
	if ( ns.length() > 0 )
	{
		if ( g_namespaces.find(ns) == g_namespaces.end() )
		{
			NamespaceDesc desc;
			desc.Name = ns;
			g_namespaces[ns] = desc;
		}
		g_namespaces[ns].Enums[en.Name] = en;
	}
}

void AnalyzeNamespace( const char* filename )
{
	NamespaceDesc desc;
	bool insideComment = false;
	string comment;

	char buf[8192];
	FILE* file = NULL;
	fopen_s( &file, filename, "rt" );
	if ( file )
	{ 
		while ( fgets(buf, 8192, file) )
		{
			string line( buf );
			line = line.substr( 0, line.length()-1 );

			size_t pos = string::npos;
			if ( (pos = line.find("/**")) != string::npos )
			{
				insideComment = (line.find("*/") == string::npos);
				comment.assign( line );
			}
			else if ( (pos = line.find("*/")) != string::npos )
			{
				insideComment = false;
				if ( (line != " */") && (line != "\t*/") )
				{
					comment = comment.append( " " ).append( line );
				}
			}
			else if ( (pos = line.find("namespace ")) == 0 )
			{
				desc.Name = line.substr( pos+10 );
				comment = ParseComment( comment );
				desc.Desc = DoReplace( comment, "\"", "'" );
			}
			else if ( insideComment )
			{
				comment = comment.append( " " ).append( line );
			}
			else if ( line.length() == 0 )
			{
				comment.assign( "" );
			}
		}
		fclose( file );
	}

	// Store namespace definition.
	if ( (desc.Name.length() > 0) && (desc.Desc.length() > 0) )
	{
		if ( g_namespaces.find(desc.Name) == g_namespaces.end() )
		{
			g_namespaces[desc.Name] = desc;
		}
		g_namespaces[desc.Name].Desc = DoReplace( desc.Desc, "\"", "'" );
	}
}

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

void WriteCode( const char* basePath )
{
	// Prepare sorted namespace list.
	vector<string> nsNames;
	map<string, NamespaceDesc>::const_iterator it = g_namespaces.begin();
	for ( ; it != g_namespaces.end() ; ++it )
	{
		nsNames.push_back( it->first );
	}
	sort( nsNames.begin(), nsNames.end() );

	// Create output.
	string out( basePath );
	out.append("/").append( "data.js" );

	// Cycle through namespaces and write stuff found inside them.
	string json( "var synkro = [\n" );
	for ( size_t n = 0; n < nsNames.size(); ++n )
	{
		NamespaceDesc& ns = g_namespaces[nsNames[n]];
		if ( ns.Ifaces.empty() && ns.Classes.empty() && ns.Enums.empty() )
			continue;

		json.append( "\t{\n\t\t" );
		JsonWrite( json, "name", ns.Name );
		JsonWrite( json, "desc", ns.Desc );
		json.append( "\n" );

		// Write namespace interfaces.
		vector<string> ifNames;
		map<string, IfaceDesc>::const_iterator it0 = ns.Ifaces.begin();
		for ( ; it0 != ns.Ifaces.end() ; ++it0 )
		{
			ifNames.push_back( it0->first );
		}
		sort( ifNames.begin(), ifNames.end() );

		json.append( "\t\t" );
		json.append( "\"ifaces\": [\n" );
		for ( size_t i = 0; i < ifNames.size(); ++i )
		{
			const IfaceDesc& iface = ns.Ifaces[ifNames[i]];
			JsonWrite( json, iface );
			if ( i != ifNames.size()-1 )
			{
				json.append( "," );
			}
			json.append( "\n" );
		}
		json.append( "\t\t]" );

		// TODO: classes.
		vector<string> clsNames;
		map<string, ClassDesc>::const_iterator it1 = ns.Classes.begin();
		for ( ; it1 != ns.Classes.end() ; ++it1 )
		{
			clsNames.push_back( it1->first );
		}
		sort( clsNames.begin(), clsNames.end() );

		// TODO: enumerations.
		vector<string> enNames;
		map<string, EnumDesc>::const_iterator it2 = ns.Enums.begin();
		for ( ; it2 != ns.Enums.end() ; ++it2 )
		{
			enNames.push_back( it2->first );
		}
		sort( enNames.begin(), enNames.end() );
		// TODO:

		json.append( "\n\t}" );
		if ( n != nsNames.size()-1 )
		{
			json.append( "," );
		}
		json.append( "\n" );
	}

	// Dump data.
	json.append( "];" );
	WriteFile( out, json );
}

void ExploreDirectory( const char* path )
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
			if ( (fileinfo.name[0] != '.') && (_strcmpi(fileinfo.name, "config.h") != 0) )
			{
				string tmp( dir );
				string str( dir );
				tmp = tmp.append("/").append(fileinfo.name);

				if ( (_A_SUBDIR & fileinfo.attrib) != 0 )
				{
					ExploreDirectory( tmp.c_str() );
				}
				else
				{
					if ( tmp.find(".h") != string::npos )
					{
						if ( (fileinfo.name[0] == 'I') && isupper(fileinfo.name[1]) )
						{
							AnalyzeIface( tmp.c_str() );
						}
						else if ( FileContains(tmp, "CONST( ") )
						{
							AnalyzeEnum( tmp.c_str() );
						}
						else if ( FileContains(tmp, "class SYNKRO_API ") )
						{
							AnalyzeClass( tmp.c_str() );
						}
						else if ( islower(fileinfo.name[0]) )
						{
							if ( str.append(".h").find_last_of(fileinfo.name) != string::npos )
							{
								AnalyzeNamespace( tmp.c_str() );
							}
						}
					}
				}
			}
		} while ( _findnext(handle, &fileinfo) == 0 );

		_findclose( handle );
	}
}

int main( int argc, char* argv[] )
{
	string srcPath;	// source path.
	string dstPath;	// destination path.

	// Make sure there is exactly two command line arguments passed.
	if ( argc != 3 )
	{
		cout << "Usage: docgen.exe: <source> <destination>" << endl;
		return 1;
	}

	// Extract paths.
	srcPath.assign( argv[1] );
	dstPath.assign( argv[2] );

	ExploreDirectory( srcPath.c_str() );
	WriteCode( dstPath.c_str() );

	return 0;
}
