#pragma once
#include "command.h"
#include "MFC project 1Dlg.h"

class AddColor : public command
{
public:
	AddColor(Figure *s, COLORREF color);
	~AddColor(void);
	void perform();
	void rollback();
private:
	Figure *s;
	COLORREF oldColor, oldPen, newColor;
	int oldSize, oldType;
};