#pragma once
#include<SFML\Graphics.hpp>
namespace abay
{
	class InputManager
	{
	public:
		InputManager(){}
		~InputManager(){}

		bool  isSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window);
		bool  isTextHovered(sf::Text text, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);




	};






}