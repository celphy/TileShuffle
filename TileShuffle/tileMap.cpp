#include "stdafx.h"
#include "tileMap.h"


void tileMap::win(void){
	solved = true;
}

bool tileMap::check(void){
	long R, G, B;
	R = map[0][0]->getRed();
	B = map[0][0]->getBlue();
	G = map[0][0]->getGreen();
	for(int i=0; i < width; i++){
		for(int j=0; j < height; j++){
			if( map[i][j]->getRed() != R ||
				map[i][j]->getBlue() != B ||
				map[i][j]->getGreen() != G)
				return false;
		}
	}
	return true;
}

void tileMap::over(POINT p){
	int i = 0;
	int j = 0;
	if(p.x > 800 || p.y > 530)
		return;
	if(p.x < 0 || p.y < 0)
		return;

	while(map[i][j]->getOri().x < p.x){
		i++;
		if(i > width-1){
			i = width-1;
			break;
		}
	}

	while(map[i][j]->getOri().y < p.y){
		j++;
		if(j > height-1){
			j = height-1;
			break;
		}
	}
	if(i > 0 && p.x < map[width-1][0]->getOri().x)
		i--;
	if(j > 0 && p.y < map[0][height-1]->getOri().y)
		j--;
	
	if(lastX != i && !solved || lastY != j && !solved){
		map[i][j]->rotate();
		if(check())
			win();
		//solved = check();
	} else if(solved) {
	map[i][j]->color();
	}
	lastX = i;
	lastY = j;
}

tileMap::tileMap(int width, int height){
	map = new tile**[width];
	this->width = width;
	this->height = height;
	for(int i=0; i<width; i++){
		map[i] = new tile*[height];
		for(int j=0; j<height; j++){
			map[i][j] = new tile((1+i)*2+i*tileSize, (1+j)*2+j*tileSize);
		}
	}
	solved = false;
}

void tileMap::draw(HDC hdc){
	POINT o;
	RECT rect;
	long R, G, B;
	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			o = map[i][j]->getOri();
			R = map[i][j]->getRed();
			G = map[i][j]->getGreen();
			B = map[i][j]->getBlue();
			rect.left = o.x;
			rect.top = o.y;
			rect.bottom = o.y+tileSize;
			rect.right = o.x+tileSize;
			HBRUSH hCustomBrush;
			hCustomBrush = CreateSolidBrush(RGB(R, G, B));
			FillRect(hdc, &rect, hCustomBrush);
			DeleteObject(hCustomBrush);
		}
	}
}

int tileMap::getHeight(void){
	return height;
}

int tileMap::getWidth(void){
	return width;
}

tileMap::~tileMap(void)
{
}

tileMap::tileMap(void)
{
}

/*void tileMap::over(POINT p){
	int i = 0;
	int j = 0;

	if(p.x < 0 || p.y < 0)
		return;

	while(map[i][j]->getOri().x < p.x){
		i++;
		if(i > width-1)
			return;
	}

	while(map[i][j]->getOri().y < p.y){
		j++;
		if(j > height -1)
			return;
	}
	if(i > 0 && p.x < map[width-1][0]->getOri().x)
		i--;
	if(j > 0 && p.y < map[0][height-1]->getOri().y)
		j--;
	
	if(lastX != i || lastY != j)
		map[i][j]->rotate();

	lastX = i;
	lastY = j;
}*/