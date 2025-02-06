//==============================================================================
// Purpose: Defines base demo application.
//==============================================================================
#ifndef __DEMO__
#define __DEMO__


#include <synkro.h>


// Demo entry point.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKRO_DEMO_BEGIN														\
	int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR cmd, int )					\
	{																				\
		SynkroMemoryInit( "synkro.mem", true, "_DemoMemory.html", false, false );	\
		SynkroProfileInit( "synkro.prf", true, "_DemoProfile.html", false, false );	\
		Demo::EditConfig( _strcmpi(cmd, "cfg") == 0 );

#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
#	define SYNKRO_DEMO_BEGIN														\
	int main( int argc, char* cmd[] )												\
	{																				\
		SynkroMemoryInit( "synkro.mem", true, "_DemoMemory.html", false, false );	\
		SynkroProfileInit( "synkro.prf", true, "_DemoProfile.html", false, false );

#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

#	define SYNKRO_DEMO_END	\
		return 0;			\
	}


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::db;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::scene;
using namespace synkro::sound;
using namespace synkro::ui;
using namespace synkro::view;
using namespace synkro::win;
using namespace synkro;

//------------------------------------------------------------------------------


// Base demo application.
class Demo :
	public SynkroListener,
	public KeyboardListener,
	public MouseListener,
	public ArcballListener,
	public AnimationListener,
	public UiListener,
	public WindowListener
{
public:
	// Initializes SDK and demo.
	Demo( const Char* title );

	// Instructs demo to show configuration editor before running.
	static void												EditConfig( Bool edit );

	// Terminates the demo.
	void													Exit();

	// Runs the demo.
	void													Run();

protected:
	virtual void											Configure( IConfiguration* config ) {}
	virtual DebugMode										GetDebugMode() const;
	virtual Bool											IsLit() const;
	virtual void											InitInput() {}
	virtual void											InitScene() {}
	virtual void											InitView() {}
	virtual void											InitUi() {}
	virtual void											OnDisplayModeChanged( const DisplayMode& displayMode ) {}
	virtual void											OnCredits( Bool active ) {}

	// SynkroListener methods.
	virtual void											OnSynkroInitialize();
	virtual void											OnSynkroUpdate( Double delta );
	virtual Bool											OnSynkroException( const Exception& ex );

	// KeyboardListener methods.
	virtual Bool											ListenKeyboardInput() const;
	virtual Bool											OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control );
	virtual Bool											OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control );
	virtual Bool											OnKeyboardKeyPress( UInt device, Char key );

	// MouseListener methods.
	virtual Bool											ListenMouseInput() const;
	virtual Bool											OnMouseClick( UInt device, const MouseButton& buttons );
	virtual Bool											OnMouseDoubleClick( UInt device, const MouseButton& buttons );
	virtual Bool											OnMouseButtonDown( UInt device, const MouseButton& buttons );
	virtual Bool											OnMouseButtonUp( UInt device, const MouseButton& buttons );
	virtual Bool											OnMouseAxisMove( UInt device, const Axis& axis, Int delta );

	// ArcballListener methods.
	virtual Bool											ListenArcballInput() const;
	virtual Bool											OnArcballOriented( const Quaternion& orientation );
	virtual Bool											OnArcballZoom( Int delta );

	// AnimationListener methods.
	virtual void											OnAnimationStop( IAnimationController* sender );
	virtual void											OnAnimationLoop( IAnimationController* sender );

	// UiListener methods.
	virtual Bool											OnUiClick( IWidget* sender );
	virtual Bool											OnUiDoubleClick( IWidget* sender );
	virtual Bool											OnUiValueChanged( IWidget* sender );

	// WindowListener methods.
	virtual void											OnWindowResize( UInt window, UInt width, UInt height );
	virtual void											OnWindowCommand( UInt window, UInt command );
	virtual void											OnWindowActivate( UInt window, Bool active );
	virtual Bool											OnWindowClosing( UInt window );

	// Demo methods.
	ITriangleMesh*											CreateTorus( INode* parent, IVisualMaterial* material, Float radiusMinor, Float radiusMajor, UInt ringCount, UInt sideCount, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateCone( INode* parent, IVisualMaterial* material, Float radius, Float height, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateCylinder( INode* parent, IVisualMaterial* material, Float radius, Float height, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateEllipsoid( INode* parent, IVisualMaterial* material, Float radiusX, Float radiusY, Float radiusZ, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateSphere( INode* parent, IVisualMaterial* material, Float radius, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreatePyramid( INode* parent, IVisualMaterial* material, Float width, Float depth, Float height, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateBox( INode* parent, IVisualMaterial* material, Float width, Float height, Float depth, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreateCube( INode* parent, IVisualMaterial* material, Float side, const Matrix4x4& transform, const Vector3& position );
	ITriangleMesh*											CreatePlane( INode* parent, IVisualMaterial* material, Float width, Float depth, UInt segmentCount, const Matrix4x4& transform, const Vector3& position );
	IAngle*													CreateAngle( UInt id, const Point& location, const Color& color );
	IAngle*													CreateAngle( UInt id, const Point& location );
	IButton*												CreateButton( UInt id, const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey, const Color& color );
	IButton*												CreateButton( UInt id, const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey );
	IButton*												CreateButton( const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey );
	IButton*												CreateButton( const Point& location, const String& text, const Anchor& anchor );
	IButton*												CreateButton( const Point& location, const String& text );
	IEdit*													CreateEdit( const Point& location, const String& text );
	ILabel*													CreateLabel( const Point& location, const Size& size, const String& text );
	ILabel*													CreateLabel( const Point& location, const String& text );
	ISlider*												CreateSlider( UInt id, const Point& location, UInt minPosition, UInt maxPosition, UInt position, const Color& color );
	ISlider*												CreateSlider( UInt id, const Point& location, UInt minPosition, UInt maxPosition, UInt position );
	IOption*												CreateOption( UInt id, const Point& location, const String& text, Pointer data, Bool selected, const Color& color );
	IOption*												CreateOption( UInt id, const Point& location, const String& text, Pointer data, Bool selected );
	ISwitch*												CreateSwitch( UInt id, const Point& location, UInt width, const String& text, Bool on );
	ISwitch*												CreateSwitch( const Point& location, UInt width, const String& text, Bool on );
	IDropList*												CreateDropList( const Point& location, const Size& size );
	IImage*													GetImage( const String& name, const PixelFormat& format );
	IImage*													GetImage( const String& name );
	IImage*													GetImage( IStream* stream, const PixelFormat& format );
	IImage*													GetImage( IStream* stream );
	IImage*													GetImage( IStreamSet* streams );
	IStream*												GetStream( const String& name );
	IStreamSet*												GetStreams( const String& dirName, const String& pattern );

	Bool													_running;
	Float													_orgFov;
	Int														_widgetLeft;
	DisplayMode												_displayModeWindowed;
	DisplayMode												_displayModeFullscreen;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrFrameRenderWindowEx									_window;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrViewport												_viewport;

	PtrText													_txtDevice;
	PtrText													_txtDisplayMode;
	PtrText													_txtStats;
	PtrButton												_btnFullscreen;
	PtrButton												_btnCredits;
	PtrButton												_btnExit;
	String													_title;

	PtrPlainRenderTexture									_shotTexture;
	PtrStream												_shotStream;
	PtrImage												_shot;

	PtrSound2D												_soundCredits;
	PtrFont													_fontCredits;
	PtrTextPool												_poolCredits;
	PtrTextPoolAnimationController							_poolCreditsCtrl;

private:
	static Bool												s_editConfig;

	void													ConfigureInternal();
	void													InitViewInternal();
	void													InitUiInternal();
	void													InitInputInternal();
	void													ToggleFullscreen();
	void													CreateCredits();
	void													ShowCredits( Bool show );
	void													CreateShotTexture();
	String													GetShotName();
};


#endif // __DEMO__
