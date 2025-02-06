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
// Purpose: Implements binary animation codec.
//==============================================================================
#include "config.h"
#include "BinAnimationCodec.h"
#include <anim/AnimationDataTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


BinAnimationCodec::BinAnimationCodec( IContext* context ) :
	AnimationCodecImpl<IAnimationCodec>( context )
{
}

IAnimationSet* BinAnimationCodec::Load( IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Load( stream );

	// Validate header.
	stream->Open( OpenMode::Read );
	char hdr[4] = {};
	stream->Read( hdr, 4 );
	stream->Close();
	if ( !Compare( hdr, "XMAN", 4 ) )
		throw Exception( L"Bad animation file." );

	const UInt BUF_SIZE = 260;
	char buf[BUF_SIZE] = {}; UInt bytes = 0; UInt len = 0;
	BinaryReader rd( stream );

	// Read header.
	bytes = rd.ReadBytes( hdr, 4 );

	// Read animation set name.
	len = rd.ReadByte();
	bytes = rd.ReadBytes( buf, len );
	buf[bytes] = 0;
	IAnimationSet* set = _context->GetAnimationSystem()->CreateAnimationSet( buf );

	// Read animations.
	while ( !rd.Eos() )
	{
		// Read animation name.
		len = rd.ReadByte();
		bytes = rd.ReadBytes( buf, len );
		buf[bytes] = 0;
		IAnimation* animation = set->CreateAnimation( buf );

		// Read track type and name.
		AnimationDataType type = (AnimationDataType)rd.ReadUInt();
		len = rd.ReadByte();
		bytes = rd.ReadBytes( buf, len );
		buf[bytes] = 0;
		String name( buf );
		switch ( type )
		{
			case TYPE_BOOL:
				ReadTrack( rd, animation->CreateBoolTrack(name) );
				break;

			case TYPE_COLOR:
				ReadTrack( rd, animation->CreateColorTrack(name) );
				break;

			case TYPE_COLOR_GRADIENT:
				ReadTrack( rd, animation->CreateColorGradientTrack(name) );
				break;

			case TYPE_FLOAT:
				ReadTrack( rd, animation->CreateFloatTrack(name) );
				break;

			case TYPE_FLOAT_RECT:
				ReadTrack( rd, animation->CreateFloatRectTrack(name) );
				break;

			case TYPE_INT:
				ReadTrack( rd, animation->CreateIntTrack(name) );
				break;

			case TYPE_MATRIX4X4:
				ReadTrack( rd, animation->CreateMatrix4x4Track(name) );
				break;

			case TYPE_POINT:
				ReadTrack( rd, animation->CreatePointTrack(name) );
				break;

			case TYPE_QUATERNION:
				ReadTrack( rd, animation->CreateQuaternionTrack(name) );
				break;

			case TYPE_RANGE:
				ReadTrack( rd, animation->CreateRangeTrack(name) );
				break;

			case TYPE_RECT:
				ReadTrack( rd, animation->CreateRectTrack(name) );
				break;

			case TYPE_SIZE:
				ReadTrack( rd, animation->CreateSizeTrack(name) );
				break;

			case TYPE_VECTOR3:
				ReadTrack( rd, animation->CreateVector3Track(name) );
				break;
		}
	}

	return set;
}

