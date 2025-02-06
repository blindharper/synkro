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
// Purpose: Generic depth-stencil state implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DepthStencilStateImpl<T>::DepthStencilStateImpl() :
	_depthEnabled( true ),
	_depthWriteEnabled( true ),
	_depthFunction( CompareFunction::LessOrEqual ),
	_stencilEnabled( false ),
	_maskRead( 0xff ),
	_maskWrite( 0xff ),
	_reference( 0x00 ),
	_frontFailOp( StencilOperation::None ),
	_frontDepthFailOp( StencilOperation::None ),
	_frontPassOp( StencilOperation::None ),
	_frontStencilFunction( CompareFunction::Always ),
	_backFailOp( StencilOperation::None ),
	_backDepthFailOp( StencilOperation::None ),
	_backPassOp( StencilOperation::None ),
	_backStencilFunction( CompareFunction::Always )
{
}

template <class T>
SYNKRO_INLINE DepthStencilStateImpl<T>::~DepthStencilStateImpl()
{
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::EnableDepth( Bool enable )
{
	if ( enable != _depthEnabled )
	{
		_depthEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::EnableDepthWrite( Bool enable )
{
	if ( enable != _depthWriteEnabled )
	{
		_depthWriteEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetDepthFunction( const CompareFunction& function )
{
	if ( function != _depthFunction )
	{
		_depthFunction = function;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::EnableStencil( Bool enable )
{
	if ( enable != _stencilEnabled )
	{
		_stencilEnabled = enable;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetReadMask( Byte mask )
{
	if ( mask != _maskRead )
	{
		_maskRead = mask;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetWriteMask( Byte mask )
{
	if ( mask != _maskWrite )
	{
		_maskWrite = mask;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetReference( Byte reference )
{
	// NB: Reference value is actually not a part of the state, so don't set _dirty flag here.
	_reference = reference;
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetFailOperation( const StencilOperation& operation )
{
	SetFrontFailOperation( operation );
	SetBackFailOperation( operation );
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetFrontFailOperation( const StencilOperation& operation )
{
	if ( operation != _frontFailOp )
	{
		_frontFailOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetBackFailOperation( const StencilOperation& operation )
{
	if ( operation != _backFailOp )
	{
		_backFailOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetDepthFailOperation( const StencilOperation& operation )
{
	SetFrontDepthFailOperation( operation );
	SetBackDepthFailOperation( operation );
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetFrontDepthFailOperation( const StencilOperation& operation )
{
	if ( operation != _frontDepthFailOp )
	{
		_frontDepthFailOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetBackDepthFailOperation( const StencilOperation& operation )
{
	if ( operation != _backDepthFailOp )
	{
		_backDepthFailOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetPassOperation( const StencilOperation& operation )
{
	SetFrontPassOperation( operation );
	SetBackPassOperation( operation );
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetFrontPassOperation( const StencilOperation& operation )
{
	if ( operation != _frontPassOp )
	{
		_frontPassOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetBackPassOperation( const StencilOperation& operation )
{
	if ( operation != _backPassOp )
	{
		_backPassOp = operation;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetStencilFunction( const CompareFunction& function )
{
	SetFrontStencilFunction( function );
	SetBackStencilFunction( function );
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetFrontStencilFunction( const CompareFunction& function )
{
	if ( function != _frontStencilFunction )
	{
		_frontStencilFunction = function;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void DepthStencilStateImpl<T>::SetBackStencilFunction( const CompareFunction& function )
{
	if ( function != _backStencilFunction )
	{
		_backStencilFunction = function;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE Bool DepthStencilStateImpl<T>::IsDepthEnabled() const
{
	return _depthEnabled;
}

template <class T>
SYNKRO_INLINE Bool DepthStencilStateImpl<T>::IsDepthWriteEnabled() const
{
	return _depthWriteEnabled;
}

template <class T>
SYNKRO_INLINE CompareFunction DepthStencilStateImpl<T>::GetDepthFunction() const
{
	return _depthFunction;
}

template <class T>
SYNKRO_INLINE Bool DepthStencilStateImpl<T>::IsStencilEnabled() const
{
	return _stencilEnabled;
}

template <class T>
SYNKRO_INLINE Byte DepthStencilStateImpl<T>::GetReadMask() const
{
	return _maskRead;
}

template <class T>
SYNKRO_INLINE Byte DepthStencilStateImpl<T>::GetWriteMask() const
{
	return _maskWrite;
}

template <class T>
SYNKRO_INLINE Byte DepthStencilStateImpl<T>::GetReference() const
{
	return _reference;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetFrontFailOperation() const
{
	return _frontFailOp;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetBackFailOperation() const
{
	return _backFailOp;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetFrontDepthFailOperation() const
{
	return _frontDepthFailOp;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetBackDepthFailOperation() const
{
	return _backDepthFailOp;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetFrontPassOperation() const
{
	return _frontPassOp;
}

template <class T>
SYNKRO_INLINE StencilOperation DepthStencilStateImpl<T>::GetBackPassOperation() const
{
	return _backPassOp;
}

template <class T>
SYNKRO_INLINE CompareFunction DepthStencilStateImpl<T>::GetFrontStencilFunction() const
{
	return _frontStencilFunction;
}

template <class T>
SYNKRO_INLINE CompareFunction DepthStencilStateImpl<T>::GetBackStencilFunction() const
{
	return _backStencilFunction;
}
