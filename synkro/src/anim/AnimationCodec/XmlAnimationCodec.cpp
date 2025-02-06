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
// Purpose: Implements Xml animation codec.
//==============================================================================
#include "config.h"
#include "XmlAnimationCodec.h"
#include <anim/AnimationDataTypeConst.h>
#include <lang/Parser.h>


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


XmlAnimationCodec::XmlAnimationCodec( IContext* context ) :
	AnimationCodecImpl<IAnimationCodec>( context )
{
}

IAnimationSet* XmlAnimationCodec::Load( IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Load( stream );

	XmlReader rd( stream, true );

	// Read <animationset> tag.
	if ( !rd.Read() || !rd.GetName().EqualsTo(L"animationset", true) )
		throw Exception( L"Bad animation. Missing <animationset> tag." );

	IAnimationSet* set = _context->GetAnimationSystem()->CreateAnimationSet(rd.GetAttributeValue(L"name"));

	// Read animations.
	while ( rd.Read() && rd.GetName().EqualsTo(L"animation", true) && rd.IsStart() )
	{
		IAnimation* animation = set->CreateAnimation( rd.GetAttributeValue(L"name") );

		while ( rd.Read() && !(rd.GetName().EqualsTo(L"animation", true) && rd.IsEnd()) )
		{
			// Read tracks.
			if ( rd.GetName().EqualsTo(L"track", true) )
			{
				AnimationDataType type = AnimationDataType( rd.GetAttributeValue(L"type") );
				String name = rd.GetAttributeValue( L"name" );
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
		}
	}

	return set;
}

void XmlAnimationCodec::Save( const IAnimationSet* animation, IStream* stream )
{
	// Call base implementation.
	AnimationCodecImpl<IAnimationCodec>::Save( animation, stream );

	// Save data.
	XmlWriter wr( stream );

	wr.WriteStartElement( L"animationset" );
	wr.WriteAttribute( L"name", animation->GetName() );

	for ( UInt i = 0; i < animation->GetAnimationCount(); ++i )
	{
		IAnimation* anim = animation->GetAnimation( i );

		wr.WriteStartElement( L"animation" );
		wr.WriteAttribute( L"name", anim->GetName() );

		for ( UInt j = 0; j < anim->GetTrackCount(); ++j )
		{
			const IAnimationTrack* track = anim->GetTrack( j );
			const AnimationDataType type = track->GetType();

			wr.WriteStartElement( L"track" );
			wr.WriteAttribute( L"type", type.ToString() );
			wr.WriteAttribute( L"name", track->GetName() );
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
			wr.WriteEndElement(); // track
		}
		wr.WriteEndElement(); // animation
	}
	wr.WriteEndElement(); // animationset
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedBoolTrack* track )
{
	Double d;
	Parser p( L"{0}" );
	p.Map( d );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, (d != 0.0) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedColorGradientTrack* track )
{
	Double d1; Double d2; Double d3; Double d4; Double d5; Double d6;
	Parser p( L"{0}, {1}, {2}, {3}, {4}, {5}" );
	p.Map( d1, d2, d3, d4, d5, d6 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, ColorGradient(GradientType::Horizontal, Color(CastFloat(d1), CastFloat(d2), CastFloat(d3)), Color(CastFloat(d4), CastFloat(d5), CastFloat(d6))) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedColorTrack* track )
{
	Double d1; Double d2; Double d3;
	Parser p( L"{0}, {1}, {2}" );
	p.Map( d1, d2, d3 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Color(CastFloat(d1), CastFloat(d2), CastFloat(d3)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedFloatRectTrack* track )
{
	Double d1; Double d2; Double d3; Double d4;
	Parser p( L"{0}, {1}, {2}, {3}" );
	p.Map( d1, d2, d3, d4 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, RectF(CastFloat(d1), CastFloat(d2), CastFloat(d3), CastFloat(d4)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedFloatTrack* track )
{
	Double d;
	Parser p( L"{0}" );
	p.Map( d );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, CastFloat(d) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedIntTrack* track )
{
	Double d;
	Parser p( L"{0}" );
	p.Map( d );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, CastInt(d) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedMatrix4x4Track* track )
{
	Double d1; Double d2; Double d3; Double d4; Double d5; Double d6; Double d7; Double d8;
	Double d9; Double d10; Double d11; Double d12; Double d13; Double d14; Double d15; Double d16;
	Parser p( L"{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}" );
	p.Map( d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Matrix4x4(d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedPointTrack* track )
{
	Double d1; Double d2;
	Parser p( L"{0}, {1}" );
	p.Map( d1, d2 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Point(CastInt(d1), CastInt(d2)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedQuaternionTrack* track )
{
	Double d1; Double d2; Double d3; Double d4;
	Parser p( L"{0}, {1}, {2}, {3}" );
	p.Map( d1, d2, d3, d4 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Quaternion(CastFloat(d1), CastFloat(d2), CastFloat(d3), CastFloat(d4)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedRectTrack* track )
{
	Double d1; Double d2; Double d3; Double d4;
	Parser p( L"{0}, {1}, {2}, {3}" );
	p.Map( d1, d2, d3, d4 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Rect(CastInt(d1), CastInt(d2), CastInt(d3), CastInt(d4)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedSizeTrack* track )
{
	Double d1; Double d2;
	Parser p( L"{0}, {1}" );
	p.Map( d1, d2 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Size(CastUInt(d1), CastUInt(d2)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedRangeTrack* track )
{
	Double d1; Double d2;
	Parser p( L"{0}, {1}" );
	p.Map( d1, d2 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Range(CastUInt(d1), CastUInt(d2)) );
		}
	}
}

void XmlAnimationCodec::ReadTrack( XmlReader& rd, IKeyframedVector3Track* track )
{
	Double d1; Double d2; Double d3;
	Parser p( L"{0}, {1}, {2}" );
	p.Map( d1, d2, d3 );
	while ( rd.Read() && !(rd.GetName().EqualsTo(L"track", true) && rd.IsEnd()) )
	{
		if ( rd.GetName().EqualsTo(L"key", true) )
		{
			const Double time = Convert::ToDouble( rd.GetAttributeValue(L"time") );
			String value = rd.GetAttributeValue( L"value" );
			p.ParseText( value );
			track->SetKey( time, Vector3(CastFloat(d1), CastFloat(d2), CastFloat(d3)) );
		}
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedBoolTrack* track )
{
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Bool value; track->GetKeyValue( i, value );
		WriteKey( wr, track->GetKeyTime(i), value ? L"1" : L"0" );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedColorGradientTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}, {3,#.######}, {4,#.######}, {5,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		ColorGradient value; track->GetKeyValue( i, value );
		f.Map( value.Start.R, value.Start.G, value.Start.B, value.End.R, value.End.G, value.End.B );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedColorTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Color value; track->GetKeyValue( i, value );
		f.Map( value.R, value.G, value.B );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedFloatRectTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}, {3,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		RectF value; track->GetKeyValue( i, value );
		f.Map( value.Left, value.Top, value.Right, value.Bottom );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedFloatTrack* track )
{
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Float value; track->GetKeyValue( i, value );
		WriteKey( wr, track->GetKeyTime(i), Convert::ToString(value) );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedIntTrack* track )
{
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Int value; track->GetKeyValue( i, value );
		WriteKey( wr, track->GetKeyTime(i), Convert::ToString(value) );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedMatrix4x4Track* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}, {3,#.######}, {4,#.######}, {5,#.######}, {6,#.######}, {7,#.######}, {8,#.######}, {9,#.######}, {10,#.######}, {11,#.######}, {12,#.######}, {13,#.######}, {14,#.######}, {15,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Matrix4x4 v; track->GetKeyValue( i, v );
		f.Map( v._00, v._01, v._02, v._03, v._10, v._11, v._12, v._13, v._20, v._21, v._22, v._23, v._30, v._31, v._32, v._33 );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedPointTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Point value; track->GetKeyValue( i, value );
		f.Map( value.X, value.Y );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedQuaternionTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}, {3,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Quaternion value; track->GetKeyValue( i, value );
		f.Map( value.x, value.y, value.z, value.w );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedRectTrack* track )
{
	Formatter f( L"{0}, {1}, {2}, {3}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Rect value; track->GetKeyValue( i, value );
		f.Map( value.Left, value.Top, value.Right, value.Bottom );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedSizeTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Size value; track->GetKeyValue( i, value );
		f.Map( value.Width, value.Height );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedRangeTrack* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Range value; track->GetKeyValue( i, value );
		f.Map( value.Start, value.Length );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteTrack( XmlWriter& wr, IKeyframedVector3Track* track )
{
	Formatter f( L"{0,#.######}, {1,#.######}, {2,#.######}" );
	for ( UInt i = 0; i < track->GetKeyCount(); ++i )
	{
		Vector3 value; track->GetKeyValue( i, value );
		f.Map( value.x, value.y, value.z );
		WriteKey( wr, track->GetKeyTime(i), f.ToString() );
	}
}

void XmlAnimationCodec::WriteKey( XmlWriter& wr, Double time, const String& value )
{
	wr.WriteStartElement( L"key" );
	wr.WriteAttribute( L"time", String(time) );
	wr.WriteAttribute( L"value", value );
	wr.WriteEndElement(); // key
}


} // anim


} // synkro
