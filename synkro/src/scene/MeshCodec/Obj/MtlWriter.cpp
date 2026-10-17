//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Obj mesh material writer.
//==============================================================================
#include "config.h"
#include "MtlWriter.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


MtlWriter::MtlWriter( IStream* stream ) :
	ObjStreamWriter( stream )
{
}

void MtlWriter::Write( const ObjMaterial& desc )
{
	// Material name.
	WriteString( L"newmtl" );
	WriteChar( ' ' );
	WriteString( desc.Name );
	WriteCRLF();

	// Colors.
	Write( L"Ka", desc.Ambient );
	Write( L"Kd", desc.Diffuse );
	if ( desc.Emissive != Color::Black )
	{
		Write( L"Ke", desc.Emissive );
	}
	Write( L"Ks", desc.Specular );
	
	// Specular power.
	WriteString( L"Ns" );
	WriteChar( ' ' );
	WriteFloat( desc.SpecularPower );
	WriteCRLF();

	// Diffuse texture.
	if ( !desc.DiffuseTexture.IsNullOrEmpty() )
	{
		WriteString( L"map_Kd" );
		WriteChar( ' ' );
		WriteString( desc.DiffuseTexture );
		WriteCRLF();
	}

	// End of material.
	WriteCRLF();
}

void MtlWriter::Write( const String& name, const Color& color )
{
	WriteString( name );
	WriteChar( ' ' );
	WriteFloat( color.R );
	WriteChar( ' ' );
	WriteFloat( color.G );
	WriteChar( ' ' );
	WriteFloat( color.B );
	WriteChar( ' ' );
	WriteCRLF();
}


} // scene


} // synkro
