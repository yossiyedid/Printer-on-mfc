#include "stdafx.h"
#include "DeleteShape.h"

DeleteShape::DeleteShape(CTypedPtrArray<CObArray, Figure*> &myShapes, Figure *s)
	: myShapes(myShapes), s(s) {}

DeleteShape::~DeleteShape(void) {}

void DeleteShape::perform()
{
	oldStart = s->start;
	oldEnd = s->end;
	s->start = 0;
	s->end = 0;

}

void DeleteShape::rollback()
{
	s->start = oldStart;
	s->end = oldEnd;

}