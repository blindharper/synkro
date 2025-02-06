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
// Purpose: Scene node list implementation.
//==============================================================================
SYNKRO_INLINE void NodeList::SetSize( UInt size )
{
	_nodes.SetSize( size );
}

SYNKRO_INLINE void NodeList::Add( scene::INode* node )
{
	_nodes.Add( node );
}

SYNKRO_INLINE void NodeList::Set( UInt index, scene::INode* node )
{
	assert( index < _nodes.Size() );

	if ( index >= _nodes.Size() )
		throw lang::OutOfRangeException( index, _nodes.Size() );

	_nodes[index] = node;
}

SYNKRO_INLINE UInt NodeList::GetSize() const
{
	return _nodes.Size();
}

SYNKRO_INLINE scene::INode* NodeList::Get( UInt index ) const
{
	assert( index < _nodes.Size() );

	if ( index >= _nodes.Size() )
		throw lang::OutOfRangeException( index, _nodes.Size() );

	return _nodes[index];
}
