#include <gfx/IBlendState.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>
#include <gfx/ISamplerState.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IPrimitive.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/IOverlayRenderObject.h>
#include <gfx/IPostProcessRenderObject.h>
#include <gfx/IProgram.h>
#include <gfx/IParameterSet.h>
#include <gfx/ITexture.h>
#include <gfx/GraphicsException.h>
#include <gfx/GraphicsSystemEx.h>
#include <gfx/IRenderWindow.h>
#include <gfx/IGraphicsSystemFactory.h>
#include <gfx/IShortStream.h>
#include <gfx/IFloatStream.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IMatrix4x4Stream.h>
#include <gfx/GraphicsStats.h>
#include <gfx/GraphicsSystem.h>
#include <io/IStreamSystemFactory.h>
#include <io/StreamSystemEx.h>
#include <io/FileStream.h>
#include <io/IStream.h>
#include <img/Image.h>
#include <img/ImageManager.h>
#include <img/ImageCodec/BmpImageCodecFactory.h>
#include <img/ImageCodec/JpgImageCodecFactory.h>
#include <img/ImageCodec/TgaImageCodecFactory.h>
#include <win/WindowSystemEx.h>
#include <win/IWindowSystemFactory.h>
#include <win/WindowListener.h>
#include <core/ObjectImpl.h>
#include <core/SynkroListener.h>
#include <lang/Convert.h>
#include <input/IInputSystemFactory.h>
#include <input/InputSystemEx.h>
#include <input/KeyboardListener.h>
#include <input/MouseListener.h>
#include <input/Key.h>
#include <math/Math.h>
#include <scene/FogType.h>
#include <scene/LightState.h>
#include <internal/Timer.h>
#include <internal/ToVector.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::input;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::scene;
using namespace synkro::win;

//------------------------------------------------------------------------------


// Abstract test item.
class TestItem
{
public:
	// Creates a test.
	TestItem( const String& name ) :
		_name( name )
	{
	}

	virtual ~TestItem()
	{
	}

	virtual void Initialize( io::IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		_streamSystem	= streamSystem;
		_gfxSystem		= gfxSystem;
		_imageManager	= imageManager;
	}

	void InitScene()
	{
		_programScene = _gfxSystem->GetProgram( L"scene" );
		_programSceneParams = _programScene->GetVertexStage()->GetParameters();
		_paramWorld = _programSceneParams->GetParam( L"sp_world" );
		_paramLightAmbient = _programSceneParams->GetParam( L"sp_lightAmbient" );
		_paramLightCount = _programSceneParams->GetParam( L"sp_lightCount" );
		_paramLights = _programSceneParams->GetParam( L"sp_lights" );

		_programViewport = _gfxSystem->GetProgram( L"viewport" );
		_programViewportParams = _programViewport->GetVertexStage()->GetParameters();

		_paramView = _programViewportParams->GetParam( L"sp_view" );
		_paramProj = _programViewportParams->GetParam( L"sp_proj" );
		_paramWorldView = _programViewportParams->GetParam( L"sp_worldView" );
		_paramWorldViewProj = _programViewportParams->GetParam( L"sp_worldViewProj" );

		_paramFog = _programScene->GetFragmentStage()->GetParameters()->GetParam( L"sp_fog" );
	}

	virtual void Uninitialize()
	{
	}

	virtual void Activate( Bool activate )
	{
	}

	virtual void Update()
	{
	}

	virtual void OnKey( const Key& key )
	{
	}

	virtual String State()
	{
		return String::Empty;
	}

	String Name()
	{
		return _name;
	}

	void GenerateNormals( const UShort* indices, ULong indexCount, const Vector3* vertices, Vector3* normals, Bool smooth )
	{
		UShort maxIdx = 0;
		Vector3 pos[3]; Vector3 a; Vector3 b; Vector3 n;
		for ( ULong i = 0; i < indexCount; i += 3 )
		{
			// Remember maximum index.
			if ( maxIdx < indices[i+0] ) { maxIdx = indices[i+0]; }
			if ( maxIdx < indices[i+1] ) { maxIdx = indices[i+1]; }
			if ( maxIdx < indices[i+2] ) { maxIdx = indices[i+2]; }

			// Retrieve face vertices.
			pos[0] = vertices[indices[i+0]];
			pos[1] = vertices[indices[i+1]];
			pos[2] = vertices[indices[i+2]];

			// Calculate face normal.
			a = pos[1] - pos[0];
			b = pos[2] - pos[0];
			n = a ^ b;
			n.Normalize();

			// Save normals.
			normals[indices[i+0]] = n;
			normals[indices[i+1]] = n;
			normals[indices[i+2]] = n;
		}

		// Make normals smooth.
		if ( smooth )
		{
			for ( ULong j = 0; j <= maxIdx; ++j )
			{
				// Calculate average normal for the vertex.
				n.x = n.y = n.z = 0.0f;
				for ( ULong i = 0; i < indexCount; ++i )
				{
					if ( indices[i] == j )
					{
						n += normals[j];
					}
				}
				n.Normalize();

				// Update normals.
				for ( ULong i = 0; i < indexCount; ++i )
				{
					if ( indices[i] == j )
					{
						normals[j] = n;
					}
				}
			}
		}
	}

	IPostProcessRenderObject* CreateFilter( const String& name )
	{
		return CreateFilter( _gfxSystem->GetFrameWindow()->GetView(0), name );
	}

	IPostProcessRenderObject* CreateFilter( gfx::IRenderView* view, const String& name )
	{
		return view->GetPostProcessQueue()->CreateObject( _gfxSystem->GetProgram(name) );
	}

	IOverlayRenderObject* CreateTriangle( IOverlayRenderQueue* queue, IProgram* program, Float left, Float top, Float width, Float height, const IndexType& indexType )
	{
		// Create graphics object.
		IOverlayRenderObject* obj = queue->CreateObject( _gfxSystem->GetDevice()->CreatePrimitive(program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleList, indexType, 3, (indexType == IndexType::None) ? 0 : 3, 0, 0, true, false) );

		// Set positions.
		P(IVector4Stream) streamPos = (IVector4Stream*)obj->GetData()->GetVertexStream( DataStream::Position2D, 0 );
		if ( streamPos->Open(io::OpenMode::Write) )
		{
			Vector4 pos[] =
			{
				Vector4( left+width/2,	top,		0.0f, 1.0f ),
				Vector4( left+width,	height+top,	0.0f, 1.0f ),
				Vector4( left,			height+top,	0.0f, 1.0f ),
			};
			streamPos->Write( pos, 3 );
			streamPos->Close();
		}

		// Set colors.
		P(IVector4Stream) streamCol = (IVector4Stream*)obj->GetData()->GetVertexStream( DataStream::Color, 0 );
		if ( (streamCol != null) && streamCol->Open(io::OpenMode::Write) )
		{
			Vector4 col[] =
			{
				Vector4( 1.0f, 0.0f, 0.0f, 1.0f ),
				Vector4( 0.0f, 1.0f, 0.0f, 1.0f ),
				Vector4( 0.0f, 0.0f, 1.0f, 1.0f ),
			};
			streamCol->Write( col, 3 );
			streamCol->Close();
		}

		// Set texture coordinates.
		P(IVector2Stream) streamTexCoord = (IVector2Stream*)obj->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
		if ( (streamTexCoord != null) && streamTexCoord->Open(io::OpenMode::Write) )
		{
			Vector2 coords[] = 
			{
				Vector2( 0.5f, 0.0f ),
				Vector2( 1.0f, 1.0f ),
				Vector2( 0.0f, 1.0f ),
			};
			streamTexCoord->Write( coords, 3 );
			streamTexCoord->Close();
		}

		// Set indices.
		P(IShortStream) streamIndex = (IShortStream*)obj->GetData()->GetIndexStream();
		if ( (streamIndex != null) && streamIndex->Open(io::OpenMode::Write) )
		{
			UShort indices[] = { 0, 1, 2 };
			streamIndex->Write( indices, 3 );
			streamIndex->Close();
		}

		return obj;
	}

	IOverlayRenderObject* CreateSquare( IOverlayRenderQueue* queue, IProgram* program, Float left, Float top, Float size )
	{
		// Create graphics object.
		IOverlayRenderObject* obj = queue->CreateObject( _gfxSystem->GetDevice()->CreatePrimitive(program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::Short, 4, 4, 0, 0, true, false) );

		// Set positions.
		P(IVector4Stream) streamPos = (IVector4Stream*)obj->GetData()->GetVertexStream( DataStream::Position2D, 0 );
		if ( streamPos->Open(io::OpenMode::Write) )
		{
			Vector4 pos[] =
			{
				Vector4( left,			top,		0.0f, 1.0f ),
				Vector4( left,			size+top,	0.0f, 1.0f ),
				Vector4( left+size,		top,		0.0f, 1.0f ),
				Vector4( left+size,		size+top,	0.0f, 1.0f ),
			};
			streamPos->Write( pos, 4 );
			streamPos->Close();
		}

		// Set colors.
		P(IVector4Stream) streamCol = (IVector4Stream*)obj->GetData()->GetVertexStream( DataStream::Color, 0 );
		if ( (streamCol != null) && streamCol->Open(io::OpenMode::Write) )
		{
			Vector4 col[] =
			{
				Vector4( 1.0f, 0.0f, 0.0f, 1.0f ),
				Vector4( 1.0f, 1.0f, 0.0f, 1.0f ),
				Vector4( 0.0f, 0.0f, 1.0f, 1.0f ),
				Vector4( 0.0f, 1.0f, 0.0f, 1.0f ),
			};
			streamCol->Write( col, 4 );
			streamCol->Close();
		}

		// Set texture coordinates.
		P(IVector2Stream) streamTexCoord = (IVector2Stream*)obj->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
		if ( (streamTexCoord != null) && streamTexCoord->Open(io::OpenMode::Write) )
		{
			Vector2 coords[] = 
			{
				Vector2( 0.0f, 0.0f ),
				Vector2( 0.0f, 1.0f ),
				Vector2( 1.0f, 0.0f ),
				Vector2( 1.0f, 1.0f ),
			};
			streamTexCoord->Write( coords, 4 );
			streamTexCoord->Close();
		}

		// Set indices.
		P(IShortStream) streamIndex = (IShortStream*)obj->GetData()->GetIndexStream();
		if ( (streamIndex != null) && streamIndex->Open(io::OpenMode::Write) )
		{
			UShort indices[] = { 0, 1, 2, 3 };
			streamIndex->Write( indices, 4 );
			streamIndex->Close();
		}

		return obj;
	}

