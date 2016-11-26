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
// 8���� �̵�
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
	// �� ������
	int** gameMap = map.getMap();
	// �޸���ƽ ������
	int heuristic = 9999;
	// ���� ���
	int curNodeX = 0;
	int curNodeY = 0;
	// �����
	int startX = start.x;
	int startY = start.y;
	// (4,0) -> (0,2)
	//cout << " ( " << startY << " , " << startX << " ) -> ";
	// ����� ���
	pushNode(startX, startY);
	// ����� �湮 ǥ��
	visit[startY][startX] = 0;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			curX = startX;
			curY = startY;
			// ������ȯ(8����)
			setNext(i);
			//cout << " ( " << y << " , " << x << " ) -> ";
			// ���� �ƴϰ� �湮���� �ʾҴٸ�
			if (gameMap[curY][curX] != 0 && visit[curY][curX])
			{
				// �湮 ǥ��
				visit[curY][curX] = 0;
				// ���� �湮���� ��ġ�� �޸���ƽ ������
				int tempX = 0;
				int tempY = 0;
				// ���� ��ġ�� �޸���ƽ ���ϱ� x,y ��ǥ
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
				//  ���� ��ġ�� �޸���ƽ�� ���²� ������ �޸���ƽ���� ������
				if ((tempX + tempY) < heuristic)
				{
					// �̶��� ��ġ�� ����ϰ�
					curNodeX = curX;
					curNodeY = curY;
					// �޸���ƽ�� ���������� �����Ѵ�.
					heuristic = tempX + tempY;
				}

			}
		}
		// �ִܰŸ� ���
		pushNode(curNodeX, curNodeY);
		if (dest.x == curNodeX && dest.y == curNodeY)
		{
			break;
		}
		// ���ο� �����. ����� ����
		startX = curNodeX;
		startY = curNodeY;
		// �޸���ƽ�� �ʱ�ȭ (���� ������ ��ġ�� �޸���ƽ�� ���ο� ��ġ���� ������ ���� �� �� ����.)
		// 115���� if���� ��� �� �� ����(if ((tempX + tempY) < heuristic))
		heuristic = 9999;
	}


	return false;
}
