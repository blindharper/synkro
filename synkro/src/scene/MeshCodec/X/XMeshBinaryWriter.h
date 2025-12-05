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
// Purpose: Binary DirectX mesh writer.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHBINARYWRITER_
#define _SYNKRO_SCENE_XMESHBINARYWRITER_


#include "config.h"
#include "XMeshWriterImpl.h"


namespace synkro
{


namespace scene
{


// Binary DirectX mesh writer.
class XMeshBinaryWriter :
	public XMeshWriterImpl<XMeshWriter>
{
public:
	// Constructor.
	XMeshBinaryWriter();

	// XMeshWriter methods.
	void													Initialize( io::IStream* stream );
	void													BeginTemplate( Byte type, const lang::String& name );
	void													EndTemplate();
	void													WriteString( const lang::String& str );
	void													WriteArray( const lang::Vector<UInt>& array );
	void													WriteArray( const lang::Vector<math::Vector2>& array );
	void													WriteArray( const lang::Vector<math::Vector3>& array );
	void													WriteTexCoords( const lang::Vector<math::Vector2>& array );
	void													WritePositions( const lang::Vector<math::Vector3>& array );
	void													WriteIndices( const lang::Vector<UInt>& array );
	void													WriteSubsets( const lang::Vector<UInt>& array, UInt materialCount );
	void													WriteColors( UInt count );
	void													WriteColorRGBA( Float r, Float g, Float b, Float a );
	void													WriteColorRGB( Float r, Float g, Float b );
	void													WritePower( Float power );

private:
	void													WriteToken( UShort token );
	void													WriteDword( UInt value );
	void													WriteFloat( Float value );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHBINARYWRITER_
