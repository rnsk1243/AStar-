#include "ShortPath.h"
#include<iostream>
using namespace std;
#include<list>

CShortPath::CShortPath()
{
}


CShortPath::~CShortPath()
{
}

void CShortPath::draw()
{
	do {
		cout << " ( " << m_path.front().y << " , " << m_path.front().x << " ) -> ";
		popNode();
	} while (!m_path.empty());
	cout << endl;
}

//void CShortPath::sort()
//{
//	std::list<Position> tempList;
//	int i = 0;
//	int j = 0;
//	do {
//		tempList.push_front = m_path.pop();
//	} while (!m_path.empty());
//
//	std::list<Position>::iterator iter;
//
//	do {
//		for (iter = tempList.begin; iter != tempList.end; iter++)
//		{
//			if (iter->y == i)
//			{
//				m_pathPrint.push(*iter);
//			}
//		}
//		i++;
//	} while (!tempList.empty());
//	
//
//}

