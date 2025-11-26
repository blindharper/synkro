extern synkro::Byte res_synkro_mat_programs[]; extern synkro::UInt res_synkro_mat_programs_size;
static synkro::core::Resource _resPrograms( synkro::core::ResourceType::GraphicsProgram, res_synkro_mat_programs, res_synkro_mat_programs_size );

static synkro::core::IResource* _resources[] =
{
	&_resPrograms,
};
