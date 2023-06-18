#include "Player.h"
#include "Keyboard.h"
#include "Game.h"

#include <iostream>


Player::Player(Vector2i pos, SDL_Texture* texture, const char* name)
	:GameObject(pos, texture), name(name)
{
	keyDown[0] = false;
	keyDown[1] = false;
	keyDown[2] = false;
	keyDown[3] = false;

	speed = 1;
}


void Player::update() 
{
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;

	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
			velocity.y = -1;
			break;
		case SDLK_DOWN:
			velocity.y = 1;
			break;
		case SDLK_RIGHT:
			velocity.x = 1;
			break;
		case SDLK_LEFT:
			velocity.x = -1;
			break;
		default:
			break;
		}
	}
	else if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
			velocity.y = 0;
			break;
		case SDLK_DOWN:
			velocity.y = 0;
			break;
		case SDLK_RIGHT:
			velocity.x = 0;
			break;
		case SDLK_LEFT:
			velocity.x = 0;
			break;
		default:
			break;
		}
	}

}
