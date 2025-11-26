using namespace synkro::scene;

#include <scene/Default/DefaultSceneFactory.h>

#include <scene/MeshBuilder/BoxMeshBuilderFactory.h>
#include <scene/MeshBuilder/ConeMeshBuilderFactory.h>
#include <scene/MeshBuilder/CylinderMeshBuilderFactory.h>
#include <scene/MeshBuilder/EllipsoidMeshBuilderFactory.h>
#include <scene/MeshBuilder/PlaneMeshBuilderFactory.h>
#include <scene/MeshBuilder/PyramidMeshBuilderFactory.h>
#include <scene/MeshBuilder/TorusMeshBuilderFactory.h>

#include <scene/MeshCodec/ObjMeshCodecFactory.h>
#include <scene/MeshCodec/XMeshCodecFactory.h>

static DefaultSceneFactory			_factDefaultSceneFactory;

static BoxMeshBuilderFactory		_factBoxMeshBuilder;
static ConeMeshBuilderFactory		_factConeMeshBuilder;
static CylinderMeshBuilderFactory	_factCylinderMeshBuilder;
static EllipsoidMeshBuilderFactory	_factEllipsoidMeshBuilder;
static PlaneMeshBuilderFactory		_factPlaneMeshBuilder;
static PyramidMeshBuilderFactory	_factPyramidMeshBuilder;
static TorusMeshBuilderFactory		_factTorusMeshBuilder;

static ObjMeshCodecFactory			_factObjMeshCodec;
static XMeshCodecFactory			_factXMeshCodec;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Scenes.
	//--------------------------------------------------------------------------
	&_factDefaultSceneFactory,

	//--------------------------------------------------------------------------
	// Mesh builders.
	//--------------------------------------------------------------------------
	&_factBoxMeshBuilder,
	&_factConeMeshBuilder,
	&_factCylinderMeshBuilder,
	&_factEllipsoidMeshBuilder,
	&_factPlaneMeshBuilder,
	&_factPyramidMeshBuilder,
	&_factTorusMeshBuilder,

	//--------------------------------------------------------------------------
	// Mesh codecs.
	//--------------------------------------------------------------------------
	&_factObjMeshCodec,
	&_factXMeshCodec,
};
