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
// Purpose: Generic light implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_LIGHTIMPL_
#define _SYNKRO_SCENE_LIGHTIMPL_


#include "config.h"
#include "NodeImpl.h"
#include <img/Color.h>


namespace synkro
{


namespace scene
{


// Generic light implementation.
template <class T>
class LightImpl :
	public NodeImpl<T>
{
public:
	// Constructor & destructor.
	LightImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize = false );
	virtual ~LightImpl();

	// INode methods.
	ILight*													AsLight() const;

	// ILight methods.
	virtual void											Enable( Bool enable );
	virtual void											SetDiffuseColor( const img::Color& color );
	virtual void											SetAmbientColor( const img::Color& color );
	virtual void											SetSpecularColor( const img::Color& color );
	virtual void											SetIntensity( Float intensity );
	virtual Bool											IsEnabled() const;
	virtual void											GetDiffuseColor( img::Color& color ) const;
	virtual void											GetAmbientColor( img::Color& color ) const;
	virtual void											GetSpecularColor( img::Color& color ) const;
	virtual Float											GetIntensity() const;
	virtual IConeLight*										AsCone() const;
	virtual IDirectLight*									AsDirect() const;
	virtual IOmniLight*										AsOmni() const;

protected:
	Bool													_enabled;
	img::Color												_diffuseColor;
	img::Color												_ambientColor;
	img::Color												_specularColor;
	Float													_intensity;
};


#include "LightImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LIGHTIMPL_
