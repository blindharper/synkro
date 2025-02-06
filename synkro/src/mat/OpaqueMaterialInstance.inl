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
// Purpose: Opaque material instance implementation.
//==============================================================================
SYNKRO_INLINE scene::ITriangleSet* OpaqueMaterialInstance::CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return _material->CreateTriangleList( mesh, index, vertexCount, indexCount, adjacency );
}

SYNKRO_INLINE scene::ITriangleSet* OpaqueMaterialInstance::CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return _material->CreateTriangleStrip( mesh, index, vertexCount, indexCount, adjacency );
}

SYNKRO_INLINE void OpaqueMaterialInstance::SetColored( Bool colored )
{
	return _material->SetColored( colored );
}

SYNKRO_INLINE Bool OpaqueMaterialInstance::IsColored() const
{
	return _material->IsColored();
}

SYNKRO_INLINE UInt OpaqueMaterialInstance::GetSubsetCount() const
{
	return _material->GetSubsetCount();
}

SYNKRO_INLINE ISimpleMaterial* OpaqueMaterialInstance::AsSimple() const
{
	return (ISimpleMaterial*)this;
}

SYNKRO_INLINE IMultiMaterial* OpaqueMaterialInstance::AsMulti() const
{
	return nullptr;
}

SYNKRO_INLINE IOpaqueMaterial* OpaqueMaterialInstance::AsOpaque() const
{
	return (IOpaqueMaterial*)this;
}

SYNKRO_INLINE ITransparentMaterial* OpaqueMaterialInstance::AsTransparent() const
{
	return nullptr;
}

SYNKRO_INLINE void OpaqueMaterialInstance::SetTwoSided( Bool twoSided )
{
	_material->SetTwoSided( twoSided );
}

SYNKRO_INLINE void OpaqueMaterialInstance::SetWireframe( Bool wireframe )
{
	_material->SetWireframe( wireframe );
}

SYNKRO_INLINE Bool OpaqueMaterialInstance::IsTwoSided() const
{
	return _material->IsTwoSided();
}

SYNKRO_INLINE Bool OpaqueMaterialInstance::IsWireframe() const
{
	return _material->IsWireframe();
}

SYNKRO_INLINE IOpaqueMaterial* OpaqueMaterialInstance::Clone() const
{
	return _material->Clone();
}
