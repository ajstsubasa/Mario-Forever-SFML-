#include"stdafx.h"
#include"Level1.h"
#include"DEFINITIONS.hpp"
#include<iostream>
namespace abay
{
	Level1::Level1(GameDataRef data) : _data(data)
	{
		_block = new Block(_data);
		_coin = new Coin(_data);

		_data->assets.LoadTexture("Playing BackGround", PLAYING_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Ground", GROUND_FILEPATH);
		_data->assets.LoadTexture("PipeUp", MARIO_PIPE_FILEPATH);
		this->Playing_BackGround.setTexture(_data->assets.GetTexture("Playing BackGround"));
		Playing_BackGround.setScale(1.60, 1.2);
		sf::Sprite ground;
		for (int i = 0; i < NUM_GROUNDS; i++)
		{
			Ground.push_back(ground);
		}
		
		for (int i = 0; i < Ground.size(); i++)
		{
			
			this->Ground[i].setTexture(_data->assets.GetTexture("Ground"));
			if (i == 0)
			{
				this->Ground[0].setPosition(0, 850);
			}
			if (i == 4)
			{
				this->Ground[i].setPosition(780 * i + 600.f, 850);
			}
			else if (i>4 && i <6)
			{
				this->Ground[i].setPosition(780 * i  , 850);
			}
			else 
			{
				this->Ground[i].setPosition(780 * i + 200, 850);
			}
			this->Ground[i].setScale(1, 1);
		}
		sf::Sprite Pipe1;
		sf::Sprite Pipe2;
		sf::Sprite Pipe3;
		Pipes.push_back(Pipe1);
		Pipes.push_back(Pipe2);
		Pipes.push_back(Pipe3);
		for (int i = 0; i < Pipes.size(); i++)
		{
			Pipes[i].setTexture(_data->assets.GetTexture("PipeUp"));
			Pipes[i].setPosition(2000 + 500 * i, 700);
		
		}

	}
	void Level1::Draw()
	{
		
			_data->window.draw(this->Playing_BackGround);
		for (int i = 0; i < this->Ground.size(); i++)
		{
			_data->window.draw(this->Ground[i]);
		}
		_block->Draw();
	
		for (int i = 0; i < Pipes.size(); i++)
		{
			_data->window.draw(Pipes[i]);
		}
	}
	void Level1::MoveLevel1(float x, float y)
	{
		if (x < 0)
		{
			for (int i = 0; i < this->Ground.size(); i++)
			{

				Ground[i].move(x, 0);
			}
			_block->move(x, y);
			_block->GetBlockSprite()[0].setColor(sf::Color::Black);
			for (int i = 0; i < this->Pipes.size(); i++)
			{

				Pipes[i].move(x, 0);
			}
		}
		else
		{
			if (Ground[0].getPosition().x > 450.f)
			{
			}
			else
			{
				for (int i = 0; i < this->Ground.size(); i++)
				{
					Ground[i].move(x, 0);
				

				}
				_block->move(x, y);
			
				for (int i = 0; i < Pipes.size(); i++)
				{
					Pipes[i].move(x, y);
				}
				
			}
		
		}
		

	}
	void Level1::PauseLevel1()
	{

	}

	std::vector<sf::Sprite> Level1::GetGroundSprite()
	{
		return Ground;
	}
	std::vector<sf::Sprite> Level1::GetBlockSprite()
	{
		return _block->GetBlockSprite();
	}
	std::vector<sf::Sprite> Level1::GetPipeSprite()
	{
		return Pipes;
	}
	void Level1::AnimateBlocks(unsigned int i)
	{
		_block->Animate(i );
	}
	void Level1::Motion()
	{
		_block->Motion();
	}

}
