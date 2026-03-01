#pragma once
#include "screens/BaseScreen.hpp"

class PauseScreen : public BaseScreen
{
public:
	explicit PauseScreen() : BaseScreen() {}

	
	bool handleInput(const sf::Event& event) override;
	void update() override;
	void draw(sf::RenderTarget& window) const override;

	~PauseScreen() = default;
private:
};