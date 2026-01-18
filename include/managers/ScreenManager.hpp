#pragma once
#include <stack>
#include <memory>

#include "screens/BaseScreen.hpp"
#include "screens/MainMenuScreen.hpp"
#include "screens/NotImplementedScreen.hpp"
#include "screens/TestScreen.hpp"

class ScreenManager
{
public:
	explicit ScreenManager() = default;
	~ScreenManager() = default;

	void init();

	void advance(GameState nextState);
	void retreat();

	void handleInputCurrentScreen(const sf::Event& event);
	void updateCurrentScreen();
	void drawCurrentScreen(sf::RenderTarget& window);

	GameState getCurrentState() const;

	bool shouldExit() const;

private:
	std::stack<GameState> p_stateStack;
	std::stack<std::unique_ptr<BaseScreen>> p_screenStack;
};