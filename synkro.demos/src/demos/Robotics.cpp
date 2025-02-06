#include "../Demo.h"


class Robotics :
	public Demo
{
public:
	Robotics() :
		Demo( L"Robotics" ),
		_hold( false )
	{
	}

	DebugMode GetDebugMode() const override
	{
		return DebugMode::None;
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		_sun = _scene->CreateDirectLight( nullptr, L"Sun" );
		_sun->SetAmbientColor( Color::Gray );
		_sun->SetDiffuseColor( Color::White );
		_sun->SetSpecularColor( Color::White );
		_sun->LookAt( Vector3(10.0f, 3.0f, 0.0f) );

		PtrStream stream = GetStream( L"cell.x" );
		_cell = _scene->LoadMesh( stream, nullptr, nullptr, 0 );

		// Create stage.
		constexpr Float STAGE_RADIUS = 3.8f;
		constexpr Float STAGE_HEIGHT = 0.2f;
		_materialStage = CreateMaterial( Color::KiwiBrown );
		_stage = CreateCylinder( _cell, _materialStage, STAGE_RADIUS, STAGE_HEIGHT, 40, 40, Matrix4x4::Identity, Vector3(0.0f, -2.9f, 0.0f) );

		// Create robot arm.
		constexpr Float ARM_SIZE = 0.25f;
		constexpr Float JOINT_SIZE = 0.25f;
		Matrix4x4 transRotation;
		Matrix4x4 transPosition;
		_materialJoint1 = CreateMaterial( Color::DarkRed );
		_materialJoint2 = CreateMaterial( Color::DarkGreen );
		_materialJoint3 = CreateMaterial( Color::DarkBlue );
		_materialArm = CreateMaterial( Color::DarkGunmetal );
		_materialCrate = CreateMaterial( Color::White );
		_materialCrate->GetDiffuseMap()->SetImage( GetImage(L"crate.bmp") );
		_materialCrate->SetSpecularColor( Color::Black );

		constexpr Float BASE_RADIUS = 0.5f;
		constexpr Float BASE_HEIGHT = 0.2f;
		constexpr Float ARM1_HEIGHT = 1.0f;
		constexpr Float ARM2_HEIGHT = 2.5f;
		transPosition.SetTranslation( Vector3(0.0f, (STAGE_HEIGHT+BASE_HEIGHT)*0.5f, 0.0f) );
		_joint1 = CreateCylinder( _stage, _materialJoint1, BASE_RADIUS, BASE_HEIGHT, 40, 40, transPosition, Vector3::Origin );
		
		transPosition.SetTranslation( Vector3(0.0f, (STAGE_HEIGHT+BASE_HEIGHT+ARM1_HEIGHT)*0.5f, 0.0f) );
		_arm1 = CreateBox( _joint1, _materialArm, ARM_SIZE, ARM_SIZE, ARM1_HEIGHT, transPosition, Vector3::Origin );

		transRotation.SetOrientation( Quaternion(Vector3::Z, Math::HalfPi) );
		_joint2 = CreateCylinder( _arm1, _materialJoint2, JOINT_SIZE, JOINT_SIZE, 40, 40, transRotation, Vector3(0.0f, 1.45f, 0.0f) );

		transPosition.SetTranslation( Vector3(0.0f, 1.5f, 0.0f) );
		_arm2 = CreateBox( _joint2, _materialArm, ARM_SIZE, ARM_SIZE, ARM2_HEIGHT, transPosition, Vector3::Origin );

		transPosition.SetTranslation( Vector3(0.0f, 3.0f, 0.0f) );
		transRotation.SetOrientation( Quaternion(Vector3::Z, Math::HalfPi) );
		_joint3 = CreateCylinder( _arm2, _materialJoint3, JOINT_SIZE, JOINT_SIZE, 40, 40, transPosition*transRotation, Vector3::Origin );

		// Create crate.
		constexpr Float CRATE_SIZE = 1.1f;
		_crate = CreateBox( _stage, _materialCrate, CRATE_SIZE, CRATE_SIZE, CRATE_SIZE, Matrix4x4::Identity, Vector3(2.0f, 0.65f, -2.0f) );
	}

	void InitView() override
	{
		_camera->SetPosition( Vector3(0.0f, 2.8f, -14.0f) );
		_camera->LookAt( Vector3(0.0f, -1.1f, 0.0f) );
	}

	void InitUi() override
	{
		_labelJoint1 = CreateLabel( Point(_widgetLeft, 120), L"Joint #1 rotation: 0" );
		_sliderJoint1 = CreateSlider( none, Point(_widgetLeft, 140), 0, 3600, 0, Color::DarkRed );

		_labelJoint2 = CreateLabel( Point(_widgetLeft, 160), L"Joint #2 rotation: 0" );
		_sliderJoint2 = CreateSlider( none, Point(_widgetLeft, 180), 0, 900, 0, Color::DarkGreen );

		_btnHold = CreateButton( Point(_widgetLeft, 210), L"Hold" );
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		if ( sender == _btnHold )
		{
			_hold = !_hold;
			if ( _hold )
			{
				_crateParent = _crate->CreateParentConstraint( _joint3, Matrix4x4::Identity );
				_crateParent->SetParent( _joint3 );
				_crateParent->Enable( true );
			}
			else
			{
				_crateParent->Enable( false );
			}
			_btnHold->SetText( _hold ? L"Release" : L"Hold" );
			return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _sliderJoint1 )
		{
			const Float angle = SliderPositionToLabel( _sliderJoint1, _labelJoint1, L"Joint #1 rotation: " );
			_joint1->SetOrientationYaw( angle );
			return true;
		}
		else if ( sender == _sliderJoint2 )
		{
			const Float angle = SliderPositionToLabel( _sliderJoint2, _labelJoint2, L"Joint #2 rotation: " );
			_joint2->SetOrientationPitch( angle );
			return true;
		}

		// TODO:

		return false;
	}

	IOpaqueMaterial* CreateMaterial( const Color& color )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->SetAmbientColor( color );
		material->SetDiffuseColor( color );
		return material;
	}

	Float SliderPositionToLabel( ISlider* slider, ILabel* label, const Char* prefix )
	{
		label->SetText( String::Format(L"{0}{1}", prefix, CastUInt(slider->GetPosition()*0.1f)) );
		return Math::ToRadians( CastFloat(slider->GetPosition())*0.1f );
	}

private:
	PtrDirectLight											_sun;
	PtrTriangleMesh											_cell;
	PtrOpaqueMaterial										_materialStage;
	PtrTriangleMesh											_stage;
	
	PtrOpaqueMaterial										_materialJoint1;
	PtrOpaqueMaterial										_materialJoint2;
	PtrOpaqueMaterial										_materialJoint3;
	PtrOpaqueMaterial										_materialArm;
	PtrOpaqueMaterial										_materialCrate;

	PtrTriangleMesh											_joint1;
	PtrTriangleMesh											_arm1;
	PtrTriangleMesh											_joint2;
	PtrTriangleMesh											_arm2;
	PtrTriangleMesh											_joint3;
	PtrTriangleMesh											_arm3;

	PtrTriangleMesh											_crate;
	PtrParentConstraint										_crateParent;

	PtrLabel												_labelJoint1;
	PtrSlider												_sliderJoint1;

	PtrLabel												_labelJoint2;
	PtrSlider												_sliderJoint2;

	PtrButton												_btnHold;
	Bool													_hold;
};

SYNKRO_DEMO_BEGIN
	Robotics demo;
	demo.Run();
SYNKRO_DEMO_END
