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
#include "config.h"
#include "SqlAnimationCodec.h"
#include <db/IDatabaseSystemEx.h>
#include <db/IDatabase.h>
#include <db/IDataTable.h>
#include <db/IInsertQuery.h>
#include <db/ISelectQuery.h>
#include <db/IDataCursor.h>
#include <db/DataFilter.h>
#include <io/BinaryReader.h>
#include <anim/AnimationDataTypeConst.h>
#include <internal/SizeOf.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::db;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


SqlAnimationCodec::SqlAnimationCodec( IContext* context ) :
	AnimationCodecImpl<IAnimationCodec>( context ),
	_trackDescs( A(TrackDesc) )
{
}

IAnimationSet* SqlAnimationCodec::Load( IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Load( stream );

	// Open database.
	stream->Close();
	P(IDatabase) database = _context->GetDatabaseSystem()->CreateDatabase( stream );
	P(IDataTable) tableInfo = GetTable( database, L"info" );

	// Get animation set name.
	IAnimationSet* set = nullptr;
	P(IDataFilter) selectFilter = _context->GetDatabaseSystem()->CreateFilter( L"id", ComparisonType::Equal, 2 );
	P(ISelectQuery) selectInfo = tableInfo->CreateSelectQuery();
	selectInfo->SelectAll();
	selectInfo->SetFilter( selectFilter );
	selectInfo->Execute();
	P(IDataCursor) cursorInfo = selectInfo->GetCursor();
	if ( cursorInfo->Read() )
	{
		Variant value = cursorInfo->GetValue( L"value" );
		String name = (String)value;
		set = _context->GetAnimationSystem()->CreateAnimationSet( name );
	}

	// Get animations.
	P(IDataTable) tableAnimation = GetTable( database, L"animation" );
	P(ISelectQuery) selectAnimation = tableAnimation->CreateSelectQuery();
	selectAnimation->SelectAll();
	selectAnimation->Sort( L"id", SortOrder::Asc );
	selectAnimation->Execute();
	P(IDataCursor) cursorAnimation = selectAnimation->GetCursor();
	while ( cursorAnimation->Read() )
	{
		Variant value = cursorAnimation->GetValue( L"name" );
		String name = (String)value;
		set->CreateAnimation( name );
	}

	// Get tracks.
	P(IDataTable) tableTrack = GetTable( database, L"track" );
	P(IDataTable) tableKey = GetTable( database, L"track_key" );
	P(ISelectQuery) selectTrack = tableTrack->CreateSelectQuery();
	selectTrack->SelectAll();
	selectTrack->Execute();
	P(IDataCursor) cursorTrack = selectTrack->GetCursor();
	while ( cursorTrack->Read() )
	{
		Variant id = cursorTrack->GetValue( L"id" );
		Variant animationIdx = cursorTrack->GetValue( L"animation_id" );
		Variant name = cursorTrack->GetValue( L"name" );
		Variant type = cursorTrack->GetValue( L"type" );
		_trackDescs.Add( TrackDesc((Int)id, (Int)animationIdx, (String)name, AnimationDataType((String)type)) );
	}

	for ( UInt i = 0; i < _trackDescs.Size(); ++i )
	{
		const TrackDesc& desc = _trackDescs[i];
		IAnimation* anim = set->GetAnimation( desc.AnimationIndex );
		P(ISelectQuery) selectKey = tableKey->CreateSelectQuery();
		switch ( desc.DataType )
		{
			case TYPE_BOOL:
				ReadTrack( desc.ID, selectKey, anim->CreateBoolTrack(desc.Name) );
				break;

			case TYPE_COLOR:
				ReadTrack( desc.ID, selectKey, anim->CreateColorTrack(desc.Name) );
				break;

			case TYPE_COLOR_GRADIENT:
				ReadTrack( desc.ID, selectKey, anim->CreateColorGradientTrack(desc.Name) );
				break;

			case TYPE_FLOAT:
				ReadTrack( desc.ID, selectKey, anim->CreateFloatTrack(desc.Name) );
				break;

			case TYPE_FLOAT_RECT:
				ReadTrack( desc.ID, selectKey, anim->CreateFloatRectTrack(desc.Name) );
				break;

			case TYPE_INT:
				ReadTrack( desc.ID, selectKey, anim->CreateIntTrack(desc.Name) );
				break;

			case TYPE_MATRIX4X4:
				ReadTrack( desc.ID, selectKey, anim->CreateMatrix4x4Track(desc.Name) );
				break;

			case TYPE_POINT:
				ReadTrack( desc.ID, selectKey, anim->CreatePointTrack(desc.Name) );
				break;

			case TYPE_QUATERNION:
				ReadTrack( desc.ID, selectKey, anim->CreateQuaternionTrack(desc.Name) );
				break;

			case TYPE_RANGE:
				ReadTrack( desc.ID, selectKey, anim->CreateRangeTrack(desc.Name) );
				break;

			case TYPE_RECT:
				ReadTrack( desc.ID, selectKey, anim->CreateRectTrack(desc.Name) );
				break;

			case TYPE_SIZE:
				ReadTrack( desc.ID, selectKey, anim->CreateSizeTrack(desc.Name) );
				break;

			case TYPE_VECTOR3:
				ReadTrack( desc.ID, selectKey, anim->CreateVector3Track(desc.Name) );
				break;
		}
	}

	return set;
}

