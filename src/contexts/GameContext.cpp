#include "contexts/GameContext.hpp"

namespace GameContext
{
	GameState p_currentState = GameState::NONE;
	std::unique_ptr<FontManager> p_fontManagerPtr;

	void init()
	{
		p_fontManagerPtr = std::make_unique<FontManager>();
		p_fontManagerPtr->init();
	}
}