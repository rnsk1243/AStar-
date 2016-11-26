#include "AStar.h"
#include"MapInfo.h"
#include"MyMap.h"
#include<iostream>
using namespace std;

CAStar::CAStar():curX(0),curY(0)
{
}


CAStar::~CAStar()
{
}
// 8방향 이동
void CAStar::setNext(int nextIndex)
{
	switch (nextIndex)
	{
	case 0:
		curY--;
		break;
	case 1:
		curX++;
		curY--;
		break;
	case 2:
		curX++;
		break;
	case 3:
		curX++;
		curY++;
		break;
	case 4:
		curY++;
		break;
	case 5:
		curX--;
		curY++;
		break;
	case 6:
		curX--;
		break;
	case 7:
		curX--;
		curY--;
		break;
	}
}

bool CAStar::findPath(Position start, Position dest, CMyMap map)
{
	int** visit = new int*[MAXNODEY];
	for (int i = 0; i < MAXNODEY; i++)
	{
		visit[i] = new int[MAXNODEX];
	}

	for (int i = 0; i < MAXNODEY; i++)
	{
		for (int j = 0; j < MAXNODEX; j++)
		{
			visit[i][j] = 1;
		}
	}
	// 멥 가져옴
	int** gameMap = map.getMap();
	// 휴리스틱 보관용
	int heuristic = 9999;
	// 현재 노드
	int curNodeX = 0;
	int curNodeY = 0;
	// 출발점
	int startX = start.x;
	int startY = start.y;
	// (4,0) -> (0,2)
	//cout << " ( " << startY << " , " << startX << " ) -> ";
	// 출발점 기록
	pushNode(startX, startY);
	// 출발점 방문 표시
	visit[startY][startX] = 0;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			curX = startX;
			curY = startY;
			// 방향전환(8방향)
			setNext(i);
			//cout << " ( " << y << " , " << x << " ) -> ";
			// 벽이 아니고 방문하지 않았다면
			if (gameMap[curY][curX] != 0 && visit[curY][curX])
			{
				// 방문 표시
				visit[curY][curX] = 0;
				// 현재 방문중인 위치의 휴리스틱 보관용
				int tempX = 0;
				int tempY = 0;
				// 현재 위치의 휴리스틱 구하기 x,y 좌표
				if (curX > dest.x)
				{
					tempX = (curX - dest.x) * 10;
				}
				else {
					tempX = (dest.x - curX) * 10;
				}
				if (curY > dest.y)
				{
					tempY = (curY - dest.y) * 10;
				}
				else {
					tempY = (dest.y - curY) * 10;
				}
				//  현재 위치의 휴리스틱이 여태껏 지나온 휴리스틱보다 작으면
				if ((tempX + tempY) < heuristic)
				{
					// 이때의 위치를 기억하고
					curNodeX = curX;
					curNodeY = curY;
					// 휴리스틱을 작은것으로 갱신한다.
					heuristic = tempX + tempY;
				}

			}
		}
		// 최단거리 기록
		pushNode(curNodeX, curNodeY);
		if (dest.x == curNodeX && dest.y == curNodeY)
		{
			break;
		}
		// 새로운 출발점. 출발점 갱신
		startX = curNodeX;
		startY = curNodeY;
		// 휴리스틱값 초기화 (막약 이전의 위치의 휴리스틱이 새로운 위치보다 작으면 갱실 될 수 없다.)
		// 115줄의 if문을 통과 할 수 없음(if ((tempX + tempY) < heuristic))
		heuristic = 9999;
	}


	return false;
}
