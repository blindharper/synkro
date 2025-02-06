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
// Purpose: Generic expression track implementation.
//==============================================================================
template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE ExpressionTrackImpl<T, K, P, V, D>::ExpressionTrackImpl( const lang::String& name, IExpressionScript* script ) :
	AnimationTrackImpl<T, D>( name ),
	_script( script )
{
	_paramTime = _script->GetParam( L"time" );
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE ExpressionTrackImpl<T, K, P, V, D>::~ExpressionTrackImpl()
{
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE void ExpressionTrackImpl<T, K, P, V, D>::GetValue( Double time, typename V& value ) const
{
	_script->SetParamValue( _paramTime, CastFloat(time) );
	_script->GetValue( value );
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE typename K* ExpressionTrackImpl<T, K, P, V, D>::AsKeyframed() const
{
	return nullptr;
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE typename P* ExpressionTrackImpl<T, K, P, V, D>::AsProcedural() const
{
	return nullptr;
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE typename T* ExpressionTrackImpl<T, K, P, V, D>::AsExpression() const
{
	return (typename T*)this;
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE void ExpressionTrackImpl<T, K, P, V, D>::SetLength( Double length )
{
	_length = length;
}

template <class T, class K, class P, class V, UInt D>
SYNKRO_INLINE IExpressionScript* ExpressionTrackImpl<T, K, P, V, D>::GetScript() const
{
	return _script;
}
