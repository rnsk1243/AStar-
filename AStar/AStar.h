#pragma once
#include "ShortPath.h"
class CAStar :
	public CShortPath
{
	// 현재 컴터가 확인하고 있는 좌표 (getNext() 함수를 사용하기 위해 전역변수로 사용했다.)
	int curX;
	int curY;
public:
	CAStar();
	~CAStar();
	void setNext(int nextIndex);
	bool findPath(Position start, Position dest, CMyMap map);
};

