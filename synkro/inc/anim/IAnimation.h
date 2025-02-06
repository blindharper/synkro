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
// Purpose: Defines animation object.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATION_
#define _SYNKRO_ANIM_IANIMATION_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <anim/AnimationTrack.h>


namespace synkro
{


namespace anim
{


/**
 * Container for animation tracks.
 */
iface IAnimation :
	public core::IObject
{
public:
	/**
	 * Creates keyframed boolean track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedBoolTrack*							CreateBoolTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression boolean track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionBoolTrack*							CreateBoolTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression boolean track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionBoolTrack*							CreateBoolTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed color track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedColorTrack*							CreateColorTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression color track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionColorTrack*							CreateColorTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression color track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionColorTrack*							CreateColorTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates procedural color track and adds it to the animation.
	 * @param name Track name.
	 * @param type Track type.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Unknown track type.
	 * @exception BadArgumentException Wrong track data type.
	 */
	virtual IProceduralColorTrack*							CreateColorTrack( const lang::String& name, const AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed color gradient track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedColorGradientTrack*					CreateColorGradientTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression color gradient track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionColorGradientTrack*					CreateColorGradientTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression color gradient track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionColorGradientTrack*					CreateColorGradientTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed floating-point track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedFloatTrack*							CreateFloatTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression floating-point track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionFloatTrack*							CreateFloatTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression floating-point track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionFloatTrack*							CreateFloatTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates procedural floating-point track and adds it to the animation.
	 * @param name Track name.
	 * @param type Track type.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Unknown track type.
	 * @exception BadArgumentException Wrong track data type.
	 */
	virtual IProceduralFloatTrack*							CreateFloatTrack( const lang::String& name, const AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedFloatRectTrack*						CreateFloatRectTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression floating-point rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionFloatRectTrack*						CreateFloatRectTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression floating-point rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionFloatRectTrack*						CreateFloatRectTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed whole-number track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedIntTrack*								CreateIntTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression whole-number track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionIntTrack*							CreateIntTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression whole-number track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionIntTrack*							CreateIntTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed 4x4-matrix track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedMatrix4x4Track*						CreateMatrix4x4Track( const lang::String& name ) = 0;

	/**
	 * Creates expression 4x4-matrix track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionMatrix4x4Track*						CreateMatrix4x4Track( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression 4x4-matrix track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionMatrix4x4Track*						CreateMatrix4x4Track( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed point track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedPointTrack*							CreatePointTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression point track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionPointTrack*							CreatePointTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression point track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionPointTrack*							CreatePointTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed quaternion track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedQuaternionTrack*						CreateQuaternionTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression quaternion track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionQuaternionTrack*						CreateQuaternionTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression quaternion track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionQuaternionTrack*						CreateQuaternionTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed range track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedRangeTrack*							CreateRangeTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression range track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionRangeTrack*							CreateRangeTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression range track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionRangeTrack*							CreateRangeTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedRectTrack*							CreateRectTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionRectTrack*							CreateRectTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression rectangle track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionRectTrack*							CreateRectTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed size track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedSizeTrack*							CreateSizeTrack( const lang::String& name ) = 0;

	/**
	 * Creates expression size track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionSizeTrack*							CreateSizeTrack( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression size track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionSizeTrack*							CreateSizeTrack( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates keyframed empty 3-component vector track and adds it to the animation.
	 * @param name Track name.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 */
	virtual IKeyframedVector3Track*							CreateVector3Track( const lang::String& name ) = 0;

	/**
	 * Creates expression 3-component vector track and adds it to the animation.
	 * @param name Track name.
	 * @param script Expression script.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionVector3Track*						CreateVector3Track( const lang::String& name, IExpressionScript* script ) = 0;

	/**
	 * Creates expression 3-component vector track and adds it to the animation.
	 * @param name Track name.
	 * @param expression Expression text.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Wrong expression type.
	 */
	virtual IExpressionVector3Track*						CreateVector3Track( const lang::String& name, const lang::String& expression ) = 0;

	/**
	 * Creates procedural 3-component vector track and adds it to the animation.
	 * @param name Track name.
	 * @param type Track type.
	 * @return Created animation track.
	 * @exception BadArgumentException Track with the specified name already exists.
	 * @exception BadArgumentException Unknown track type.
	 * @exception BadArgumentException Wrong track data type.
	 */
	virtual IProceduralVector3Track*						CreateVector3Track( const lang::String& name, const AnimationTrack& type ) = 0;

	/**
	 * Retrieves the number of tracks comprising the animation.
	 */
	virtual UInt											GetTrackCount() const = 0;

	/**
	 * Retrieves value track by index.
	 * @param index Index of the track to retrieve.
	 * @return Requested value track.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAnimationTrack*								GetTrack( UInt index ) const = 0;

	/**
	 * Retrieves value track by name.
	 * @param name Value track name.
	 * @return Requested value track, if found, nullptr otherwise.
	 */
	virtual IAnimationTrack*								GetTrack( const lang::String& name ) const = 0;

	/**
	 * Retrieves animation length, in seconds.
	 * Animation length is equal to the length of its longest track.
	 */
	virtual Double											GetLength() const = 0;

	/**
	 * Retrieves animation name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATION_
