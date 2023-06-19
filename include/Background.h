#pragma once

#include "GameObject.h"

#include <SDL.h>

class Background : public GameObject
{
public:
	Background(SDL_Texture* tex);

	void update() override;

private:
};

