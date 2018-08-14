#include"stdafx.h"
#include"Coin.h"
#include"DEFINITIONS.hpp"
namespace abay
{
	Coin::Coin(GameDataRef data) :_data(data)
	{
		sf::Sprite coin1;
		_data->assets.LoadTexture("Coin1", COIN_FRAME_1);
		_data->assets.LoadTexture("Coin2", COIN_FRAME_1);


		_animation_Iterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Coin1"));
		_animationFrames.push_back(_data->assets.GetTexture("Coin2"));

		for (int i = 0; i < NUM_COINS; i++)
		{
			_Coins.push_back(coin1);

		}
		for (int i = 0; i < NUM_COINS; i++)
		{
			_Coins[i].setOrigin(_Coins[i].getGlobalBounds().width, _Coins[i].getGlobalBounds().height);
			_Coins[i].setTexture(_data->assets.GetTexture("Coin1"));
			_Coins[i].setScale(0.5, 0.5);
			_Coins[i].setColor(sf::Color::Yellow);
		}
		for (int i = 0; i < _Coins.size(); i++)
		{
			if (i < 5)
			{

				_Coins[i].setPosition(sf::Vector2f(1200 + 50 * i, 520));

			}
			else if (i > 4 && i < 15)
			{
				_Coins[i].setPosition(sf::Vector2f(2500 + 50 * i, 520 + i / 2));


			}
			else if (i > 14 && i < 20)
			{

				_Coins[i].setPosition(sf::Vector2f(4000 + 50 * i, 520 -  i ));


			}
			else if (i > 19 && i < 30)
			{

				_Coins[i].setPosition(sf::Vector2f(5000 + 50 * i, 920 - i * i  ));

			}
			else if (i > 29 && i < 35)
			{
				_Coins[i].setPosition(sf::Vector2f(5400 + 50 * i, 520));
			}



		}
	}
	void Coin::Animate()
	{
		
			if (_clock.getElapsedTime().asSeconds() > COIN_ANIMATION_DURATION )
			{
				for (int i = 0; i < _Coins.size(); i++)
				{
					if (_Coins[i].getColor() == sf::Color::Yellow)
					{
						_Coins[i].setColor(sf::Color(102, 102, 0, 255));
					}
					else
					{
						_Coins[i].setColor(sf::Color::Yellow);
					}

				}
				_clock.restart();

			}

	}
	void Coin::Draw()
	{
		for (int i = 0; i < _Coins.size(); i++)
		{
			_data->window.draw(_Coins[i]);
		}

	}
	
	void Coin::Update(float dt)
	{

	}
	void Coin::move(float x, float y)
	{
		
		for (int i = 0; i < _Coins.size(); i++)
		{
			_Coins[i].move(x, y);
		}

	}
	std::vector<sf::Sprite> Coin::GetCoinSprite()
	{
		return _Coins;
	}
	void Coin::vanish(unsigned int i)
	{
		_Coins.erase(_Coins.begin() + i);
	}






}
