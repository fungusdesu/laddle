#include "screens/MainMenuScreen.hpp"

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

	p_window->clear();
	p_window->draw(laddleText);
	p_window->display();
}