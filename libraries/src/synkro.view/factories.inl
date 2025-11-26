using namespace synkro::view;

#include <view/Filter/Pass/AlphaFilterFactory.h>
#include <view/Filter/Pass/BlueFilterFactory.h>
#include <view/Filter/Kernel3x3/BlurFilterFactory.h>
#include <view/Filter/Simple/BrightnessFilterFactory.h>
#include <view/Filter/Color/ColorFilterFactory.h>
#include <view/Filter/Simple/ContrastFilterFactory.h>
#include <view/Filter/Depth/DepthFilterFactory.h>
#include <view/Filter/Depth/DepthOfFieldFilterFactory.h>
#include <view/Filter/Kernel3x3/DilationFilterFactory.h>
#include <view/Filter/Kernel3x3/Emboss/EmbossFilterFactory.h>
#include <view/Filter/Kernel3x3/ErosionFilterFactory.h>
#include <view/Filter/Depth/FogFilterFactory.h>
#include <view/Filter/Pass/GrayscaleFilterFactory.h>
#include <view/Filter/Pass/GreenFilterFactory.h>
#include <view/Filter/Simple/HueFilterFactory.h>
#include <view/Filter/Kernel3x3/LaplacianFilterFactory.h>
#include <view/Filter/Depth/MotionBlurFilterFactory.h>
#include <view/Filter/Pass/NegativeFilterFactory.h>
#include <view/Filter/Kernel3x3/PrewittFilterFactory.h>
#include <view/Filter/Pass/RedFilterFactory.h>
#include <view/Filter/Pass/SepiaFilterFactory.h>
#include <view/Filter/Kernel3x3/SharpenFilterFactory.h>
#include <view/Filter/Kernel3x3/SobelFilterFactory.h>

static AlphaFilterFactory			_factAlphaFilter;
static BlueFilterFactory			_factBlueFilter;
static BlurFilterFactory			_factBlurFilter;
static BrightnessFilterFactory		_factBrightnessFilter;
static ColorFilterFactory			_factColorFilter;
static ContrastFilterFactory		_factContrastFilter;
static DepthFilterFactory			_factDepthFilter;
static DepthOfFieldFilterFactory	_factDepthOfFieldFilter;
static DilationFilterFactory		_factDilationFilter;
static EmbossFilterFactory			_factEmbossFilter;
static ErosionFilterFactory			_factErosionFilter;
static FogFilterFactory				_factFogFilter;
static GrayscaleFilterFactory		_factGrayscaleFilter;
static GreenFilterFactory			_factGreenFilter;
static HueFilterFactory				_factHueFilter;
static LaplacianFilterFactory		_factLaplacianFilter;
static MotionBlurFilterFactory		_factMotionBlurFilter;
static NegativeFilterFactory		_factNegativeFilter;
static PrewittFilterFactory			_factPrewittFilter;
static RedFilterFactory				_factRedFilter;
static SepiaFilterFactory			_factSepiaFilter;
static SharpenFilterFactory			_factSharpenFilter;
static SobelFilterFactory			_factSobelFilter;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Viewport filters.
	//--------------------------------------------------------------------------
	&_factAlphaFilter,
	&_factBlueFilter,
	&_factBlurFilter,
	&_factBrightnessFilter,
	&_factColorFilter,
	&_factContrastFilter,
	&_factDepthFilter,
	&_factDepthOfFieldFilter,
	&_factDilationFilter,
	&_factEmbossFilter,
	&_factErosionFilter,
	&_factFogFilter,
	&_factGrayscaleFilter,
	&_factGreenFilter,
	&_factHueFilter,
	&_factLaplacianFilter,
	&_factMotionBlurFilter,
	&_factNegativeFilter,
	&_factPrewittFilter,
	&_factRedFilter,
	&_factSepiaFilter,
	&_factSharpenFilter,
	&_factSobelFilter,
};
