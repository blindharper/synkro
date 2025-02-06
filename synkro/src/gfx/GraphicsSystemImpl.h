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
// Purpose: Generic graphics system implementation.
//=============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSSYSTEMIMPL_
#define _SYNKRO_GFX_GRAPHICSSYSTEMIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <gfx/GraphicsException.h>
#include <gfx/GraphicsDeviceDesc.h>


namespace synkro
{


namespace gfx
{


// Generic graphics system implementation.
template <class T>
class GraphicsSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor and destructor.
	GraphicsSystemImpl( const lang::String& name, win::IWindowSystemEx* windowSystem, diag::ILog* log );
	virtual ~GraphicsSystemImpl();

	// ISystem methods.
	virtual Bool											Update( Double delta );

	// IGraphicsSystem methods.
	virtual UInt											GetTotalDeviceCount() const;
	virtual void											GetDeviceDesc( UInt index, GraphicsDeviceDesc& desc ) const;
	virtual lang::String									GetName() const;

protected:
	lang::String											_name;
	lang::Vector<GraphicsDeviceDesc>						_devices;
	win::IWindowSystemEx*									_windowSystem;
};


#include "GraphicsSystemImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSSYSTEMIMPL_
