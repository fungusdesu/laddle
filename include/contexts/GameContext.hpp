#pragma once
#include "managers/FontManager.hpp"

// ////////////////////////////////////
// GAME STATES
enum class GameState
{
	NONE,
	TEST
};

namespace GameContext
{
	extern std::unique_ptr<FontManager> p_fontManagerPtr;
	void init();

	template <typename ...Ts>
	void loadFont(Ts&&... yuke)
	{
		p_fontManagerPtr->load(std::forward<Ts>(yuke)...);
	}

	template <typename ...Ts>
	const sf::Font& getFont(Ts&&... yuke)
	{
		return p_fontManagerPtr->get(std::forward<Ts>(yuke)...);
	}
}