void BinAnimationCodec::Save( const IAnimationSet* animation, IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Save( animation, stream );

	// Save data.
	constexpr UInt BUF_SIZE = 260;
	char buf[BUF_SIZE]; UInt bytes = 0; Byte len = 0;
	BinaryWriter wr( stream );

	// Write header.
	char hdr[] = "XMAN";
	wr.Write( hdr, sizeof(hdr) );

	// Write animation set name.
	len = animation->GetName().Length();
	bytes = animation->GetName().GetBytes( buf, BUF_SIZE );
	wr.Write( len );
	wr.Write( buf, bytes );

	for ( UInt i = 0; i < animation->GetAnimationCount(); ++i )
	{
		IAnimation* anim = animation->GetAnimation( i );

		// Write animation name.
		len = animation->GetName().Length();
		bytes = animation->GetName().GetBytes( buf, BUF_SIZE );
		wr.Write( len );
		wr.Write( buf, bytes );

		for ( UInt j = 0; j < anim->GetTrackCount(); ++j )
		{
			const IAnimationTrack* track = anim->GetTrack( j );

			// Write track type.
			const AnimationDataType type = track->GetType();
			wr.Write( type.Value() );

			// Write track name.
			len = track->GetName().Length();
			bytes = track->GetName().GetBytes( buf, BUF_SIZE );
			wr.Write( len );
			wr.Write( buf, bytes );

			// Write keys.
			switch ( type )
			{
				case TYPE_BOOL:
					WriteTrack( wr, track->AsBool()->AsKeyframed() );
					break;

				case TYPE_COLOR:
					WriteTrack( wr, track->AsColor()->AsKeyframed() );
					break;

				case TYPE_COLOR_GRADIENT:
					WriteTrack( wr, track->AsColorGradient()->AsKeyframed() );
					break;

				case TYPE_FLOAT:
					WriteTrack( wr, track->AsFloat()->AsKeyframed() );
					break;

				case TYPE_FLOAT_RECT:
					WriteTrack( wr, track->AsFloatRect()->AsKeyframed() );
					break;

				case TYPE_INT:
					WriteTrack( wr, track->AsInt()->AsKeyframed() );
					break;

				case TYPE_MATRIX4X4:
					WriteTrack( wr, track->AsMatrix4x4()->AsKeyframed() );
					break;

				case TYPE_POINT:
					WriteTrack( wr, track->AsPoint()->AsKeyframed() );
					break;

				case TYPE_QUATERNION:
					WriteTrack( wr, track->AsQuaternion()->AsKeyframed() );
					break;

				case TYPE_RANGE:
					WriteTrack( wr, track->AsRange()->AsKeyframed() );
					break;

				case TYPE_RECT:
					WriteTrack( wr, track->AsRect()->AsKeyframed() );
					break;

				case TYPE_SIZE:
					WriteTrack( wr, track->AsSize()->AsKeyframed() );
					break;

				case TYPE_VECTOR3:
					WriteTrack( wr, track->AsVector3()->AsKeyframed() );
					break;
			}
		}
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedBoolTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Bool value = rd.ReadBoolean();
		track->SetKey( time, value );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedColorGradientTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float r1 = rd.ReadFloat();
		const Float g1 = rd.ReadFloat();
		const Float b1 = rd.ReadFloat();
		const Float r2 = rd.ReadFloat();
		const Float g2 = rd.ReadFloat();
		const Float b2 = rd.ReadFloat();
		track->SetKey( time, ColorGradient(GradientType::Horizontal, Color(r1, g1, b1), Color(r2, g2, b2)) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedColorTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float r = rd.ReadFloat();
		const Float g = rd.ReadFloat();
		const Float b = rd.ReadFloat();
		track->SetKey( time, Color(r, g, b) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedFloatRectTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float left = rd.ReadFloat();
		const Float top = rd.ReadFloat();
		const Float right = rd.ReadFloat();
		const Float bottom = rd.ReadFloat();
		track->SetKey( time, RectF(left, top, right, bottom) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedFloatTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float value = rd.ReadFloat();
		track->SetKey( time, value );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedIntTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Int value = rd.ReadInt();
		track->SetKey( time, value );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedMatrix4x4Track* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		Float d[16];
		rd.ReadBytes( d, sizeof(d) );
		track->SetKey( time, Matrix4x4(d) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedPointTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Int x = rd.ReadInt();
		const Int y = rd.ReadInt();
		track->SetKey( time, Point(x, y) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedQuaternionTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float x = rd.ReadFloat();
		const Float y = rd.ReadFloat();
		const Float z = rd.ReadFloat();
		const Float w = rd.ReadFloat();
		track->SetKey( time, Quaternion(x, y, z, w) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedRectTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Int left = rd.ReadInt();
		const Int top = rd.ReadInt();
		const Int right = rd.ReadInt();
		const Int bottom = rd.ReadInt();
		track->SetKey( time, Rect(left, top, right, bottom) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedSizeTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const UInt width = rd.ReadUInt();
		const UInt height = rd.ReadUInt();
		track->SetKey( time, Size(width, height) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedRangeTrack* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const UInt width = rd.ReadUInt();
		const UInt height = rd.ReadUInt();
		track->SetKey( time, Range(width, height) );
	}
}

void BinAnimationCodec::ReadTrack( BinaryReader& rd, IKeyframedVector3Track* track )
{
	const UInt count = rd.ReadUInt();
	for ( UInt i = 0; i < count; ++i )
	{
		const Double time = 0.001*CastDouble(rd.ReadUInt());
		const Float x = rd.ReadFloat();
		const Float y = rd.ReadFloat();
		const Float z = rd.ReadFloat();
		track->SetKey( time, Vector3(x, y, z) );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedBoolTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Bool value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedColorGradientTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		ColorGradient value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.Start.R );
		wr.Write( value.Start.G );
		wr.Write( value.Start.B );
		wr.Write( value.End.R );
		wr.Write( value.End.G );
		wr.Write( value.End.B );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedColorTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Color value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.R );
		wr.Write( value.G );
		wr.Write( value.B );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedFloatRectTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		RectF value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.Left );
		wr.Write( value.Top );
		wr.Write( value.Right );
		wr.Write( value.Bottom );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedFloatTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Float value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedIntTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Int value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedMatrix4x4Track* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Matrix4x4 value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.d, sizeof(value.d) );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedPointTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Point value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.X );
		wr.Write( value.Y );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedQuaternionTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Quaternion value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.x );
		wr.Write( value.y );
		wr.Write( value.z );
		wr.Write( value.w );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedRectTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Rect value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.Left );
		wr.Write( value.Top );
		wr.Write( value.Right );
		wr.Write( value.Bottom );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedSizeTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Size value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.Width );
		wr.Write( value.Height );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedRangeTrack* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Range value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.Start );
		wr.Write( value.Length );
	}
}

void BinAnimationCodec::WriteTrack( BinaryWriter& wr, IKeyframedVector3Track* track )
{
	wr.Write( track->GetKeyCount() );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		const UInt time = CastUInt(1000.0 * track->GetKeyTime( i ));
		Vector3 value; track->GetKeyValue( i, value );
		wr.Write( time );
		wr.Write( value.x );
		wr.Write( value.y );
		wr.Write( value.z );
	}
}


} // anim


} // synkro
