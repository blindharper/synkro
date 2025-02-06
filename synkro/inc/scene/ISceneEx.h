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
// Purpose: Defines extended 3D scene.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISCENEEX_
#define _SYNKRO_SCENE_ISCENEEX_


#include "config.h"
#include <scene/IScene.h>
#include <img/Color.h>
#include <math/Matrix4x4.h>
#include <scene/DebugMode.h>
#include <scene/MeshCodec.h>
#include <sound/SoundCodec.h>


namespace synkro
{


namespace scene
{


/**
 * Extended 3D scene.
 */
iface ISceneEx :
	public IScene
{
public:
	/**
	 * Creates animation controller for the scene.
	 * @param animation Optional scene animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual ISceneAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/** 
	 * Creates dummy node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual INode*											CreateDummy( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates curve node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual ICurve*											CreateCurve( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates camera node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual ICamera*										CreateCamera( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates omni light source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual IOmniLight*										CreateOmniLight( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates cone light source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual IConeLight*										CreateConeLight( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates direct light source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual IDirectLight*									CreateDirectLight( INode* parent, const lang::String& name ) = 0;

	/** 
	 * Creates omni sound source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @param stream Sound data.
	 * @param type Sound codec type.
	 * @return Created node.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual IOmniSound*										CreateOmniSound( INode* parent, const lang::String& name, io::IStream* stream, const sound::SoundCodec& type ) = 0;

	/** 
	 * Creates omni sound source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @param stream Sound data.
	 * @return Created node.
	 */
	virtual IOmniSound*										CreateOmniSound( INode* parent, const lang::String& name, io::IStream* stream ) = 0;

	/** 
	 * Creates cone sound source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @param stream Sound data.
	 * @param type Sound codec type.
	 * @return Created node.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual IConeSound*										CreateConeSound( INode* parent, const lang::String& name, io::IStream* stream, const sound::SoundCodec& type ) = 0;

	/** 
	 * Creates cone sound source with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @param stream Sound data.
	 * @return Created node.
	 */
	virtual IConeSound*										CreateConeSound( INode* parent, const lang::String& name, io::IStream* stream ) = 0;

	/**
	 * Creates point mesh node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual IPointMesh*										CreatePointMesh( INode* parent, const lang::String& name ) = 0;

	/**
	 * Creates a batch of point mesh nodes.
	 * @param capacity Number of mesh instances to allocate.
	 * @return Created mesh batch.
	 */
	virtual IPointMeshBatch*								CreatePointMeshBatch( UInt capacity ) = 0;

	/**
	 * Creates line mesh node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @return Created node.
	 */
	virtual ILineMesh*										CreateLineMesh( INode* parent, const lang::String& name ) = 0;

	/**
	 * Creates a batch of line mesh nodes.
	 * @param capacity Number of mesh instances to allocate.
	 * @return Created mesh batch.
	 */
	virtual ILineMeshBatch*									CreateLineMeshBatch( UInt capacity ) = 0;

	/**
	 * Loads mesh from a stream. Opens stream for reading and closes it after mesh is loaded.
	 * @param stream Stream from which to load mesh.
	 * @param material Optional material to assign to mesh.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param instanceCapacity Number of mesh instances to allocate.
	 * @param type Mesh codec type.
	 * @return Loaded mesh if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong mesh type.
	 */
	virtual ITriangleMesh*									LoadMesh( io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type ) = 0;

	/**
	 * Loads mesh from a stream. Opens stream for reading and closes it after mesh is loaded.
	 * @param stream Stream from which to load mesh.
	 * @param material Optional material to assign to mesh.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param instanceCapacity Number of mesh instances to allocate.
	 * @return Loaded mesh if succeeded, or null otherwise.
	 */
	virtual ITriangleMesh*									LoadMesh( io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity ) = 0;

	/**
	 * Sets scene ambient light color.
	 * @param color Ambient light color.
	 */
	virtual void											SetAmbientLightColor( const img::Color& color ) = 0;

	/**
	 * Sets scene ambient light intensity.
	 * @param intensity Ambient light intensity. Should be in range [0, 1].
	 */
	virtual void											SetAmbientLightIntensity( Float intensity ) = 0;

	/**
	 * Sets sky properties.
	 * @param map Sky image.
	 * @param size Sky size.
	 */
	virtual void											SetSky( img::IImage* map, Float size ) = 0;

	/**
	 * Retrieves a node with the given name.
	 * @param name Node name.
	 * @return Requested node, if one is found, or nullptr otherwise.
	 */
	virtual INode*											GetNode( const lang::String& name ) const = 0;

	/**
	 * Retrieves a node with the given identifier.
	 * @param id Node identifier.
	 * @return Requested node, if one is found, or nullptr otherwise.
	 */
	virtual INode*											GetNode( UInt id ) const = 0;

	/**
	 * Retrieves the root node of the scene.
	 * @return Root node.
	 */
	virtual INode*											GetRoot() const = 0;

	/**
	 * Retrieves scene's fog properties.
	 */
	virtual IFog*											GetFog() const = 0;

	/**
	 * Retrieves ambient light color.
	 * @param [out] color Ambient light color.
	 */
	virtual void											GetAmbientLightColor( img::Color& color ) const = 0;

	/**
	 * Retrieves ambient light intensity.
	 */
	virtual Float											GetAmbientLightIntensity() const = 0;

	/**
	 * Retrieves underlying audio environment.
	 */
	virtual audio::IAudioEnvironment*						GetAudioEnvironment() const = 0;

	/**
	 * Retrieves scene name.
	 */
	virtual lang::String									GetName() const = 0;

	/**
	 * Retrieves debug mode.
	 */
	virtual DebugMode										GetDebugMode() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISCENEEX_
