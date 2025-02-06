//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines abstract graphics device.
//==============================================================================
#ifndef _SYNKRO_GFX_IGRAPHICSDEVICE_
#define _SYNKRO_GFX_IGRAPHICSDEVICE_


#include "config.h"
#include <core/IObject.h>
#include <img/PixelFormat.h>
#include <gfx/DepthFormat.h>
#include <gfx/DisplayMode.h>
#include <gfx/DataUsage.h>
#include <gfx/DataAccess.h>
#include <gfx/IndexType.h>
#include <gfx/PrimitiveType.h>
#include <gfx/ProgramDataType.h>
#include <gfx/GraphicsDeviceDesc.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract graphics device.
 */
iface IGraphicsDevice :
	public core::IObject
{
public:
	/**
	 * Creates rendering window based on the specified frame window.
	 * @remarks Rendering window is a wrapper around frame window that owns frame buffers.
	 * @param window Source window.
	 * @param displayMode Window's display mode.
	 * @param vsync Specifies whether to synchronize presentation of a frame with the vertical blank.
	 * @param sampleCount Number of samples per pixel.
	 * @param sampleQuality Image quality level.
	 * @return Created rendering window.
	 */
	virtual IFrameRenderWindow*								CreateRenderWindow( win::IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates rendering window based on the specified view window.
	 * @param window Source window.
	 * @param format Window's pixel format.
	 * @param vsync Specifies whether to synchronize presentation of a frame with the vertical blank.
	 * @param sampleCount Number of samples per pixel.
	 * @param sampleQuality Image quality level.
	 * @return Created rendering window.
	 */
	virtual IViewRenderWindow*								CreateRenderWindow( win::IViewWindow* window, const img::PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates rendering textures set of the given size.
	 * @param size Number of textures in the set.
	 * @return Created rendering textures set.
	 */
	virtual IRenderTextureSet*								CreateRenderTextures( UInt size ) = 0;

	/**
	 * Creates linear rendering texture.
	 * @param length Texture length.
	 * @param format Pixel format.
	 * @return Created texture.
	 */
	virtual ILinearRenderTexture*							CreateRenderTexture( UInt length, const img::PixelFormat& format ) = 0;

	/**
	 * Creates plain rendering texture.
	 * @param width Texture width.
	 * @param height Texture height.
	 * @param format Pixel format.
	 * @param sampleCount Number of samples per texel.
	 * @param sampleQuality Image quality level.
	 * @return Created texture.
	 */
	virtual IPlainRenderTexture*							CreateRenderTexture( UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates cube rendering texture.
	 * @param length Cube edge length.
	 * @param format Pixel format.
	 * @param sampleCount Number of samples per texel.
	 * @param sampleQuality Image quality level.
	 * @return Created texture.
	 */
	virtual ICubeRenderTexture*								CreateRenderTexture( UInt length, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates volume rendering texture.
	 * @param width Texture width.
	 * @param height Texture height.
	 * @param depth Texture depth.
	 * @param format Pixel format.
	 * @return Created texture.
	 */
	virtual IVolumeRenderTexture*							CreateRenderTexture( UInt width, UInt height, UInt depth, const img::PixelFormat& format ) = 0;

	/**
	 * Creates plain depth-stencil texture.
	 * @param width Texture width.
	 * @param height Texture height.
	 * @param colorFormat Render target format.
	 * @param depthFormat Depth texture format.
	 * @param stencil Indicates whether the texture should contain stencil data.
	 * @param sampleCount Number of samples per texel.
	 * @param sampleQuality Image quality level.
	 * @return Created depth texture if the given format is supported, or null otherwise.
	 */
	virtual IPlainDepthTexture*								CreateDepthTexture( UInt width, UInt height, const img::PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates cube depth-stencil texture.
	 * @param length Cube edge length.
	 * @param colorFormat Render target format.
	 * @param depthFormat Depth texture format.
	 * @param stencil Indicates whether the texture should contain stencil data.
	 * @param sampleCount Number of samples per texel.
	 * @param sampleQuality Image quality level.
	 * @return Created depth texture if the given format is supported, or null otherwise.
	 */
	virtual ICubeDepthTexture*								CreateDepthTexture( UInt length, const img::PixelFormat& colorFormat, const DepthFormat& depthFormat, Bool stencil, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Creates linear texture with the specified properties.
	 * @param usage Data usage.
	 * @param length Texture length.
	 * @param format Pixel format.
	 * @param levelCount Number of mipmap levels.
	 * @param elementCount Number of elements in the array.
	 * @return Created texture.
	 */
	virtual ILinearTexture*									CreateTexture( const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount, UInt elementCount ) = 0;

	/**
	 * Creates plain texture of the given dimensions and format.
	 * @param usage Data usage.
	 * @param width Texture width.
	 * @param height Texture height.
	 * @param format Pixel format.
	 * @param levelCount Number of mipmap levels.
	 * @param elementCount Number of elements in the array.
	 * @return Created texture.
	 */
	virtual IPlainTexture*									CreateTexture( const DataUsage& usage, UInt width, UInt height, const img::PixelFormat& format, UInt levelCount, UInt elementCount ) = 0;

	/**
	 * Creates cube texture of the given dimensions and format.
	 * @param usage Data usage.
	 * @param length Cube edge length.
	 * @param format Pixel format.
	 * @param levelCount Number of mipmap levels.
	 * @return Created texture.
	 */
	virtual ICubeTexture*									CreateTexture( const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount ) = 0;

	/**
	 * Creates volume texture of the given dimensions and format.
	 * @param usage Data usage.
	 * @param width Texture width.
	 * @param height Texture height.
	 * @param depth Texture depth.
	 * @param format Pixel format.
	 * @param levelCount Number of mipmap levels.
	 * @return Created texture.
	 */
	virtual IVolumeTexture*									CreateTexture( const DataUsage& usage, UInt width, UInt height, UInt depth, const img::PixelFormat& format, UInt levelCount ) = 0;

	/**
	 * Creates typed buffer with the specified properties.
	 * @param usage Data usage.
	 * @param dataType Buffer data type.
	 * @param count Number of elements in the array.
	 * @return Created buffer.
	 */
	virtual ITypedBuffer*									CreateTypedBuffer( const DataUsage& usage, const ProgramDataType& dataType, UInt count ) = 0;

	/**
	 * Creates structured buffer with the specified properties.
	 * @param usage Data usage.
	 * @param stride Structure size, in bytes.
	 * @param count Number of elements in the array.
	 * @return Created buffer.
	 */
	virtual IStructuredBuffer*								CreateStructuredBuffer( const DataUsage& usage, UInt stride, UInt count ) = 0;

	/**
	 * Creates visual primitive.
	 * @param program Program used to draw the primitive.
	 * @param usage Data usage.
	 * @param access Data access mode.
	 * @param type Geometric primitive type.
	 * @param indexType Type of index data.
	 * @param vertexCount Number of vertices in the primitive.
	 * @param indexCount Number of indices in the primitive.
	 * @param instanceCount Maximum number of instances the primitive can hold.
	 * @param pointCount Number of control points for patched primitive.
	 * @param interleaved Indicates whether to use interleaved or dedicated element buffers.
	 * @param adjacency Indicates whether the element data contain adjacency information.
	 * @return Created primitive.
	 */
	virtual IPrimitive*										CreatePrimitive( IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency ) = 0;

	/**
	 * Creates graphics program from a set of streams.
	 * @param parent Parent program.
	 * @param inputFormat Input data format.
	 * @param outputFormat Output data format. Used with geometry stage.
	 * @param vertexProgram Vertex program stream.
	 * @param hullProgram Hull program stream.
	 * @param domainProgram Domain program stream.
	 * @param geometryProgram Geometry program stream.
	 * @param fragmentProgram Fragment program stream.
	 * @return Created program.
	 * @exception BadArgumentException Stream is null.
	 */
	virtual IProgram*										CreateProgram( IProgram* parent, IDataFormat* inputFormat, IDataFormat* outputFormat, io::IStream* vertexProgram, io::IStream* hullProgram, io::IStream* domainProgram, io::IStream* geometryProgram, io::IStream* fragmentProgram ) = 0;

	/**
	 * Creates scissor rectangle.
	 * @param left Left coordinate of the rectangle, in pixels.
	 * @param top Top coordinate of the rectangle, in pixels.
	 * @param right Right coordinate of the rectangle, in pixels.
	 * @param bottom Bottom coordinate of the rectangle, in pixels.
	 * @return Created rectangle.
	 */
	virtual IRect*											CreateScissorRect( Int left, Int top, Int right, Int bottom ) = 0;

	/**
	 * Tests if the device supports specified pixel format.
	 * @param format Pixel format to test.
	 * @return True, if the device supports pixel format, false otherwise.
	 */
	virtual Bool											IsSupported( const img::PixelFormat& format ) const = 0;

	/**
	 * Retrieves device's default blend states.
	 */
	virtual IBlendStateSet*									GetBlendStates() const = 0;

	/**
	 * Retrieves device's default depth-stencil state.
	 */
	virtual IDepthStencilState*								GetDepthStencilState() const = 0;

	/**
	 * Retrieves device's default rasterizer state.
	 */
	virtual IRasterizerState*								GetRasterizerState() const = 0;

	/**
	 * Retrieves device description.
	 * @param [out] desc Device description.
	 */
	virtual void											GetDesc( GraphicsDeviceDesc& desc ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IGRAPHICSDEVICE_
