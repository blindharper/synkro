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
// Purpose: Viewport transition controller implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTTRANSITIONCONTROLLER_
#define _SYNKRO_VIEW_VIEWPORTTRANSITIONCONTROLLER_


#include "config.h"
#include <core/ControllerImpl.h>
#include <view/IViewportTransitionController.h>
#include <view/IViewport.h>
#include <lang/Vector.h>
#include "BaseViewportTransitionController.h"
#include "BaseViewportManager.h"


namespace synkro
{


namespace view
{


// Viewport transition controller implementation.
class ViewportTransitionController :
	public core::ControllerImpl<IViewportTransitionController>,
	public BaseViewportTransitionController
{
public:
	// Constructor & destructor.
	ViewportTransitionController( BaseViewportManager* viewportManager, ViewportListener* listener );
	~ViewportTransitionController();

	// IController methods.
	void													Start( Bool start );
	void													Update( Double delta );

	// IViewportTransitionController methods.
	void													Clear();
	void													SetKey( Double time, IViewport* viewport, const TransitionEffect& effect );
	void													SetKey( Double time, IViewport* viewport );
	void													SetLoopCount( UInt loopCount );
	UInt													GetKeyCount() const;
	Double													GetKeyTime( UInt index ) const;
	TransitionEffect										GetKeyEffect( UInt index ) const;
	IViewport*												GetKeyViewport( UInt index ) const;
	UInt													GetLoopCount() const;

	// BaseViewportTransitionController methods.
	void													PostUpdate();

private:
	struct Key
	{
		Key( Double time, IViewport* viewport, const TransitionEffect& effect ) :
			Time( time ),
			Viewport( viewport ),
			Effect( effect )
		{
		}

		Key() :
			Time( 0.0 ),
			Effect( TransitionEffect::Step )
		{
		}

		Double				Time;
		P(IViewport)		Viewport;
		TransitionEffect	Effect;
	};

	lang::Vector<Key>										_keys;
	BaseViewportManager*									_viewportManager;
	ViewportListener*										_listener;
	Double													_length;
	UInt													_loopCount;
	UInt													_iteration;

	Double													GetLength() const;
	Bool													GetFork( Double time, UInt& key1, UInt& key2 ) const;
	void													Prepare();
};


#include "ViewportTransitionController.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTTRANSITIONCONTROLLER_
