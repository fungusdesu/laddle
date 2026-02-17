#pragma once
#include <stack>

#include "screens/BaseScreen.hpp"

struct AboutPage
{
	const char* text;
};

constexpr auto MAX_ABOUT_PAGES = 2;

constexpr AboutPage ABOUT_PAGE_ABOUT = {
	"Laddle (a portmanteau of Ladder and Wordle) is a word game inheriting both functionalities from Word Ladder and Wordle. You are given a source word, and through hints you must ladder your way to the answer.\n\nEach of your guesses should only differ by one letter at a time. Upon confirming your row, the row tiles may either be highlighted green, yellow, or none at all. When highlighted green, it means the answer contains the letter in the tile and at the correct position. When highlighted yellow, it means the answer contains the letter in the tile, but not at that position. No highlight means that letter does not exist in the answer."
};

constexpr AboutPage ABOUT_PAGE_KEYBINDS = {
	"Arrow Up - Menu move up/Move row up\nArrow Down - Menu move down/Move row down\nEnter - Select\nBackspace - Delete"
};

constexpr std::array<AboutPage, MAX_ABOUT_PAGES> ABOUT_PAGES = { ABOUT_PAGE_ABOUT, ABOUT_PAGE_KEYBINDS };

class AboutScreen : public BaseScreen
{
public:
	explicit AboutScreen() : BaseScreen() {}

	bool handleInput(const sf::Event& event) override;
	void update() override;
	void draw(sf::RenderTarget& window) const override;

	~AboutScreen() = default;

private:
	int p_iterator = 0;

	void p_drawText(sf::RenderTarget& window, const sf::Font& font) const;
};