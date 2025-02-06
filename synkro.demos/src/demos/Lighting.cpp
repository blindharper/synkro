#include "../Demo.h"


class Lighting :
	public Demo
{
public:
	Lighting() :
		Demo( L"Lighting" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create material.
		_material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		_material->SetDiffuseColor( Color::Red );
		_material->SetSpecularColor( Color::White );
		_material->SetSpecularPower( 50 );

		// Create ball and torus.
		constexpr Float BALL_RADIUS = 20.0f; constexpr Float TORUS_RADIUS = 7.0f;
		_ball = CreateSphere( nullptr, _material, BALL_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(-25.0f, 0.0f, 0.0f) );
		_torus = CreateTorus( nullptr, _material, TORUS_RADIUS, 2.0f*TORUS_RADIUS, 40, 40, Matrix4x4::Identity.RotateX(Math::HalfPi), Vector3(20.0f, 0.0f, 0.0f) );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(-10.0f, -3.0f, 0.0f) );
	}

	void InitView() override
	{
		// Setup viewport and camera.
		_viewport->SetColor( Color::Black );
		_camera->SetPosition( Vector3(0.0f, 24.0f, -136.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	void InitUi() override
	{
		PtrStream stream = GetStream( L"Lighting.ui" );
		_synkro->GetUi()->Load( stream );

		_listMode = _synkro->GetUi()->GetWidget( ID_LIST_MODE )->AsDropList();
		_listColor = _synkro->GetUi()->GetWidget( ID_LIST_COLOR )->AsDropList();
		_labelRed = _synkro->GetUi()->GetWidget( ID_LABEL_RED )->AsLabel();
		_sliderRed = _synkro->GetUi()->GetWidget( ID_SLIDER_RED )->AsSlider();
		_labelGreen = _synkro->GetUi()->GetWidget( ID_LABEL_GREEN )->AsLabel();
		_sliderGreen = _synkro->GetUi()->GetWidget( ID_SLIDER_GREEN )->AsSlider();
		_labelBlue = _synkro->GetUi()->GetWidget( ID_LABEL_BLUE )->AsLabel();
		_sliderBlue = _synkro->GetUi()->GetWidget( ID_SLIDER_BLUE )->AsSlider();
		_labelSpecularPower = _synkro->GetUi()->GetWidget( ID_LABEL_SPECULAR_POWER )->AsLabel();
		_sliderSpecularPower = _synkro->GetUi()->GetWidget( ID_SLIDER_SPECULAR_POWER )->AsSlider();
		_labelIntensity = _synkro->GetUi()->GetWidget( ID_LABEL_INTENSITY )->AsLabel();
		_sliderIntensity = _synkro->GetUi()->GetWidget( ID_SLIDER_INTENSITY )->AsSlider();
		SetColorComponent( _labelIntensity, _sliderIntensity, L"Intensity: ", 1.0f );
		_switchEnableLight = _synkro->GetUi()->GetWidget( ID_SWITCH_ENABLE_LIGHT )->AsSwitch();

		_listMode->AddItem( L"Material" );
		_listMode->AddItem( L"Light" );
		_listMode->AddItem( L"Scene" );
		_listMode->SetListHeight( _listMode->GetItemCount() );
		_listMode->SelectItem( 0 );
	}

	// ArcballListener methods.
	Bool ListenArcballInput() const override
	{
		return true;
	}

	Bool OnArcballOriented( const Quaternion& orientation ) override
	{
		_ball->SetOrientation( orientation );
		_torus->SetOrientation( orientation );
		return true;
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _listMode )
		{
			_listColor->Clear();
			_listColor->AddItem( L"Ambient" );
			if ( _listMode->GetSelectedItem() != 2 )
			{
				_listColor->AddItem( L"Diffuse" );
				_listColor->AddItem( L"Specular" );
			}
			if ( _listMode->GetSelectedItem() == 0 )
			{
				_listColor->AddItem( L"Emissive" );
				_labelSpecularPower->SetText( String::Format(L"Specular power: {0}", CastUInt(_material->GetSpecularPower())) );
				_sliderSpecularPower->SetPosition( _material->GetSpecularPower() );
			}
			_listColor->SetListHeight( _listColor->GetItemCount() );
			_listColor->SelectItem( 0 );
			const Bool showSpecularPower = _listMode->GetSelectedItem() == 0;
			_labelSpecularPower->Show( showSpecularPower );
			_sliderSpecularPower->Show( showSpecularPower );
			const Bool showIntensity = _listMode->GetSelectedItem() == 1;
			_labelIntensity->Show( showIntensity );
			_sliderIntensity->Show( showIntensity );
			return true;
		}
		else if ( sender == _listColor )
		{
			if ( _listMode->GetSelectedItem() == 0 )
			{
				Color color;
				switch ( _listColor->GetSelectedItem() )
				{
					case 0: _material->GetAmbientColor( color ); break;
					case 1: _material->GetDiffuseColor( color ); break;
					case 2: _material->GetSpecularColor( color ); break;
					case 3: _material->GetEmissiveColor( color ); break;
				}
				SetColor( color );
				return true;
			}
			else if ( _listMode->GetSelectedItem() == 1 )
			{
				Color color;
				switch ( _listColor->GetSelectedItem() )
				{
					case 0: _light->GetAmbientColor( color ); break;
					case 1: _light->GetDiffuseColor( color ); break;
					case 2: _light->GetSpecularColor( color ); break;
				}
				SetColor( color );
				return true;
			}
			else if ( _listMode->GetSelectedItem() == 2 )
			{
				Color color;
				_scene->GetAmbientLightColor( color );
				SetColor( color );
				return true;
			}
		}
		else if ( (sender == _sliderRed) || (sender == _sliderGreen) || (sender == _sliderBlue) )
		{
			Color color;
			GetColor( color );
			if ( _listMode->GetSelectedItem() == 0 )
			{
				switch ( _listColor->GetSelectedItem() )
				{
					case 0: _material->SetAmbientColor( color ); break;
					case 1: _material->SetDiffuseColor( color ); break;
					case 2: _material->SetSpecularColor( color ); break;
					case 3: _material->SetEmissiveColor( color ); break;
				}
			}
			else if ( _listMode->GetSelectedItem() == 1 )
			{
				switch (_listColor->GetSelectedItem())
				{
					case 0: _light->SetAmbientColor( color ); break;
					case 1: _light->SetDiffuseColor( color ); break;
					case 2: _light->SetSpecularColor( color ); break;
				}
			}
			else if ( _listMode->GetSelectedItem() == 2 )
			{
				_scene->SetAmbientLightColor( color );
			}
			SetColorLabel( _labelRed, L"Red: ", color.R );
			SetColorLabel( _labelGreen, L"Green: ", color.G );
			SetColorLabel( _labelBlue, L"Blue: ", color.B );
			return true;
		}
		else if ( sender == _sliderSpecularPower )
		{
			_material->SetSpecularPower( CastFloat(_sliderSpecularPower->GetPosition()) );
			_labelSpecularPower->SetText( String::Format(L"Specular power: {0}", CastUInt(_material->GetSpecularPower())) );
			return true;
		}
		else if ( sender == _sliderIntensity )
		{
			Float intensity = CastFloat(_sliderIntensity->GetPosition())*0.001f;
			_light->SetIntensity( intensity );
			SetColorComponent( _labelIntensity, _sliderIntensity, L"Intensity: ", intensity );
			return true;
		}
		else if ( sender == _switchEnableLight )
		{
			_light->Enable( _switchEnableLight->IsOn() );
			return true;
		}

		return false;
	}

	void GetColor( Color& color )
	{
		color.R = CastFloat(_sliderRed->GetPosition())*0.001f;
		color.G = CastFloat(_sliderGreen->GetPosition())*0.001f;
		color.B = CastFloat(_sliderBlue->GetPosition())*0.001f;
	}

	void SetColor( const Color& color )
	{
		SetColorComponent( _labelRed, _sliderRed, L"Red: ", color.R );
		SetColorComponent( _labelGreen, _sliderGreen, L"Green: ", color.G );
		SetColorComponent( _labelBlue, _sliderBlue, L"Blue: ", color.B );
	}

	void SetColorLabel( ILabel* label, const String& prefix, Float value )
	{
		label->SetText( String::Format(L"{0}{1}", prefix, value) );
	}

	void SetColorComponent( ILabel* label, ISlider* slider, const String& prefix, Float value )
	{
		SetColorLabel( label, prefix, value );
		slider->SetPosition( CastUInt(value*1000.0f) );
	}

private:
	enum
	{
		ID_LIST_MODE = 0,
		ID_LIST_COLOR = 1,
		ID_LABEL_RED = 2,
		ID_SLIDER_RED = 3,
		ID_LABEL_GREEN = 4,
		ID_SLIDER_GREEN = 5,
		ID_LABEL_BLUE = 6,
		ID_SLIDER_BLUE = 7,
		ID_LABEL_SPECULAR_POWER = 8,
		ID_SLIDER_SPECULAR_POWER = 9,
		ID_LABEL_INTENSITY = 10,
		ID_SLIDER_INTENSITY = 11,
		ID_SWITCH_ENABLE_LIGHT = 12,
	};

	PtrDirectLight											_light;
	PtrOpaqueMaterial										_material;
	PtrTriangleMesh											_ball;
	PtrTriangleMesh											_torus;

	PtrDropList												_listMode;
	PtrDropList												_listColor;
	PtrLabel												_labelRed;
	PtrSlider												_sliderRed;
	PtrLabel												_labelGreen;
	PtrSlider												_sliderGreen;
	PtrLabel												_labelBlue;
	PtrSlider												_sliderBlue;
	PtrLabel												_labelSpecularPower;
	PtrSlider												_sliderSpecularPower;
	PtrLabel												_labelIntensity;
	PtrSlider												_sliderIntensity;
	PtrSwitch												_switchEnableLight;
};

SYNKRO_DEMO_BEGIN
	Lighting demo;
	demo.Run();
SYNKRO_DEMO_END
