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
// Purpose: Defines abstract mesh codec.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESHCODEC_
#define _SYNKRO_SCENE_IMESHCODEC_


#include "config.h"
#include <core/IObject.h>
#include <core/DataMode.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace scene
{


/**
 * Abstract mesh codec.
 */
iface IMeshCodec :
	public core::IObject
{
public:
	/**
	 * Loads mesh from stream.
	 * @param scene Scene to load mesh into.
	 * @param stream Stream to load mesh from.
	 * @param format Format to convert image data to.
	 * @param material Optional material to assign to mesh.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param instanceCapacity Number of mesh instances to allocate.
	 * @return Loaded mesh.
	 */
	virtual ITriangleMesh*									Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity ) = 0;

	/**
	 * Loads skeleton from stream.
	 * @param stream Stream to load skeleton from.
	 * @return Loaded skeleton.
	 */
	virtual ISkeleton*										Load( io::IStream* stream ) = 0;

	/**
	 * Saves mesh to stream.
	 * @param mesh Mesh to save.
	 * @param stream Stream to save mesh to.
	 * @param mode Data mode to save data in.
	 */
	virtual void											Save( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode ) = 0;

	/**
	 * Saves skeleton to stream.
	 * @param skeleton Skeleton to save.
	 * @param stream Stream to save skeleton to.
	 * @param mode Data mode to save data in.
	 */
	virtual void											Save( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESHCODEC_
