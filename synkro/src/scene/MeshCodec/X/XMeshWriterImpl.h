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
// Purpose: Generic DirectX mesh writer implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHWRITERIMPL_
#define _SYNKRO_SCENE_XMESHWRITERIMPL_


#include "config.h"
#include "XMeshWriter.h"


namespace synkro
{


namespace scene
{


// Generic DirectX mesh writer.
template <class T>
class XMeshWriterImpl :
	public T
{
public:
	// Constructors & destructor.
	XMeshWriterImpl();
	virtual ~XMeshWriterImpl();

	// XMeshWriter methods.
	virtual void											WriteName( const lang::String& name );

protected:
	io::IStream*											_stream;
	lang::Map<Byte, lang::String>							_templates;
	lang::Vector<Byte>										_buffer;

	void													RegisterTemplates();
	void													RegisterTemplate( Byte type, const lang::String& name );
};


#include "XMeshWriterImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHWRITERIMPL_
