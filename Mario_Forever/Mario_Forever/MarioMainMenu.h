#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Game.hpp"
#include"State.hpp"
namespace abay
{
	class MarioMainMenu : public State
	{
	public :

		MarioMainMenu(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		sf::Sprite MenuBackground;
		sf::Text StartGame;
		sf::Text QuitGame;
		GameDataRef _data;
		sf::SoundBuffer CoinBuffer;
		sf::Sound CoinSound;
		

	



	};










}