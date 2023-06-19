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

	speed = 6;
}


void Player::update() 
{
	GameObject::update();

	clamp(position.x, 0, Game::SCRN_WIDTH - 32);
	clamp(position.y, 0, Game::SCRN_HEIGHT - 32);

	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
			//velocity.y = -1;
			keyDown[0] = true;
			break;
		case SDLK_DOWN:
			//velocity.y = 1;
			keyDown[1] = true;
			break;
		case SDLK_RIGHT:
			//velocity.x = 1;
			keyDown[2] = true;
			break;
		case SDLK_LEFT:
			//velocity.x = -1;
			keyDown[3] = true;
			break;
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_UP:
			//velocity.y = 0;
			keyDown[0] = false;
			break;
		case SDLK_DOWN:
			//velocity.y = 0;
			keyDown[1] = false;
			break;
		case SDLK_RIGHT:
			//velocity.x = 0;
			keyDown[2] = false;
			break;
		case SDLK_LEFT:
			//velocity.x = 0;
			keyDown[3] = false;
			break;
		default:
			break;
		}
	}
	if (keyDown[0])
		velocity.y = -1;
	if (keyDown[1])
		velocity.y = 1;

	if (keyDown[2])
		velocity.x = 1;
	if (keyDown[3])
		velocity.x = -1;

	if (!keyDown[0] && !keyDown[1])
		velocity.y = 0;
	if (!keyDown[2] && !keyDown[3])
		velocity.x = 0;

}
