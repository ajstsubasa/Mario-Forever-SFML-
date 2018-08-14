#pragma once
#include<memory>
#include<string>
#include"AssestManager.hpp"
#include"InputManager.hpp"
#include"Statemachine.h"
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
namespace abay
{


	struct GameData 
	{
		StateMachine machine;
		AssetManager assets;
		InputManager input;
		sf::RenderWindow window;

	};
	typedef std::shared_ptr<GameData> GameDataRef;
	class Game {
	public :
		Game(int width, int height, std::string title);
	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock clock;
         GameDataRef _data = std::make_shared < GameData>();
		void Run();
		//sf::SoundBuffer musicbuffer;
		//sf::Sound music;

	};





}