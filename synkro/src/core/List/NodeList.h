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
#ifndef _SYNKRO_CORE_NODELIST_
#define _SYNKRO_CORE_NODELIST_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/INodeList.h>
#include <lang/Vector.h>
#include <scene/INode.h>


namespace synkro
{


namespace core
{


// Scene node list.
class NodeList :
	public ObjectImpl<INodeList>
{
public:
	// Constructor.
	NodeList();

	// INodeList methods.
	void													SetSize( UInt size );
	void													Add( scene::INode* node );
	void													Set( UInt index, scene::INode* node );
	UInt													GetSize() const;
	scene::INode*											Get( UInt index ) const;

private:
	lang::Vector<P(scene::INode)>							_nodes;
};


#include "NodeList.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_NODELIST_
