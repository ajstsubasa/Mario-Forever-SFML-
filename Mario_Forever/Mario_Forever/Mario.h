#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Game.hpp"
#include"Level1.h"
#include"Collision.h"
#include"DEFINITIONS.hpp"
namespace abay
{
	class Mario {
	public:
		Mario(GameDataRef data);
		void Update(float dt);
		void Draw();
		void Animate();
		void Jump();
		void SwitchScale();
		void SwitchScale2();
		int  GetCurrentState();
		sf::Sprite& GetSprite();
		void SetState(int state);
		void SetdeadSprite();
		bool isMarioDead();
		void Death();
	private:
		sf::Sprite Mario_Sprite;
		std::vector<sf::Texture> _animationFrames;
		GameDataRef _data;
		bool isDead;
		Level1 *level1;
		sf::Clock _clock;
		int Mario_State;
		Collision *collision_detector;
		unsigned int _animation_Iterator;
	






	};




}