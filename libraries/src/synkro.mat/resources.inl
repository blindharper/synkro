extern synkro::Byte res_synkro_mat_programs[]; extern synkro::UInt res_synkro_mat_programs_size;
static synkro::core::Resource _resPrograms( synkro::core::ResourceType::GraphicsProgram, res_synkro_mat_programs, res_synkro_mat_programs_size );

extern synkro::Byte res_synkro_mat_resources[]; extern synkro::UInt res_synkro_mat_resources_size;
static synkro::core::Resource _resTextures( synkro::mat::MaterialManager::ID_RESOURCE_TEXTURES, res_synkro_mat_resources, res_synkro_mat_resources_size );

static synkro::core::IResource* _resources[] =
{
	&_resPrograms,
	&_resTextures,
};
