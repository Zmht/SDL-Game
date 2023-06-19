#pragma once

#include "Vector2f.h"
#include "Vector2i.h"

#include <SDL.h>

#include <iostream>

class GameObject
{
public:
	GameObject(Vector2i pos, SDL_Texture* texture);
	SDL_Texture* getTexture();
	Vector2i getPosition();
	Vector2f getVelocity();
	SDL_Rect getCurrentFrame();

	virtual void update();
	void clamp(int& var, int min, int max);
	void TransformVelocity(float x, float y);
	void TransformPosition(int x, int y);

protected:
	Vector2i position;
	Vector2f velocity;
	float speed{};

	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