	/*IGraphicsObject* CreatePyramid( IProgram* program, Float size, ULong instanceCount, Vector4* colors, Bool lighting, Bool fogging )
	{
		// Create data buffer.
		IGraphicsObject* obj = _gfxSystem->CreateObject(_gfxSystem->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, PrimitiveType::TriangleList, IndexType::Short, 18, instanceCount, 18, true, false) );

		// Set indices.
		static UShort indices[] =
		{
			0, 2, 1,
			0, 4, 2,
			0, 3, 4,
			0, 1, 3,
			1, 2, 4,
			1, 4, 3,
		};
		P(IShortStream) streamIndex = (IShortStream*)obj->GetData()->GetIndexStream();
		if ( (streamIndex != null) && (streamIndex->Open()) )
		{
			streamIndex->Write( indices, sizeof(indices)/sizeof(indices[0]) );
			streamIndex->Close();
		}

		// Set positions.
		Vector3 pos[] =
		{
			Vector3( 0.0f, size/Math::Sqrt(2.0f), 0.0f ),
			Vector3( -size/2.0f,  0.0f,  size/2.0f ),
			Vector3( -size/2.0f,  0.0f, -size/2.0f ),
			Vector3(  size/2.0f,  0.0f,  size/2.0f ),
			Vector3(  size/2.0f,  0.0f, -size/2.0f ),
		};
		P(IVector3Stream) streamPos = (IVector3Stream*)obj->GetData()->GetVertexStream( DataStream::Position3D, 0 );
		if ( streamPos->Open() )
		{
			streamPos->Write( pos, sizeof(pos)/sizeof(pos[0]) );
			streamPos->Close();
		}

		// Set texure coordinates.
		static Vector2 coords[] = 
		{
			Vector2( 0.5f, 0.5f ),
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
		};
		P(IVector2Stream) streamTex = (IVector2Stream*)obj->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
		if ( streamTex->Open() )
		{
			streamTex->Write( coords, sizeof(coords)/sizeof(coords[0]) );
			streamTex->Close();
		}

		// Set normals.
		static Vector3 normals[5];
		GenerateNormals( indices, sizeof(indices)/sizeof(indices[0]), pos, normals, false );
		P(IVector3Stream) streamNorm = (IVector3Stream*)obj->GetData()->GetVertexStream( DataStream::Normal, 0 );
		if ( streamNorm->Open() )
		{
			streamNorm->Write( normals, sizeof(normals)/sizeof(normals[0]) );
			streamNorm->Close();
		}

		// Set instance colors.
		P(IVector4Stream) streamColor = (IVector4Stream*)obj->GetData()->GetInstanceStream( DataStream::Color, 0 );
		if ( (streamColor != null) && streamColor->Open() )
		{
			streamColor->Write( colors, instanceCount );
			streamColor->Close();
		}

		// Enable lighting.
		P(IFloatStream) streamLighting = (IFloatStream*)obj->GetData()->GetInstanceStream( L"lighting", 0 );
		if ( (streamLighting != null) && streamLighting->Open() )
		{
			streamLighting->Set( lighting ? 1.0f : 0.0f, instanceCount );
			streamLighting->Close();
		}

		// Enable fogging.
		P(IFloatStream) streamFogging = (IFloatStream*)obj->GetData()->GetInstanceStream( L"fogging", 0 );
		if ( (streamFogging != null) && streamFogging->Open() )
		{
			streamFogging->Set( fogging ? 1.0f : 0.0f, instanceCount );
			streamFogging->Close();
		}

		return obj;
	}*/

