#include "stdafx.h"
#include "myRectangle.h"

IMPLEMENT_SERIAL(myRectangle, Figure, 1)

myRectangle::myRectangle(void) {}
myRectangle::~myRectangle(void) {}

void myRectangle::innerDraw(CDC *dc)
{
	dc->Rectangle(start.x, start.y, end.x, end.y);
}
bool myRectangle::InShape(CPoint p)
{
	int minX = start.x < end.x ? start.x : end.x;
	int maxX = start.x > end.x ? start.x : end.x;
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	if (p.x < minX || p.x > maxX || p.y < minY || p.y > maxY)
		return false;
	return true;
}