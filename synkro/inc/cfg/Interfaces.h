//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Preliminary declarations of Synkro interfaces.
//=============================================================================
namespace synkro
{


namespace anim
{

iface AnimationListener;
iface ExpressionParam;
iface IAnimation;
iface IAnimationBoolTrack;
iface IAnimationCodec;
iface IAnimationCodecFactory;
iface IAnimationColorGradientTrack;
iface IAnimationColorTrack;
iface IAnimationController;
iface IAnimationFloatRectTrack;
iface IAnimationFloatTrack;
iface IAnimationIntTrack;
iface IAnimationMatrix4x4Track;
iface IAnimationPointTrack;
iface IAnimationQuaternionTrack;
iface IAnimationRangeTrack;
iface IAnimationRectTrack;
iface IAnimationSet;
iface IAnimationSizeTrack;
iface IAnimationSystem;
iface IAnimationTrack;
iface IAnimationTrackFactory;
iface IAnimationVector3Track;
iface IExpressionBoolTrack;
iface IExpressionColorGradientTrack;
iface IExpressionColorTrack;
iface IExpressionFloatRectTrack;
iface IExpressionFloatTrack;
iface IExpressionIntTrack;
iface IExpressionMatrix4x4Track;
iface IExpressionPointTrack;
iface IExpressionQuaternionTrack;
iface IExpressionRangeTrack;
iface IExpressionRectTrack;
iface IExpressionScript;
iface IExpressionSizeTrack;
iface IExpressionVector3Track;
iface IKeyframedBoolTrack;
iface IKeyframedColorGradientTrack;
iface IKeyframedColorTrack;
iface IKeyframedFloatRectTrack;
iface IKeyframedFloatTrack;
iface IKeyframedIntTrack;
iface IKeyframedMatrix4x4Track;
iface IKeyframedPointTrack;
iface IKeyframedQuaternionTrack;
iface IKeyframedRangeTrack;
iface IKeyframedRectTrack;
iface IKeyframedSizeTrack;
iface IKeyframedVector3Track;
iface INoiseFloatTrack;
iface IPlaybackAnimationController;
iface IProceduralBoolTrack;
iface IProceduralColorGradientTrack;
iface IProceduralColorTrack;
iface IProceduralFloatRectTrack;
iface IProceduralFloatTrack;
iface IProceduralIntTrack;
iface IProceduralMatrix4x4Track;
iface IProceduralPointTrack;
iface IProceduralQuaternionTrack;
iface IProceduralRangeTrack;
iface IProceduralRectTrack;
iface IProceduralSizeTrack;
iface IProceduralVector3Track;
iface IRecordAnimationController;
iface IWaveFloatTrack;

} // anim

namespace audio
{

iface IAudioBuffer;
iface IAudioChunk;
iface IAudioEnvironment;
iface IAudioPlayer;
iface IAudioRecorder;
iface IAudioSystem;
iface IAudioSystemEx;
iface IAudioSystemFactory;
iface ISoundBuffer;
iface ISoundEmitter;
iface ISoundListener;
iface IVoiceBuffer;

} // audio

namespace cons
{

iface IConsole;
iface IConsoleCommand;
iface IConsoleCommandFactory;

} // cons

namespace core
{

iface IConfiguration;
iface IConstraint;
iface IContext;
iface IContextEx;
iface IController;
iface IFactory;
iface ILibrary;
iface INodeList;
iface IObject;
iface IResource;
iface IStringList;
iface ISynkro;
iface ISystem;
iface ITriangleMeshList;
iface Param;
iface ParamConstraint;
iface ParamType;
iface ProgressListener;
iface SynkroListener;
iface Task;
iface TimerListener;

} // core

namespace db
{

iface IDatabase;
iface IDatabaseQuery;
iface IDatabaseSystem;
iface IDatabaseSystemEx;
iface IDatabaseSystemFactory;
iface IDataCursor;
iface IDataFilter;
iface IDataTable;
iface IDeleteQuery;
iface IInsertQuery;
iface ISelectQuery;
iface ITableIndex;
iface IUpdateQuery;

} // db

namespace diag
{

iface IDiag;
iface ILog;
iface LogListener;

} // diag

namespace gfx
{

iface IBlendState;
iface IBlendStateSet;
iface IBuffer;
iface ICubeDepthTexture;
iface ICubeRenderMap;
iface ICubeRenderTexture;
iface ICubeTexture;
iface IDataBuffer;
iface IDataBufferSet;
iface IDataFormat;
iface IDataFormatEx;
iface IDataStream;
iface IDepthStencilState;
iface IDepthTexture;
iface IFloatStream;
iface IFrameRenderWindow;
iface IFrameRenderWindowEx;
iface IGraphicsDevice;
iface IGraphicsDeviceEx;
iface IGraphicsSystem;
iface IGraphicsSystemEx;
iface IGraphicsSystemFactory;
iface IIndexBuffer;
iface ILinearRenderTexture;
iface ILinearTexture;
iface ILineRenderObject;
iface ILineRenderQueue;
iface ILongStream;
iface IMatrix4x4Stream;
iface IOverlayRenderObject;
iface IOverlayRenderQueue;
iface IParameterSet;
iface IPlainDepthTexture;
iface IPlainRenderMap;
iface IPlainRenderTexture;
iface IPlainTexture;
iface IPostProcessRenderObject;
iface IPostProcessRenderQueue;
iface IPrimitive;
iface IPrimitiveEx;
iface IProgram;
iface IProgramStage;
iface IRasterizerState;
iface IRect;
iface IRenderMap;
iface IRenderObject;
iface IRenderQueue;
iface IRenderState;
iface IRenderTexture;
iface IRenderTextureSet;
iface IRenderView;
iface IRenderWindow;
iface IResource;
iface IResourceSet;
iface ISamplerState;
iface ISamplerStateSet;
iface ISceneRenderObject;
iface ISceneRenderQueue;
iface IShortStream;
iface ISkyRenderObject;
iface IStructuredBuffer;
iface ITexture;
iface ITypedBuffer;
iface IVector2Stream;
iface IVector3Stream;
iface IVector4Stream;
iface IViewRenderWindow;
iface IViewRenderWindowEx;
iface IVirtualRenderWindow;
iface IVolumeRenderTexture;
iface IVolumeTexture;
iface ProgramParam;

} // gfx

namespace img
{

iface IImage;
iface IImageCodec;
iface IImageCodecFactory;
iface IImageManager;
iface ImageCodecContext;

} // img

namespace input
{

iface ArcballListener;
iface IArcball;
iface IInputDevice;
iface IInputSystem;
iface IInputSystemEx;
iface IInputSystemFactory;
iface IJoystick;
iface IJoystickEx;
iface IKeyboard;
iface IKeyboardEx;
iface IMouse;
iface IMouseEx;
iface JoystickListener;
iface KeyboardListener;
iface MouseListener;

} // input

namespace io
{

iface IStream;
iface IStreamDirectory;
iface IStreamDirectoryFactory;
iface IStreamSet;
iface IStreamSystem;
iface IStreamSystemEx;
iface IStreamSystemFactory;

} // io

namespace mat
{

iface IMaterialManager;
iface IMaterialMap;
iface IMultiMaterial;
iface IOpaqueMaterial;
iface ISimpleMaterial;
iface ISimpleMaterialAnimationController;
iface ITransparentMaterial;
iface ITransparentMaterialAnimationController;
iface IVisualMaterial;
iface IVisualMaterialAnimationController;

} // mat

namespace net
{

iface INetworkDevice;
iface INetworkDeviceEx;
iface INetworkPeer;
iface INetworkSystem;
iface INetworkSystemEx;
iface INetworkSystemFactory;
iface NetworkListener;
iface NetworkMessage;

} // net

namespace over
{

iface IFont;
iface IOverlay;
iface IOverlayManager;
iface IPolyLine;
iface IQuad;
iface ISprite;
iface ISpriteAnimationController;
iface ISpritePool;
iface IText;
iface ITextAnimationController;
iface ITextPool;
iface ITextPoolAnimationController;

} // over

namespace scene
{

iface IBone;
iface ICamera;
iface ICameraAnimationController;
iface ICameraRecordController;
iface IConeLight;
iface IConeLightAnimationController;
iface IConeSound;
iface ICurve;
iface IDirectLight;
iface IFog;
iface IFogAnimationController;
iface ILight;
iface ILightAnimationController;
iface ILineMesh;
iface ILineMeshBatch;
iface ILineSet;
iface ILineSetAnimationController;
iface ILookAtConstraint;
iface IMesh;
iface IMeshBatchAnimationController;
iface IMeshBuilder;
iface IMeshBuilderFactory;
iface IMeshCodec;
iface IMeshCodecFactory;
iface INode;
iface INodeAnimationController;
iface INodeRecordController;
iface IOmniLight;
iface IOmniLightAnimationController;
iface IOmniSound;
iface IParentConstraint;
iface IPointMesh;
iface IPointMeshBatch;
iface IPointSet;
iface IPointSetAnimationController;
iface IPrimitive;
iface IPrimitiveAnimationController;
iface IScene;
iface ISceneAnimationController;
iface ISceneEx;
iface ISceneFactory;
iface ISceneManager;
iface ISkeleton;
iface ISkeletonAnimationController;
iface ISound;
iface ISoundAnimationController;
iface ITriangleMesh;
iface ITriangleMeshBatch;
iface ITriangleSet;

} // scene

namespace script
{

iface IScriptMachine;
iface IScriptObject;
iface IScriptSystem;
iface IScriptSystemEx;
iface IScriptSystemFactory;
iface ScriptMethod;
iface ScriptParam;
iface ScriptParamType;

} // script

namespace sound
{

iface IMusic;
iface IMusicAnimationController;
iface ISound2D;
iface ISound3D;
iface ISoundCodec;
iface ISoundCodecFactory;
iface ISoundManager;
iface IVoice;
iface SoundCodecContext;

} // sound

namespace ui
{

iface IAccordion;
iface IAngle;
iface IButton;
iface ICursor;
iface IDropList;
iface IEdit;
iface IFrame;
iface ILabel;
iface IList;
iface IOption;
iface IPicture;
iface IProgress;
iface ISlider;
iface ISwitch;
iface ITheme;
iface IUi;
iface IUiEx;
iface IUiFactory;
iface IWidget;
iface UiListener;

} // ui

namespace view
{

iface IColorFilter;
iface IColorFilterAnimationController;
iface IDepthFilter;
iface IDepthMap;
iface IDepthOfFieldFilter;
iface IEmbossFilter;
iface IEmbossFilterAnimationController;
iface IFogFilter;
iface IFogFilterAnimationController;
iface IKernel3x3Filter;
iface IKernel3x3FilterAnimationController;
iface ILightFilter;
iface IMotionBlurFilter;
iface ISimpleFilter;
iface ISimpleFilterAnimationController;
iface IViewport;
iface IViewportAnimationController;
iface IViewportFilter;
iface IViewportFilterAnimationController;
iface IViewportFilterFactory;
iface IViewportManager;
iface IViewportTransitionController;
iface ViewportListener;

} // view

namespace win
{

iface IFrameWindow;
iface IFrameWindowEx;
iface IIconWindow;
iface IMonitor;
iface IViewWindow;
iface IViewWindowEx;
iface IWindow;
iface IWindowSystem;
iface IWindowSystemEx;
iface IWindowSystemFactory;
iface WindowListener;

} // win


} // synkro
