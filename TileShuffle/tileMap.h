#pragma once
#include "tile.h"

class tileMap
{
private:
	tile*** map;
	int width;
	int height;
	int lastX;
	int lastY;
	void win(void);
	bool check(void);
	bool solved;
public:
	tileMap(void);
	tileMap(int width, int height);
	~tileMap(void);
	void draw(HDC hdc);
	void over( POINT p);
	int getWidth(void);
	int getHeight(void);
	
};

