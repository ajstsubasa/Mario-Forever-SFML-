#pragma once
#include<SFML\Graphics.hpp>
#include"Game.hpp"
#include"State.hpp"
#include"DEFINITIONS.hpp"
#include"Mario.h"
#include"Goomba.h"
#include"Level1.h"
#include"Collision.h"
#include"Coin.h"

namespace abay
{
	class PlayingState : public State
	{
	public:
		PlayingState(GameDataRef _data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		bool checkCollisionwithPipe();
		bool CheckGoombaCollision(unsigned int i);
		 int   x[NUM_GOOMBAAS];
		
	
	private:
		sf::Text Score;
		int _score;
		sf::Text Points;
		sf::Font font;
		sf::Sprite Playing_BackGround;
		GameDataRef _data;
		Collision *_collision;
		Block *block;
		Mario *mario;
		Level1 *level1;
		Coin *coin;
		Goomba * goomba;
		sf::SoundBuffer BrickSmashBuffer;
		sf::Sound BrickSmashSound;
		sf::SoundBuffer CoinBuffer;
		sf::Sound CoinSound;
		sf::Clock clock;
		Collision *collision_detector;
		sf::SoundBuffer jumpBuffer;
		sf::Sound jumpSound;
		sf::SoundBuffer themeBuffer;
		sf::Sound theme;
		

	};



}