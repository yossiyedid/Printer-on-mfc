#include "stdafx.h"
#include "myEllipse.h"

IMPLEMENT_SERIAL(myEllipse, Figure, 1)

myEllipse::myEllipse(void) {}
myEllipse::~myEllipse(void) {}

void myEllipse::innerDraw(CDC *dc)
{
	dc->Ellipse(start.x, start.y, end.x, end.y);
}
bool myEllipse::InShape(CPoint p)
{
	if (p.x > start.x && p.x < end.x && p.y > start.y && p.y < end.y)
		return true;
	return false;
}