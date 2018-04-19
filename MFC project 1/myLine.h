#pragma once
#include "Figure.h"
class myLine :
	public Figure
{
public:
	DECLARE_SERIAL(myLine)
	myLine(void);
	~myLine(void);
	void innerDraw(CDC *dc);

};