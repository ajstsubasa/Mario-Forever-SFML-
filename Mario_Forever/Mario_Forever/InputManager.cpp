#include"stdafx.h"
#include"InputManager.hpp"
namespace abay
{
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{

		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width
				, object.getGlobalBounds().height);
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;


	}
	sf::Vector2i  InputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
	bool InputManager::isTextHovered(sf::Text text, sf::RenderWindow &window)
	{

		
			sf::IntRect tempRect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width
				, text.getGlobalBounds().height);
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		
		return false;


	}






}