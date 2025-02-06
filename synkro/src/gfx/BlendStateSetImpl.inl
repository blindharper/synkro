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
// Purpose: Generic blend state set implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE BlendStateSetImpl<T>::BlendStateSetImpl( UInt capacity ) :
	_states( A(P(IBlendState)), capacity ),
	_alphaToCoverageEnabled( false )
{
}

template <class T>
SYNKRO_INLINE BlendStateSetImpl<T>::~BlendStateSetImpl()
{
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::Enable( Bool enable )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->Enable( enable );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::EnableAlphaToCoverage( Bool enable )
{
	if ( enable != _alphaToCoverageEnabled )
	{
		_alphaToCoverageEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetSrcMode( const BlendMode& mode )
{
	SetColorSrcMode( mode );
	SetAlphaSrcMode( mode );
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetColorSrcMode( const BlendMode& mode )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetColorSrcMode( mode );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetAlphaSrcMode( const BlendMode& mode )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAlphaSrcMode( mode );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetDstMode( const BlendMode& mode )
{
	SetColorDstMode( mode );
	SetAlphaDstMode( mode );
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetColorDstMode( const BlendMode& mode )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetColorDstMode( mode );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetAlphaDstMode( const BlendMode& mode )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAlphaDstMode( mode );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetOperation( const BlendOperation& operation )
{
	SetColorOperation( operation );
	SetAlphaOperation( operation );
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetColorOperation( const BlendOperation& operation )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetColorOperation( operation );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetAlphaOperation( const BlendOperation& operation )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAlphaOperation( operation );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void BlendStateSetImpl<T>::SetWriteChannels( const img::PixelChannel& channels )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetWriteChannels( channels );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE Bool  BlendStateSetImpl<T>::IsAlphaToCoverageEnabled() const
{
	return _alphaToCoverageEnabled;
}

template <class T>
SYNKRO_INLINE UInt BlendStateSetImpl<T>::GetSize() const
{
	return _states.Size();
}

template <class T>
SYNKRO_INLINE IBlendState* BlendStateSetImpl<T>::Get( UInt index ) const
{
	assert( index < _states.Size() );

	if ( index >= _states.Size() )
		throw lang::OutOfRangeException( index, _states.Size() );

	return _states[index];
}