void SqlAnimationCodec::Save( const IAnimationSet* animation, IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Save( animation, stream );

	stream->Close();
	P(IDatabase) database = _context->GetDatabaseSystem()->CreateDatabase( stream );

	// Create tables.
	TableColumn columnsInfo[] =
	{
		{L"id", DataType::Integer, true, false, true},
		{L"value", DataType::String, false, false, false},
	};
	IDataTable* tableInfo = database->CreateTable( L"info", columnsInfo, SizeOf(columnsInfo) );

	TableColumn columnsAnimation[] =
	{
		{L"id", DataType::Integer, true, false, true},
		{L"name", DataType::String, false, false, false},
	};
	IDataTable* tableAnimation = database->CreateTable( L"animation", columnsAnimation, SizeOf(columnsAnimation) );

	TableColumn columnsTrack[] =
	{
		{L"id", DataType::Integer, true, false, true},
		{L"animation_id", DataType::Integer, false, false, false},
		{L"name", DataType::String, false, false, false},
		{L"type", DataType::String, false, false, false},
	};
	IDataTable* tableTrack = database->CreateTable( L"track", columnsTrack, SizeOf(columnsTrack) );

	TableColumn columnsKey[] =
	{
		{L"track_id", DataType::Integer, false, false, false},
		{L"time", DataType::Float, false, false, false},
		{L"value", DataType::Blob, false, false, false},
	};
	IDataTable* tableKey = database->CreateTable( L"track_key", columnsKey, SizeOf(columnsKey) );
	String colName( columnsKey[0].Name );
	tableKey->CreateIndex( L"idx_track_key", false, &colName, 1 );

	// Fill in info.
	P(IInsertQuery) insertInfo = tableInfo->CreateInsertQuery();
	
	insertInfo->SetValue( L"id", 1L );
	insertInfo->SetValue( L"value", L"1.0" );
	insertInfo->Execute();

	insertInfo->SetValue( L"id", 2L );
	insertInfo->SetValue( L"value", animation->GetName().IsEmpty() ? L"Default" : animation->GetName() );
	insertInfo->Execute();

	// Dump animations.
	P(IInsertQuery) insertAnimation = tableAnimation->CreateInsertQuery();
	P(IInsertQuery) insertTrack = tableTrack->CreateInsertQuery();
	P(IInsertQuery) insertKey = tableKey->CreateInsertQuery();
	for ( UInt i = 0; i < animation->GetAnimationCount(); ++i )
	{
		IAnimation* anim = animation->GetAnimation( i );
		insertAnimation->SetValue( L"id", CastInt(i) );
		insertAnimation->SetValue( L"name", anim->GetName() );
		insertAnimation->Execute();

		for ( UInt j = 0; j < anim->GetTrackCount(); ++j )
		{
			const IAnimationTrack* track = anim->GetTrack( j );
			const AnimationDataType type = track->GetType();
			insertTrack->SetValue( L"id", CastInt(track->ID()) );
			insertTrack->SetValue( L"animation_id", CastInt(i) );
			insertTrack->SetValue( L"name", track->GetName() );
			insertTrack->SetValue( L"type", type.ToString() );
			insertTrack->Execute();

			// Dump track.
			switch ( type )
			{
				case TYPE_BOOL:
					WriteTrack( insertKey, track->AsBool()->AsKeyframed() );
					break;

				case TYPE_COLOR:
					WriteTrack( insertKey, track->AsColor()->AsKeyframed() );
					break;

				case TYPE_COLOR_GRADIENT:
					WriteTrack( insertKey, track->AsColorGradient()->AsKeyframed() );
					break;

				case TYPE_FLOAT:
					WriteTrack( insertKey, track->AsFloat()->AsKeyframed() );
					break;

				case TYPE_FLOAT_RECT:
					WriteTrack( insertKey, track->AsFloatRect()->AsKeyframed() );
					break;

				case TYPE_INT:
					WriteTrack( insertKey, track->AsInt()->AsKeyframed() );
					break;

				case TYPE_MATRIX4X4:
					WriteTrack( insertKey, track->AsMatrix4x4()->AsKeyframed() );
					break;

				case TYPE_POINT:
					WriteTrack( insertKey, track->AsPoint()->AsKeyframed() );
					break;

				case TYPE_QUATERNION:
					WriteTrack( insertKey, track->AsQuaternion()->AsKeyframed() );
					break;

				case TYPE_RANGE:
					WriteTrack( insertKey, track->AsRange()->AsKeyframed() );
					break;

				case TYPE_RECT:
					WriteTrack( insertKey, track->AsRect()->AsKeyframed() );
					break;

				case TYPE_SIZE:
					WriteTrack( insertKey, track->AsSize()->AsKeyframed() );
					break;

				case TYPE_VECTOR3:
					WriteTrack( insertKey, track->AsVector3()->AsKeyframed() );
					break;
			}
		}
	}
}

