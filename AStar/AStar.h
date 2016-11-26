#pragma once
#include "ShortPath.h"
class CAStar :
	public CShortPath
{
	// ���� ���Ͱ� Ȯ���ϰ� �ִ� ��ǥ (getNext() �Լ��� ����ϱ� ���� ���������� ����ߴ�.)
	int curX;
	int curY;
public:
	CAStar();
	~CAStar();
	void setNext(int nextIndex);
	bool findPath(Position start, Position dest, CMyMap map);
};

