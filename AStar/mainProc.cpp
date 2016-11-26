#include"AStar.h"
#include"MyMap.h"
#include"MapInfo.h"

// ∏„ ¡§∫∏
int cost1[MAXNODEY][MAXNODEX] = {
	// 0 = ∫Æ
	// 1 = ±Ê
	//	   0 1   2		3 4  
	/*0*/{ 0,0,	0,		0,0 },
	/*1*/{ 0,1,	1,		1,0 },
	/*2*/{ 0,1,	1,		1,0 },
	/*3*/{ 0,1,	0,		1,0 },
	/*4*/{ 0,1,	0,		1,0 },
	/*5*/{ 0,1,	0,		1,0 },
	/*6*/{ 0,0,	0,		0,0 }
};

int main()
{
	Position start(1, 5);
	Position end(3, 5);
	CMyMap myMap(MAXNODEX, MAXNODEY);
	// ∏„ √ ±‚»≠
	int* map[MAXNODEY];
	for (int i = 0; i < MAXNODEY; i++)
		map[i] = new int[MAXNODEX];

	for (int i = 0; i < MAXNODEY; i++)
		for (int j = 0; j < MAXNODEX; j++)
			map[i][j] = cost1[i][j];

	myMap.setMap(map);

	CAStar aStar;
	
	aStar.findPath(start, end, myMap);
	myMap.draw(start, end);
	aStar.draw();
	return 1;
}