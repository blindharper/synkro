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
// Purpose: User interface cursor implementation.
//==============================================================================
#include "config.h"
#include "Cursor.h"
#include <gfx/IPrimitiveEx.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IParameterSet.h>
#include <over/Order.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Cursor::Cursor( BaseUiEx* ui ) :
	_ui( ui ),
	_type( CursorType::Pointer )
{
	_object = _ui->CreateObject( PrimitiveType::TriangleStrip, IndexType::None, 4, 0, Order::GetValue(Order::Highest, Order::High) );
	_paramColor = _object->GetFragmentParameters()->GetParam( L"p_color" );
	SetTheme( _ui->GetThemeEx() );
}

void Cursor::SetLocation( const Point& location )
{
	if ( location != _location )
	{
		P(IVector4Stream) stream = (IVector4Stream*)_object->GetData()->GetVertexStream( DataStream::Position2D, 0 );
		if ( (stream != nullptr) && stream->Open(OpenMode::Write) )
		{
			const Float left = CastFloat(location.X);
			const Float top = CastFloat(location.Y);
			Vector4 pos[] =
			{
				Vector4( left,			top,			0.0f, 1.0f ),
				Vector4( left,			top+_height,	0.0f, 1.0f ),
				Vector4( left+_width,	top,			0.0f, 1.0f ),
				Vector4( left+_width,	top+_height,	0.0f, 1.0f ),
			};
			stream->Write( pos, 4 );
			stream->Close();
		}
		_location = location;
	}
}

void Cursor::SetTheme( ITheme* theme )
{
	Color color;
	_object->SetFragmentResources( theme->GetResources() );
	UpdateTextureCoordinates();
	theme->GetWidgetColor( WidgetState::Normal, color );
	SetColor( color );
}

void Cursor::UpdateTextureCoordinates()
{
	Rect rc;
	_ui->GetThemeEx()->GetCursorRect( rc );
	_width = CastFloat(rc.Width());
	_height = CastFloat(rc.Height());

	P(IVector2Stream) stream = (IVector2Stream*)_object->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
	if ( stream->Open(OpenMode::Write) )
	{
		RectF rect;
		_ui->GetThemeEx()->ToRectF( rc, rect );
		Vector2 coords[] = 
		{
			Vector2( rect.Left, rect.Top ),
			Vector2( rect.Left, rect.Bottom ),
			Vector2( rect.Right, rect.Top ),
			Vector2( rect.Right, rect.Bottom ),
		};
		stream->Write( coords, 4 );
		stream->Close();
	}
}


} // ui


} // synkro
