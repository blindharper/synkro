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
// Purpose: Logical blend state.
//==============================================================================
SYNKRO_INLINE void BlendState::Enable( Bool enable )
{
	PreventModify();

	_state->Enable( enable );
}

SYNKRO_INLINE void BlendState::SetSrcMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetSrcMode( mode );
}

SYNKRO_INLINE void BlendState::SetColorSrcMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetColorSrcMode( mode );
}

SYNKRO_INLINE void BlendState::SetAlphaSrcMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetAlphaSrcMode( mode );
}

SYNKRO_INLINE void BlendState::SetDstMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetDstMode( mode );
}

SYNKRO_INLINE void BlendState::SetColorDstMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetColorDstMode( mode );
}

SYNKRO_INLINE void BlendState::SetAlphaDstMode( const BlendMode& mode )
{
	PreventModify();

	_state->SetAlphaDstMode( mode );
}

SYNKRO_INLINE void BlendState::SetOperation( const BlendOperation& operation )
{
	PreventModify();

	_state->SetOperation( operation );
}

SYNKRO_INLINE void BlendState::SetColorOperation( const BlendOperation& operation )
{
	PreventModify();

	_state->SetColorOperation( operation );
}

SYNKRO_INLINE void BlendState::SetAlphaOperation( const BlendOperation& operation )
{
	PreventModify();

	_state->SetAlphaOperation( operation );
}

SYNKRO_INLINE void BlendState::SetWriteChannels( const img::PixelChannel& channels )
{
	PreventModify();

	_state->SetWriteChannels( channels );
}

SYNKRO_INLINE Bool BlendState::IsEnabled() const
{
	return _state->IsEnabled();
}

SYNKRO_INLINE BlendMode BlendState::GetColorSrcMode() const
{
	return _state->GetColorSrcMode();
}

SYNKRO_INLINE BlendMode BlendState::GetAlphaSrcMode() const
{
	return _state->GetAlphaSrcMode();
}

SYNKRO_INLINE BlendMode BlendState::GetColorDstMode() const
{
	return _state->GetColorDstMode();
}

SYNKRO_INLINE BlendMode BlendState::GetAlphaDstMode() const
{
	return _state->GetAlphaDstMode();
}

SYNKRO_INLINE BlendOperation BlendState::GetColorOperation() const
{
	return _state->GetColorOperation();
}

SYNKRO_INLINE BlendOperation BlendState::GetAlphaOperation() const
{
	return _state->GetAlphaOperation();
}

SYNKRO_INLINE img::PixelChannel BlendState::GetWriteChannels() const
{
	return _state->GetWriteChannels();
}
