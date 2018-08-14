#include"stdafx.h"
#include"Blocks.h"
#include"DEFINITIONS.hpp"
#include<iostream>
namespace abay
{
	Block::Block(GameDataRef data) :_data(data)
	{


		sf::Sprite block1;
		sf::Sprite block_piece;
		_data->assets.LoadTexture("Block_Piece", BLOCK_PIECE_FILE_PATH);
		for (int i = 0; i < 4; i++)
		{
			_block_pieces.push_back(block_piece);
			
		}
		for (int i = 0; i < _block_pieces.size(); i++)
		{
			_block_pieces[i].setTexture(_data->assets.GetTexture("Block_Piece"));
			_block_pieces[i].setScale(0.05, 0.05);
			_block_pieces[i].setPosition(-100, -20000);
		}
		
		
		_data->assets.LoadTexture("Block", BLOCK_FILE_PATH);
		_data->assets.LoadTexture("Power Block", POWER_BLOCK_FILE_PATH);
		for (int i = 0; i < NUM_BLOCKS; i++)
		{
			_blocks.push_back(block1);
		}
	

		for (int i = 0; i < _blocks.size(); i++)
		{
			if (i < 5)
			{
				if (i == 3 )
				{
					_blocks[i].setTexture(_data->assets.GetTexture("Power Block"));
					_blocks[i].setPosition(1200 + 56 * i, 600);
					_blocks[i].setScale(0.385, 0.385);

				}
				else
				{
					_blocks[i].setTexture(_data->assets.GetTexture("Block"));
					_blocks[i].setPosition(1200 + 56 * i , 600);
					_blocks[i].setScale(0.04, 0.04);
				}
			}
			else if (i > 4 && i < 10)
			{
				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				_blocks[i].setPosition(4000 + 50 * i, 600);
				_blocks[i].setScale(0.04, 0.04);
			}
			else if (i > 9 && i < 18)
			{
				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				_blocks[i].setPosition(4600 + 50 * i, 800);
				_blocks[i].setScale(0.04, 0.04);

			}
			else if (i > 17 && i< 25)
			{
				if (i == 24)
				{
					_blocks[i].setTexture(_data->assets.GetTexture("Power Block"));
					_blocks[i].setPosition(6000 + 50 * i, 600);
					_blocks[i].setScale(0.385, 0.385);
				}
				else
				{

					_blocks[i].setTexture(_data->assets.GetTexture("Block"));
					_blocks[i].setPosition(6000 + 50 * i, 600);
					_blocks[i].setScale(0.04, 0.04);
				}
			}
			else if (i > 24 && i< 30)
			{

				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				_blocks[i].setPosition(6500 + 50 * i, 600);
				_blocks[i].setScale(0.04, 0.04);
			}
			else if (i > 29 && i< 34)
			{

				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				_blocks[i].setPosition(7000+ 50 * i, 600);
				_blocks[i].setScale(0.04, 0.04);
			}
			else if (i > 33 && i< 40)
			{

				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				_blocks[i].setPosition(7500 + 50 * i, 600);
				_blocks[i].setScale(0.04, 0.04);
			}
			else if (i > 40 && i< 50)
			{
				_blocks[i].setScale(0.04, 0.04);
				_blocks[i].setTexture(_data->assets.GetTexture("Block"));
				if (i < 45)
					_blocks[i].setPosition(8000 + 50 * i, 600);
				else
					_blocks[i].setPosition(7000 + 50 * i, 400);
			}
		}

	
	
	





	}
	void Block::Animate()
	{

		if (_clock.getElapsedTime().asSeconds() > COIN_ANIMATION_DURATION)
		{
			
				if (_blocks[3].getColor() == sf::Color::Yellow)
				{
					_blocks[3].setColor(sf::Color(102, 102, 0, 255));
				}
				else
				{
					_blocks[3].setColor(sf::Color::Yellow);
				}

			}
			_clock.restart();

		}


	void Block::Update(float dt)
	{
		for (int i = 0; i < _blocks.size(); i++)
		{
			_blocks[i].setColor(sf::Color::Black);
		}
	}
	void Block::Draw()
	{
		for (int i = 0; i < _blocks.size(); i++)
		{
			_data->window.draw(_blocks[i]);
			
		}
		for (int i = 0; i < 4; i++)
		{
			_data->window.draw(_block_pieces[i]);
		}
	}
	void Block::move(float x, float y)
	{
		
		for (int i = 0; i < _blocks.size(); i++)
		{
			_blocks[i].move(x, y);
			
		}
	}
	void Block::moveup(float y,unsigned  int i)
	{
		_blocks[i].move(0, y);
	}
	std:: vector<sf::Sprite> Block::GetBlockSprite()
	{
		return _blocks;
	}
	void Block::Animate(unsigned int i)
	{
		
		
		
		
		for (int i = 0; i <_block_pieces.size(); i++)
		{
			_block_pieces[i].setTexture(_data->assets.GetTexture("Block_Piece"));
			_block_pieces[i].setScale(0.04, 0.04);
		}

		
		sf::Vector2f pos = _blocks[i].getPosition();
	
		
		//_blocks.erase(_blocks.begin() + i);
		_blocks[i].move(-100, -110000);
		for (int i  = 0; i < 4; i++)
		{

			_block_pieces[i].setPosition(pos.x + 50 * i, pos.y - i*  +  20 + i);
			
		}
	
		
		
		
	}
	void Block::Motion()
	{
		for (int i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				_block_pieces[i].move(1, 10.f);
				_block_pieces[i].rotate(-4.5f);
			}
			else
			{
				_block_pieces[i].move(-1, 10.f);
				_block_pieces[i].rotate(-4.5f);
			}
		}
	}

	

}