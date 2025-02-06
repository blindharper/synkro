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
// Purpose: Point mesh implementation.
//==============================================================================
#include "config.h"
#include "PointMesh.h"
#include "PointSet.h"
#include "NodeAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IParameterSet.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/DataAccess.h>
#include <gfx/DataUsage.h>
#include <scene/IScene.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::input;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PointMesh::PointMesh( ISceneEx* scene, IContext* context, const String& name ) :
	MeshImpl<IPointMesh>( scene, context, AsBaseScene(scene)->GetPointMeshName(name) )
{
}

INodeAnimationController* PointMesh::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new NodeAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* PointMesh::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* PointMesh::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

IPointSet* PointMesh::CreatePointList( const String& name, UInt count, Float size, const ColorMode& colorMode, const Matrix4x4& transform )
{
	String programName = (colorMode == ColorMode::Colored) ? L"line.colored" : L"line.monochrome";
	IProgram* program = _context->GetGraphicsSystem()->GetProgram( programName );
	gfx::IPrimitive* data = _context->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::PointList, IndexType::None, count, 0, 0, 0, true, false );
	ILineRenderQueue* queue = _scene->GetRenderQueue()->GetLineQueue();
	ILineRenderObject* object = queue->CreateObject( data );
	if ( !name.IsNull() )
	{
		object->SetVertexParameters( program->GetVertexStage()->GetParameters()->Clone( object->ID(), true) );
	}
	P(IPointSet) subset = new PointSet( _context, object, 0, 0, size );
	if ( name.IsNull() )
	{
		if ( _base.Primitive != nullptr )
			throw InvalidOperationException( L"Base primitive already exists." );

		subset->Show( false );
		_base.Primitive = subset;
		_base.Primitive->SetTransform( transform );
	}
	else
	{
		if ( _base.Primitive != nullptr )
			throw InvalidOperationException( L"Only reference primitives are allowed after the base primitive has been created." );

		_subsets.Add( SubsetDesc(subset, transform, name) );
	}
	return subset;
}

IPointSet* PointMesh::CreatePointSet( const String& name, const Range& range )
{
	if ( _base.Primitive == nullptr )
		throw InvalidOperationException( L"Base primitive does not exist." );

	PointSet* base = (PointSet*)_base.Primitive.AsPtr();
	IPointSet* subset = base->CreateSubset( range.Start, range.Length );
	_subsets.Add( SubsetDesc(subset, _base.Primitive, name) );
	return subset;
}

void PointMesh::SetColor( const Color& color )
{
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->AsPointSet()->SetColor( color );
	}
}

void PointMesh::Update()
{
	NodeImpl<IPointMesh>::ApplyConstraints( _ctrlAnimation );

	Matrix4x4 worldTransform;
	GetWorldTransform( worldTransform );

	// Set subset transforms.
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i].Primitive->SetOwnerTransform( worldTransform );
	}
}
	

} // scene


} // synkro
