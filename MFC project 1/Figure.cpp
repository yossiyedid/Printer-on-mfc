#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(void) {}

Figure::~Figure(void) {}

void Figure::Serialize(CArchive& archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring())
		archive << start.x << start.y << end.x << end.y << bgColor << pColor << ShapePenSize << ShapePenType;
	else
		archive >> start.x >> start.y >> end.x >> end.y >> bgColor >> pColor >> ShapePenSize >> ShapePenType;
}

void Figure::Draw(CDC *dc) {
	CPen pen(ShapePenType, ShapePenSize, pColor);
	CBrush brush(bgColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	CPen *oldPen = dc->SelectObject(&pen);
	innerDraw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}