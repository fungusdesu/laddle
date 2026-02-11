#pragma once
#include <array>
#include <SFML/Graphics.hpp>

constexpr auto GAME_ACTIONS_COUNT = 4;

enum GameAction
{
	MAIN_MENU_MOVE_UP,
	MAIN_MENU_MOVE_DOWN,
	MAIN_MENU_SELECT,
	EXIT_TO_MAIN_MENU
};

class ActionManager
{
public:
	void checkActions(const sf::Event& event);
	bool hasAction(GameAction action);
	void clearActions();

private:
	std::array<bool, GAME_ACTIONS_COUNT> p_actionStates;
};