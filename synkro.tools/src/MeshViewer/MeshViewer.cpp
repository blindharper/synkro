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
// Purpose: 'Mesh Viewer' tool.
//==============================================================================
#include "../Tool.h"


extern unsigned __int8 res_MeshViewer_resources[];
extern unsigned __int32 res_MeshViewer_resources_size;


class MeshViewer :
	public Tool
{
public:
	// Initialization.
	MeshViewer() :
		Tool( L"Mesh Viewer", true ),
		_stopping( false ),
		_meshCtrl( nullptr ),
		_skeletonCtrl( nullptr )
	{
	}

	// Configuration.
	void Configure( IConfiguration* config ) override
	{
		config->Set( Param::AudioEnable, true );
		config->Set( Param::AudioFormat, CastUInt(5) );
		config->Set( Param::AudioSystem, AudioSystem::DirectSound8 );
		config->Set( Param::CoreThreadPoolCapacity, CastUInt(8) );
		config->Set( Param::GraphicsDisplayMode, DisplayMode::AboveMedium.Index() );
		config->Set( Param::GraphicsFullscreen, false );
		config->Set( Param::GraphicsProgramCache, String(L"..\\..\\programs") );
		config->Set( Param::GraphicsProgramPreload, String(L"material.standard.textured.skinned") );
		config->Set( Param::UiFontSize, CastUInt(8) );
		config->Set( Param::UiColorWidgetNormal, Color::ForestGreen );
		config->Set( Param::UiColorTextNormal, Color::White );
		config->Set( Param::UiColorTextActive, Color::LightGreen );
		config->Set( Param::UiColorTextHovered, Color::Yellow );
		config->Set( Param::LogFileName, String(L"MeshViewer.log") );
		config->Set( Param::LogFileAppend, false );
		config->Set( Param::LogLevel, LogLevel::Extensive );
		config->Set( Param::LogMode, LogMode::All );
		config->Set( Param::StreamPath, String(L"..\\..\\..\\synkro.models") );
	}

	// Setup scene.
	void Init() override
	{
		String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
		_displayModeWindowed = DisplayMode( mode, false );
		DisplayMode::GetMode( 0, _displayModeFullscreen );
		_displayModeFullscreen.Fullscreen = true;

		_camera->SetPosition( Vector3(0.0f, 0.0f, -500.0f) );
		_camera->LookAt( Vector3::Origin );
		_synkro->GetInputSystem()->GetKeyboard( 0 )->ListenKeyDown( this, Key::Return, true );

		_scene->SetAmbientLightColor( Color::DimGray );
		_light = _scene->CreateOmniLight( nullptr, L"Light" );
		//_light->SetAmbientColor( Color::DarkGray );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->SetPosition( Vector3(0.0f, 50.0f, -50.0f) );
		_light->SetIntensity( 0.25f );
	}

	// Setup GUI.
	void InitUi( IUiEx* ui ) override
	{
		core::IResource* res = _synkro->CreateResource( res_MeshViewer_resources, res_MeshViewer_resources_size );
		P(IStreamDirectory) dir = res->Load();
		P(IStream) streamUI = dir->GetStream( L"MeshViewer.ui" );
		_synkro->GetUi()->Load( streamUI );
		P(IStream) streamWav = dir->GetStream( L"pop.wav" );
		_feedbackSound = CreateSound( streamWav );
		delete res;
		_accordion = _synkro->GetUi()->GetFrame( ID_ACCORDION )->AsAccordion();
		for ( UInt i = 0; i < _accordion->GetPanelCount(); ++i )
		{
			_accordion->ExpandPanel( i, true );
		}
		_btnFullscreen = _synkro->GetUi()->GetWidget( ID_BUTTON_FULLSCREEN )->AsButton();
		_switchWireframe = _synkro->GetUi()->GetWidget( ID_SWITCH_WIREFRAME )->AsSwitch();
		_labelModels = _synkro->GetUi()->GetWidget( ID_LABEL_MODELS )->AsLabel();
		_listModels = _synkro->GetUi()->GetWidget( ID_LIST_MODELS )->AsList();
		_btnLoad = _synkro->GetUi()->GetWidget( ID_BUTTON_LOAD )->AsButton();
		_btnLoad->Enable( false );
		_labelSubsets = _synkro->GetUi()->GetWidget( ID_LABEL_SUBSETS )->AsLabel();
		_listSubsets = _synkro->GetUi()->GetWidget( ID_LIST_SUBSETS )->AsDropList();
		_labelAnimations = _synkro->GetUi()->GetWidget( ID_LABEL_ANIMATIONS )->AsLabel();
		_listAnimations = _synkro->GetUi()->GetWidget( ID_LIST_ANIMATIONS )->AsDropList();
		_labelRotateAngle = _synkro->GetUi()->GetWidget( ID_LABEL_ROTATE_ANGLE )->AsLabel();
		_angleRotation = _synkro->GetUi()->GetWidget( ID_ANGLE_ROTATION )->AsAngle();
		_btnRotate = _synkro->GetUi()->GetWidget( ID_BUTTON_ROTATE )->AsButton();
		_labelAnimationTime = _synkro->GetUi()->GetWidget( ID_LABEL_ANIMATION_TIME )->AsLabel();
		_sliderAnimationTime = _synkro->GetUi()->GetWidget( ID_SLIDER_ANIMATION_TIME )->AsSlider();
		_btnAnimationPause = _synkro->GetUi()->GetWidget( ID_BUTTON_ANIMATION_PAUSE )->AsButton();
		_labelVertices = _synkro->GetUi()->GetWidget( ID_LABEL_VERTICES )->AsLabel();
		_labelTriangles = _synkro->GetUi()->GetWidget( ID_LABEL_TRIANGLES )->AsLabel();
		_labelBones = _synkro->GetUi()->GetWidget( ID_LABEL_BONES )->AsLabel();
		ShowSubsetWidgets( false );
		ShowAnimationWidgets( false );

		IOverlay* overlay = _synkro->GetOverlayManager()->GetOverlay( _synkro->GetGraphicsSystem()->GetFrameWindow(0) );
		_font = overlay->GetFont( L"ui" );
		_feedbackText = _font->CreateText( Color::Yellow, Point(), String::Empty, Order::Highest, Order::Highest );
		_feedbackText->Show( false );
		_feedbackCtrl = _feedbackText->CreateAnimationController( nullptr, nullptr );
		_trackOpacity = _feedbackCtrl->CreateOpacityTrack();

		DisplayModels( L"synkro.models" );
		_listModels->Activate( true );
	}

	// SynkroListener methods.
	void OnSynkroUpdate( Double delta ) override
	{
		Tool::OnSynkroUpdate( delta );

		if ( _meshCtrl != nullptr )
		{
			if ( _meshCtrl->GetState() != ControllerState::Suspended )
			{
				const Double time = _meshCtrl->GetTime();
				const UInt angle = time/Math::TwoPi*360.0f;
				_angleRotation->SetValue( angle );
			}
		}

		if ( _skeletonCtrl != nullptr )
		{
			Double time = _skeletonCtrl->GetTime();
			_labelAnimationTime->SetText( String::Format(L"TIME: {0,0.000}", time) );
			time *= 100.0;
			IAnimation* animation = _skeletonCtrl->GetAnimation();
			_sliderAnimationTime->SetMaxPosition( CastUInt(animation->GetLength()*100.0) );
			_sliderAnimationTime->SetPosition( CastUInt(time) );
		}
	}

	// KeyboardListener methods.
	Bool OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control ) override
	{
		if ( key == Key::Return )
		{
			if ( _listModels->IsActive() )
			{
				OpenMesh();
				return true;
			}
		}
		return false;
	}

	// ArcballListener methods.
	Bool OnArcballOriented( const Quaternion& orientation ) override
	{
		if ( _mesh != nullptr )
		{
			_mesh->SetOrientation( orientation );
		}
		return true;
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
			OpenMesh();
			return true;
		}
		else if ( sender == _btnRotate )
		{
			_meshCtrl->Pause( _meshCtrl->GetState() != ControllerState::Suspended );
			_btnRotate->SetText( (_meshCtrl->GetState() != ControllerState::Suspended) ? L"St[o]p" : L"R[o]tate" );
			return true;
		}
		else if ( sender == _btnAnimationPause )
		{
			if ( _skeletonCtrl != nullptr )
			{
				_skeletonCtrl->Pause( _skeletonCtrl->GetState() != ControllerState::Suspended );
				_btnAnimationPause->SetText( (_skeletonCtrl->GetState() != ControllerState::Suspended) ? L"Pau[s]e" : L"Re[s]ume" );
				return true;
			}
		}

		return false;
	}

	Bool OnUiDoubleClick( IWidget* sender ) override
	{
		if ( Tool::OnUiDoubleClick(sender) )
			return true;

		if ( sender == _listModels )
		{
			OpenMesh();
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Tool::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listModels )
		{
			_btnLoad->Enable( _listModels->GetSelectedItem() != none );
			return true;
		}
		else if ( sender == _listSubsets )
		{
			DisplayActiveSubset();
			return true;
		}
		else if ( sender == _listAnimations )
		{
			DisplayActiveAnimation();
			return true;
		}
		else if ( sender == _switchWireframe )
		{
			_viewport->SetWireframe( _switchWireframe->IsOn() );
			return true;
		}
		else if ( sender == _angleRotation )
		{
			const UInt angle = _angleRotation->GetValue();
			_mesh->SetOrientationYaw( -Math::ToRadians(angle) );
			_labelRotateAngle->SetText( String::Format(L"ANGLE: {0}", angle) );
			const Double time = CastFloat(angle)/360.0f*Math::TwoPi;
			_meshCtrl->SetTime( time );
			_meshCtrl->Update( 0.0 );
			return true;
		}
		else if ( sender == _sliderAnimationTime )
		{
			Double time = CastDouble( _sliderAnimationTime->GetPosition() );
			time *= 0.01;
			_skeletonCtrl->SetTime( time );
			_skeletonCtrl->Update( 0.0 );
			return true;
		}

		return false;
	}

	// Other methods.
	void DisplayModels( String dirName )
	{
		_listModels->Clear();
		IStreamDirectory* dir = _synkro->GetStreamSystem()->GetDirectory( dirName );
		for ( UInt i = 0; i < dir->GetStreamCount(); ++i )
		{
			IStream* stream = dir->GetStream( i );
			if ( MeshCodec::IsValid(stream->GetName()) )
			{
				_listModels->AddItem( ListItem(stream->GetName(), (Pointer)stream) );
			}
		}
		_labelModels->SetText( String::Format(L"MODELS ({0})", _listModels->GetItemCount()) );
	}

	void LoadMesh( IStream* stream )
	{
		try
		{
			if ( stream == nullptr )
			{
				DisplayError( L"Mesh does not exist" );
				return;
			}
			_skeletonCtrl = nullptr;
			P(ISkeleton) skeleton = _synkro->GetSceneManager()->CreateSkeleton();
			_mesh = _scene->LoadMesh( stream, nullptr, skeleton, 0 );
		}
		catch ( Exception& ex )
		{
			DisplayError( ex.ToString() );
			return;
		}

		const Float sphere = _mesh->GetBoundSphere();
		Vector3 center; _mesh->GetCenter( center );
		_mesh->SetScale( 35.0f/sphere );
		// TODO:_mesh->SetPosition( -center/*Vector3::Origin*/ );
		_mesh->SetPosition( Vector3::Origin );

		_meshCtrl = _mesh->CreateAnimationController( nullptr, nullptr );
		IWaveFloatTrack* trackYaw = _meshCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothDown );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0/Math::TwoPi );
		trackYaw->SetLength( CastDouble(Math::TwoPi) );
		_meshCtrl->SetMode( AnimationMode::Loop );
		_meshCtrl->Start( true );

		DisplaySubsets();
		DisplayAnimations();
		SetupSkeletonController();
		DisplayFeedback( String::Format(L"Model {0,q} loaded", stream->GetName()) );
	}
	
	void OpenMesh()
	{
		const UInt index = _listModels->GetSelectedItem();
		if ( index != none )
		{
			IStream* stream = (IStream*)_listModels->GetItemData( index );
			LoadMesh( stream );
		}
	}

	void DisplaySubsets()
	{
		UInt vertexCount = 0;
		UInt indexCount = 0;
		_listSubsets->Clear();
		_listSubsets->AddItem( L"All" );
		for ( UInt i = 0; i < _mesh->GetSubsetCount(); ++i )
		{
			_listSubsets->AddItem(_mesh->GetSubsetName( i ) );
			vertexCount += _mesh->GetSubset( i )->GetVertexCount();
			indexCount += _mesh->GetSubset( i )->GetIndexCount();
		}
		_listSubsets->SetListHeight( _mesh->GetSubsetCount()+1 );
		_listSubsets->SelectItem( 0 );
		_labelSubsets->SetText( String::Format(L"SUBSETS ({0})", _mesh->GetSubsetCount()) );
		_labelVertices->SetText( String::Format(L"VERTICES: {0}", vertexCount) );
		_labelTriangles->SetText( String::Format(L"TRIANGLES: {0}", indexCount/3) );

		ShowSubsetWidgets( true );
	}

	void DisplayAnimations()
	{
		UInt boneCount = 0;
		_listAnimations->Clear();
		ISkeleton* skeleton = _mesh->GetSkeleton();
		if ( skeleton != nullptr )
		{
			boneCount = skeleton->GetBoneCount();
			for ( UInt i = 0; i < skeleton->GetAnimationSetCount(); ++i )
			{
				String name = skeleton->GetAnimationSet( i )->GetName();
				_listAnimations->AddItem( name.IsEmpty() ? L"Default" : name );
			}
			_listAnimations->SetListHeight( _listAnimations->GetItemCount() );
			_listAnimations->SelectItem( 0 );
		}
		_labelAnimations->SetText( String::Format(L"ANIMATIONS ({0})", _listAnimations->GetItemCount()) );
		_labelBones->SetText( String::Format(L"BONES: {0}", boneCount) );

		ShowAnimationWidgets( skeleton != nullptr );
	}

	void ShowSubsetWidgets( Bool show )
	{
		_labelSubsets->Show( show );
		_listSubsets->Show( show );
		_labelRotateAngle->Show( show );
		_angleRotation->Show( show );
		_btnRotate->Show( show );
	}

	void ShowAnimationWidgets( Bool show )
	{
		_labelAnimations->Show( show );
		_labelBones->Show( show );
		_listAnimations->Show( show );
		_labelAnimationTime->Show( show );
		_sliderAnimationTime->Show( show );
		_btnAnimationPause->Show( show );
	}

	void SetupSkeletonController()
	{
		ISkeleton* skeleton = _mesh->GetSkeleton();
		if ( skeleton != nullptr )
		{
			_skeletonCtrl = skeleton->CreateAnimationController( nullptr, nullptr );
			_skeletonCtrl->SetMode( AnimationMode::Loop );
			_skeletonCtrl->SetDirection( AnimationDirection::Forward );
			_skeletonCtrl->SetLoopCount( 0 );
			_skeletonCtrl->SetSpeed( 4.0 );
			_skeletonCtrl->Start( true );
			IAnimation* animation = _skeletonCtrl->GetAnimation();
			_sliderAnimationTime->SetMaxPosition( CastUInt(animation->GetLength()*100.0) );
		}
	}

	void DisplayActiveSubset()
	{
		UInt vertexCount = 0;
		UInt indexCount = 0;
		const UInt idx = _listSubsets->GetSelectedItem();
		for ( UInt i = 0; i < _mesh->GetSubsetCount(); ++i )
		{
			const Bool countSubset = (idx == 0) || (idx == i+1);
			_mesh->GetSubset( i )->Show( countSubset );
			vertexCount += countSubset ? _mesh->GetSubset( i )->GetVertexCount() : 0;
			indexCount += countSubset ? _mesh->GetSubset( i )->GetIndexCount() : 0;
		}
		_labelVertices->SetText( String::Format(L"VERTICES: {0}", vertexCount) );
		_labelTriangles->SetText( String::Format(L"TRIANGLES: {0}", indexCount/3) );
	}

	void DisplayActiveAnimation()
	{
		if ( _skeletonCtrl != nullptr )
		{
			_skeletonCtrl->SetAnimationSet( _listAnimations->GetText() );
			_skeletonCtrl->Restart();
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

	void DisplayFeedback( const String& text, const Color& color = Color::Yellow, Double delay = 2.0 )
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
		ID_SWITCH_WIREFRAME			= 2,
		ID_LABEL_MODELS				= 3,
		ID_LIST_MODELS				= 4,
		ID_BUTTON_LOAD				= 5,
		ID_LABEL_SUBSETS			= 6,
		ID_LIST_SUBSETS				= 7,
		ID_LABEL_ANIMATIONS			= 8,
		ID_LIST_ANIMATIONS			= 9,
		ID_LABEL_ROTATE_ANGLE		= 10,
		ID_ANGLE_ROTATION			= 11,
		ID_BUTTON_ROTATE			= 12,
		ID_LABEL_ANIMATION_TIME		= 13,
		ID_SLIDER_ANIMATION_TIME	= 14,
		ID_BUTTON_ANIMATION_PAUSE	= 15,
		ID_ACCORDION				= 16,
		ID_LABEL_VERTICES			= 20,
		ID_LABEL_TRIANGLES			= 21,
		ID_LABEL_BONES				= 22,
	};

	Bool													_stopping;
	DisplayMode												_displayModeWindowed;
	DisplayMode												_displayModeFullscreen;

	PtrAccordion											_accordion;
	PtrButton												_btnFullscreen;
	PtrSwitch												_switchWireframe;
	PtrLabel												_labelModels;
	PtrList													_listModels;
	PtrButton												_btnLoad;
	PtrLabel												_labelSubsets;
	PtrDropList												_listSubsets;
	PtrLabel												_labelAnimations;
	PtrDropList												_listAnimations;
	PtrLabel												_labelRotateAngle;
	PtrSlider												_sliderRotateAngle;
	PtrAngle												_angleRotation;
	PtrButton												_btnRotate;
	PtrLabel												_labelAnimationTime;
	PtrSlider												_sliderAnimationTime;
	PtrButton												_btnAnimationPause;
	PtrLabel												_labelVertices;
	PtrLabel												_labelTriangles;
	PtrLabel												_labelBones;

	PtrOmniLight											_light;
	PtrTriangleMesh											_mesh;
	PtrNodeAnimationController								_meshCtrl;
	PtrSkeletonAnimationController							_skeletonCtrl;

	PtrFont													_font;
	PtrText													_feedbackText;
	PtrTextAnimationController								_feedbackCtrl;
	PtrKeyframedFloatTrack									_trackOpacity;
	PtrSound2D												_feedbackSound;
};

int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR cmd, int )
{
	SynkroMemoryInit( "synkro.mem", true, "MeshViewer.mem", false, true );
	SynkroProfileInit( "synkro.prf", true, "MeshViewer.prf", false, true );

	MeshViewer app;
	app.Run();
	return 0;
}
