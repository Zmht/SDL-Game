#include "Game.h"
#include "GameObject.h"
#include "Keyboard.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <memory>

SDL_Event Game::event;

Game::Game()
{
	window = NULL;
	renderer = NULL;
}

void Game::init(const char* title, int w, int h)
{



	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL couldn't initialize. SDL_Error: " << SDL_GetError() << std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_Init failed! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Couldn't create window. SDL_Error: " << SDL_GetError() << std::endl;
			isRunning = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				isRunning = true;
			}
		}
	}
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::clear()
{
	SDL_RenderClear(renderer);
}

void Game::update(std::unique_ptr<GameObject>& obj)
{
	obj->update();
}

void Game::render(std::unique_ptr<GameObject>& obj)
{
	SDL_Rect src;
	src = obj->getCurrentFrame();
	SDL_Rect dst;
	dst.x = obj->getPosition().x;
	dst.y = obj->getPosition().y;
	dst.w = obj->getCurrentFrame().w;
	dst.h = obj->getCurrentFrame().h;
	SDL_RenderCopy(renderer, obj->getTexture(), &src, &dst);
	SDL_RenderPresent(renderer);
}

void Game::close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::running()
{
	return isRunning;
}

SDL_Texture* Game::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == NULL)
	{
		std::cout << "Couldn't load texture at file path: " << filePath << " SDL_Error: " << SDL_GetError() << std::endl;
	}
	return texture;
}
