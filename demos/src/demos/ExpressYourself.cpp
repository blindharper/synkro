#include "../Demo.h"


class ExpressYourself :
	public Demo
{
public:
	ExpressYourself() :
		Demo( L"Express Yourself" )
	{
	}

	Bool IsLit() const override
	{
		return true;
	}

	void InitScene() override
	{
		// Create materials.
		IImage* diffuseMap = GetImage( L"checkers.jpg" );
		_material = CreateMaterial( diffuseMap );
		_material2 = CreateMaterial( diffuseMap );
		_material3 = CreateMaterial( diffuseMap );
		_material4 = CreateMaterial( diffuseMap );
		_material5 = CreateMaterial( diffuseMap );

		// Create light source.
		_light = _scene->CreateDirectLight( nullptr, L"Light" );
		_light->SetDiffuseColor( Color::White );
		_light->SetSpecularColor( Color::White );
		_light->LookAt( Vector3(0.0f, -1.0f, 1.0f) );

		// Create spheres.
		constexpr Float SPHERE_RADIUS = 10.0f;
		_sphere = CreateSphere( nullptr, _material, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(-50.0f, 25.0f, 0.0f) );
		_sphere2 = CreateSphere( nullptr, _material2, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(50.0f, 25.0f, 0.0f) );
		_sphere3 = CreateSphere( nullptr, _material3, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3::Origin );
		_sphere4 = CreateSphere( nullptr, _material4, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(-50.0f, -25.0f, 0.0f) );
		_sphere5 = CreateSphere( nullptr, _material5, SPHERE_RADIUS, 40, 40, Matrix4x4::Identity, Vector3(50.0f, -25.0f, 0.0f) );

		// Setup sphere controllers.
		_scriptSphere = _synkro->GetAnimationSystem()->CreateScript( L"float t = FREQ*time+PHASE; return AMP*(t-floor(t));" );
		_scriptSphere->DeclareParam( L"AMP", AnimationDataType::Float );
		_scriptSphere->DeclareParam( L"FREQ", AnimationDataType::Float );
		_scriptSphere->DeclareParam( L"PHASE", AnimationDataType::Float );
		_scriptSphere->Prepare();

		AnimateSphere( _sphere, _scriptSphere,  2.0f, 1.0f, 0.0f );
		AnimateSphere( _sphere2, _scriptSphere, 3.0f, 1.5f, 2.0f );
		AnimateSphere( _sphere3, _scriptSphere, 1.5f, 2.5f, 0.5f );
		AnimateSphere( _sphere4, _scriptSphere, 2.5f, 2.0f, 1.5f );
		AnimateSphere( _sphere5, _scriptSphere, 1.0f, 3.0f, 1.0f );

		// Animate materials.
		_scriptMat = _synkro->GetAnimationSystem()->CreateScript( L"float f = 0.5+0.5*sin(5.0*time); return lerp(COLOR1, COLOR2, f);" );
		_scriptMat->DeclareParam( L"COLOR1", AnimationDataType::Color );
		_scriptMat->DeclareParam( L"COLOR2", AnimationDataType::Color );
		_scriptMat->Prepare();

		AnimateMaterial( _material, _scriptMat, Color::KiwiBrown, Color::KiwiGreen );
		AnimateMaterial( _material2, _scriptMat, Color::DarkOrange, Color::Blue );
		AnimateMaterial( _material3, _scriptMat, Color::Red, Color::Yellow );
		AnimateMaterial( _material4, _scriptMat, Color::White, Color::Magenta );
		AnimateMaterial( _material5, _scriptMat, Color::Purple, Color::Cyan );
	}

	void InitView() override
	{
		// Setup camera.
		_camera->SetPosition( Vector3(0.0f, 50.0f, -170.0f) );
		_camera->LookAt( Vector3::Origin );
	}

	IOpaqueMaterial* CreateMaterial( IImage* diffuse )
	{
		IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
		material->GetDiffuseMap()->SetImage( diffuse );
		material->SetTilingHorizontal( 8 );
		material->SetTilingVertical( 8 );
		material->SetSpecularPower( 10.0f );
		return material;
	}

	void AnimateSphere( ITriangleMesh* sphere, IExpressionScript* script, Float amplitude, Float frequency, Float phase )
	{
		IExpressionScript* scriptClone = script->Clone();
		ExpressionParam* paramAmplitude = scriptClone->GetParam( L"AMP" );
		scriptClone->SetParamValue( paramAmplitude, amplitude );
		ExpressionParam* paramFreq = scriptClone->GetParam( L"FREQ" );
		scriptClone->SetParamValue( paramFreq, frequency );
		ExpressionParam* paramPhase = scriptClone->GetParam( L"PHASE" );
		scriptClone->SetParamValue( paramPhase, phase );

		INodeAnimationController* ctrl = sphere->CreateAnimationController( nullptr, nullptr );
		ctrl->CreateOrientationYawTrack( scriptClone );
		ctrl->CreateScaleUniformTrack( scriptClone );
		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );
	}

	void AnimateMaterial( IOpaqueMaterial* material, IExpressionScript* script, const Color& color1, const Color& color2 )
	{
		IExpressionScript* scriptClone = script->Clone();
		ExpressionParam* paramColor1 = scriptClone->GetParam( L"COLOR1" );
		scriptClone->SetParamValue( paramColor1, color1 );
		ExpressionParam* paramColor2 = scriptClone->GetParam( L"COLOR2" );
		scriptClone->SetParamValue( paramColor2, color2 );

		ISimpleMaterialAnimationController* ctrl = material->CreateAnimationController( nullptr, nullptr )->AsSimple();
		ctrl->CreateDiffuseColorTrack( scriptClone );
		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );
	}

private:
	PtrDirectLight											_light;

	PtrOpaqueMaterial										_material;
	PtrOpaqueMaterial										_material2;
	PtrOpaqueMaterial										_material3;
	PtrOpaqueMaterial										_material4;
	PtrOpaqueMaterial										_material5;
	PtrExpressionScript										_scriptMat;

	PtrTriangleMesh											_sphere;
	PtrTriangleMesh											_sphere2;
	PtrTriangleMesh											_sphere3;
	PtrTriangleMesh											_sphere4;
	PtrTriangleMesh											_sphere5;
	PtrExpressionScript										_scriptSphere;
};

SYNKRO_DEMO_BEGIN
	ExpressYourself demo;
	demo.Run();
SYNKRO_DEMO_END
