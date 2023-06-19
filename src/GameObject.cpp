#include "GameObject.h"
#include "Keyboard.h"

#include <SDL.h>

GameObject::GameObject(Vector2i pos, SDL_Texture* texture)
	:texture(texture), position(pos)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

SDL_Texture* GameObject::getTexture()
{
	return texture;
}

Vector2i GameObject::getPosition()
{
	return position;
}

Vector2f GameObject::getVelocity()
{
	return velocity;
}

SDL_Rect GameObject::getCurrentFrame()
{
	return currentFrame;
}

void GameObject::update()
{
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
}

void GameObject::clamp(int& var, int min, int max)
{
	if (var <= min)
		var = min;
	else if (var >= max)
		var = max;
	else
		var = var;
}

void GameObject::TransformVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

void GameObject::TransformPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
