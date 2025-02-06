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
// Purpose: Defines mesh codec types.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHCODEC_
#define _SYNKRO_SCENE_MESHCODEC_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


/**
 * Mesh codec types.
 */
SYNKRO_ENUM_BEGIN( MeshCodec )
	/** Unknown mesh codec. */
	SYNKRO_ENUM_CONST( MeshCodec, Unknown )

	/** Custom mesh codec. */
	SYNKRO_ENUM_CONST( MeshCodec, Custom )

	/** Wavefront Advanced Visualizer mesh codec (ASCII format). */
	SYNKRO_ENUM_CONST( MeshCodec, Obj )

	/** Microsoft DirectX mesh codec. */
	SYNKRO_ENUM_CONST( MeshCodec, X )

	/** Creates mesh codec type from string. */
	MeshCodec( const lang::String& type );

	/** Converts mesh codec type to string. */
	lang::String											ToString() const;

	/** Tests whether the given name has an extension corresponding to one of the mesh codecs. */
	static Bool												IsValid( const lang::String& name );
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHCODEC_