	ISceneRenderObject* CreateCube( ISceneRenderQueue* queue, IProgram* program, Float size, ULong instanceCount, Vector4* colors, Bool lighting, Bool fogging )
	{
		// Create graphics object.
		ISceneRenderObject* obj = queue->CreateObject( _gfxSystem->GetDevice()->CreatePrimitive(program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleList, IndexType::Short, 24, 36, instanceCount, 0, false, false), false );

		// Set indices.
		static UShort indices[] =
		{
			0,   2,  1,  1,  2,  3,
			4,   5,  6,  5,  7,  6,
			8,   9, 10,  9, 11, 10,
			12, 13, 14, 13, 15, 14,
			16, 17, 18, 17, 19, 18,
			20, 21, 22, 21, 23, 22,
		};
		P(IShortStream) streamIndex = (IShortStream*)obj->GetData()->GetIndexStream();
		if ( (streamIndex != null) && (streamIndex->Open(io::OpenMode::Write)) )
		{
			streamIndex->Write( indices, sizeof(indices)/sizeof(indices[0]) );
			streamIndex->Close();
		}

		// Set positions.
		Vector3 pos[] =
		{
			// Top.
			Vector3( -size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f,  size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3(  size/2.0f,  size/2.0f, -size/2.0f ),

			// Bottom.
			Vector3( -size/2.0f, -size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f, -size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f,  size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f, -size/2.0f ),
			// Left.
			Vector3( -size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f,  size/2.0f, -size/2.0f ),
			Vector3( -size/2.0f, -size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f, -size/2.0f, -size/2.0f ),
			// Right.
			Vector3(  size/2.0f,  size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f,  size/2.0f ),
			// Front.
			Vector3(  size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f,  size/2.0f,  size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f,  size/2.0f ),
			Vector3( -size/2.0f, -size/2.0f,  size/2.0f ),
			// Back.
			Vector3( -size/2.0f,  size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f,  size/2.0f, -size/2.0f ),
			Vector3( -size/2.0f, -size/2.0f, -size/2.0f ),
			Vector3(  size/2.0f, -size/2.0f, -size/2.0f ),
		};
		P(IVector3Stream) streamPos = (IVector3Stream*)obj->GetData()->GetVertexStream( DataStream::Position3D, 0 );
		if ( (streamPos != null) && streamPos->Open(io::OpenMode::Write) )
		{
			streamPos->Write( pos, sizeof(pos)/sizeof(pos[0]) );
			streamPos->Close();
		}

		// Set texure coordinates.
		static Vector2 coords[] = 
		{
			// Top.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
			// Bottom.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
			// Left.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
			// Right.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
			// Front.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
			// Back.
			Vector2( 0.0f, 0.0f ),
			Vector2( 0.0f, 1.0f ),
			Vector2( 1.0f, 0.0f ),
			Vector2( 1.0f, 1.0f ),
		};
		P(IVector2Stream) streamTex = (IVector2Stream*)obj->GetData()->GetVertexStream( DataStream::TexCoord2D, 0 );
		if ( (streamTex != null) && streamTex->Open(io::OpenMode::Write) )
		{
			streamTex->Write( coords, sizeof(coords)/sizeof(coords[0]) );
			streamTex->Close();
		}

		// Set normals.
		Vector3 normals[24];
		GenerateNormals( indices, sizeof(indices)/sizeof(indices[0]), pos, normals, false );
		P(IVector3Stream) streamNorm = (IVector3Stream*)obj->GetData()->GetVertexStream( DataStream::Normal, 0 );
		if ( (streamNorm != null) && streamNorm->Open(io::OpenMode::Write) )
		{
			streamNorm->Write( normals, sizeof(normals)/sizeof(normals[0]) );
			streamNorm->Close();
		}

		// Set instance colors.
		P(IVector4Stream) streamColor = (IVector4Stream*)obj->GetData()->GetInstanceStream( DataStream::Color, 0 );
		if ( (streamColor != null) && streamColor->Open(io::OpenMode::Write) )
		{
			streamColor->Write( colors, instanceCount );
			streamColor->Close();
		}

		/*// Enable lighting.
		P(IFloatStream) streamLighting = (IFloatStream*)obj->GetData()->GetInstanceStream( L"lighting", 0 );
		if ( (streamLighting != null) && streamLighting->Open(io::OpenMode::Write) )
		{
			streamLighting->Set( lighting ? 1.0f : 0.0f, instanceCount );
			streamLighting->Close();
		}

		// Enable fogging.
		P(IFloatStream) streamFogging = (IFloatStream*)obj->GetData()->GetInstanceStream( L"fogging", 0 );
		if ( (streamFogging != null) && streamFogging->Open(io::OpenMode::Write) )
		{
			streamFogging->Set( fogging ? 1.0f : 0.0f, instanceCount );
			streamFogging->Close();
		}*/

		return obj;
	}

	static CullMode GetNext( const CullMode& mode )
	{
		static CullMode modes[] =
		{
			CullMode::None,
			CullMode::Front,
			CullMode::Back,
		};
		static ULong cnt = sizeof(modes)/sizeof(modes[0]);

		ULong idx = mode.Value() - CullMode::None.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return modes[idx];
	}

	static FillMode GetNext( const FillMode& mode )
	{
		static FillMode modes[] =
		{
			FillMode::Wireframe,
			FillMode::Solid,
		};
		static ULong cnt = sizeof(modes)/sizeof(modes[0]);

		ULong idx = mode.Value() - FillMode::Wireframe.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return modes[idx];
	}

	static CompareFunction GetNext( const CompareFunction& function )
	{
		static CompareFunction funcs[] =
		{
			CompareFunction::Never,
			CompareFunction::Less,
			CompareFunction::Equal,
			CompareFunction::LessOrEqual,
			CompareFunction::Greater,
			CompareFunction::NotEqual,
			CompareFunction::GreaterOrEqual,
			CompareFunction::Always,
		};
		static ULong cnt = sizeof(funcs)/sizeof(funcs[0]);

		ULong idx = function.Value() - CompareFunction::Never.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return funcs[idx];
	}

	static BlendMode GetNext( const BlendMode& mode )
	{
		static BlendMode modes[] =
		{
			BlendMode::Zero,
			BlendMode::One,
			BlendMode::SrcColor,
			BlendMode::InvSrcColor,
			BlendMode::SrcAlpha,
			BlendMode::InvSrcAlpha,
			BlendMode::DstAlpha,
			BlendMode::InvDstAlpha,
			BlendMode::DstColor,
			BlendMode::InvDstColor,
			BlendMode::SrcAlphaSat,
		};
		static ULong cnt = sizeof(modes)/sizeof(modes[0]);

		ULong idx = mode.Value() - BlendMode::Zero.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return modes[idx];
	}

	static BlendOperation GetNext( const BlendOperation& op )
	{
		static BlendOperation ops[] =
		{
			BlendOperation::Add,
			BlendOperation::Sub,
			BlendOperation::RevSub,
			BlendOperation::Min,
			BlendOperation::Max,
		};
		static ULong cnt = sizeof(ops)/sizeof(ops[0]);

		ULong idx = op.Value() - BlendOperation::Add.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return ops[idx];
	}

	static TextureFilter GetNext( const TextureFilter& filter )
	{
		static TextureFilter filters[] =
		{
			TextureFilter::Point,
			TextureFilter::Linear,
			TextureFilter::Anisotropic,
			TextureFilter::PyramidalQuad,
			TextureFilter::GaussianQuad,
		};
		static ULong cnt = sizeof(filters)/sizeof(filters[0]);

		ULong idx = filter.Value() - TextureFilter::Point.Value() + 1;
		if ( idx >= cnt )
			idx = 0;

		return filters[idx];
	}

protected:
	String					_name;
	P(io::IStreamSystemEx)	_streamSystem;
	P(IGraphicsSystemEx)	_gfxSystem;
	P(IImageManager)		_imageManager;

	P(IProgram)				_programScene;
	P(IParameterSet)		_programSceneParams;
	ProgramParam*			_paramWorld;

	P(IProgram)				_programViewport;
	P(IParameterSet)		_programViewportParams;
	ProgramParam*			_paramView;
	ProgramParam*			_paramProj;
	ProgramParam*			_paramWorldView;
	ProgramParam*			_paramWorldViewProj;
	ProgramParam*			_paramLightAmbient;
	ProgramParam*			_paramLightCount;
	ProgramParam*			_paramLights;
	ProgramParam*			_paramFog;

	P(IBlendState)			_blendState;
	P(IDepthStencilState)	_depthStencilState;
	P(IRasterizerState)		_rasterizerState;

	FillMode				_fill;
	CullMode				_cull;
	CompareFunction			_function;
	BlendOperation			_blendOp;
	BlendMode				_srcBlend;
	BlendMode				_dstBlend;
	TextureFilter			_texFilter;
	Float					_angle;
	Float					_scale;
	Float					_delta;
	Float					_pos;
};

//------------------------------------------------------------------------------

class OverlayTest :
	public TestItem
{
public:
	OverlayTest() :
	  TestItem( L"Overlays" )
	{
	}

	void Initialize( io::IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup program #1.
		_programCol = gfxSystem->GetProgram( L"overlay.colored" );
		_fill = FillMode::Solid; _cull = CullMode::None;
		_rasterizerState = gfxSystem->GetDevice()->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_depthStencilState = gfxSystem->GetDevice()->GetDepthStencilState()->Clone();
		_depthStencilState->EnableDepth( false );

		// Setup program #2.
		_programTex = gfxSystem->GetProgram( L"overlay.textured" );
		_programTexParams = _programTex->GetFragmentStage()->GetParameters()->Clone( 1000, true );
		ProgramParam* paramTexColor = _programTexParams->GetParam( L"p_color" );
		_programTexParams->Set( paramTexColor, Vector4(1.0f, 1.0f, 1.0f, 1.0f) );

		PixelFormat pixFmt = _gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programTexRes = _programTex->GetFragmentStage()->GetResources()->Clone( 1000 );
		P(io::IStream) streamImage = _streamSystem->GetStream( L"console.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, pixFmt );
		image->Prepare( pixFmt, 1 );
		_programTexRes->Set( 0, image->AsResource() );

		// Setup program #3.
		_programTexCol = gfxSystem->GetProgram( L"overlay.textured.colored" );
		_programTexColRes = _programTexCol->GetFragmentStage()->GetResources()->Clone( 1000 );
		P(io::IStream) streamImage2 = _streamSystem->GetStream( L"earth.jpg" );
		P(IImage) image2 = _imageManager->LoadImage( streamImage2, pixFmt );
		image2->Prepare( pixFmt, 1 );
		_programTexColRes->Set( 0, image2->AsResource() );

		// Enable overlay.
		_gfxSystem->GetFrameWindow()->EnableOverlay();
		IOverlayRenderQueue* overlayQueue = _gfxSystem->GetFrameWindow()->GetOverlayQueue();

		// Create geometry.
		_tri0 = CreateTriangle( overlayQueue, _programTexCol, 170.0f, 200.0f, 200.0f, 200.0f, IndexType::None );
		_tri0->SetFragmentResources( _programTexColRes );

		_tri1 = CreateTriangle( overlayQueue, _programCol, 750.0f, 200.0f, 200.0f, 200.0f, IndexType::Short );

		_tri2 = CreateTriangle( overlayQueue, _programTex, 450.0f, 500.0f, 200.0f, 200.0f, IndexType::None );
		_tri2->SetFragmentParameters( _programTexParams );
		_tri2->SetFragmentResources( _programTexRes );

		_quad0 = CreateSquare( overlayQueue, _programCol, 450.0f, 200.0f, 200.0f );

		_quad1 = CreateSquare( overlayQueue, _programTex, 170.0f, 500.0f, 200.0f );
		_quad1->SetFragmentParameters( _programTexParams );
		_quad1->SetFragmentResources( _programTexColRes );

		_quad2 = CreateSquare( overlayQueue, _programTexCol, 750.0f, 500.0f, 200.0f );
		_quad2->SetFragmentResources( _programTexRes );

		_gfxSystem->GetFrameWindow()->GetView( 0 )->SetBackColor( Vector4(0.0f, 0.2f, 0.4f, 1.0f) );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
	}

	void Activate( Bool activate )
	{
		_tri0->Enable( activate );
		_tri1->Enable( activate );
		_tri2->Enable( activate );
		_quad0->Enable( activate );
		_quad1->Enable( activate );
		_quad2->Enable( activate );
	}

	String State()
	{
		return String::Format( L"[F]illMode: {0}, [C]ullMode: {1}", _fill.ToString(), _cull.ToString() );
	}

private:
	P(IProgram)				_programCol;
	P(IProgram)				_programTex;
	P(IParameterSet)		_programTexParams;
	P(IResourceSet)			_programTexRes;
	P(IProgram)				_programTexCol;
	P(IResourceSet)			_programTexColRes;

	P(IOverlayRenderObject)	_tri0;
	P(IOverlayRenderObject)	_tri1;
	P(IOverlayRenderObject)	_tri2;
	P(IOverlayRenderObject)	_quad0;
	P(IOverlayRenderObject)	_quad1;
	P(IOverlayRenderObject)	_quad2;
};

//------------------------------------------------------------------------------

class TextureTest :
	public TestItem
{
public:
	TextureTest() :
	  TestItem( L"Texturing" )
	{
		_angle = 0.0f;
		_filterEnabled = true;
	}

	void Initialize( io::IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard.textured" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone( 1001, true );
		_paramMaterial = _programMatParams->GetParam( L"p_material" );
		_paramTransform = _programMatParams->GetParam( L"p_transform" );
		_paramColor = _programMatParams->GetParam( L"p_color" );
		/*_paramLighting = _programMatParams->GetParam( L"p_lighting" );
		_paramFogging = _programMatParams->GetParam( L"p_fogging" );*/ 

		_programMatParams->Set( _paramColor, ToVector(Color::White) );
		/*_programMatParams->Set( _paramLighting, false );
		_programMatParams->Set( _paramFogging, false );*/

		_programMatParams2 = _programMatParams->Clone( 1001, true );
		_paramTransform2 = _programMatParams2->GetParam( L"p_transform" );

		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone( 1001 );
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format );
		image->Prepare( format, 0 );
		_programMatRes->Set( 0, image->AsResource() );

		_programMatRes2 = _programMat->GetFragmentStage()->GetResources()->Clone( 1001 );
		P(io::IStream) streamImage2 = _streamSystem->GetStream( L"glass.bmp" );
		P(IImage) image2 = _imageManager->LoadImage( streamImage2, format );
		image2->Prepare( format, 0 );
		_programMatRes2->Set( 0, image2->AsResource() );

		// Setup states.
		_texFilter = TextureFilter::Linear;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone( 1001 );	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		_fill = FillMode::Solid; _cull = CullMode::None;
		_rasterizerState = gfxSystem->GetDevice()->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_function = CompareFunction::LessOrEqual;
		_depthStencilState = gfxSystem->GetDevice()->GetDepthStencilState()->Clone();
		_depthStencilState->SetDepthFunction( _function );
		_depthStencilState->EnableDepth( true );
		_depthStencilState->EnableDepthWrite( true );

		ISceneRenderQueue* queue = _gfxSystem->CreateRenderQueue();
		_gfxSystem->GetFrameWindow()->GetView(0)->SetQueue( queue );

		// Create geometry.
		_cube = CreateCube( queue, _programMat, 16.0f, 0, null, false, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetRasterizerState( _rasterizerState );
		_cube->SetElementRange( 0, 24 );

		_cube2 = queue->CreateObject( _cube->GetData(), false );
		_cube2->SetVertexParameters( _programMatParams2 );
		_cube2->SetFragmentResources( _programMatRes2 );
		_cube2->SetFragmentSamplers( _programMatSamplers );
		_cube2->SetDepthStencilState( _depthStencilState );
		_cube2->SetRasterizerState( _rasterizerState );

		/*// Create post-processing filter.
		_gfxSystem->GetFrameWindow()->GetView(0)->EnablePostProcess();
		_filter = CreateFilter( L"filter.negative" );
		_filter->Enable( _filterEnabled );*/

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programViewportParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::ToRadians(45.0f), 1.0f, 200.0f, 1.0f );
		_programViewportParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programViewportParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programViewportParams->Set( _paramWorldViewProj, matWorldViewProj );

		Matrix4x4 trans;
		trans.SetTranslation( Vector3( -12.0f, 0.0f, 0.0f) );
		_programMatParams->Set( _paramTransform, trans );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::Z )
		{
			_function = GetNext( _function );
			_depthStencilState->SetDepthFunction( _function );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->EnableDepth( !_depthStencilState->IsDepthEnabled() );
		}
		else if ( key == Key::T )
		{
			_texFilter = GetNext( _texFilter );
			_programMatSamplers->Get(0)->SetFilter( _texFilter );
		}
		else if ( key == Key::R )
		{
			if ( _cube->GetFragmentResources() == _programMatRes )
			{
				_cube->SetFragmentResources( _programMatRes2 );
				_cube2->SetFragmentResources( _programMatRes );
			}
			else
			{
				_cube->SetFragmentResources( _programMatRes );
				_cube2->SetFragmentResources( _programMatRes2 );
			}
		}
		else if ( key == Key::X )
		{
			if ( _filterEnabled ) { _filterEnabled = false;}
			else { _filterEnabled = true;}
			_filter->Enable( _filterEnabled );
		}
	}

