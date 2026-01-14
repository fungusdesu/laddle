#pragma once
#include "ui/Tile.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

constexpr int WORD_LENGTH = 5;

class Row : public sf::Drawable
{
public:
	explicit Row() = default;

	bool isFull() const;

	sf::Vector2f getPosition() const;
	void setPosition(const float& x, const float& y);

	Tile getTileAtIndex(const int& i) const;

	std::array<TileState, WORD_LENGTH> getState() const;
	void check(const std::string& target);
	std::string getWord() const;

	void pushLetter(const char& letter);
	char popLetter();
	void reset();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::array<Tile, WORD_LENGTH> p_tiles;
	int p_iterator = 0;

	sf::Vector2f p_position = {0.0f, 0.0f};
};