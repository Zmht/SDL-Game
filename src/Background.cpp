#include "Background.h"
#include "Vector2i.h"

#include <SDL.h>

Background::Background(SDL_Texture* tex)
	:GameObject(Vector2i(0,0), tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 640;
	currentFrame.h = 480;
}

void Background::update()
{

}