	void Update()
	{
		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programViewportParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::ToRadians(45.0f), 1.0f, 200.0f, 1.0f );
		_programViewportParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programViewportParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programViewportParams->Set( _paramWorldViewProj, matWorldViewProj );

		Matrix4x4 rot;
		Vector3 axis(0.0f, 1.0f, 0.0f);
		rot.SetOrientation( axis, _angle );
		_angle += 0.004f;

		Matrix4x4 trans;
		trans.SetTranslation( Vector3( -12.0f, 0.0f, 0.0f) );
		trans = rot * trans;
		_programMatParams->Set( _paramTransform, trans );

		//Matrix4x4 trans2;
		//trans2.SetTranslation( Vector3( 12.0f, 10.0f, 0.0f) );
		//trans2 = rot * trans2;
		//_programMatParams2->Set( _paramTransform2, trans2 );
	}

	void Activate( Bool activate )
	{
		_cube->Enable( activate );
		//_cube2->Enable( activate );
		//_filter->Enable( activate && _filterEnabled );
	}

	String State()
	{
		return String::Format( L"[T]extureFilter: {0}, [Z]-Func: {1}", _texFilter.ToString(), _function.ToString() );
	}

private:
	P(ISceneRenderObject)		_cube;
	P(ISceneRenderObject)		_cube2;
	P(IPostProcessRenderObject)	_filter;
	P(IProgram)					_programMat;
	P(IParameterSet)			_programMatParams;
	P(IParameterSet)			_programMatParams2;
	P(IResourceSet)				_programMatRes;
	P(IResourceSet)				_programMatRes2;
	P(ISamplerStateSet)			_programMatSamplers;
	Bool						_filterEnabled;
	
	ProgramParam*			_paramMaterial;
	ProgramParam*			_paramTransform;
	ProgramParam*			_paramTransform2;
	ProgramParam*			_paramColor;
	ProgramParam*			_paramLighting;
	ProgramParam*			_paramFogging;
};

//------------------------------------------------------------------------------

/*class LightTest :
	public TestItem
{
public:
	LightTest() :
	  TestItem( L"Lighting" ),
	  _lights( A(LightState) )
	{
		_angle = 0.0f;
		_scale = 0.33f;
		_pos = 150.0f;
		_delta = 0.25f;
		_lighting = true;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );
		_paramTransform = _programMatParams->GetParam( L"p_transform" );
		_paramColor = _programMatParams->GetParam( L"p_color" );
		_paramLighting = _programMatParams->GetParam( L"p_lighting" );
		_paramFogging = _programMatParams->GetParam( L"p_fogging" ); 

		_programMatParams->Set( _paramColor, ToVector(Color::Blue) );
		_programMatParams->Set( _paramLighting, true );
		_programMatParams->Set( _paramFogging, false );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup states.
		_texFilter = TextureFilter::Point;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		_fill = FillMode::Solid; _cull = CullMode::None;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_function = CompareFunction::Equal;
		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( true );

		// Create geometry.
		_cube = CreateCube( _programMat, 12.0f, 0, null, true, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetRasterizerState( _rasterizerState );

		// Setup material.
		MaterialState mat;
		mat.Diffuse		= ToVector( Color::White );
		mat.Ambient		= ToVector( Color::DarkGray );
		mat.Specular	= ToVector( Color::Black );
		mat.Emissive	= ToVector( Color::Black );
		mat.Power		= 1.0f;
		_programMatParams->Set( _paramMaterial, (const Byte*)&mat, sizeof(MaterialState) );

		// Setup lights.
		LightState light;
		light.Type		= (Float)SourceType::Point.Value();
		light.Diffuse	= ToVector( Color::Yellow );
		light.Ambient	= ToVector( Color::DarkGray );
		light.Specular	= ToVector( Color::Black );
		light.Position	= Vector( _pos, 30.0f, 60.0f, 1.0f );
		light.Direction	= Vector( 0.0f, 0.0f, 1.0f, 1.0f );
		light.Range		= 160.0f;
		light.ConstAttenuation = 0.0f;
		light.LinearAttenuation = 0.01f;
		light.QuadraticAttenuation = 0.0f;
		light.Falloff	= 0.0f;
		light.Theta		= 0.0f;
		light.Phi		= 0.0f;

		_lights.Add( light );

		_programSceneParams->Set( _paramLightAmbient, ToVector(Color::DarkOliveGreen) );
		_programSceneParams->Set( _paramLightCount, (Int)_lights.Size() );

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->Enable( !_depthStencilState->IsEnabled() );
		}
		else if ( key == Key::L )
		{
			_programMatParams->Set( _paramLighting, _lighting = !_lighting );
		}
		else if ( key == Key::T )
		{
			_texFilter = GetNext( _texFilter );
			_programMatSamplers->Get(0)->SetFilter( _texFilter );
		}
	}

	void Update()
	{
		_lights[0].Position = Vector4( _pos, 80.0f, 60.0f, 1.0f );
		_programSceneParams->Set( _paramLights, (const Byte*)_lights.Begin(), sizeof(LightState), _lights.Size() );

		Vector3 axis(0.0f, 1.0f, 0.0f);
		Matrix4x4 trans; Matrix4x4 rot;
		trans.SetTranslation( Vector3( 20.0f, 0.0f, 0.0f) );
		rot.SetRotation( axis, _angle );
		trans = rot * trans;
		trans *= rot;
		_programMatParams->Set( _paramTransform, trans );

		_angle += 0.004f;
		_pos += _delta;
		if ( _pos < -150.0f )
			_delta = 0.25f;
		else if ( _pos > 150.0f )
			_delta = -0.25f;
	}

	void Activate( Bool activate )
	{
		_cube->Enable( activate );
	}

	String State()
	{
		return Format( L"[L]ights: {0}", Convert::ToString(_lighting) );
	}

private:
	P(IGraphicsObject)	_cube;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;
	
	ProgramParam*		_paramMaterial;
	ProgramParam*		_paramTransform;
	ProgramParam*		_paramColor;
	ProgramParam*		_paramLighting;
	ProgramParam*		_paramFogging;

	Vector<LightState>	_lights;
	Bool				_lighting;
};*/

//------------------------------------------------------------------------------

