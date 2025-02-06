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
// Purpose: Default triangle mesh batch implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTTRIANGLEMESHBATCH_
#define _SYNKRO_SCENE_DEFAULTTRIANGLEMESHBATCH_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/ITriangleMeshBatch.h>
#include <scene/IMeshBatchAnimationController.h>
#include <scene/ISkeleton.h>
#include <scene/ITriangleSet.h>
#include <mat/IVisualMaterial.h>
#include <gfx/PrimitiveType.h>
#include "DefaultScene.h"


namespace synkro
{


namespace scene
{


// Default triangle mesh batch implementation.
class DefaultTriangleMeshBatch :
	public core::ObjectImpl<ITriangleMeshBatch>
{
public:
	// Constructor.
	DefaultTriangleMeshBatch( DefaultScene* scene, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt capacity );

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
	IPointMesh*												AsPoint() const;
	ILineMesh*												AsLine() const;
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

	// ITriangleMeshBatch methods.
	ITriangleMesh*											CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	void													RemoveInstance( UInt index );
	void													SetRange( const lang::Range& range );
	void													SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	void													SetInstanceColor( UInt index, const img::Color& color );
	UInt													GetCapacity() const;
	UInt													GetInstanceCount() const;
	ITriangleMesh*											GetInstance( UInt index ) const;
	void													GetRange( lang::Range& range ) const;

	// Other methods.
	ITriangleSet*											CreateTriangleSet( const gfx::PrimitiveType& type, const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );

private:
	DefaultScene*											_scene;
	P(IMeshBatchAnimationController)						_ctrlAnimation;
	P(ISkeleton)											_skeleton;
	P(mat::IVisualMaterial)									_material;
	P(ITriangleSet)											_base;
	lang::Vector<P(ITriangleSet)>							_subsets;
	lang::Vector<P(ITriangleMesh)>							_instances;
	lang::Range												_range;
};


#include "DefaultTriangleMeshBatch.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTTRIANGLEMESHBATCH_
