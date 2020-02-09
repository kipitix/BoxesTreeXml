#pragma once

#include <string>

class TreeElementDrawer
{
public:
	TreeElementDrawer();

	virtual ~TreeElementDrawer();
	
	virtual void addRectangle(int x, int y, int width, int height) = 0;
	virtual void addText(int x, int y, std::string text) = 0;
	virtual void addLine(int x1, int y1, int x2, int y2) = 0;
};
