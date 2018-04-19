#include "stdafx.h"
#include "AddShape.h"

AddShape::AddShape(CTypedPtrArray<CObArray, Figure*> &myShapes, Figure *s)
	: myShapes(myShapes), s(s) {}

AddShape::~AddShape(void) {}

void AddShape::perform()
{
	myShapes.Add(s);
}

void AddShape::rollback()
{
	for (int i = 0; i<myShapes.GetSize(); ++i)
	{
		if (myShapes[i] == s)
		{
			myShapes.RemoveAt(i);
			return;
		}
	}
}