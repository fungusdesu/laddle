#include "screens/AboutScreen.hpp"

#include "managers/ResourceManager.hpp"
#include "managers/ScreenManager.hpp"

bool AboutScreen::handleInput(const sf::Event& event)
{
	bool captured = false;
	ResourceManager::checkActions(event);

	if (ResourceManager::hasAction(GameAction::ABOUT_MOVE_NEXT_PAGE))
	{
		if (p_iterator < MAX_ABOUT_PAGES - 1)
		{
			p_iterator++;
			captured = true;
		}
	}
	else if (ResourceManager::hasAction(GameAction::ABOUT_MOVE_PREVIOUS_PAGE))
	{
		if (p_iterator > 0)
		{
			p_iterator--;
			captured = true;
		}
	}
	else if (ResourceManager::hasAction(GameAction::ABOUT_EXIT))
	{
		ScreenManager::retreat();
		captured = true;
	}

	ResourceManager::clearActions();
	return captured;
}

void AboutScreen::update()
{

}

void AboutScreen::p_drawText(sf::RenderTarget& window, const sf::Font& font) const
{
	sf::Text mainText(font, ABOUT_PAGES[p_iterator].text, 30);
	mainText.setPosition({200.0f, 200.0f});
	window.draw(mainText);
}

void AboutScreen::draw(sf::RenderTarget& window) const
{
	const sf::Font& font = ResourceManager::getFont(Font::VCR_OSD_MONO);

	p_drawText(window, font);

	sf::RectangleShape rect({800.0f, 400.0f});
	rect.setPosition({200.0f, 200.0f});
	rect.setOutlineThickness(3);
	rect.setFillColor(sf::Color::Transparent);
	window.draw(rect);
}