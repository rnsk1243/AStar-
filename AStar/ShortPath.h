#pragma once
#include<queue>


struct Position
{
	int x;
	int y;
	Position(int x_, int y_)
	{
		x = x_;
		y = y_;
	}
};
class CMyMap;

class CShortPath
{
	std::queue<Position> m_path;
	//std::queue<Position> m_pathPrint;
public:
	CShortPath();
	~CShortPath();
	void pushNode(int x, int y) { m_path.push(Position(x,y)); }
	void popNode() { m_path.pop(); }
	Position getNode() { return m_path.front(); }
	//std::queue<Position> getPath() { return m_pathPrint; }
	void draw();
	//void sort();
	virtual bool findPath(Position start, Position dest, CMyMap map) = 0;
};