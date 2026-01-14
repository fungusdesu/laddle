#include "helper/centerTextInRect.hpp"

void centerTextInRect(sf::Text& text, const sf::RectangleShape& rect)
{
	auto lbounds = text.getLocalBounds();
	auto gbounds = rect.getGlobalBounds();

	text.setOrigin(lbounds.position + lbounds.size / 2.0f);
	text.setPosition(gbounds.position + gbounds.size / 2.0f);
}