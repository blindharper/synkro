//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:info@synkro.org
//
// Purpose: 'Image Viewer' tool.
//==============================================================================
#include "../Tool.h"


extern unsigned __int8 res_ImageViewer_resources[];
extern unsigned __int32 res_ImageViewer_resources_size;


class ImageViewer :
	public Tool,
	public ProgressListener
{
public:
	// Initialization.
	ImageViewer() :
		Tool( L"Image Viewer" ),
		_stopping( false )
	{
	}

	// Configuration.
	void Configure( IConfiguration* config ) override
	{
		config->Set( Param::AudioEnable, true );
		config->Set( Param::AudioFormat, CastUInt(5) );
		config->Set( Param::AudioSystem, AudioSystem::DirectSound8 );
		config->Set( Param::CoreThreadPoolCapacity, CastUInt(8) );
		config->Set( Param::GraphicsDisplayMode, CastUInt(DisplayMode::AboveMedium.Index()) );
		config->Set( Param::GraphicsFullscreen, false );
		config->Set( Param::GraphicsProgramCache, String(L"..\\..\\programs") );
		config->Set( Param::UiColorWidgetNormal, Color::ForestGreen );
		config->Set( Param::UiColorTextNormal, Color::White );
		config->Set( Param::UiColorTextActive, Color::LightGreen );
		config->Set( Param::UiColorTextHovered, Color::Yellow );
		config->Set( Param::LogFileName, String(L"ImageViewer.log") );
		config->Set( Param::LogFileAppend, false );
		config->Set( Param::LogLevel, LogLevel::Extensive );
		config->Set( Param::LogMode, LogMode::All );
		config->Set( Param::StreamPath, String(L"..\\..\\..\\synkro.textures\\bricks") );
	}

	// Setup scene.
	void Init() override
	{
		String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
		_displayModeWindowed = DisplayMode( mode, false );
		DisplayMode::GetMode( 0, _displayModeFullscreen );
		_displayModeFullscreen.Fullscreen = true;

		_synkro->GetInputSystem()->GetKeyboard( 0 )->ListenKeyDown( this, Key::Return, true );
	}

	// Setup GUI.
	void InitUi( IUiEx* ui ) override
	{
		core::IResource* res = _synkro->CreateResource( res_ImageViewer_resources, res_ImageViewer_resources_size );
		P(IStreamDirectory) dir = res->Load();
		P(IStream) streamUI = dir->GetStream( L"ImageViewer.ui" );
		_synkro->GetUi()->Load( streamUI );
		P(IStream) streamWav = dir->GetStream( L"pop.wav" );
		_feedbackSound = CreateSound( streamWav );
		delete res;
		_btnFullscreen = _synkro->GetUi()->GetWidget( ID_BUTTON_FULLSCREEN )->AsButton();
		_labelImages = _synkro->GetUi()->GetWidget( ID_LABEL_IMAGES )->AsLabel();
		_listImages = _synkro->GetUi()->GetWidget( ID_LIST_IMAGES )->AsList();
		_btnLoad = _synkro->GetUi()->GetWidget( ID_BUTTON_LOAD )->AsButton();
		_btnLoad->Enable( false );
		_progress = _synkro->GetUi()->GetWidget( ID_PROGRESS )->AsProgress();
		_progress->ShowText( true );
		_progress->Show( false );

		IOverlay* overlay = _synkro->GetOverlayManager()->GetOverlay( _synkro->GetGraphicsSystem()->GetFrameWindow(0) );
		_font = overlay->GetFont(L"ui");
		_feedbackText = _font->CreateText( Color::White, Point(), String::Empty, Order::Highest, Order::Highest );
		_feedbackText->Show( false );
		_feedbackCtrl = _feedbackText->CreateAnimationController( nullptr, nullptr );
		_trackOpacity = _feedbackCtrl->CreateOpacityTrack();

		DisplayImages( L"bricks" );
		_listImages->Activate( true );
	}

	// KeyboardListener methods.
	Bool OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control ) override
	{
		if ( key == Key::Return )
		{
			if ( _listImages->IsActive() )
			{
				OpenImage();
				return true;
			}
		}
		return false;
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Tool::OnUiClick(sender) )
			return true;

		if ( sender == _btnFullscreen )
		{
			ToggleFullscreen();
			return true;
		}
		else if ( sender == _btnLoad )
		{
			OpenImage();
			return true;
		}

		return false;
	}

	Bool OnUiDoubleClick( IWidget* sender ) override
	{
		if ( Tool::OnUiDoubleClick(sender) )
			return true;

		if ( sender == _listImages )
		{
			OpenImage();
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Tool::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listImages )
		{
			_btnLoad->Enable( _listImages->GetSelectedItem() != none );
			return true;
		}

		return false;
	}

	// ProgressListener methods.
	void OnProgressBegin( IObject* context, UInt total ) override
	{
		_progress->SetMaxValue( total );
	}

	void OnProgressUpdate( IObject* context, UInt current ) override
	{
		_progress->SetValue( current );
	}

	void OnProgressEnd( IObject* context ) override
	{
		IImage* image = (IImage*)context;
		CreateSprite( image );
		_progress->Show( false );
		DisplayFeedback( String::Format(L"Image {0,q} loaded", _stream->GetName()) );
	}

	// Other methods.
	void DisplayImages( String dirName )
	{
		_listImages->Clear();
		IStreamDirectory* dir = _synkro->GetStreamSystem()->GetDirectory( dirName );
		for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
		{
			IStream* stream = dir->GetStream( i );
			if ( ImageCodec::IsValid(stream->GetName()) )
			{
				_listImages->AddItem( ListItem(stream->GetName(), (Pointer)stream) );
			}
		}
		_labelImages->SetText( String::Format(L"IMAGES ({0})", _listImages->GetItemCount()) );
	}

	void CreateSprite( IImage* image )
	{
		IFrameRenderWindowEx* window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
		const Size szWin( window->GetWidth(), window->GetHeight() );
		PixelFormat format = window->GetClientPixelFormat();
		IOverlay* overlay = _synkro->GetOverlayManager()->GetOverlay( _viewport->GetView()->GetWindow() );
		const Size szImg( image->GetWidth(), image->GetHeight() );
		const Float aspect = CastFloat(szImg.Width)/CastFloat(szImg.Height);
		Point pt( 200, 10 ); Size sz( 0, 0 );
		if ( szImg.Width >= szImg.Height )
		{
			if ( szImg.Width > szWin.Width )
			{
				sz.Width = szWin.Width;
				sz.Height = CastUInt(CastFloat(sz.Width)/aspect);
			}
			else
			{
				sz.Width = szImg.Width;
				sz.Height = szImg.Height;
			}
		}
		else
		{
			if ( szImg.Height > szWin.Height )
			{
				sz.Height = szWin.Height;
				sz.Width = CastUInt(CastFloat(sz.Height*aspect));
			}
			else
			{
				sz.Width = szImg.Width;
				sz.Height = szImg.Height;
			}
		}
		_sprite = overlay->CreateSprite( image, Order::Lowest, Order::Normal, pt, sz );
	}

	void LoadImage( IStream* stream )
	{
		try
		{
			_sprite = nullptr;
			if ( stream == nullptr )
			{
				DisplayError( L"Image does not exist" );
				return;
			}

			_stream = stream;
			IFrameRenderWindowEx* window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
			const Size szWin( window->GetWidth(), window->GetHeight() );
			PixelFormat format = window->GetClientPixelFormat();
			_progress->SetValue( 0 );
			_progress->Show( true );
			P(IImage) image = _synkro->GetImageManager()->LoadImageAsync( stream, format, this );
			if ( image->IsLoaded() )
			{
				_progress->SetValue( 0 );
				_progress->Show( false );
				CreateSprite( image );
				DisplayFeedback( String::Format(L"Image {0,q} loaded", _stream->GetName()) );
			}
		}
		catch ( Exception& ex )
		{
			DisplayError( ex.ToString() );
			return;
		}
	}
	
	void OpenImage()
	{
		const UInt index = _listImages->GetSelectedItem();
		if ( index != none )
		{
			IStream* stream = (IStream*)_listImages->GetItemData( index );
			LoadImage( stream );
		}
	}

	void ToggleFullscreen()
	{
		DisplayMode displayMode;
		_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
		displayMode = (displayMode == _displayModeFullscreen) ? _displayModeWindowed : _displayModeFullscreen;
		_camera->SetAspect( displayMode.AspectFactor() );
		_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->SetDisplayMode( displayMode );
	}

	void DisplayFeedback( const String& text, const Color& color = Color::White, Double delay = 2.0 )
	{
		Size szText;
		_font->GetTextSize( text, szText );
		Size sz; _viewport->GetSize( sz );

		const Double duration = delay;
		const Int left = (sz.Width - szText.Width)/2;
		const Int top = sz.Height - 80;
		_feedbackText->SetLocation( Point(left, top) );
		_feedbackText->SetText( text );
		_feedbackText->SetColor( color );

		_trackOpacity->Clear();
		_trackOpacity->SetKey( 0.0, 1.0f );
		_trackOpacity->SetKey( duration, 0.0f );

		_feedbackText->Show( true );
		_feedbackCtrl->Reset();
		_feedbackCtrl->Start( true );
		_feedbackSound->Play( true );
	}

	void DisplayError( const String& text )
	{
		DisplayFeedback( text, Color::Red, 5.0 );
	}

private:

	enum
	{
		ID_BUTTON_FULLSCREEN		= 1,
		ID_LABEL_IMAGES				= 2,
		ID_LIST_IMAGES				= 3,
		ID_BUTTON_LOAD				= 4,
		ID_PROGRESS					= 5,
	};

	Bool													_stopping;
	DisplayMode												_displayModeWindowed;
	DisplayMode												_displayModeFullscreen;

	PtrButton												_btnFullscreen;
	PtrLabel												_labelImages;
	PtrList													_listImages;
	PtrButton												_btnLoad;
	PtrProgress												_progress;
	PtrSprite												_sprite;
	PtrStream												_stream;

	PtrFont													_font;
	PtrText													_feedbackText;
	PtrTextAnimationController								_feedbackCtrl;
	PtrKeyframedFloatTrack									_trackOpacity;
	PtrSound2D												_feedbackSound;
};

int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR cmd, int )
{
	SynkroMemoryInit( "synkro.mem", true, "ImageViewer.mem", false, true );
	SynkroProfileInit( "synkro.prf", true, "ImageViewer.prf", false, true );

	ImageViewer app;
	app.Run();
	return 0;
}
