struct StrDef
{
	const synkro::Char* Name;
	const synkro::Char* Value;
};

static StrDef _strings[] =
{
#include "../../../languages/src/synkro.lng/languages/english.inl"
};
