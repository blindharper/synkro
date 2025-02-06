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
// Purpose: Generic program implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMIMPL_
#define _SYNKRO_GFX_PROGRAMIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <io/IStream.h>
#include <gfx/IDataFormat.h>
#include <gfx/IProgramStage.h>
#include <gfx/IProgram.h>


namespace synkro
{


namespace gfx
{


// Program implementation.
template <class T>
class ProgramImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ProgramImpl( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat );
	virtual ~ProgramImpl();

	// IProgram methods.
	virtual IDataFormat*									GetInputFormat() const;
	virtual IDataFormat*									GetOutputFormat() const;
	virtual IProgramStage*									GetVertexStage() const;
	virtual IProgramStage*									GetHullStage() const;
	virtual IProgramStage*									GetDomainStage() const;
	virtual IProgramStage*									GetGeometryStage() const;
	virtual IProgramStage*									GetFragmentStage() const;
	virtual IProgram*										GetParent() const;

protected:
	IProgram*												_parent;
	IDataFormat*											_inputFormat;
	IDataFormat*											_outputFormat;
	P(IProgramStage)										_vertexStage;
	P(IProgramStage)										_hullStage;
	P(IProgramStage)										_domainStage;
	P(IProgramStage)										_geometryStage;
	P(IProgramStage)										_fragmentStage;

	static Bool												IsAscii( const Byte* data, UInt size );
};


#include "ProgramImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMIMPL_
