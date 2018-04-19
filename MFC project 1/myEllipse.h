#pragma once
#include "Figure.h"
#include "myRectangle.h"
class myEllipse :
	public myRectangle
{
public:
	DECLARE_SERIAL(myEllipse)
	myEllipse(void);
	~myEllipse(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

