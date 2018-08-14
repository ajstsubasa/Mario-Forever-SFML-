#include"stdafx.h"
#include "Game.hpp"
#include<stdlib.h>
#include "Splashscreen.h"
#include"DEFINITIONS.hpp"
#include<ctime>



namespace abay

{

	Game::Game(int width, int height, std::string title)

	{
		srand(time(0));
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));
		//musicbuffer.loadFromFile(MUSIC_FILE_PATH);
		//music.setBuffer(musicbuffer);
		this->Run();

	}



	void Game::Run()

	{


		float newTime, frameTime, interpolation;



		float currentTime = this->clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;



		while (this->_data->window.isOpen())

		{

			this->_data->machine.ProcessStateChange();



			newTime = this->clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;



			if (frameTime > 0.25f)

			{

				frameTime = 0.25f;

			}



			currentTime = newTime;

			accumulator += frameTime;



			while (accumulator >= dt)

			{

				this->_data->machine.getActiveState()->HandleInput();

				this->_data->machine.getActiveState()->Update(dt);



				accumulator -= dt;

		}

			


			interpolation = accumulator / dt;

			this->_data->machine.getActiveState()->Draw(interpolation);

		}

	}

}