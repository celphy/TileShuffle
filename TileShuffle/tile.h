#include "stdafx.h"


#define tileSize 24

class tile{
private:
	long R, G, B;
	POINT ori;

public:
	tile();
	tile(long x, long y);
	~tile();
	long getRed(void);
	long getGreen(void);
	long getBlue(void);
	POINT getOri(void);
	bool rotate(void);
	void color(void);
};