#pragma once
#include"SFML\Graphics.hpp"
#include"Game.hpp"
namespace abay
{
	class Block
	{
	public:
		Block(GameDataRef data);
		void Draw();
		void Update(float dt);
		void move(float x , float y);
		void moveup(float y,  unsigned int i);
		std::vector<sf::Sprite>  GetBlockSprite();
		void Animate(unsigned int i);
		void AnimateDown(unsigned int i);
		void Motion();
		void Animate();
		


	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _blocks;
		std::vector<sf::Sprite>_block_pieces;
		sf::Clock _clock;
	




	};





}