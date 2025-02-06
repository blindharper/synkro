#include "../Demo.h"


class Transparency :
	public Demo
{
public:
	Transparency() :
		Demo( L"Transparency" )
	{
	}

	void InitScene() override
	{
		// Create materials.
		PtrImage imageDiffuse = GetImage( L"earthmap1k.jpg" );
		PtrImage imageOpacity = GetImage( L"earthopac1k.jpg", PixelFormat::R8G8B8A8 );
		_material = CreateTransparentMaterial( imageDiffuse );
		
		_material2 = CreateTransparentMaterial( imageDiffuse );
		_material2->GetOpacityMap()->SetImage( imageOpacity );
		_material2->SetColorSourceMode( BlendMode::SrcAlpha );
		_material2->SetAlphaSourceMode( BlendMode::SrcAlpha );
		_material2->SetColorDestinationMode( BlendMode::DstAlpha );
		_material2->SetAlphaDestinationMode( BlendMode::DstAlpha );
		_material2->SetColorOperation( BlendOperation::Add );
		_material2->SetAlphaOperation( BlendOperation::Add );
		
		_material3 = CreateTransparentMaterial( imageDiffuse );
		_material3->SetColorSourceMode( BlendMode::SrcAlpha );
		_material3->SetAlphaSourceMode( BlendMode::SrcAlpha );
		_material3->SetColorDestinationMode( BlendMode::DstAlpha );
		_material3->SetAlphaDestinationMode( BlendMode::DstAlpha );
		_material3->SetColorOperation( BlendOperation::Add );
		_material3->SetAlphaOperation( BlendOperation::Add );

		// Create geometry.
		constexpr Float EARTH_RADIUS = 30.0f;
		_earth = CreateSphere( nullptr, _material, EARTH_RADIUS, 80, 80, Matrix4x4::Identity, Vector3(70.0f, 0.0f, 0.0f) );
		_earth2 = CreateSphere( nullptr, _material2, EARTH_RADIUS, 80, 80, Matrix4x4::Identity, Vector3(0.0f, 0.0f, 0.0f) );
		_earth3 = CreateSphere( nullptr, _material3, EARTH_RADIUS, 80, 80, Matrix4x4::Identity, Vector3(-70.0f, 0.0f, 0.0f) );

		// Setup animations.
		PtrNodeAnimationController ctrlEarth = _earth->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = ctrlEarth->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothUp );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0f/Math::Pi );
		ctrlEarth->SetMode( AnimationMode::Loop );
		ctrlEarth->SetSpeed( 0.5 );
		ctrlEarth->Start( true );

		PtrNodeAnimationController ctrlEarth2 = _earth2->CreateAnimationController( ctrlEarth->GetAnimation(), nullptr);
		ctrlEarth2->SetMode( AnimationMode::Loop );
		ctrlEarth2->SetSpeed( 0.5 );
		ctrlEarth2->Start( true );

		PtrNodeAnimationController ctrlEarth3 = _earth3->CreateAnimationController( ctrlEarth->GetAnimation(), nullptr);
		ctrlEarth3->SetMode( AnimationMode::Loop );
		ctrlEarth3->SetSpeed( 0.5 );
		ctrlEarth3->Start( true );

		PtrTransparentMaterialAnimationController ctrlMaterial = _material3->CreateAnimationController( nullptr, nullptr )->AsSimple()->AsTransparent();
		PtrWaveFloatTrack trackOpacity = ctrlMaterial->CreateOpacityTrack( AnimationTrack::FloatWave )->AsWave();
		trackOpacity->SetType( WaveType::Sine );
		trackOpacity->SetAmplitude( 0.45f );
		trackOpacity->SetOffset( 0.55f );
		ctrlMaterial->SetMode( AnimationMode::Loop );
		ctrlMaterial->Start( true );
	}

	void InitView() override
	{
		// Setup camera and viewport.
		_viewport->SetColor( Color::Black );
		_camera->SetPosition( Vector3(0.0f, 50.0f, -250.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		_labelColorSourceMode = CreateLabel( Point( _widgetLeft-156, 152 ), L"Color Source Mode:" );
		_listColorSourceMode = CreateDropList( Point( _widgetLeft, 150 ), Size(150, 25) );
		_labelAlphaSourceMode = CreateLabel( Point( _widgetLeft-156, 182 ), L"Alpha Source Mode:" );
		_listAlphaSourceMode = CreateDropList( Point( _widgetLeft, 180 ), Size(150, 25) );
		_labelColorDestinationMode = CreateLabel( Point( _widgetLeft-148, 212 ), L"Color Dest Mode:" );
		_listColorDestinationMode = CreateDropList( Point( _widgetLeft, 210 ), Size(150, 25) );
		_labelAlphaDestinationMode = CreateLabel( Point( _widgetLeft-148, 242 ), L"Alpha Dest Mode:" );
		_listAlphaDestinationMode = CreateDropList( Point( _widgetLeft, 240 ), Size(150, 25) );
		_labelColorOperation = CreateLabel( Point( _widgetLeft-144, 272 ), L"Color Operation:" );
		_listColorOperation = CreateDropList( Point( _widgetLeft, 270 ), Size(150, 25) );
		_labelAlphaOperation = CreateLabel( Point( _widgetLeft-144, 302 ), L"Alpha Operation:" );
		_listAlphaOperation = CreateDropList( Point( _widgetLeft, 300 ), Size(150, 25) );

		FillModeList( _listColorSourceMode );
		FillModeList( _listAlphaSourceMode, true );
		FillModeList( _listColorDestinationMode );
		FillModeList( _listAlphaDestinationMode, true );
		FillOperationList( _listColorOperation );
		FillOperationList( _listAlphaOperation );
		_listColorSourceMode->SelectItem( BlendMode::InvDstColor.Value()-1 );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listColorSourceMode )
		{
			_material->SetColorSourceMode( BlendMode(_listColorSourceMode->GetText()) );
			return true;
		}
		else if ( sender == _listAlphaSourceMode )
		{
			_material->SetAlphaSourceMode( BlendMode(_listAlphaSourceMode->GetText()) );
			return true;
		}
		else if ( sender == _listColorDestinationMode )
		{
			_material->SetColorDestinationMode( BlendMode(_listColorDestinationMode->GetText()) );
			return true;
		}
		else if ( sender == _listAlphaDestinationMode )
		{
			_material->SetAlphaDestinationMode( BlendMode(_listAlphaDestinationMode->GetText()) );
			return true;
		}
		else if ( sender == _listColorOperation )
		{
			_material->SetColorOperation( BlendOperation(_listColorOperation->GetText()) );
			return true;
		}
		else if ( sender == _listAlphaOperation )
		{
			_material->SetAlphaOperation( BlendOperation(_listAlphaOperation->GetText()) );
			return true;
		}

		return false;
	}

	void FillModeList( IDropList* list, Bool alpha = false )
	{
		list->AddItem( BlendMode::Zero.ToString() );
		list->AddItem( BlendMode::One.ToString() );
		if ( !alpha )
		{
			list->AddItem( BlendMode::SrcColor.ToString() );
			list->AddItem( BlendMode::InvSrcColor.ToString() );
		}
		list->AddItem( BlendMode::SrcAlpha.ToString() );
		list->AddItem( BlendMode::InvSrcAlpha.ToString() );
		list->AddItem( BlendMode::DstAlpha.ToString() );
		list->AddItem( BlendMode::InvDstAlpha.ToString() );
		if ( !alpha )
		{
			list->AddItem( BlendMode::DstColor.ToString() );
			list->AddItem( BlendMode::InvDstColor.ToString() );
		}
		list->AddItem( BlendMode::SrcAlphaSat.ToString() );
		list->SetListHeight( list->GetItemCount() );
		list->SelectItem( 0 );
	}

	void FillOperationList( IDropList* list )
	{
		list->AddItem( BlendOperation::Add.ToString() );
		list->AddItem( BlendOperation::Sub.ToString() );
		list->AddItem( BlendOperation::RevSub.ToString() );
		list->AddItem( BlendOperation::Min.ToString() );
		list->AddItem( BlendOperation::Max.ToString() );
		list->SetListHeight( list->GetItemCount() );
		list->SelectItem( 0 );
	}

	ITransparentMaterial* CreateTransparentMaterial( IImage* diffuse )
	{
		ITransparentMaterial* material = _synkro->GetMaterialManager()->CreateTransparentMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->GetDiffuseMap()->SetAmount( 1.0f );
		material->SetDiffuseColor( Color::White );
		return material;
	}

private:
	PtrTransparentMaterial									_material;
	PtrTriangleMesh											_earth;

	PtrTransparentMaterial									_material2;
	PtrTriangleMesh											_earth2;

	PtrTransparentMaterial									_material3;
	PtrTriangleMesh											_earth3;

	PtrLabel												_labelColorSourceMode;
	PtrDropList												_listColorSourceMode;
	PtrLabel												_labelAlphaSourceMode;
	PtrDropList												_listAlphaSourceMode;
	PtrLabel												_labelColorDestinationMode;
	PtrDropList												_listColorDestinationMode;
	PtrLabel												_labelAlphaDestinationMode;
	PtrDropList												_listAlphaDestinationMode;
	PtrLabel												_labelColorOperation;
	PtrDropList												_listColorOperation;
	PtrLabel												_labelAlphaOperation;
	PtrDropList												_listAlphaOperation;
};

SYNKRO_DEMO_BEGIN
	Transparency demo;
	demo.Run();
SYNKRO_DEMO_END
