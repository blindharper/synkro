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
// Purpose: Transparent material instance implementation.
//==============================================================================
SYNKRO_INLINE scene::ITriangleSet* TransparentMaterialInstance::CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return _material->CreateTriangleList( mesh, index, vertexCount, indexCount, adjacency );
}

SYNKRO_INLINE scene::ITriangleSet* TransparentMaterialInstance::CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency )
{
	return _material->CreateTriangleStrip( mesh, index, vertexCount, indexCount, adjacency );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetColored( Bool colored )
{
	return _material->SetColored( colored );
}

SYNKRO_INLINE Bool TransparentMaterialInstance::IsColored() const
{
	return _material->IsColored();
}

SYNKRO_INLINE UInt TransparentMaterialInstance::GetSubsetCount() const
{
	return _material->GetSubsetCount();
}

SYNKRO_INLINE ISimpleMaterial* TransparentMaterialInstance::AsSimple() const
{
	return (ISimpleMaterial*)this;
}

SYNKRO_INLINE IMultiMaterial* TransparentMaterialInstance::AsMulti() const
{
	return nullptr;
}

SYNKRO_INLINE IMaterialMap* TransparentMaterialInstance::GetDiffuseMap() const
{
	return _material->GetDiffuseMap();
}

SYNKRO_INLINE IOpaqueMaterial* TransparentMaterialInstance::AsOpaque() const
{
	return nullptr;
}

SYNKRO_INLINE ITransparentMaterial* TransparentMaterialInstance::AsTransparent() const
{
	return (ITransparentMaterial*)this;
}

SYNKRO_INLINE void TransparentMaterialInstance::SetOpacity( Float opacity )
{
	_material->SetOpacity( opacity );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetColorSourceMode( const gfx::BlendMode& mode )
{
	_material->SetColorSourceMode( mode );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetAlphaSourceMode( const gfx::BlendMode& mode )
{
	_material->SetAlphaSourceMode( mode );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetColorDestinationMode( const gfx::BlendMode& mode )
{
	_material->SetColorDestinationMode( mode );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetAlphaDestinationMode( const gfx::BlendMode& mode )
{
	_material->SetAlphaDestinationMode( mode );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetColorOperation( const gfx::BlendOperation& operation )
{
	_material->SetColorOperation( operation );
}

SYNKRO_INLINE void TransparentMaterialInstance::SetAlphaOperation( const gfx::BlendOperation& operation )
{
	_material->SetAlphaOperation( operation );
}

SYNKRO_INLINE Float TransparentMaterialInstance::GetOpacity() const
{
	return _material->GetOpacity();
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterialInstance::GetColorSourceMode() const
{
	return _material->GetColorSourceMode();
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterialInstance::GetAlphaSourceMode() const
{
	return _material->GetAlphaSourceMode();
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterialInstance::GetColorDestinationMode() const
{
	return _material->GetColorDestinationMode();
}

SYNKRO_INLINE gfx::BlendMode TransparentMaterialInstance::GetAlphaDestinationMode() const
{
	return _material->GetAlphaDestinationMode();
}

SYNKRO_INLINE gfx::BlendOperation TransparentMaterialInstance::GetColorOperation() const
{
	return _material->GetColorOperation();
}

SYNKRO_INLINE gfx::BlendOperation TransparentMaterialInstance::GetAlphaOperation() const
{
	return _material->GetAlphaOperation();
}

SYNKRO_INLINE IMaterialMap* TransparentMaterialInstance::GetOpacityMap() const
{
	return _material->GetOpacityMap();
}

SYNKRO_INLINE ITransparentMaterial* TransparentMaterialInstance::Clone() const
{
	return _material->Clone();
}
