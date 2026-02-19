#include "screens/SettingsScreen.hpp"

#include "managers/ResourceManager.hpp"
#include "managers/ScreenManager.hpp"

#include "ui/Spinner.hpp"

SettingsScreen::SettingsScreen() : BaseScreen()
{
	std::vector<std::string> vec;
	for (const auto &option : TEST_SPINNER_OPTIONS)
	{
		vec.push_back(option);
	}
	p_spinnerPtr = std::make_unique<Spinner>(vec, 10);
	p_spinnerPtr->setLoop();
	p_spinnerPtr->setSize(30);
	p_spinnerPtr->setPosition({200.0f, 200.0f});
}

bool SettingsScreen::handleInput(const sf::Event &event)
{
	bool captured = false;
	ResourceManager::checkActions(event);

	if (ResourceManager::hasAction(GameAction::SETTINGS_MOVE_UP))
	{
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::SETTINGS_MOVE_DOWN))
	{
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::SETTINGS_MOVE_LEFT))
	{
		p_spinnerPtr->goPrevious();
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::SETTINGS_MOVE_RIGHT))
	{
		p_spinnerPtr->goNext();
		captured = true;
	}
	else if (ResourceManager::hasAction(GameAction::SETTINGS_EXIT))
	{
		ScreenManager::retreat();
		captured = true;
	}

	ResourceManager::clearActions();
	return captured;
}

void SettingsScreen::update()
{
}

void SettingsScreen::draw(sf::RenderTarget &window) const
{
	const sf::Font &font = ResourceManager::getFont(Font::VCR_OSD_MONO);

	window.draw(*p_spinnerPtr);
}