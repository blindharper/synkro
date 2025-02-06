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
// Purpose: Bone implementation.
//==============================================================================
#include "config.h"
#include "Bone.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Bone::Bone( BaseSkeleton* skeleton, UInt index ) :
	_skeleton( skeleton ),
	_index( index )
{
}

Bone::Bone( BaseSkeleton* skeleton, const Bone* other ) :
	_skeleton( skeleton ),
	_index( other->_index )
{
}

Bone::Bone() :
	_skeleton( nullptr ),
	_index( none )
{
}


} // scene


} // synkro
