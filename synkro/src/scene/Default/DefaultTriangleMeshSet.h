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
// Purpose: Default triangle mesh set implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTTRIANGLEMESHSET_
#define _SYNKRO_SCENE_DEFAULTTRIANGLEMESHSET_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/ITriangleMeshSet.h>
#include <scene/ISkeleton.h>
#include <scene/ITriangleSet.h>
#include <mat/IVisualMaterial.h>
#include <gfx/PrimitiveType.h>
#include <lang/Vector.h>
#include "DefaultScene.h"


namespace synkro
{


namespace scene
{


// Default triangle mesh set implementation.
class DefaultTriangleMeshSet :
	public core::ObjectImpl<ITriangleMeshSet>
{
public:
	// Constructor & destructor.
	DefaultTriangleMeshSet( DefaultScene* scene, mat::IVisualMaterial* material );
	~DefaultTriangleMeshSet();

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener );
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
	void													GetWorldTransform( math::Matrix4x4& transform, Bool ignoreOrientation ) const;
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	void													GetTransform( math::Matrix4x4& transform, Bool ignoreOrientation ) const;
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
	IBillboard*												AsBillboard() const;
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
	IPointMesh*												AsPoint() const;
	ILineMesh*												AsLine() const;
	ITriangleMesh*											AsTriangle() const;

	// ITriangleMeshSet methods.
	ITriangleSet*											CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleSet( const lang::String& name, const lang::Range& range );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	void													SetActor( phys::IActor* actor );
	ISkeleton*												GetSkeleton() const;
	mat::IVisualMaterial*									GetMaterial() const;
	phys::IActor*											GetActor() const;
	IScene*													GetScene() const;
	ITriangleMeshBatch*										AsBatch() const;
	ITriangleMeshSet*										AsSet() const;

	// ITriangleMeshSet methods.
	void													SetMinimumLevelSize( UInt index, Float size );
	UInt													GetLevelCount() const;
	Float													GetMinimumLevelSize( UInt index ) const;

private:
	DefaultScene*											_scene;
	INode*													_parent;
	mutable Bool											_transformDirty;
	mutable math::Matrix4x4									_transform;
	mutable math::Vector3									_translation;
	mutable math::Quaternion								_orientation;
	math::Vector3											_scale;
	Float													_yaw;
	Float													_pitch;
	Float													_roll;
	lang::Vector<P(ITriangleSet)>							_subsets;
	P(ITriangleSet)											_base;
	P(mat::IVisualMaterial)									_material;

	ITriangleSet*											CreateTriangleSet( const gfx::PrimitiveType& type, const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	void													AdjustAngle( Float& angle );
};


#include "DefaultTriangleMeshSet.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTTRIANGLEMESHSET_
