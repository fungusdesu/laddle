#include <iostream>
#include "screens/TestScreen.hpp"
#include "contexts/GameContext.hpp"
#include "helper/centerTextInRect.hpp"
#include <SFML/Graphics.hpp>

void TestScreen::handleInput(const sf::Event& event)
{
	if (event.is<sf::Event::KeyPressed>())
	{
		auto scancode = event.getIf<sf::Event::KeyPressed>()->scancode;
		if (scancode == sf::Keyboard::Scan::Backspace)
		{
			std::cout << "backspace\n";
			p_row.popLetter();
		}
	}
	else if (event.is<sf::Event::TextEntered>())
	{
		auto letter = event.getIf<sf::Event::TextEntered>()->unicode;
		if (letter >= 'a' && letter <= 'z')
		{
			if (p_row.isFull())
			{
				p_row.reset();
				std::cout << "RESET\n";
			}
			else p_row.pushLetter(letter);
		}
	}
}

void TestScreen::update()
{

}

void TestScreen::draw()
{
	const sf::Font& font = GameContext::getFont("VCR_OSD_MONO");
	sf::Text allOKText(font, "SFML all OK!", 50);

	p_window->clear();
	p_window->draw(allOKText);
	p_window->draw(p_row);
	p_window->display();
}