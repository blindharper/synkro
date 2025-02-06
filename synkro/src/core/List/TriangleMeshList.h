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
// Purpose: Triangle mesh list implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_TRIANGLEMESHLIST_
#define _SYNKRO_CORE_TRIANGLEMESHLIST_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/ITriangleMeshList.h>
#include <lang/Vector.h>
#include <scene/ITriangleMesh.h>


namespace synkro
{


namespace core
{


// Triangle mesh list.
class TriangleMeshList :
	public ObjectImpl<ITriangleMeshList>
{
public:
	// Constructor.
	TriangleMeshList();

	// ITriangleMeshList methods.
	void													SetSize( UInt size );
	void													Add( scene::ITriangleMesh* mesh );
	void													Set( UInt index, scene::ITriangleMesh* mesh );
	UInt													GetSize() const;
	scene::ITriangleMesh*									Get( UInt index ) const;

private:
	lang::Vector<P(scene::ITriangleMesh)>					_meshes;
};


#include "TriangleMeshList.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_TRIANGLEMESHLIST_
