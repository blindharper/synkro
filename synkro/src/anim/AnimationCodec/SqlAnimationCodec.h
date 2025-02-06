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
// Purpose: Implements Sql animation codec.
//==============================================================================
#ifndef _SYNKRO_ANIM_SQLANIMATIONCODEC_
#define _SYNKRO_ANIM_SQLANIMATIONCODEC_


#include "config.h"
#include "AnimationCodecImpl.h"
#include <anim/IAnimationCodec.h>
#include <lang/Variant.h>
#include <lang/Vector.h>


namespace synkro
{


namespace anim
{


// Synkro animation codec implementation.
class SqlAnimationCodec :
	public AnimationCodecImpl<IAnimationCodec>
{
public:
	// Constructor.
	SqlAnimationCodec( core::IContext* context );

	// IAnimationCodec methods.
	IAnimationSet*											Load( io::IStream* stream );
	void													Save( const IAnimationSet* animation, io::IStream* stream );

private:
	struct TrackDesc
	{
		TrackDesc( Int id, Int animationIndex, const lang::String& name, const AnimationDataType& type ) :
			ID( id ),
			AnimationIndex( animationIndex ),
			Name( name ),
			DataType( type )
		{
		}

		TrackDesc()
		{
		}

		Int					ID;
		Int					AnimationIndex;
		lang::String		Name;
		AnimationDataType	DataType;
	};

	lang::Vector<TrackDesc>									_trackDescs;

	db::IDataTable*											GetTable( db::IDatabase* database, const lang::String& name );

	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedBoolTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedColorGradientTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedColorTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedFloatRectTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedFloatTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedIntTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedMatrix4x4Track* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedPointTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedQuaternionTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedRectTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedSizeTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedRangeTrack* track );
	void													ReadTrack( Int trackID, db::ISelectQuery* select, IKeyframedVector3Track* track );
	db::IDataCursor*										GetKeyCursor( Int trackID, db::ISelectQuery* select );

	void													WriteTrack( db::IInsertQuery* insert, IKeyframedBoolTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedColorGradientTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedColorTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedFloatRectTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedFloatTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedIntTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedMatrix4x4Track* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedPointTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedQuaternionTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedRectTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedSizeTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedRangeTrack* track );
	void													WriteTrack( db::IInsertQuery* insert, IKeyframedVector3Track* track );
	void													WriteKey( db::IInsertQuery* insert, UInt trackID, Double time, const lang::Variant& value );
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_SQLANIMATIONCODEC_
