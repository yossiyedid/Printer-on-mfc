#pragma once

#include "command.h"
#include "Figure.h"

class DeleteShape : public command
{
public:
	DeleteShape(CTypedPtrArray<CObArray, Figure*> &myShapes, Figure *s);
	~DeleteShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, Figure*> &myShapes;
	Figure *s;
	CPoint oldStart, oldEnd;
};