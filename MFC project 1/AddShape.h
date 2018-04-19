#pragma once
#include "command.h"
#include "Figure.h"

class AddShape : public command
{
public:
	
	AddShape(CTypedPtrArray<CObArray, Figure*> &myShapes, Figure *s);
	~AddShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, Figure*> &myShapes;
	Figure *s;
};