#pragma once
#include "ui/Tile.hpp"

constexpr int WORD_LENGTH = 5;

class Row
{
public:
	explicit Row() = default;

	bool isFull() const;

	std::array<TileState, WORD_LENGTH> getState() const;
	void check(const std::string& target);
	std::string getWord() const;
	void appendLetter(const char& letter);
	void reset();

private:
	std::array<Tile, WORD_LENGTH> p_tiles;
	int p_iterator = 0;
};