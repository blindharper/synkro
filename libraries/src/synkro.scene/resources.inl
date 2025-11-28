extern synkro::Byte res_synkro_scene_resources[]; extern synkro::UInt res_synkro_scene_resources_size;
static synkro::core::Resource _resModels( synkro::scene::SceneManager::ID_RESOURCE_MODELS, res_synkro_scene_resources, res_synkro_scene_resources_size );

static synkro::core::IResource* _resources[] =
{
	&_resModels,
};
