#pragma once
#include "Figure.h"
class myRectangle :
	public Figure
{
public:
	DECLARE_SERIAL(myRectangle)
	myRectangle(void);
	~myRectangle(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

