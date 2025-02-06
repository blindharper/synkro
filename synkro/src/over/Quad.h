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
// Purpose: Quad implementation.
//==============================================================================
#ifndef _SYNKRO_OVER_QUAD_
#define _SYNKRO_OVER_QUAD_


#include "config.h"
#include <core/ObjectImpl.h>
#include <over/IQuad.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IParameterSet.h>
#include <gfx/IBlendState.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IRect.h>
#include <gfx/Ndc.h>
#include <internal/ToVector.h>


namespace synkro
{


namespace over
{


// Quad implementation.
class Quad :
	public core::ObjectImpl<IQuad>
{
public:
	// Constructor.
	Quad( gfx::IOverlayRenderQueue* queue, gfx::IGraphicsSystemEx* graphicsSystem, gfx::IBlendStateSet* blendStates, const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color, gfx::Ndc* ndc );

	// IQuad methods.
	void													Show( Bool show );
	void													EnableRect( Bool enable );
	void													SetRect( const lang::Rect& rect );
	void													SetLocation( const lang::Point& location );
	void													SetSize( const lang::Size& size );
	void													SetColor( const img::Color& color );
	void													SetOpacity( Float opacity );
	void													SetGroupOrder( const Order& order );
	void													SetOrder( const Order& order );
	Bool													IsVisible() const;
	Bool													IsRectEnabled() const;
	void													GetRect( lang::Rect& rect ) const;
	void													GetLocation( lang::Point& location ) const;
	void													GetSize( lang::Size& size ) const;
	void													GetColor( img::Color& color ) const;
	Float													GetOpacity() const;
	Order													GetGroupOrder() const;
	Order													GetOrder() const;

	// Other methods.
	void													Update( Bool validateOffset );

private:
	gfx::IGraphicsSystemEx*									_graphicsSystem;
	P(gfx::IOverlayRenderObject)							_quad;
	P(gfx::IBlendStateSet)									_blendStates;
	P(gfx::IParameterSet)									_vertexParams;
	P(gfx::IParameterSet)									_fragmentParams;
	gfx::ProgramParam*										_paramOffset;
	gfx::ProgramParam*										_paramColor;
	P(gfx::IRect)											_scissor;
	lang::Rect												_rect;
	Bool													_rectEnabled;
	lang::Point												_location;
	lang::Size												_size;
	img::Color												_color;
	Float													_opacity;
	Order													_groupOrder;
	Order													_order;
	gfx::Ndc*												_ndc;
};


#include "Quad.inl"


} // over


} // synkro


#endif // _SYNKRO_OVER_QUAD_
