#include "managers/ScreenManager.hpp"

#include "helper/swag_assert.hpp"

void ScreenManager::init()
{
	p_stateStack.push(GameState::MAIN_MENU);
	p_screenStack.push(std::make_unique<MainMenuScreen>());
}

void ScreenManager::advance(GameState nextState)
{
	switch (nextState)
	{
		case GameState::MAIN_MENU:
		{
			p_stateStack.push(GameState::MAIN_MENU);
			p_screenStack.push(std::make_unique<MainMenuScreen>());
			break;
		}

		case GameState::TEST:
		{
			p_stateStack.push(GameState::TEST);
			p_screenStack.push(std::make_unique<TestScreen>());
			break;
		}

		default:
		{
			p_stateStack.push(GameState::NOT_IMPLEMENTED);
			p_screenStack.push(std::make_unique<NotImplementedScreen>());
			break;
		}
	}
}

void ScreenManager::retreat()
{
	p_screenStack.pop();
}

void ScreenManager::handleInputCurrentScreen(const sf::Event& event)
{
	swag_assert(!p_screenStack.empty());
	p_screenStack.top()->handleInput(event);
}

void ScreenManager::updateCurrentScreen()
{
	swag_assert(!p_screenStack.empty());
	p_screenStack.top()->update();
}

void ScreenManager::drawCurrentScreen(sf::RenderTarget& window)
{
	swag_assert(!p_screenStack.empty());
	p_screenStack.top()->draw(window);
}

GameState ScreenManager::getCurrentState() const
{
	swag_assert(!p_stateStack.empty());
	return p_stateStack.top();
}

bool ScreenManager::shouldExit() const
{
	return p_screenStack.empty();
}