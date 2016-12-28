#include "stdafx.h"
#include "tile.h"

tile::tile(long x, long y){
	ori.x = x;
	ori.y = y;
	R = rand()%255 + 1;
	G = rand()%255 + 1;
	B = rand()%255 + 1;
	
};

POINT tile::getOri(void){
	return ori;
}

void tile::color(void){
	R = rand()%255 + 1;
	G = rand()%255 + 1;
	B = rand()%255 + 1;
}

long tile::getRed(void){
	return R;
}

long tile::getGreen(void){
	return G;
}

long tile::getBlue(void){
	return B;
}

bool tile::rotate(void){
	 if(R == 1 && B == 1 && G == 1){
		R=254;
		B=254;
		G=254;
	} else {
	R = 1;
	B = 1;
	G = 1;
	}
	
	return false;
}