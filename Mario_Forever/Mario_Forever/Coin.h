#pragma once
#include"Game.hpp"
#include"SFML/Graphics.hpp"
namespace abay
{
	class Coin
	{
	public:

		Coin(GameDataRef data);
		void Draw();
		void Update(float dt);
		void move(float x, float y);
		void vanish(unsigned int i);
		void Animate();
		std::vector<sf::Sprite> GetCoinSprite();
	private :
		GameDataRef _data;
		sf::Clock _clock;
		std::vector<sf::Sprite> _Coins;
		std::vector<sf::Texture> _animationFrames;
		unsigned int _animation_Iterator;





	};



}
