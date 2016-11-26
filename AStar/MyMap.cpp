#include "MyMap.h"

#include<iostream>
using namespace std;


CMyMap::CMyMap()
{
}


CMyMap::~CMyMap()
{
}

void CMyMap::setMap(int ** map)
{
	for (int h = 0; h<m_height; h++)
	{
		for (int w = 0; w<m_width; w++)
		{
			m_map[h][w] = map[h][w];
		}
	}
}

void CMyMap::draw(Position start, Position end)
{

	for (int h = 0; h<m_height; h++)
	{
		for (int w = 0; w<m_width; w++)
		{
			//cout << m_map[h][w] << "\t";
			if (m_map[h][w] == 0)
			{
				// º®
				cout << "¡á";
			}
			else 
			{
				if (start.x == w && start.y == h)
				{
					// ½ÃÀÛÁ¡
					cout << "¢¾";
				}
				else if(end.x == w && end.y == h)
				{
					// µµÂøÁ¡
					cout << "¢½";
				}
				else
				{
					// ºó°ø°£
					cout << "  ";
				}
				
			}
		}



		cout << endl;
	}
	//cout << path.front().x << endl;
	//cout << path.front().y << endl;
}

/*
if (pathTemp.front().x == w && pathTemp.front().y == h)
{
cout << "¢À";
if (!pathTemp.empty())
{
pathTemp.pop();
}
}
*/