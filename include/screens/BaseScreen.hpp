#pragma once
#include "contexts/GameContext.hpp"
#include <SFML/Graphics.hpp>

// abstract class for a screen
class BaseScreen
{
public:
	BaseScreen(sf::RenderWindow& window)
	{
		p_window = &window;
	}

	virtual void update() = 0;
	virtual void draw() = 0;

	virtual ~BaseScreen() = default;

protected:
	sf::RenderWindow* p_window;
};