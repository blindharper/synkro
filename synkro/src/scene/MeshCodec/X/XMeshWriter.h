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
// Purpose: Abstract DirectX mesh writer.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHWRITER_
#define _SYNKRO_SCENE_XMESHWRITER_


#include "config.h"
#include "XMesh.h"


namespace synkro
{


namespace scene
{


// Abstract DirectX mesh writer.
class XMeshWriter
{
public:
	virtual void											Initialize( io::IStream* stream ) = 0;
	virtual void											BeginTemplate( Byte type, const lang::String& name ) = 0;
	virtual void											EndTemplate() = 0;
	virtual void											WriteName( const lang::String& name ) = 0;
	virtual void											WriteString( const lang::String& str ) = 0;
	virtual void											WriteArray( const lang::Vector<UInt>& array ) = 0;
	virtual void											WriteTexCoords( const lang::Vector<math::Vector2>& array ) = 0;
	virtual void											WritePositions( const lang::Vector<math::Vector3>& array ) = 0;
	virtual void											WriteIndices( const lang::Vector<UInt>& array ) = 0;
	virtual void											WriteSubsets( const lang::Vector<UInt>& array, UInt materialCount ) = 0;
	virtual void											WriteColors( UInt count ) = 0;
	virtual void											WriteColorRGBA( Float r, Float g, Float b, Float a ) = 0;
	virtual void											WriteColorRGB( Float r, Float g, Float b ) = 0;
	virtual void											WritePower( Float power ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHWRITER_
