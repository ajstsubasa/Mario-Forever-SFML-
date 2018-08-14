#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Game.hpp"
#include"Level1.h"
#include"Collision.h"
#include"DEFINITIONS.hpp"
namespace abay
{
	class Goomba
	{
	public :

		Goomba(GameDataRef data);
		void Update(float dt);
		int  IsAlive(unsigned int i);
		void Draw();
		void Move(float x);
		void Motion(float x,unsigned int i);
		void Death(unsigned int i);
		sf::Sprite GoombaSprite;
		std::vector<sf::Sprite> GetGoombaSprite();
		
	private:
	
	int  Goomba_is_Alive[10];
	GameDataRef _data;
	std::vector<sf::Sprite> Goombaas;



	};



}
