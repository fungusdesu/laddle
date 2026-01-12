#pragma once
#include "screens/BaseScreen.hpp"

class TestScreen : public BaseScreen
{
public:
	explicit TestScreen(sf::RenderWindow& window) : BaseScreen(window) {}

	void update() override;
	void draw() override;

	~TestScreen() = default;
};