/*class FogTest :
	public TestItem
{
public:
	FogTest() :
	  TestItem( L"Fogging" )
	{
		_angle = 0.0f;
		_scale = 0.33f;
		_pos = 150.0f;
		_delta = 0.25f;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );
		_paramTransform = _programMatParams->GetParam( L"p_transform" );
		_paramColor = _programMatParams->GetParam( L"p_color" );
		_paramLighting = _programMatParams->GetParam( L"p_lighting" );
		_paramFogging = _programMatParams->GetParam( L"p_fogging" ); 

		_programMatParams->Set( _paramColor, ToVector(Color::Blue) );
		_programMatParams->Set( _paramLighting, false );
		_programMatParams->Set( _paramFogging, true );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup states.
		_texFilter = TextureFilter::Point;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		_fill = FillMode::Solid; _cull = CullMode::None;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_function = CompareFunction::Equal;
		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( true );

		// Create geometry.
		_cube = CreateCube( _programMat, 12.0f, 0, null, true, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetRasterizerState( _rasterizerState );

		// Setup fog.
		FogState fog;
		fog.Type		= (Float)FogType::Linear.Value();
		fog.FogColor	= ToVector( Color::Gray );
		fog.Start		= 5.0f;
		fog.End			= 100.0f;
		fog.Density		= 0.025f;
		_programScene->GetFragmentStage()->GetParameters()->Set( _paramFog, (const Byte*)&fog, sizeof(FogState) );

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->Enable( !_depthStencilState->IsEnabled() );
		}
	}

	void Update()
	{
		Vector3 axis(0.0f, 1.0f, 0.0f);
		Matrix4x4 trans; Matrix4x4 rot;
		trans.SetTranslation( Vector3( 20.0f, 0.0f, 0.0f) );
		rot.SetRotation( axis, _angle );
		trans = rot * trans;
		trans *= rot;
		_programMatParams->Set( _paramTransform, trans );

		_angle += 0.004f;
		_pos += _delta;
		if ( _pos < -150.0f )
			_delta = 0.25f;
		else if ( _pos > 150.0f )
			_delta = -0.25f;
	}

	void Activate( Bool activate )
	{
		_cube->Enable( activate );
	}

private:
	P(IGraphicsObject)	_cube;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;
	
	ProgramParam*		_paramMaterial;
	ProgramParam*		_paramTransform;
	ProgramParam*		_paramColor;
	ProgramParam*		_paramLighting;
	ProgramParam*		_paramFogging;
};*/

//------------------------------------------------------------------------------

/*class BlendTest :
	public TestItem
{
public:
	BlendTest() :
	  TestItem( L"Blending" )
	{
		_angle = 0.0f;
		_scale = 0.33f;
		_pos = 150.0f;
		_delta = 0.25f;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );
		_paramTransform = _programMatParams->GetParam( L"p_transform" );
		_paramColor = _programMatParams->GetParam( L"p_color" );
		_paramLighting = _programMatParams->GetParam( L"p_lighting" );
		_paramFogging = _programMatParams->GetParam( L"p_fogging" ); 

		_programMatParams->Set( _paramColor, Vector4(1.0f, 1.0f, 1.0f, 0.5f) );
		_programMatParams->Set( _paramLighting, false );
		_programMatParams->Set( _paramFogging, false );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"glass.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup states.
		_texFilter = TextureFilter::Linear;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		_fill = FillMode::Solid; _cull = CullMode::None;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_blendOp = BlendOperation::Add; _srcBlend = BlendMode::SrcAlpha; _dstBlend = BlendMode::One;
		_blendState = _programMat->GetBlendState()->Clone();
		_blendState->Enable( true );
		_blendState->SetOperation( _blendOp );
		_blendState->SetSrcMode( _srcBlend );
		_blendState->SetDstMode( _dstBlend );

		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( false );

		// Create geometry.
		_cube = CreateCube( _programMat, 12.0f, 0, null, false, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetStencilState( _stencilState );
		_cube->SetBlendState( _blendState );
		_cube->SetRasterizerState( _rasterizerState );

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::B )
		{
			_blendOp = GetNext( _blendOp );
			_blendState->SetOperation( _blendOp );
		}
		else if ( key == Key::D )
		{
			_dstBlend = GetNext( _dstBlend );
			_blendState->SetDstMode( _dstBlend );
		}
		else if ( key == Key::S )
		{
			_srcBlend = GetNext( _srcBlend );
			_blendState->SetSrcMode( _srcBlend );
		}
	}

	void Update()
	{
		Matrix4x4 rot;
		Vector3 axis(0.0f, 1.0f, 0.0f);
		rot.SetRotation( axis, _angle );
		_angle += 0.004f;
		
		Matrix4x4 trans;
		trans.SetTranslation( Vector3( 20.0f, 0.0f, 0.0f) );
		trans = rot * trans;
		trans *= rot;
		_programMatParams->Set( _paramTransform, trans );

		_pos += _delta;
		if ( _pos < -150.0f )
			_delta = 0.25f;
		else if ( _pos > 150.0f )
			_delta = -0.25f;
	}

	void Activate( Bool activate )
	{
		_cube->Enable( activate );
	}

	String State()
	{
		return Format( L"[F]illMode: {0}, [C]ullMode: {1}, [B]lend Op: {2}, [S]rcMode: {3}, [D]stMode: {4}", _fill.ToString(), _cull.ToString(), _blendOp.ToString(), _srcBlend.ToString(), _dstBlend.ToString() );
	}

private:
	P(IGraphicsObject)	_cube;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;
	
	ProgramParam*		_paramMaterial;
	ProgramParam*		_paramTransform;
	ProgramParam*		_paramColor;
	ProgramParam*		_paramLighting;
	ProgramParam*		_paramFogging;
};*/

//------------------------------------------------------------------------------

/*class InstancingTest :
	public TestItem
{
public:
	InstancingTest() :
	  TestItem( L"Instancing" )
	{
		_angle = 0.0f;
		_scale = 0.33f;
		_delta = 0.0005f;
		_subset = false;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard", L"instanced" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup states.
		_fill = FillMode::Solid; _cull = CullMode::None; _function = CompareFunction::Equal;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( true );
		_depthStencilState->SetFunction( CompareFunction::Always );

		_texFilter = TextureFilter::Linear;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		// Create geometry.
		Vector4 colors[] =
		{
			ToVector( Color::Red ),
			ToVector( Color::Yellow ),
			ToVector( Color::Green ),
			ToVector( Color::Cyan ),
			ToVector( Color::Magenta ),
			ToVector( Color::White ),
		};
		_cube = CreateCube( _programMat, 12.0f, 6, colors, false, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetStencilState( _stencilState );
		_cube->SetRasterizerState( _rasterizerState );

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::Z )
		{
			_function = GetNext( _function );
			_depthStencilState->SetFunction( _function );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->Enable( !_depthStencilState->IsEnabled() );
		}
		else if ( key == Key::S )
		{
			_subset = !_subset;
			_cube->SetStartElement( _subset ? 6 : 0 );
			_cube->SetElementCount( _subset ? 18 : 36 );
		}
		else if ( key == Key::T )
		{
			_texFilter = GetNext( _texFilter );
			_programMatSamplers->Get(0)->SetFilter( _texFilter );
		}

		else if ( key == Key::D1 )
		{
			_cube->SetInstanceCount( 1 );
		}
		else if ( key == Key::D2 )
		{
			_cube->SetInstanceCount( 2 );
		}
		else if ( key == Key::D3 )
		{
			_cube->SetInstanceCount( 3 );
		}
		else if ( key == Key::D4 )
		{
			_cube->SetInstanceCount( 4 );
		}
		else if ( key == Key::D5 )
		{
			_cube->SetInstanceCount( 5 );
		}
		else if ( key == Key::D6 )
		{
			_cube->SetInstanceCount( 6 );
		}

		else if ( key == Key::Numpad0 )
		{
			_cube->SetStartInstance( 0 );
		}
		else if ( key == Key::Numpad1 )
		{
			_cube->SetStartInstance( 1 );
		}
		else if ( key == Key::Numpad2 )
		{
			_cube->SetStartInstance( 2 );
		}
		else if ( key == Key::Numpad3 )
		{
			_cube->SetStartInstance( 3 );
		}
		else if ( key == Key::Numpad4 )
		{
			_cube->SetStartInstance( 4 );
		}
		else if ( key == Key::Numpad5 )
		{
			_cube->SetStartInstance( 5 );
		}
	}

	void Update()
	{
		Vector3 axis(0.0f, 1.0f, 0.0f);
		Vector3 axis2(1.0f, 0.0f, 0.0f);
		Vector3 axis3(0.0f, 0.0f, 1.0f);

		IMatrix4x4Stream* streamTrans = (IMatrix4x4Stream*)_cube->GetData()->GetInstanceStream( "transform", 0 );
		if ( streamTrans->Open() )
		{
			Matrix4x4 rot;
			Matrix4x4 scale;
			Matrix4x4 trans[] =
			{
				Matrix4x4(),
				Matrix4x4(),
				Matrix4x4(),
				Matrix4x4(),
				Matrix4x4(),
				Matrix4x4(),
			};
			trans[0].SetTranslation( Vector3( 20.0f, 0.0f,  0.0f) );
			trans[1].SetTranslation( Vector3(  0.0f, 0.0f,  0.0f) );
			trans[2].SetTranslation( Vector3( -20.0f, 0.0f, 0.0f) );
			trans[3].SetTranslation( Vector3( 20.0f, 20.0f,  0.0f) );
			trans[4].SetTranslation( Vector3(  0.0f, 20.0f,  0.0f) );
			trans[5].SetTranslation( Vector3( -20.0f, 20.0f, 0.0f) );

			rot.SetRotation( axis, -_angle );
			trans[0] = rot * trans[0];
			trans[5] = rot * trans[5];

			rot.SetRotation( axis2, _angle );
			scale.SetScale( _scale );
			trans[1] = rot * trans[1];
			trans[1] = scale * trans[1];

			trans[4] = rot * trans[4];

			rot.SetRotation( axis3, _angle );
			trans[2] = rot * trans[2];
			trans[3] = rot * trans[3];

			streamTrans->Write( trans, 6 );
			streamTrans->Close();
		}

		_angle += 0.004f;
		_scale += _delta;
		if ( _scale < 0.2f )
			_delta = 0.0005f;
		else if ( _scale > 1.0f )
			_delta = -0.0005f;
	}
	
	void Activate( Bool activate )
	{
		_cube->Enable( activate );
	}

private:
	P(IGraphicsObject)	_cube;
	P(IGraphicsObject)	_cubeSubset;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;
	
	ProgramParam*		_paramMaterial;
	Bool				_subset;
};*/

