
#pragma once
#include "Figure.h"
class myTrapeze :
	public Figure
{
public:
	DECLARE_SERIAL(myTrapeze)
	myTrapeze(void);
	~myTrapeze(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

