#include "stdafx.h"
#include "myLine.h"

IMPLEMENT_SERIAL(myLine, Figure, 1)

myLine::myLine(void) {}
myLine::~myLine(void) {}

void myLine::innerDraw(CDC *dc)
{
	dc->MoveTo(start.x, start.y);
	dc->LineTo(end.x, end.y);
}
