#include"stdafx.h"
#include"DEFINITIONS.hpp"
#include"MarioMainMenu.h"
#include<iostream>
#include"PlayingState.h"

namespace abay
{

	MarioMainMenu::MarioMainMenu(GameDataRef data) :_data(data)
	{
		

	}
	void 	MarioMainMenu::Init()
	{
		this->_data->assets.LoadTexture("Main Menu BackGround", MAIN_MENU_BACKGROUND_FILEPATH);
		this->MenuBackground.setTexture(_data->assets.GetTexture("Main Menu BackGround"));
		this->MenuBackground.setScale(1.25, 1.25);
		this->_data->assets.LoadFont("Start Game Font", FONT_MENU_FILEPATH);
		this->StartGame.setFont(this->_data->assets.GetFont("Start Game Font"));
		StartGame.setPosition(sf::Vector2f(250, 250));
		StartGame.setCharacterSize(50);
		StartGame.setString("Start Game");
		StartGame.setFillColor(sf::Color::Red);
		this->_data->assets.LoadFont("Start Game Font", FONT_MENU_FILEPATH);
		this->QuitGame.setFont(this->_data->assets.GetFont("Start Game Font"));
		QuitGame.setPosition(sf::Vector2f(250, 450));
		QuitGame.setCharacterSize(50);
		QuitGame.setString("Quit Game");
		QuitGame.setFillColor(sf::Color::Red);

		this->CoinBuffer.loadFromFile(COIN_SOUND_FILEPATH);
		this->CoinSound.setBuffer(CoinBuffer);


	}
	void MarioMainMenu::HandleInput()
	{
		
		sf::Event event;
		
		while (this->_data->window.pollEvent(event))

		{

			if (sf::Event::Closed == event.type)

			{

				this->_data->window.close();

			}

		}
		static bool hover_count = 0;
		if (_data->input.isTextHovered(StartGame, _data->window))
		{
		
			
			StartGame.setFillColor(sf::Color::White);
			StartGame.setCharacterSize(70);
			if ( ! hover_count )
			{
				CoinSound.play();
				hover_count = true;
			}
			
			
			
		}

		else
		{
			
				StartGame.setFillColor(sf::Color::Red);
				StartGame.setCharacterSize(50);
				hover_count = 0;
			
			
		}
		static bool hover_count2 = 0;
		if (_data->input.isTextHovered(QuitGame, _data->window))
		{
			
			QuitGame.setFillColor(sf::Color::White);
			QuitGame.setCharacterSize(70);
			if (!hover_count2)
			{
				CoinSound.play();
				hover_count2 = true;
			}
			
		
		
			
		}
		else
		{

			QuitGame.setFillColor(sf::Color::Red);
			QuitGame.setCharacterSize(50);
			hover_count2 = 0;
			
		}
		


	}

	 void MarioMainMenu::Update(float dt)
	 {
		 if (_data->input.isTextHovered(StartGame, _data->window))
		 {
			 if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			 {
				 _data->machine.AddState(StateRef(new PlayingState(this->_data)), true);

			 }
		 }
		 if (_data->input.isTextHovered(QuitGame, _data->window))
		 {
			 if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			 {
				 _data->window.close();

			 }
		 }











	 }
	 void MarioMainMenu::Draw(float dt)
	 {
		 _data->window.clear(sf::Color::Red);
		 _data->window.draw(MenuBackground);
		 _data->window.draw(StartGame);
		 _data->window.draw(QuitGame);
		 _data->window.display();

	 }





}