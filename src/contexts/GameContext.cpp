#include "contexts/GameContext.hpp"

namespace GameContext
{
	GameState currentState = GameState::MAIN_MENU;
	std::unique_ptr<FontManager> fontManagerPtr;

	void init()
	{
		fontManagerPtr = std::make_unique<FontManager>();
		fontManagerPtr->init();
	}
}