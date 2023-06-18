#include "Keyboard.h"
#include "Game.h"

#include <SDL.h>



bool Keyboard::getKeyState(SDL_Keycode key)
{
	bool isDown = false;
	if (Game::event.type == SDL_KEYDOWN)
	{
		if (Game::event.key.keysym.sym == key)
		{
			isDown = true;
		}
	}
	else if (Game::event.type == SDL_KEYUP)
	{
		if (Game::event.key.keysym.sym == key)
		{
			isDown = false;
		}	
	}
	return isDown;
}
