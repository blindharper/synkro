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
// Purpose: Generic record animation controller implementation.
//==============================================================================
#ifndef _SYNKRO_ANIM_RECORDCONTROLLERIMPL_
#define _SYNKRO_ANIM_RECORDCONTROLLERIMPL_


#include "config.h"
#include "AnimationControllerImpl.h"


namespace synkro
{


namespace anim
{


// Generic record animation controller implementation.
template <class T>
class RecordControllerImpl :
	public AnimationControllerImpl<T>
{
public:
	// Constructor & destructor.
	RecordControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation );
	virtual ~RecordControllerImpl();

	// IController methods.
	virtual void											Start( Bool start );

	// IRecordController methods.
	virtual void											SetStep( Double step );
	virtual Double											GetStep() const;

protected:
	Double													_step;
};


#include "RecordControllerImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_RECORDCONTROLLERIMPL_
