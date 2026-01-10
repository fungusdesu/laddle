#pragma once
#include "screen/BaseScreen.hpp"

class TestScreen : public BaseScreen
{
public:
	TestScreen(sf::RenderWindow& window) : BaseScreen(window) {}

	void update() override;
	void draw() override;

	~TestScreen() = default;
};