IDataTable* SqlAnimationCodec::GetTable( IDatabase* database, const String& name )
{
	IDataTable* table = database->GetTable( name );
	if ( table == nullptr )
		throw Exception( String::Format(L"Bad animation file. {0,q} table is missing.", name) );
	return table;
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedBoolTrack* track )
{
	Bool v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedColorGradientTrack* track )
{
	ColorGradient v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedColorTrack* track )
{
	Color v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedFloatRectTrack* track )
{
	RectF v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedFloatTrack* track )
{
	Float v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedIntTrack* track )
{
	Int v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedMatrix4x4Track* track )
{
	Matrix4x4 v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedPointTrack* track )
{
	Point v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedQuaternionTrack* track )
{
	Quaternion v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedRectTrack* track )
{
	Rect v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedSizeTrack* track )
{
	Size v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedRangeTrack* track )
{
	Range v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

void SqlAnimationCodec::ReadTrack( Int trackID, ISelectQuery* select, IKeyframedVector3Track* track )
{
	Vector3 v;
	P(IDataCursor) cursorKey = GetKeyCursor( trackID, select );
	while ( cursorKey->Read() )
	{
		Variant varTime = cursorKey->GetValue( L"time" );
		Variant varValue = cursorKey->GetValue( L"value" );

		const Double time = CastDouble( (Float)varTime );
		IStream* value = (IStream*)varValue;
		BinaryReader rd( value );
		rd.ReadBytes( &v, sizeof(v) );
		track->SetKey( time, v );
	}
}

IDataCursor* SqlAnimationCodec::GetKeyCursor( Int trackID, ISelectQuery* select )
{
	P(IDataFilter) filter = _context->GetDatabaseSystem()->CreateFilter( L"track_id", ComparisonType::Equal, trackID );
	select->SelectAll();
	select->SetFilter( filter );
	select->Execute();
	return select->GetCursor();
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedBoolTrack* track )
{
	Bool v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedColorGradientTrack* track )
{
	ColorGradient v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedColorTrack* track )
{
	Color v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedFloatRectTrack* track )
{
	RectF v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedFloatTrack* track )
{
	Float v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedIntTrack* track )
{
	Int v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedMatrix4x4Track* track )
{
	Matrix4x4 v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedPointTrack* track )
{
	Point v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedQuaternionTrack* track )
{
	Quaternion v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedRectTrack* track )
{
	Rect v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedSizeTrack* track )
{
	Size v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedRangeTrack* track )
{
	Range v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteTrack( IInsertQuery* insert, IKeyframedVector3Track* track )
{
	Vector3 v;
	for ( UInt k = 0; k < track->GetKeyCount(); ++k )
	{
		const Double time = track->GetKeyTime( k );
		track->GetKeyValue( k, v );
		WriteKey( insert, track->ID(), time, Variant((const Byte*)&v, sizeof(v)) );
	}
}

void SqlAnimationCodec::WriteKey( IInsertQuery* insert, UInt trackID, Double time, const Variant& value )
{
	insert->SetValue( L"track_id", CastInt(trackID) );
	insert->SetValue( L"time", CastFloat(time) );
	insert->SetValue( L"value", value );
	insert->Execute();
}


} // anim


} // synkro
