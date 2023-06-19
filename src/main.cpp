#include "Game.h"
#include "Vector2f.h"
#include "GameObject.h"
#include "Player.h"

#include <SDL.h>

#include <memory>
#include <iostream>
#include <vector>

#undef main

Game* game = nullptr;

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Zach's Game", Game::SCRN_WIDTH, Game::SCRN_HEIGHT);


	SDL_Texture* tex = game->loadTexture("res/bozo.png");
	std::vector<std::unique_ptr<GameObject>> objects;
	objects.push_back(std::make_unique<Player>(Vector2i(640/2, 480/2), tex, "test"));

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		
		for (std::unique_ptr<GameObject>& ob : objects)
		{
			game->update(ob);
			game->render(ob);
		}

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->close();
	return 0;
}