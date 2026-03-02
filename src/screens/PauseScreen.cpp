#include "screens/PauseScreen.hpp"

#include "managers/ResourceManager.hpp"
#include "managers/ScreenManager.hpp"

bool PauseScreen::handleInput(const sf::Event& event)
{
	bool captured = false;
	ResourceManager::checkActions(event);

	if (ResourceManager::hasAction(GameAction::PAUSE_MOVE_UP))
	{
		p_selector = (p_selector + P_PAUSE_MAX_OPTIONS - 1) % P_PAUSE_MAX_OPTIONS;
		ResourceManager::playSoundMoveMenuOption();
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::PAUSE_MOVE_DOWN))
	{
		p_selector = (p_selector + 1) % P_PAUSE_MAX_OPTIONS;
		ResourceManager::playSoundMoveMenuOption();
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::PAUSE_SELECT))
	{
		switch (p_nextState[p_selector])
		{
			case GameState::PLAY:
			{
				ScreenManager::retreat();
				break;
			}

			case GameState::SETTINGS:
			{
				ScreenManager::advance(GameState::SETTINGS);
				break;
			}

			case GameState::MAIN_MENU:
			{
				ScreenManager::retreat();
				ScreenManager::retreat();
				break;
			}
		}
		ResourceManager::playSoundSelectMenuOption();
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::PAUSE_RESUME))
	{
		ScreenManager::retreat();
		captured = true;
	}

	ResourceManager::clearActions();
	return captured;
}

void PauseScreen::update()
{
	
}

void PauseScreen::p_drawTitle(sf::RenderTarget& window, const sf::Font& font) const
{
	sf::Text moratoriumText(font, "MORATORIUM", 80);
	{
		moratoriumText.setPosition({window.getSize().x / 4.0f, 100.0f});
	}

	window.draw(moratoriumText);
}

void PauseScreen::p_drawPauseOptions(sf::RenderTarget& window, const sf::Font& font) const
{
	sf::Text resumeText(font, "RESUME", 60);
	sf::Text settingsText(font, "SETTINGS", 60);
	sf::Text exitText(font, "EXIT", 60);
	{
		resumeText.setPosition({window.getSize().x / 4.0f, 300.0f});
		settingsText.setPosition({window.getSize().x / 4.0f, 380.0f});
		exitText.setPosition({window.getSize().x / 4.0f, 460.0f});
	}

	window.draw(resumeText);
	window.draw(settingsText);
	window.draw(exitText);
}

void PauseScreen::p_drawSelector(sf::RenderTarget& window, const sf::Font& font) const
{
	sf::Text selectorText(font, ">", 60);
	{
		auto selectorYPosition = p_selector * 80 + 300;
		auto lbounds = selectorText.getLocalBounds();
		selectorText.setPosition({window.getSize().x / 4.0f - 2.0f * lbounds.size.x, selectorYPosition});
	}

	window.draw(selectorText);
}

void PauseScreen::draw(sf::RenderTarget& window) const
{
	const sf::Font& font = ResourceManager::getFont(Font::VCR_OSD_MONO);
	
	p_drawTitle(window, font);
	p_drawPauseOptions(window, font);
	p_drawSelector(window, font);
}