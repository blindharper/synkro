extern synkro::Byte res_synkro_cons_resources[]; extern synkro::UInt res_synkro_cons_resources_size;
static synkro::core::Resource _resConsole( synkro::cons::Console::ID_RESOURCE_CONSOLE, res_synkro_cons_resources, res_synkro_cons_resources_size );

static synkro::core::IResource* _resources[] =
{
	&_resConsole,
};
