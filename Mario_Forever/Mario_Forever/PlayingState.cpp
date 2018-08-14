#include"stdafx.h"
#include"PlayingState.h"
#include"Level1.h"
#include"Blocks.h"
#include<iostream>
namespace abay

{
	PlayingState::PlayingState(GameDataRef data) : _data(data)
	{
		CoinBuffer.loadFromFile(COIN_SOUND_FILEPATH);

		CoinSound.setBuffer(CoinBuffer);
		themeBuffer.loadFromFile(MUSIC_PATH);
		theme.setBuffer(themeBuffer);
		BrickSmashBuffer.loadFromFile(BRICK_SMASH_JUMP_SOUND_FILEPATH);
		BrickSmashSound.setBuffer(BrickSmashBuffer);
		theme.play();
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			x[i] = 1.f;
		}
	
		
    }
	void PlayingState:: Init()
	{
		_score = 0;
		std::string score_string = std::to_string(_score);
		_data->assets.LoadFont("Score Font", FONT_MENU_FILEPATH);	
		Score.setFont(_data->assets.GetFont("Score Font"));
		Points.setFont(_data->assets.GetFont("Score Font"));
		 
		Score.setPosition(_data->window.getPosition().x/2 ,_data->window.getPosition().y);
		Points.setPosition(_data->window.getPosition().x / 0.55 , _data->window.getPosition().y);
		Score.setString("Score : ");
	
		Points.setString(score_string);
		
		Score.setCharacterSize(50);
		Points.setCharacterSize(50);
		jumpBuffer.loadFromFile(MARIO_JUMP_SOUND_FILEPATH);
		jumpSound.setBuffer(jumpBuffer);

	
		Playing_BackGround.setScale(1.60, 1.2);
		mario = new Mario(_data);
		block = new Block(_data);
		level1 = new Level1(_data);
		coin = new Coin(_data);
		goomba = new Goomba(_data);
		

	}
	void PlayingState::HandleInput()
	{
		if (mario->GetCurrentState()!=DEAD_STATE)
		{
			for (int i = 0; i < level1->GetGroundSprite().size(); i++)
			{
				if (mario->GetSprite().getGlobalBounds().intersects(level1->GetGroundSprite()[i].getGlobalBounds()))
				{

					mario->SetState(STILL_STATE);
					jumpSound.pause();
				}

			}

			sf::Event event;
			while (_data->window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_data->window.close();
				}
				if (mario->GetCurrentState() == STILL_STATE)
				{

					if (event.key.code == (sf::Keyboard::X))
					{
						mario->Jump();
						jumpSound.play();
					}
				}


			}


		}

	}

	/*UPDATE FUNCTION*/


	void PlayingState::Update(float dt)
	{ 
		static bool collided = false;
		static bool Collision = false;
		
		mario->Update(dt);

		if (mario->GetCurrentState() != DEAD_STATE)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{

				mario->SwitchScale2();

				if (mario->GetCurrentState() != 1 && mario->GetCurrentState() != 3)
				{
					mario->Animate();
				}

				level1->MoveLevel1(-MARIO_SPEED, 0);
				coin->move(-MARIO_SPEED, 0);

				goomba->Move(-MARIO_SPEED);
				if (checkCollisionwithPipe())
				{
					level1->MoveLevel1(MARIO_SPEED, 0);
					coin->move(MARIO_SPEED, 0);
					goomba->Move(MARIO_SPEED);

				}





			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{

				mario->SwitchScale();
				if (mario->GetCurrentState() != 1 && mario->GetCurrentState() != 3)
				{
					mario->Animate();
				}

				level1->MoveLevel1(MARIO_SPEED, 0);
				coin->move(MARIO_SPEED, 0);
				goomba->Move(MARIO_SPEED);


				if (checkCollisionwithPipe())
				{
					level1->MoveLevel1(-MARIO_SPEED, 0);
					coin->move(-MARIO_SPEED, 0);

					goomba->Move(-MARIO_SPEED);
				}

			}

		}
		

		for (int i = 0; i < level1->GetGroundSprite().size(); i++)
		{
			
				if (mario->GetSprite().getGlobalBounds().intersects(level1->GetGroundSprite()[i].getGlobalBounds()))
					

				{
				
					mario->SetState(STILL_STATE);
					jumpSound.pause();
					if (mario->GetSprite().getPosition().y > level1->GetGroundSprite()[i].getPosition().y-40.f
						)
					{
						mario->GetSprite().setPosition(sf::Vector2f(mario->GetSprite().getPosition().x, 
							level1->GetGroundSprite()[i].getPosition().y-40.f));
						
					}
				
					  
				}
			
			else 
			{
				if (mario->GetCurrentState() != FLYING_STATE)
				{
					mario->SetState(FALLING_STATE);
				}
			}
			
		}
		
		for (int i = 0; i < level1->GetPipeSprite().size(); i++)
		{
			if (collision_detector->CheckSpriteCollision(mario->GetSprite(), level1->GetPipeSprite()[i]))
			{
				
				mario->SetState(STILL_STATE);
				break;
			}
			else
			{
				

			}

		}
		
		
		
		
		for (int i = 0; i < level1->GetBlockSprite().size(); i++)
		{
			if (collision_detector->CheckSpriteCollision(mario->GetSprite(), level1->GetBlockSprite()[i]))
				
			{
				mario->SetState(STILL_STATE);
				
				if (mario->GetSprite().getPosition().y > level1->GetBlockSprite()[i].getPosition().y +30)
				{
				  
					mario->SetState(FALLING_STATE);
					
					
					if (i != 3&&i!=24)
					{
						level1->AnimateBlocks(i);
						collided = true;
						BrickSmashSound.play();
					}
						
					
			
				
					
				}
				else if (mario->GetSprite().getPosition().y > level1->GetBlockSprite()[i].getPosition().y - 40.f)
				{
					mario->GetSprite().setPosition(mario->GetSprite().getPosition().x,
						level1->GetBlockSprite()[i].getPosition().y - 40.f);
				}
			
				

				break;
			}
			else
			{

			}

		}
		std::vector<sf::Sprite> Coin_Sprite = coin->GetCoinSprite();
		for (int i = 0; i < Coin_Sprite.size(); i++)
		{
			if (mario->GetSprite().getGlobalBounds().intersects(Coin_Sprite[i].getGlobalBounds()))
			{
				_score++;
				coin->vanish(i);
				CoinSound.play();
			}
		}
		std::vector<sf::Sprite> Goombaas;
		Goombaas = goomba->GetGoombaSprite();
		
	
		for (int i = 0; i < NUM_GOOMBAAS; i++)
		{
			if (Goombaas[i].getGlobalBounds().intersects(mario->GetSprite().getGlobalBounds()) && goomba
				->IsAlive(i) == 1 && Goombaas[i].getPosition().y -10 > mario->GetSprite().getPosition().y)
			{

				goomba->Death(i);
				mario->SetState(MINI_FLYING_STATE);
				
				
			}
			if (Goombaas[i].getGlobalBounds().intersects(mario->GetSprite().getGlobalBounds()))
			{
				if (goomba->IsAlive(i) == 1)
				{
					mario->SetdeadSprite();
					mario->SetState(DEAD_STATE);
					
				}
				
							
			}
			
			
		
		

			if (goomba->IsAlive(i) == 1)
			{
				if (CheckGoombaCollision(i))
				{
					
					x[i] = x[i] * -1;
					
				}
			
			}
			
			if (goomba->IsAlive(i))
			{
				goomba->Motion(x[i], i);
			}
			
		
			
			
		
			
		}
		
	   

		coin->Animate();
		std::string dummy = std::to_string(_score);
		Points.setString(dummy);

		if (collided)
		{
			level1->Motion();
		}
		
	}
	void PlayingState::Draw(float dt)
	{
		_data->window.clear();
		level1->Draw();
		mario->Draw();
		coin->Draw();
		goomba->Draw();
		_data->window.draw(Score);
		_data->window.draw(Points);
		_data->window.display();

	}
	bool PlayingState::checkCollisionwithPipe()
	{
		for (int i = 0; i < level1->GetPipeSprite().size(); i++)
		{
			if (mario->GetSprite().getPosition().y > level1->GetPipeSprite()[i].getPosition().y - 20.f)
			{
				if (collision_detector->CheckSpriteCollision(mario->GetSprite(),
					level1->GetPipeSprite()[i]))
				{
					


					
					return true;
					//break;
				}
			}
			else
			{
				return false;
			}

		}

	}
	bool  PlayingState::CheckGoombaCollision(unsigned int i)
	{
		std::vector<sf::Sprite> Goombaas = goomba->GetGoombaSprite();
		
			for (int j = 0; j < 3; j++)
			{
				if (Goombaas[i].getGlobalBounds().intersects(level1->GetPipeSprite()[j].getGlobalBounds()))
				{
					return true;
				}
			}
		

			return false;



	}

}
