#ifndef __APP__
#define __APP__


#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class App :
	public core::SynkroListener,
	public anim::AnimationListener,
	public input::KeyboardListener,
	public input::MouseListener,
	public input::ArcballListener,
	public ui::UiListener
{
public:
	// Constructor.
	App();

	// Runs the application.
	void													Run();

	// SynkroListener methods.
	void													OnSynkroInitialize();
	void													OnSynkroUpdate( Double delta );
	Bool													OnSynkroException( const lang::Exception& ex );

	// AnimationListener methods.
	void													OnAnimationStop( anim::IAnimationController* sender );
	void													OnAnimationLoop( anim::IAnimationController* sender );

	// KeyboardListener methods.
	Bool													ListenKeyboardInput() const;
	Bool													OnKeyboardKeyDown( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyUp( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyPress( UInt device, Char key );

	// MouseListener methods.
	Bool													ListenMouseInput() const;
	Bool													OnMouseClick( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseDoubleClick( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseButtonDown( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseButtonUp( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseAxisMove( UInt device, const input::Axis& axis, Int delta );

	// ArcballListener methods.
	Bool													ListenArcballInput() const;
	Bool													OnArcballOriented( const math::Quaternion& orientation );
	Bool													OnArcballZoom( Int delta );

	// UiListener methods.
	Bool													OnUiClick( ui::IWidget* sender );
	Bool													OnUiDoubleClick( ui::IWidget* sender );
	Bool													OnUiValueChanged( ui::IWidget* sender );

private:
	enum
	{
		TV_COUNT = 4,
	};

	Double													_deltaTime;
	Float													_orgFov;
	Bool													_running;
	gfx::DisplayMode										_displayModeWindowed;
	gfx::DisplayMode										_displayModeFullscreen;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrFrameRenderWindowEx									_window;

	PtrSceneEx												_sceneTV;
	PtrCamera												_cameraTV;
	PtrViewport												_viewportTV;
	PtrViewportFilter										_filterGrayscale;
	PtrDirectLight											_sun;
	PtrOpaqueMaterial										_materialEarth;
	PtrTriangleMesh											_earth;
	PtrText													_txt;

	Bool													_day;
	PtrSceneEx												_scene;
	PtrConeSound											_sound;
	PtrCamera												_camera;
	PtrViewport												_viewport;
	PtrDirectLight											_light;
	PtrOpaqueMaterial										_materialFloor;
	PtrTriangleMesh											_floor;
	PtrOpaqueMaterial										_materialScreen;
	PtrTriangleMeshBatch									_tv;
	PtrTriangleMeshBatch									_screen;
	PtrTriangleMesh											_tvSets[TV_COUNT];
	PtrTriangleMesh											_screens[TV_COUNT];
	PtrText													_txtHelp;
	PtrText													_txtHints;

	PtrButton												_btnLoadAnimation;
	PtrButton												_btnStartRecording;
	PtrButton												_btnStopRecording;
	PtrButton												_btnPlayAnimation;

	PtrAnimationSet											_animationSet;
	PtrAnimation											_animation;
	PtrCameraRecordController								_ctrlRecord;
	PtrStream												_animStream;

	void													Configure();
	void													InitVirtualScene();
	void													InitScene();
	void													InitView();
	void													InitOverlay();
	void													InitInput();
	void													InitUi();
	ui::IButton*											CreateButton( const lang::Point& location, const lang::String& text, const ui::Anchor& anchor, const ui::HotKey& hotkey );
	img::IImage*											GetImage( const lang::String& name );
	io::IStream*											GetStream( const lang::String& name );
	void													ToggleFullscreen();
};


#endif // __APP__
