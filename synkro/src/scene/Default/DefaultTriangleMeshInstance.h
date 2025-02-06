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
// Purpose: Default triangle mesh node instance implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTTRIANGLEMESHINSTANCE_
#define _SYNKRO_SCENE_DEFAULTTRIANGLEMESHINSTANCE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/ITriangleMeshBatch.h>
#include <scene/ISkeleton.h>
#include <gfx/ISceneRenderObject.h>
#include <mat/IVisualMaterial.h>


namespace synkro
{


namespace scene
{


// Default triangle mesh instance implementation.
class DefaultTriangleMeshInstance :
	public core::ObjectImpl<ITriangleMesh>
{
public:
	// Constructor & destructor.
	DefaultTriangleMeshInstance( ITriangleMeshBatch* batch, mat::IVisualMaterial* material, ISkeleton* skeleton, const lang::String& name, UInt index, const math::Matrix4x4& transform );
	~DefaultTriangleMeshInstance();

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );
	void													SetTransform( const math::Matrix4x4& transform );
	void													SetPosition( const math::Vector3& position );
	void													SetPositionX( Float x );
	void													SetPositionY( Float y );
	void													SetPositionZ( Float z );
	void													SetOrientation( const math::Quaternion& orientation );
	void													SetOrientationYaw( Float yaw );
	void													SetOrientationPitch( Float pitch );
	void													SetOrientationRoll( Float roll );
	void													LookAt( const math::Vector3& target );
	void													SetScale( const math::Vector3& scale );
	void													SetScale( Float scale );
	void													SetScaleX( Float scale );
	void													SetScaleY( Float scale );
	void													SetScaleZ( Float scale );
	void													SetPath( ICurve* path );
	void													SetPathPhase( Float phase );
	void													SetParent( INode* parent );
	void													ShowGizmo( Bool show );
	void													SetGizmoSize( Float size );
	IParentConstraint*										GetParentConstraint() const;
	ILookAtConstraint*										GetLookAtConstraint() const;
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	void													GetTransform( math::Matrix4x4& transform ) const;
	void													GetPosition( math::Vector3& position ) const;
	Float													GetPositionX() const;
	Float													GetPositionY() const;
	Float													GetPositionZ() const;
	void													GetOrientation( math::Quaternion& orientation ) const;
	Float													GetOrientationYaw() const;
	Float													GetOrientationPitch() const;
	Float													GetOrientationRoll() const;
	void													GetScale( math::Vector3& scale ) const;
	Float													GetScaleX() const;
	Float													GetScaleY() const;
	Float													GetScaleZ() const;
	ICurve*													GetPath() const;
	Float													GetPathPhase() const;
	INode*													GetParent() const;
	INode*													GetNode( const lang::String& name ) const;
	ISceneEx*												GetSceneEx() const;
	lang::String											GetName() const;
	ICamera*												AsCamera() const;
	ILight*													AsLight() const;
	IMesh*													AsMesh() const;
	ISound*													AsSound() const;

	// IMesh methods.
	void													Show( Bool show );
	UInt													GetSubsetCount() const;
	lang::String											GetSubsetName( UInt index ) const;
	IPrimitive*												GetSubset( UInt index ) const;
	IPrimitive*												GetSubset( const lang::String& name ) const;
	void													GetCenter( math::Vector3& center ) const;
	Float													GetBoundSphere() const;
	Bool													IsVisible() const;
	ILineMesh*												AsLine() const;
	IPointMesh*												AsPoint() const;
	ITriangleMesh*											AsTriangle() const;

	// ITriangleMesh methods.
	ITriangleSet*											CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleSet( const lang::String& name, const lang::Range& range );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	ISkeleton*												GetSkeleton() const;
	mat::IVisualMaterial*									GetMaterial() const;
	IScene*													GetScene() const;
	ITriangleMeshBatch*										AsBatch() const;

	// Other methods.
	void													SetIndex( UInt index );

private:
	ITriangleMeshBatch*										_batch;
	P(mat::IVisualMaterial)									_material;
	P(ISkeleton)											_skeleton;
	UInt													_index;
	Bool													_visible;
};


#include "DefaultTriangleMeshInstance.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTTRIANGLEMESHINSTANCE_
