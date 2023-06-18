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

const int SCRN_WIDTH = 640;
const int SCRN_HEIGHT = 480;

int main(int argc, char* args[])
{
	game = new Game();
	game->init("Zach's Game", SCRN_WIDTH, SCRN_HEIGHT);


	SDL_Texture* tex = game->loadTexture("res/bozo.png");
	std::vector<std::unique_ptr<GameObject>> objects;
	objects.push_back(std::make_unique<Player>(Vector2i(640/2, 480/2), tex, "test"));

	while (game->running())
	{
		game->handleEvents();
		
		for (std::unique_ptr<GameObject>& ob : objects)
		{
			game->update(ob);
			game->render(ob);
		}
	}
	game->close();
	return 0;
}