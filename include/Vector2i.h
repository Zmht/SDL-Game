#pragma once
class Vector2i
{
public:
	Vector2i()
		:x(0), y(0)
	{}
	Vector2i(int x, int y)
		:x(x), y(y)
	{}
	int x, y;
};