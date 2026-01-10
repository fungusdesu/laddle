#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class FontManager
{
public:
	FontManager() = default;
	~FontManager() = default;
	
	void init();
	void load(const std::string& key, const std::string& path);
	const sf::Font& get(const std::string& name) const;

private:
	std::unordered_map<std::string, sf::Font> p_fonts;
};