#include "../Demo.h"


class FourthDimension :
	public Demo
{
public:
	FourthDimension() :
		Demo( L"Fourth Dimension" ),
		_paramSpeed1( nullptr ),
		_paramSpeed2( nullptr )
	{
	}

	void InitScene() override
	{
		// Create 4D cube.
		CreateCube();

		// Rotate cube in XY and ZW planes.
		String expr( L"float ta = SPEED1*time; float sa = sin(ta); float ca = cos(ta); " );
		expr = expr.Append( L"float tb = SPEED2*time; float sb = sin(tb); float cb = cos(tb); " );
		expr = expr.Append( L"return matrix4x4(ca, -sa, 0.0, 0.0, sa, ca, 0.0, 0.0, 0.0, 0.0, cb, -sb, 0.0, 0.0, sb, cb);" );
		_script = _synkro->GetAnimationSystem()->CreateScript( expr );
		_paramSpeed1 = _script->DeclareParam( L"SPEED1", AnimationDataType::Float );
		_paramSpeed2 = _script->DeclareParam( L"SPEED2", AnimationDataType::Float );
		_script->SetParamValue( _paramSpeed1, 1.0f );
		_script->SetParamValue( _paramSpeed2, 1.0f );
		IPrimitiveAnimationController* ctrl = _cube->GetSubset(0)->CreateAnimationController( nullptr, nullptr );
		ctrl->CreateTransformTrack( _script );
		ctrl->SetMode( AnimationMode::Loop );
		ctrl->Start( true );
	}

	void InitView() override
	{
		// Setup camera and viewport.
		_viewport->SetColor( Color::Black );
		_camera->SetPosition( Vector3(-6.0f, 6.0f, -6.0f) );
		_camera->LookAt( Vector3::Origin );

		// Setup post-processing filters.
		_blurFilter = _viewport->CreateFilter( ViewportFilter::Blur )->AsKernel3x3();
		_blurFilter->SetPassCount( 5 );

		_contrastFilter = _viewport->CreateFilter( ViewportFilter::Contrast )->AsSimple();
		_contrastFilter->SetValue( 15.0f );
	}

	void InitUi() override
	{
		_labelSpeed1 = CreateLabel( Point(_widgetLeft, 120), L"Speed XY: 1.500" );
		_sliderSpeed1 = CreateSlider( none, Point(_widgetLeft, 140), 0, 3000, 1500 );

		_labelSpeed2 = CreateLabel( Point(_widgetLeft, 160), L"Speed ZW: 1.500" );
		_sliderSpeed2 = CreateSlider( none, Point(_widgetLeft, 180), 0, 3000, 1500 );
	}

	// UiListener methods.
	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		if ( sender == _sliderSpeed1 )
		{
			const Float speed = SliderPositionToLabel( _sliderSpeed1, _labelSpeed1, L"Speed XY: " );
			_script->SetParamValue( _paramSpeed1, speed );
			return true;
		}
		else if ( sender == _sliderSpeed2 )
		{
			const Float speed = SliderPositionToLabel( _sliderSpeed2, _labelSpeed2, L"Speed ZW: " );
			_script->SetParamValue( _paramSpeed2, speed );
			return true;
		}

		return false;
	}

	// ArcballListener methods.
	Bool ListenArcballInput() const override
	{
		return true;
	}

	Bool OnArcballOriented( const Quaternion& orientation ) override
	{
		_cube->SetOrientation( orientation );
		return true;
	}

	void CreateCube()
	{
		_cube = _scene->CreateLineMesh( nullptr, L"Cube" );
		_cube->CreateLineList4D( L"Cube", 16, 64, false, ColorMode::Colored, Matrix4x4::Identity );
		ILineSet* cube = _cube->GetSubset( 0 )->AsLineSet();

		// Set positions.
		constexpr Float s = 0.5f;
		Vector4 positions[16] =
		{
			Vector4( s, s, s, s ),
			Vector4( -s, s, s, s ),
			Vector4( s, -s, s, s ),
			Vector4( -s, -s, s, s ),
			Vector4( s, s, -s, s ),
			Vector4( -s, s, -s, s ),
			Vector4( s, -s, -s, s ),
			Vector4( -s, -s, -s, s ),
			Vector4( s, s, s, -s ),
			Vector4( -s, s, s, -s ),
			Vector4( s, -s, s, -s ),
			Vector4( -s, -s, s, -s ),
			Vector4( s, s, -s, -s ),
			Vector4( -s, s, -s, -s ),
			Vector4( s, -s, -s, -s ),
			Vector4( -s, -s, -s, -s ),
		};
		cube->SetPositions( positions, 0, 16 );

		// Paint internal and external cubes with complementary colors.
		Color colors[16] = {};
		for ( UInt i = 0; i < 16; ++i )
		{
			colors[i] = (i < 8) ? Color::Red : Color::Yellow;
		}
		cube->SetColors( colors, 0, 16 );

		// Set indices.
		UInt indices[64] =
		{
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
			0, 2, 1, 3, 4, 6, 5, 7, 8, 10, 9, 11, 12, 14, 13, 15,
			0, 4, 1, 5, 2, 6, 3, 7, 8, 12, 9, 13, 10, 14, 11, 15,
			0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15,
		};
		cube->SetIndices( indices, 0, 64 );
	}

	Float SliderPositionToLabel( ISlider* slider, ILabel* label, const Char* prefix )
	{
		label->SetText( String::Format(L"{0}{1,0.000}", prefix, CastDouble((slider->GetPosition()*0.001f))) );
		return CastFloat(slider->GetPosition()) * 0.001f;
	}

private:
	PtrKernel3x3Filter										_blurFilter;
	PtrSimpleFilter											_contrastFilter;

	PtrLineMesh												_cube;
	PtrExpressionScript										_script;
	ExpressionParam*										_paramSpeed1;
	ExpressionParam*										_paramSpeed2;

	PtrLabel												_labelSpeed1;
	PtrSlider												_sliderSpeed1;

	PtrLabel												_labelSpeed2;
	PtrSlider												_sliderSpeed2;
};

SYNKRO_DEMO_BEGIN
	FourthDimension demo;
	demo.Run();
SYNKRO_DEMO_END
