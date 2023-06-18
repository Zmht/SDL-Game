#include "Player.h"
#include "Keyboard.h"

#include <iostream>


Player::Player(Vector2i pos, SDL_Texture* texture, const char* name)
	:GameObject(pos, texture), name(name)
{

}


void Player::update() 
{
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;

	if (Keyboard::getKeyState(SDLK_UP))
		velocity.y = -1;
	else if (Keyboard::getKeyState(SDLK_DOWN))
		velocity.y = 1;
	else
		velocity.y = 0;
	if (Keyboard::getKeyState(SDLK_RIGHT))
		velocity.x = 1;
	else if (Keyboard::getKeyState(SDLK_LEFT))
		velocity.x = -1;
	else 
		velocity.x = 0;

}
