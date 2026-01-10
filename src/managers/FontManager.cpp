#include <managers/FontManager.hpp>

struct FontTableEntry
{
	const char* name;
	const char* path;
};

constexpr FontTableEntry FONT_TABLE[] = {
	{"VCR_OSD_MONO", "assets/fonts/VCR_OSD_MONO.ttf"}
};

void FontManager::init()
{
	for (auto entry : FONT_TABLE)
	{
		load(entry.name, entry.path);
	}
}

void FontManager::load(const std::string& key, const std::string& path)
{
	sf::Font font(path);
	p_fonts.insert({key, font});
}

const sf::Font& FontManager::get(const std::string& name) const
{
	return p_fonts.at(name);
}