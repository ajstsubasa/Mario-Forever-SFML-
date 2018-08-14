#pragma once
#include"SFML\Graphics.hpp"
#include"Game.hpp"
#include "Blocks.h"
#include"Coin.h"
namespace abay
{
	class Level1
	{
	public:
		Level1(GameDataRef data);
		void Draw();
		void MoveLevel1(float x, float y);
		void AnimateBlocks(unsigned int i);
		void AnimateBlocksDown(unsigned int i);
		std::vector<sf::Sprite> GetGroundSprite();
		std::vector<sf::Sprite> GetBlockSprite();
		std::vector<sf::Sprite> GetPipeSprite();
		void Motion();
		void PauseLevel1();
	private:
		GameDataRef _data;
		Block  *_block;
		Coin *_coin;
		sf::Sprite Playing_BackGround;
		std::vector<sf::Sprite> Ground;
		std::vector<sf::Sprite> Pipes;
		




     };
}