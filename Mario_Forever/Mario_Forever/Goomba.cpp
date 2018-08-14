#include"stdafx.h"
#include"Goomba.h"
#include<iostream>
#include"DEFINITIONS.hpp"
namespace abay
{
	Goomba::Goomba(GameDataRef data) :_data(data)
	{
		_data->assets.LoadTexture("Goomba", GOOMBA_FILEPATH);
		_data->assets.LoadTexture("DeadGoomba", DEAD_GOOMBA_FILEPATH);
		GoombaSprite.setTexture(_data->assets.GetTexture("Goomba"));
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			Goombaas.push_back(GoombaSprite);
		}
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			Goombaas[i].setPosition(sf::Vector2f(2100.f + 2000 * i, 810.f));
			Goombaas[i].setScale(2.7, 2.7);
		}
	
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			Goomba_is_Alive[i] = 1;
		}
	}
	void Goomba::Draw()
	{
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			_data->window.draw(Goombaas[i]);
		}
	}
	void Goomba::Move(float x)
	{
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			Goombaas[i].move(x, 0);
		}

	}
	void Goomba::Motion(float x,unsigned int i)
	{
		
			Goombaas[i].move(x, 0);
		
	}
	void Goomba::Death(unsigned int i)
	{
		Goombaas[i].setTexture(_data->assets.GetTexture("DeadGoomba"));
		Goombaas[i].move(0, 15.f);

		Goomba_is_Alive[i] =0;
		
	}
	std::vector<sf::Sprite> Goomba::GetGoombaSprite()
	{
		return Goombaas;
	}
	int  Goomba::IsAlive(unsigned int i)
	{
		return Goomba_is_Alive[i];
	}
}