//------------------------------------------------------------------------------

/*class PostProcessTest :
	public TestItem
{
public:
	PostProcessTest() :
	  TestItem( L"Post Processing" )
	{
		_filtersEnabled = true;
		_angle = 0.0f;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard", L"instanced" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup filters.
		DisplayMode displayMode; _gfxSystem->GetFrameWindow()->GetDisplayMode( displayMode );

		// Calculate offsets.
		Float dx = 1.0f / displayMode.Width; Float dy = 1.0f / displayMode.Height;
		Vector<Vector2> offsets( A(Vector2) );
		offsets.SetSize( 9 );
		for ( ULong i = 0; i < 3; ++i )
		{
			for ( ULong j = 0; j < 3; ++j )
			{
				offsets[(((i*3)+j))].x = (-1.0f * dx) + ((Float)i * dx);
				offsets[(((i*3)+j))].y = (-1.0f * dy) + ((Float)j * dy);
			}
		}

		// Brightness.
		_filterBrightness = CreateFilter( L"filter.brightness" );
		_paramsBrightness = _filterBrightness->GetProgram()->GetFragmentStage()->GetParameters()->Clone();
		_brightnessValue = _paramsBrightness->GetParam( L"p_value" );
		_paramsBrightness->Set( _brightnessValue, 0.0f );
		_filterBrightness->SetFragmentParameters( _paramsBrightness );

		// Edge filter.
		_filterEdge = CreateFilter( L"filter.prewitt" );
		_paramsEdge = _filterEdge->GetProgram()->GetFragmentStage()->GetParameters()->Clone();
		_edgeOffset = _paramsEdge->GetParam( L"p_offset" );
		_paramsEdge->Set( _edgeOffset, offsets.Begin(), offsets.Size() );
		_filterEdge->SetFragmentParameters( _paramsEdge );

		// Grayscale.
		_filterGrayscale = CreateFilter( L"filter.grayscale" );

		// Negative.
		_filterNegative = CreateFilter( L"filter.negative" );
		_filterNegative->Enable( false );

		// Color.
		_filterColor = CreateFilter( L"filter.color" );
		_paramsColor = _filterColor->GetProgram()->GetFragmentStage()->GetParameters()->Clone();
		_colorValue = _paramsColor->GetParam( L"p_color" );
		_paramsColor->Set( _colorValue, ToVector(Color::Yellow) );
		_filterColor->SetFragmentParameters( _paramsColor );
		_filterColor->Enable( false );

		// Blur.
		_filterBlur = CreateFilter( L"filter.blur" );
		_paramsBlur = _filterBlur->GetProgram()->GetFragmentStage()->GetParameters()->Clone();
		_blurOffset = _paramsBlur->GetParam( L"p_offset" );
		_paramsBlur->Set( _blurOffset, offsets.Begin(), offsets.Size() );
		_filterBlur->SetFragmentParameters( _paramsBlur );

		_filterBlur2 = CreateFilter( L"filter.blur" );
		_filterBlur2->SetFragmentParameters( _paramsBlur );
		
		// Setup states.
		_fill = FillMode::Solid; _cull = CullMode::Back; _function = CompareFunction::Equal;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( true );
		_depthStencilState->SetFunction( CompareFunction::Always );

		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( TextureFilter::Linear );

		// Create geometry.
		Vector4 colors[] =
		{
			ToVector( Color::Blue ),
			ToVector( Color::Red ),
			ToVector( Color::LightBlue ),
		};
		_pyramid = CreatePyramid( _programMat, 16.0f, 3, colors, false, false );
		_pyramid->SetVertexParameters( _programMatParams );
		_pyramid->SetFragmentResources( _programMatRes );
		_pyramid->SetFragmentSamplers( _programMatSamplers );
		_pyramid->SetDepthStencilState( _depthStencilState );
		_pyramid->SetStencilState( _stencilState );
		_pyramid->SetRasterizerState( _rasterizerState );

		// Setup overlay sprite.
		_programOverlay = gfxSystem->GetProgram( L"overlay", L"colored" );
		_overlay = CreateSquare( null, _programOverlay, 630.0f, 320.0f, 50.0f );
		
		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::Z )
		{
			_function = GetNext( _function );
			_depthStencilState->SetFunction( _function );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->Enable( !_depthStencilState->IsEnabled() );
		}
		else if ( key == Key::B )
		{
			if ( _filtersEnabled )
			{
				_filterBlur2->Enable( !_filterBlur2->IsEnabled() );
			}
		}
		else if ( key == Key::P )
		{
			_filtersEnabled = !_filtersEnabled;

			_filterBlur->Enable( _filtersEnabled );
			_filterBlur2->Enable( _filtersEnabled );
			_filterBrightness->Enable( _filtersEnabled );
			_filterEdge->Enable( _filtersEnabled );
			_filterGrayscale->Enable( _filtersEnabled );
			_filterNegative->Enable( _filtersEnabled );
			_filterColor->Enable( _filtersEnabled );
		}

		// 
		else if ( key == Key::F1 )
		{
			_filterGrayscale->Enable( _filtersEnabled && !_filterGrayscale->IsEnabled() );
		}
		else if ( key == Key::F2 )
		{
			_filterBlur->Enable( _filtersEnabled && !_filterBlur->IsEnabled() );
			_filterBlur2->Enable( _filtersEnabled && !_filterBlur2->IsEnabled() );
		}
		else if ( key == Key::F3 )
		{
			_filterBrightness->Enable( _filtersEnabled && !_filterBrightness->IsEnabled() );
		}
		else if ( key == Key::F4 )
		{
			_filterEdge->Enable( _filtersEnabled && !_filterEdge->IsEnabled() );
		}
		else if ( key == Key::F5 )
		{
			_filterNegative->Enable( _filtersEnabled && !_filterNegative->IsEnabled() );
		}
		else if ( key == Key::F6 )
		{
			_filterColor->Enable( _filtersEnabled && !_filterColor->IsEnabled() );
		}

		// 
		else if ( key == Key::D1 )
		{
			_paramsBrightness->Set( _brightnessValue, 0.5f );
		}
		else if ( key == Key::D2 )
		{
			_paramsBrightness->Set( _brightnessValue, 0.4f );
		}
		else if ( key == Key::D3 )
		{
			_paramsBrightness->Set( _brightnessValue, 0.3f );
		}
		else if ( key == Key::D4 )
		{
			_paramsBrightness->Set( _brightnessValue, 0.2f );
		}
		else if ( key == Key::D5 )
		{
			_paramsBrightness->Set( _brightnessValue, 0.0f );
		}
		else if ( key == Key::D6 )
		{
			_paramsBrightness->Set( _brightnessValue, -0.2f );
		}
		else if ( key == Key::D7 )
		{
			_paramsBrightness->Set( _brightnessValue, -0.3f );
		}
		else if ( key == Key::D8 )
		{
			_paramsBrightness->Set( _brightnessValue, -0.4f );
		}
		else if ( key == Key::D9 )
		{
			_paramsBrightness->Set( _brightnessValue, -0.5f );
		}
	}

	void Update()
	{
		Vector3 axis(0.0f, 1.0f, 0.0f);
		Vector3 axis2(1.0f, 0.0f, 0.0f);

		IMatrix4x4Stream* streamTrans = (IMatrix4x4Stream*)_pyramid->GetData()->GetInstanceStream( "transform", 0 );
		if ( streamTrans->Open() )
		{
			Matrix4x4 rot;
			Matrix4x4 trans[] =
			{
				Matrix4x4(),
				Matrix4x4(),
				Matrix4x4(),
			};
			trans[0].SetTranslation( Vector3( 24.0f, 0.0f,  0.0f) );
			trans[1].SetTranslation( Vector3(  0.0f, 0.0f,  0.0f) );
			trans[2].SetTranslation( Vector3( -24.0f, 0.0f, 0.0f) );

			rot.SetRotation( axis, _angle );
			trans[0] = rot * trans[0];

			rot.SetRotation( axis, -_angle );
			trans[1] = rot * trans[1];

			rot.SetRotation( axis, _angle );
			trans[2] = rot * trans[2];

			streamTrans->Write( trans, 3 );
			streamTrans->Close();
		}

		_angle += 0.004f;
	}

	void Activate( Bool activate )
	{
		_pyramid->Enable( activate );
		_overlay->Enable( activate );
		_filterBlur->Enable( activate );
		_filterBlur2->Enable( activate );
		_filterBrightness->Enable( activate );
		_filterEdge->Enable( activate );
		_filterGrayscale->Enable( activate );
		_filterNegative->Enable( activate );
		_filterColor->Enable( activate );
	}

private:
	P(IGraphicsObject)	_pyramid;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;
	ProgramParam*		_paramMaterial;
	ProgramParam*		_paramLighting;
	P(IProgram)			_programOverlay;
	P(IGraphicsObject)	_overlay;
	Bool				_filtersEnabled;

	P(IGraphicsObject)	_filterBrightness;
	P(IParameterSet)	_paramsBrightness;
	ProgramParam*		_brightnessValue;

	P(IGraphicsObject)	_filterEdge;
	P(IParameterSet)	_paramsEdge;
	ProgramParam*		_edgeOffset;

	P(IGraphicsObject)	_filterGrayscale;
	P(IGraphicsObject)	_filterNegative;
	
	P(IGraphicsObject)	_filterColor;
	P(IParameterSet)	_paramsColor;
	ProgramParam*		_colorValue;

	P(IGraphicsObject)	_screenRed;
	P(IProgram)			_filterRed;

	P(IGraphicsObject)	_filterBlur2;
	P(IGraphicsObject)	_filterBlur;
	P(IParameterSet)	_paramsBlur;
	ProgramParam*		_blurOffset;
};*/

