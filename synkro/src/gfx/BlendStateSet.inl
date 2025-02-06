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
// Purpose: Logical blend state set.
//==============================================================================
SYNKRO_INLINE void BlendStateSet::Bind()
{
	SynkroProfile( "BlendStateSet.Bind" );

	_set->Bind();
}

SYNKRO_INLINE void BlendStateSet::Enable( Bool enable )
{
	_set->Enable( enable );
}

SYNKRO_INLINE void BlendStateSet::EnableAlphaToCoverage( Bool enable )
{
	if ( _readonly )
		throw lang::InvalidOperationException( L"Cannot modify default blend state." );

	_set->EnableAlphaToCoverage( enable );
}

SYNKRO_INLINE void BlendStateSet::SetSrcMode( const BlendMode& mode )
{
	_set->SetSrcMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetColorSrcMode( const BlendMode& mode )
{
	_set->SetColorSrcMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetAlphaSrcMode( const BlendMode& mode )
{
	_set->SetAlphaSrcMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetDstMode( const BlendMode& mode )
{
	_set->SetDstMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetColorDstMode( const BlendMode& mode )
{
	_set->SetColorDstMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetAlphaDstMode( const BlendMode& mode )
{
	_set->SetAlphaDstMode( mode );
}

SYNKRO_INLINE void BlendStateSet::SetOperation( const BlendOperation& operation )
{
	_set->SetOperation( operation );
}

SYNKRO_INLINE void BlendStateSet::SetColorOperation( const BlendOperation& operation )
{
	_set->SetColorOperation( operation );
}

SYNKRO_INLINE void BlendStateSet::SetAlphaOperation( const BlendOperation& operation )
{
	_set->SetAlphaOperation( operation );
}

SYNKRO_INLINE void BlendStateSet::SetWriteChannels( const img::PixelChannel& channels )
{
	_set->SetWriteChannels( channels );
}

SYNKRO_INLINE Bool BlendStateSet::IsAlphaToCoverageEnabled() const
{
	return _set->IsAlphaToCoverageEnabled();
}

SYNKRO_INLINE IBlendStateSet* BlendStateSet::Clone() const
{
	return new BlendStateSet( *this );
}
