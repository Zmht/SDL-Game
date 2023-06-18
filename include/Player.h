#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(Vector2i pos, SDL_Texture* texture, const char* name);
	void update() override;
	
private:
	const char* name;
	bool keyDown[4];
};

