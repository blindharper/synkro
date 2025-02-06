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
// Purpose: PolyLine implementation.
//==============================================================================
#ifndef _SYNKRO_OVER_POLYLINE_
#define _SYNKRO_OVER_POLYLINE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <over/IPolyLine.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IBlendState.h>
#include <gfx/IBlendStateSet.h>


namespace synkro
{


namespace over
{


// PolyLine implementation.
class PolyLine :
	public core::ObjectImpl<IPolyLine>
{
public:
	// Constructors.
	PolyLine( gfx::IOverlayRenderQueue* queue, gfx::IGraphicsSystemEx* graphicsSystem, gfx::IBlendStateSet* blendStates, UInt pointCount, UInt width, const img::Color& color );
	PolyLine( gfx::IOverlayRenderQueue* queue, gfx::IGraphicsSystemEx* graphicsSystem, gfx::IBlendStateSet* blendStates, UInt pointCount, UInt width );

	// IPolyLine methods.
	void													Show( Bool show );
	void													SetPositions( const lang::Point* positions );
	void													SetColors( const img::Color* colors );
	void													SetColor( const img::Color& color );
	void													SetOpacity( Float opacity );
	void													SetGroupOrder( const Order& order );
	void													SetOrder( const Order& order );
	Bool													IsVisible() const;
	void													GetColor( img::Color& color ) const;
	Float													GetOpacity() const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;
	UInt													GetPointCount() const;
	UInt													GetWidth() const;

private:
	P(gfx::IOverlayRenderObject)							_polyline;
	P(gfx::IBlendStateSet)									_blendStates;
	P(gfx::IParameterSet)									_fragmentParams;
	gfx::ProgramParam*										_paramColor;
	img::Color												_color;
	Float													_opacity;
	Order													_groupOrder;
	Order													_order;
	UInt													_pointCount;
	UInt													_width;
};


#include "PolyLine.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_POLYLINE_
