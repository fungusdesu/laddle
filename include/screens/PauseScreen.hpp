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
	int p_selector = 0;
	static constexpr auto P_PAUSE_MAX_OPTIONS = 3;
	static constexpr GameState p_nextState[P_PAUSE_MAX_OPTIONS] = {
		GameState::PLAY,
		GameState::SETTINGS,
		GameState::MAIN_MENU
	};

	void p_drawTitle(sf::RenderTarget& window, const sf::Font& font) const;
	void p_drawPauseOptions(sf::RenderTarget& window, const sf::Font& font) const;
	void p_drawSelector(sf::RenderTarget& window, const sf::Font& font) const;
};