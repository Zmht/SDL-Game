#pragma once

#include "GameObject.h"

#include <SDL.h>

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int width, int height);
	void handleEvents();
	void update(std::unique_ptr<GameObject>& obj);
	void render(std::unique_ptr<GameObject>& obj);
	void close();
	bool running();

	static SDL_Event event;
	SDL_Texture* loadTexture(const char* filePath);

	static constexpr int SCRN_WIDTH = 640;
	static constexpr int SCRN_HEIGHT = 480;
private:
	
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
};

