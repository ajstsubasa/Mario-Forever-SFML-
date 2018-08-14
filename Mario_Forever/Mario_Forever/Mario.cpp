#include"stdafx.h"
#include"Mario.h"
#include<iostream>
#include"DEFINITIONS.hpp"

namespace abay
{
	Mario::Mario(GameDataRef data) : _data(data)
	{
		
		_data->assets.LoadTexture("Mario1", MARIO_FRAME_01);
		_data->assets.LoadTexture("Mario2", MARIO_FRAME_02);
		_data->assets.LoadTexture("Mario3", MARIO_FRAME_03);
		_data->assets.LoadTexture("Mario_Dead", MARIO_DEATH);
		_animation_Iterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Mario1"));
		_animationFrames.push_back(_data->assets.GetTexture("Mario2"));
	
		Mario_Sprite.setTexture(_animationFrames.at(_animation_Iterator));
		Mario_Sprite.setOrigin(Mario_Sprite.getGlobalBounds().width / 2,
			Mario_Sprite.getGlobalBounds().height / 2);
		Mario_Sprite.setPosition(470, 810);
		Mario_Sprite.setScale(SCALEX, SCALEY);
	
		isDead = false;
		Mario_State = STILL_STATE;
	}
	void Mario::Draw()
	{
		_data->window.draw(Mario_Sprite);
		
	}
	void Mario::Update(float dt)
	{
		static float velocity = JUMP_DISTANCE;
		 if (FLYING_STATE == Mario_State)
		{
			
			velocity += GRAVITY;
		
				Mario_Sprite.move(0, velocity* dt);
			
			
			Mario_Sprite.setTexture(_data->assets.GetTexture("Mario3"));
	
		

		}
		 if (Mario_State == MINI_FLYING_STATE)
		 {        
			 velocity = (5 * JUMP_DISTANCE) / 4;
			 Mario_Sprite.move(0, velocity* dt);

			
			 
			 

		 }
		 if (STILL_STATE == Mario_State)
		{
			velocity = JUMP_DISTANCE;
			
		}
		 if (FALLING_STATE == Mario_State)
		 {
			 Mario_Sprite.move(0, -JUMP_DISTANCE/2*dt);
		 }
		 if (DEAD_STATE == Mario_State)
		 {
			 isDead = true;
			 
		 }
		
		
		
		 
			
	
			
	  
			

	}
	void Mario::Death()
	{
		
	}

	void Mario::Jump()
	{
		 
			Mario_State = FLYING_STATE;
		
	

	}
	int Mario::GetCurrentState()
	{
		return Mario_State;
	}
	void Mario::Animate()
	{
		
			if (_clock.getElapsedTime().asSeconds() > MARIO_ANIMATION_DURATION / _animationFrames.size())
			{
				if (_animation_Iterator < _animationFrames.size() - 1)
				{
					_animation_Iterator++;
				}
				else
				{
					_animation_Iterator = 0;
				}

				Mario_Sprite.setTexture(_animationFrames.at(_animation_Iterator));
				_clock.restart();

			}



		
	}

	

	void Mario::SwitchScale()
	{
		
			Mario_Sprite.setScale(-SCALEX, SCALEY);
		
	}
	void Mario::SwitchScale2()
	{
		Mario_Sprite.setScale(SCALEX,SCALEY);
	}
	sf::Sprite& Mario::GetSprite()
	{
		return Mario_Sprite;
	}
	void Mario::SetState(int state)
	{
		Mario_State = state;

	}
	void Mario::SetdeadSprite()
	{
		Mario_Sprite.setTexture(_data->assets.GetTexture("Mario_Dead"));
		Mario_Sprite.setScale(3, 3);
		
	}
	bool Mario::isMarioDead()
	{
		return isDead;
	}


}