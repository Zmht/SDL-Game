#include "Player.h"
#include "Keyboard.h"

#include <iostream>


Player::Player(Vector2i pos, SDL_Texture* texture, const char* name)
	:GameObject(pos, texture), name(name)
{
	keyDown[0] = false;
	keyDown[1] = false;
	keyDown[2] = false;
	keyDown[3] = false;
}


void Player::update() 
{
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;

	if (Keyboard::getKeyState(SDLK_UP))
	{
		velocity.y = -1;
		keyDown[0] = true;
	}
	if (!Keyboard::getKeyState(SDLK_UP))
	{
		velocity.y = 0;
		keyDown[0] = false;
	}
	if (Keyboard::getKeyState(SDLK_DOWN))
	{
		velocity.y = 1;
		keyDown[1] = true;
	}
	if (!Keyboard::getKeyState(SDLK_DOWN))
	{
		velocity.y = 0;
		keyDown[1] = false;
	}
	if (Keyboard::getKeyState(SDLK_RIGHT))
	{
		velocity.x = 1;
		keyDown[2] = true;
	}
	if (!Keyboard::getKeyState(SDLK_RIGHT))
	{
		velocity.x = 0;
		keyDown[2] = false;
	}
	if (Keyboard::getKeyState(SDLK_LEFT))
	{
		velocity.x = -1;
		keyDown[3] = true;
	}
	if (!Keyboard::getKeyState(SDLK_LEFT))
	{
		velocity.x = 0;
		keyDown[3] = false;
	}
	if (!keyDown[0] && !keyDown[1])
	{
		velocity.x = 0;
	}
	if (!keyDown[2] && !keyDown[3])
	{
		velocity.y = 0;
	}

}
