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
// Purpose: Generic factory implementation.
//==============================================================================
#ifndef _SYNKRO_CORE_FACTORYIMPL_
#define _SYNKRO_CORE_FACTORYIMPL_


#include "config.h"
#include <core/Iface.h>
#include <mem/OperatorNew.h>
#ifdef SYNKRO_STATIC
#include "BaseFactory.h"
#endif // SYNKRO_STATIC


// Begins factory definition.
#define SYNKRO_FACTORY_BEGIN( FACTORY, BASE, IFACE_ID, CLASS_ID )										\
	class FACTORY : public synkro::core::FactoryImpl<BASE>												\
	{ public: FACTORY() : synkro::core::FactoryImpl<BASE>( synkro::core::Iface::IFACE_ID, CLASS_ID ) {}	\
			void Init() { _ifaceID = synkro::core::Iface::IFACE_ID; _classID = CLASS_ID; }

// Ends factory definition.
#define SYNKRO_FACTORY_END() \
	};


namespace synkro
{


namespace core
{


// Generic factory implementation.
template <class T>
class FactoryImpl :
	public T
#ifdef SYNKRO_STATIC
	, public BaseFactory
#endif // SYNKRO_STATIC
{
public:
	// Constructors & destructors.
	FactoryImpl( const Iface& ifaceID, const lang::Enum& classID );
	virtual ~FactoryImpl();

	// IFactory methods.
	Iface													GetIfaceID() const;
	lang::Enum												GetClassID() const;

protected:
	Iface													_ifaceID;
	lang::Enum												_classID;
};


#include "FactoryImpl.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_FACTORYIMPL_
