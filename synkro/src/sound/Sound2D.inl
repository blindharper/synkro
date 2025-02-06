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
// Purpose: 2D sound implementation.
//==============================================================================
SYNKRO_INLINE void Sound2D::Play( Bool play )
{
	_buffer->Process( play, false );
}

SYNKRO_INLINE void Sound2D::SetVolume( Int volume )
{
	_buffer->SetAttenuation( volume );
}

SYNKRO_INLINE Bool Sound2D::IsPlaying() const
{
	return _buffer->GetChunk(0)->IsProcessing();
}

SYNKRO_INLINE Int Sound2D::GetVolume() const
{
	return _buffer->GetAttenuation();
}

SYNKRO_INLINE Double Sound2D::GetLength() const
{
	return _length;
}