//------------------------------------------------------------------------------

/*class ViewportTest :
	public TestItem
{
public:
	ViewportTest( IWindowSystemEx* windowSystem ) :
	  TestItem( L"Viewports" ),
	  _windowSystem( windowSystem )
	{
		_angle = 0.0f;
	}

	void Initialize( IStreamSystemEx* streamSystem, IGraphicsSystemEx* gfxSystem, IImageManager* imageManager )
	{
		// Call base implementation.
		TestItem::Initialize( streamSystem, gfxSystem, imageManager );

		// Setup scene program.
		InitScene();

		// Setup material program.
		_programMat = gfxSystem->GetProgram( L"material.standard" );
		_programMatParams = _programMat->GetVertexStage()->GetParameters()->Clone();
		_paramMaterial = _programMatParams->GetParam( L"p_material" );
		_paramTransform = _programMatParams->GetParam( L"p_transform" );
		_paramColor = _programMatParams->GetParam( L"p_color" );
		_paramLighting = _programMatParams->GetParam( L"p_lighting" );
		_paramFogging = _programMatParams->GetParam( L"p_fogging" ); 

		_programMatParams->Set( _paramColor, ToVector(Color::White) );
		_programMatParams->Set( _paramLighting, false );
		_programMatParams->Set( _paramFogging, false );

		PixelFormat format = gfxSystem->GetFrameWindow()->GetClientPixelFormat();
		_programMatRes = _programMat->GetFragmentStage()->GetResources()->Clone();
		P(io::IStream) streamImage = _streamSystem->GetStream( L"crate.bmp" );
		P(IImage) image = _imageManager->LoadImage( streamImage, format, nullptr );
		_programMatRes->Set( 0, image->GetTexture() );

		// Setup states.
		_texFilter = TextureFilter::Linear;
		_programMatSamplers = _programMat->GetFragmentStage()->GetSamplers()->Clone();	
		_programMatSamplers->Get(0)->SetFilter( _texFilter );

		_fill = FillMode::Solid; _cull = CullMode::Back;
		_rasterizerState = _programMat->GetRasterizerState()->Clone();
		_rasterizerState->SetFillMode( _fill );
		_rasterizerState->SetCullMode( _cull );

		_function = CompareFunction::Always;
		_depthStencilState = _programMat->GetDepthStencilState()->Clone();
		_depthStencilState->Enable( true );
		_depthStencilState->SetFunction( _function );

		// Create custom viewports.
		//IViewWindow* window = _windowSystem->CreateWindow( _windowSystem->GetFrameWindow()->GetHandle(), 1000, 100, 300, 200 );
		//IViewRenderWindow* renderWindow = gfxSystem->GetDevice()->CreateRenderWindow( window, format, false, 1, 0 );
		//_viewport2 = gfxSystem->GetViewWindow(0)->GetViewport();
		//_viewport2->SetColor( Color::Green );

		gfxSystem->GetFrameWindow()->GetViewport(0)->SetColor( Color::Green );

		//_viewport = gfxSystem->CreateViewport( 50, 600, 400, 300, Color::Teal );
		//_viewport2 = gfxSystem->GetFrameWindow()->GetViewport( 0 );
		//_viewport2 = gfxSystem->GetFrameWindow()->CreateViewport( 100, 650, 300, 200, Color::Green );
		//_viewport2 = gfxSystem->GetFrameWindow()->CreateViewport( 0, 0, 1024, 768, Color::Green );

		// Create geometry.
		_cube = CreateCube( _programMat, 16.0f, 0, null, false, false );
		_cube->SetVertexParameters( _programMatParams );
		_cube->SetFragmentResources( _programMatRes );
		_cube->SetFragmentSamplers( _programMatSamplers );
		_cube->SetDepthStencilState( _depthStencilState );
		_cube->SetStencilState( _stencilState );
		_cube->SetRasterizerState( _rasterizerState );

		//_cube2 = _gfxSystem->CreateObject( _viewport2, _cube->GetData() );
		//_cube2->SetVertexParameters( _programMatParams );
		//_cube2->SetFragmentResources( _programMatRes );
		//_cube2->SetFragmentSamplers( _programMatSamplers );
		//_cube2->SetDepthStencilState( _depthStencilState );
		//_cube2->SetStencilState( _stencilState );
		//_cube2->SetRasterizerState( _rasterizerState );

		// Setup scene.
		Matrix4x4 matWorld;
		_programSceneParams->Set( _paramWorld, matWorld );

		Matrix4x4 matView;
		Vector3 target(0.1f, 0.1f, 0.1f);
		Vector3 pos(2.0f, 40.0f, 80.0f);
		Vector3 up(0.0f, 1.0f, 0.0f);
		matView.SetLookAt( target, pos, up );
		_programSceneParams->Set( _paramView, matView );

		Matrix4x4 matProj;
		matProj.SetPerspectiveProjection( Math::DegToRad(45.0f), 1.0f, 200.0f, 1.0f );
		_programSceneParams->Set( _paramProj, matProj );

		Matrix4x4 matWorldView;
		matWorldView = matWorld * matView;
		_programSceneParams->Set( _paramWorldView, matWorldView );

		Matrix4x4 matWorldViewProj;
		matWorldViewProj = matWorldView * matProj;
		_programSceneParams->Set( _paramWorldViewProj, matWorldViewProj );
	}

	void OnKey( const Key& key )
	{
		if ( key == Key::F )
		{
			_fill = GetNext( _fill );
			_rasterizerState->SetFillMode( _fill );
		}
		else if ( key == Key::C )
		{
			_cull = GetNext( _cull );
			_rasterizerState->SetCullMode( _cull );
		}
		else if ( key == Key::Z )
		{
			_function = GetNext( _function );
			_depthStencilState->SetFunction( _function );
		}
		else if ( key == Key::D )
		{
			_depthStencilState->Enable( !_depthStencilState->IsEnabled() );
		}
		else if ( key == Key::T )
		{
			_texFilter = GetNext( _texFilter );
			_programMatSamplers->Get(0)->SetFilter( _texFilter );
		}
	}

	void Update()
	{
		Matrix4x4 rot;
		Vector3 axis(0.0f, 1.0f, 0.0f);
		rot.SetRotation( axis, _angle );
		_angle += 0.004f;

		Matrix4x4 trans;
		trans.SetTranslation( Vector3( -12.0f, 0.0f, 0.0f) );
		trans = rot * trans;
		_programMatParams->Set( _paramTransform, trans );
	}

	void Activate( Bool activate )
	{
		_cube->Enable( activate );
		//_cube2->Enable( activate );
	}

private:
	P(IWindowSystemEx)	_windowSystem;

	P(IGraphicsObject)	_cube;
	P(IGraphicsObject)	_cube2;
	P(IProgram)			_programMat;
	P(IParameterSet)	_programMatParams;
	P(IResourceSet)		_programMatRes;
	P(ISamplerStateSet)	_programMatSamplers;

	P(IProgram)			_filterGrayscale;
	P(IProgram)			_filterNegative;
	
	ProgramParam*		_paramMaterial;
	ProgramParam*		_paramTransform;
	ProgramParam*		_paramTransform2;
	ProgramParam*		_paramColor;
	ProgramParam*		_paramLighting;
	ProgramParam*		_paramFogging;

	P(synkro::gfx::IRenderView)	_viewport;
	P(synkro::gfx::IRenderView)	_viewport2;
};*/


//------------------------------------------------------------------------------

