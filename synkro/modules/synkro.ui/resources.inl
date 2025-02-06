extern synkro::Byte res_synkro_ui_resources[]; extern synkro::UInt res_synkro_ui_resources_size;
static synkro::core::Resource _resResources( synkro::core::ResourceType::UiTheme, res_synkro_ui_resources, res_synkro_ui_resources_size );

static synkro::core::IResource* _resources[] =
{
	&_resResources,
};
