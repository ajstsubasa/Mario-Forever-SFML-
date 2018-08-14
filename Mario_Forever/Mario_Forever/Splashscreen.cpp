
#include"stdafx.h"
#include <sstream>
#include"Splashscreen.h"
#include "DEFINITIONS.hpp"
#include"MarioMainMenu.h"
#include <iostream>



namespace abay

{

	SplashState::SplashState(GameDataRef data) : _data(data)

	{

	}


	void SplashState::Init()

	{

		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		

	}
	void SplashState::HandleInput()

	{

		sf::Event event;



		while (this->_data->window.pollEvent(event))

		{

			if (sf::Event::Closed == event.type)

			{

				this->_data->window.close();

			}

		}

	}



	void SplashState::Update(float dt)

	{

		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOWTIME)

		{
			//std::cout << "Go to Main Menu";
			// Switch To Main Menu
			_data->machine.AddState(StateRef(new MarioMainMenu(this->_data)),true);
			

		}

	}



	void SplashState::Draw(float dt)

	{

		this->_data->window.clear(sf::Color::White);



		this->_data->window.draw(this->_background);



		this->_data->window.display();

	}

}