class GraphicsSystemTest :
	public SynkroListener,
	public WindowListener,
	public MouseListener,
	public KeyboardListener
{
public:
	GraphicsSystemTest( const String& pathMain, io::IStreamSystemFactory* factStreamSys, IWindowSystemFactory* factWinSys, IInputSystemFactory* factInputSys, IGraphicsSystemFactory* factGfxSys ) :
		_pathMain( pathMain ),	
		_tests( A(TestItem*) ),
		_shot( false ),
		_fps( false ),
		_frame( 0 ),
		_current( 0 )
	{
		ULong module = (ULong)::GetModuleHandleW( NULL );
		DisplayMode displayMode("1024x768x32", false);

		_streamSystem = new io::StreamSystemEx( nullptr, nullptr );
		((io::StreamSystemEx*)(io::IStreamSystem*)_streamSystem)->Initialize( factStreamSys->Create(nullptr) );
		String pathGfx = io::Path::MakeAbsolute( _pathMain, L"..\\..\\data\\gfx" );
		((io::IStreamSystem*)_streamSystem)->MapDirectory( pathGfx, true );
		
		_windowSystem = new WindowSystemEx( module, nullptr );
		((WindowSystemEx*)(IWindowSystem*)_windowSystem)->Initialize( factWinSys );
		IFrameWindow* frameWindow = _windowSystem->CreateWindow( displayMode.Fullscreen, false, L"Graphics System Test", 0, displayMode.Width, displayMode.Height );
		
		_inputSystem = new InputSystemEx( module, nullptr );
		((InputSystemEx*)(IInputSystem*)_inputSystem)->Initialize( factInputSys, _windowSystem );

		GraphicsSystem system = factGfxSys->GetClassID();
		_graphicsSystem = new GraphicsSystemEx( nullptr );
		((GraphicsSystemEx*)(IGraphicsSystem*)_graphicsSystem)->Initialize( factGfxSys, GraphicsDeviceType::Hardware, _windowSystem );
		_graphicsSystem->AddProgramLibrary( _streamSystem->GetDirectory(L"programs"), system.ToString() );
		((GraphicsSystemEx*)(IGraphicsSystem*)_graphicsSystem)->Init( DepthFormat::D32F, displayMode, false, 1 );

		// Rendering stuff.
		_renderWindow = _graphicsSystem->GetFrameWindow();

		// Screen-shot stuff.
		_shotTexture = _graphicsSystem->GetDevice()->CreateRenderTexture( displayMode.Width, displayMode.Height, _renderWindow->GetPixelFormat(), 1, 0 );

		// Imaging stuff.
		BmpImageCodecFactory factBmp;
		JpgImageCodecFactory factJpg;
		TgaImageCodecFactory factTga;

		_threadPool = new ThreadPool( 4, nullptr );
		_imageManager = new ImageManager( 1.0f, _graphicsSystem, nullptr );
		ImageManager* mgr = (ImageManager*)(IImageManager*)_imageManager;
		mgr->SetThreadPool( _threadPool );
		mgr->RegisterCodec( &factBmp );
		mgr->RegisterCodec( &factJpg );
		mgr->RegisterCodec( &factTga );
	}

	void AddItem( TestItem* item )
	{
		item->Initialize( _streamSystem, _graphicsSystem, _imageManager );
		_tests.Add( item );
	}

	void OnSynkroInitialize()
	{
	}

	void OnSynkroUpdate( Double delta )
	{
		/*// Calculate frame rate.
		_time += delta; _delta += delta; ++_frame; ++_frames;
		if ( _delta >= 1.0 )
		{
			Double fps = _frames/_delta;
			_frames = 0; _delta = 0.0;

			String stat = Convert::ToString(fps, L"0.##");
			_fps->SetText( stat );
		}

		// Save screenshot, if needed.
		if ( _shot != String::Empty )
		{
			SynkroProfile( "Context.Run.MainLoop.Shot" );

			_synkro->GetGraphicsSystem()->GetFrameWindow()->SetTarget( null );
			P(IImage) image = _synkro->GetImageManager()->CreateImage( _shotTexture );

			//String strPath(L"..\\..\\"); //_config->Get( Param::ScreenshotPath, &strPath );
			String pathShot = "shot.jpg"; //io::Path::MakeAbsolute( strPath, _shot.Append(_shotFormat) );

			io::IStream* stream = _synkro->GetStreamSystem()->CreateStream( pathShot );
			_synkro->GetImageManager()->SaveImage( image, stream, image->GetFormat() );
			_shot = String::Empty;

			LogMessage( MessagePriority::Normal, L"Screenshot saved." );
		}*/
	}

	Bool OnSynkroException( const Exception& ex )
	{
		return false;
	}

	void OnWindowResize( Pointer handle, UInt width, UInt height )
	{
	}

	void OnWindowCommand( Pointer handle, UInt command )
	{
		if ( command == 1200 )
		{
			::MessageBoxA( 0, "OnWindowCommand", 0, 0 );
			_windowSystem->GetIconWindow()->SetHint( L"OnWindowCommand(1200)" );
		}
	}

	void OnWindowActivate( Pointer handle, Bool active )
	{
	}

	Bool OnWindowClosing( Pointer handle )
	{
		return (::MessageBoxA((HWND)handle, "Are you sure you want to quit?", "Exit confirmation", MB_YESNO|MB_ICONQUESTION) == IDYES);
	}

	Bool ListenMouseInput() const
	{
		return true;
	}

	Bool OnMouseClick( UInt device, const MouseButton& buttons )
	{
		return false;
	}

	Bool OnMouseDoubleClick( UInt device, const MouseButton& buttons )
	{
		return false;
	}

	Bool OnMouseButtonDown( UInt device, const MouseButton& buttons )
	{
		return false;
	}

	Bool OnMouseButtonUp( UInt device, const MouseButton& buttons )
	{
		return false;
	}

	Bool OnMouseAxisMove( UInt device, const Axis& axis, Int delta )
	{
		return false;
	}

	Bool ListenKeyboardInput() const
	{
		return true;
	}

	Bool OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
	{
		if ( key == Key::Space )
		{
			ULong prev = _current;

			if ( shift )
			{
				// Switch to previous test.
				if ( _current == 0 )
					_current = _tests.Size()-1;
				else
					--_current;
			}
			else
			{
				// Switch to the next test.
				if ( ++_current >= _tests.Size() )
					_current = 0;
			}

			_tests[prev]->Activate( false );
			_tests[_current]->Activate( true );
		}
		else if ( key == Key::F1 )
		{
			// Toggle fullscreen mode.
			DisplayMode mode;
			_renderWindow->GetDisplayMode( mode );
			mode.Fullscreen = !mode.Fullscreen;
			_renderWindow->SetDisplayMode( mode );
		}
		else if ( key == Key::F11 )
		{
			if ( !_shot )
				_shot = true;
		}
		else if ( key == Key::F12 )
		{
			if ( !_fps )
				_fps = true;
		}
		else if ( key == Key::Escape )
		{
			// Exit test.
			_windowSystem->GetFrameWindow()->Close();
			return true;
		}

		// Let the test item handle user input.
		if ( (_current >= 0) && (_current < _tests.Size()) )
		{
			_tests[_current]->OnKey( key );
			_windowSystem->GetFrameWindow()->SetTitle( String::Format(L"{5}. Frame: {4}. Test {0} of {1}: {2}. {3} [Space]-switch to next test. [Escape]-exit.", _current+1, _tests.Size(), _tests[_current]->Name(), _tests[_current]->State(), _frame, _systemName) );
		}

		return true;
	}

	Bool OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
	{
		return false;
	}

	Bool OnKeyboardKeyPress( UInt device, Char key )
	{
		return false;
	}

	void Run()
	{
		OverlayTest tstOverlay; AddItem( &tstOverlay );
		//TextureTest tstTexture; AddItem( &tstTexture );
		//LightTest tstLight; AddItem( &tstLight );
		//FogTest tstFog; AddItem( &tstFog );
		//BlendTest tstBlend; AddItem( &tstBlend );
		//InstancingTest tstInstancing; AddItem( &tstInstancing );
		//PostProcessTest tstPostProcess; AddItem( &tstPostProcess );
		//ViewportTest tstViewport(_windowSystem); AddItem( &tstViewport );

		_inputSystem->CreateKeyboard( 0 );
		IKeyboardEx* keyboard = _inputSystem->GetKeyboard( 0 );
		keyboard->ListenKeyDown( this, Key::F1, true );
		keyboard->ListenKeyDown( this, Key::D, true );
		keyboard->ListenKeyDown( this, Key::F10, true );
		keyboard->ListenKeyDown( this, Key::F, true );
		keyboard->ListenKeyDown( this, Key::C, true );

		if ( (_current < 0) || (_current >= _tests.Size()) )
			return;

		for ( ULong i = 0; i < _tests.Size(); ++i )
		{
			_tests[i]->Activate( (i == _current) );
		}

		_windowSystem->GetFrameWindow()->SetTitle( String::Format(L"{5}. Frame: {4}. Test {0} of {1}: {2}. {3} [Space]-switch to next test. [Escape]-exit.", _current+1, _tests.Size(), _tests[_current]->Name(), _tests[_current]->State(), _frame, _systemName) );

		static Double delta = 0.0;
		static ULong frames = 0;
		static Double fps = 0.0;

		while ( _windowSystem->Update(delta) )
		{
			{
				_inputSystem->Update( 0.05 );

				if ( (_current >= 0) && (_current < _tests.Size()) )
				{
					_tests[_current]->Update();
				}

				if ( _graphicsSystem->Update(delta) ) // _renderWindow, _shot ? _shotTexture : null, _depthTexture
				{
					// Calculate stats.
					Double sec = _timer.GetElapsedSeconds();
					delta += sec;
					++_frame; frames++;
					if ( delta >= 1.0 )
					{
						fps = frames/delta;
						frames = 0;
						delta = 0.0;
					}
					if ( _fps )
					{
						GraphicsStats stats;
						_graphicsSystem->GetStats( stats );
						wprintf( L"FPS: %f. PrimitiveCount: %d\n", fps, stats.PrimitiveCount );
					}

					if ( _shot )
					{
						wprintf( L"Saving screen shot...  " );

						P(IImage) image = _imageManager->CreateImage( _shotTexture );
						String pathShot = io::Path::MakeAbsolute( _pathMain, L"shot.jpg" );
						P(io::IStream) stream = _streamSystem->CreateStream( pathShot );
						image->Save( stream, PixelFormat::R8G8B8A8 );

						_shot = false;
						wprintf( L"Screen shot saved.\n" );
					}
				}
				_fps = false;
			}
		}

		for ( ULong i = 0; i < _tests.Size(); ++i )
		{
			_tests[i]->Uninitialize();
		}
		_tests.Clear();

		delete _threadPool;
	}

protected:
	Bool					_fps;
	Bool					_shot;
	ULong					_frame;
	ULong					_current;
	Vector<TestItem*>		_tests;
	String					_pathMain;
	String					_systemName;
	Timer					_timer;
	ThreadPool*				_threadPool;
	P(io::IStreamSystemEx)	_streamSystem;
	P(IWindowSystemEx)		_windowSystem;
	P(IInputSystemEx)		_inputSystem;
	P(GraphicsSystemEx)		_graphicsSystem;
	P(IImageManager)		_imageManager;
	P(IPlainRenderTexture)	_shotTexture;
	P(IFrameRenderWindowEx)	_renderWindow;
};
