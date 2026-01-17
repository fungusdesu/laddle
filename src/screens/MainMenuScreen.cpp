#include <iostream>

#include "screens/MainMenuScreen.hpp"

#include "helper/centerTextInRect.hpp"

constexpr auto LADDLE_TEXT_Y_POSITION = 100.0f;

void MainMenuScreen::handleInput(const sf::Event& event)
{
	
}

void MainMenuScreen::update()
{

}

void MainMenuScreen::draw()
{
	const sf::Font& font = GameContext::getFont("VCR_OSD_MONO");

	sf::Text laddleText(font, "LADDLE", 120);
	{
		laddleText.setLetterSpacing(2.0f);
		auto lbounds = laddleText.getLocalBounds();
		laddleText.setOrigin(lbounds.position + lbounds.size / 2.0f);
		laddleText.setPosition({p_window->getSize().x / 2.0f, LADDLE_TEXT_Y_POSITION});
	}
	
	sf::Text playText(font, "PLAY");


	p_window->clear();
	p_window->draw(laddleText);
	p_window->display();
}