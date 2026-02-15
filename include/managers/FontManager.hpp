#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum class Font
{
	VCR_OSD_MONO
};

class FontManager
{
public:
	explicit FontManager() = default;
	~FontManager() = default;
	
	void init();
	void load(const Font& key, const std::string& path);
	const sf::Font& get(const Font& font) const;

private:
	std::unordered_map<Font, sf::Font> p_fonts;
};