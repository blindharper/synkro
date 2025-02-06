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
// Purpose: Multi material implementation.
//==============================================================================
SYNKRO_INLINE void MultiMaterial::SetColored( Bool colored )
{
}

SYNKRO_INLINE Bool MultiMaterial::IsColored() const
{
	return false;
}

SYNKRO_INLINE UInt MultiMaterial::GetSubsetCount() const
{
	return _materials.Size();
}

SYNKRO_INLINE ISimpleMaterial* MultiMaterial::AsSimple() const
{
	return nullptr;
}

SYNKRO_INLINE IMultiMaterial* MultiMaterial::AsMulti() const
{
	return (IMultiMaterial*)this;
}

SYNKRO_INLINE void MultiMaterial::SetSubset( UInt index, ISimpleMaterial* material )
{
	assert( index < _materials.Size() );
	assert( material != nullptr );

	if ( index >= _materials.Size() )
		throw lang::OutOfRangeException( index, _materials.Size() );

	_materials[index] = material;
}

SYNKRO_INLINE ISimpleMaterial* MultiMaterial::GetSubset( UInt index ) const
{
	assert( index < _materials.Size() );

	return _materials[index];
}

SYNKRO_INLINE IMultiMaterial* MultiMaterial::Clone() const
{
	return nullptr;
}
